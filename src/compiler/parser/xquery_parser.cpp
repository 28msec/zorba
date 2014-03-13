/* A Bison parser, made by GNU Bison 2.6.5.  */

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
#line 1 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"

#define XQUERY_PARSER
/* Line 278 of lalr1.cc  */
#line 59 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"


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
#include "zorbatypes/decimal.h"
#include "zorbatypes/integer.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )

#define ERROR_IF_QNAME_NOT_NCNAME(qname, location)                \
  do {                                                            \
    if ( ! static_cast<QName*>(qname)->is_ncname()) {             \
      error((location), "A NCName is expected, found a QName");   \
      YYERROR;                                                    \
  }                                                               \
  } while (0);          


#define YYDEBUG 1

using namespace std;
using namespace zorba;

/* Line 278 of lalr1.cc  */
#line 102 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"


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


/* Line 278 of lalr1.cc  */
#line 98 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */
/* Line 284 of lalr1.cc  */
#line 898 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"



template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}
/* Line 284 of lalr1.cc  */
#line 1028 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"

namespace {
bool convert_postfix_to_target_and_selector(
    exprnode* aPostfixExpr,
    rchandle<exprnode>* aTargetExpr,
    rchandle<exprnode>* aSelectorExpr,
    string* anError,
    bool allowArray = true)
{
  rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
      dynamic_cast<DynamicFunctionInvocation*>(aPostfixExpr);
  rchandle<FilterExpr> lFilterExpr = dynamic_cast<FilterExpr*>(aPostfixExpr);
  rchandle<JSONObjectLookup> lObjectLookup = dynamic_cast<JSONObjectLookup*>(aPostfixExpr);


  if (lDynamicFunctionInvocation != NULL) {
    if (lDynamicFunctionInvocation->getArgList()->size() != 1)
    {
      *anError = "An object or array lookup with exactly one argument is expected. Zero or more than one argument were found.";
      return false;
    }
    *aTargetExpr = lDynamicFunctionInvocation->getPrimaryExpr(),
    *aSelectorExpr = lDynamicFunctionInvocation->getArgList()->operator[](0);
    return true;
  }
  else
  {
    *anError = "An object or array lookup is expected.";
    return false;
  }
};
}

/* Line 284 of lalr1.cc  */
#line 151 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"


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
#line 246 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
        case 111: /* "'DECIMAL'" */
/* Line 453 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).decval); };
/* Line 453 of lalr1.cc  */
#line 352 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 125: /* "'DOUBLE'" */
/* Line 453 of lalr1.cc  */
#line 895 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).dval); };
/* Line 453 of lalr1.cc  */
#line 359 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 150: /* "'INTEGER'" */
/* Line 453 of lalr1.cc  */
#line 894 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).ival); };
/* Line 453 of lalr1.cc  */
#line 366 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* VersionDecl */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 373 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* MainModule */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 380 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* LibraryModule */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 387 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* ModuleDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 394 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* SIND_DeclList */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 401 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* SIND_Decl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 408 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* Setter */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 415 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* BoundarySpaceDecl */
/* Line 453 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 422 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* DefaultCollationDecl */
/* Line 453 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 429 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* BaseURIDecl */
/* Line 453 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 436 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* ConstructionDecl */
/* Line 453 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 443 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* OrderingModeDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 450 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* EmptyOrderDecl */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 457 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* CopyNamespacesDecl */
/* Line 453 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 464 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* Import */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 471 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* SchemaImport */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 478 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* URILiteralList */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 485 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* SchemaPrefix */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 492 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* ModuleImport */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 499 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* NamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 506 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* DefaultNamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 513 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* VFO_DeclList */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 520 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* VFO_Decl */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 527 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* DecimalFormatDecl */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 534 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* DecimalFormatParamList */
/* Line 453 of lalr1.cc  */
#line 945 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).vstrpair); };
/* Line 453 of lalr1.cc  */
#line 541 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* DecimalFormatParam */
/* Line 453 of lalr1.cc  */
#line 945 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).strpair); };
/* Line 453 of lalr1.cc  */
#line 548 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* OptionDecl */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 555 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* FTOptionDecl */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 562 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* CtxItemDecl */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 569 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* CtxItemDecl2 */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 576 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* CtxItemDecl3 */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 583 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* CtxItemDecl4 */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 590 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* VarDecl */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 597 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* VarNameAndType */
/* Line 453 of lalr1.cc  */
#line 945 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).varnametype); };
/* Line 453 of lalr1.cc  */
#line 604 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* AnnotationList */
/* Line 453 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 611 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* Annotation */
/* Line 453 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 618 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* AnnotationLiteralList */
/* Line 453 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 625 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* FunctionDecl */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 632 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* FunctionDecl2 */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 639 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* FunctionDeclSimple */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 646 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* FunctionDeclUpdating */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 653 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* FunctionSig */
/* Line 453 of lalr1.cc  */
#line 945 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).fnsig); };
/* Line 453 of lalr1.cc  */
#line 660 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* ParamList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 667 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* Param */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 674 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* CollectionDecl */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 681 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* IndexDecl */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 688 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* IndexKeyList */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 695 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* IndexKeySpec */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 702 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* IntegrityConstraintDecl */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 709 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* QueryBody */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 716 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* StatementsAndOptionalExprTop */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 723 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* StatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 730 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* StatementsAndExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 737 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* Statements */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 744 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* Statement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 751 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* BlockStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 758 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* BlockExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 765 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* EnclosedStatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 772 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* VarDeclStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 779 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* AssignStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 786 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* ApplyStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 793 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* ExitStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 800 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* WhileStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 807 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* FlowCtlStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 814 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* FLWORStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 821 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* ReturnStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 828 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* IfStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 835 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* TryStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* CatchListStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 849 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* CatchStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* VoidStatement */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 863 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* Expr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 870 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* ExprSingle */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* ExprSimple */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 884 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* FLWORExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 891 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* ReturnExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 898 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* FLWORWinCond */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 905 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* WindowClause */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 912 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* CountClause */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* ForLetWinClause */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* OffsetClause */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* LimitClause */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* FLWORClauseList */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* ForClause */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 954 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* VarInDeclList */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 961 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* VarInDecl */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 968 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* PositionalVar */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 975 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* FTScoreVar */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 982 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* LetClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 989 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* VarGetsDeclList */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 996 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* VarGetsDecl */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1003 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* WindowVarDecl */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1010 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* WindowVars */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1017 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* WindowVars3 */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1024 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* WindowVars2 */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1031 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* WhereClause */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1038 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* GroupByClause */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1045 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* GroupSpecList */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1052 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* GroupSpec */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1059 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* GroupCollationSpec */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1066 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* OrderByClause */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1073 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* OrderSpecList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1080 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* OrderSpec */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1087 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* OrderModifier */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1094 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* OrderDirSpec */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* OrderEmptySpec */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1108 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* OrderCollationSpec */
/* Line 453 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1115 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* QuantifiedExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1122 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* QVarInDeclList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1129 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* QVarInDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1136 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* SwitchExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1143 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* SwitchCaseClauseList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1150 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* SwitchCaseClause */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1157 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* SwitchCaseOperandList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* SwitchStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* TypeswitchExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1178 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* TypeswitchStatement */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1185 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* CaseClauseList */
/* Line 453 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1192 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* CaseClause */
/* Line 453 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1199 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* SequenceTypeList */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1206 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* IfExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1213 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* OrExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1220 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* AndExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1227 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* ComparisonExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1234 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* FTContainsExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1241 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* StringConcatExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1248 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* opt_FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1255 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* RangeExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1262 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* AdditiveExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1269 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* MultiplicativeExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1276 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* UnionExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1283 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* IntersectExceptExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1290 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* InstanceofExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* TreatExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1304 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* CastableExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1311 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* CastExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1318 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* SingleType */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1325 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* UnaryExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1332 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* SignList */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1339 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* ValueExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1346 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* SimpleMapExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* ValueComp */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1360 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* NodeComp */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1367 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* ValidateExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1374 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* ExtensionExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1381 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* Pragma_list */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1388 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* Pragma */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1395 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* PathExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1402 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* RelativePathExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1409 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* StepExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1416 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* AxisStep */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1423 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* ForwardStep */
/* Line 453 of lalr1.cc  */
#line 911 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1430 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* ForwardAxis */
/* Line 453 of lalr1.cc  */
#line 911 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1437 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* AbbrevForwardStep */
/* Line 453 of lalr1.cc  */
#line 911 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1444 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* ReverseStep */
/* Line 453 of lalr1.cc  */
#line 911 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1451 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* ReverseAxis */
/* Line 453 of lalr1.cc  */
#line 911 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1458 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* NodeTest */
/* Line 453 of lalr1.cc  */
#line 911 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1465 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* NameTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1472 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* Wildcard */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* PostfixExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* PredicateList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1493 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* Predicate */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1500 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* PrimaryExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1507 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* Literal */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1514 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* NumericLiteral */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1521 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* VarRef */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1528 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* ParenthesizedExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1535 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* ContextItemExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1542 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* OrderedExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* UnorderedExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1556 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* FunctionCall */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1563 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* ArgList */
/* Line 453 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1570 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* Constructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1577 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* DirectConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1584 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* DirElemConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1591 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* DirElemContentList */
/* Line 453 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1598 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* DirAttributeList */
/* Line 453 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1605 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* DirAttr */
/* Line 453 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1612 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* DirAttributeValue */
/* Line 453 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1619 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* opt_QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1626 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1633 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* opt_AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1640 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1647 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* QuoteAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1654 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* AposAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1661 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* DirElemContent */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1668 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* CommonContent */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1675 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* DirCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1682 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* DirPIConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1689 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* CDataSection */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1696 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* ComputedConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1703 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* CompDocConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1710 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* CompElemConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1717 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* CompAttrConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1724 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* CompTextConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* CompCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1738 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* CompPIConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1745 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* CompNamespaceConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1752 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* TypeDeclaration */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1759 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* SequenceType */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1766 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* OccurrenceIndicator */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1773 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* ItemType */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1780 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* TypeList */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1787 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* GeneralizedAtomicType */
/* Line 453 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1794 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* SimpleType */
/* Line 453 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1801 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* KindTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1808 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* AnyKindTest */
/* Line 453 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1815 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* DocumentTest */
/* Line 453 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1822 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* NamespaceTest */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1829 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* TextTest */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1836 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* CommentTest */
/* Line 453 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1843 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* PITest */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1850 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* AttributeTest */
/* Line 453 of lalr1.cc  */
#line 915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1857 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* SchemaAttributeTest */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1864 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* ElementTest */
/* Line 453 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1871 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* SchemaElementTest */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1878 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* TypeName */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1885 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* TypeName_WITH_HOOK */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1892 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* StringLiteral */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1899 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* AnyFunctionTest */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1906 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* TypedFunctionTest */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1913 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* InsertExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* DeleteExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* ReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* RenameExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1941 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* TransformExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1948 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* VarNameList */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1955 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* VarNameDecl */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1962 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* TryExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1969 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* CatchListExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1976 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* CatchExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1983 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* BracedExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1990 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* NameTestList */
/* Line 453 of lalr1.cc  */
#line 945 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).name_test_list); };
/* Line 453 of lalr1.cc  */
#line 1997 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* FTSelection */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2004 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* FTOr */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2011 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* FTAnd */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2018 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* FTMildNot */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2025 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* FTUnaryNot */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2032 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* FTPrimaryWithOptions */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2039 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* opt_FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2046 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* FTWeight */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2053 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* FTPrimary */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2060 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* opt_FTTimes */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2067 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* FTExtensionSelection */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2074 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* FTWords */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2081 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* FTWordsValue */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2088 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* FTAnyallOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2095 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* FTPosFilter */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2102 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* FTOrder */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* FTWindow */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2116 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* FTDistance */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2123 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* FTUnit */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2130 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2137 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* FTMatchOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2144 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* FTCaseOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2151 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* FTDiacriticsOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2158 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* FTExtensionOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2165 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* FTStemOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* FTThesaurusOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2179 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* FTThesaurusID */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2186 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* FTStopWordOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2193 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* FTStopWords */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2200 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* FTStopWordsInclExcl */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2207 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* FTLanguageOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2214 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* FTWildCardOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2221 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* FTContent */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2228 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* FTTimes */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2235 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* FTRange */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2242 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* FTScope */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2249 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* FTBigUnit */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2256 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2263 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* JSONArrayConstructor */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2270 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* JSONSimpleObjectUnion */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2277 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* JSONAccumulatorObjectUnion */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2284 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* JSONObjectConstructor */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2291 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 653: /* JSONPairList */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2298 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 654: /* JSONInsertExpr */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2305 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 655: /* JSONAppendExpr */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2312 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 656: /* JSONDeleteExpr */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2319 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 657: /* JSONRenameExpr */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2326 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 658: /* JSONReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2333 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 661: /* QNAME */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2340 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 662: /* FUNCTION_NAME */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2347 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 663: /* EQNAME */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2354 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
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

    YYCDEBUG << "Starting parse" << std::endl;


/* User initialization code.  */
/* Line 543 of lalr1.cc  */
#line 139 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}
/* Line 543 of lalr1.cc  */
#line 2450 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1074 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:
/* Line 661 of lalr1.cc  */
#line 1078 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 1082 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 1090 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 1096 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 1100 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 1109 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 1115 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 1123 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 1129 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 1141 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 1146 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 1154 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 1161 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 1168 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 1177 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 1184 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 1192 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 1200 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 1208 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 1219 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 1224 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 1231 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 1238 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 1250 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 1260 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 1267 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 1274 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 1309 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 1314 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 1322 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 1330 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 1338 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 1343 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 1351 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 1356 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 1364 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 1369 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 1377 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 1382 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 1387 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 1392 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 1405 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\"");
      YYERROR;
    }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 1415 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 1420 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 1428 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 1436 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 1447 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 1454 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:
/* Line 661 of lalr1.cc  */
#line 1465 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 68:
/* Line 661 of lalr1.cc  */
#line 1471 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:
/* Line 661 of lalr1.cc  */
#line 1493 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 1502 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(8) - (4)].expr), (yylocation_stack_[(8) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(8) - (4)].expr)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 73:
/* Line 661 of lalr1.cc  */
#line 1516 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 1525 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 1532 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 1542 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:
/* Line 661 of lalr1.cc  */
#line 1556 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 1579 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 1585 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 1594 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 1601 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 1611 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 1620 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 1621 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 1622 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 1623 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 1624 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 1625 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 1626 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 1627 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 1628 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 1629 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 1635 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));



      if (static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_localname() == "enable")
      {
        zstring opt = SYMTAB((yysemantic_stack_[(4) - (4)].sval));
        if (opt.find(":") != zstring::npos)
          opt = opt.substr(opt.find(":")+1);
        if (opt == "common-language")
          driver.enableCommonLanguage();
      }
    }
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 1654 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 1662 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 1670 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 1677 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 1685 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 1692 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 1697 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 1705 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 1713 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      std::unique_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(4) - (4)].expr),
                             nt->get_annotations(),
                             false);

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 1727 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      std::unique_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             NULL,
                             nt->get_annotations(),
                             true);

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 1741 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      std::unique_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(5) - (5)].expr),
                             nt->get_annotations(),
                             true);

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 1758 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 1763 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 1771 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 1779 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 1790 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 1795 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 1804 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 1809 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 1816 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 1821 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 1831 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 1836 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 1845 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 1851 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 1870 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      exprnode* body = (yysemantic_stack_[(4) - (4)].expr);
      if (body == NULL)
        body = new BlockBody(LOC((yylocation_stack_[(4) - (4)])));

      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            body,
                            false,
                            false);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 1885 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 132:
/* Line 661 of lalr1.cc  */
#line 1900 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      exprnode* body = (yysemantic_stack_[(5) - (5)].expr);
      if (body == NULL)
        body = new BlockBody(LOC((yylocation_stack_[(5) - (5)])));

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

  case 133:
/* Line 661 of lalr1.cc  */
#line 1916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 134:
/* Line 661 of lalr1.cc  */
#line 1931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 1936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 1941 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 1946 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 1954 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 1961 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 1972 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 1977 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 1987 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 1996 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 2005 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 2014 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceTypeAST*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 2026 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 2030 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 2036 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 2040 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 2050 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2060 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2073 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 2079 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 2088 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 2093 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 2100 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 2107 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 2119 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 2129 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 2139 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 2150 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2166 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2186 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 2190 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 2194 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 2202 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 2206 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 2210 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 2218 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 2223 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 2235 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 2242 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 2252 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr);
      (yyval.expr) = (yysemantic_stack_[(4) - (2)].expr);
      (yyval.expr) = (yysemantic_stack_[(4) - (4)].expr);
      error((yylocation_stack_[(4) - (3)]), "syntax error, unexpected statement");
      delete (yysemantic_stack_[(4) - (1)].expr);
      delete (yysemantic_stack_[(4) - (2)].expr);
      delete (yysemantic_stack_[(4) - (4)].expr);
      YYERROR;
    }
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 2285 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 2292 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {

      driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_EMPTY_BLOCK));
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 2303 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));
      if ((yysemantic_stack_[(3) - (2)].expr) == NULL)
      {
        (yyval.expr) = new BlockBody(LOC((yyloc)));
      }
      else if (block == NULL)
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

  case 190:
/* Line 661 of lalr1.cc  */
#line 2325 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 2333 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 2341 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 2348 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 2355 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 2366 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 2375 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (3)].node)),
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 2384 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,
                                          (yysemantic_stack_[(4) - (4)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 2393 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (3)].node)),
                                          (yysemantic_stack_[(5) - (5)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 2406 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 2414 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 2422 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 2430 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 203:
/* Line 661 of lalr1.cc  */
#line 2445 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 2450 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 205:
/* Line 661 of lalr1.cc  */
#line 2458 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 206:
/* Line 661 of lalr1.cc  */
#line 2472 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 207:
/* Line 661 of lalr1.cc  */
#line 2489 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 208:
/* Line 661 of lalr1.cc  */
#line 2514 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 2522 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 2529 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 2540 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 2549 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 2557 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 2562 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 215:
/* Line 661 of lalr1.cc  */
#line 2575 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr);





      if (dynamic_cast<PathExpr*>((yysemantic_stack_[(3) - (1)].expr)) == NULL)
        error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected expression");
      delete (yysemantic_stack_[(3) - (1)].expr);
      delete (yysemantic_stack_[(3) - (3)].expr);
      YYERROR;
    }
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 2624 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 235:
/* Line 661 of lalr1.cc  */
#line 2638 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 2650 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
    }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 2657 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 2662 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 2670 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 2675 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 2680 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 2688 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 243:
/* Line 661 of lalr1.cc  */
#line 2697 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 244:
/* Line 661 of lalr1.cc  */
#line 2709 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2719 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2732 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 2757 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.node) = new OffsetClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
  }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 2764 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.node) = new LimitClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
  }
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 2771 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 260:
/* Line 661 of lalr1.cc  */
#line 2778 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 261:
/* Line 661 of lalr1.cc  */
#line 2788 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 2793 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 2801 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 2815 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {

    }
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 2823 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 2830 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 2838 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 2850 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 269:
/* Line 661 of lalr1.cc  */
#line 2860 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 270:
/* Line 661 of lalr1.cc  */
#line 2870 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 2880 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 2890 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 273:
/* Line 661 of lalr1.cc  */
#line 2900 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 274:
/* Line 661 of lalr1.cc  */
#line 2910 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 2920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)),
                         NULL,
                         (yysemantic_stack_[(7) - (7)].expr),
                         true);
    }
    break;

  case 276:
/* Line 661 of lalr1.cc  */
#line 2931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 2940 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 2950 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 279:
/* Line 661 of lalr1.cc  */
#line 2960 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr),
                         false);
    }
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 2976 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 2985 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 2994 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 3002 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 3008 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 3020 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 3028 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 3038 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 3046 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 3058 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 3064 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 3077 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 3081 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 3089 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 3093 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 3102 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 3106 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 3110 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 3120 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 3128 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 3135 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 3141 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 3151 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 3155 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 3163 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceTypeAST*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 3171 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 3179 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 3187 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 3199 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 3207 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 3213 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 3223 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 3229 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 3239 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 3243 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 3253 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 3259 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 3265 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 3271 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 3280 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 3289 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 3298 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 3311 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 3315 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 3323 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 3329 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 3339 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 3347 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 3356 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 3369 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 3376 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 3388 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 3392 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 3404 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 3411 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 3417 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 3426 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 3433 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 3439 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 3450 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 3457 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 3463 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 3472 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 3481 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 3488 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 3499 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 3506 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 3518 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 3524 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 3536 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 3542 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 3553 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 3559 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 3570 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 3576 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 3587 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceTypeAST*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 3593 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 3604 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 360:
/* Line 661 of lalr1.cc  */
#line 3613 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 3617 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 362:
/* Line 661 of lalr1.cc  */
#line 3631 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 3641 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 3647 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 3651 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {

            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 3661 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {

            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 3668 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 3677 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 3686 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {


            driver.getXqueryLexer()->interpretAsLessThan();



        }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 3695 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 3704 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 3713 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 3722 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 3735 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 3739 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 3751 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 3755 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 3762 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 3766 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 3773 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 3777 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 3786 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 3790 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 3794 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 3802 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 3806 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 3812 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 3818 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 3824 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 3834 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:
/* Line 661 of lalr1.cc  */
#line 3838 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 392:
/* Line 661 of lalr1.cc  */
#line 3842 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 393:
/* Line 661 of lalr1.cc  */
#line 3850 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:
/* Line 661 of lalr1.cc  */
#line 3854 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 395:
/* Line 661 of lalr1.cc  */
#line 3860 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 396:
/* Line 661 of lalr1.cc  */
#line 3870 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:
/* Line 661 of lalr1.cc  */
#line 3874 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:
/* Line 661 of lalr1.cc  */
#line 3884 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:
/* Line 661 of lalr1.cc  */
#line 3888 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 400:
/* Line 661 of lalr1.cc  */
#line 3898 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:
/* Line 661 of lalr1.cc  */
#line 3902 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 402:
/* Line 661 of lalr1.cc  */
#line 3912 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:
/* Line 661 of lalr1.cc  */
#line 3916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 404:
/* Line 661 of lalr1.cc  */
#line 3926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 405:
/* Line 661 of lalr1.cc  */
#line 3930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 406:
/* Line 661 of lalr1.cc  */
#line 3939 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:
/* Line 661 of lalr1.cc  */
#line 3943 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 408:
/* Line 661 of lalr1.cc  */
#line 3951 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 409:
/* Line 661 of lalr1.cc  */
#line 3955 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 410:
/* Line 661 of lalr1.cc  */
#line 3959 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 411:
/* Line 661 of lalr1.cc  */
#line 3963 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 415:
/* Line 661 of lalr1.cc  */
#line 3979 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 416:
/* Line 661 of lalr1.cc  */
#line 3984 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 417:
/* Line 661 of lalr1.cc  */
#line 3992 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 418:
/* Line 661 of lalr1.cc  */
#line 3996 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 419:
/* Line 661 of lalr1.cc  */
#line 4000 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 420:
/* Line 661 of lalr1.cc  */
#line 4004 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 421:
/* Line 661 of lalr1.cc  */
#line 4008 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 422:
/* Line 661 of lalr1.cc  */
#line 4012 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 423:
/* Line 661 of lalr1.cc  */
#line 4020 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 424:
/* Line 661 of lalr1.cc  */
#line 4024 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 425:
/* Line 661 of lalr1.cc  */
#line 4028 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 426:
/* Line 661 of lalr1.cc  */
#line 4036 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 427:
/* Line 661 of lalr1.cc  */
#line 4040 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 428:
/* Line 661 of lalr1.cc  */
#line 4044 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 429:
/* Line 661 of lalr1.cc  */
#line 4048 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 430:
/* Line 661 of lalr1.cc  */
#line 4059 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 431:
/* Line 661 of lalr1.cc  */
#line 4069 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 432:
/* Line 661 of lalr1.cc  */
#line 4075 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 433:
/* Line 661 of lalr1.cc  */
#line 4085 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 434:
/* Line 661 of lalr1.cc  */
#line 4089 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 435:
/* Line 661 of lalr1.cc  */
#line 4093 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 436:
/* Line 661 of lalr1.cc  */
#line 4099 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 437:
/* Line 661 of lalr1.cc  */
#line 4103 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 438:
/* Line 661 of lalr1.cc  */
#line 4113 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 439:
/* Line 661 of lalr1.cc  */
#line 4123 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;

      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));

      if (rpe != NULL &&
         ( (dynamic_cast<ContextItemExpr*>(rpe->get_step_expr()) != NULL &&
             dynamic_cast<ContextItemExpr*>(rpe->get_step_expr())->is_placeholder() &&
             dynamic_cast<AxisStep*>(rpe->get_relpath_expr()) != NULL)
           ||
             dynamic_cast<AxisStep*>(rpe->get_step_expr()) != NULL))
      {


        driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_AXIS_STEP));
      }

      if ((yyval.expr) == NULL)
        (yyval.expr) = (rpe ?
              new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)) :
              (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 440:
/* Line 661 of lalr1.cc  */
#line 4152 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 441:
/* Line 661 of lalr1.cc  */
#line 4161 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 442:
/* Line 661 of lalr1.cc  */
#line 4171 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 443:
/* Line 661 of lalr1.cc  */
#line 4175 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 446:
/* Line 661 of lalr1.cc  */
#line 4191 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 447:
/* Line 661 of lalr1.cc  */
#line 4197 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 448:
/* Line 661 of lalr1.cc  */
#line 4205 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 449:
/* Line 661 of lalr1.cc  */
#line 4211 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 450:
/* Line 661 of lalr1.cc  */
#line 4224 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 451:
/* Line 661 of lalr1.cc  */
#line 4230 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 452:
/* Line 661 of lalr1.cc  */
#line 4241 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 453:
/* Line 661 of lalr1.cc  */
#line 4245 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 454:
/* Line 661 of lalr1.cc  */
#line 4249 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 455:
/* Line 661 of lalr1.cc  */
#line 4253 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 456:
/* Line 661 of lalr1.cc  */
#line 4257 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 457:
/* Line 661 of lalr1.cc  */
#line 4263 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 458:
/* Line 661 of lalr1.cc  */
#line 4269 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 459:
/* Line 661 of lalr1.cc  */
#line 4278 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 460:
/* Line 661 of lalr1.cc  */
#line 4282 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 461:
/* Line 661 of lalr1.cc  */
#line 4291 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 462:
/* Line 661 of lalr1.cc  */
#line 4295 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 463:
/* Line 661 of lalr1.cc  */
#line 4307 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 464:
/* Line 661 of lalr1.cc  */
#line 4311 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 465:
/* Line 661 of lalr1.cc  */
#line 4315 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 466:
/* Line 661 of lalr1.cc  */
#line 4321 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 467:
/* Line 661 of lalr1.cc  */
#line 4325 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 470:
/* Line 661 of lalr1.cc  */
#line 4347 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 471:
/* Line 661 of lalr1.cc  */
#line 4351 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 472:
/* Line 661 of lalr1.cc  */
#line 4361 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 473:
/* Line 661 of lalr1.cc  */
#line 4365 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 474:
/* Line 661 of lalr1.cc  */
#line 4369 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 475:
/* Line 661 of lalr1.cc  */
#line 4373 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 476:
/* Line 661 of lalr1.cc  */
#line 4386 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 477:
/* Line 661 of lalr1.cc  */
#line 4390 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 478:
/* Line 661 of lalr1.cc  */
#line 4394 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 479:
/* Line 661 of lalr1.cc  */
#line 4398 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 480:
/* Line 661 of lalr1.cc  */
#line 4406 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 481:
/* Line 661 of lalr1.cc  */
#line 4412 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));

      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 482:
/* Line 661 of lalr1.cc  */
#line 4423 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 497:
/* Line 661 of lalr1.cc  */
#line 4451 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:
/* Line 661 of lalr1.cc  */
#line 4455 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:
/* Line 661 of lalr1.cc  */
#line 4463 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 500:
/* Line 661 of lalr1.cc  */
#line 4470 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 501:
/* Line 661 of lalr1.cc  */
#line 4477 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 502:
/* Line 661 of lalr1.cc  */
#line 4488 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 503:
/* Line 661 of lalr1.cc  */
#line 4496 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 504:
/* Line 661 of lalr1.cc  */
#line 4500 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 505:
/* Line 661 of lalr1.cc  */
#line 4510 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {

            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 506:
/* Line 661 of lalr1.cc  */
#line 4520 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 507:
/* Line 661 of lalr1.cc  */
#line 4528 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 508:
/* Line 661 of lalr1.cc  */
#line 4534 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 509:
/* Line 661 of lalr1.cc  */
#line 4538 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 510:
/* Line 661 of lalr1.cc  */
#line 4560 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 511:
/* Line 661 of lalr1.cc  */
#line 4566 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 512:
/* Line 661 of lalr1.cc  */
#line 4572 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 513:
/* Line 661 of lalr1.cc  */
#line 4578 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 514:
/* Line 661 of lalr1.cc  */
#line 4588 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 515:
/* Line 661 of lalr1.cc  */
#line 4592 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 516:
/* Line 661 of lalr1.cc  */
#line 4600 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 517:
/* Line 661 of lalr1.cc  */
#line 4608 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 523:
/* Line 661 of lalr1.cc  */
#line 4633 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 524:
/* Line 661 of lalr1.cc  */
#line 4641 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 525:
/* Line 661 of lalr1.cc  */
#line 4658 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 526:
/* Line 661 of lalr1.cc  */
#line 4666 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 527:
/* Line 661 of lalr1.cc  */
#line 4685 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 528:
/* Line 661 of lalr1.cc  */
#line 4704 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 529:
/* Line 661 of lalr1.cc  */
#line 4726 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 530:
/* Line 661 of lalr1.cc  */
#line 4732 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 531:
/* Line 661 of lalr1.cc  */
#line 4743 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 532:
/* Line 661 of lalr1.cc  */
#line 4749 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 533:
/* Line 661 of lalr1.cc  */
#line 4760 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 536:
/* Line 661 of lalr1.cc  */
#line 4775 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 537:
/* Line 661 of lalr1.cc  */
#line 4780 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 538:
/* Line 661 of lalr1.cc  */
#line 4789 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 539:
/* Line 661 of lalr1.cc  */
#line 4793 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 540:
/* Line 661 of lalr1.cc  */
#line 4800 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 541:
/* Line 661 of lalr1.cc  */
#line 4806 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 542:
/* Line 661 of lalr1.cc  */
#line 4812 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:
/* Line 661 of lalr1.cc  */
#line 4819 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:
/* Line 661 of lalr1.cc  */
#line 4830 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 545:
/* Line 661 of lalr1.cc  */
#line 4834 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 546:
/* Line 661 of lalr1.cc  */
#line 4841 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 547:
/* Line 661 of lalr1.cc  */
#line 4847 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 548:
/* Line 661 of lalr1.cc  */
#line 4853 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 549:
/* Line 661 of lalr1.cc  */
#line 4860 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 550:
/* Line 661 of lalr1.cc  */
#line 4871 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 551:
/* Line 661 of lalr1.cc  */
#line 4875 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 552:
/* Line 661 of lalr1.cc  */
#line 4883 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 553:
/* Line 661 of lalr1.cc  */
#line 4887 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 554:
/* Line 661 of lalr1.cc  */
#line 4895 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 555:
/* Line 661 of lalr1.cc  */
#line 4899 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 556:
/* Line 661 of lalr1.cc  */
#line 4903 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 557:
/* Line 661 of lalr1.cc  */
#line 4908 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 558:
/* Line 661 of lalr1.cc  */
#line 4917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 559:
/* Line 661 of lalr1.cc  */
#line 4921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 560:
/* Line 661 of lalr1.cc  */
#line 4925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 561:
/* Line 661 of lalr1.cc  */
#line 4929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 562:
/* Line 661 of lalr1.cc  */
#line 4937 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 563:
/* Line 661 of lalr1.cc  */
#line 4942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 564:
/* Line 661 of lalr1.cc  */
#line 4950 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 565:
/* Line 661 of lalr1.cc  */
#line 4956 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 566:
/* Line 661 of lalr1.cc  */
#line 4965 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 567:
/* Line 661 of lalr1.cc  */
#line 4973 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:
/* Line 661 of lalr1.cc  */
#line 4978 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 569:
/* Line 661 of lalr1.cc  */
#line 4983 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 570:
/* Line 661 of lalr1.cc  */
#line 4988 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 571:
/* Line 661 of lalr1.cc  */
#line 4993 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 572:
/* Line 661 of lalr1.cc  */
#line 4998 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 574:
/* Line 661 of lalr1.cc  */
#line 5009 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 575:
/* Line 661 of lalr1.cc  */
#line 5017 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 576:
/* Line 661 of lalr1.cc  */
#line 5021 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 577:
/* Line 661 of lalr1.cc  */
#line 5027 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 578:
/* Line 661 of lalr1.cc  */
#line 5031 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 579:
/* Line 661 of lalr1.cc  */
#line 5039 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 580:
/* Line 661 of lalr1.cc  */
#line 5047 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 581:
/* Line 661 of lalr1.cc  */
#line 5055 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 582:
/* Line 661 of lalr1.cc  */
#line 5059 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 583:
/* Line 661 of lalr1.cc  */
#line 5067 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 584:
/* Line 661 of lalr1.cc  */
#line 5071 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 585:
/* Line 661 of lalr1.cc  */
#line 5079 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 586:
/* Line 661 of lalr1.cc  */
#line 5087 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 587:
/* Line 661 of lalr1.cc  */
#line 5091 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 588:
/* Line 661 of lalr1.cc  */
#line 5095 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 589:
/* Line 661 of lalr1.cc  */
#line 5101 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 590:
/* Line 661 of lalr1.cc  */
#line 5107 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 591:
/* Line 661 of lalr1.cc  */
#line 5113 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 592:
/* Line 661 of lalr1.cc  */
#line 5123 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            GeneralizedAtomicType* gat = static_cast<GeneralizedAtomicType*>((yysemantic_stack_[(1) - (1)].node));
            QName* q = gat->get_qname();
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);

        }
    break;

  case 593:
/* Line 661 of lalr1.cc  */
#line 5130 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:
/* Line 661 of lalr1.cc  */
#line 5134 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 595:
/* Line 661 of lalr1.cc  */
#line 5138 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 596:
/* Line 661 of lalr1.cc  */
#line 5142 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 597:
/* Line 661 of lalr1.cc  */
#line 5146 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 598:
/* Line 661 of lalr1.cc  */
#line 5150 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 599:
/* Line 661 of lalr1.cc  */
#line 5157 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 600:
/* Line 661 of lalr1.cc  */
#line 5163 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 601:
/* Line 661 of lalr1.cc  */
#line 5173 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 602:
/* Line 661 of lalr1.cc  */
#line 5181 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 603:
/* Line 661 of lalr1.cc  */
#line 5189 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:
/* Line 661 of lalr1.cc  */
#line 5193 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:
/* Line 661 of lalr1.cc  */
#line 5197 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:
/* Line 661 of lalr1.cc  */
#line 5201 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:
/* Line 661 of lalr1.cc  */
#line 5205 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 608:
/* Line 661 of lalr1.cc  */
#line 5209 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 609:
/* Line 661 of lalr1.cc  */
#line 5213 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 610:
/* Line 661 of lalr1.cc  */
#line 5217 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:
/* Line 661 of lalr1.cc  */
#line 5221 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:
/* Line 661 of lalr1.cc  */
#line 5225 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 613:
/* Line 661 of lalr1.cc  */
#line 5233 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 614:
/* Line 661 of lalr1.cc  */
#line 5240 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 615:
/* Line 661 of lalr1.cc  */
#line 5247 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 616:
/* Line 661 of lalr1.cc  */
#line 5251 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 617:
/* Line 661 of lalr1.cc  */
#line 5255 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 618:
/* Line 661 of lalr1.cc  */
#line 5263 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 619:
/* Line 661 of lalr1.cc  */
#line 5270 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 620:
/* Line 661 of lalr1.cc  */
#line 5278 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 621:
/* Line 661 of lalr1.cc  */
#line 5286 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 622:
/* Line 661 of lalr1.cc  */
#line 5290 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 623:
/* Line 661 of lalr1.cc  */
#line 5295 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 624:
/* Line 661 of lalr1.cc  */
#line 5303 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 625:
/* Line 661 of lalr1.cc  */
#line 5307 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 626:
/* Line 661 of lalr1.cc  */
#line 5313 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 627:
/* Line 661 of lalr1.cc  */
#line 5319 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 628:
/* Line 661 of lalr1.cc  */
#line 5323 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 629:
/* Line 661 of lalr1.cc  */
#line 5333 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 630:
/* Line 661 of lalr1.cc  */
#line 5341 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 631:
/* Line 661 of lalr1.cc  */
#line 5345 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 632:
/* Line 661 of lalr1.cc  */
#line 5351 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 633:
/* Line 661 of lalr1.cc  */
#line 5360 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 634:
/* Line 661 of lalr1.cc  */
#line 5369 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 635:
/* Line 661 of lalr1.cc  */
#line 5375 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 636:
/* Line 661 of lalr1.cc  */
#line 5381 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 637:
/* Line 661 of lalr1.cc  */
#line 5391 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 638:
/* Line 661 of lalr1.cc  */
#line 5397 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 639:
/* Line 661 of lalr1.cc  */
#line 5404 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 640:
/* Line 661 of lalr1.cc  */
#line 5410 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 641:
/* Line 661 of lalr1.cc  */
#line 5416 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 642:
/* Line 661 of lalr1.cc  */
#line 5420 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 643:
/* Line 661 of lalr1.cc  */
#line 5428 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 644:
/* Line 661 of lalr1.cc  */
#line 5436 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 645:
/* Line 661 of lalr1.cc  */
#line 5440 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 646:
/* Line 661 of lalr1.cc  */
#line 5451 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 647:
/* Line 661 of lalr1.cc  */
#line 5457 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 648:
/* Line 661 of lalr1.cc  */
#line 5463 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 649:
/* Line 661 of lalr1.cc  */
#line 5469 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 650:
/* Line 661 of lalr1.cc  */
#line 5479 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 651:
/* Line 661 of lalr1.cc  */
#line 5483 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 652:
/* Line 661 of lalr1.cc  */
#line 5489 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 653:
/* Line 661 of lalr1.cc  */
#line 5495 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 654:
/* Line 661 of lalr1.cc  */
#line 5499 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 655:
/* Line 661 of lalr1.cc  */
#line 5505 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 656:
/* Line 661 of lalr1.cc  */
#line 5509 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 657:
/* Line 661 of lalr1.cc  */
#line 5515 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 658:
/* Line 661 of lalr1.cc  */
#line 5521 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 659:
/* Line 661 of lalr1.cc  */
#line 5528 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 660:
/* Line 661 of lalr1.cc  */
#line 5538 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 661:
/* Line 661 of lalr1.cc  */
#line 5543 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 662:
/* Line 661 of lalr1.cc  */
#line 5551 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 663:
/* Line 661 of lalr1.cc  */
#line 5557 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 664:
/* Line 661 of lalr1.cc  */
#line 5567 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 665:
/* Line 661 of lalr1.cc  */
#line 5573 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 666:
/* Line 661 of lalr1.cc  */
#line 5582 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 667:
/* Line 661 of lalr1.cc  */
#line 5588 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 668:
/* Line 661 of lalr1.cc  */
#line 5601 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 669:
/* Line 661 of lalr1.cc  */
#line 5607 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 670:
/* Line 661 of lalr1.cc  */
#line 5614 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 671:
/* Line 661 of lalr1.cc  */
#line 5620 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 672:
/* Line 661 of lalr1.cc  */
#line 5630 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 673:
/* Line 661 of lalr1.cc  */
#line 5639 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 674:
/* Line 661 of lalr1.cc  */
#line 5647 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 675:
/* Line 661 of lalr1.cc  */
#line 5653 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 676:
/* Line 661 of lalr1.cc  */
#line 5662 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 677:
/* Line 661 of lalr1.cc  */
#line 5670 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 678:
/* Line 661 of lalr1.cc  */
#line 5674 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 679:
/* Line 661 of lalr1.cc  */
#line 5681 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 680:
/* Line 661 of lalr1.cc  */
#line 5686 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 681:
/* Line 661 of lalr1.cc  */
#line 5694 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:
/* Line 661 of lalr1.cc  */
#line 5698 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 683:
/* Line 661 of lalr1.cc  */
#line 5705 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:
/* Line 661 of lalr1.cc  */
#line 5709 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 685:
/* Line 661 of lalr1.cc  */
#line 5716 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:
/* Line 661 of lalr1.cc  */
#line 5720 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 687:
/* Line 661 of lalr1.cc  */
#line 5727 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:
/* Line 661 of lalr1.cc  */
#line 5731 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 689:
/* Line 661 of lalr1.cc  */
#line 5740 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 690:
/* Line 661 of lalr1.cc  */
#line 5752 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 691:
/* Line 661 of lalr1.cc  */
#line 5756 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:
/* Line 661 of lalr1.cc  */
#line 5763 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:
/* Line 661 of lalr1.cc  */
#line 5767 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:
/* Line 661 of lalr1.cc  */
#line 5775 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 695:
/* Line 661 of lalr1.cc  */
#line 5783 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 696:
/* Line 661 of lalr1.cc  */
#line 5791 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 697:
/* Line 661 of lalr1.cc  */
#line 5795 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:
/* Line 661 of lalr1.cc  */
#line 5802 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 699:
/* Line 661 of lalr1.cc  */
#line 5806 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:
/* Line 661 of lalr1.cc  */
#line 5814 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 701:
/* Line 661 of lalr1.cc  */
#line 5825 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 702:
/* Line 661 of lalr1.cc  */
#line 5829 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:
/* Line 661 of lalr1.cc  */
#line 5837 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 704:
/* Line 661 of lalr1.cc  */
#line 5849 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 705:
/* Line 661 of lalr1.cc  */
#line 5855 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 706:
/* Line 661 of lalr1.cc  */
#line 5864 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 707:
/* Line 661 of lalr1.cc  */
#line 5868 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:
/* Line 661 of lalr1.cc  */
#line 5876 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 709:
/* Line 661 of lalr1.cc  */
#line 5880 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 710:
/* Line 661 of lalr1.cc  */
#line 5884 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 711:
/* Line 661 of lalr1.cc  */
#line 5891 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 712:
/* Line 661 of lalr1.cc  */
#line 5895 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 713:
/* Line 661 of lalr1.cc  */
#line 5902 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 714:
/* Line 661 of lalr1.cc  */
#line 5906 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 715:
/* Line 661 of lalr1.cc  */
#line 5914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:
/* Line 661 of lalr1.cc  */
#line 5918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:
/* Line 661 of lalr1.cc  */
#line 5922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:
/* Line 661 of lalr1.cc  */
#line 5926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 719:
/* Line 661 of lalr1.cc  */
#line 5930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 720:
/* Line 661 of lalr1.cc  */
#line 5938 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 721:
/* Line 661 of lalr1.cc  */
#line 5946 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 722:
/* Line 661 of lalr1.cc  */
#line 5958 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 723:
/* Line 661 of lalr1.cc  */
#line 5970 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 724:
/* Line 661 of lalr1.cc  */
#line 5974 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 725:
/* Line 661 of lalr1.cc  */
#line 5978 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 726:
/* Line 661 of lalr1.cc  */
#line 5986 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 727:
/* Line 661 of lalr1.cc  */
#line 5992 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 728:
/* Line 661 of lalr1.cc  */
#line 6002 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:
/* Line 661 of lalr1.cc  */
#line 6006 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:
/* Line 661 of lalr1.cc  */
#line 6010 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:
/* Line 661 of lalr1.cc  */
#line 6014 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 732:
/* Line 661 of lalr1.cc  */
#line 6018 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 733:
/* Line 661 of lalr1.cc  */
#line 6022 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 734:
/* Line 661 of lalr1.cc  */
#line 6026 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 735:
/* Line 661 of lalr1.cc  */
#line 6030 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 736:
/* Line 661 of lalr1.cc  */
#line 6038 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 737:
/* Line 661 of lalr1.cc  */
#line 6042 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 738:
/* Line 661 of lalr1.cc  */
#line 6046 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 739:
/* Line 661 of lalr1.cc  */
#line 6050 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 740:
/* Line 661 of lalr1.cc  */
#line 6058 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 741:
/* Line 661 of lalr1.cc  */
#line 6064 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 742:
/* Line 661 of lalr1.cc  */
#line 6074 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 743:
/* Line 661 of lalr1.cc  */
#line 6084 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 744:
/* Line 661 of lalr1.cc  */
#line 6088 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 745:
/* Line 661 of lalr1.cc  */
#line 6096 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 746:
/* Line 661 of lalr1.cc  */
#line 6106 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 747:
/* Line 661 of lalr1.cc  */
#line 6117 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 748:
/* Line 661 of lalr1.cc  */
#line 6124 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 749:
/* Line 661 of lalr1.cc  */
#line 6128 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 750:
/* Line 661 of lalr1.cc  */
#line 6135 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 751:
/* Line 661 of lalr1.cc  */
#line 6139 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 752:
/* Line 661 of lalr1.cc  */
#line 6146 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 753:
/* Line 661 of lalr1.cc  */
#line 6151 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 754:
/* Line 661 of lalr1.cc  */
#line 6160 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 755:
/* Line 661 of lalr1.cc  */
#line 6169 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 756:
/* Line 661 of lalr1.cc  */
#line 6173 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 757:
/* Line 661 of lalr1.cc  */
#line 6180 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 758:
/* Line 661 of lalr1.cc  */
#line 6184 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 759:
/* Line 661 of lalr1.cc  */
#line 6192 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 760:
/* Line 661 of lalr1.cc  */
#line 6201 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 761:
/* Line 661 of lalr1.cc  */
#line 6208 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 762:
/* Line 661 of lalr1.cc  */
#line 6218 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 763:
/* Line 661 of lalr1.cc  */
#line 6222 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 764:
/* Line 661 of lalr1.cc  */
#line 6229 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 765:
/* Line 661 of lalr1.cc  */
#line 6235 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 766:
/* Line 661 of lalr1.cc  */
#line 6244 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 767:
/* Line 661 of lalr1.cc  */
#line 6248 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 768:
/* Line 661 of lalr1.cc  */
#line 6255 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 769:
/* Line 661 of lalr1.cc  */
#line 6260 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 770:
/* Line 661 of lalr1.cc  */
#line 6272 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 771:
/* Line 661 of lalr1.cc  */
#line 6280 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 772:
/* Line 661 of lalr1.cc  */
#line 6292 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 773:
/* Line 661 of lalr1.cc  */
#line 6300 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 774:
/* Line 661 of lalr1.cc  */
#line 6304 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 775:
/* Line 661 of lalr1.cc  */
#line 6312 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 776:
/* Line 661 of lalr1.cc  */
#line 6316 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 777:
/* Line 661 of lalr1.cc  */
#line 6320 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 778:
/* Line 661 of lalr1.cc  */
#line 6328 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 779:
/* Line 661 of lalr1.cc  */
#line 6336 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 780:
/* Line 661 of lalr1.cc  */
#line 6340 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 781:
/* Line 661 of lalr1.cc  */
#line 6344 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 782:
/* Line 661 of lalr1.cc  */
#line 6348 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 783:
/* Line 661 of lalr1.cc  */
#line 6356 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 784:
/* Line 661 of lalr1.cc  */
#line 6364 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 785:
/* Line 661 of lalr1.cc  */
#line 6376 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 786:
/* Line 661 of lalr1.cc  */
#line 6380 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 787:
/* Line 661 of lalr1.cc  */
#line 6388 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 788:
/* Line 661 of lalr1.cc  */
#line 6394 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 789:
/* Line 661 of lalr1.cc  */
#line 6398 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 790:
/* Line 661 of lalr1.cc  */
#line 6405 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 791:
/* Line 661 of lalr1.cc  */
#line 6409 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 792:
/* Line 661 of lalr1.cc  */
#line 6416 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 793:
/* Line 661 of lalr1.cc  */
#line 6420 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 794:
/* Line 661 of lalr1.cc  */
#line 6428 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 795:
/* Line 661 of lalr1.cc  */
#line 6436 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 796:
/* Line 661 of lalr1.cc  */
#line 6442 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 797:
/* Line 661 of lalr1.cc  */
#line 6452 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 798:
/* Line 661 of lalr1.cc  */
#line 6458 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
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

  case 799:
/* Line 661 of lalr1.cc  */
#line 6468 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 800:
/* Line 661 of lalr1.cc  */
#line 6475 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 801:
/* Line 661 of lalr1.cc  */
#line 6482 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          rchandle<exprnode> lTargetExpr;
          rchandle<exprnode> lSelectorExpr;
          string lError;
          if (!convert_postfix_to_target_and_selector((yysemantic_stack_[(3) - (3)].expr), &lTargetExpr, &lSelectorExpr, &lError))
          {
            error((yylocation_stack_[(3) - (2)]), lError);
            YYERROR;
          }
          (yyval.expr) = new JSONDeleteExpr(
              LOC((yyloc)),
              lTargetExpr,
              lSelectorExpr);
        }
    break;

  case 802:
/* Line 661 of lalr1.cc  */
#line 6500 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          rchandle<exprnode> lTargetExpr;
          rchandle<exprnode> lSelectorExpr;
          string lError;
          if (!convert_postfix_to_target_and_selector(
              (yysemantic_stack_[(5) - (3)].expr),
              &lTargetExpr,
              &lSelectorExpr,
              &lError,
              false))
          {
            error((yylocation_stack_[(5) - (3)]), lError);
            delete (yysemantic_stack_[(5) - (5)].expr);
            YYERROR;
          }
          (yyval.expr) = new JSONRenameExpr(
                LOC((yyloc)),
                lTargetExpr,
                lSelectorExpr,
                (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 803:
/* Line 661 of lalr1.cc  */
#line 6525 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          rchandle<exprnode> lTargetExpr;
          rchandle<exprnode> lSelectorExpr;
          string lError;
          if (!convert_postfix_to_target_and_selector((yysemantic_stack_[(7) - (5)].expr), &lTargetExpr, &lSelectorExpr, &lError))
          {
            error((yylocation_stack_[(7) - (5)]), lError);
            delete (yysemantic_stack_[(7) - (7)].expr);
            YYERROR;
          }
          (yyval.expr) = new JSONReplaceExpr(
                LOC((yyloc)),
                lTargetExpr,
                lSelectorExpr,
                (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 804:
/* Line 661 of lalr1.cc  */
#line 6545 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 805:
/* Line 661 of lalr1.cc  */
#line 6549 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 806:
/* Line 661 of lalr1.cc  */
#line 6553 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 809:
/* Line 661 of lalr1.cc  */
#line 6571 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 810:
/* Line 661 of lalr1.cc  */
#line 6572 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 811:
/* Line 661 of lalr1.cc  */
#line 6573 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 812:
/* Line 661 of lalr1.cc  */
#line 6574 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 813:
/* Line 661 of lalr1.cc  */
#line 6575 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 814:
/* Line 661 of lalr1.cc  */
#line 6576 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 815:
/* Line 661 of lalr1.cc  */
#line 6577 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 816:
/* Line 661 of lalr1.cc  */
#line 6578 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 817:
/* Line 661 of lalr1.cc  */
#line 6579 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 818:
/* Line 661 of lalr1.cc  */
#line 6580 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 819:
/* Line 661 of lalr1.cc  */
#line 6581 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 820:
/* Line 661 of lalr1.cc  */
#line 6582 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 821:
/* Line 661 of lalr1.cc  */
#line 6583 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 822:
/* Line 661 of lalr1.cc  */
#line 6584 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 823:
/* Line 661 of lalr1.cc  */
#line 6585 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 824:
/* Line 661 of lalr1.cc  */
#line 6586 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 825:
/* Line 661 of lalr1.cc  */
#line 6587 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 826:
/* Line 661 of lalr1.cc  */
#line 6588 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 827:
/* Line 661 of lalr1.cc  */
#line 6589 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 828:
/* Line 661 of lalr1.cc  */
#line 6590 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 829:
/* Line 661 of lalr1.cc  */
#line 6591 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 830:
/* Line 661 of lalr1.cc  */
#line 6592 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 832:
/* Line 661 of lalr1.cc  */
#line 6597 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 833:
/* Line 661 of lalr1.cc  */
#line 6598 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 834:
/* Line 661 of lalr1.cc  */
#line 6599 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 835:
/* Line 661 of lalr1.cc  */
#line 6600 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 836:
/* Line 661 of lalr1.cc  */
#line 6601 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 837:
/* Line 661 of lalr1.cc  */
#line 6602 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 838:
/* Line 661 of lalr1.cc  */
#line 6603 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 839:
/* Line 661 of lalr1.cc  */
#line 6604 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 840:
/* Line 661 of lalr1.cc  */
#line 6605 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 841:
/* Line 661 of lalr1.cc  */
#line 6606 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 842:
/* Line 661 of lalr1.cc  */
#line 6607 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 843:
/* Line 661 of lalr1.cc  */
#line 6608 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 844:
/* Line 661 of lalr1.cc  */
#line 6609 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 845:
/* Line 661 of lalr1.cc  */
#line 6610 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 846:
/* Line 661 of lalr1.cc  */
#line 6611 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 847:
/* Line 661 of lalr1.cc  */
#line 6612 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 848:
/* Line 661 of lalr1.cc  */
#line 6613 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 849:
/* Line 661 of lalr1.cc  */
#line 6614 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 850:
/* Line 661 of lalr1.cc  */
#line 6615 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 851:
/* Line 661 of lalr1.cc  */
#line 6616 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 852:
/* Line 661 of lalr1.cc  */
#line 6617 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 853:
/* Line 661 of lalr1.cc  */
#line 6618 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 854:
/* Line 661 of lalr1.cc  */
#line 6619 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 855:
/* Line 661 of lalr1.cc  */
#line 6620 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 856:
/* Line 661 of lalr1.cc  */
#line 6621 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 857:
/* Line 661 of lalr1.cc  */
#line 6622 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 858:
/* Line 661 of lalr1.cc  */
#line 6623 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 859:
/* Line 661 of lalr1.cc  */
#line 6624 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 860:
/* Line 661 of lalr1.cc  */
#line 6625 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 861:
/* Line 661 of lalr1.cc  */
#line 6626 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 862:
/* Line 661 of lalr1.cc  */
#line 6627 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 863:
/* Line 661 of lalr1.cc  */
#line 6628 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 864:
/* Line 661 of lalr1.cc  */
#line 6629 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 865:
/* Line 661 of lalr1.cc  */
#line 6630 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 866:
/* Line 661 of lalr1.cc  */
#line 6631 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 867:
/* Line 661 of lalr1.cc  */
#line 6632 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 868:
/* Line 661 of lalr1.cc  */
#line 6633 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 869:
/* Line 661 of lalr1.cc  */
#line 6634 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 870:
/* Line 661 of lalr1.cc  */
#line 6635 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 871:
/* Line 661 of lalr1.cc  */
#line 6636 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 872:
/* Line 661 of lalr1.cc  */
#line 6637 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 873:
/* Line 661 of lalr1.cc  */
#line 6638 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 874:
/* Line 661 of lalr1.cc  */
#line 6639 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 875:
/* Line 661 of lalr1.cc  */
#line 6640 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 876:
/* Line 661 of lalr1.cc  */
#line 6641 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 877:
/* Line 661 of lalr1.cc  */
#line 6642 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 878:
/* Line 661 of lalr1.cc  */
#line 6643 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 879:
/* Line 661 of lalr1.cc  */
#line 6644 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 880:
/* Line 661 of lalr1.cc  */
#line 6645 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 881:
/* Line 661 of lalr1.cc  */
#line 6646 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 882:
/* Line 661 of lalr1.cc  */
#line 6647 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 883:
/* Line 661 of lalr1.cc  */
#line 6648 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 884:
/* Line 661 of lalr1.cc  */
#line 6649 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 885:
/* Line 661 of lalr1.cc  */
#line 6650 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("offset"))); }
    break;

  case 886:
/* Line 661 of lalr1.cc  */
#line 6651 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("limit"))); }
    break;

  case 887:
/* Line 661 of lalr1.cc  */
#line 6652 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 888:
/* Line 661 of lalr1.cc  */
#line 6653 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 889:
/* Line 661 of lalr1.cc  */
#line 6654 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 890:
/* Line 661 of lalr1.cc  */
#line 6655 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 891:
/* Line 661 of lalr1.cc  */
#line 6656 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 892:
/* Line 661 of lalr1.cc  */
#line 6657 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 893:
/* Line 661 of lalr1.cc  */
#line 6658 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 894:
/* Line 661 of lalr1.cc  */
#line 6659 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 895:
/* Line 661 of lalr1.cc  */
#line 6660 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 896:
/* Line 661 of lalr1.cc  */
#line 6661 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 897:
/* Line 661 of lalr1.cc  */
#line 6662 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 898:
/* Line 661 of lalr1.cc  */
#line 6663 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 899:
/* Line 661 of lalr1.cc  */
#line 6664 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 900:
/* Line 661 of lalr1.cc  */
#line 6665 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 901:
/* Line 661 of lalr1.cc  */
#line 6666 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 902:
/* Line 661 of lalr1.cc  */
#line 6667 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 903:
/* Line 661 of lalr1.cc  */
#line 6668 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 904:
/* Line 661 of lalr1.cc  */
#line 6669 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 905:
/* Line 661 of lalr1.cc  */
#line 6670 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 906:
/* Line 661 of lalr1.cc  */
#line 6671 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 907:
/* Line 661 of lalr1.cc  */
#line 6672 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 908:
/* Line 661 of lalr1.cc  */
#line 6673 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 909:
/* Line 661 of lalr1.cc  */
#line 6674 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 910:
/* Line 661 of lalr1.cc  */
#line 6675 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 911:
/* Line 661 of lalr1.cc  */
#line 6676 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 912:
/* Line 661 of lalr1.cc  */
#line 6677 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 913:
/* Line 661 of lalr1.cc  */
#line 6678 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 914:
/* Line 661 of lalr1.cc  */
#line 6679 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 915:
/* Line 661 of lalr1.cc  */
#line 6680 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 916:
/* Line 661 of lalr1.cc  */
#line 6681 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 917:
/* Line 661 of lalr1.cc  */
#line 6682 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 918:
/* Line 661 of lalr1.cc  */
#line 6683 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 919:
/* Line 661 of lalr1.cc  */
#line 6684 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 920:
/* Line 661 of lalr1.cc  */
#line 6685 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 921:
/* Line 661 of lalr1.cc  */
#line 6686 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 922:
/* Line 661 of lalr1.cc  */
#line 6687 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 923:
/* Line 661 of lalr1.cc  */
#line 6688 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 924:
/* Line 661 of lalr1.cc  */
#line 6689 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 925:
/* Line 661 of lalr1.cc  */
#line 6690 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 926:
/* Line 661 of lalr1.cc  */
#line 6691 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 927:
/* Line 661 of lalr1.cc  */
#line 6692 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 928:
/* Line 661 of lalr1.cc  */
#line 6693 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 929:
/* Line 661 of lalr1.cc  */
#line 6694 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 930:
/* Line 661 of lalr1.cc  */
#line 6695 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 931:
/* Line 661 of lalr1.cc  */
#line 6696 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 932:
/* Line 661 of lalr1.cc  */
#line 6697 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 933:
/* Line 661 of lalr1.cc  */
#line 6698 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 934:
/* Line 661 of lalr1.cc  */
#line 6699 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 935:
/* Line 661 of lalr1.cc  */
#line 6700 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 936:
/* Line 661 of lalr1.cc  */
#line 6701 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 937:
/* Line 661 of lalr1.cc  */
#line 6702 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 938:
/* Line 661 of lalr1.cc  */
#line 6703 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 939:
/* Line 661 of lalr1.cc  */
#line 6704 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 940:
/* Line 661 of lalr1.cc  */
#line 6705 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 941:
/* Line 661 of lalr1.cc  */
#line 6706 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 942:
/* Line 661 of lalr1.cc  */
#line 6707 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 943:
/* Line 661 of lalr1.cc  */
#line 6708 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 944:
/* Line 661 of lalr1.cc  */
#line 6709 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 945:
/* Line 661 of lalr1.cc  */
#line 6710 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 946:
/* Line 661 of lalr1.cc  */
#line 6711 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 947:
/* Line 661 of lalr1.cc  */
#line 6712 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 948:
/* Line 661 of lalr1.cc  */
#line 6713 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 949:
/* Line 661 of lalr1.cc  */
#line 6714 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 950:
/* Line 661 of lalr1.cc  */
#line 6715 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 951:
/* Line 661 of lalr1.cc  */
#line 6716 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 952:
/* Line 661 of lalr1.cc  */
#line 6717 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 953:
/* Line 661 of lalr1.cc  */
#line 6718 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 954:
/* Line 661 of lalr1.cc  */
#line 6719 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 955:
/* Line 661 of lalr1.cc  */
#line 6720 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 956:
/* Line 661 of lalr1.cc  */
#line 6721 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 957:
/* Line 661 of lalr1.cc  */
#line 6722 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 958:
/* Line 661 of lalr1.cc  */
#line 6723 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 959:
/* Line 661 of lalr1.cc  */
#line 6724 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 960:
/* Line 661 of lalr1.cc  */
#line 6725 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 961:
/* Line 661 of lalr1.cc  */
#line 6726 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 962:
/* Line 661 of lalr1.cc  */
#line 6727 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 963:
/* Line 661 of lalr1.cc  */
#line 6728 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 964:
/* Line 661 of lalr1.cc  */
#line 6729 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 965:
/* Line 661 of lalr1.cc  */
#line 6730 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 966:
/* Line 661 of lalr1.cc  */
#line 6731 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 967:
/* Line 661 of lalr1.cc  */
#line 6732 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 968:
/* Line 661 of lalr1.cc  */
#line 6733 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 969:
/* Line 661 of lalr1.cc  */
#line 6734 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 970:
/* Line 661 of lalr1.cc  */
#line 6735 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 971:
/* Line 661 of lalr1.cc  */
#line 6736 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 972:
/* Line 661 of lalr1.cc  */
#line 6737 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 973:
/* Line 661 of lalr1.cc  */
#line 6738 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 974:
/* Line 661 of lalr1.cc  */
#line 6739 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 975:
/* Line 661 of lalr1.cc  */
#line 6740 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 976:
/* Line 661 of lalr1.cc  */
#line 6741 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 977:
/* Line 661 of lalr1.cc  */
#line 6742 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 978:
/* Line 661 of lalr1.cc  */
#line 6743 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 979:
/* Line 661 of lalr1.cc  */
#line 6744 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 980:
/* Line 661 of lalr1.cc  */
#line 6745 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 981:
/* Line 661 of lalr1.cc  */
#line 6746 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 982:
/* Line 661 of lalr1.cc  */
#line 6747 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 983:
/* Line 661 of lalr1.cc  */
#line 6748 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 984:
/* Line 661 of lalr1.cc  */
#line 6749 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 985:
/* Line 661 of lalr1.cc  */
#line 6750 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 986:
/* Line 661 of lalr1.cc  */
#line 6751 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 987:
/* Line 661 of lalr1.cc  */
#line 6752 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 988:
/* Line 661 of lalr1.cc  */
#line 6753 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 989:
/* Line 661 of lalr1.cc  */
#line 6754 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 990:
/* Line 661 of lalr1.cc  */
#line 6755 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 991:
/* Line 661 of lalr1.cc  */
#line 6756 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 992:
/* Line 661 of lalr1.cc  */
#line 6757 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 993:
/* Line 661 of lalr1.cc  */
#line 6758 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 994:
/* Line 661 of lalr1.cc  */
#line 6759 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 995:
/* Line 661 of lalr1.cc  */
#line 6760 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 996:
/* Line 661 of lalr1.cc  */
#line 6761 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 997:
/* Line 661 of lalr1.cc  */
#line 6762 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 998:
/* Line 661 of lalr1.cc  */
#line 6763 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 999:
/* Line 661 of lalr1.cc  */
#line 6764 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 1000:
/* Line 661 of lalr1.cc  */
#line 6765 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 1001:
/* Line 661 of lalr1.cc  */
#line 6766 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 1002:
/* Line 661 of lalr1.cc  */
#line 6767 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 1003:
/* Line 661 of lalr1.cc  */
#line 6768 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 1004:
/* Line 661 of lalr1.cc  */
#line 6769 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 1005:
/* Line 661 of lalr1.cc  */
#line 6770 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1006:
/* Line 661 of lalr1.cc  */
#line 6771 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1007:
/* Line 661 of lalr1.cc  */
#line 6772 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1008:
/* Line 661 of lalr1.cc  */
#line 6773 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1009:
/* Line 661 of lalr1.cc  */
#line 6774 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1010:
/* Line 661 of lalr1.cc  */
#line 6775 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1011:
/* Line 661 of lalr1.cc  */
#line 6776 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1012:
/* Line 661 of lalr1.cc  */
#line 6777 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1013:
/* Line 661 of lalr1.cc  */
#line 6778 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1014:
/* Line 661 of lalr1.cc  */
#line 6779 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1015:
/* Line 661 of lalr1.cc  */
#line 6780 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1016:
/* Line 661 of lalr1.cc  */
#line 6781 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1017:
/* Line 661 of lalr1.cc  */
#line 6782 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1018:
/* Line 661 of lalr1.cc  */
#line 6783 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1019:
/* Line 661 of lalr1.cc  */
#line 6784 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1020:
/* Line 661 of lalr1.cc  */
#line 6785 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1021:
/* Line 661 of lalr1.cc  */
#line 6786 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1022:
/* Line 661 of lalr1.cc  */
#line 6787 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1023:
/* Line 661 of lalr1.cc  */
#line 6788 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1024:
/* Line 661 of lalr1.cc  */
#line 6789 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1025:
/* Line 661 of lalr1.cc  */
#line 6790 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1026:
/* Line 661 of lalr1.cc  */
#line 6791 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1027:
/* Line 661 of lalr1.cc  */
#line 6792 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1028:
/* Line 661 of lalr1.cc  */
#line 6793 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1029:
/* Line 661 of lalr1.cc  */
#line 6794 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1030:
/* Line 661 of lalr1.cc  */
#line 6795 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1031:
/* Line 661 of lalr1.cc  */
#line 6796 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1032:
/* Line 661 of lalr1.cc  */
#line 6797 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1033:
/* Line 661 of lalr1.cc  */
#line 6798 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1034:
/* Line 661 of lalr1.cc  */
#line 6810 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 661 of lalr1.cc  */
#line 10745 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1512;
  const short int
  xquery_parser::yypact_[] =
  {
      4629, -1512, -1512, -1512, -1512,  6193,  6193,  6193,  6193, -1512,
   -1512,   250,   329, -1512,    65,   111, -1512, -1512, -1512,   738,
   -1512, -1512, -1512,   456,   407,   789,  2240,   489,   517,   865,
   -1512,   -22, -1512,   542, -1512, -1512, -1512, -1512, -1512,   829,
   -1512,   548,   693, -1512, -1512, -1512, -1512,   270, -1512,   831,
   -1512,   717,   824, -1512,   284, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   676,
     887, -1512, -1512, -1512, -1512,   667, 12433, -1512, -1512, -1512,
     895, -1512, -1512, -1512,   904, -1512,   902,   903, -1512, -1512,
   16330, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   908,
   -1512, -1512,   905,   906, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512,  5257,  8689,  9001, 16330, -1512, -1512,   591, -1512, -1512,
   -1512, -1512,   876, -1512, -1512,   911, 16330, -1512, 13350,   912,
     914, -1512, -1512, -1512, -1512, -1512,   916, -1512, -1512, 11809,
   -1512, -1512, -1512, -1512, -1512, -1512,   886, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,    77,   823, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,   212,   885,   272, -1512,  -112,
     648, -1512, -1512, -1512, -1512, -1512, -1512,   925, -1512,   803,
     804,   801, -1512, -1512,   891,   898, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,  9313,
    9625, -1512,   733, -1512, -1512, -1512, -1512, -1512,  4943,  6505,
    1053, -1512,  6817, -1512, -1512,   644,    99, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512,   100, -1512, -1512, -1512, -1512, -1512, -1512,   375, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512,  6193, -1512, -1512,
   -1512, -1512,    17, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512,   216, -1512,   864, -1512, -1512, -1512,   765, -1512,
     454, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   890,   965,
   -1512,   880,   809,   961,   681,   595,   441,   756, -1512,  1012,
     863,   967,   964, 10249, -1512,   875, -1512, -1512,   611, -1512,
   -1512, 12121, -1512,    13, -1512,   919, 12433, -1512,   919, 12433,
   -1512, -1512, -1512,   697, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512,   918, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   788,
   -1512, -1512, -1512, -1512, -1512,   892, -1512,  6193,   893,   896,
     897,  6193,   402,   402,  1041,    -1,   510,   530, 16922, 16330,
     265,  1032, 16330,   939,   974,   556, 16330,   771,   846, 16330,
   16330,   790,   816,    71, -1512, -1512, -1512, 16330,  6193,   909,
    6193,   331, 10561, 13648, 16330,   227,   941, 10561,  1096,   219,
      84, 16330,   981,   958,   995, -1512,   915, 10561, 13946, 16330,
   16330, 16330,  6193,   920, 10561, 10561, 16330,  6193,   951,   954,
   -1512, -1512, -1512, 10561, 14244,   953, -1512,   957, -1512, -1512,
   -1512, -1512,   959, -1512,   960, -1512, -1512, -1512, -1512, -1512,
     963, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, 16330,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512,   968, 16330, -1512, -1512, -1512,   931,  5569,
    1000,   -12,   969,   970,   971, 16330,  6193, -1512,   977,   226,
   -1512,   765, -1512,    87,  1097, 10561, 10561, -1512,    86, -1512,
   -1512,  1116, -1512, -1512, -1512, -1512, 10561,   922, -1512,  1104,
   10561, 10561, 16632, 10561, 10561, 10561, 10561, 16632, 10561,   910,
   16330,   943,   944, 10561, 10561,  5257,   899, -1512,    66, -1512,
      62, 10561,  6505, -1512, -1512, -1512, -1512, -1512,    65,   865,
     106,   115,  1134,  7129,  3370,  7441,  3693,   904, -1512, -1512,
     240,   904, -1512, 10561,  4317, -1512,  1023,   642,   -22,   976,
     975,   979, 10561, 10561, -1512, 10561, -1512, -1512,  6193, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   861,   867,
   16330,  1035, 10873, 10873, 10873, -1512, 10873, 10873, -1512, 10873,
   -1512, 10873, -1512, -1512, -1512, -1512, -1512, -1512, -1512, 10873,
   10873,  1080, 10873, 10873, 10873, 10873, 10873, 10873, 10873, 10873,
   10873, 10873, 10873, 10873,   923,  1060,  1062,  1063, -1512, -1512,
   -1512, 11497,  6193, -1512, -1512, 11809, 11809, 10561,   919, -1512,
   -1512,   919, -1512,  8065,   919,   978,  1009,  8377, -1512, -1512,
   -1512, -1512,   401, -1512,   406, -1512, -1512, -1512, -1512, -1512,
   -1512,  1052,  1055,   489,  1135, -1512, -1512, 16922,   917,   684,
   16330,  1003,  1005,   917,  1041,  1040,  1037, -1512, -1512, -1512,
     399,   924,  1076,   872, 16330,  1031, 10561,  1056, 16330, 16330,
   -1512,  1043,   994, -1512,   996,   957,   693, -1512,   988,   990,
     165, -1512,   411,   445,  1073, -1512,    37, 16330,  1087,   466,
   -1512,  6193, -1512,   120, -1512, 16330,  1086,  1139, 16330,  1041,
    1088,   626, 16330, 10561,   -22, -1512,   175,   998, -1512,   999,
    1001,  1002,   239, -1512,   311,  1008, -1512,   125,   140,  1039,
   -1512,  1010,  6193,  6193,   230, -1512,   498,   506,   662, 10561,
     255, -1512, -1512, 10561, 10561, -1512, 10561, 10561, 10561, -1512,
   10561, -1512, 10561, -1512, 16330,  1097, -1512,     2,   237,   267,
   -1512, -1512, -1512,   300, -1512,    27, -1512, -1512,  1042,  1044,
    1045,  1046,  1047,   697,   788,   215,   232,     8,    20,  1094,
     494,   956,   -98,     5, -1512,  1054, -1512, -1512,  1014,   143,
    5569,   364, 12745,   899, -1512, -1512, -1512,   972, -1512,   644,
     702,  1169,   167, -1512, -1512,   116, -1512, -1512, -1512,   119,
   -1512,   108, -1512, -1512, -1512, -1512, -1512,  4005, -1512, -1512,
   -1512, 16330,  1034, 10561, 11185, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512,  1073, 16330,    33,   965, -1512, -1512, -1512, -1512,
   -1512, 10873, -1512, -1512, -1512,    80, -1512,   595,   595,   630,
     441,   441,   441,   441,   756,   756, -1512, -1512, 15436, 15436,
   16330, 16330, -1512,  1026, -1512, -1512,   235, -1512, -1512, -1512,
   -1512,   508, -1512, -1512, -1512,   521,   402, -1512, -1512,   669,
     695,   708, -1512,   489, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512,   917, -1512,  1078, 15734,  1070, 10561,
   -1512, -1512, -1512,  1119,  1041,  1041,   917, -1512,   828,  1041,
     682, 16330,   673,   674,  1186, -1512, -1512,   929,   572, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
     399,    98,   991,   609, 10561, -1512, 16330,  1124,   927,  1041,
   -1512, -1512, -1512, -1512,  1068, 16330, -1512, 16330, -1512, 16032,
    1095, 15436,  1105, 10561,   171,  1077,    51,  1119, 15436,  1107,
    1136,  1048,  1029,  1100,  1041,  1069,  1101,  1138,  1041, 10561,
     -52, -1512, -1512, -1512,  1082, -1512, -1512, -1512, -1512,  1118,
   10561, 10561,  1090, -1512,  1140,  1141,  6193, -1512,  1059,  1064,
    1085, 16330, -1512, 16330, -1512, 10561,  1103,  1057, 10561, -1512,
    1122,   148,   155,   161,  1205, -1512,   291, -1512,   461,  1093,
   -1512, -1512,  1220, -1512,   308, 10561, 10561, 10561,   688, 10561,
   10561, 10561, 10561, 10561, 10561, 10561, 10561, 10561, 16632,  1132,
   10561, 10561, -1512,  7753,   264,  1011, -1512,   -45, -1512, 10561,
     123,   174,   108,  7441,  3693,  7441,  1176, -1512, -1512, 10561,
     777,  1149, -1512, 16330,  1152,  1154, -1512,   588,  1004, -1512,
   -1512,   690,    33, -1512, 10561,    80,   550,   678, -1512,   980,
     286,  1006,  1013, -1512, -1512,   846, -1512,  1007,   422,  1106,
    1108, 15734,  1113,  1114,  1115,  1117,  1120, -1512,   335, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,  1128,
   -1512, -1512, -1512, -1512,  9937, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512,   718, -1512,  1248,   827, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512,  1016, -1512, -1512,
    1249, -1512, -1512, -1512, -1512, -1512,   653,  1251, -1512,   706,
   -1512, -1512, -1512,   953,   407,   542,   959,   548,   960,   963,
   -1512,  1114,  1115,  1117, -1512,   335,   335, 11497,   997,   982,
   -1512,  1119,    98,  1058,  1091,  6193,  1099,  1109,  1137,  1111,
    1112, 16330, -1512,   541, -1512, 16330, -1512, 10561,  1144, 10561,
    1156, 10561,   204,  1145, -1512, -1512, -1512, 15436, -1512,  6193,
    1041,  1181, -1512, -1512, -1512,  1041,  1181, -1512, 10561,  1151,
    6193, 16330, -1512, -1512, 10561, 10561,   431, -1512,   222,   795,
   -1512, 14542,   802, -1512,   811, -1512,  1123, -1512, -1512,  6193,
    1121,  1125, -1512, 10561, -1512, -1512, 10561,  1102,  1140,  1194,
   -1512,  1173, -1512,   622, -1512, -1512,  1301, -1512, -1512,  6193,
   16330, -1512,   763, -1512, -1512, -1512,  6193,  1126,  1081,  1089,
   -1512, -1512, -1512,  1092,  1098, -1512, -1512, -1512,  1214, -1512,
   -1512, -1512, -1512,  1074,   452, 16330,  1129, -1512,  1155,  1163,
    1164,  1171, -1512,   864,   765, 12745,  1011, -1512,  5881, 12745,
   -1512, -1512,  1169,   416, -1512, -1512, -1512,  1149, -1512,  1041,
   -1512,   847, -1512,   451,  1216, -1512, 10561,   687,  1041, -1512,
   11185, 10561,  1180, -1512,  1210,  1212, 10561, 16330,   921,  1256,
   -1512, -1512, -1512,   377,  1147, -1512,    80,  1110, -1512, -1512,
     -48, -1512,   581,   128,  1127,    80,   581, 10873, -1512,   261,
   -1512, -1512, -1512, -1512, -1512, -1512,    80,  1189,  1065,   924,
     128, -1512, -1512,  1050,  1261, -1512, -1512, -1512, 13043,  1157,
    1158,  1159,  1161,  1165,  1166,  1168, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,  1329,
      10,  1331,    10,  1130,  1258, -1512, -1512,  1197, 16330,  1133,
   -1512, -1512, 11497, -1512,  1185, -1512, -1512, -1512, -1512, -1512,
   -1512, 10561,  1222, -1512, -1512, 10561, -1512,   593, -1512, 10561,
    1224, 10561, -1512,  1246,  1250,  1279,  1041,  1181, -1512, 10561,
    1196, -1512, -1512, -1512,  1129, -1512,   222, 10561,  6193,  1129,
     222, -1512, 16330,   293, -1512, 14840,   543, -1512, 15138,  1129,
   -1512, -1512,  1198, -1512, -1512, -1512, -1512, 10561,   830,  1205,
   16330,   774, -1512,  1200,  1205, 16330, -1512,  1202, -1512, 10561,
   10561, 10561, 10561,  1071, 10561, 10561, -1512, 10561, 10561, 10561,
   10561,  7753,   271, -1512, -1512, -1512, -1512, -1512,  1216, -1512,
   -1512, -1512, 10561,  1238, -1512, -1512, -1512, 10561, 16330, 16330,
   -1512,   772, -1512, 10561, -1512, -1512, -1512,  1204, 10873, -1512,
   -1512, -1512, -1512, -1512,   374, 10873, 10873,   652, -1512,  1006,
   -1512,   410, -1512,  1013,    80,  1237, -1512, -1512,  1131, -1512,
   -1512, -1512, -1512,  1298,  1206, -1512,   551, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,   641,   641, -1512,    10, -1512,
   -1512,   558, -1512,  1364,   128,  1299,  1208, 11497,    12,  1142,
    1228, -1512, -1512, 10561, -1512, 10561,  1252, -1512, 10561, -1512,
    7753, 10561,  1041, -1512, -1512, -1512, 10561, 10561, -1512, -1512,
   -1512,  7753,  7753,  1304, 15436,  6193, 16330,   293, 16330, 10561,
   16330,   293,  7753, -1512,   549,    88,  1205, 16330, -1512,  1203,
    1205, -1512, -1512, -1512, -1512, -1512, 10561, -1512, -1512, -1512,
     192,   223,   234, 10561, -1512, -1512,  1152, 10561, -1512, -1512,
    1347, -1512, -1512, -1512,   441, 10873, 10873,   630,   707, -1512,
   -1512, -1512, -1512, -1512, -1512, 10561, -1512, 15436, -1512, 15436,
    1309, -1512, -1512, -1512,  1375, -1512, -1512, -1512,  1148,  1300,
   -1512, -1512,  1303, -1512,   262, 16330,  1287,  1182, 16330, 11497,
   -1512, -1512, 10561, -1512, -1512, -1512,  1181, -1512, -1512, 15436,
   -1512, -1512, -1512,  1312, 10561,  1129, -1512,  1317,  7753, -1512,
   16330,   457,   604, -1512,  1215,  1205, -1512,  1217, -1512,  1218,
    1140,  1141,   384, -1512,  1152,  1302,   630,   630, 10873,   387,
   -1512, -1512, 15436, -1512, -1512,  1299, 11497, -1512,  1216,  1146,
   16330,  1305,  1190,  1303, -1512,   293, 15436,  6193, 15436,  1129,
   -1512, -1512,  1325,   468, -1512, -1512, -1512, -1512,  1240,   608,
   -1512, -1512, -1512,  1221, -1512,  7753,   841, -1512, -1512, 16330,
     630, -1512, -1512, -1512, -1512, -1512, 10561,  1153, 16330,  1306,
    6193,   293, -1512, -1512,   293, 10561, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512,  1307, -1512, -1512,  1143,  1160, 16330, -1512,
   -1512, 10561,  7753, 16330,  1150, 10561,  1162,  1129, 11497, -1512,
   11497,  7753, -1512,  1229,  1170, 16330,  1207,  1314, 16330,  1172,
   11497, -1512
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   473,   474,   809,   475,   168,   168,   168,     0,   832,
    1034,   120,   122,   640,   927,   936,   874,   837,   835,   811,
     928,   931,   881,   841,   812,   814,     0,   937,   816,   934,
     905,   883,   857,   813,   878,   879,   932,   929,   877,   818,
     935,   819,   820,   976,   988,   975,   875,   896,   890,   821,
     876,   823,   822,   977,   914,   915,   880,   854,   998,   999,
    1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1022,
    1029,   904,   900,   891,   868,   810,     0,   899,   907,   916,
    1023,   895,   499,   869,   870,   930,  1024,  1030,   892,   909,
       0,   505,   462,   501,   902,   834,   893,   894,   923,   897,
     913,   922,  1028,  1031,   840,   882,   925,   500,   912,   918,
     815,     0,     0,     0,     0,   409,   910,   921,   926,   924,
     903,   889,   978,   887,   888,  1025,     0,   408,     0,  1026,
    1032,   919,   885,   886,   871,   898,  1027,   212,   440,     0,
     472,   920,   901,   908,   917,   911,   979,   862,   867,   866,
     865,   864,   863,   824,   884,     0,   833,   933,   855,   969,
     968,   970,   839,   838,   858,   967,   817,   964,   972,   966,
     965,   861,   906,   962,   974,   973,   961,   859,   971,   983,
     984,   981,   982,   980,   825,   985,   986,   987,   953,   952,
     939,   853,   846,   946,   942,   856,   852,   954,   873,   842,
     843,   836,   845,   951,   950,   947,   943,   959,   960,   958,
     949,   945,   938,   844,   957,   956,   848,   850,   849,   944,
     948,   940,   851,   941,   847,   955,  1009,  1010,  1011,  1012,
    1013,  1014,   990,   991,   989,   995,   996,   997,   992,   993,
     994,   860,  1015,  1016,  1017,  1018,  1019,  1020,  1021,     0,
       0,   826,   963,  1033,   828,   827,   829,   830,   165,   165,
       0,     2,   165,     9,    11,    23,     0,    28,    31,    36,
      37,    38,    39,    40,    41,    42,    32,    58,    59,    33,
      34,     0,    76,    79,    80,    35,    81,    82,     0,   118,
      83,    84,    85,    86,    18,   162,   163,   164,   171,   174,
     492,   175,     0,   176,   177,   178,   179,   180,   181,   182,
     185,   186,     0,   213,   221,   216,   249,   259,     0,   247,
       0,   248,   223,   217,   184,   218,   183,   219,   222,   360,
     362,   364,   374,   376,   380,   382,   385,   390,   393,   396,
     398,   400,   402,     0,   406,   413,   412,   414,     0,   431,
     415,   436,   439,   441,   444,   446,     0,   451,   448,     0,
     459,   469,   471,   445,   476,   483,   497,   484,   485,   486,
     489,   490,   487,   491,   514,   515,   488,   518,   520,   521,
     522,   519,   567,   568,   569,   570,   571,   572,   573,   468,
     612,     0,   603,   611,   610,   609,   608,   605,   607,   604,
     606,   498,    43,   224,   225,   227,   226,   228,   220,   494,
     495,   496,   493,   230,   233,   229,   231,   232,   470,   808,
     831,   927,   936,   934,   833,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,   283,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   467,   454,     0,     0,   811,   841,   814,   872,   937,
     816,   883,   818,   896,   821,   823,   822,   914,  1022,  1029,
     810,  1023,   870,  1024,  1030,   897,  1028,  1031,   921,   978,
    1025,  1026,  1032,  1027,   979,   967,   964,   966,   965,   859,
     983,   984,   981,   825,   985,   963,   460,   808,   452,     0,
     193,   453,   456,   811,   812,   814,   813,   818,   819,   820,
     821,   810,   817,   502,     0,   458,   457,   188,     0,     0,
     213,     0,   816,   823,   822,     0,   168,   788,   985,     0,
     221,     0,   503,     0,   534,     0,     0,   463,     0,   434,
     435,     0,   466,   465,   455,   438,     0,     0,   563,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   790,     0,   792,
       0,     0,   165,     3,     4,     1,    10,    12,     0,     0,
       0,     0,     6,   165,     0,   165,     0,     0,   119,   172,
       0,     0,   191,     0,     0,   200,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,   205,   234,     0,   254,
     250,   260,   255,   256,   251,   253,   252,   263,     0,     0,
       0,     0,     0,     0,     0,   425,     0,     0,   423,     0,
     369,     0,   424,   417,   422,   421,   420,   419,   418,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   411,   410,
     407,     0,   168,   432,   437,     0,     0,     0,   447,   480,
     450,   449,   461,     0,   477,     0,     0,     0,   575,   577,
     581,   583,     0,   124,     0,   807,    47,    44,    45,    48,
      49,     0,     0,     0,     0,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   647,   648,   649,
       0,   103,   142,     0,     0,   112,     0,     0,     0,     0,
     127,     0,     0,   620,     0,     0,     0,   615,     0,     0,
       0,   630,     0,     0,   262,   265,     0,     0,   134,     0,
     138,   168,   517,     0,    60,     0,    69,     0,     0,     0,
      61,     0,     0,     0,     0,   618,     0,     0,   621,     0,
       0,     0,     0,   331,     0,     0,   619,     0,     0,     0,
     638,     0,     0,     0,     0,   624,     0,     0,   195,     0,
       0,   189,   187,     0,     0,   794,     0,     0,     0,   502,
       0,   789,     0,   504,   535,   534,   531,     0,     0,     0,
     565,   564,   433,     0,   562,     0,   660,   661,     0,     0,
       0,     0,     0,   801,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   666,     0,   203,   204,     0,     0,
       0,     0,     0,   208,   209,   791,   793,     0,     5,    24,
       0,    25,     0,     7,    29,     0,    15,     8,    30,     0,
      19,   927,    77,    16,    78,    20,   194,     0,   192,   214,
     215,     0,     0,     0,     0,   257,   258,   300,   206,   235,
     237,   238,   261,     0,     0,   361,   363,   367,   373,   372,
     371,     0,   368,   365,   366,     0,   377,   384,   383,   381,
     387,   388,   389,   386,   391,   392,   395,   394,     0,     0,
       0,     0,   416,     0,   442,   443,     0,   481,   510,   478,
     512,     0,   613,   516,   508,     0,     0,   121,   123,     0,
       0,     0,   102,     0,    92,    94,    95,    96,    97,    99,
     100,   101,    93,    98,    88,    89,     0,     0,   108,     0,
     104,   106,   107,   114,     0,     0,    87,    46,     0,     0,
       0,     0,     0,     0,     0,   738,   743,     0,     0,   739,
     773,   726,   728,   729,   730,   732,   734,   733,   731,   735,
       0,     0,     0,     0,     0,   111,     0,   144,     0,     0,
     580,   574,   616,   617,     0,     0,   634,     0,   631,     0,
       0,     0,     0,     0,     0,     0,     0,   140,     0,     0,
     135,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,   281,   287,   284,     0,   623,   622,   629,   637,     0,
       0,     0,     0,   579,     0,     0,     0,   426,     0,     0,
       0,     0,   627,     0,   625,     0,   196,     0,     0,   795,
       0,     0,     0,     0,   534,   532,     0,   523,     0,     0,
     506,   507,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,     0,     0,     0,   674,     0,   210,     0,
       0,     0,     0,   165,     0,   165,     0,   173,   246,     0,
     315,   311,   313,     0,   308,   301,   302,     0,     0,   239,
     240,     0,   245,   370,     0,     0,     0,     0,   704,   378,
     677,   681,   683,   685,   687,   690,   697,   698,   706,   937,
     815,     0,   824,   828,   827,   829,   830,   397,   586,   592,
     593,   596,   641,   642,   597,   598,   601,   399,   401,   404,
     602,   403,   430,   482,     0,   479,   509,   125,    56,    57,
      54,    55,   131,   130,     0,    90,     0,     0,   109,   110,
     115,    74,    75,    52,    53,    73,   744,     0,   747,   774,
       0,   737,   736,   741,   740,   772,     0,     0,   749,     0,
     745,   748,   727,     0,     0,     0,     0,     0,     0,     0,
     614,     0,     0,     0,   143,   146,   148,     0,     0,     0,
     113,   116,     0,     0,     0,   168,     0,     0,   638,     0,
       0,     0,   267,     0,   585,     0,   268,     0,     0,     0,
       0,     0,     0,     0,   141,   136,   139,     0,   190,     0,
       0,    71,    65,    68,    67,     0,    63,   285,     0,     0,
     168,     0,   329,   333,     0,     0,     0,   336,     0,     0,
     342,     0,     0,   349,     0,   353,     0,   428,   427,   168,
       0,     0,   197,     0,   199,   330,     0,     0,     0,     0,
     535,     0,   525,     0,   558,   555,     0,   559,   560,     0,
       0,   554,     0,   529,   557,   556,     0,     0,     0,     0,
     653,   654,   650,     0,     0,   658,   659,   655,   797,   798,
     664,   802,   662,     0,     0,     0,     0,   668,   816,   823,
     822,   985,   202,     0,     0,     0,   669,   670,     0,     0,
     211,   800,    26,     0,    17,    21,    22,   312,   324,     0,
     325,     0,   316,   317,   318,   319,     0,   502,     0,   309,
       0,     0,     0,   241,     0,     0,     0,     0,   294,     0,
     291,   296,   244,     0,     0,   688,   701,     0,   375,   379,
       0,   720,     0,     0,     0,     0,     0,     0,   676,   678,
     679,   715,   716,   717,   719,   718,     0,     0,   692,   691,
       0,   695,   699,   713,   711,   710,   703,   707,     0,     0,
       0,     0,     0,     0,     0,     0,   589,   591,   590,   587,
     405,   511,   513,   133,   132,    91,   105,   761,   742,     0,
     766,     0,   766,   755,   750,   147,   149,     0,     0,     0,
     117,   145,     0,    27,     0,   635,   636,   639,   632,   633,
     266,     0,     0,   280,   272,     0,   276,     0,   270,     0,
       0,     0,   137,     0,     0,    70,     0,    64,   286,     0,
       0,   332,   334,   339,     0,   337,     0,     0,     0,     0,
       0,   343,     0,     0,   357,     0,     0,   350,     0,     0,
     354,   429,     0,   628,   626,   198,   796,     0,     0,   534,
       0,     0,   566,     0,   534,     0,   530,     0,    14,     0,
       0,     0,     0,     0,     0,     0,   667,     0,     0,     0,
       0,     0,     0,   671,   675,   328,   326,   327,   320,   321,
     322,   314,     0,     0,   310,   303,   289,     0,     0,     0,
     243,   292,   295,     0,   705,   696,   702,     0,     0,   775,
     776,   786,   785,   784,     0,     0,     0,     0,   777,   682,
     783,     0,   680,   684,     0,     0,   689,   693,     0,   714,
     709,   712,   708,     0,     0,   599,     0,   594,   646,   588,
     806,   805,   804,   595,   762,     0,     0,   760,   767,   768,
     764,     0,   759,     0,   757,     0,     0,     0,     0,     0,
       0,   576,   269,     0,   278,     0,     0,   274,     0,   277,
       0,     0,     0,    66,   288,   582,     0,     0,   340,   344,
     338,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   578,     0,     0,   534,     0,   561,     0,
     534,   584,   651,   652,   656,   657,     0,   663,   803,   665,
       0,     0,     0,     0,   672,   323,   304,     0,   290,   298,
     299,   293,   242,   700,   787,     0,     0,   779,     0,   725,
     724,   723,   722,   721,   686,     0,   778,     0,   643,     0,
       0,   771,   770,   769,     0,   763,   756,   754,     0,   751,
     752,   746,   150,   152,   154,     0,     0,     0,     0,     0,
     273,   271,     0,   279,   207,   359,    72,   335,   341,     0,
     358,   355,   351,     0,     0,     0,   345,     0,     0,   347,
       0,   544,   538,   533,     0,   534,   524,     0,   799,     0,
       0,     0,     0,   307,   305,     0,   781,   780,     0,     0,
     644,   600,     0,   765,   758,     0,     0,   156,   155,     0,
       0,     0,     0,   151,   275,     0,     0,     0,     0,     0,
     552,   546,     0,   545,   547,   553,   550,   540,     0,   539,
     541,   551,   526,     0,   527,     0,     0,   673,   306,     0,
     782,   694,   645,   753,   153,   157,     0,     0,     0,     0,
       0,     0,   348,   346,     0,     0,   537,   548,   549,   536,
     542,   543,   528,     0,   297,   158,     0,     0,     0,   356,
     352,     0,     0,     0,     0,     0,     0,     0,     0,   160,
       0,     0,   159,     0,     0,     0,     0,     0,     0,     0,
       0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1512, -1512,  -229,  -197, -1512,  1174,  1175, -1512,  1183,  -540,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1005, -1512, -1512, -1512, -1512,  -225,  -587, -1512,   698,  -127,
   -1512, -1512, -1512, -1512, -1512,   243,   467, -1512, -1512,   -10,
    -193,  1018, -1512,  1015, -1512, -1512,  -658, -1512,   413, -1512,
     207, -1512,  -273,  -312, -1512,  -547, -1512,    23,    64,    52,
    -277,  -182, -1512,  -908, -1512, -1512,   337, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512,   582, -1512,  -111,
    1570,     0, -1512, -1512,  -291, -1512, -1512,   320, -1512, -1512,
    -304, -1512, -1512, -1512,    16, -1512, -1512,   805,  -955,  -757,
    -732, -1512, -1512,   672, -1512, -1512,   -92,    75, -1512, -1512,
   -1512,    96, -1198, -1512,   348,   102, -1512, -1512,   109, -1319,
   -1512,   932,   200, -1512, -1512,   197, -1039, -1512, -1512,   196,
   -1512, -1512, -1260, -1241, -1512,   195, -1423, -1512, -1512,   832,
     833, -1512,  -477,   808, -1512, -1512,  -674,   307,  -653,   318,
     322, -1512, -1512, -1512,   552, -1512, -1512,  1167, -1512, -1512,
   -1512, -1512, -1512,  -899,  -333,  -688, -1512,  -107, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,   -26,  -830, -1512,  -551,   629,
     258, -1512,  -423, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
     775, -1512, -1512, -1512, -1512, -1032, -1512,   178, -1512,   660,
    -818, -1512, -1512, -1512, -1512, -1512,  -292,  -284, -1236,  -940,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512,  -773,  -874,  -219,  -825, -1512, -1512, -1512,  -858, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,  1051,  1061,
    -210,   474,   306, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512,   158, -1512, -1512,   149, -1512,   151,
   -1079, -1512, -1512, -1512,   103,    91,   -80,   363, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512,   104, -1512, -1512, -1512,   -70,   360,   507, -1512, -1512,
   -1512, -1512, -1512,   297, -1512, -1512, -1511, -1512, -1512, -1512,
    -586, -1512,    67, -1512,   -87, -1512, -1512, -1512, -1512, -1330,
   -1512,   118, -1512, -1512, -1512, -1512, -1512,   930, -1512, -1512,
   -1512, -1512, -1512,  -943,  -422,   993,   314, -1512
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   260,   634,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
    1271,   789,   278,   279,   280,   281,   282,   283,   974,   975,
     976,   284,   285,   286,   980,   981,   982,   287,   452,   288,
     289,   722,   290,   454,   455,   456,   466,   779,   780,   291,
    1234,   292,  1712,  1713,   293,   294,   295,   558,   296,   297,
     298,   299,   300,   782,   301,   302,   540,   303,   304,   305,
     306,   307,   308,   646,   309,   310,   873,   874,   311,   312,
     313,   570,   315,   647,  1649,   661,  1141,  1142,   316,   649,
     317,   651,   652,   653,   571,   319,   320,   774,   775,  1388,
     473,   321,   474,   475,   914,  1389,  1390,  1391,   654,   655,
    1135,  1136,  1379,   656,  1131,  1132,  1372,  1373,  1374,  1375,
     322,   802,   803,   323,  1286,  1287,  1496,   324,  1289,  1290,
     325,   326,  1292,  1293,  1294,  1295,  1503,   327,   328,   329,
     330,   921,   331,   332,  1398,   333,   334,   335,   336,   337,
     338,   339,   340,   341,  1178,   342,   343,   344,   345,   679,
     680,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   714,
     709,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     951,   373,   374,   375,   376,   377,   378,  1322,   835,   836,
     837,  1743,  1788,  1789,  1782,  1783,  1790,  1784,  1323,  1324,
     379,   380,  1325,   381,   382,   383,   384,   385,   386,   387,
     388,  1036,  1504,  1439,  1168,  1596,  1169,  1179,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     809,  1247,   401,  1171,  1172,  1173,  1174,   402,   403,   404,
     405,   406,   407,   863,   864,   408,  1356,  1357,  1674,  1117,
    1149,  1408,  1409,  1150,  1151,  1152,  1153,  1154,  1418,  1586,
    1587,  1155,  1421,  1156,  1567,  1157,  1158,  1426,  1427,  1592,
    1590,  1410,  1411,  1412,  1413,  1692,   751,  1001,  1002,  1003,
    1004,  1005,  1006,  1220,  1616,  1709,  1221,  1614,  1707,  1007,
    1452,  1611,  1607,  1608,  1609,  1008,  1009,  1414,  1422,  1577,
    1415,  1573,  1399,   409,   410,   411,   412,   561,   413,   414,
     415,   416,   417,  1175,  1272,   418,   419,   420
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -873;
  const short int
  xquery_parser::yytable_[] =
  {
       314,   569,   573,   606,   453,   314,   314,   314,   314,   723,
     723,   929,   726,   942,   650,   703,   318,  1086,  1050,  1034,
     629,   318,   318,   318,   318,  1288,  1147,   648,   425,   428,
     429,  1062,   585,   930,   931,   932,   933,   624,   892,   894,
     621,   853,  1116,  1276,  1035,  1076,   860,   786,   790,  1518,
     536,  1507,   626,  1193,  1549,  1550,  1321,   427,   427,   427,
     431,   613,   614,   622,  1167,  1177,  1394,   622,  1236,   426,
     426,   426,   430,  1030,  1252,   961,   886,   890,   893,   895,
    1170,  1170,  1647,   884,   888,  1651,  1526,  1260,   622,  1138,
    1588,  1278,    11,    12,   840,   628,   824,   471,    11,    12,
     622,   622,   434,   435,  1710,   436,   437,   622,   587,  1358,
      13,   314,   438,  1109,   725,   596,   622,   622,   438,  1170,
     622,   622,   439,   440,   622,   631,   622,   318,   824,  1107,
     823,  1715,  1031,  1087,  1032,    11,    12,  1223,   608,   610,
     441,   622,  1224,   765,   622,   442,   441,  1605,  1032,   622,
     629,  1225,  1197,  1235,   629,   438,   622,  1254,  1226,  1092,
    1227,   766,   622,   559,  1265,   439,   622,  1359,   887,  1228,
     633,  1569,   825,  1170,   633,   426,   622,   443,   444,   445,
    1170,   727,  1741,   441,   757,  1033,   630,   917,   442,   918,
     919,    82,   920,   622,   922,   633,  1229,   728,   787,  1261,
    1122,  1088,   923,   924,   597,    93,   705,   706,  1570,   632,
    1200,   434,   435,  1606,   436,   437,  -169,   622,  1108,  1093,
     443,   444,  1126,   472,   622,  1574,   446,   622,   633,  1675,
     107,   622,   440,   633,  1144,   622,   622,  1145,   622,  1716,
    -170,   622,  1110,  1102,   704,   788,  1147,  1147,   633,   725,
    1500,   633,  1139,   472,  1803,  1103,   633,   128,   314,   314,
     628,   841,   314,   633,  1264,   622,  1311,   650,   622,   633,
    1487,  1742,   457,   633,   318,   318,   833,  1507,   318,  1262,
     832,  1321,   629,   633,  1708,  1526,  1444,   447,  1363,  1140,
    1321,   623,   625,   588,   892,   894,  1470,   314,   879,  1236,
     633,   622,  1258,  1170,  1263,  1194,  1775,   881,  1123,  1042,
    1094,  1125,   472,   318,  1064,  1362,   630,  1566,  1279,  1257,
     630,  1717,   987,  1497,   633,  1230,   472,  1098,   448,  1065,
     710,   633,  1113,   712,   633,   446,  1430,  1307,   633,   884,
     888,  1146,   633,   633,  1308,   633,   777,  1059,   633,  1024,
    1309,   770,  1479,  1811,   449,  1814,   783,  1031,  1400,  1054,
     758,   486,   450,  1059,  1382,   622,   796,  1047,   759,  1369,
     451,   908,   633,   807,   808,   633,   765,   876,   622,   875,
     785,  1749,   814,  1400,  1235,   622,  1575,  1576,   622,   481,
     537,   880,   882,  1482,   766,  1767,   447,   449,   885,   889,
    -169,   897,    11,    12,   537,   450,  1031,   432,   633,  1170,
     644,   831,  1750,   451,  1070,   878,   778,  1231,  1232,  1233,
    1183,  1089,  1312,  1751,  -170,  1673,  1685,   314,   537,  1060,
    1401,   314,    13,  1170,   735,  1095,  1096,   448,   487,   590,
     537,   591,   537,   318,  1143,  1078,   472,   318,   630,  1805,
    1097,  1090,  1099,  1100,   990,  1401,   991,   657,   314,  1061,
     314,   741,  1780,   742,   838,   839,  1314,  1101,  1460,   736,
    1314,  1315,   633,  1780,   318,   843,   318,  1314,  1753,   472,
    1436,   644,   314,  1359,  1091,   633,   433,   314,   627,  1321,
    1313,  1796,   633,   869,   871,   633,  1472,  1147,   318,   593,
     992,   594,  1148,   318,  1686,  1644,  1147,   488,   489,   956,
     431,  1437,   431,    82,   956,  1402,  1403,  1147,  1404,  1025,
     767,   658,   762,   744,   764,  1116,   659,    93,   592,  1544,
    1480,  1438,  1285,  1187,   431,  1406,   892,   894,   892,   431,
    1402,  1403,  1328,  1404,  1329,  1494,   805,  1407,  1115,  1457,
    1405,   811,   107,  1027,  1595,  1507,  1798,  1344,  1369,   314,
    1406,  1564,  1201,  1202,   461,  1316,   314,  1205,  1797,   683,
    1170,  1801,  1407,   660,  1039,   318,  1364,  1365,  1366,  1371,
      13,  1317,   318,  1318,   745,  1317,   684,  1318,   595,  1105,
     957,  1781,  1317,   629,  1318,   958,   946,  1244,   944,   945,
    1026,   741,  1817,   742,  1553,   314,  1071,   707,   453,   713,
     460,  1319,   314,  1314,  1073,  1319,  1184,  1314,   427,   114,
    1127,   318,  1319,   314,   314,   314,   314,  1726,   318,  1184,
     426,  1314,  1315,  1786,  1028,   126,   743,  1786,  1032,   318,
     318,   318,   318,   464,   690,  -264,   465,  1170,   314,   707,
    1170,   713,   993,   691,  1120,  1040,  1124,   870,  1320,  1699,
     882,    82,  1648,   744,   318,   994,  1704,   995,  1740,  1217,
     537,  1423,  1424,   537,   467,    93,   155,   618,   996,   997,
     998,  1689,   999,  1031,  1000,  1147,  1218,  1072,  1690,  1471,
    1032,  1535,   729,   619,  1425,  1074,   731,  1185,  1691,   476,
     107,  1655,   314,   887,  1144,   479,  1659,  1145,   730,  -264,
    1186,  1500,   732,   686,  -264,  1081,  1082,  1083,   318,   871,
    1626,  1031,  1148,  1148,   745,   943,  1316,   128,  1317,  1219,
    1318,   644,  1317,  1581,  1318,  1121,  1381,   644,  1449,  1787,
    1700,  1625,   687,  1820,  1384,   575,  1317,  1705,  1318,  1385,
    1449,   619,   733,   537,   427,   688,   537,  1031,  1319,  1114,
     537,  -264,  1319,   537,   537,   702,   426,  1450,  1386,  1049,
    1730,   537,  1314,  1315,  1620,   892,  1319,   537,   537,   977,
     114,   314,  1031,  1314,  1315,   537,  1170,  1032,   128,   683,
     492,   689,   537,   537,   537,   537,   126,   318,  1451,   490,
     537,  1785,  1791,  1217,  1041,  1075,   684,   636,   537,  1387,
    1451,   637,   314,   314,   703,  1246,   638,  1249,  1188,  1520,
    1218,   493,   978,  1760,   494,  1761,  1384,   979,   318,   318,
    1552,  1385,  1396,   427,  1189,   639,  1352,   155,  1744,  1170,
     683,  1170,  1747,  1785,  1190,   426,  1192,  1195,  1485,  1791,
     480,  1571,   707,   537,   713,   128,  1443,   684,  1572,  1195,
    1191,  1300,   781,  1301,   431,   431,   683,  1316,   537,  1032,
     314,  1170,   781,  1368,   484,   598,  1068,  1069,  1316,   537,
     599,   453,   685,   684,  1369,   897,   318,  1317,  1802,  1318,
     468,   882,   458,   692,  1370,   459,  1285,   314,  1317,   469,
    1318,  1687,  1688,  1505,  1170,  1371,   854,   693,  1758,  1499,
    1238,   854,  1508,   318,   537,  1684,  1506,  1319,  1170,  1239,
    1170,   114,  1333,  1689,  1334,  1509,   470,  1793,  1319,  1714,
    1690,  1505,   114,   640,   716,  1360,   641,   126,  1211,  1213,
    1691,  1768,  1505,   462,  1654,   717,   463,  1545,   126,  1212,
    1214,   642,   643,   644,   755,  1823,  1554,  1203,  1204,   756,
    1525,  1206,  1207,  1208,   896,   978,   947,  1209,   898,   947,
     979,  1657,   947,  1148,   537,  1384,  1546,  1547,   155,   645,
    1385,   485,  1148,   477,   708,   482,   478,   711,   483,   155,
     927,   928,  1483,  1148,   747,   748,   749,  1498,   964,   965,
     966,   967,   968,   969,   970,   971,   972,   973,   934,   935,
     491,  1756,  1757,   664,   936,   937,  1455,  1456,   538,  1701,
    1702,   665,   666,   539,   667,   541,   542,   554,   555,   556,
     576,  1714,   668,  1393,   577,   582,   669,   583,   670,   584,
     586,   589,  -614,   671,   600,   603,   601,   602,   604,   611,
     650,   963,   605,   615,   537,  1537,   635,   662,   663,   672,
     681,   682,   694,  1541,  1633,   695,   314,   697,   537,   696,
     701,   725,   537,   537,   707,   715,   718,   719,  1714,   737,
     720,   721,   318,   553,  1800,   673,   674,   675,   676,   677,
     678,   537,   739,   740,   750,   781,   754,   784,   763,   537,
     792,   793,   537,   794,   795,   812,   537,   574,   813,   806,
     459,   819,   453,  1353,   463,   821,   478,   483,   431,   578,
     494,   581,   823,   314,   314,   314,   826,   827,   828,  1354,
    1296,   830,   834,   842,   845,   866,   867,   883,   844,   318,
     318,   318,   901,   862,   902,   903,   872,   910,   537,   904,
    1842,   925,  1843,   911,   913,   939,   938,   940,   941,   953,
     959,  1148,  1851,   960,   984,   962,   985,   952,   988,   606,
     989,  1011,  1010,  1012,  1014,  1016,  1019,  1022,  1020,  1023,
    1021,  1029,  1038,  1044,  1045,  1048,   537,  1055,  1056,  1104,
    1057,  1058,  1063,  1066,  1067,  1106,   458,  1111,   462,   477,
     482,   493,  1122,  1636,  1129,  1637,  1112,  1119,  1641,  1642,
    1182,  1196,  1645,   979,  1031,   537,  1215,  1216,  1652,  1242,
    1237,  1639,  1245,  1253,  1255,  1259,   777,   537,  1243,  1269,
    1273,  1267,  1268,  1270,  1274,  1275,  1280,  1281,  1284,  1299,
    1310,  1285,  1291,  1297,  1306,   314,  1303,  1326,  1298,  1304,
    1327,  1345,   537,   537,   537,   537,   743,  1376,  1355,  1378,
    1383,   318,  1380,  1428,   908,  1429,  1416,  1397,  1464,   314,
    1431,  1432,  1433,  1440,  1434,  1417,  1420,  1435,    13,  1448,
     314,  1453,  1467,  1463,  1477,   318,  1458,  1462,  1465,  1486,
    1459,   537,  1475,  1481,  1489,  1505,   318,   427,  1466,   314,
    1468,  1469,  1517,  1490,  1447,   537,  1519,  1511,  1522,   426,
    1513,  1533,  1538,  1534,  1514,   318,  1529,   644,  1528,   314,
    1539,  1540,  1512,  1369,  1530,  1358,   314,  1531,  1557,  1558,
     537,  1559,   427,  1532,  1563,   318,  1565,  1584,  1589,   537,
    1591,   537,   318,   537,   426,   537,  1597,  1598,  1599,  1585,
    1600,   427,   537,  1724,  1601,  1602,  1734,  1603,  1353,  1604,
    1738,  1610,  1568,   426,  1728,  1639,  1615,  1617,  1731,  1621,
    1623,   431,  1628,  1630,  1354,  1739,  1632,  1631,   431,  1578,
    1635,  1677,  1653,  1523,  1658,   537,  1661,   537,  1683,  1666,
    1527,  1695,  1619,  1697,  1706,  1698,  1217,  1711,  1719,  1729,
    1722,  1755,  1746,  1613,  1762,  1763,  1770,  1776,  1765,  1771,
     870,  1766,  1778,  1696,  1792,  1764,  1794,  1809,  1795,  1816,
    1822,  1799,   854,  1819,  1808,  1828,  1833,  1670,  1671,  1672,
    1844,  1718,   734,  1848,  1847,   738,   616,   617,  1834,   746,
    1446,   986,   752,   753,  1777,  1198,  1773,   537,   620,  1461,
     761,   724,  1266,  1806,  1804,  1118,   773,   776,  1838,  1845,
    1826,  1731,  1392,  1562,   791,   912,  1053,  1835,   760,  1681,
    1840,   799,   800,   801,   804,   537,  1555,  1367,  1551,   810,
    1850,  1491,  1548,  1495,  1810,  1501,   820,   817,  1815,  1510,
     926,  1521,   955,  1181,   915,  1085,   916,  1821,   314,  1818,
    1812,  1250,  1445,  1536,  1694,  1543,  1542,  1583,  1579,  1395,
     700,  1693,   768,  1582,   318,  1419,  1454,  1222,  1483,  1612,
    1831,  1703,   769,  1832,  1580,   858,     0,     0,     0,     0,
       0,     0,   818,  1829,     0,     0,     0,     0,     0,     0,
       0,  1353,     0,     0,     0,     0,  1841,   804,     0,     0,
       0,     0,     0,     0,     0,  1829,     0,  1354,   829,     0,
       0,     0,  1752,     0,  1812,   537,     0,     0,     0,   537,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   537,     0,     0,  1759,     0,     0,     0,     0,     0,
       0,     0,     0,   865,     0,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1353,     0,     0,     0,   537,     0,     0,     0,     0,     0,
       0,  1353,  1353,     0,     0,   314,  1354,     0,     0,     0,
       0,     0,  1353,   776,     0,     0,     0,  1354,  1354,   537,
       0,   318,     0,     0,     0,     0,     0,     0,  1354,   537,
       0,     0,     0,   537,     0,     0,     0,     0,     0,     0,
       0,   560,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   983,     0,     0,     0,     0,  1353,     0,
       0,     0,   537,     0,     0,     0,     0,  1013,     0,     0,
       0,  1017,  1018,     0,  1354,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1037,     0,   537,     0,     0,     0,     0,   314,  1043,     0,
       0,  1046,     0,     0,     0,  1051,     0,     0,     0,     0,
       0,     0,     0,   318,     0,  1353,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     314,  1354,     0,     0,     0,     0,   537,     0,     0,   537,
       0,     0,   537,     0,     0,     0,   318,  1084,     0,     0,
       0,     0,  1353,     0,   537,     0,     0,     0,     0,   537,
       0,  1353,     0,     0,     0,     0,     0,     0,  1354,     0,
       0,     0,     0,     0,     0,     0,     0,  1354,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   537,   537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1176,  1176,  1180,  1180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   537,     0,
     537,     0,   537,     0,   537,     0,     0,     0,     0,     0,
    1176,   537,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1241,
       0,   537,     0,   537,     0,     0,     0,     0,  1248,     0,
    1248,     0,   776,     0,  1176,     0,     0,     0,     0,   537,
       0,  1176,   537,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   537,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   810,     0,   810,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   537,     0,     0,     0,
       0,     0,     0,     0,   537,     0,     0,     0,     0,     0,
     537,     0,   537,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,     0,     0,     0,     0,     0,     0,
       0,     0,   537,     0,     0,     0,  1377,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   560,     0,     0,     0,
       0,     0,   537,     0,     0,     0,     0,   537,     0,     0,
       0,     0,     0,     0,  1176,     0,     0,     0,     0,   537,
     846,   847,   537,   855,   856,   857,   859,     0,   861,     0,
       0,     0,     0,   868,     0,     0,     0,     0,     0,     0,
       0,   877,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   899,   900,     0,     0,     0,     0,     0,
       0,     0,   905,   906,     0,   907,     0,     0,   909,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -872,   464,     0,  -264,   776,     0,     0,     0,  1473,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1176,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   804,     0,     0,     0,     0,     0,
       0,     0,  -872,   950,  1176,     0,  -872,   950,     0,     0,
    -872,  -872,     0,     0,     0,     0,  -872,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -264,     0,     0,
    -872,     0,  -264,  1524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1015,     0,     0,     0,
       0,     0,     0,  -872,     0,  -872,  -872,  -872,   865,     0,
    -872,  -872,  -872,  -872,     0,     0,     0,  -872,  -872,     0,
       0,     0,     0,     0,  -872,     0,     0,  -872,  -872,  -264,
       0,     0,  -872,  1052,     0,     0,     0,  -872,  -872,     0,
       0,     0,     0,  -872,     0,     0,     0,  -872,     0,     0,
    1561,  -872,  -872,     0,  -872,     0,  -872,  -872,     0,  1077,
       0,  -872,  -872,  1079,  1080,  -872,  -872,  -872,  -872,  -872,
    -872,     0,   909,  -872,     0,     0,     0,  -872,  -872,     0,
       0,  -872,     0,     0,     0,     0,  -872,     0,     0,  -872,
       0,  1176,     0,     0,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,     0,  -872,  -872,  -872,  -872,  -872,     0,     0,     0,
       0,  -872,  -872,  -872,     0,  -872,  -872,  -872,  -872,  -872,
    -872,  1618,  -872,     0,  -872,     0,     0,     0,     0,  -872,
    -872,  -872,     0,     0,     0,     0,     0,   900,     0,     0,
       0,     0,     0,  1130,  1134,  -872,     0,  -872,     0,  -872,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -872,     0,     0,     0,  1643,  -872,     0,  1176,     0,
       0,  1176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1656,     0,     0,     0,     0,  1660,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1199,
       0,  1679,  1680,  -872,     0,  -872,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1282,  1283,     0,     0,     0,     0,     0,  1176,     0,  1733,
       0,  1735,     0,  1737,     0,  1302,     0,     0,  1305,     0,
    1745,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1330,  1331,  1332,     0,  1335,
    1336,  1337,  1338,  1339,  1340,  1341,  1342,  1343,     0,     0,
    1346,  1347,     0,     0,     0,     0,     0,     0,     0,  1361,
    1176,     0,  1176,     0,     0,     0,     0,     0,     0,  1130,
       0,     0,     0,     0,     0,     0,     0,     0,  1769,     0,
       0,  1772,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1176,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1779,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1442,  1176,     0,     0,     0,     0,
       0,     0,     0,  1807,     0,     0,     0,     0,     0,  1176,
       0,  1176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1824,     0,     0,     0,     0,     0,     0,     0,
       0,  1827,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1836,     0,     0,     0,     0,  1837,  1474,     0,  1476,
       0,  1478,     0,     0,     0,     0,     0,     0,  1846,  1484,
       0,  1849,     0,     0,     0,     0,     0,     0,  1488,     0,
       0,     0,     0,     0,  1492,  1493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1515,     0,     0,  1516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1130,     0,     0,     0,
    1134,  1556,     0,     0,     0,     0,  1560,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1622,     0,     0,     0,  1624,     0,     0,     0,  1627,
       0,  1629,     0,     0,     0,     0,     0,     0,     0,  1634,
       0,     0,     0,     0,     0,     0,     0,  1638,  1640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1484,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1662,
    1663,  1664,  1665,     0,  1667,  1668,     0,  1669,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1676,     0,     0,     0,     0,  1678,     0,     0,
       0,     0,     0,  1682,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1720,     0,  1721,     0,     0,  1723,     0,
       0,  1725,     0,     0,     0,     0,  1727,  1640,     0,     0,
       0,     0,     0,     0,     0,  1732,     0,     0,     0,  1736,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1748,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1754,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1774,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1732,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1813,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -165,   887,     0,     0,     0,     0,  1825,     0,     0,     0,
    1830,     1,     2,     0,     0,  1813,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,  1830,     0,    14,   422,  1839,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,   133,   134,     0,
     135,   136,   137,   138,   139,     0,   140,     0,   141,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     0,     0,   153,   154,   155,     0,   424,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,     0,   250,     0,   251,   252,   253,   254,
     255,   256,   257,  -165,   887,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,   891,   422,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   423,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,   137,   138,   139,     0,   140,
       0,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,   153,   154,   155,     0,
     424,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   887,   250,     0,   251,
     252,   253,   254,   255,   256,   257,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,   421,   422,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   423,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   133,   134,     0,   135,   136,   137,   138,   139,
       0,   140,     0,   141,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,   153,   154,
     155,     0,   424,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,     0,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   887,   250,
       0,   251,   252,   253,   254,   255,   256,   257,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     421,   422,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   562,   423,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     563,   564,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     512,    85,    86,    87,    88,    89,   565,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   566,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,     0,
     138,   139,     0,   140,     0,   141,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
     153,   154,   155,     0,   424,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   530,   531,   532,
     182,   183,   533,   568,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,     0,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
       0,   250,     0,   251,   252,   253,   254,   255,   256,   257,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,     0,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,   137,   138,   139,     0,   140,     0,   141,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,   153,   154,   155,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,     0,   250,     0,   251,   252,   253,   254,   255,
     256,   257,   258,   259,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,   137,   138,   139,     0,   140,
       0,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,   153,   154,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,     0,   250,     0,   251,
     252,   253,   254,   255,   256,   257,     0,   612,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     421,   422,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   423,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,   557,     0,   132,   133,   134,     0,   135,   136,   137,
     138,   139,     0,   140,     0,   141,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
     153,   154,   155,     0,   424,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,     0,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
       0,   250,     0,   251,   252,   253,   254,   255,   256,   257,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,     0,   421,   422,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,   423,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,   822,     0,   132,   133,   134,     0,   135,
     136,   137,   138,   139,     0,   140,     0,   141,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,   153,   154,   155,     0,   424,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,     0,   250,     0,   251,   252,   253,   254,   255,
     256,   257,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   421,   422,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,  1348,
     423,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,  1349,  1350,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,   557,     0,   132,   133,   134,
       0,   135,   136,   137,   138,   139,     0,   140,     0,   141,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,   153,   154,   155,     0,   424,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,  1351,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,     0,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,     0,   250,     0,   251,   252,   253,
     254,   255,   256,   257,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,   421,   422,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   423,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,   137,   138,   139,     0,   140,
       0,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,   153,   154,   155,     0,
     424,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,     0,   250,     0,   251,
     252,   253,   254,   255,   256,   257,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   133,   134,     0,   135,   136,   137,   138,   139,
       0,   140,     0,   141,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,   153,   154,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,     0,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,     0,   250,
       0,   251,   252,   253,   254,   255,   256,   257,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,   137,
     138,   139,     0,   140,     0,   141,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
     153,   154,   155,     0,   424,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,     0,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
       0,   250,     0,   251,   252,   253,   254,   255,   256,   257,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,     0,    14,   422,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,   137,   138,   139,     0,   140,     0,   141,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,   153,   154,   155,     0,   424,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,     0,   250,     0,   251,   252,   253,   254,   255,
     256,   257,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   891,   422,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     423,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   133,   134,
       0,   135,   136,   137,   138,   139,     0,   140,     0,   141,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,   153,   154,   155,     0,   424,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,     0,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,     0,   250,     0,   251,   252,   253,
     254,   255,   256,   257,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,   421,   422,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,  1348,   423,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,  1349,  1350,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,   137,   138,   139,     0,   140,
       0,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,   153,   154,   155,     0,
     424,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,  1351,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,     0,   250,     0,   251,
     252,   253,   254,   255,   256,   257,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   421,   422,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   562,   423,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   563,   564,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   512,    85,
      86,    87,    88,    89,   565,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     948,     0,   104,   105,   106,   107,   108,   109,   110,   566,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   133,   134,   949,   135,   136,     0,   138,   139,
       0,   140,     0,   141,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,   153,   154,
     155,     0,   424,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   530,   531,   532,   182,   183,
     533,   568,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,     0,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,     0,   250,
       0,   251,   252,   253,   254,   255,   256,   257,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     421,   422,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   562,   423,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     563,   564,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     512,    85,    86,    87,    88,    89,   565,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   948,     0,   104,   105,   106,   107,   108,   109,
     110,   566,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,   954,   135,   136,     0,
     138,   139,     0,   140,     0,   141,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
     153,   154,   155,     0,   424,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   530,   531,   532,
     182,   183,   533,   568,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,     0,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
       0,   250,     0,   251,   252,   253,   254,   255,   256,   257,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   421,   422,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   562,   423,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,   563,   564,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   512,    85,    86,    87,    88,    89,   565,    91,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   566,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,   567,   132,   133,   134,     0,   135,
     136,     0,   138,   139,     0,   140,     0,   141,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,   153,   154,   155,     0,   424,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   530,
     531,   532,   182,   183,   533,   568,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,     0,   250,     0,   251,   252,   253,   254,   255,
     256,   257,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   421,   422,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   562,
     423,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   563,   564,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   512,    85,    86,    87,    88,    89,
     565,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   566,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   133,   134,
     572,   135,   136,     0,   138,   139,     0,   140,     0,   141,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,   153,   154,   155,     0,   424,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   530,   531,   532,   182,   183,   533,   568,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,     0,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,     0,   250,     0,   251,   252,   253,
     254,   255,   256,   257,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   421,   422,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   562,   423,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,   563,   564,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   512,    85,    86,    87,
      88,    89,   565,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   566,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,     0,   138,   139,     0,   140,
       0,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,   153,   154,   155,     0,
     424,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   530,   531,   532,   182,   183,   533,   568,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   607,   250,     0,   251,
     252,   253,   254,   255,   256,   257,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   421,   422,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   562,   423,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   563,   564,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   512,    85,
      86,    87,    88,    89,   565,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   566,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   133,   134,     0,   135,   136,     0,   138,   139,
       0,   140,     0,   141,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,   153,   154,
     155,     0,   424,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   530,   531,   532,   182,   183,
     533,   568,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,     0,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,     0,   250,
     609,   251,   252,   253,   254,   255,   256,   257,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     421,   422,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   562,   423,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     563,   564,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     512,    85,    86,    87,    88,    89,   565,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,  1441,     0,   104,   105,   106,   107,   108,   109,
     110,   566,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,     0,
     138,   139,     0,   140,     0,   141,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
     153,   154,   155,     0,   424,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   530,   531,   532,
     182,   183,   533,   568,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,     0,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
       0,   250,     0,   251,   252,   253,   254,   255,   256,   257,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   421,   422,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   498,    27,   500,   423,    30,
     501,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,   503,     0,    48,
      49,    50,   505,   506,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   512,    85,    86,    87,    88,    89,   565,    91,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   515,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   566,   112,     0,   113,   114,   698,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   699,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,     0,   138,   139,     0,   140,     0,   141,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,   153,   154,   155,     0,   424,   157,   158,   159,
     160,   161,   162,   163,   164,   525,   166,   526,   168,   527,
     528,   171,   172,   173,   174,   175,   176,   529,   178,   530,
     531,   532,   182,   183,   533,   534,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,     0,   250,     0,   251,   535,   253,   254,   255,
     256,   257,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   421,   422,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   562,
     423,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   563,   564,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   512,    85,    86,    87,    88,    89,
     565,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   566,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   133,   134,
       0,   135,   136,     0,   138,   139,     0,   140,     0,   141,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,   153,   154,   155,     0,   424,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   530,   531,   532,   182,   183,   533,   568,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,     0,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,     0,   250,     0,   251,   252,   253,
     254,   255,   256,   257,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   421,   422,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   498,
      27,   500,   423,    30,   501,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,   503,     0,    48,    49,    50,   505,   506,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   512,    85,    86,    87,
      88,    89,   565,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   515,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   566,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,     0,   138,   139,     0,   140,
       0,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,   153,   154,   155,     0,
     424,   157,   158,   159,   160,   161,   162,   163,   164,   525,
     166,   526,   168,   527,   528,   171,   172,   173,   174,   175,
     176,   529,   178,   530,   531,   532,   182,   183,   533,   534,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,     0,   250,     0,   251,
     535,   253,   254,   255,   256,   257,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   421,   422,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   562,   423,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   563,   564,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   512,    85,
      86,    87,    88,    89,  1133,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   566,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   133,   134,     0,   135,   136,     0,   138,   139,
       0,   140,     0,   141,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,   153,   154,
     155,     0,   424,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   530,   531,   532,   182,   183,
     533,   568,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,     0,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,     0,   250,
       0,   251,   252,   253,   254,   255,   256,   257,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     421,   422,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   498,    27,   500,   423,    30,   501,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   503,     0,    48,    49,    50,
     505,   506,    53,   507,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     512,    85,    86,    87,    88,    89,   565,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   515,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   566,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,     0,
     138,   139,     0,   140,     0,   141,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
     153,   154,   155,     0,   424,   157,   158,   159,   160,   161,
     162,   163,   164,   525,   166,   526,   168,   527,   528,   171,
     172,   173,   174,   175,   176,   529,   178,   530,   531,   532,
     182,   183,   533,   534,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,     0,   199,   200,
     201,     0,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
       0,   250,     0,   251,   535,   253,   254,   255,   256,   257,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   421,   422,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   498,    27,   500,   423,    30,
     501,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,   503,     0,    48,
      49,    50,   505,   506,    53,   507,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   512,    85,    86,    87,    88,    89,   565,    91,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   515,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   566,   112,     0,   113,   114,     0,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,     0,     0,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,     0,     0,     0,     0,   140,     0,   141,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,   153,   154,   155,     0,   424,   157,   158,   159,
     160,   161,   162,   163,   164,   525,   166,   526,   168,   527,
     528,   171,   172,   173,   174,   175,   176,   529,   178,   530,
     531,   532,   182,   183,   533,   534,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,     0,
     199,   200,   201,     0,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,     0,   250,     0,   251,   535,   253,   254,   255,
     256,   257,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   421,   422,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   498,    27,   500,
     423,    30,   501,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   503,
       0,    48,    49,    50,   505,   506,    53,   507,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   512,    85,    86,    87,    88,    89,
     565,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   515,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,     0,   109,   110,   566,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   133,   134,
       0,   135,   136,     0,     0,     0,     0,   140,     0,   141,
       0,   142,     0,   144,     0,   146,   147,   148,   149,   150,
     151,   152,     0,     0,   153,   154,   155,     0,   424,   157,
     158,   159,   160,   161,   162,   163,   164,   525,   166,   526,
     168,   527,   528,   171,   172,   173,   174,   175,   176,   529,
     178,   530,   531,   532,   182,   183,   533,   534,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,     0,   199,   200,   201,     0,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,     0,   250,     0,   251,   535,   253,
     254,   255,   256,   257,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     0,     0,     0,     0,     9,    10,
       0,     0,     0,     0,     0,     0,   421,   422,     0,    16,
      17,    18,   495,    20,    21,    22,   496,    24,   497,   498,
     499,   500,   423,    30,   501,    32,    33,    34,     0,    35,
      36,    37,    38,   502,    40,    41,    42,    43,    44,    45,
      46,   503,     0,    48,   504,    50,   505,   506,    53,   507,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   508,   509,    71,     0,    72,    73,
      74,   510,     0,     0,    77,    78,    79,     0,     0,   511,
      81,     0,     0,     0,     0,    83,   512,    85,   513,   514,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   515,
     100,   101,   516,   517,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   116,   518,     0,     0,     0,   118,   119,
     120,   121,   519,   123,   124,   520,     0,     0,     0,     0,
       0,     0,     0,   521,   522,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   523,     0,     0,     0,     0,   140,
       0,   141,     0,   142,   143,   144,   145,   524,   147,   148,
     149,   150,   151,   152,     0,     0,   153,   154,     0,     0,
     424,   157,   158,   159,   160,   161,   162,   163,   164,   525,
     166,   526,   168,   527,   528,   171,   172,   173,   174,   175,
     176,   529,   178,   530,   531,   532,   182,   183,   533,   534,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,     0,     0,     0,     0,   251,
     535,   253,   254,   255,   256,   257,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     0,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,   421,   422,
       0,    16,    17,    18,   543,    20,    21,    22,   496,   544,
     545,   498,   499,   500,   423,    30,   501,    32,   546,    34,
       0,    35,    36,    37,    38,   547,    40,   548,   549,    43,
      44,    45,    46,   503,     0,    48,   550,    50,   505,   506,
      53,   507,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   508,   509,    71,     0,
      72,    73,    74,   551,     0,     0,    77,    78,    79,     0,
       0,   511,    81,     0,     0,     0,     0,    83,   512,    85,
     513,   514,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   515,   100,   101,   516,   517,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   116,   518,     0,     0,     0,
     118,   119,   120,   121,   519,   123,   124,   520,     0,     0,
       0,     0,     0,     0,     0,   521,   522,   131,     0,     0,
       0,   132,   133,   134,     0,   135,   523,     0,     0,     0,
       0,   140,     0,   141,     0,   142,   143,   144,   145,   524,
     147,   148,   149,   150,   151,   152,     0,     0,   153,   154,
       0,     0,   424,   157,   158,   159,   160,   161,   162,   163,
     164,   525,   552,   526,   168,   527,   528,   171,   172,   173,
     174,   175,   176,   529,   178,   530,   531,   532,   182,   183,
     533,   534,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,     0,   199,   200,   201,     0,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,     0,     0,     3,
       0,   251,   535,   253,   254,   255,   256,   257,     9,    10,
       0,     0,     0,     0,     0,     0,   421,   422,     0,    16,
      17,    18,   495,    20,    21,    22,   496,    24,   497,   498,
    1159,   500,   423,    30,   501,    32,    33,    34,     0,    35,
      36,    37,    38,   502,    40,    41,    42,    43,    44,    45,
      46,   503,     0,    48,   504,    50,   505,   506,    53,   507,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   508,   509,    71,     0,    72,    73,
      74,   510,     0,     0,    77,    78,    79,     0,     0,   511,
      81,     0,     0,     0,     0,    83,   512,    85,   513,   514,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   515,
     100,   101,   516,   517,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1160,     0,     0,     0,
    1161,     0,     0,   116,   518,     0,     0,     0,   118,   119,
     120,   121,   519,   123,   124,   520,     0,     0,     0,     0,
       0,     0,     0,   521,   522,   131,     0,     0,     0,   132,
     133,   134,  1593,   135,   523,     0,     0,     0,     0,  1594,
       0,   141,     0,   142,   143,   144,   145,   524,   147,   148,
     149,   150,   151,   152,     0,     0,  1162,   154,     0,     0,
     424,   157,   158,   159,   160,   161,   162,   163,   164,   525,
     166,   526,   168,   527,   528,   171,   172,   173,   174,   175,
     176,   529,   178,   530,   531,   532,   182,   183,   533,   534,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,     0,   199,   200,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,     0,     0,     0,     0,   251,
     535,   253,  1163,  1164,  1165,  1166,     3,     0,   579,   580,
       0,     0,     0,     0,     0,     9,    10,     0,     0,     0,
       0,     0,     0,   421,   422,     0,    16,    17,    18,   543,
      20,    21,    22,   496,   544,   545,   498,   499,   500,   423,
      30,   501,    32,   546,    34,     0,    35,    36,    37,    38,
     547,    40,   548,   549,    43,    44,    45,    46,   503,     0,
      48,   550,    50,   505,   506,    53,   507,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   508,   509,    71,     0,    72,    73,    74,   551,     0,
       0,    77,    78,    79,     0,     0,   511,    81,     0,     0,
       0,     0,    83,   512,    85,   513,   514,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   515,   100,   101,   516,
     517,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   518,     0,     0,     0,   118,   119,   120,   121,   519,
     123,   124,   520,     0,     0,     0,     0,     0,     0,     0,
     521,   522,   131,     0,     0,     0,   132,   133,   134,     0,
     135,   523,     0,     0,     0,     0,     0,     0,   141,     0,
     142,   143,   144,   145,   524,   147,   148,   149,   150,   151,
     152,     0,     0,   153,   154,     0,     0,   424,   157,   158,
     159,   160,   161,   162,   163,   164,   525,   552,   526,   168,
     527,   528,   171,   172,   173,   174,   175,   176,   529,   178,
     530,   531,   532,   182,   183,   533,   534,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     3,     0,   251,   535,   253,   254,
     255,   256,   257,     9,    10,     0,     0,     0,     0,     0,
       0,   421,   422,     0,    16,    17,    18,   543,    20,    21,
      22,   496,   544,   545,   498,   499,   500,   423,    30,   501,
      32,   546,    34,     0,    35,    36,    37,    38,   547,    40,
     548,   549,    43,    44,    45,    46,   503,     0,    48,   550,
      50,   505,   506,    53,   507,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   508,
     509,    71,     0,    72,    73,    74,   551,     0,     0,    77,
      78,    79,     0,     0,   511,    81,     0,     0,     0,     0,
      83,   512,    85,   513,   514,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   516,   517,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   518,
       0,     0,     0,   118,   119,   120,   121,   519,   123,   124,
     520,     0,     0,     0,     0,     0,     0,     0,   521,   522,
     131,     0,     0,     0,   132,   133,   134,   771,   135,   523,
       0,     0,     0,     0,   772,     0,   141,     0,   142,   143,
     144,   145,   524,   147,   148,   149,   150,   151,   152,     0,
       0,   153,   154,     0,     0,   424,   157,   158,   159,   160,
     161,   162,   163,   164,   525,   552,   526,   168,   527,   528,
     171,   172,   173,   174,   175,   176,   529,   178,   530,   531,
     532,   182,   183,   533,   534,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,     0,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,     3,     0,   251,   535,   253,   254,   255,   256,
     257,     9,    10,     0,     0,     0,   797,     0,     0,   421,
     422,     0,    16,    17,    18,   543,    20,    21,    22,   496,
     544,   545,   498,   499,   500,   423,    30,   501,    32,   546,
      34,     0,    35,    36,    37,    38,   547,    40,   548,   549,
      43,    44,    45,    46,   503,     0,    48,   550,    50,   505,
     506,    53,   507,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   508,   509,    71,
       0,    72,    73,    74,   551,     0,     0,    77,    78,    79,
       0,     0,   511,    81,     0,     0,     0,     0,    83,   512,
      85,   513,   514,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   516,   517,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   518,     0,     0,
       0,   118,   119,   120,   121,   519,   123,   124,   520,     0,
       0,     0,     0,     0,     0,     0,   521,   522,   131,     0,
       0,     0,   132,   133,   134,   798,   135,   523,     0,     0,
       0,     0,     0,     0,   141,     0,   142,   143,   144,   145,
     524,   147,   148,   149,   150,   151,   152,     0,     0,   153,
     154,     0,     0,   424,   157,   158,   159,   160,   161,   162,
     163,   164,   525,   552,   526,   168,   527,   528,   171,   172,
     173,   174,   175,   176,   529,   178,   530,   531,   532,   182,
     183,   533,   534,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
       0,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       3,     0,   251,   535,   253,   254,   255,   256,   257,     9,
      10,     0,     0,     0,     0,     0,     0,   421,   422,     0,
      16,    17,    18,   543,    20,    21,    22,   496,   544,   545,
     498,   499,   500,   423,    30,   501,    32,   546,    34,     0,
      35,    36,    37,    38,   547,    40,   548,   549,    43,    44,
      45,    46,   503,     0,    48,   550,    50,   505,   506,    53,
     507,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   508,   509,    71,     0,    72,
      73,    74,   551,     0,     0,    77,    78,    79,     0,     0,
     511,    81,     0,     0,     0,     0,    83,   512,    85,   513,
     514,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     515,   100,   101,   516,   517,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,   116,   518,     0,     0,     0,   118,
     119,   120,   121,   519,   123,   124,   520,     0,     0,     0,
       0,     0,     0,     0,   521,   522,   131,     0,     0,     0,
     132,   133,   134,   815,   135,   523,     0,     0,     0,     0,
     816,     0,   141,     0,   142,   143,   144,   145,   524,   147,
     148,   149,   150,   151,   152,     0,     0,   153,   154,     0,
       0,   424,   157,   158,   159,   160,   161,   162,   163,   164,
     525,   552,   526,   168,   527,   528,   171,   172,   173,   174,
     175,   176,   529,   178,   530,   531,   532,   182,   183,   533,
     534,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,     0,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,     0,     0,     3,     0,
     251,   535,   253,   254,   255,   256,   257,     9,    10,     0,
       0,     0,     0,     0,     0,   421,   422,     0,    16,    17,
      18,   495,    20,    21,    22,   496,    24,   497,   498,  1159,
     500,   423,    30,   501,    32,    33,    34,     0,    35,    36,
      37,    38,   502,    40,    41,    42,    43,    44,    45,    46,
     503,     0,    48,   504,    50,   505,   506,    53,   507,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   508,   509,    71,     0,    72,    73,    74,
     510,     0,     0,    77,    78,    79,     0,     0,   511,    81,
       0,     0,     0,     0,    83,   512,    85,   513,   514,    88,
      89,  1502,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   515,   100,
     101,   516,   517,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1160,     0,     0,     0,  1161,
       0,     0,   116,   518,     0,     0,     0,   118,   119,   120,
     121,   519,   123,   124,   520,     0,     0,     0,     0,     0,
       0,     0,   521,   522,   131,     0,     0,     0,   132,   133,
     134,     0,   135,   523,     0,     0,     0,     0,     0,     0,
     141,     0,   142,   143,   144,   145,   524,   147,   148,   149,
     150,   151,   152,     0,     0,  1162,   154,     0,     0,   424,
     157,   158,   159,   160,   161,   162,   163,   164,   525,   166,
     526,   168,   527,   528,   171,   172,   173,   174,   175,   176,
     529,   178,   530,   531,   532,   182,   183,   533,   534,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,     0,     0,     3,     0,   251,   535,
     253,  1163,  1164,  1165,  1166,     9,    10,     0,     0,     0,
       0,     0,     0,   421,   422,     0,    16,    17,    18,   495,
      20,    21,    22,   496,    24,   497,   498,  1159,   500,   423,
      30,   501,    32,    33,    34,     0,    35,    36,    37,    38,
     502,    40,    41,    42,    43,    44,    45,    46,   503,     0,
      48,   504,    50,   505,   506,    53,   507,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   508,   509,    71,     0,    72,    73,    74,   510,     0,
       0,    77,    78,    79,     0,     0,   511,    81,     0,     0,
       0,     0,    83,   512,    85,   513,   514,    88,    89,  1646,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   515,   100,   101,   516,
     517,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,  1160,     0,     0,     0,  1161,     0,     0,
     116,   518,     0,     0,     0,   118,   119,   120,   121,   519,
     123,   124,   520,     0,     0,     0,     0,     0,     0,     0,
     521,   522,   131,     0,     0,     0,   132,   133,   134,     0,
     135,   523,     0,     0,     0,     0,     0,     0,   141,     0,
     142,   143,   144,   145,   524,   147,   148,   149,   150,   151,
     152,     0,     0,  1162,   154,     0,     0,   424,   157,   158,
     159,   160,   161,   162,   163,   164,   525,   166,   526,   168,
     527,   528,   171,   172,   173,   174,   175,   176,   529,   178,
     530,   531,   532,   182,   183,   533,   534,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     3,     0,   251,   535,   253,  1163,
    1164,  1165,  1166,     9,    10,     0,     0,     0,     0,     0,
       0,   421,   422,     0,    16,    17,    18,   495,    20,    21,
      22,   496,    24,   497,   498,  1159,   500,   423,    30,   501,
      32,    33,    34,     0,    35,    36,    37,    38,   502,    40,
      41,    42,    43,    44,    45,    46,   503,     0,    48,   504,
      50,   505,   506,    53,   507,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   508,
     509,    71,     0,    72,    73,    74,   510,     0,     0,    77,
      78,    79,     0,     0,   511,    81,     0,     0,     0,     0,
      83,   512,    85,   513,   514,    88,    89,  1650,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   515,   100,   101,   516,   517,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1160,     0,     0,     0,  1161,     0,     0,   116,   518,
       0,     0,     0,   118,   119,   120,   121,   519,   123,   124,
     520,     0,     0,     0,     0,     0,     0,     0,   521,   522,
     131,     0,     0,     0,   132,   133,   134,     0,   135,   523,
       0,     0,     0,     0,     0,     0,   141,     0,   142,   143,
     144,   145,   524,   147,   148,   149,   150,   151,   152,     0,
       0,  1162,   154,     0,     0,   424,   157,   158,   159,   160,
     161,   162,   163,   164,   525,   166,   526,   168,   527,   528,
     171,   172,   173,   174,   175,   176,   529,   178,   530,   531,
     532,   182,   183,   533,   534,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,     0,   199,
     200,   201,     0,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,     3,     0,   251,   535,   253,  1163,  1164,  1165,
    1166,     9,    10,     0,     0,     0,     0,     0,     0,   421,
     422,     0,    16,    17,    18,   495,    20,    21,    22,   496,
      24,   497,   498,  1159,   500,   423,    30,   501,    32,    33,
      34,     0,    35,    36,    37,    38,   502,    40,    41,    42,
      43,    44,    45,    46,   503,     0,    48,   504,    50,   505,
     506,    53,   507,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   508,   509,    71,
       0,    72,    73,    74,   510,     0,     0,    77,    78,    79,
       0,     0,   511,    81,     0,     0,     0,     0,    83,   512,
      85,   513,   514,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   515,   100,   101,   516,   517,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1160,
       0,     0,     0,  1161,     0,     0,   116,   518,     0,     0,
       0,   118,   119,   120,   121,   519,   123,   124,   520,     0,
       0,     0,     0,     0,     0,     0,   521,   522,   131,     0,
       0,     0,   132,   133,   134,     0,   135,   523,     0,     0,
       0,     0,     0,     0,   141,     0,   142,   143,   144,   145,
     524,   147,   148,   149,   150,   151,   152,     0,     0,  1162,
     154,     0,     0,   424,   157,   158,   159,   160,   161,   162,
     163,   164,   525,   166,   526,   168,   527,   528,   171,   172,
     173,   174,   175,   176,   529,   178,   530,   531,   532,   182,
     183,   533,   534,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,     0,   199,   200,   201,
       0,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       3,     0,   251,   535,   253,  1163,  1164,  1165,  1166,     9,
      10,     0,     0,     0,     0,     0,     0,   421,   422,     0,
      16,    17,    18,   495,    20,    21,    22,   496,    24,   497,
     498,  1159,   500,   423,    30,   501,    32,    33,    34,     0,
      35,    36,    37,    38,   502,    40,    41,    42,    43,    44,
      45,    46,   503,     0,    48,   504,    50,   505,   506,    53,
     507,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   508,   509,    71,     0,    72,
      73,    74,   510,     0,     0,    77,    78,    79,     0,     0,
     511,    81,     0,     0,     0,     0,    83,   512,    85,   513,
     514,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     515,   100,   101,   516,   517,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1160,     0,     0,
       0,  1161,     0,     0,   116,   518,     0,     0,     0,   118,
     119,   120,   121,   519,   123,   124,   520,     0,     0,     0,
       0,     0,     0,     0,   521,   522,   131,     0,     0,     0,
     132,   133,   134,     0,   135,   523,     0,     0,     0,     0,
       0,     0,   141,     0,   142,   143,   144,   145,   524,   147,
     148,   149,   150,   151,   152,     0,     0,   153,   154,     0,
       0,   424,   157,   158,   159,   160,   161,   162,   163,   164,
     525,   166,   526,   168,   527,   528,   171,   172,   173,   174,
     175,   176,   529,   178,   530,   531,   532,   182,   183,   533,
     534,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,     0,   199,   200,   201,     0,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,     0,     0,     3,     0,
     251,   535,   253,  1163,  1164,  1165,  1166,     9,    10,     0,
       0,     0,     0,     0,     0,   421,   422,     0,    16,    17,
      18,   543,    20,    21,    22,   496,   544,   545,   498,   499,
     500,   423,    30,   501,    32,   546,    34,     0,    35,    36,
      37,    38,   547,    40,   548,   549,    43,    44,    45,    46,
     503,     0,    48,   550,    50,   505,   506,    53,   507,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   508,   509,    71,     0,    72,    73,    74,
     551,     0,     0,    77,    78,    79,     0,     0,   511,    81,
       0,     0,     0,     0,    83,   512,    85,   513,   514,    88,
      89,  1251,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   515,   100,
     101,   516,   517,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   518,     0,     0,     0,   118,   119,   120,
     121,   519,   123,   124,   520,     0,     0,     0,     0,     0,
       0,     0,   521,   522,   131,     0,     0,     0,   132,   133,
     134,     0,   135,   523,     0,     0,     0,     0,     0,     0,
     141,     0,   142,   143,   144,   145,   524,   147,   148,   149,
     150,   151,   152,     0,     0,   153,   154,     0,     0,   424,
     157,   158,   159,   160,   161,   162,   163,   164,   525,   552,
     526,   168,   527,   528,   171,   172,   173,   174,   175,   176,
     529,   178,   530,   531,   532,   182,   183,   533,   534,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,     0,     0,     3,     0,   251,   535,
     253,   254,   255,   256,   257,     9,    10,     0,     0,     0,
       0,     0,     0,   421,   422,     0,    16,    17,    18,   543,
      20,    21,    22,   496,   544,   545,   498,   499,   500,   423,
      30,   501,    32,   546,    34,     0,    35,    36,    37,    38,
     547,    40,   548,   549,    43,    44,    45,    46,   503,     0,
      48,   550,    50,   505,   506,    53,   507,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   508,   509,    71,     0,    72,    73,    74,   551,     0,
       0,    77,    78,    79,     0,     0,   511,    81,     0,     0,
       0,     0,    83,   512,    85,   513,   514,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   515,   100,   101,   516,
     517,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   518,     0,     0,     0,   118,   119,   120,   121,   519,
     123,   124,   520,     0,     0,     0,     0,     0,     0,     0,
     521,   522,   131,     0,     0,     0,   132,   133,   134,     0,
     135,   523,     0,     0,     0,     0,     0,     0,   141,     0,
     142,   143,   144,   145,   524,   147,   148,   149,   150,   151,
     152,     0,     0,   153,   154,     0,     0,   424,   157,   158,
     159,   160,   161,   162,   163,   164,   525,   552,   526,   168,
     527,   528,   171,   172,   173,   174,   175,   176,   529,   178,
     530,   531,   532,   182,   183,   533,   534,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
       0,   199,   200,   201,     0,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     0,     0,   251,   535,   253,   254,
     255,   256,   257,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   421,   422,     0,    16,    17,
      18,   848,    20,    21,    22,    23,     0,   849,   498,    27,
       0,   423,    30,   501,    32,     0,    34,     0,    35,    36,
      37,    38,   850,    40,     0,     0,    43,    44,    45,    46,
     503,     0,    48,   851,    50,     0,     0,    53,   507,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   508,   509,    71,     0,    72,    73,    74,
     852,     0,     0,    77,    78,    79,     0,     0,   511,    81,
       0,     0,     0,    82,    83,   512,    85,   513,   514,    88,
      89,   565,    91,     0,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   515,   100,
     101,   516,   517,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,     0,   566,   112,     0,   113,
     114,     0,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   520,     0,   126,     0,     0,     0,
       0,     0,   521,   522,   131,     0,     0,     0,   132,   133,
     134,     0,   135,   523,     0,     0,     0,     0,     0,     0,
     141,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   154,   155,     0,   424,
     157,   158,   159,   160,   161,   162,   163,   164,   525,     0,
     526,   168,   527,   528,   171,   172,   173,   174,   175,   176,
     529,   178,   530,   531,   532,   182,   183,     0,   534,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,     0,   250,     9,    10,   535,
     253,     0,     0,     0,     0,   421,   422,     0,    16,    17,
      18,     0,    20,    21,    22,   496,     0,     0,   498,   499,
       0,   423,    30,   501,    32,     0,    34,     0,    35,    36,
      37,    38,     0,    40,     0,     0,    43,    44,    45,    46,
     503,     0,    48,     0,    50,     0,     0,    53,   507,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   508,   509,    71,     0,    72,    73,    74,
       0,     0,     0,    77,    78,    79,     0,     0,   511,    81,
       0,     0,     0,     0,    83,   512,    85,   513,   514,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   515,   100,
     101,   516,   517,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,     0,     0,     0,     0,     0,
       0,     0,   116,   518,     0,     0,     0,   118,   119,   120,
     121,   519,   123,   124,   520,     0,     0,     0,     0,     0,
       0,     0,   521,   522,   131,     0,     0,     0,   132,   133,
     134,     0,   135,   523,     0,     0,     0,     0,     0,     0,
     141,     0,   142,   143,   144,   145,   524,   147,   148,   149,
     150,   151,   152,     0,     0,     0,   154,     0,     0,   424,
     157,   158,   159,   160,   161,   162,   163,   164,   525,     0,
     526,   168,   527,   528,   171,   172,   173,   174,   175,   176,
     529,   178,   530,   531,   532,   182,   183,     0,   534,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,     0,   199,   200,   201,     0,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,     0,     0,     0,     0,     0,   535,
     253
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   112,   113,   185,    14,     5,     6,     7,     8,   432,
     433,   685,   434,   701,   318,   348,     0,   835,   791,   776,
     297,     5,     6,     7,     8,  1064,   925,   318,     5,     6,
       7,   804,   139,   686,   687,   688,   689,   266,   625,   626,
     265,   592,   872,  1048,   776,   818,   597,   469,   470,  1309,
      76,  1292,   281,   961,  1373,  1374,  1088,     5,     6,     7,
       8,   258,   259,     1,   938,   939,  1145,     1,  1011,     5,
       6,     7,     8,    36,  1029,   733,   623,   624,   625,   626,
     938,   939,  1505,   623,   624,  1508,  1322,    36,     1,    56,
    1420,   143,    27,    28,     8,   288,   108,   119,    27,    28,
       1,     1,    37,    38,  1615,    40,    41,     1,    31,   154,
      30,   111,    47,   108,    30,   227,     1,     1,    47,   977,
       1,     1,    57,    58,     1,   108,     1,   111,   108,   227,
     122,   119,    95,   131,    97,    27,    28,    39,   249,   250,
      75,     1,    44,    45,     1,    80,    75,   137,    97,     1,
     427,    53,   977,  1011,   431,    47,     1,  1031,    60,   132,
      62,    63,     1,   111,  1038,    57,     1,   212,     1,    71,
     108,   219,   184,  1031,   108,   111,     1,   112,   113,   114,
    1038,   182,    94,    75,   113,   148,   297,   664,    80,   666,
     667,   111,   669,     1,   671,   108,    98,   198,   114,   148,
      33,   199,   679,   680,   316,   125,   193,   194,   256,   192,
     983,    37,    38,   203,    40,    41,     0,     1,   316,   192,
     112,   113,   114,   275,     1,    97,   161,     1,   108,  1548,
     150,     1,    58,   108,   154,     1,     1,   157,     1,   227,
       0,     1,   237,   235,   351,   161,  1145,  1146,   108,    30,
    1289,   108,   219,   275,  1765,   235,   108,   177,   258,   259,
     453,   175,   262,   108,  1037,     1,  1084,   571,     1,   108,
    1275,   183,   161,   108,   258,   259,   189,  1518,   262,  1036,
     571,  1313,   559,   108,  1614,  1521,  1194,   222,   114,   256,
    1322,   192,   192,   216,   881,   882,  1251,   297,   192,  1242,
     108,     1,  1034,  1161,  1036,   963,  1729,   192,   192,   189,
      95,   192,   275,   297,   189,   192,   427,  1396,  1050,   148,
     431,   309,   744,   101,   108,   227,   275,    95,   263,   189,
     356,   108,   189,   359,   108,   161,  1161,   189,   108,   879,
     880,   261,   108,   108,   189,   108,   119,   108,   108,   184,
     189,   462,   148,  1776,   289,  1778,   467,    95,    97,   184,
     289,    77,   297,   108,  1137,     1,   477,   789,   297,   107,
     305,   648,   108,   484,   485,   108,    45,   315,     1,   313,
     161,   189,   493,    97,  1242,     1,   258,   259,     1,   119,
      76,   620,   621,  1267,    63,  1714,   222,   289,   623,   624,
     184,   630,    27,    28,    90,   297,    95,   157,   108,  1267,
     188,   185,   189,   305,   184,   612,   189,   319,   320,   321,
     185,   184,   131,   189,   184,   154,    52,   427,   114,   190,
     169,   431,    30,  1291,   169,   220,   221,   263,   154,   227,
     126,   229,   128,   427,   921,   190,   275,   431,   559,  1768,
     235,   184,   220,   221,    55,   169,    57,     3,   458,   148,
     460,    45,     5,    47,   575,   576,     9,   235,  1241,   204,
       9,    10,   108,     5,   458,   586,   460,     9,  1676,   275,
     145,   188,   482,   212,   184,   108,   157,   487,   113,  1521,
     199,  1751,   108,   604,   605,   108,  1253,  1396,   482,   227,
     101,   229,   925,   487,   130,   212,  1405,   223,   224,   108,
     458,   176,   460,   111,   108,   254,   255,  1416,   257,   108,
     189,    67,   458,   107,   460,  1355,    72,   125,   316,  1359,
    1262,   196,   101,   956,   482,   274,  1123,  1124,  1125,   487,
     254,   255,   234,   257,   236,   114,   482,   286,   184,  1237,
     264,   487,   150,   108,  1428,  1796,  1754,  1108,   107,   559,
     274,   184,   984,   985,   157,   104,   566,   989,   184,   159,
    1428,   184,   286,   119,   108,   559,  1123,  1124,  1125,   128,
      30,   124,   566,   126,   168,   124,   176,   126,   316,    95,
     189,   134,   124,   870,   126,   189,   707,  1019,   705,   706,
     189,    45,   134,    47,  1377,   605,   108,   155,   618,   157,
     154,   154,   612,     9,   108,   154,   108,     9,   566,   158,
     897,   605,   154,   623,   624,   625,   626,  1632,   612,   108,
     566,     9,    10,    29,   189,   174,    80,    29,    97,   623,
     624,   625,   626,     1,   203,     3,   157,  1505,   648,   155,
    1508,   157,   253,   212,   879,   189,   885,   605,   197,   108,
     889,   111,   119,   107,   648,   266,   108,   268,   119,    97,
     356,   249,   250,   359,   157,   125,   215,    33,   279,   280,
     281,   271,   283,    95,   285,  1584,   114,   189,   278,   148,
      97,   239,   182,    49,   272,   189,   166,   189,   288,   157,
     150,  1519,   702,     1,   154,   157,  1524,   157,   198,    67,
     189,  1750,   182,   118,    72,   826,   827,   828,   702,   830,
    1477,    95,  1145,  1146,   168,   702,   104,   177,   124,   157,
     126,   188,   124,  1407,   126,    33,   148,   188,    97,   135,
     189,   148,   147,   135,    54,   154,   124,   189,   126,    59,
      97,    49,   438,   439,   702,   160,   442,    95,   154,   870,
     446,   119,   154,   449,   450,   154,   702,   114,    78,   143,
    1644,   457,     9,    10,  1462,  1362,   154,   463,   464,    95,
     158,   781,    95,     9,    10,   471,  1644,    97,   177,   159,
     123,   196,   478,   479,   480,   481,   174,   781,   157,   123,
     486,  1741,  1742,    97,   781,   143,   176,    42,   494,   119,
     157,    46,   812,   813,  1147,  1025,    51,  1027,   149,   197,
     114,   154,   138,  1697,   157,  1699,    54,   143,   812,   813,
     143,    59,   154,   781,   165,    70,  1113,   215,  1656,  1697,
     159,  1699,  1660,  1783,   149,   781,   138,   974,  1270,  1789,
     157,   270,   155,   539,   157,   177,   138,   176,   277,   986,
     165,  1071,   154,  1073,   812,   813,   159,   104,   554,    97,
     870,  1729,   154,    96,   157,   227,   812,   813,   104,   565,
     232,   891,   201,   176,   107,  1114,   870,   124,  1762,   126,
      25,  1120,   154,   137,   117,   157,   101,   897,   124,    34,
     126,  1575,  1576,   101,  1762,   128,   592,   151,   201,   114,
     301,   597,   101,   897,   600,  1568,   114,   154,  1776,   310,
    1778,   158,   234,   271,   236,   114,    61,  1745,   154,  1617,
     278,   101,   158,   168,   146,  1117,   171,   174,   265,   265,
     288,  1714,   101,   154,   114,   157,   157,  1369,   174,   276,
     276,   186,   187,   188,   138,   114,  1378,   129,   130,   143,
     197,   279,   280,   281,   627,   138,   708,   285,   631,   711,
     143,   197,   714,  1396,   660,    54,   129,   130,   215,   214,
      59,   157,  1405,   154,   355,   154,   157,   358,   157,   215,
     683,   684,  1269,  1416,   223,   224,   225,  1288,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   690,   691,
     123,  1685,  1686,   133,   692,   693,  1235,  1236,   123,  1605,
    1606,   141,   142,   119,   144,   123,   123,   119,   123,   123,
     154,  1719,   152,  1144,   123,   123,   156,   123,   158,   123,
     154,   218,   157,   163,   119,   244,   243,   243,   157,   316,
    1354,   737,   154,     0,   740,  1346,   192,   167,    93,   179,
     251,   100,    50,  1354,  1486,   202,  1066,   103,   754,   102,
     195,    30,   758,   759,   155,   157,   184,   184,  1766,    47,
     184,   184,  1066,    90,  1758,   205,   206,   207,   208,   209,
     210,   777,   153,   119,   248,   154,   306,     1,   189,   785,
     119,   143,   788,   108,   189,   154,   792,   114,   154,   189,
     157,   143,  1122,  1113,   157,   184,   157,   157,  1066,   126,
     157,   128,   122,  1123,  1124,  1125,   157,   157,   157,  1113,
    1066,   154,    35,    17,    30,   192,   192,     3,   216,  1123,
    1124,  1125,   119,   233,   168,   170,   247,   286,   834,   170,
    1838,    71,  1840,   286,   119,    95,   233,    95,    95,   150,
     108,  1584,  1850,   108,   161,    30,   161,   189,   128,  1351,
     133,    95,   248,   301,   143,   119,   133,   189,   184,   189,
     184,   108,    95,    97,    45,    97,   872,   189,   189,    95,
     189,   189,   184,   154,   184,   239,   154,   143,   154,   154,
     154,   154,    33,  1494,   170,  1496,   192,   235,  1499,  1500,
     184,   133,  1503,   143,    95,   901,    30,   288,  1509,    95,
     229,  1498,   154,   128,   119,   148,   119,   913,   301,   200,
     161,    95,   184,   133,   133,    97,   154,   119,   148,   154,
      35,   101,   101,   184,   122,  1245,   143,   154,   184,   192,
      30,   119,   938,   939,   940,   941,    80,   108,   247,   107,
     256,  1245,   108,   157,  1541,   157,   260,   287,  1245,  1269,
     157,   157,   157,   145,   157,   262,   269,   157,    30,    30,
    1280,    30,   145,   192,   128,  1269,   289,   229,   189,   108,
     308,   977,   148,   148,   143,   101,  1280,  1245,   189,  1299,
     189,   189,   200,  1280,   288,   991,   133,   184,     7,  1245,
     189,    97,   157,   239,   189,  1299,   235,   188,   192,  1319,
     157,   157,  1299,   107,   235,   154,  1326,   235,   148,   119,
    1016,   119,  1280,   235,    78,  1319,   189,   148,   288,  1025,
      79,  1027,  1326,  1029,  1280,  1031,   189,   189,   189,   284,
     189,  1299,  1038,  1630,   189,   189,  1647,   189,  1358,    30,
    1651,    30,   252,  1299,  1641,  1642,   108,   170,  1645,   184,
     148,  1319,   148,   127,  1358,  1652,    97,   127,  1326,   252,
     184,   143,   184,  1319,   184,  1071,   184,  1073,   184,   318,
    1326,   154,   259,    95,    30,   189,    97,   189,   170,    95,
     148,    54,   199,   273,    95,    30,   119,    95,   108,   227,
    1358,   108,    95,   282,   199,   267,   199,   227,   200,    94,
     199,   119,  1108,   183,   119,   119,   119,  1538,  1539,  1540,
     201,   289,   439,   119,   227,   442,   262,   262,   295,   446,
    1197,   743,   449,   450,  1735,   978,  1719,  1133,   265,  1242,
     457,   433,  1039,   307,  1766,   873,   463,   464,   308,   289,
     307,  1738,  1142,  1388,   471,   660,   794,   307,   453,  1561,
     308,   478,   479,   480,   481,  1161,  1380,  1129,  1376,   486,
     308,  1281,  1373,  1286,  1775,  1289,   554,   494,  1779,  1294,
     682,  1313,   717,   941,   662,   835,   663,  1789,  1498,  1783,
    1777,  1027,  1196,  1345,  1584,  1356,  1355,  1416,  1405,  1146,
     343,  1581,   461,  1409,  1498,  1155,  1219,  1010,  1795,  1452,
    1811,  1608,   461,  1814,  1406,   595,    -1,    -1,    -1,    -1,
      -1,    -1,   539,  1810,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1541,    -1,    -1,    -1,    -1,  1837,   554,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1832,    -1,  1541,   565,    -1,
      -1,    -1,  1673,    -1,  1841,  1251,    -1,    -1,    -1,  1255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1267,    -1,    -1,  1695,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   600,    -1,  1281,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1291,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1630,    -1,    -1,    -1,  1320,    -1,    -1,    -1,    -1,    -1,
      -1,  1641,  1642,    -1,    -1,  1645,  1630,    -1,    -1,    -1,
      -1,    -1,  1652,   660,    -1,    -1,    -1,  1641,  1642,  1345,
      -1,  1645,    -1,    -1,    -1,    -1,    -1,    -1,  1652,  1355,
      -1,    -1,    -1,  1359,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   740,    -1,    -1,    -1,    -1,  1738,    -1,
      -1,    -1,  1428,    -1,    -1,    -1,    -1,   754,    -1,    -1,
      -1,   758,   759,    -1,  1738,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     777,    -1,  1458,    -1,    -1,    -1,    -1,  1777,   785,    -1,
      -1,   788,    -1,    -1,    -1,   792,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1777,    -1,  1795,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1810,  1795,    -1,    -1,    -1,    -1,  1502,    -1,    -1,  1505,
      -1,    -1,  1508,    -1,    -1,    -1,  1810,   834,    -1,    -1,
      -1,    -1,  1832,    -1,  1520,    -1,    -1,    -1,    -1,  1525,
      -1,  1841,    -1,    -1,    -1,    -1,    -1,    -1,  1832,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1841,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1558,  1559,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   901,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   913,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   938,   939,   940,   941,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1644,    -1,
    1646,    -1,  1648,    -1,  1650,    -1,    -1,    -1,    -1,    -1,
     977,  1657,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   991,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1016,
      -1,  1697,    -1,  1699,    -1,    -1,    -1,    -1,  1025,    -1,
    1027,    -1,  1029,    -1,  1031,    -1,    -1,    -1,    -1,  1715,
      -1,  1038,  1718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1729,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1740,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1071,    -1,  1073,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1762,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1770,    -1,    -1,    -1,    -1,    -1,
    1776,    -1,  1778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1799,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1808,    -1,    -1,    -1,  1133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   566,    -1,    -1,    -1,
      -1,    -1,  1828,    -1,    -1,    -1,    -1,  1833,    -1,    -1,
      -1,    -1,    -1,    -1,  1161,    -1,    -1,    -1,    -1,  1845,
     590,   591,  1848,   593,   594,   595,   596,    -1,   598,    -1,
      -1,    -1,    -1,   603,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   633,   634,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   642,   643,    -1,   645,    -1,    -1,   648,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,     3,  1251,    -1,    -1,    -1,  1255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1281,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,   713,  1291,    -1,    46,   717,    -1,    -1,
      50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    72,  1320,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   756,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    95,    96,    97,  1345,    -1,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,   119,
      -1,    -1,   122,   793,    -1,    -1,    -1,   127,   128,    -1,
      -1,    -1,    -1,   133,    -1,    -1,    -1,   137,    -1,    -1,
    1387,   141,   142,    -1,   144,    -1,   146,   147,    -1,   819,
      -1,   151,   152,   823,   824,   155,   156,   157,   158,   159,
     160,    -1,   832,   163,    -1,    -1,    -1,   167,   168,    -1,
      -1,   171,    -1,    -1,    -1,    -1,   176,    -1,    -1,   179,
      -1,  1428,    -1,    -1,   184,   185,   186,   187,   188,   189,
     190,    -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,   206,   207,   208,   209,
     210,  1458,   212,    -1,   214,    -1,    -1,    -1,    -1,   219,
     220,   221,    -1,    -1,    -1,    -1,    -1,   897,    -1,    -1,
      -1,    -1,    -1,   903,   904,   235,    -1,   237,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,  1502,   256,    -1,  1505,    -1,
      -1,  1508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1520,    -1,    -1,    -1,    -1,  1525,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   979,
      -1,  1558,  1559,   313,    -1,   315,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1014,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1033,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1049,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1060,  1061,    -1,    -1,    -1,    -1,    -1,  1644,    -1,  1646,
      -1,  1648,    -1,  1650,    -1,  1075,    -1,    -1,  1078,    -1,
    1657,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1095,  1096,  1097,    -1,  1099,
    1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,    -1,    -1,
    1110,  1111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1119,
    1697,    -1,  1699,    -1,    -1,    -1,    -1,    -1,    -1,  1129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1715,    -1,
      -1,  1718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1740,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1184,  1762,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1770,    -1,    -1,    -1,    -1,    -1,  1776,
      -1,  1778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1808,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1828,    -1,    -1,    -1,    -1,  1833,  1257,    -1,  1259,
      -1,  1261,    -1,    -1,    -1,    -1,    -1,    -1,  1845,  1269,
      -1,  1848,    -1,    -1,    -1,    -1,    -1,    -1,  1278,    -1,
      -1,    -1,    -1,    -1,  1284,  1285,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1303,    -1,    -1,  1306,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1376,    -1,    -1,    -1,
    1380,  1381,    -1,    -1,    -1,    -1,  1386,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1471,    -1,    -1,    -1,  1475,    -1,    -1,    -1,  1479,
      -1,  1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1489,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1497,  1498,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1517,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1529,
    1530,  1531,  1532,    -1,  1534,  1535,    -1,  1537,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1552,    -1,    -1,    -1,    -1,  1557,    -1,    -1,
      -1,    -1,    -1,  1563,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1623,    -1,  1625,    -1,    -1,  1628,    -1,
      -1,  1631,    -1,    -1,    -1,    -1,  1636,  1637,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1645,    -1,    -1,    -1,  1649,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1666,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1722,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1734,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1777,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,    -1,    -1,  1806,    -1,    -1,    -1,
    1810,    11,    12,    -1,    -1,  1815,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,  1831,    -1,    33,    34,  1835,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,    -1,
     190,   191,   192,   193,   194,    -1,   196,    -1,   198,    -1,
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
     320,   321,   322,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,    -1,   190,   191,   192,   193,   194,    -1,   196,
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
     307,   308,   309,   310,   311,   312,     1,   314,    -1,   316,
     317,   318,   319,   320,   321,   322,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,    -1,   190,   191,   192,   193,   194,
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
     305,   306,   307,   308,   309,   310,   311,   312,     1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,    -1,   190,   191,    -1,
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
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,    -1,   190,
     191,   192,   193,   194,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,   323,   324,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,    -1,   190,   191,   192,   193,   194,    -1,   196,
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
     317,   318,   319,   320,   321,   322,    -1,   324,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,   187,   188,    -1,   190,   191,   192,
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
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,   184,    -1,   186,   187,   188,    -1,   190,
     191,   192,   193,   194,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,   184,    -1,   186,   187,   188,
      -1,   190,   191,   192,   193,   194,    -1,   196,    -1,   198,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,    -1,   190,   191,   192,   193,   194,    -1,   196,
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
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,    -1,   190,   191,   192,   193,   194,
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
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,    -1,   190,   191,   192,
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
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,    -1,   190,
     191,   192,   193,   194,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
      -1,   190,   191,   192,   193,   194,    -1,   196,    -1,   198,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,    -1,   190,   191,   192,   193,   194,    -1,   196,
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
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
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
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,   189,   190,   191,    -1,
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
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,   185,   186,   187,   188,    -1,   190,
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
     321,   322,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,    -1,   190,   191,    -1,   193,   194,    -1,   196,
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
     317,   318,   319,   320,   321,   322,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,    -1,   190,   191,    -1,   193,   194,
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
     315,   316,   317,   318,   319,   320,   321,   322,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,    -1,   190,   191,    -1,
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
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,    -1,   190,
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
     321,   322,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,    -1,   190,   191,    -1,   193,   194,    -1,   196,
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
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,    -1,   190,   191,    -1,   193,   194,
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
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,   157,   158,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,    -1,   190,   191,    -1,
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
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,   157,   158,    -1,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,    -1,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,    -1,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,    -1,   152,   153,   154,   155,    -1,   157,   158,
      -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
      -1,   200,    -1,   202,    -1,   204,   205,   206,   207,   208,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,   196,
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
     307,   308,   309,   310,   311,    -1,    -1,    -1,    -1,   316,
     317,   318,   319,   320,   321,   322,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,    -1,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,    -1,   200,   201,   202,   203,   204,
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
     305,   306,   307,   308,   309,   310,   311,    -1,    -1,    16,
      -1,   316,   317,   318,   319,   320,   321,   322,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
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
     307,   308,   309,   310,   311,    -1,    -1,    -1,    -1,   316,
     317,   318,   319,   320,   321,   322,    16,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
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
     320,   321,   322,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
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
     322,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,    -1,    -1,
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
      16,    -1,   316,   317,   318,   319,   320,   321,   322,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
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
     306,   307,   308,   309,   310,   311,    -1,    -1,    16,    -1,
     316,   317,   318,   319,   320,   321,   322,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,   157,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
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
     308,   309,   310,   311,    -1,    -1,    16,    -1,   316,   317,
     318,   319,   320,   321,   322,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
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
     320,   321,   322,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,    -1,   190,   191,
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
     322,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,   157,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,    -1,   190,   191,    -1,    -1,
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
      16,    -1,   316,   317,   318,   319,   320,   321,   322,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,   157,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
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
     306,   307,   308,   309,   310,   311,    -1,    -1,    16,    -1,
     316,   317,   318,   319,   320,   321,   322,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
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
     308,   309,   310,   311,    -1,    -1,    16,    -1,   316,   317,
     318,   319,   320,   321,   322,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
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
     310,   311,    -1,    -1,    -1,    -1,   316,   317,   318,   319,
     320,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      -1,    49,    50,    51,    52,    -1,    54,    -1,    56,    57,
      58,    59,    60,    61,    -1,    -1,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,   125,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,    -1,   154,   155,    -1,   157,
     158,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,    -1,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,   314,    25,    26,   317,
     318,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    -1,    40,    41,    42,    43,    -1,    -1,    46,    47,
      -1,    49,    50,    51,    52,    -1,    54,    -1,    56,    57,
      58,    59,    -1,    61,    -1,    -1,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    -1,    -1,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      -1,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,    -1,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    -1,    -1,    -1,    -1,    -1,   317,
     318
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    16,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    30,    33,    34,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    95,    96,    97,    98,    99,   101,   102,   103,
     106,   107,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   125,   127,   128,   129,   130,   132,   136,
     137,   138,   139,   140,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   157,   158,   159,   160,   161,   165,   166,
     167,   168,   169,   170,   171,   172,   174,   176,   177,   180,
     181,   182,   186,   187,   188,   190,   191,   192,   193,   194,
     196,   198,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   213,   214,   215,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   261,
     262,   263,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     314,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     337,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   358,   359,
     360,   361,   362,   363,   367,   368,   369,   373,   375,   376,
     378,   385,   387,   390,   391,   392,   394,   395,   396,   397,
     398,   400,   401,   403,   404,   405,   406,   407,   408,   410,
     411,   414,   415,   416,   417,   418,   424,   426,   430,   431,
     432,   437,   456,   459,   463,   466,   467,   473,   474,   475,
     476,   478,   479,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   491,   492,   493,   494,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   527,   528,   529,   530,   531,   532,   546,
     547,   549,   550,   551,   552,   553,   554,   555,   556,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   578,   583,   584,   585,   586,   587,   588,   591,   649,
     650,   651,   652,   654,   655,   656,   657,   658,   661,   662,
     663,    33,    34,    49,   217,   393,   394,   395,   393,   393,
     394,   395,   157,   157,    37,    38,    40,    41,    47,    57,
      58,    75,    80,   112,   113,   114,   161,   222,   263,   289,
     297,   305,   374,   375,   379,   380,   381,   161,   154,   157,
     154,   157,   154,   157,     1,   157,   382,   157,    25,    34,
      61,   119,   275,   436,   438,   439,   157,   154,   157,   157,
     157,   119,   154,   157,   157,   157,    77,   154,   223,   224,
     123,   123,   123,   154,   157,    39,    43,    45,    46,    47,
      48,    51,    60,    68,    71,    73,    74,    76,    91,    92,
      98,   106,   113,   115,   116,   136,   139,   140,   161,   169,
     172,   180,   181,   191,   204,   226,   228,   230,   231,   238,
     240,   241,   242,   245,   246,   317,   511,   662,   123,   119,
     402,   123,   123,    39,    44,    45,    53,    60,    62,    63,
      71,    98,   227,   661,   119,   123,   123,   184,   393,   395,
     416,   653,    48,    73,    74,   119,   154,   185,   246,   415,
     417,   430,   189,   415,   661,   154,   154,   123,   661,    18,
      19,   661,   123,   123,   123,   503,   154,    31,   216,   218,
     227,   229,   316,   227,   229,   316,   227,   316,   227,   232,
     119,   243,   243,   244,   157,   154,   397,   313,   415,   315,
     415,   316,   324,   339,   339,     0,   341,   342,    33,    49,
     344,   361,     1,   192,   338,   192,   338,   113,   376,   396,
     415,   108,   192,   108,   338,   192,    42,    46,    51,    70,
     168,   171,   186,   187,   188,   214,   409,   419,   420,   425,
     426,   427,   428,   429,   444,   445,   449,     3,    67,    72,
     119,   421,   167,    93,   133,   141,   142,   144,   152,   156,
     158,   163,   179,   205,   206,   207,   208,   209,   210,   495,
     496,   251,   100,   159,   176,   201,   118,   147,   160,   196,
     203,   212,   137,   151,    50,   202,   102,   103,   159,   176,
     493,   195,   154,   500,   503,   193,   194,   155,   515,   516,
     511,   515,   511,   157,   515,   157,   146,   157,   184,   184,
     184,   184,   377,   518,   377,    30,   660,   182,   198,   182,
     198,   166,   182,   662,   661,   169,   204,    47,   661,   153,
     119,    45,    47,    80,   107,   168,   661,   223,   224,   225,
     248,   622,   661,   661,   306,   138,   143,   113,   289,   297,
     379,   661,   394,   189,   394,    45,    63,   189,   574,   575,
     415,   189,   196,   661,   433,   434,   661,   119,   189,   383,
     384,   154,   399,   415,     1,   161,   660,   114,   161,   357,
     660,   661,   119,   143,   108,   189,   415,    30,   189,   661,
     661,   661,   457,   458,   661,   394,   189,   415,   415,   576,
     661,   394,   154,   154,   415,   189,   196,   661,   661,   143,
     457,   184,   184,   122,   108,   184,   157,   157,   157,   661,
     154,   185,   420,   189,    35,   534,   535,   536,   415,   415,
       8,   175,    17,   415,   216,    30,   416,   416,    39,    45,
      60,    71,    98,   514,   662,   416,   416,   416,   653,   416,
     514,   416,   233,   589,   590,   661,   192,   192,   416,   415,
     395,   415,   247,   412,   413,   313,   315,   416,   339,   192,
     338,   192,   338,     3,   345,   361,   391,     1,   345,   361,
     391,    33,   362,   391,   362,   391,   402,   338,   402,   416,
     416,   119,   168,   170,   170,   416,   416,   416,   396,   416,
     286,   286,   433,   119,   440,   475,   476,   478,   478,   478,
     478,   477,   478,   478,   478,    71,   479,   483,   483,   482,
     484,   484,   484,   484,   485,   485,   486,   486,   233,    95,
      95,    95,   501,   393,   503,   503,   415,   516,   145,   189,
     416,   526,   189,   150,   189,   526,   108,   189,   189,   108,
     108,   382,    30,   662,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,   364,   365,   366,    95,   138,   143,
     370,   371,   372,   661,   161,   161,   364,   660,   128,   133,
      55,    57,   101,   253,   266,   268,   279,   280,   281,   283,
     285,   623,   624,   625,   626,   627,   628,   635,   641,   642,
     248,    95,   301,   661,   143,   416,   119,   661,   661,   133,
     184,   184,   189,   189,   184,   108,   189,   108,   189,   108,
      36,    95,    97,   148,   435,   436,   557,   661,    95,   108,
     189,   393,   189,   661,    97,    45,   661,   660,    97,   143,
     557,   661,   416,   439,   184,   189,   189,   189,   189,   108,
     190,   148,   557,   184,   189,   189,   154,   184,   394,   394,
     184,   108,   189,   108,   189,   143,   557,   416,   190,   416,
     416,   415,   415,   415,   661,   535,   536,   131,   199,   184,
     184,   184,   132,   192,    95,   220,   221,   235,    95,   220,
     221,   235,   235,   235,    95,    95,   239,   227,   316,   108,
     237,   143,   192,   189,   415,   184,   512,   595,   413,   235,
     361,    33,    33,   192,   338,   192,   114,   396,   661,   170,
     416,   450,   451,   119,   416,   446,   447,   661,    56,   219,
     256,   422,   423,   478,   154,   157,   261,   499,   518,   596,
     599,   600,   601,   602,   603,   607,   609,   611,   612,    47,
     153,   157,   213,   319,   320,   321,   322,   558,   560,   562,
     564,   579,   580,   581,   582,   659,   661,   558,   490,   563,
     661,   490,   184,   185,   108,   189,   189,   518,   149,   165,
     149,   165,   138,   399,   382,   365,   133,   560,   372,   416,
     557,   660,   660,   129,   130,   660,   279,   280,   281,   285,
     661,   265,   276,   265,   276,    30,   288,    97,   114,   157,
     629,   632,   623,    39,    44,    53,    60,    62,    71,    98,
     227,   319,   320,   321,   386,   564,   659,   229,   301,   310,
     416,   661,    95,   301,   660,   154,   576,   577,   661,   576,
     577,   119,   434,   128,   558,   119,   416,   148,   436,   148,
      36,   148,   435,   436,   557,   558,   384,    95,   184,   200,
     133,   356,   660,   161,   133,    97,   356,   416,   143,   436,
     154,   119,   416,   416,   148,   101,   460,   461,   462,   464,
     465,   101,   468,   469,   470,   471,   394,   184,   184,   154,
     576,   576,   416,   143,   192,   416,   122,   189,   189,   189,
      35,   536,   131,   199,     9,    10,   104,   124,   126,   154,
     197,   531,   533,   544,   545,   548,   154,    30,   234,   236,
     416,   416,   416,   234,   236,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   514,   119,   416,   416,    48,    73,
      74,   246,   396,   417,   430,   247,   592,   593,   154,   212,
     397,   416,   192,   114,   391,   391,   391,   450,    96,   107,
     117,   128,   452,   453,   454,   455,   108,   661,   107,   448,
     108,   148,   557,   256,    54,    59,    78,   119,   435,   441,
     442,   443,   423,   415,   596,   603,   154,   287,   480,   648,
      97,   169,   254,   255,   257,   264,   274,   286,   597,   598,
     617,   618,   619,   620,   643,   646,   260,   262,   604,   622,
     269,   608,   644,   249,   250,   272,   613,   614,   157,   157,
     560,   157,   157,   157,   157,   157,   145,   176,   196,   559,
     145,   145,   416,   138,   399,   578,   371,   288,    30,    97,
     114,   157,   636,    30,   629,   559,   559,   501,   289,   308,
     557,   386,   229,   192,   393,   189,   189,   145,   189,   189,
     434,   148,   435,   661,   416,   148,   416,   128,   416,   148,
     436,   148,   558,   396,   416,   660,   108,   356,   416,   143,
     393,   458,   416,   416,   114,   461,   462,   101,   420,   114,
     462,   465,   119,   472,   558,   101,   114,   469,   101,   114,
     471,   184,   393,   189,   189,   416,   416,   200,   468,   133,
     197,   533,     7,   394,   661,   197,   544,   394,   192,   235,
     235,   235,   235,    97,   239,   239,   590,   420,   157,   157,
     157,   420,   595,   593,   512,   660,   129,   130,   454,   455,
     455,   451,   143,   557,   660,   447,   416,   148,   119,   119,
     416,   661,   443,    78,   184,   189,   596,   610,   252,   219,
     256,   270,   277,   647,    97,   258,   259,   645,   252,   600,
     647,   482,   617,   601,   148,   284,   605,   606,   645,   288,
     616,    79,   615,   189,   196,   558,   561,   189,   189,   189,
     189,   189,   189,   189,    30,   137,   203,   638,   639,   640,
      30,   637,   638,   273,   633,   108,   630,   170,   661,   259,
     501,   184,   416,   148,   416,   148,   435,   416,   148,   416,
     127,   127,    97,   660,   416,   184,   420,   420,   416,   396,
     416,   420,   420,   661,   212,   420,   119,   472,   119,   420,
     119,   472,   420,   184,   114,   536,   661,   197,   184,   536,
     661,   184,   416,   416,   416,   416,   318,   416,   416,   416,
     415,   415,   415,   154,   594,   455,   416,   143,   416,   661,
     661,   442,   416,   184,   484,    52,   130,   482,   482,   271,
     278,   288,   621,   621,   602,   154,   282,    95,   189,   108,
     189,   636,   636,   640,   108,   189,    30,   634,   645,   631,
     632,   189,   388,   389,   501,   119,   227,   309,   289,   170,
     416,   416,   148,   416,   396,   416,   356,   416,   396,    95,
     558,   396,   416,   661,   420,   661,   416,   661,   420,   396,
     119,    94,   183,   537,   536,   661,   199,   536,   416,   189,
     189,   189,   415,   448,   416,    54,   482,   482,   201,   415,
     558,   558,    95,    30,   267,   108,   108,   455,   557,   661,
     119,   227,   661,   388,   416,   472,    95,   420,    95,   661,
       5,   134,   540,   541,   543,   545,    29,   135,   538,   539,
     542,   545,   199,   536,   199,   200,   468,   184,   448,   119,
     482,   184,   558,   632,   389,   455,   307,   661,   119,   227,
     420,   472,   396,   416,   472,   420,    94,   134,   543,   183,
     135,   542,   199,   114,   661,   416,   307,   661,   119,   396,
     416,   420,   420,   119,   295,   307,   661,   661,   308,   416,
     308,   420,   501,   501,   201,   289,   661,   227,   119,   661,
     308,   501
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
     396,   396,   396,   396,   396,   396,   396,   397,   397,   398,
     399,   400,   401,   401,   401,   402,   402,   402,   402,   403,
     404,   405,   406,   407,   407,   408,   409,   410,   411,   412,
     412,   413,   414,   415,   415,   415,   416,   416,   416,   416,
     416,   416,   417,   417,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   418,   419,   420,   421,   421,   422,
     422,   422,   423,   423,   424,   424,   425,   426,   426,   426,
     427,   427,   427,   427,   427,   427,   427,   428,   429,   430,
     430,   431,   431,   431,   432,   433,   433,   433,   434,   434,
     434,   434,   434,   434,   434,   434,   434,   434,   434,   434,
     435,   436,   437,   438,   438,   439,   439,   439,   439,   440,
     440,   441,   441,   441,   442,   442,   442,   443,   443,   443,
     444,   445,   446,   446,   447,   447,   447,   447,   447,   447,
     448,   449,   449,   450,   450,   451,   451,   452,   452,   452,
     452,   452,   452,   452,   453,   453,   454,   454,   455,   456,
     456,   457,   457,   458,   458,   459,   460,   460,   461,   462,
     462,   463,   464,   464,   465,   466,   466,   467,   467,   468,
     468,   469,   469,   470,   470,   471,   471,   472,   472,   473,
     474,   474,   475,   475,   476,   476,   476,   476,   476,   477,
     476,   476,   476,   476,   478,   478,   479,   479,   480,   480,
     481,   481,   482,   482,   482,   483,   483,   483,   483,   483,
     484,   484,   484,   485,   485,   485,   486,   486,   487,   487,
     488,   488,   489,   489,   490,   490,   491,   491,   492,   492,
     492,   492,   493,   493,   493,   494,   494,   495,   495,   495,
     495,   495,   495,   496,   496,   496,   497,   497,   497,   497,
     498,   499,   499,   500,   500,   500,   501,   501,   501,   501,
     502,   503,   503,   503,   504,   504,   505,   505,   505,   505,
     506,   506,   507,   507,   507,   507,   507,   507,   507,   508,
     508,   509,   509,   510,   510,   510,   510,   510,   511,   511,
     512,   512,   513,   513,   513,   513,   514,   514,   514,   514,
     515,   515,   516,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   518,   518,   519,
     519,   519,   520,   521,   521,   522,   523,   524,   525,   525,
     526,   526,   526,   526,   527,   527,   528,   529,   530,   530,
     531,   531,   531,   532,   532,   532,   532,   532,   532,   533,
     533,   534,   534,   535,   536,   536,   537,   537,   538,   538,
     539,   539,   539,   539,   540,   540,   541,   541,   541,   541,
     542,   542,   543,   543,   544,   544,   544,   544,   545,   545,
     545,   545,   546,   546,   547,   547,   548,   549,   549,   549,
     549,   549,   549,   549,   550,   551,   551,   552,   552,   553,
     554,   555,   555,   556,   556,   557,   558,   558,   558,   559,
     559,   559,   560,   560,   560,   560,   560,   560,   560,   561,
     561,   562,   563,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   565,   566,   567,   567,   567,   568,   569,
     570,   571,   571,   571,   572,   572,   572,   572,   572,   573,
     574,   574,   574,   574,   574,   574,   574,   575,   576,   577,
     578,   579,   579,   580,   581,   581,   582,   583,   583,   583,
     584,   584,   584,   584,   584,   584,   584,   584,   584,   584,
     585,   585,   586,   586,   587,   588,   589,   589,   590,   591,
     592,   592,   593,   594,   595,   595,   596,   597,   597,   598,
     598,   599,   599,   600,   600,   601,   601,   602,   602,   603,
     604,   604,   605,   605,   606,   607,   607,   607,   608,   608,
     609,   610,   610,   611,   612,   612,   613,   613,   614,   614,
     614,   615,   615,   616,   616,   617,   617,   617,   617,   617,
     618,   619,   620,   621,   621,   621,   622,   622,   623,   623,
     623,   623,   623,   623,   623,   623,   624,   624,   624,   624,
     625,   625,   626,   627,   627,   628,   628,   628,   629,   629,
     630,   630,   631,   631,   632,   633,   633,   634,   634,   635,
     635,   635,   636,   636,   637,   637,   638,   638,   639,   639,
     640,   640,   641,   642,   642,   643,   643,   643,   644,   645,
     645,   645,   645,   646,   646,   647,   647,   648,   649,   649,
     650,   650,   651,   651,   652,   653,   653,   654,   654,   654,
     655,   656,   657,   658,   659,   659,   659,   660,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   663
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
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     2,     3,     2,     3,     2,     3,     4,     5,     5,
       2,     4,     5,     3,     3,     2,     2,     8,     3,     1,
       2,     3,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     3,     3,     2,     1,     1,     4,     3,     3,     5,
       4,     6,     4,     6,     5,     7,     4,     5,     5,     6,
       3,     3,     2,     1,     3,     4,     5,     3,     6,     4,
       5,     1,     2,     3,     1,     2,     1,     6,     3,     3,
       2,     3,     1,     3,     4,     5,     6,     5,     1,     2,
       2,     3,     4,     1,     3,     1,     2,     1,     1,     1,
       2,     2,     2,     3,     1,     1,     2,     2,     2,     5,
       5,     1,     4,     3,     4,     8,     1,     2,     3,     2,
       3,     8,     1,     2,     3,     8,    10,     8,    10,     1,
       2,     4,     7,     1,     2,     4,     7,     1,     3,     8,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     1,     5,     1,     3,     0,     1,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     4,     1,     4,
       1,     4,     1,     4,     1,     2,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     5,     6,
       4,     1,     2,     3,     2,     2,     1,     2,     2,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     4,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     1,     4,     4,     3,     4,
       1,     3,     1,     3,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     4,     8,     5,     9,     9,    10,     1,
       2,     1,     2,     6,     0,     1,     3,     3,     0,     1,
       1,     1,     2,     2,     0,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     7,     3,     7,     4,
       4,     3,     7,     3,     7,     2,     1,     2,     3,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     4,     4,     3,     3,
       3,     3,     4,     4,     3,     4,     6,     4,     6,     4,
       3,     4,     6,     6,     4,     6,     6,     4,     1,     2,
       1,     1,     1,     4,     5,     6,     3,     3,     3,     3,
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
       5,     3,     5,     7,     3,     3,     3,     1,     1,     1,
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
       1,     1,     1,     1,     1
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
  "\"'processing-instruction NCName {'\"", "\"'namespace NCName {'\"",
  "\"'QName'\"", "\"'EQName'\"", "\"'%QName'\"", "\"'%EQName'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'XML comment'\"",
  "\"'URI'\"", "\"'declare'\"", "\"'module'\"", "\"'<blank>'\"",
  "\"'allowing'\"", "\"'base-uri'\"", "\"'boundary-space'\"",
  "\"'comment'\"", "\"'construction'\"", "\"'copy-namespaces'\"",
  "\"'count'\"", "\"'document'\"", "\"'document-node'\"", "\"'element'\"",
  "\"'for'\"", "\"'function'\"", "\"'if'\"", "\"'import'\"",
  "\"'instance'\"", "\"'let'\"", "\"'most'\"", "\"'namespace-node'\"",
  "\"'next'\"", "\"'no'\"", "\"'only'\"", "\"'option'\"", "\"'ordering'\"",
  "\"'previous'\"", "\"'processing-instruction'\"", "\"'schema'\"",
  "\"'schema-attribute'\"", "\"'schema-element'\"", "\"'sequential'\"",
  "\"'set'\"", "\"'simple'\"", "\"'sliding'\"", "\"'some'\"",
  "\"'space'\"", "\"'stable'\"", "\"'text'\"", "\"'tumbling'\"",
  "\"'switch'\"", "\"'typeswitch'\"", "\"'updating'\"", "\"'validate'\"",
  "\"'type'\"", "\"'when'\"", "\"'word'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor'\"", "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"",
  "\"'||'\"", "\"'case'\"", "\"'castable'\"", "\"'cast'\"",
  "\"'CDATA[['\"", "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"",
  "\"'(:'\"", "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"",
  "\"'variable'\"", "\"'default'\"", "\"'descendant'\"",
  "\"'descendant-or-self'\"", "\"'descending'\"", "\"'div'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"",
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
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'offset'\"", "\"'limit'\"",
  "\"'return'\"", "\"')'\"", "\"'satisfies'\"", "\"'self'\"", "\"';'\"",
  "\"'/'\"", "\"'//'\"", "\"'!'\"", "\"'*'\"", "\"'</ (start tag end)'\"",
  "\"'strip'\"", "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"",
  "\"'treat'\"", "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"",
  "\"'|'\"", "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"",
  "\"'-->'\"", "\"'xquery'\"", "\"'version'\"", "\"'start'\"",
  "\"'after'\"", "\"'before'\"", "\"'revalidation'\"", "\"'strict'\"",
  "\"'lax'\"", "\"'skip'\"", "\"'delete'\"", "\"'node'\"", "\"'insert'\"",
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
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "UNARY_PREC",
  "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE", "MULTIPLICATIVE_REDUCE", "SELECT",
  "$accept", "Module", "ERROR", "ModuleWithoutBOM", "VersionDecl",
  "MainModule", "LibraryModule", "ModuleDecl", "SIND_DeclList",
  "SIND_Decl", "Setter", "BoundarySpaceDecl", "DefaultCollationDecl",
  "BaseURIDecl", "ConstructionDecl", "OrderingModeDecl", "EmptyOrderDecl",
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
  "FLWORExpr", "ReturnExpr", "ReturnOrSelect", "WindowType",
  "FLWORWinCondType", "FLWORWinCond", "WindowClause", "CountClause",
  "ForLetWinClause", "FLWORClause", "OffsetClause", "LimitClause",
  "FLWORClauseList", "ForClause", "ForOrFrom", "VarInDeclList",
  "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
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
  "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr", "AxisStep",
  "ForwardStep", "ForwardAxis", "AbbrevForwardStep", "ReverseStep",
  "ReverseAxis", "NodeTest", "NameTest", "Wildcard", "PostfixExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "VarRef", "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr",
  "UnorderedExpr", "FunctionCall", "ArgList", "FunctionItemExpr",
  "LiteralFunctionItem", "InlineFunction", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
  "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor",
  "CompNamespaceConstructor", "TypeDeclaration", "SequenceType",
  "OccurrenceIndicator", "ItemType", "TypeList", "GeneralizedAtomicType",
  "SimpleType", "KindTest", "AnyKindTest", "NODE_KIND_TEST",
  "DocumentTest", "NamespaceTest", "TextTest", "CommentTest", "PITest",
  "AttributeTest", "SchemaAttributeTest", "ElementTest",
  "SchemaElementTest", "TypeName", "TypeName_WITH_HOOK", "StringLiteral",
  "FunctionTest", "AnyFunctionTest", "TypedFunctionTest",
  "ParenthesizedItemType", "RevalidationDecl", "InsertExpr", "DeleteExpr",
  "ReplaceExpr", "RenameExpr", "TransformExpr", "VarNameList",
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "BracedExpr",
  "NameTestList", "FTSelection", "opt_FTPosFilter_list",
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
  "JSONTest", "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       337,     0,    -1,   339,    -1,   323,   339,    -1,   324,   339,
      -1,   323,   324,   339,    -1,     1,    -1,     1,     3,    -1,
     338,     1,    -1,   341,    -1,   340,   341,    -1,   342,    -1,
     340,   342,    -1,   217,   218,    30,   192,    -1,   217,   218,
      30,   132,    30,   192,    -1,   344,   192,   391,    -1,   361,
     192,   391,    -1,   344,   192,   361,   192,   391,    -1,   391,
      -1,   344,   338,   391,    -1,   361,   338,   391,    -1,   344,
     192,   361,   338,   391,    -1,   344,   338,   361,   192,   391,
      -1,   343,    -1,   343,   344,   192,    -1,   343,   361,   192,
      -1,   343,   344,   192,   361,   192,    -1,    34,   161,   661,
     133,   660,   192,    -1,   345,    -1,   344,   192,   345,    -1,
     344,   338,   345,    -1,   346,    -1,   354,    -1,   359,    -1,
     360,    -1,   368,    -1,   347,    -1,   348,    -1,   349,    -1,
     350,    -1,   351,    -1,   352,    -1,   353,    -1,   583,    -1,
      33,    38,   182,    -1,    33,    38,   198,    -1,    33,   114,
     107,   660,    -1,    33,    37,   660,    -1,    33,    40,   182,
      -1,    33,    40,   198,    -1,    33,    58,   169,    -1,    33,
      58,   204,    -1,    33,   114,   168,   128,   129,    -1,    33,
     114,   168,   128,   130,    -1,    33,    41,   182,   108,   149,
      -1,    33,    41,   182,   108,   165,    -1,    33,    41,   166,
     108,   149,    -1,    33,    41,   166,   108,   165,    -1,   355,
      -1,   358,    -1,    49,    25,     1,    -1,    49,    61,   660,
      -1,    49,    61,   357,   660,    -1,    49,    61,   660,    97,
     356,    -1,    49,    61,   357,   660,    97,   356,    -1,   660,
      -1,   356,   108,   660,    -1,   161,   661,   133,    -1,   114,
      45,   161,    -1,    49,    34,   660,    -1,    49,    34,   161,
     661,   133,   660,    -1,    49,    34,   660,    97,   356,    -1,
      49,    34,   161,   661,   133,   660,    97,   356,    -1,    33,
     161,   661,   133,   660,    -1,    33,   114,    45,   161,   660,
      -1,    33,   114,    47,   161,   660,    -1,   362,    -1,   361,
     192,   362,    -1,   361,   338,   362,    -1,   363,    -1,   367,
      -1,   369,    -1,   373,    -1,   378,    -1,   385,    -1,   387,
      -1,   390,    -1,    33,   114,    80,   364,    -1,    33,    80,
     661,   364,    -1,   365,    -1,   364,   365,    -1,   366,   133,
     578,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    33,    57,   661,    30,    -1,    33,   263,   622,
      -1,    33,   112,   153,   370,    -1,    95,   560,   371,    -1,
     371,    -1,   372,    -1,   138,    -1,   138,   372,    -1,   143,
     416,    -1,    33,   374,   143,   416,    -1,    33,   374,   138,
      -1,    33,   374,   138,   143,   416,    -1,   113,   119,   661,
      -1,   113,   119,   661,   557,    -1,   375,   113,   119,   661,
      -1,   375,   113,   119,   661,   557,    -1,   376,    -1,   375,
     376,    -1,    27,    -1,    27,   157,   377,   189,    -1,    28,
      -1,    28,   157,   377,   189,    -1,   518,    -1,   377,   108,
     518,    -1,    33,   379,    -1,    33,   375,   379,    -1,   380,
      -1,   381,    -1,    47,   662,   382,   399,    -1,    47,   662,
     382,   138,    -1,    75,    47,   662,   382,   399,    -1,    75,
      47,   662,   382,   138,    -1,   157,   189,    -1,   157,   383,
     189,    -1,   157,   189,    95,   558,    -1,   157,   383,   189,
      95,   558,    -1,   384,    -1,   383,   108,   384,    -1,   119,
     661,    -1,   119,   661,   557,    -1,    33,   289,   661,    -1,
      33,   289,   661,    95,   386,    -1,    33,   375,   289,   661,
      -1,    33,   375,   289,   661,    95,   386,    -1,   564,    -1,
     564,   559,    -1,   659,    -1,   659,   559,    -1,    33,   297,
     661,   301,   229,   501,   170,   388,    -1,    33,   375,   297,
     661,   301,   229,   501,   170,   388,    -1,   389,    -1,   388,
     108,   389,    -1,   501,    -1,   501,   557,    -1,   501,   455,
      -1,   501,   557,   455,    -1,    33,   305,   306,   661,   301,
     289,   661,   119,   661,   307,   416,    -1,    33,   305,   306,
     661,   301,   289,   661,   227,   119,   661,   307,   295,   308,
     501,    -1,    33,   305,   306,   661,   301,   289,   661,   309,
     227,   119,   661,   307,   416,    -1,    33,   305,   306,   661,
     310,   308,   259,   289,   661,   227,   119,   661,   308,   501,
     201,   289,   661,   227,   119,   661,   308,   501,    -1,   392,
      -1,   394,    -1,   395,    -1,    -1,   394,    -1,   395,    -1,
      -1,   415,    -1,   395,   415,    -1,   396,    -1,   395,   396,
      -1,   395,   415,   338,   396,    -1,   397,    -1,   400,    -1,
     403,    -1,   404,    -1,   405,    -1,   406,    -1,   407,    -1,
     408,    -1,   410,    -1,   467,    -1,   463,    -1,   411,    -1,
     414,    -1,   154,   395,   184,    -1,   154,   184,    -1,   154,
     393,   184,    -1,   154,   393,   184,    -1,   401,   192,    -1,
     401,   108,   402,    -1,   113,   402,    -1,   375,   113,   402,
      -1,   119,   661,    -1,   119,   661,   557,    -1,   119,   661,
     143,   416,    -1,   119,   661,   557,   143,   416,    -1,   119,
     661,   143,   416,   192,    -1,   417,   192,    -1,   242,   244,
     416,   192,    -1,   245,   157,   415,   189,   396,    -1,   240,
     243,   192,    -1,   241,   243,   192,    -1,   430,   409,    -1,
     420,   396,    -1,    48,   157,   415,   189,   200,   396,   127,
     396,    -1,   246,   397,   412,    -1,   413,    -1,   412,   413,
      -1,   247,   595,   397,    -1,   192,    -1,   416,    -1,   415,
     108,   416,    -1,   415,   338,   416,    -1,   418,    -1,   459,
      -1,   466,    -1,   473,    -1,   591,    -1,   417,    -1,   474,
      -1,   456,    -1,   584,    -1,   585,    -1,   587,    -1,   586,
      -1,   588,    -1,   656,    -1,   654,    -1,   657,    -1,   658,
      -1,   655,    -1,   430,   419,    -1,   420,   416,    -1,   188,
      -1,    67,   286,    -1,    72,   286,    -1,   219,    -1,   256,
      -1,    56,   256,    -1,   422,   441,    78,   416,    -1,   422,
      78,   416,    -1,   432,   421,   440,   423,   423,    -1,   432,
     421,   440,   423,    -1,    42,   119,   661,    -1,   431,    -1,
     437,    -1,   424,    -1,   426,    -1,   444,    -1,   449,    -1,
     445,    -1,   425,    -1,   428,    -1,   429,    -1,   186,   416,
      -1,   187,   416,    -1,   426,    -1,   430,   427,    -1,   432,
     119,   433,    -1,    46,     1,   433,    -1,   432,     3,    -1,
      46,    -1,   434,    -1,   433,   108,   119,   434,    -1,   433,
     108,   434,    -1,   661,   148,   416,    -1,   661,    36,   128,
     148,   416,    -1,   661,   557,   148,   416,    -1,   661,   557,
      36,   128,   148,   416,    -1,   661,   435,   148,   416,    -1,
     661,    36,   128,   435,   148,   416,    -1,   661,   557,   435,
     148,   416,    -1,   661,   557,    36,   128,   435,   148,   416,
      -1,   661,   436,   148,   416,    -1,   661,   557,   436,   148,
     416,    -1,   661,   435,   436,   148,   416,    -1,   661,   557,
     435,   436,   148,   416,    -1,    97,   119,   661,    -1,   275,
     119,   661,    -1,    51,   438,    -1,   439,    -1,   438,   108,
     439,    -1,   119,   661,   143,   416,    -1,   119,   661,   557,
     143,   416,    -1,   436,   143,   416,    -1,   119,   661,   557,
     436,   143,   416,    -1,   119,   661,   148,   416,    -1,   119,
     661,   557,   148,   416,    -1,   442,    -1,   119,   661,    -1,
     119,   661,   442,    -1,   435,    -1,   435,   443,    -1,   443,
      -1,    59,   119,   661,    54,   119,   661,    -1,    54,   119,
     661,    -1,    59,   119,   661,    -1,   214,   416,    -1,   171,
     170,   446,    -1,   447,    -1,   446,   108,   447,    -1,   119,
     661,   143,   416,    -1,   119,   661,   557,   143,   416,    -1,
     119,   661,   557,   143,   416,   448,    -1,   119,   661,   143,
     416,   448,    -1,   416,    -1,   416,   448,    -1,   107,   660,
      -1,   168,   170,   450,    -1,    70,   168,   170,   450,    -1,
     451,    -1,   450,   108,   451,    -1,   416,    -1,   416,   452,
      -1,   453,    -1,   454,    -1,   455,    -1,   453,   454,    -1,
     453,   455,    -1,   454,   455,    -1,   453,   454,   455,    -1,
      96,    -1,   117,    -1,   128,   129,    -1,   128,   130,    -1,
     107,   660,    -1,    68,   119,   457,   190,   416,    -1,   136,
     119,   457,   190,   416,    -1,   458,    -1,   457,   108,   119,
     458,    -1,   661,   148,   416,    -1,   661,   557,   148,   416,
      -1,    73,   157,   415,   189,   460,   114,   420,   416,    -1,
     461,    -1,   460,   461,    -1,   462,   420,   416,    -1,   101,
     416,    -1,   462,   101,   416,    -1,    73,   157,   415,   189,
     464,   114,   420,   396,    -1,   465,    -1,   464,   465,    -1,
     462,   420,   396,    -1,    74,   157,   415,   189,   468,   114,
     420,   416,    -1,    74,   157,   415,   189,   468,   114,   119,
     661,   420,   416,    -1,    74,   157,   415,   189,   470,   114,
     420,   396,    -1,    74,   157,   415,   189,   468,   114,   119,
     661,   420,   396,    -1,   469,    -1,   468,   469,    -1,   101,
     472,   420,   416,    -1,   101,   119,   661,    95,   472,   420,
     416,    -1,   471,    -1,   470,   471,    -1,   101,   472,   420,
     396,    -1,   101,   119,   661,    95,   472,   420,   396,    -1,
     558,    -1,   472,   212,   558,    -1,    48,   157,   415,   189,
     200,   416,   127,   416,    -1,   475,    -1,   474,   167,   475,
      -1,   476,    -1,   475,    93,   476,    -1,   478,    -1,   478,
     495,   478,    -1,   478,   496,   478,    -1,   478,   133,   478,
      -1,   478,   163,   478,    -1,    -1,   478,   158,   477,   478,
      -1,   478,   156,   478,    -1,   478,   144,   478,    -1,   478,
     142,   478,    -1,   479,    -1,   479,   251,    71,   596,   480,
      -1,   481,    -1,   481,   100,   479,    -1,    -1,   648,    -1,
     482,    -1,   482,   201,   482,    -1,   483,    -1,   482,   176,
     483,    -1,   482,   159,   483,    -1,   484,    -1,   483,   196,
     484,    -1,   483,   118,   484,    -1,   483,   147,   484,    -1,
     483,   160,   484,    -1,   485,    -1,   484,   203,   485,    -1,
     484,   212,   485,    -1,   486,    -1,   485,   151,   486,    -1,
     485,   137,   486,    -1,   487,    -1,   487,    50,   233,   558,
      -1,   488,    -1,   488,   202,    95,   558,    -1,   489,    -1,
     489,   102,    95,   490,    -1,   491,    -1,   491,   103,    95,
     490,    -1,   563,    -1,   563,   145,    -1,   493,    -1,   492,
     493,    -1,   176,    -1,   159,    -1,   492,   176,    -1,   492,
     159,    -1,   497,    -1,   494,    -1,   498,    -1,   501,    -1,
     494,   195,   501,    -1,   205,    -1,   210,    -1,   209,    -1,
     208,    -1,   207,    -1,   206,    -1,   152,    -1,   179,    -1,
     141,    -1,    76,   154,   394,   184,    -1,    76,   224,   154,
     394,   184,    -1,    76,   223,   154,   394,   184,    -1,    76,
      77,   576,   154,   394,   184,    -1,   499,   154,   393,   184,
      -1,   500,    -1,   499,   500,    -1,   177,   661,    17,    -1,
     177,    18,    -1,   177,    19,    -1,   502,    -1,   502,   503,
      -1,   194,   503,    -1,   503,    -1,   193,    -1,   504,    -1,
     504,   193,   503,    -1,   504,   194,   503,    -1,   505,    -1,
     514,    -1,   506,    -1,   506,   515,    -1,   509,    -1,   509,
     515,    -1,   507,   511,    -1,   508,    -1,   106,   123,    -1,
     115,   123,    -1,    98,   123,    -1,   191,   123,    -1,   116,
     123,    -1,   140,   123,    -1,   139,   123,    -1,   511,    -1,
      99,   511,    -1,   510,   511,    -1,   121,    -1,   172,   123,
      -1,    91,   123,    -1,   181,   123,    -1,   180,   123,    -1,
      92,   123,    -1,   564,    -1,   512,    -1,   661,    -1,   513,
      -1,   196,    -1,    11,    -1,    12,    -1,    20,    -1,   517,
      -1,   514,   515,    -1,   514,   157,   189,    -1,   514,   157,
     526,   189,    -1,   516,    -1,   515,   516,    -1,   155,   415,
     185,    -1,   518,    -1,   520,    -1,   521,    -1,   522,    -1,
     525,    -1,   530,    -1,   523,    -1,   524,    -1,   527,    -1,
     398,    -1,   652,    -1,   649,    -1,   650,    -1,   651,    -1,
     519,    -1,   578,    -1,   111,    -1,   150,    -1,   125,    -1,
     119,   661,    -1,   157,   189,    -1,   157,   415,   189,    -1,
     120,    -1,   169,   154,   415,   184,    -1,   204,   154,   415,
     184,    -1,   662,   157,   189,    -1,   662,   157,   526,   189,
      -1,   145,    -1,   526,   108,   145,    -1,   416,    -1,   526,
     108,   416,    -1,   528,    -1,   529,    -1,   662,   146,   150,
      -1,    47,   382,   399,    -1,   531,    -1,   549,    -1,   532,
      -1,   546,    -1,   547,    -1,   158,   661,   536,   131,    -1,
     158,   661,   536,   199,   197,   661,   536,   199,    -1,   158,
     661,   534,   536,   131,    -1,   158,   661,   534,   536,   199,
     197,   661,   536,   199,    -1,   158,   661,   536,   199,   533,
     197,   661,   536,   199,    -1,   158,   661,   534,   536,   199,
     533,   197,   661,   536,   199,    -1,   544,    -1,   533,   544,
      -1,   535,    -1,   534,   535,    -1,    35,   661,   536,   133,
     536,   537,    -1,    -1,    35,    -1,   183,   538,   183,    -1,
      94,   540,    94,    -1,    -1,   539,    -1,   135,    -1,   542,
      -1,   539,   135,    -1,   539,   542,    -1,    -1,   541,    -1,
     134,    -1,   543,    -1,   541,   134,    -1,   541,   543,    -1,
      29,    -1,   545,    -1,     5,    -1,   545,    -1,   531,    -1,
      10,    -1,   548,    -1,   545,    -1,     9,    -1,   124,    -1,
     126,    -1,   154,   394,   184,    -1,   215,    31,   216,    -1,
     215,   216,    -1,   174,   661,   175,    -1,   174,   661,     8,
      -1,   104,     7,    -1,   550,    -1,   551,    -1,   552,    -1,
     553,    -1,   554,    -1,   555,    -1,   556,    -1,    43,   154,
     394,   184,    -1,    21,   393,   184,    -1,    45,   154,   415,
     184,   154,   393,   184,    -1,    22,   393,   184,    -1,    98,
     154,   415,   184,   154,   393,   184,    -1,    71,   154,   394,
     184,    -1,    39,   154,   394,   184,    -1,    23,   393,   184,
      -1,    60,   154,   415,   184,   154,   393,   184,    -1,    24,
     394,   184,    -1,   161,   154,   415,   184,   154,   394,   184,
      -1,    95,   558,    -1,   560,    -1,   560,   559,    -1,   213,
     157,   189,    -1,   145,    -1,   196,    -1,   176,    -1,   562,
      -1,   564,    -1,   153,   157,   189,    -1,   322,   157,   189,
      -1,   579,    -1,   582,    -1,   659,    -1,   558,    -1,   561,
     108,   558,    -1,   661,    -1,   661,    -1,   567,    -1,   574,
      -1,   572,    -1,   575,    -1,   573,    -1,   571,    -1,   570,
      -1,   569,    -1,   568,    -1,   565,    -1,   566,   157,   189,
      -1,   227,    -1,    44,   157,   189,    -1,    44,   157,   574,
     189,    -1,    44,   157,   575,   189,    -1,    53,   157,   189,
      -1,    71,   157,   189,    -1,    39,   157,   189,    -1,    60,
     157,   189,    -1,    60,   157,   661,   189,    -1,    60,   157,
      30,   189,    -1,    98,   157,   189,    -1,    98,   157,   661,
     189,    -1,    98,   157,   661,   108,   576,   189,    -1,    98,
     157,   196,   189,    -1,    98,   157,   196,   108,   576,   189,
      -1,    62,   157,   661,   189,    -1,    45,   157,   189,    -1,
      45,   157,   661,   189,    -1,    45,   157,   661,   108,   576,
     189,    -1,    45,   157,   661,   108,   577,   189,    -1,    45,
     157,   196,   189,    -1,    45,   157,   196,   108,   576,   189,
      -1,    45,   157,   196,   108,   577,   189,    -1,    63,   157,
     661,   189,    -1,   661,    -1,   661,   145,    -1,    30,    -1,
     580,    -1,   581,    -1,    47,   157,   196,   189,    -1,    47,
     157,   189,    95,   558,    -1,    47,   157,   561,   189,    95,
     558,    -1,   157,   560,   189,    -1,    33,   222,   223,    -1,
      33,   222,   224,    -1,    33,   222,   225,    -1,   228,   227,
     416,   235,   416,    -1,   228,   227,   416,    95,   234,   235,
     416,    -1,   228,   227,   416,    95,   236,   235,   416,    -1,
     228,   227,   416,   220,   416,    -1,   228,   227,   416,   221,
     416,    -1,   228,   229,   416,   235,   416,    -1,   228,   229,
     416,    95,   234,   235,   416,    -1,   228,   229,   416,    95,
     236,   235,   416,    -1,   228,   229,   416,   220,   416,    -1,
     228,   229,   416,   221,   416,    -1,   226,   227,   416,    -1,
     226,   229,   416,    -1,   231,   227,   416,   239,   416,    -1,
     231,   232,   233,   227,   416,   239,   416,    -1,   230,   227,
     416,    95,   416,    -1,   238,   119,   589,   237,   416,   420,
     416,    -1,   590,    -1,   589,   108,   119,   590,    -1,   661,
     143,   416,    -1,   246,   154,   415,   184,   592,    -1,   593,
      -1,   592,   593,    -1,   247,   595,   594,    -1,   154,   415,
     184,    -1,   512,    -1,   595,   212,   512,    -1,   599,   597,
      -1,    -1,   598,    -1,   617,    -1,   598,   617,    -1,   600,
      -1,   599,   264,   600,    -1,   601,    -1,   600,   260,   601,
      -1,   602,    -1,   601,   262,   148,   602,    -1,   603,    -1,
     261,   603,    -1,   607,   604,   605,    -1,    -1,   622,    -1,
      -1,   606,    -1,   284,   154,   415,   184,    -1,   611,   608,
      -1,   157,   596,   189,    -1,   609,    -1,    -1,   644,    -1,
     499,   154,   610,   184,    -1,    -1,   596,    -1,   612,   613,
      -1,   518,    -1,   154,   415,   184,    -1,    -1,   614,    -1,
     250,   615,    -1,   249,   616,    -1,   272,    -1,    -1,    79,
      -1,    -1,   288,    -1,   618,    -1,   619,    -1,   620,    -1,
     646,    -1,   643,    -1,   169,    -1,   286,   482,   621,    -1,
     255,   645,   621,    -1,   288,    -1,   278,    -1,   271,    -1,
     248,   623,    -1,   622,   248,   623,    -1,   624,    -1,   625,
      -1,   626,    -1,   641,    -1,   627,    -1,   635,    -1,   628,
      -1,   642,    -1,   101,   276,    -1,   101,   265,    -1,   268,
      -1,   283,    -1,   253,   276,    -1,   253,   265,    -1,    57,
     661,    30,    -1,   279,    -1,    55,   279,    -1,   281,   629,
      -1,   281,   157,   629,   630,   189,    -1,    55,   281,    -1,
     632,    -1,   114,    -1,    -1,   108,   631,    -1,   632,    -1,
     631,   108,   632,    -1,    97,    30,   633,   634,    -1,    -1,
     273,    30,    -1,    -1,   645,   267,    -1,   280,   288,   636,
     638,    -1,   280,   288,   114,   638,    -1,    55,   280,   288,
      -1,    97,    30,    -1,   157,   637,   189,    -1,    30,    -1,
     637,   108,    30,    -1,    -1,   639,    -1,   640,    -1,   639,
     640,    -1,   203,   636,    -1,   137,   636,    -1,   266,    30,
      -1,   285,    -1,    55,   285,    -1,    97,   219,    -1,    97,
     256,    -1,   257,   252,    -1,   269,   645,   282,    -1,   258,
     482,    -1,    97,   130,   482,    -1,    97,    52,   482,    -1,
     259,   482,   201,   482,    -1,   274,   647,    -1,   254,   647,
      -1,   277,    -1,   270,    -1,   287,   252,   484,    -1,   155,
     185,    -1,   155,   415,   185,    -1,   312,   313,    -1,   312,
     415,   313,    -1,   314,   315,    -1,   314,   415,   315,    -1,
     154,   653,   184,    -1,   416,   122,   416,    -1,   653,   108,
     416,   122,   416,    -1,   228,   316,   416,   235,   416,    -1,
     228,   316,   653,   235,   416,    -1,   228,   316,   416,   235,
     416,    97,   318,   416,    -1,   317,   316,   416,   235,   416,
      -1,   226,   316,   514,    -1,   230,   316,   514,    95,   416,
      -1,   231,   232,   233,   316,   514,   239,   416,    -1,   321,
     157,   189,    -1,   320,   157,   189,    -1,   319,   157,   189,
      -1,    30,    -1,   662,    -1,    16,    -1,    98,    -1,    39,
      -1,    44,    -1,    53,    -1,    45,    -1,   153,    -1,    48,
      -1,   227,    -1,    60,    -1,    62,    -1,    63,    -1,    71,
      -1,    74,    -1,    73,    -1,   213,    -1,   245,    -1,   316,
      -1,   320,    -1,   319,    -1,   321,    -1,   322,    -1,   663,
      -1,    25,    -1,   217,    -1,   128,    -1,    38,    -1,   263,
      -1,    37,    -1,   224,    -1,   223,    -1,   147,    -1,    43,
      -1,   261,    -1,   262,    -1,   276,    -1,   265,    -1,   253,
      -1,   287,    -1,   279,    -1,   281,    -1,   280,    -1,   285,
      -1,   257,    -1,   252,    -1,    79,    -1,   219,    -1,   256,
      -1,    52,    -1,   225,    -1,   238,    -1,   304,    -1,   232,
      -1,   205,    -1,   210,    -1,   209,    -1,   208,    -1,   207,
      -1,   206,    -1,    97,    -1,   112,    -1,   113,    -1,   188,
      -1,    46,    -1,   259,    -1,    36,    -1,    67,    -1,    72,
      -1,    59,    -1,    54,    -1,    56,    -1,    78,    -1,    42,
      -1,   148,    -1,    51,    -1,   214,    -1,   186,    -1,   187,
      -1,   170,    -1,   171,    -1,   168,    -1,    70,    -1,    96,
      -1,   117,    -1,   129,    -1,   130,    -1,   107,    -1,    68,
      -1,   136,    -1,   190,    -1,   101,    -1,    95,    -1,   200,
      -1,   127,    -1,   167,    -1,    93,    -1,    50,    -1,   233,
      -1,   102,    -1,   201,    -1,   118,    -1,   160,    -1,   203,
      -1,   151,    -1,   137,    -1,    76,    -1,    77,    -1,   103,
      -1,   202,    -1,   152,    -1,   182,    -1,   198,    -1,   161,
      -1,   138,    -1,   132,    -1,   166,    -1,   149,    -1,   165,
      -1,    33,    -1,    40,    -1,    58,    -1,   114,    -1,    41,
      -1,    57,    -1,   218,    -1,    49,    -1,    61,    -1,    34,
      -1,    47,    -1,   275,    -1,   251,    -1,   284,    -1,   286,
      -1,   255,    -1,   269,    -1,   282,    -1,   274,    -1,   254,
      -1,   268,    -1,   283,    -1,   273,    -1,   267,    -1,   266,
      -1,   250,    -1,   249,    -1,   258,    -1,   288,    -1,   278,
      -1,   277,    -1,   272,    -1,   270,    -1,   271,    -1,   237,
      -1,   234,    -1,   317,    -1,   228,    -1,   231,    -1,   230,
      -1,   226,    -1,   221,    -1,   220,    -1,   222,    -1,   239,
      -1,   229,    -1,   236,    -1,   235,    -1,    66,    -1,    64,
      -1,    75,    -1,   169,    -1,   204,    -1,   244,    -1,   242,
      -1,   243,    -1,   240,    -1,   241,    -1,   246,    -1,   247,
      -1,   248,    -1,    65,    -1,   297,    -1,   295,    -1,   296,
      -1,   301,    -1,   302,    -1,   303,    -1,   298,    -1,   299,
      -1,   300,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,    90,    -1,   289,    -1,   290,    -1,   291,
      -1,   292,    -1,   293,    -1,   294,    -1,   305,    -1,   306,
      -1,   307,    -1,   308,    -1,   309,    -1,   310,    -1,   311,
      -1,    91,    -1,   106,    -1,   115,    -1,   172,    -1,   180,
      -1,   191,    -1,   139,    -1,    92,    -1,   116,    -1,   140,
      -1,   181,    -1,   318,    -1,    26,    -1
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
     688,   690,   692,   694,   696,   698,   700,   702,   706,   709,
     713,   717,   720,   724,   727,   731,   734,   738,   743,   749,
     755,   758,   763,   769,   773,   777,   780,   783,   792,   796,
     798,   801,   805,   807,   809,   813,   817,   819,   821,   823,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   851,   853,   856,   859,   861,   864,   867,
     869,   871,   874,   879,   883,   889,   894,   898,   900,   902,
     904,   906,   908,   910,   912,   914,   916,   918,   921,   924,
     926,   929,   933,   937,   940,   942,   944,   949,   953,   957,
     963,   968,   975,   980,   987,   993,  1001,  1006,  1012,  1018,
    1025,  1029,  1033,  1036,  1038,  1042,  1047,  1053,  1057,  1064,
    1069,  1075,  1077,  1080,  1084,  1086,  1089,  1091,  1098,  1102,
    1106,  1109,  1113,  1115,  1119,  1124,  1130,  1137,  1143,  1145,
    1148,  1151,  1155,  1160,  1162,  1166,  1168,  1171,  1173,  1175,
    1177,  1180,  1183,  1186,  1190,  1192,  1194,  1197,  1200,  1203,
    1209,  1215,  1217,  1222,  1226,  1231,  1240,  1242,  1245,  1249,
    1252,  1256,  1265,  1267,  1270,  1274,  1283,  1294,  1303,  1314,
    1316,  1319,  1324,  1332,  1334,  1337,  1342,  1350,  1352,  1356,
    1365,  1367,  1371,  1373,  1377,  1379,  1383,  1387,  1391,  1395,
    1396,  1401,  1405,  1409,  1413,  1415,  1421,  1423,  1427,  1428,
    1430,  1432,  1436,  1438,  1442,  1446,  1448,  1452,  1456,  1460,
    1464,  1466,  1470,  1474,  1476,  1480,  1484,  1486,  1491,  1493,
    1498,  1500,  1505,  1507,  1512,  1514,  1517,  1519,  1522,  1524,
    1526,  1529,  1532,  1534,  1536,  1538,  1540,  1544,  1546,  1548,
    1550,  1552,  1554,  1556,  1558,  1560,  1562,  1567,  1573,  1579,
    1586,  1591,  1593,  1596,  1600,  1603,  1606,  1608,  1611,  1614,
    1616,  1618,  1620,  1624,  1628,  1630,  1632,  1634,  1637,  1639,
    1642,  1645,  1647,  1650,  1653,  1656,  1659,  1662,  1665,  1668,
    1670,  1673,  1676,  1678,  1681,  1684,  1687,  1690,  1693,  1695,
    1697,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1714,  1718,
    1723,  1725,  1728,  1732,  1734,  1736,  1738,  1740,  1742,  1744,
    1746,  1748,  1750,  1752,  1754,  1756,  1758,  1760,  1762,  1764,
    1766,  1768,  1770,  1773,  1776,  1780,  1782,  1787,  1792,  1796,
    1801,  1803,  1807,  1809,  1813,  1815,  1817,  1821,  1825,  1827,
    1829,  1831,  1833,  1835,  1840,  1849,  1855,  1865,  1875,  1886,
    1888,  1891,  1893,  1896,  1903,  1904,  1906,  1910,  1914,  1915,
    1917,  1919,  1921,  1924,  1927,  1928,  1930,  1932,  1934,  1937,
    1940,  1942,  1944,  1946,  1948,  1950,  1952,  1954,  1956,  1958,
    1960,  1962,  1966,  1970,  1973,  1977,  1981,  1984,  1986,  1988,
    1990,  1992,  1994,  1996,  1998,  2003,  2007,  2015,  2019,  2027,
    2032,  2037,  2041,  2049,  2053,  2061,  2064,  2066,  2069,  2073,
    2075,  2077,  2079,  2081,  2083,  2087,  2091,  2093,  2095,  2097,
    2099,  2103,  2105,  2107,  2109,  2111,  2113,  2115,  2117,  2119,
    2121,  2123,  2125,  2127,  2131,  2133,  2137,  2142,  2147,  2151,
    2155,  2159,  2163,  2168,  2173,  2177,  2182,  2189,  2194,  2201,
    2206,  2210,  2215,  2222,  2229,  2234,  2241,  2248,  2253,  2255,
    2258,  2260,  2262,  2264,  2269,  2275,  2282,  2286,  2290,  2294,
    2298,  2304,  2312,  2320,  2326,  2332,  2338,  2346,  2354,  2360,
    2366,  2370,  2374,  2380,  2388,  2394,  2402,  2404,  2409,  2413,
    2419,  2421,  2424,  2428,  2432,  2434,  2438,  2441,  2442,  2444,
    2446,  2449,  2451,  2455,  2457,  2461,  2463,  2468,  2470,  2473,
    2477,  2478,  2480,  2481,  2483,  2488,  2491,  2495,  2497,  2498,
    2500,  2505,  2506,  2508,  2511,  2513,  2517,  2518,  2520,  2523,
    2526,  2528,  2529,  2531,  2532,  2534,  2536,  2538,  2540,  2542,
    2544,  2546,  2550,  2554,  2556,  2558,  2560,  2563,  2567,  2569,
    2571,  2573,  2575,  2577,  2579,  2581,  2583,  2586,  2589,  2591,
    2593,  2596,  2599,  2603,  2605,  2608,  2611,  2617,  2620,  2622,
    2624,  2625,  2628,  2630,  2634,  2639,  2640,  2643,  2644,  2647,
    2652,  2657,  2661,  2664,  2668,  2670,  2674,  2675,  2677,  2679,
    2682,  2685,  2688,  2691,  2693,  2696,  2699,  2702,  2705,  2709,
    2712,  2716,  2720,  2725,  2728,  2731,  2733,  2735,  2739,  2742,
    2746,  2749,  2753,  2756,  2760,  2764,  2768,  2774,  2780,  2786,
    2795,  2801,  2805,  2811,  2819,  2823,  2827,  2831,  2833,  2835,
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
    3257,  3259,  3261,  3263,  3265,  3267,  3269,  3271,  3273,  3275,
    3277,  3279,  3281,  3283,  3285
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1072,  1072,  1073,  1077,  1081,  1089,  1095,  1099,  1108,
    1114,  1122,  1128,  1140,  1145,  1153,  1160,  1167,  1176,  1183,
    1191,  1199,  1207,  1218,  1223,  1230,  1237,  1249,  1259,  1266,
    1273,  1285,  1286,  1287,  1288,  1289,  1294,  1295,  1296,  1297,
    1298,  1299,  1300,  1303,  1308,  1313,  1321,  1329,  1337,  1342,
    1350,  1355,  1363,  1368,  1376,  1381,  1386,  1391,  1399,  1401,
    1404,  1414,  1419,  1427,  1435,  1446,  1453,  1464,  1470,  1478,
    1485,  1492,  1501,  1515,  1524,  1531,  1541,  1548,  1555,  1566,
    1567,  1568,  1569,  1570,  1571,  1572,  1573,  1578,  1584,  1593,
    1600,  1610,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1634,  1653,  1661,  1669,  1676,  1684,  1691,  1696,
    1704,  1712,  1726,  1740,  1757,  1762,  1770,  1778,  1789,  1794,
    1803,  1808,  1815,  1820,  1830,  1835,  1844,  1850,  1863,  1864,
    1869,  1884,  1899,  1915,  1930,  1935,  1940,  1945,  1953,  1960,
    1971,  1976,  1986,  1995,  2004,  2013,  2025,  2029,  2035,  2039,
    2049,  2059,  2072,  2078,  2087,  2092,  2099,  2106,  2117,  2127,
    2137,  2147,  2165,  2185,  2189,  2194,  2201,  2205,  2210,  2217,
    2222,  2234,  2241,  2251,  2266,  2267,  2268,  2269,  2270,  2271,
    2272,  2274,  2275,  2276,  2277,  2278,  2279,  2284,  2291,  2302,
    2324,  2332,  2340,  2347,  2354,  2365,  2374,  2383,  2392,  2405,
    2413,  2421,  2429,  2444,  2449,  2457,  2471,  2488,  2513,  2521,
    2528,  2539,  2548,  2556,  2561,  2574,  2593,  2594,  2595,  2596,
    2597,  2598,  2603,  2604,  2607,  2608,  2609,  2610,  2611,  2614,
    2615,  2616,  2617,  2618,  2623,  2637,  2645,  2656,  2661,  2669,
    2674,  2679,  2687,  2696,  2708,  2718,  2731,  2739,  2740,  2741,
    2746,  2747,  2748,  2749,  2750,  2751,  2752,  2756,  2763,  2770,
    2777,  2787,  2792,  2800,  2810,  2822,  2829,  2837,  2849,  2859,
    2869,  2879,  2889,  2899,  2909,  2919,  2930,  2939,  2949,  2959,
    2975,  2984,  2993,  3001,  3007,  3019,  3027,  3037,  3045,  3057,
    3063,  3074,  3076,  3080,  3088,  3092,  3097,  3101,  3105,  3109,
    3119,  3127,  3134,  3140,  3150,  3154,  3162,  3170,  3178,  3186,
    3198,  3206,  3212,  3222,  3228,  3238,  3242,  3252,  3258,  3264,
    3270,  3279,  3288,  3297,  3310,  3314,  3322,  3328,  3338,  3346,
    3355,  3368,  3375,  3387,  3391,  3403,  3410,  3416,  3425,  3432,
    3438,  3449,  3456,  3462,  3471,  3480,  3487,  3498,  3505,  3517,
    3523,  3535,  3541,  3552,  3558,  3569,  3575,  3586,  3592,  3603,
    3612,  3616,  3627,  3637,  3646,  3650,  3660,  3667,  3676,  3686,
    3685,  3703,  3712,  3721,  3734,  3738,  3750,  3754,  3762,  3765,
    3772,  3776,  3785,  3789,  3793,  3801,  3805,  3811,  3817,  3823,
    3833,  3837,  3841,  3849,  3853,  3859,  3869,  3873,  3883,  3887,
    3897,  3901,  3911,  3915,  3925,  3929,  3938,  3942,  3950,  3954,
    3958,  3962,  3972,  3973,  3974,  3978,  3983,  3991,  3995,  3999,
    4003,  4007,  4011,  4019,  4023,  4027,  4035,  4039,  4043,  4047,
    4058,  4068,  4074,  4084,  4088,  4092,  4098,  4102,  4112,  4122,
    4151,  4160,  4170,  4174,  4183,  4184,  4190,  4196,  4204,  4210,
    4223,  4229,  4240,  4244,  4248,  4252,  4256,  4262,  4268,  4277,
    4281,  4290,  4294,  4306,  4310,  4314,  4320,  4324,  4339,  4340,
    4346,  4350,  4360,  4364,  4368,  4372,  4382,  4389,  4393,  4397,
    4405,  4411,  4422,  4430,  4431,  4432,  4433,  4434,  4435,  4436,
    4437,  4438,  4439,  4442,  4443,  4444,  4445,  4450,  4454,  4462,
    4469,  4476,  4487,  4495,  4499,  4509,  4519,  4527,  4533,  4537,
    4559,  4565,  4571,  4577,  4587,  4591,  4599,  4607,  4619,  4620,
    4625,  4626,  4627,  4632,  4640,  4657,  4665,  4682,  4701,  4725,
    4731,  4742,  4748,  4759,  4768,  4770,  4774,  4779,  4789,  4792,
    4799,  4805,  4811,  4818,  4830,  4833,  4840,  4846,  4852,  4859,
    4870,  4874,  4882,  4886,  4894,  4898,  4902,  4907,  4916,  4920,
    4924,  4928,  4936,  4941,  4949,  4955,  4964,  4972,  4977,  4982,
    4987,  4992,  4997,  5002,  5008,  5016,  5020,  5026,  5030,  5038,
    5046,  5054,  5058,  5066,  5070,  5078,  5086,  5090,  5094,  5100,
    5106,  5112,  5122,  5129,  5133,  5137,  5141,  5145,  5149,  5156,
    5162,  5172,  5180,  5188,  5192,  5196,  5200,  5204,  5208,  5212,
    5216,  5220,  5224,  5232,  5239,  5246,  5250,  5254,  5262,  5269,
    5277,  5285,  5289,  5294,  5302,  5306,  5312,  5318,  5322,  5332,
    5340,  5344,  5350,  5359,  5368,  5374,  5380,  5390,  5396,  5403,
    5409,  5415,  5419,  5427,  5435,  5439,  5450,  5456,  5462,  5468,
    5478,  5482,  5488,  5494,  5498,  5504,  5508,  5514,  5520,  5527,
    5537,  5542,  5550,  5556,  5566,  5572,  5581,  5587,  5600,  5606,
    5613,  5619,  5629,  5638,  5646,  5652,  5661,  5669,  5673,  5680,
    5685,  5693,  5697,  5704,  5708,  5715,  5719,  5726,  5730,  5739,
    5752,  5755,  5763,  5766,  5774,  5782,  5790,  5794,  5802,  5805,
    5813,  5825,  5828,  5836,  5848,  5854,  5864,  5867,  5875,  5879,
    5883,  5891,  5894,  5902,  5905,  5913,  5917,  5921,  5925,  5929,
    5937,  5945,  5957,  5969,  5973,  5977,  5985,  5991,  6001,  6005,
    6009,  6013,  6017,  6021,  6025,  6029,  6037,  6041,  6045,  6049,
    6057,  6063,  6073,  6083,  6087,  6095,  6105,  6116,  6123,  6127,
    6135,  6138,  6145,  6150,  6159,  6169,  6172,  6179,  6183,  6191,
    6200,  6207,  6217,  6221,  6228,  6234,  6244,  6247,  6254,  6259,
    6271,  6279,  6291,  6299,  6303,  6311,  6315,  6319,  6327,  6335,
    6339,  6343,  6347,  6355,  6363,  6375,  6379,  6387,  6393,  6397,
    6404,  6408,  6415,  6419,  6427,  6435,  6441,  6451,  6457,  6467,
    6474,  6481,  6499,  6524,  6544,  6548,  6552,  6565,  6570,  6571,
    6572,  6573,  6574,  6575,  6576,  6577,  6578,  6579,  6580,  6581,
    6582,  6583,  6584,  6585,  6586,  6587,  6588,  6589,  6590,  6591,
    6592,  6596,  6597,  6598,  6599,  6600,  6601,  6602,  6603,  6604,
    6605,  6606,  6607,  6608,  6609,  6610,  6611,  6612,  6613,  6614,
    6615,  6616,  6617,  6618,  6619,  6620,  6621,  6622,  6623,  6624,
    6625,  6626,  6627,  6628,  6629,  6630,  6631,  6632,  6633,  6634,
    6635,  6636,  6637,  6638,  6639,  6640,  6641,  6642,  6643,  6644,
    6645,  6646,  6647,  6648,  6649,  6650,  6651,  6652,  6653,  6654,
    6655,  6656,  6657,  6658,  6659,  6660,  6661,  6662,  6663,  6664,
    6665,  6666,  6667,  6668,  6669,  6670,  6671,  6672,  6673,  6674,
    6675,  6676,  6677,  6678,  6679,  6680,  6681,  6682,  6683,  6684,
    6685,  6686,  6687,  6688,  6689,  6690,  6691,  6692,  6693,  6694,
    6695,  6696,  6697,  6698,  6699,  6700,  6701,  6702,  6703,  6704,
    6705,  6706,  6707,  6708,  6709,  6710,  6711,  6712,  6713,  6714,
    6715,  6716,  6717,  6718,  6719,  6720,  6721,  6722,  6723,  6724,
    6725,  6726,  6727,  6728,  6729,  6730,  6731,  6732,  6733,  6734,
    6735,  6736,  6737,  6738,  6739,  6740,  6741,  6742,  6743,  6744,
    6745,  6746,  6747,  6748,  6749,  6750,  6751,  6752,  6753,  6754,
    6755,  6756,  6757,  6758,  6759,  6760,  6761,  6762,  6763,  6764,
    6765,  6766,  6767,  6768,  6769,  6770,  6771,  6772,  6773,  6774,
    6775,  6776,  6777,  6778,  6779,  6780,  6781,  6782,  6783,  6784,
    6785,  6786,  6787,  6788,  6789,  6790,  6791,  6792,  6793,  6794,
    6795,  6796,  6797,  6798,  6810
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
  const int xquery_parser::yylast_ = 17240;
  const int xquery_parser::yynnts_ = 328;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 615;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 336;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 590;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba
/* Line 1106 of lalr1.cc  */
#line 16261 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.cpp"
/* Line 1107 of lalr1.cc  */
#line 6814 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"


namespace zorba {

static bool contains(const zstring& msg, const char* str1, const char* str2)
{
  zstring::size_type pos = msg.find(str1);

  if (pos == zstring::npos)
    return false;

  if (zstring(str2).size() == 0)
    return true;

  pos = msg.find(str2, pos);
  if (pos == zstring::npos)
    return false;

  return true;
}






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



      if ((msg.find("unexpected expression") != string::npos &&
            ! contains(prevErr->msg, "expecting", ","))
          ||
          (msg.find("missing semicolon \";\" after") != string::npos &&
            ! contains(prevErr->msg, "expecting", ";")))
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
