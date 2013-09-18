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
#line 1 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"

#define JSONIQ_PARSER
/* Line 278 of lalr1.cc  */
#line 58 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"


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
#line 101 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"


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
#line 98 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */
/* Line 284 of lalr1.cc  */
#line 904 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"



template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}
/* Line 284 of lalr1.cc  */
#line 1042 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"

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


  else if (lObjectLookup != NULL)
  {
    *aTargetExpr = lObjectLookup->get_object_expr();
    lObjectLookup->release_object_expr();
    *aSelectorExpr = lObjectLookup->get_selector_expr();
    lObjectLookup->release_selector_expr();
    return true;
  }

  else if (!allowArray && lFilterExpr != NULL)
  {
    *anError = "An object lookup is expected.";
    return false;
  }
  else if (allowArray && lFilterExpr != NULL)
  {
    rchandle<exprnode> lPrimary = lFilterExpr->get_primary();
    rchandle<PredicateList> lPredicateList = lFilterExpr->get_pred_list();
    ulong lSize = lPredicateList->size();


    if (lSize < 1)
    {
      *anError = "An object or array lookup with exactly one argument is expected. No argument was found.";
      return false;
    }
    rchandle<JSONArrayConstructor> lConstructor =
        dynamic_cast<JSONArrayConstructor*>(lPredicateList->operator[](lSize - 1).getp());
    if (lConstructor == NULL)
    {
      *anError = "An object or array lookup is expected.";
      return false;
    }
    *aSelectorExpr = lConstructor->get_expr();
    if (aSelectorExpr == NULL)
    {
      *anError = "An object or array lookup with exactly one argument is expected. No argument was found.";
      return false;
    }
    lConstructor->set_expr(NULL);


    *aTargetExpr = lPrimary;
    if (lSize > 1)
    {
      rchandle<PredicateList> lNewPredicateList =
          new PredicateList(lPredicateList->get_location());
      for (int i = 0; i < lSize - 1; ++i)
      {
        lNewPredicateList->push_back(lPredicateList->operator[](i));
      }
      *aTargetExpr = new FilterExpr(
          lFilterExpr->get_location(),
          lPrimary,
          lNewPredicateList);
    }
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
#line 212 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"


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
#line 307 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"

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

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 111: /* "'DECIMAL'" */
/* Line 453 of lalr1.cc  */
#line 902 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).decval); };
/* Line 453 of lalr1.cc  */
#line 413 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "'DOUBLE'" */
/* Line 453 of lalr1.cc  */
#line 901 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).dval); };
/* Line 453 of lalr1.cc  */
#line 420 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "'INTEGER'" */
/* Line 453 of lalr1.cc  */
#line 900 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).ival); };
/* Line 453 of lalr1.cc  */
#line 427 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 344: /* VersionDecl */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 434 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* MainModule */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 441 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* LibraryModule */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 448 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* ModuleDecl */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 455 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* SIND_DeclList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 462 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* SIND_Decl */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 469 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* Setter */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 476 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* BoundarySpaceDecl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 483 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* DefaultCollationDecl */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 490 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* BaseURIDecl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 497 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* ConstructionDecl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 504 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* OrderingModeDecl */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 511 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* EmptyOrderDecl */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 518 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* CopyNamespacesDecl */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 525 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* Import */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 532 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* SchemaImport */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 539 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* URILiteralList */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 546 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* SchemaPrefix */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 553 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* ModuleImport */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 560 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* NamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 567 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* DefaultNamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 574 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* VFO_DeclList */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 581 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* VFO_Decl */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 588 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* DecimalFormatDecl */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 595 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* DecimalFormatParamList */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).vstrpair); };
/* Line 453 of lalr1.cc  */
#line 602 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* DecimalFormatParam */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).strpair); };
/* Line 453 of lalr1.cc  */
#line 609 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* OptionDecl */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 616 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* FTOptionDecl */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 623 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* CtxItemDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 630 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* CtxItemDecl2 */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 637 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* CtxItemDecl3 */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 644 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* CtxItemDecl4 */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 651 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* VarDecl */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 658 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* VarNameAndType */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).varnametype); };
/* Line 453 of lalr1.cc  */
#line 665 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* AnnotationList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 672 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* Annotation */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 679 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* AnnotationLiteralList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 686 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* FunctionDecl */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 693 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* FunctionDecl2 */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 700 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* FunctionDeclSimple */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 707 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* FunctionDeclUpdating */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 714 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* FunctionSig */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).fnsig); };
/* Line 453 of lalr1.cc  */
#line 721 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* ParamList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 728 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* Param */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 735 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* CollectionDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 742 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* IndexDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 749 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* IndexKeyList */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 756 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* IndexKeySpec */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 763 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* IntegrityConstraintDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 770 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* QueryBody */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 777 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* StatementsAndOptionalExprTop */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 784 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* StatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 791 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* StatementsAndExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 798 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* Statements */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 805 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* Statement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 812 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* BlockStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 819 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* BlockExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 826 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* EnclosedStatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 833 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* VarDeclStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 840 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 407: /* AssignStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 847 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* ApplyStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 854 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* ExitStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 861 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* WhileStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 868 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* FlowCtlStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 875 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* FLWORStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 882 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* ReturnStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 889 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* IfStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 896 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* TryStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 903 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* CatchListStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 910 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* CatchStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* VoidStatement */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* Expr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* ExprSingle */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 938 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* ExprSimple */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* FLWORExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 952 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* ReturnExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 959 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* FLWORWinCond */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 966 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* WindowClause */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 973 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* CountClause */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 980 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* ForLetWinClause */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 987 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* FLWORClauseList */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 994 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* ForClause */
/* Line 453 of lalr1.cc  */
#line 923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1001 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* VarInDeclList */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1008 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* VarInDecl */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1015 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* PositionalVar */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1022 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* FTScoreVar */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1029 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* LetClause */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1036 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* VarGetsDeclList */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1043 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* VarGetsDecl */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1050 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* WindowVarDecl */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1057 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* WindowVars */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1064 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* WindowVars3 */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1071 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* WindowVars2 */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1078 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* WhereClause */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1085 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* GroupByClause */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1092 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* GroupSpecList */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1099 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* GroupSpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1106 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* GroupCollationSpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1113 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* OrderByClause */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1120 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* OrderSpecList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1127 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* OrderSpec */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1134 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* OrderModifier */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1141 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* OrderDirSpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1148 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* OrderEmptySpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1155 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* OrderCollationSpec */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1162 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* QuantifiedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1169 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* QVarInDeclList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1176 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* QVarInDecl */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1183 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* SwitchExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1190 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* SwitchCaseClauseList */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1197 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* SwitchCaseClause */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1204 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* SwitchCaseOperandList */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1211 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* SwitchStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1218 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* TypeswitchExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1225 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* TypeswitchStatement */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1232 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* CaseClauseList */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1239 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* CaseClause */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1246 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* SequenceTypeList */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1253 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* IfExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1260 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* OrExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1267 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* AndExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1274 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* NotExpr */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1281 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* ComparisonExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1288 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* FTContainsExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1295 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* StringConcatExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1302 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* opt_FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1309 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* RangeExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1316 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* AdditiveExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1323 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* MultiplicativeExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1330 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* UnionExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1337 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* IntersectExceptExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1344 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* InstanceofExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1351 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* TreatExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1358 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* CastableExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1365 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* CastExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1372 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* SingleType */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1379 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* UnaryExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1386 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* SignList */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1393 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* ValueExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1400 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* SimpleMapExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1407 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* ValueComp */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1414 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* NodeComp */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1421 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* ValidateExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1428 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* ExtensionExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1435 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* Pragma_list */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1442 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* Pragma */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1449 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* PathExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1456 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* RelativePathExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1463 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* StepExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1470 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* AxisStep */
/* Line 453 of lalr1.cc  */
#line 945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1477 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* ForwardStep */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1484 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* ForwardAxis */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1491 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* AbbrevForwardStep */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1498 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* ReverseStep */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1505 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* ReverseAxis */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1512 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* NodeTest */
/* Line 453 of lalr1.cc  */
#line 917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1519 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* NameTest */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1526 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* Wildcard */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1533 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* PostfixExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1540 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* PredicateList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1547 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* Predicate */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1554 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* PrimaryExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1561 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* Literal */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1568 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* NumericLiteral */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1575 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 523: /* VarRef */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1582 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* ParenthesizedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1589 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* ContextItemExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1596 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* OrderedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1603 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* UnorderedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1610 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* FunctionCall */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1617 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* ArgList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1624 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* Constructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1631 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* DirectConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1638 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* DirElemConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1645 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* DirElemContentList */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1652 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* DirAttributeList */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1659 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* DirAttr */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1666 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* DirAttributeValue */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1673 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* opt_QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1680 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1687 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* opt_AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1694 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1701 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* QuoteAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1708 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* AposAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1715 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* DirElemContent */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1722 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* CommonContent */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1729 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* DirCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1736 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* DirPIConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1743 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* CDataSection */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1750 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* ComputedConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1757 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* CompDocConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1764 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* CompElemConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1771 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* CompAttrConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1778 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* CompTextConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1785 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* CompCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1792 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* CompPIConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1799 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* CompNamespaceConstructor */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1806 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* TypeDeclaration */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1813 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* SequenceType */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1820 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* OccurrenceIndicator */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1827 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* ItemType */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1834 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* TypeList */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1841 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* GeneralizedAtomicType */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1848 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* SimpleType */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1855 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* KindTest */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1862 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* AnyKindTest */
/* Line 453 of lalr1.cc  */
#line 920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1869 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* DocumentTest */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1876 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* NamespaceTest */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1883 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* TextTest */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1890 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* CommentTest */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1897 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* PITest */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1904 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* AttributeTest */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1911 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* SchemaAttributeTest */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1918 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* ElementTest */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* SchemaElementTest */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* TypeName */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* TypeName_WITH_HOOK */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1946 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* StringLiteral */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1953 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* AnyFunctionTest */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1960 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* TypedFunctionTest */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1967 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* InsertExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1974 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* DeleteExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1981 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* ReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1988 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* RenameExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1995 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* TransformExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2002 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* VarNameList */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2009 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* VarNameDecl */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2016 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* TryExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2023 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* CatchListExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2030 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* CatchExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2037 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* BracedExpr */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2044 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* NameTestList */
/* Line 453 of lalr1.cc  */
#line 951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).name_test_list); };
/* Line 453 of lalr1.cc  */
#line 2051 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* FTSelection */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2058 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* FTOr */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2065 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* FTAnd */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2072 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* FTMildNot */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2079 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* FTUnaryNot */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2086 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* FTPrimaryWithOptions */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2093 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* opt_FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2100 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* FTWeight */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2107 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* FTPrimary */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2114 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* opt_FTTimes */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2121 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* FTExtensionSelection */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2128 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* FTWords */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2135 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* FTWordsValue */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2142 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* FTAnyallOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2149 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* FTPosFilter */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2156 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* FTOrder */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2163 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* FTWindow */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2170 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 623: /* FTDistance */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2177 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 624: /* FTUnit */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2184 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 625: /* FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2191 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* FTMatchOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2198 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* FTCaseOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2205 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* FTDiacriticsOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2212 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* FTExtensionOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2219 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* FTStemOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2226 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 631: /* FTThesaurusOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2233 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* FTThesaurusID */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2240 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* FTStopWordOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2247 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* FTStopWords */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2254 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* FTStopWordsInclExcl */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2261 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* FTLanguageOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2268 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* FTWildCardOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2275 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* FTContent */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2282 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* FTTimes */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2289 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* FTRange */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2296 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* FTScope */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2303 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* FTBigUnit */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2310 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2317 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* JSONArrayConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2324 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* JSONSimpleObjectUnion */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2331 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 654: /* JSONAccumulatorObjectUnion */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2338 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 655: /* JSONObjectConstructor */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2345 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 656: /* JSONPairList */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2352 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 657: /* JSONInsertExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2359 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* JSONAppendExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2366 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* JSONDeleteExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2373 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* JSONRenameExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2380 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* JSONReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2387 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 664: /* QNAME */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2394 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 665: /* FUNCTION_NAME */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2401 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 666: /* EQNAME */
/* Line 453 of lalr1.cc  */
#line 948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2408 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
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
/* Line 538 of lalr1.cc  */
#line 140 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}
/* Line 538 of lalr1.cc  */
#line 2503 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"

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
#line 1149 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:
/* Line 661 of lalr1.cc  */
#line 1153 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 1157 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 1165 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 1171 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 1175 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 1184 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 1190 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 1198 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 1204 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 1215 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 1220 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 1229 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 1236 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 1243 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 1252 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 1259 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 1267 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 1275 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 1283 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 1294 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 1299 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 1306 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 1313 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 1325 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 1335 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 1342 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 1349 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 1384 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 1389 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 1397 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 1405 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 1413 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 1418 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 1426 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 1431 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 1439 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 1444 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 1452 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 1457 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 1462 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 1467 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 1480 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\"");
      YYERROR;
    }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 1490 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 1495 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 1503 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 1511 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 1522 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 1529 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:
/* Line 661 of lalr1.cc  */
#line 1540 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 68:
/* Line 661 of lalr1.cc  */
#line 1546 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 1554 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 1561 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:
/* Line 661 of lalr1.cc  */
#line 1568 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 1577 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 1591 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 1600 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 1607 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 1617 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 1624 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:
/* Line 661 of lalr1.cc  */
#line 1631 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 1654 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 1660 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 1669 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 1676 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 1686 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 1695 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 1696 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 1697 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 1698 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 1699 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 1700 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 1701 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 1702 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 1703 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 1704 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 1710 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 1729 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 1737 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 1745 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 1752 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 1760 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 1767 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 1772 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 1780 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 1788 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 1802 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 1816 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 1833 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 1838 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 1846 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 1854 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 1865 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 1870 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 1879 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 1884 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 1891 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 1896 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 1906 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 1911 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 1920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 1926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 1945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 1960 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 1975 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 1991 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2006 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 2011 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 2016 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 2021 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 2029 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 2036 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 2047 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 2052 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 2062 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2071 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 2080 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2089 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 2101 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 2105 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 2111 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 2115 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 2125 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2135 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2148 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 2154 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 2163 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 2168 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 2175 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 2182 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 2194 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2204 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2214 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2225 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2241 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2261 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 2265 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 2269 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 2277 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 2281 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 2285 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 2293 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 2298 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 2310 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 2317 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 2327 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 187:
/* Line 661 of lalr1.cc  */
#line 2360 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 2368 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));


      if ((yysemantic_stack_[(3) - (2)].expr) == NULL || (block != NULL && block->isEmpty()))
      {

        driver.addCommonLanguageWarning((yylocation_stack_[(3) - (1)]), ZED(ZWST0009_EMPTY_OBJECT));
        (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)));
      }
      else

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

  case 189:
/* Line 661 of lalr1.cc  */
#line 2400 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 2408 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 2416 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 2423 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 2430 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 2441 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 2450 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)),
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 2459 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,
                                          (yysemantic_stack_[(4) - (4)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 2468 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                                          (yysemantic_stack_[(5) - (5)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 2481 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 2489 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 2497 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 2505 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2520 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 2525 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 2533 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2547 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2564 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2589 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 2597 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 2604 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 2615 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 2624 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 2632 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 2637 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 214:
/* Line 661 of lalr1.cc  */
#line 2650 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 233:
/* Line 661 of lalr1.cc  */
#line 2697 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 234:
/* Line 661 of lalr1.cc  */
#line 2711 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 2723 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
    }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 2730 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 2735 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 2743 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 2748 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 2753 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 2761 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2770 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2782 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2792 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 2805 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 2829 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 2836 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 2846 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 2851 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 2860 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 260:
/* Line 661 of lalr1.cc  */
#line 2869 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 2883 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

    }
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 2891 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 2898 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 2906 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 2918 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 267:
/* Line 661 of lalr1.cc  */
#line 2928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 268:
/* Line 661 of lalr1.cc  */
#line 2938 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 269:
/* Line 661 of lalr1.cc  */
#line 2948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 270:
/* Line 661 of lalr1.cc  */
#line 2958 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 271:
/* Line 661 of lalr1.cc  */
#line 2968 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 272:
/* Line 661 of lalr1.cc  */
#line 2978 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 273:
/* Line 661 of lalr1.cc  */
#line 2988 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 274:
/* Line 661 of lalr1.cc  */
#line 2999 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 3008 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 276:
/* Line 661 of lalr1.cc  */
#line 3018 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 277:
/* Line 661 of lalr1.cc  */
#line 3028 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 278:
/* Line 661 of lalr1.cc  */
#line 3044 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 3053 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 3062 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 3070 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 3076 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 3088 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 3096 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 3106 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 3114 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 3126 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 3132 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 3145 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 3149 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 3157 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 3161 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 3170 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 3174 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 3178 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 3188 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 3196 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 3203 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 3209 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 3219 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 3223 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 3231 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 3239 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 3247 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 3255 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 3267 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 3275 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 3281 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 3291 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 3297 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 3307 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 3311 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 3321 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 3327 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 3333 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 3339 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 3348 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 3357 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 3366 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 3379 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 3383 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 3391 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 3397 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 3407 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 3415 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 3424 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 3437 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 3444 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 3456 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 3460 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 3472 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 3479 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 3485 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 3494 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 3501 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 3507 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 3518 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 3525 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 3531 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 3540 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 3549 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 3556 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 3567 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 3574 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 3586 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 3592 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 3604 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 3610 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 3621 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 3627 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 3638 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 3644 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 3655 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 3661 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 3672 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 3681 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 3685 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 360:
/* Line 661 of lalr1.cc  */
#line 3699 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 3709 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:
/* Line 661 of lalr1.cc  */
#line 3719 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 3723 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new ComparisonExpr(
              LOC((yyloc)),
              new ValueComp( LOC((yyloc)), ParseConstants::op_val_not ),
              (yysemantic_stack_[(2) - (2)].expr),
              NULL
          );
        }
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 3738 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 3742 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 3752 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 3759 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 3768 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 3777 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {




            driver.getJsoniqLexer()->interpretAsLessThan();

        }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 3786 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 3795 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 3804 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 3813 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 3826 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 3830 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 3842 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 3846 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 3853 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 3857 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 3864 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 3868 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 3877 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 3881 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 3885 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 3893 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 3897 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 3903 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 3909 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 3915 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 3925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:
/* Line 661 of lalr1.cc  */
#line 3929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 392:
/* Line 661 of lalr1.cc  */
#line 3933 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 393:
/* Line 661 of lalr1.cc  */
#line 3941 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:
/* Line 661 of lalr1.cc  */
#line 3945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 395:
/* Line 661 of lalr1.cc  */
#line 3951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 396:
/* Line 661 of lalr1.cc  */
#line 3961 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:
/* Line 661 of lalr1.cc  */
#line 3965 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:
/* Line 661 of lalr1.cc  */
#line 3975 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:
/* Line 661 of lalr1.cc  */
#line 3979 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 400:
/* Line 661 of lalr1.cc  */
#line 3989 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:
/* Line 661 of lalr1.cc  */
#line 3993 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 402:
/* Line 661 of lalr1.cc  */
#line 4003 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:
/* Line 661 of lalr1.cc  */
#line 4007 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 404:
/* Line 661 of lalr1.cc  */
#line 4017 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 405:
/* Line 661 of lalr1.cc  */
#line 4021 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 406:
/* Line 661 of lalr1.cc  */
#line 4030 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:
/* Line 661 of lalr1.cc  */
#line 4034 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 408:
/* Line 661 of lalr1.cc  */
#line 4042 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 409:
/* Line 661 of lalr1.cc  */
#line 4046 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 410:
/* Line 661 of lalr1.cc  */
#line 4050 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 411:
/* Line 661 of lalr1.cc  */
#line 4054 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 415:
/* Line 661 of lalr1.cc  */
#line 4070 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 416:
/* Line 661 of lalr1.cc  */
#line 4075 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 417:
/* Line 661 of lalr1.cc  */
#line 4083 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 418:
/* Line 661 of lalr1.cc  */
#line 4087 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 419:
/* Line 661 of lalr1.cc  */
#line 4091 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 420:
/* Line 661 of lalr1.cc  */
#line 4095 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 421:
/* Line 661 of lalr1.cc  */
#line 4099 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 422:
/* Line 661 of lalr1.cc  */
#line 4103 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 423:
/* Line 661 of lalr1.cc  */
#line 4111 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 424:
/* Line 661 of lalr1.cc  */
#line 4115 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 425:
/* Line 661 of lalr1.cc  */
#line 4119 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 426:
/* Line 661 of lalr1.cc  */
#line 4127 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 427:
/* Line 661 of lalr1.cc  */
#line 4131 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 428:
/* Line 661 of lalr1.cc  */
#line 4135 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 429:
/* Line 661 of lalr1.cc  */
#line 4139 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 430:
/* Line 661 of lalr1.cc  */
#line 4150 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 431:
/* Line 661 of lalr1.cc  */
#line 4160 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 432:
/* Line 661 of lalr1.cc  */
#line 4166 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 433:
/* Line 661 of lalr1.cc  */
#line 4176 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 434:
/* Line 661 of lalr1.cc  */
#line 4180 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 435:
/* Line 661 of lalr1.cc  */
#line 4184 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 436:
/* Line 661 of lalr1.cc  */
#line 4190 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 437:
/* Line 661 of lalr1.cc  */
#line 4194 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 4204 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 4214 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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




        switch (rpe->is_jsoniq_literal())
        {
        case 0:


          break;
        case 1:

          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
          (yyval.expr) = new NullLiteral(LOC((yyloc)));
          break;
        case 2:

          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
          break;
        case 3:

          driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
          break;
        }

      }

      if ((yyval.expr) == NULL)
        (yyval.expr) = (rpe ?
              new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)) :
              (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 440:
/* Line 661 of lalr1.cc  */
#line 4267 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 441:
/* Line 661 of lalr1.cc  */
#line 4276 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 4286 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 443:
/* Line 661 of lalr1.cc  */
#line 4290 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 446:
/* Line 661 of lalr1.cc  */
#line 4306 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 447:
/* Line 661 of lalr1.cc  */
#line 4312 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 4320 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 449:
/* Line 661 of lalr1.cc  */
#line 4326 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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
#line 4339 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 451:
/* Line 661 of lalr1.cc  */
#line 4345 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 452:
/* Line 661 of lalr1.cc  */
#line 4356 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 453:
/* Line 661 of lalr1.cc  */
#line 4360 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 454:
/* Line 661 of lalr1.cc  */
#line 4364 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 455:
/* Line 661 of lalr1.cc  */
#line 4368 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 456:
/* Line 661 of lalr1.cc  */
#line 4372 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 457:
/* Line 661 of lalr1.cc  */
#line 4378 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 458:
/* Line 661 of lalr1.cc  */
#line 4384 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 459:
/* Line 661 of lalr1.cc  */
#line 4393 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 460:
/* Line 661 of lalr1.cc  */
#line 4397 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 461:
/* Line 661 of lalr1.cc  */
#line 4406 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 462:
/* Line 661 of lalr1.cc  */
#line 4410 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 463:
/* Line 661 of lalr1.cc  */
#line 4422 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 464:
/* Line 661 of lalr1.cc  */
#line 4426 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 465:
/* Line 661 of lalr1.cc  */
#line 4430 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 466:
/* Line 661 of lalr1.cc  */
#line 4436 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 467:
/* Line 661 of lalr1.cc  */
#line 4440 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 470:
/* Line 661 of lalr1.cc  */
#line 4462 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 471:
/* Line 661 of lalr1.cc  */
#line 4466 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 472:
/* Line 661 of lalr1.cc  */
#line 4476 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 473:
/* Line 661 of lalr1.cc  */
#line 4480 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 474:
/* Line 661 of lalr1.cc  */
#line 4484 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 475:
/* Line 661 of lalr1.cc  */
#line 4488 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 476:
/* Line 661 of lalr1.cc  */
#line 4501 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 477:
/* Line 661 of lalr1.cc  */
#line 4505 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 478:
/* Line 661 of lalr1.cc  */
#line 4509 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 479:
/* Line 661 of lalr1.cc  */
#line 4513 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 480:
/* Line 661 of lalr1.cc  */
#line 4519 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new JSONArrayUnboxing(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
    }
    break;

  case 481:
/* Line 661 of lalr1.cc  */
#line 4523 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (3)].expr), (yylocation_stack_[(3) - (3)]));
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 482:
/* Line 661 of lalr1.cc  */
#line 4529 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(4) - (2)])),
                                 (yysemantic_stack_[(4) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), NULL));
     }
    break;

  case 483:
/* Line 661 of lalr1.cc  */
#line 4535 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(5) - (2)])),
                                 (yysemantic_stack_[(5) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (4)].expr)));
     }
    break;

  case 484:
/* Line 661 of lalr1.cc  */
#line 4541 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 485:
/* Line 661 of lalr1.cc  */
#line 4545 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 486:
/* Line 661 of lalr1.cc  */
#line 4554 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 487:
/* Line 661 of lalr1.cc  */
#line 4560 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));

      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 488:
/* Line 661 of lalr1.cc  */
#line 4571 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 503:
/* Line 661 of lalr1.cc  */
#line 4599 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:
/* Line 661 of lalr1.cc  */
#line 4603 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:
/* Line 661 of lalr1.cc  */
#line 4611 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 506:
/* Line 661 of lalr1.cc  */
#line 4618 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 507:
/* Line 661 of lalr1.cc  */
#line 4625 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 508:
/* Line 661 of lalr1.cc  */
#line 4636 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 509:
/* Line 661 of lalr1.cc  */
#line 4644 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 510:
/* Line 661 of lalr1.cc  */
#line 4648 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 511:
/* Line 661 of lalr1.cc  */
#line 4656 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 512:
/* Line 661 of lalr1.cc  */
#line 4667 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 513:
/* Line 661 of lalr1.cc  */
#line 4675 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 514:
/* Line 661 of lalr1.cc  */
#line 4681 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 515:
/* Line 661 of lalr1.cc  */
#line 4685 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 516:
/* Line 661 of lalr1.cc  */
#line 4707 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 517:
/* Line 661 of lalr1.cc  */
#line 4713 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 518:
/* Line 661 of lalr1.cc  */
#line 4719 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 519:
/* Line 661 of lalr1.cc  */
#line 4725 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 520:
/* Line 661 of lalr1.cc  */
#line 4735 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 521:
/* Line 661 of lalr1.cc  */
#line 4739 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 522:
/* Line 661 of lalr1.cc  */
#line 4747 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 523:
/* Line 661 of lalr1.cc  */
#line 4755 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 529:
/* Line 661 of lalr1.cc  */
#line 4780 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 530:
/* Line 661 of lalr1.cc  */
#line 4788 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 531:
/* Line 661 of lalr1.cc  */
#line 4805 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 532:
/* Line 661 of lalr1.cc  */
#line 4813 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 533:
/* Line 661 of lalr1.cc  */
#line 4832 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 534:
/* Line 661 of lalr1.cc  */
#line 4851 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 535:
/* Line 661 of lalr1.cc  */
#line 4873 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 536:
/* Line 661 of lalr1.cc  */
#line 4879 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:
/* Line 661 of lalr1.cc  */
#line 4890 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 538:
/* Line 661 of lalr1.cc  */
#line 4896 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 539:
/* Line 661 of lalr1.cc  */
#line 4907 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 542:
/* Line 661 of lalr1.cc  */
#line 4922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 543:
/* Line 661 of lalr1.cc  */
#line 4927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 544:
/* Line 661 of lalr1.cc  */
#line 4936 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 545:
/* Line 661 of lalr1.cc  */
#line 4940 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 546:
/* Line 661 of lalr1.cc  */
#line 4947 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 547:
/* Line 661 of lalr1.cc  */
#line 4953 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 548:
/* Line 661 of lalr1.cc  */
#line 4959 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 549:
/* Line 661 of lalr1.cc  */
#line 4966 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 550:
/* Line 661 of lalr1.cc  */
#line 4977 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 551:
/* Line 661 of lalr1.cc  */
#line 4981 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 552:
/* Line 661 of lalr1.cc  */
#line 4988 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 553:
/* Line 661 of lalr1.cc  */
#line 4994 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 554:
/* Line 661 of lalr1.cc  */
#line 5000 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 555:
/* Line 661 of lalr1.cc  */
#line 5007 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 556:
/* Line 661 of lalr1.cc  */
#line 5018 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 557:
/* Line 661 of lalr1.cc  */
#line 5022 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 558:
/* Line 661 of lalr1.cc  */
#line 5030 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 559:
/* Line 661 of lalr1.cc  */
#line 5034 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 560:
/* Line 661 of lalr1.cc  */
#line 5042 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 561:
/* Line 661 of lalr1.cc  */
#line 5046 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 562:
/* Line 661 of lalr1.cc  */
#line 5050 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 563:
/* Line 661 of lalr1.cc  */
#line 5055 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 564:
/* Line 661 of lalr1.cc  */
#line 5064 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 565:
/* Line 661 of lalr1.cc  */
#line 5068 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 566:
/* Line 661 of lalr1.cc  */
#line 5072 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 567:
/* Line 661 of lalr1.cc  */
#line 5076 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 568:
/* Line 661 of lalr1.cc  */
#line 5084 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 569:
/* Line 661 of lalr1.cc  */
#line 5089 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 570:
/* Line 661 of lalr1.cc  */
#line 5097 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 571:
/* Line 661 of lalr1.cc  */
#line 5103 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 572:
/* Line 661 of lalr1.cc  */
#line 5112 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 573:
/* Line 661 of lalr1.cc  */
#line 5120 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 574:
/* Line 661 of lalr1.cc  */
#line 5125 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 575:
/* Line 661 of lalr1.cc  */
#line 5130 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 576:
/* Line 661 of lalr1.cc  */
#line 5135 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 577:
/* Line 661 of lalr1.cc  */
#line 5140 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 578:
/* Line 661 of lalr1.cc  */
#line 5145 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 580:
/* Line 661 of lalr1.cc  */
#line 5156 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 581:
/* Line 661 of lalr1.cc  */
#line 5164 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 582:
/* Line 661 of lalr1.cc  */
#line 5168 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 583:
/* Line 661 of lalr1.cc  */
#line 5174 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 584:
/* Line 661 of lalr1.cc  */
#line 5178 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 585:
/* Line 661 of lalr1.cc  */
#line 5186 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 586:
/* Line 661 of lalr1.cc  */
#line 5194 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 587:
/* Line 661 of lalr1.cc  */
#line 5202 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 588:
/* Line 661 of lalr1.cc  */
#line 5206 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 589:
/* Line 661 of lalr1.cc  */
#line 5214 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 590:
/* Line 661 of lalr1.cc  */
#line 5218 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 591:
/* Line 661 of lalr1.cc  */
#line 5226 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 592:
/* Line 661 of lalr1.cc  */
#line 5234 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 593:
/* Line 661 of lalr1.cc  */
#line 5238 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 594:
/* Line 661 of lalr1.cc  */
#line 5242 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 595:
/* Line 661 of lalr1.cc  */
#line 5248 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {

            driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_JSONIQ_EMPTY_SEQUENCE));
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 596:
/* Line 661 of lalr1.cc  */
#line 5257 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 597:
/* Line 661 of lalr1.cc  */
#line 5263 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 598:
/* Line 661 of lalr1.cc  */
#line 5269 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 599:
/* Line 661 of lalr1.cc  */
#line 5279 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            GeneralizedAtomicType* gat = static_cast<GeneralizedAtomicType*>((yysemantic_stack_[(1) - (1)].node));
            QName* q = gat->get_qname();


            if (q->get_qname() == "item")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new ItemType( LOC((yyloc)), true );
            }
            else if (q->get_qname() == "array")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
            }
            else if (q->get_qname() == "object")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
            }
            else if (q->get_qname() == "json-item")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
            }
            else if (q->get_qname() == "structured-item")
            {

              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new StructuredItemType(LOC((yyloc)));
            }
            else
            {
              (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            }



        }
    break;

  case 600:
/* Line 661 of lalr1.cc  */
#line 5323 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 601:
/* Line 661 of lalr1.cc  */
#line 5327 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 602:
/* Line 661 of lalr1.cc  */
#line 5331 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 603:
/* Line 661 of lalr1.cc  */
#line 5335 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 604:
/* Line 661 of lalr1.cc  */
#line 5339 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 605:
/* Line 661 of lalr1.cc  */
#line 5343 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 606:
/* Line 661 of lalr1.cc  */
#line 5350 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 607:
/* Line 661 of lalr1.cc  */
#line 5356 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 608:
/* Line 661 of lalr1.cc  */
#line 5366 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 609:
/* Line 661 of lalr1.cc  */
#line 5374 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 610:
/* Line 661 of lalr1.cc  */
#line 5382 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:
/* Line 661 of lalr1.cc  */
#line 5386 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:
/* Line 661 of lalr1.cc  */
#line 5390 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 613:
/* Line 661 of lalr1.cc  */
#line 5394 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 614:
/* Line 661 of lalr1.cc  */
#line 5398 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 615:
/* Line 661 of lalr1.cc  */
#line 5402 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 616:
/* Line 661 of lalr1.cc  */
#line 5406 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:
/* Line 661 of lalr1.cc  */
#line 5410 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:
/* Line 661 of lalr1.cc  */
#line 5414 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 619:
/* Line 661 of lalr1.cc  */
#line 5418 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 620:
/* Line 661 of lalr1.cc  */
#line 5426 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 621:
/* Line 661 of lalr1.cc  */
#line 5433 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 622:
/* Line 661 of lalr1.cc  */
#line 5440 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 623:
/* Line 661 of lalr1.cc  */
#line 5444 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 624:
/* Line 661 of lalr1.cc  */
#line 5448 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 625:
/* Line 661 of lalr1.cc  */
#line 5456 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 626:
/* Line 661 of lalr1.cc  */
#line 5463 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 627:
/* Line 661 of lalr1.cc  */
#line 5471 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 628:
/* Line 661 of lalr1.cc  */
#line 5479 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 629:
/* Line 661 of lalr1.cc  */
#line 5483 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 630:
/* Line 661 of lalr1.cc  */
#line 5488 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 631:
/* Line 661 of lalr1.cc  */
#line 5496 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 632:
/* Line 661 of lalr1.cc  */
#line 5500 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 633:
/* Line 661 of lalr1.cc  */
#line 5506 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 634:
/* Line 661 of lalr1.cc  */
#line 5512 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 635:
/* Line 661 of lalr1.cc  */
#line 5516 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 636:
/* Line 661 of lalr1.cc  */
#line 5526 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 637:
/* Line 661 of lalr1.cc  */
#line 5534 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 638:
/* Line 661 of lalr1.cc  */
#line 5538 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 639:
/* Line 661 of lalr1.cc  */
#line 5544 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 640:
/* Line 661 of lalr1.cc  */
#line 5553 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 641:
/* Line 661 of lalr1.cc  */
#line 5562 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 642:
/* Line 661 of lalr1.cc  */
#line 5568 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 643:
/* Line 661 of lalr1.cc  */
#line 5574 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 644:
/* Line 661 of lalr1.cc  */
#line 5584 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 645:
/* Line 661 of lalr1.cc  */
#line 5590 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 646:
/* Line 661 of lalr1.cc  */
#line 5597 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 647:
/* Line 661 of lalr1.cc  */
#line 5603 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 648:
/* Line 661 of lalr1.cc  */
#line 5609 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 649:
/* Line 661 of lalr1.cc  */
#line 5613 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 650:
/* Line 661 of lalr1.cc  */
#line 5621 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 651:
/* Line 661 of lalr1.cc  */
#line 5629 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 652:
/* Line 661 of lalr1.cc  */
#line 5633 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 653:
/* Line 661 of lalr1.cc  */
#line 5644 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 654:
/* Line 661 of lalr1.cc  */
#line 5650 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 655:
/* Line 661 of lalr1.cc  */
#line 5656 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 656:
/* Line 661 of lalr1.cc  */
#line 5662 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 657:
/* Line 661 of lalr1.cc  */
#line 5672 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 658:
/* Line 661 of lalr1.cc  */
#line 5676 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 659:
/* Line 661 of lalr1.cc  */
#line 5682 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 660:
/* Line 661 of lalr1.cc  */
#line 5688 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 661:
/* Line 661 of lalr1.cc  */
#line 5692 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 662:
/* Line 661 of lalr1.cc  */
#line 5698 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 663:
/* Line 661 of lalr1.cc  */
#line 5702 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 664:
/* Line 661 of lalr1.cc  */
#line 5708 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 665:
/* Line 661 of lalr1.cc  */
#line 5714 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 666:
/* Line 661 of lalr1.cc  */
#line 5721 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 667:
/* Line 661 of lalr1.cc  */
#line 5731 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 668:
/* Line 661 of lalr1.cc  */
#line 5736 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 669:
/* Line 661 of lalr1.cc  */
#line 5744 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 670:
/* Line 661 of lalr1.cc  */
#line 5750 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 671:
/* Line 661 of lalr1.cc  */
#line 5760 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 672:
/* Line 661 of lalr1.cc  */
#line 5766 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 673:
/* Line 661 of lalr1.cc  */
#line 5775 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 674:
/* Line 661 of lalr1.cc  */
#line 5781 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 675:
/* Line 661 of lalr1.cc  */
#line 5794 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 676:
/* Line 661 of lalr1.cc  */
#line 5800 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 677:
/* Line 661 of lalr1.cc  */
#line 5807 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 678:
/* Line 661 of lalr1.cc  */
#line 5813 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 679:
/* Line 661 of lalr1.cc  */
#line 5823 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 680:
/* Line 661 of lalr1.cc  */
#line 5832 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 681:
/* Line 661 of lalr1.cc  */
#line 5840 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 682:
/* Line 661 of lalr1.cc  */
#line 5846 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 683:
/* Line 661 of lalr1.cc  */
#line 5855 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 684:
/* Line 661 of lalr1.cc  */
#line 5863 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 685:
/* Line 661 of lalr1.cc  */
#line 5867 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 686:
/* Line 661 of lalr1.cc  */
#line 5874 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 687:
/* Line 661 of lalr1.cc  */
#line 5879 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 688:
/* Line 661 of lalr1.cc  */
#line 5887 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:
/* Line 661 of lalr1.cc  */
#line 5891 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 690:
/* Line 661 of lalr1.cc  */
#line 5898 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:
/* Line 661 of lalr1.cc  */
#line 5902 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 692:
/* Line 661 of lalr1.cc  */
#line 5909 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:
/* Line 661 of lalr1.cc  */
#line 5913 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 694:
/* Line 661 of lalr1.cc  */
#line 5920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:
/* Line 661 of lalr1.cc  */
#line 5924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 696:
/* Line 661 of lalr1.cc  */
#line 5933 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 697:
/* Line 661 of lalr1.cc  */
#line 5945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 698:
/* Line 661 of lalr1.cc  */
#line 5949 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:
/* Line 661 of lalr1.cc  */
#line 5956 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 700:
/* Line 661 of lalr1.cc  */
#line 5960 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:
/* Line 661 of lalr1.cc  */
#line 5968 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 702:
/* Line 661 of lalr1.cc  */
#line 5976 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 703:
/* Line 661 of lalr1.cc  */
#line 5984 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 704:
/* Line 661 of lalr1.cc  */
#line 5988 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:
/* Line 661 of lalr1.cc  */
#line 5995 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 706:
/* Line 661 of lalr1.cc  */
#line 5999 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:
/* Line 661 of lalr1.cc  */
#line 6007 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 708:
/* Line 661 of lalr1.cc  */
#line 6018 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 709:
/* Line 661 of lalr1.cc  */
#line 6022 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:
/* Line 661 of lalr1.cc  */
#line 6030 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 711:
/* Line 661 of lalr1.cc  */
#line 6042 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 712:
/* Line 661 of lalr1.cc  */
#line 6048 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 713:
/* Line 661 of lalr1.cc  */
#line 6057 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 714:
/* Line 661 of lalr1.cc  */
#line 6061 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:
/* Line 661 of lalr1.cc  */
#line 6069 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 716:
/* Line 661 of lalr1.cc  */
#line 6073 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 717:
/* Line 661 of lalr1.cc  */
#line 6077 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 718:
/* Line 661 of lalr1.cc  */
#line 6084 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 719:
/* Line 661 of lalr1.cc  */
#line 6088 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 720:
/* Line 661 of lalr1.cc  */
#line 6095 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 721:
/* Line 661 of lalr1.cc  */
#line 6099 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 722:
/* Line 661 of lalr1.cc  */
#line 6107 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:
/* Line 661 of lalr1.cc  */
#line 6111 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:
/* Line 661 of lalr1.cc  */
#line 6115 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:
/* Line 661 of lalr1.cc  */
#line 6119 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:
/* Line 661 of lalr1.cc  */
#line 6123 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:
/* Line 661 of lalr1.cc  */
#line 6131 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 728:
/* Line 661 of lalr1.cc  */
#line 6139 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 729:
/* Line 661 of lalr1.cc  */
#line 6151 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 730:
/* Line 661 of lalr1.cc  */
#line 6163 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 731:
/* Line 661 of lalr1.cc  */
#line 6167 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 732:
/* Line 661 of lalr1.cc  */
#line 6171 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 733:
/* Line 661 of lalr1.cc  */
#line 6179 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 734:
/* Line 661 of lalr1.cc  */
#line 6185 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 735:
/* Line 661 of lalr1.cc  */
#line 6195 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 736:
/* Line 661 of lalr1.cc  */
#line 6199 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 737:
/* Line 661 of lalr1.cc  */
#line 6203 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 738:
/* Line 661 of lalr1.cc  */
#line 6207 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 739:
/* Line 661 of lalr1.cc  */
#line 6211 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 740:
/* Line 661 of lalr1.cc  */
#line 6215 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 741:
/* Line 661 of lalr1.cc  */
#line 6219 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 742:
/* Line 661 of lalr1.cc  */
#line 6223 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:
/* Line 661 of lalr1.cc  */
#line 6231 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 744:
/* Line 661 of lalr1.cc  */
#line 6235 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 745:
/* Line 661 of lalr1.cc  */
#line 6239 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 746:
/* Line 661 of lalr1.cc  */
#line 6243 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 747:
/* Line 661 of lalr1.cc  */
#line 6251 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 748:
/* Line 661 of lalr1.cc  */
#line 6257 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 749:
/* Line 661 of lalr1.cc  */
#line 6267 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 750:
/* Line 661 of lalr1.cc  */
#line 6277 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 751:
/* Line 661 of lalr1.cc  */
#line 6281 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 752:
/* Line 661 of lalr1.cc  */
#line 6289 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 753:
/* Line 661 of lalr1.cc  */
#line 6299 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 754:
/* Line 661 of lalr1.cc  */
#line 6310 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 755:
/* Line 661 of lalr1.cc  */
#line 6317 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 756:
/* Line 661 of lalr1.cc  */
#line 6321 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 757:
/* Line 661 of lalr1.cc  */
#line 6328 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 758:
/* Line 661 of lalr1.cc  */
#line 6332 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 759:
/* Line 661 of lalr1.cc  */
#line 6339 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 760:
/* Line 661 of lalr1.cc  */
#line 6344 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 761:
/* Line 661 of lalr1.cc  */
#line 6353 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 762:
/* Line 661 of lalr1.cc  */
#line 6362 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 763:
/* Line 661 of lalr1.cc  */
#line 6366 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 764:
/* Line 661 of lalr1.cc  */
#line 6373 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 765:
/* Line 661 of lalr1.cc  */
#line 6377 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 766:
/* Line 661 of lalr1.cc  */
#line 6385 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 767:
/* Line 661 of lalr1.cc  */
#line 6394 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 768:
/* Line 661 of lalr1.cc  */
#line 6401 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 769:
/* Line 661 of lalr1.cc  */
#line 6411 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 770:
/* Line 661 of lalr1.cc  */
#line 6415 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 771:
/* Line 661 of lalr1.cc  */
#line 6422 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 772:
/* Line 661 of lalr1.cc  */
#line 6428 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 773:
/* Line 661 of lalr1.cc  */
#line 6437 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 774:
/* Line 661 of lalr1.cc  */
#line 6441 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 775:
/* Line 661 of lalr1.cc  */
#line 6448 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 776:
/* Line 661 of lalr1.cc  */
#line 6453 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 777:
/* Line 661 of lalr1.cc  */
#line 6465 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 778:
/* Line 661 of lalr1.cc  */
#line 6473 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 779:
/* Line 661 of lalr1.cc  */
#line 6485 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 780:
/* Line 661 of lalr1.cc  */
#line 6493 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 781:
/* Line 661 of lalr1.cc  */
#line 6497 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 782:
/* Line 661 of lalr1.cc  */
#line 6505 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 783:
/* Line 661 of lalr1.cc  */
#line 6509 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 784:
/* Line 661 of lalr1.cc  */
#line 6513 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 785:
/* Line 661 of lalr1.cc  */
#line 6521 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 786:
/* Line 661 of lalr1.cc  */
#line 6529 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 787:
/* Line 661 of lalr1.cc  */
#line 6533 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 788:
/* Line 661 of lalr1.cc  */
#line 6537 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 789:
/* Line 661 of lalr1.cc  */
#line 6541 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 790:
/* Line 661 of lalr1.cc  */
#line 6549 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 791:
/* Line 661 of lalr1.cc  */
#line 6557 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 792:
/* Line 661 of lalr1.cc  */
#line 6569 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 793:
/* Line 661 of lalr1.cc  */
#line 6573 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 794:
/* Line 661 of lalr1.cc  */
#line 6581 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 795:
/* Line 661 of lalr1.cc  */
#line 6587 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 796:
/* Line 661 of lalr1.cc  */
#line 6591 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 797:
/* Line 661 of lalr1.cc  */
#line 6598 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 798:
/* Line 661 of lalr1.cc  */
#line 6602 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 799:
/* Line 661 of lalr1.cc  */
#line 6609 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 800:
/* Line 661 of lalr1.cc  */
#line 6613 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 801:
/* Line 661 of lalr1.cc  */
#line 6621 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 802:
/* Line 661 of lalr1.cc  */
#line 6631 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (1)].expr), (yylocation_stack_[(3) - (1)]));


          driver.addCommonLanguageWarning((yylocation_stack_[(3) - (1)]), ZED(ZWST0009_OBJECT_KEY_NOT_QUOTED));

          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 803:
/* Line 661 of lalr1.cc  */
#line 6645 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 804:
/* Line 661 of lalr1.cc  */
#line 6651 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 805:
/* Line 661 of lalr1.cc  */
#line 6660 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 806:
/* Line 661 of lalr1.cc  */
#line 6673 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 807:
/* Line 661 of lalr1.cc  */
#line 6679 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 808:
/* Line 661 of lalr1.cc  */
#line 6689 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 809:
/* Line 661 of lalr1.cc  */
#line 6696 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 810:
/* Line 661 of lalr1.cc  */
#line 6703 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 811:
/* Line 661 of lalr1.cc  */
#line 6721 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 812:
/* Line 661 of lalr1.cc  */
#line 6746 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
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

  case 813:
/* Line 661 of lalr1.cc  */
#line 6766 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 814:
/* Line 661 of lalr1.cc  */
#line 6770 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 815:
/* Line 661 of lalr1.cc  */
#line 6774 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 818:
/* Line 661 of lalr1.cc  */
#line 6792 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 819:
/* Line 661 of lalr1.cc  */
#line 6793 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 820:
/* Line 661 of lalr1.cc  */
#line 6794 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 821:
/* Line 661 of lalr1.cc  */
#line 6795 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 822:
/* Line 661 of lalr1.cc  */
#line 6796 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 823:
/* Line 661 of lalr1.cc  */
#line 6797 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 824:
/* Line 661 of lalr1.cc  */
#line 6798 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 825:
/* Line 661 of lalr1.cc  */
#line 6799 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 826:
/* Line 661 of lalr1.cc  */
#line 6800 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 827:
/* Line 661 of lalr1.cc  */
#line 6801 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 828:
/* Line 661 of lalr1.cc  */
#line 6802 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 829:
/* Line 661 of lalr1.cc  */
#line 6803 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 830:
/* Line 661 of lalr1.cc  */
#line 6804 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 831:
/* Line 661 of lalr1.cc  */
#line 6805 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 832:
/* Line 661 of lalr1.cc  */
#line 6806 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 833:
/* Line 661 of lalr1.cc  */
#line 6807 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 834:
/* Line 661 of lalr1.cc  */
#line 6808 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 835:
/* Line 661 of lalr1.cc  */
#line 6809 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 836:
/* Line 661 of lalr1.cc  */
#line 6810 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 837:
/* Line 661 of lalr1.cc  */
#line 6811 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 838:
/* Line 661 of lalr1.cc  */
#line 6812 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 839:
/* Line 661 of lalr1.cc  */
#line 6813 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 841:
/* Line 661 of lalr1.cc  */
#line 6818 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 842:
/* Line 661 of lalr1.cc  */
#line 6819 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 843:
/* Line 661 of lalr1.cc  */
#line 6820 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 844:
/* Line 661 of lalr1.cc  */
#line 6821 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 845:
/* Line 661 of lalr1.cc  */
#line 6822 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 846:
/* Line 661 of lalr1.cc  */
#line 6823 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 847:
/* Line 661 of lalr1.cc  */
#line 6824 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 848:
/* Line 661 of lalr1.cc  */
#line 6825 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 849:
/* Line 661 of lalr1.cc  */
#line 6826 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 850:
/* Line 661 of lalr1.cc  */
#line 6827 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 851:
/* Line 661 of lalr1.cc  */
#line 6828 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 852:
/* Line 661 of lalr1.cc  */
#line 6829 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 853:
/* Line 661 of lalr1.cc  */
#line 6830 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 854:
/* Line 661 of lalr1.cc  */
#line 6831 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 855:
/* Line 661 of lalr1.cc  */
#line 6832 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 856:
/* Line 661 of lalr1.cc  */
#line 6833 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 857:
/* Line 661 of lalr1.cc  */
#line 6834 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 858:
/* Line 661 of lalr1.cc  */
#line 6835 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 859:
/* Line 661 of lalr1.cc  */
#line 6836 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 860:
/* Line 661 of lalr1.cc  */
#line 6837 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 861:
/* Line 661 of lalr1.cc  */
#line 6838 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 862:
/* Line 661 of lalr1.cc  */
#line 6839 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 863:
/* Line 661 of lalr1.cc  */
#line 6840 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 864:
/* Line 661 of lalr1.cc  */
#line 6841 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 865:
/* Line 661 of lalr1.cc  */
#line 6842 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 866:
/* Line 661 of lalr1.cc  */
#line 6843 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 867:
/* Line 661 of lalr1.cc  */
#line 6844 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 868:
/* Line 661 of lalr1.cc  */
#line 6845 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 869:
/* Line 661 of lalr1.cc  */
#line 6846 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 870:
/* Line 661 of lalr1.cc  */
#line 6847 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 871:
/* Line 661 of lalr1.cc  */
#line 6848 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 872:
/* Line 661 of lalr1.cc  */
#line 6849 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 873:
/* Line 661 of lalr1.cc  */
#line 6850 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 874:
/* Line 661 of lalr1.cc  */
#line 6851 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 875:
/* Line 661 of lalr1.cc  */
#line 6852 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 876:
/* Line 661 of lalr1.cc  */
#line 6853 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 877:
/* Line 661 of lalr1.cc  */
#line 6854 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 878:
/* Line 661 of lalr1.cc  */
#line 6855 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 879:
/* Line 661 of lalr1.cc  */
#line 6856 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 880:
/* Line 661 of lalr1.cc  */
#line 6857 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 881:
/* Line 661 of lalr1.cc  */
#line 6858 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 882:
/* Line 661 of lalr1.cc  */
#line 6859 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 883:
/* Line 661 of lalr1.cc  */
#line 6860 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 884:
/* Line 661 of lalr1.cc  */
#line 6861 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 885:
/* Line 661 of lalr1.cc  */
#line 6862 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 886:
/* Line 661 of lalr1.cc  */
#line 6863 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 887:
/* Line 661 of lalr1.cc  */
#line 6864 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 888:
/* Line 661 of lalr1.cc  */
#line 6865 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 889:
/* Line 661 of lalr1.cc  */
#line 6866 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 890:
/* Line 661 of lalr1.cc  */
#line 6867 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 891:
/* Line 661 of lalr1.cc  */
#line 6868 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 892:
/* Line 661 of lalr1.cc  */
#line 6869 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 893:
/* Line 661 of lalr1.cc  */
#line 6870 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 894:
/* Line 661 of lalr1.cc  */
#line 6871 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 895:
/* Line 661 of lalr1.cc  */
#line 6872 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 896:
/* Line 661 of lalr1.cc  */
#line 6873 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 897:
/* Line 661 of lalr1.cc  */
#line 6874 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 898:
/* Line 661 of lalr1.cc  */
#line 6875 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 899:
/* Line 661 of lalr1.cc  */
#line 6876 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 900:
/* Line 661 of lalr1.cc  */
#line 6877 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 901:
/* Line 661 of lalr1.cc  */
#line 6878 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 902:
/* Line 661 of lalr1.cc  */
#line 6879 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 903:
/* Line 661 of lalr1.cc  */
#line 6880 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 904:
/* Line 661 of lalr1.cc  */
#line 6881 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 905:
/* Line 661 of lalr1.cc  */
#line 6882 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 906:
/* Line 661 of lalr1.cc  */
#line 6883 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 907:
/* Line 661 of lalr1.cc  */
#line 6884 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 908:
/* Line 661 of lalr1.cc  */
#line 6885 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 909:
/* Line 661 of lalr1.cc  */
#line 6886 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 910:
/* Line 661 of lalr1.cc  */
#line 6887 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 911:
/* Line 661 of lalr1.cc  */
#line 6888 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 912:
/* Line 661 of lalr1.cc  */
#line 6889 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 913:
/* Line 661 of lalr1.cc  */
#line 6890 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 914:
/* Line 661 of lalr1.cc  */
#line 6891 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 915:
/* Line 661 of lalr1.cc  */
#line 6892 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 916:
/* Line 661 of lalr1.cc  */
#line 6893 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 917:
/* Line 661 of lalr1.cc  */
#line 6894 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 918:
/* Line 661 of lalr1.cc  */
#line 6895 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 919:
/* Line 661 of lalr1.cc  */
#line 6896 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 920:
/* Line 661 of lalr1.cc  */
#line 6897 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 921:
/* Line 661 of lalr1.cc  */
#line 6898 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 922:
/* Line 661 of lalr1.cc  */
#line 6899 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 923:
/* Line 661 of lalr1.cc  */
#line 6900 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 924:
/* Line 661 of lalr1.cc  */
#line 6901 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 925:
/* Line 661 of lalr1.cc  */
#line 6902 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 926:
/* Line 661 of lalr1.cc  */
#line 6903 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 927:
/* Line 661 of lalr1.cc  */
#line 6904 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 928:
/* Line 661 of lalr1.cc  */
#line 6905 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 929:
/* Line 661 of lalr1.cc  */
#line 6906 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 930:
/* Line 661 of lalr1.cc  */
#line 6907 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 931:
/* Line 661 of lalr1.cc  */
#line 6908 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 932:
/* Line 661 of lalr1.cc  */
#line 6909 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 933:
/* Line 661 of lalr1.cc  */
#line 6910 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 934:
/* Line 661 of lalr1.cc  */
#line 6911 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 935:
/* Line 661 of lalr1.cc  */
#line 6912 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 936:
/* Line 661 of lalr1.cc  */
#line 6913 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 937:
/* Line 661 of lalr1.cc  */
#line 6914 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 938:
/* Line 661 of lalr1.cc  */
#line 6915 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 939:
/* Line 661 of lalr1.cc  */
#line 6916 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 940:
/* Line 661 of lalr1.cc  */
#line 6917 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 941:
/* Line 661 of lalr1.cc  */
#line 6918 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 942:
/* Line 661 of lalr1.cc  */
#line 6919 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 943:
/* Line 661 of lalr1.cc  */
#line 6920 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 944:
/* Line 661 of lalr1.cc  */
#line 6921 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 945:
/* Line 661 of lalr1.cc  */
#line 6922 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 946:
/* Line 661 of lalr1.cc  */
#line 6923 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 947:
/* Line 661 of lalr1.cc  */
#line 6924 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 948:
/* Line 661 of lalr1.cc  */
#line 6925 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 949:
/* Line 661 of lalr1.cc  */
#line 6926 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 950:
/* Line 661 of lalr1.cc  */
#line 6927 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 951:
/* Line 661 of lalr1.cc  */
#line 6928 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 952:
/* Line 661 of lalr1.cc  */
#line 6929 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 953:
/* Line 661 of lalr1.cc  */
#line 6930 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 954:
/* Line 661 of lalr1.cc  */
#line 6931 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 955:
/* Line 661 of lalr1.cc  */
#line 6932 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 956:
/* Line 661 of lalr1.cc  */
#line 6933 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 957:
/* Line 661 of lalr1.cc  */
#line 6934 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 958:
/* Line 661 of lalr1.cc  */
#line 6935 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 959:
/* Line 661 of lalr1.cc  */
#line 6936 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 960:
/* Line 661 of lalr1.cc  */
#line 6937 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 961:
/* Line 661 of lalr1.cc  */
#line 6938 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 962:
/* Line 661 of lalr1.cc  */
#line 6939 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 963:
/* Line 661 of lalr1.cc  */
#line 6940 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 964:
/* Line 661 of lalr1.cc  */
#line 6941 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 965:
/* Line 661 of lalr1.cc  */
#line 6942 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 966:
/* Line 661 of lalr1.cc  */
#line 6943 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 967:
/* Line 661 of lalr1.cc  */
#line 6944 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 968:
/* Line 661 of lalr1.cc  */
#line 6945 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 969:
/* Line 661 of lalr1.cc  */
#line 6946 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 970:
/* Line 661 of lalr1.cc  */
#line 6947 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 971:
/* Line 661 of lalr1.cc  */
#line 6948 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 972:
/* Line 661 of lalr1.cc  */
#line 6949 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 973:
/* Line 661 of lalr1.cc  */
#line 6950 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 974:
/* Line 661 of lalr1.cc  */
#line 6951 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 975:
/* Line 661 of lalr1.cc  */
#line 6952 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 976:
/* Line 661 of lalr1.cc  */
#line 6953 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 977:
/* Line 661 of lalr1.cc  */
#line 6954 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 978:
/* Line 661 of lalr1.cc  */
#line 6955 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 979:
/* Line 661 of lalr1.cc  */
#line 6956 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 980:
/* Line 661 of lalr1.cc  */
#line 6957 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 981:
/* Line 661 of lalr1.cc  */
#line 6958 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 982:
/* Line 661 of lalr1.cc  */
#line 6959 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 983:
/* Line 661 of lalr1.cc  */
#line 6960 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 984:
/* Line 661 of lalr1.cc  */
#line 6961 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 985:
/* Line 661 of lalr1.cc  */
#line 6962 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 986:
/* Line 661 of lalr1.cc  */
#line 6963 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 987:
/* Line 661 of lalr1.cc  */
#line 6964 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 988:
/* Line 661 of lalr1.cc  */
#line 6965 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 989:
/* Line 661 of lalr1.cc  */
#line 6966 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 990:
/* Line 661 of lalr1.cc  */
#line 6967 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 991:
/* Line 661 of lalr1.cc  */
#line 6968 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 992:
/* Line 661 of lalr1.cc  */
#line 6969 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 993:
/* Line 661 of lalr1.cc  */
#line 6970 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 994:
/* Line 661 of lalr1.cc  */
#line 6971 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 995:
/* Line 661 of lalr1.cc  */
#line 6972 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 996:
/* Line 661 of lalr1.cc  */
#line 6973 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 997:
/* Line 661 of lalr1.cc  */
#line 6974 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 998:
/* Line 661 of lalr1.cc  */
#line 6975 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 999:
/* Line 661 of lalr1.cc  */
#line 6976 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 1000:
/* Line 661 of lalr1.cc  */
#line 6977 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 1001:
/* Line 661 of lalr1.cc  */
#line 6978 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 1002:
/* Line 661 of lalr1.cc  */
#line 6979 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 1003:
/* Line 661 of lalr1.cc  */
#line 6980 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 1004:
/* Line 661 of lalr1.cc  */
#line 6981 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 1005:
/* Line 661 of lalr1.cc  */
#line 6982 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 1006:
/* Line 661 of lalr1.cc  */
#line 6983 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 1007:
/* Line 661 of lalr1.cc  */
#line 6984 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 1008:
/* Line 661 of lalr1.cc  */
#line 6985 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 1009:
/* Line 661 of lalr1.cc  */
#line 6986 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 1010:
/* Line 661 of lalr1.cc  */
#line 6987 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 1011:
/* Line 661 of lalr1.cc  */
#line 6988 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 1012:
/* Line 661 of lalr1.cc  */
#line 6989 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1013:
/* Line 661 of lalr1.cc  */
#line 6990 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1014:
/* Line 661 of lalr1.cc  */
#line 6991 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1015:
/* Line 661 of lalr1.cc  */
#line 6992 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1016:
/* Line 661 of lalr1.cc  */
#line 6993 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1017:
/* Line 661 of lalr1.cc  */
#line 6994 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1018:
/* Line 661 of lalr1.cc  */
#line 6995 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1019:
/* Line 661 of lalr1.cc  */
#line 6996 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1020:
/* Line 661 of lalr1.cc  */
#line 6997 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1021:
/* Line 661 of lalr1.cc  */
#line 6998 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1022:
/* Line 661 of lalr1.cc  */
#line 6999 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1023:
/* Line 661 of lalr1.cc  */
#line 7000 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1024:
/* Line 661 of lalr1.cc  */
#line 7001 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1025:
/* Line 661 of lalr1.cc  */
#line 7002 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1026:
/* Line 661 of lalr1.cc  */
#line 7003 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1027:
/* Line 661 of lalr1.cc  */
#line 7004 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1028:
/* Line 661 of lalr1.cc  */
#line 7005 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1029:
/* Line 661 of lalr1.cc  */
#line 7006 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1030:
/* Line 661 of lalr1.cc  */
#line 7007 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1031:
/* Line 661 of lalr1.cc  */
#line 7008 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1032:
/* Line 661 of lalr1.cc  */
#line 7009 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1033:
/* Line 661 of lalr1.cc  */
#line 7010 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1034:
/* Line 661 of lalr1.cc  */
#line 7011 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1035:
/* Line 661 of lalr1.cc  */
#line 7012 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1036:
/* Line 661 of lalr1.cc  */
#line 7013 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1037:
/* Line 661 of lalr1.cc  */
#line 7014 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1038:
/* Line 661 of lalr1.cc  */
#line 7015 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1039:
/* Line 661 of lalr1.cc  */
#line 7016 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1040:
/* Line 661 of lalr1.cc  */
#line 7017 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1041:
/* Line 661 of lalr1.cc  */
#line 7019 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("null"))); }
    break;

  case 1042:
/* Line 661 of lalr1.cc  */
#line 7020 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("true"))); }
    break;

  case 1043:
/* Line 661 of lalr1.cc  */
#line 7021 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("false"))); }
    break;

  case 1044:
/* Line 661 of lalr1.cc  */
#line 7022 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("select"))); }
    break;

  case 1045:
/* Line 661 of lalr1.cc  */
#line 7023 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("jsoniq"))); }
    break;

  case 1046:
/* Line 661 of lalr1.cc  */
#line 7029 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 661 of lalr1.cc  */
#line 10986 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1540;
  const short int
  jsoniq_parser::yypact_[] =
  {
      5105, -1540, -1540, -1540, -1540,  6057,  6057,  6057,  6057, -1540,
   -1540,   243,   270, -1540,    78,   294, -1540, -1540, -1540,   844,
   -1540, -1540, -1540,   311,   477,   845,  4590,   539,   563,   792,
   -1540,    94, -1540,   600, -1540, -1540, -1540, -1540, -1540,   874,
   -1540,   619,   707, -1540, -1540, -1540, -1540,   524, -1540,   876,
   -1540,   757,   872, -1540,   333, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,   643,
     787, -1540, -1540, -1540, -1540,   788, 13641, -1540, -1540, -1540,
     812, -1540, -1540, -1540,   584, -1540,   923,   944, -1540, -1540,
   18194, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,   951,
   -1540, -1540,   947,   948, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540,  6057,  8585,  8901, 18194, -1540, -1540,   919, -1540, -1540,
   -1540, -1540,   921, -1540, -1540,   953, 18194, -1540, 14872,   957,
     958, -1540, -1540, -1540, -1540,   959, -1540, -1540, 12693, -1540,
   -1540, -1540, -1540, -1540, -1540,   931, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540,    66, -1540,   856, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,   -77,   930,
     186, -1540,   191,   -31, -1540, -1540, -1540, -1540, -1540, -1540,
     972, -1540,   850,   852,   846, -1540, -1540,   934,   943, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540,  4817, -1540, 13325, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540,  9217,  9533, -1540,   780, -1540, -1540, -1540, -1540,
   -1540,  5423,  6373,  1101, -1540,  6689, -1540, -1540,   847,   109,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540,   128, -1540, -1540, -1540, -1540, -1540,
   -1540,   506, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
    6057, -1540, -1540, -1540, -1540,   280, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540,   176, -1540,   910, -1540, -1540,
   -1540,   659, -1540,   762, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540,   938,  1016, -1540, -1540,   807,   857,  1010,    29,   598,
     271,   441, -1540,  1065,   914,  1015,  1017, 10797, -1540,   924,
   -1540, -1540,   306, -1540, -1540, 13009, -1540,   798, -1540,   965,
   13641, -1540,   965, 13641, -1540, -1540, -1540,   736, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540,   964, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540,   467, -1540, -1540, -1540, -1540, -1540,   939,
   -1540,  6057,   940,   945,   946,  6057,   304,   304,  1093,   678,
     756,   609, 18794, 18194,    12,  1082, 18194,   978,  1014,   638,
   18194,   816,   883, 18194, 18194,   826,   833,    96, -1540, -1540,
   -1540, 18194,  6057,   949,  6057,   408, 11113, 15174, 18194,   305,
     986, 11113,  1141,    84,   443, 18194,  1024,  1001,  1039, -1540,
     960, 11113, 15476, 18194, 18194, 18194,  6057,   961, 11113, 11113,
   18194,  6057,   995,   996, -1540, -1540, -1540, 11113, 15778,   994,
   -1540,   999, -1540, -1540, -1540, -1540,  1000, -1540,  1002, -1540,
   -1540, -1540, -1540, -1540,  1004, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, 18194, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,  1009,
   18194, -1540, -1540,   980,  5741,  1036,   407,  1040,  1006,  1008,
    1011, 18194,  6057, -1540,  1012,   106, -1540,   659, -1540,   119,
    1136, 11113, 11113, -1540,   114, -1540, -1540,  1156, -1540, -1540,
   -1540, -1540, 11113,   962, -1540,  1144, 11113, 11113, 18500, 11113,
   11113, 11113, 11113, 18500, 11113,   942, 18194,   983,   984, 11113,
   11113,  6057,   926, 18194, -1540, -1540,    58, -1540,    55, 11113,
    6373, -1540, -1540, -1540, -1540, -1540,    78,   792,   129,   137,
    1178,  7005,  3304,  7321,  3631,   584, -1540, -1540,   369,   584,
   -1540, 11113,  4263, -1540,  1063,   690,    94,  1018,  1013,  1019,
   -1540, -1540, 11113,   706, -1540, -1540,  6057, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540,   895,   896, 18194,  1069, 11429, 11429,
   11745, -1540, 11745, 11745, -1540, 11745, -1540, 11745, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, 11745, 11745,  1118, 11745, 11745,
   11745, 11745, 11745, 11745, 11745, 11745, 11745, 11745, 11745, 11745,
     954,  1097,  1098,  1099, -1540, -1540, -1540, 12377,  6057, -1540,
   -1540, 12693, 12693, 11113,   965, -1540, -1540,   965, -1540, 14259,
    9849,  7953,   965,  1007,  1045,  8269, -1540, -1540, -1540, -1540,
     288, -1540,   331, -1540, -1540, -1540, -1540, -1540, -1540,  1089,
    1090,   539,  1170, -1540, -1540, 18794,   937,   746, 18194,  1041,
    1042,   937,  1093,  1072,  1068, -1540, -1540, -1540,   403,   955,
    1110,   901, 18194,  1064, 11113,  1091, 18194, 18194, -1540,  1075,
    1026, -1540,  1027,   999,   707, -1540,  1025,  1028,   125, -1540,
     473,   486,  1106, -1540,    52, 18194,  1120,   489, -1540,  6057,
   -1540,   130, -1540, 18194,  1121,  1172, 18194,  1093,  1122,   353,
   18194, 11113,    94, -1540,   255,  1032, -1540,  1033,  1034,  1035,
     319, -1540,   326,  1043, -1540,   139,   147,  1070, -1540,  1046,
    6057,  6057,   269, -1540,   518,   546,   507, 11113,   335, -1540,
   -1540, 11113, 11113, -1540, 11113, 11113, 11113, 11113, -1540, 11113,
   -1540, 11113, -1540, 18194,  1136, -1540,   496,   296,   361, -1540,
   -1540, -1540,   381, -1540,   287, -1540, -1540,  1071,  1077,  1078,
    1079,  1080,   736,   467,   323,   428,   277,   118,  1129,   719,
     993,   210,     9, -1540,  1083, -1540, -1540,  1048,   156,  5741,
     402, 13957,   926, -1540,  1106, -1540, -1540,   998, -1540,   847,
     773,  1205,   178, -1540, -1540,   140, -1540, -1540, -1540,   149,
   -1540,   105, -1540, -1540, -1540, -1540, -1540,  3947, -1540, -1540,
   -1540, 18194,  1073, 11113, 12061, -1540, -1540, -1540, -1540, -1540,
    1106, 18194,    43,  1016, -1540, -1540, -1540, -1540, -1540, 11745,
   -1540, -1540, -1540,   312, -1540,   598,   598,   635,   271,   271,
     271,   271,   441,   441, -1540, -1540, 17288, 17288, 18194, 18194,
   -1540,  1056, -1540, -1540,   150, -1540, 10165, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540,   549, -1540, -1540, -1540,   560,   304,
   -1540, -1540,   734,   747,   789, -1540,   539, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540,   937, -1540,  1108,
   17590,  1102, 11113, -1540, -1540, -1540,  1148,  1093,  1093,   937,
   -1540,   920,  1093,   722, 18194,   459,   603,  1215, -1540, -1540,
     956,   641, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540,   403,    41,  1020,   -90, 11113, -1540, 18194,
    1152,   950,  1093, -1540, -1540, -1540, -1540,  1094, 18194, -1540,
   18194, -1540, 17892,  1123, 17288,  1131, 11113,   -12,  1105,    47,
    1148, 17288,  1132,  1161,  1074,  1057,  1124,  1093,  1100,  1126,
    1164,  1093, 11113,    79, -1540, -1540, -1540,  1113, -1540, -1540,
   -1540, -1540,  1150, 11113, 11113,  1128, -1540,  1171,  1174,  6057,
   -1540,  1086,  1088,  1125, 18194, -1540, 18194, -1540, 11113,  1139,
    1092, 11113, -1540,  1163,  1165, -1540,   160,   163,   166,  1254,
   -1540,   552, -1540,   184,  1135, -1540, -1540,  1262, -1540,   723,
   11113, 11113, 11113,   808, 11113, 11113, 11113, 11113, 11113, 11113,
   11113, 11113, 11113, 18500,  1175, 11113, 11113, -1540,  7637,   133,
    1044, -1540,    17, -1540, 11113,   154,   146,   105,  7321,  3631,
    7321,  1213, -1540, -1540, 11113,   813,  1188, -1540, 18194,  1192,
    1193, -1540,   513,  1047, -1540, -1540,   860,    43, -1540, 11113,
     312,   693,   592, -1540,  1021,   421,  1038,  1049, -1540, -1540,
     883, -1540,  1031,   720,  1142,  1151, 16080,  1153,  1155,  1158,
    1160,  1162, -1540,   291, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540,  1173, -1540, -1540, -1540, -1540, -1540,
     172, 10481, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540,   793, -1540,  1276, 17590,   865, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540,  1029, -1540, -1540,  1280, -1540,
   -1540, -1540, -1540, -1540,   716,  1293, -1540,   753, -1540, -1540,
   -1540,   994,   477,   600,  1000,   619,  1002,  1004, -1540,  1155,
    1158,  1160, -1540,   291,   291, 12377,  1050,  1022, -1540,  1148,
      41,  1095,  1133,  6057,  1138,  1143,  1181,  1147,  1149, 18194,
   -1540,   545, -1540, 18194, -1540, 11113,  1180, 11113,  1207, 11113,
     242,  1190, -1540, -1540, -1540, 17288, -1540,  6057,  1093,  1232,
   -1540, -1540, -1540,  1093,  1232, -1540, 11113,  1197,  6057, 18194,
   -1540, -1540, 11113, 11113,   696, -1540,    64,   697, -1540, 16382,
     855, -1540,   864, -1540,  1157, -1540, -1540,  6057,  1167,  1169,
   -1540, 11113, -1540, -1540, 11113, 11113,  1146,  1171,  1243, -1540,
    1214, -1540,   440, -1540, -1540,  1342, -1540, -1540,  6057, 18194,
   -1540,   743, -1540, -1540, -1540,  6057,  1176,  1111,  1114, -1540,
   -1540, -1540,  1127,  1134, -1540, -1540, -1540,  1255, -1540, -1540,
   -1540, -1540,  1116,   380, 18194,   851, -1540,  1206,  1209,  1212,
    1216, -1540,   910,   659, 13957,  1044, -1540,  7637, 13957, -1540,
   -1540,  1205,   531, -1540, -1540, -1540,  1188, -1540,  1093, -1540,
     922, -1540,    92,  1269, -1540, 11113,   575,  1093, -1540, 12061,
   11113,  1231, -1540,  1263,  1264, 11113, 18194,   974,  1303, -1540,
   -1540, -1540,   424,  1198, -1540,   312,  1140, -1540, -1540,   -32,
   -1540,   714,   123,  1145,   312,   714, 11745, -1540,   574, -1540,
   -1540, -1540, -1540, -1540, -1540,   312,  1238,  1103,   955,   123,
   -1540, -1540,  1096,  1310, -1540, -1540, -1540, 14561,  1202, -1540,
    1204,  1210,  1211,  1218,  1219,  1220, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
    1364,    22,  1365,    22,  1137,  1289, -1540, -1540,  1229, 18194,
    1154, -1540, -1540, 12377, -1540,  1224, -1540, -1540, -1540, -1540,
   -1540, -1540, 11113,  1261, -1540, -1540, 11113, -1540,   547, -1540,
   11113,  1266, 11113, -1540,  1275,  1285,  1319,  1093,  1232, -1540,
   11113,  1233, -1540, -1540, -1540,   851, -1540,    64, 11113,  6057,
     851,    64, -1540, 18194,    20, -1540, 16684,   527, -1540, 16986,
     851, -1540, -1540,  1234, -1540, -1540, -1540, -1540, -1540, 11113,
     866,  1254, 18194,   778, -1540,  1235,  1254, 18194, -1540,  1236,
   -1540, 11113, 11113, 11113, 11113,  1104, 11113, 11113, -1540, 11113,
   11113, 11113, 11113,  7637,   452, -1540, -1540, -1540, -1540, -1540,
    1269, -1540, -1540, -1540, 11113,  1279, -1540, -1540, -1540, 11113,
   18194, 18194, -1540,   398, -1540, 11113, -1540, -1540, -1540,  1239,
   11745, -1540, -1540, -1540, -1540, -1540,   122, 11745, 11745,   -80,
   -1540,  1038, -1540,   230, -1540,  1049,   312,  1272, -1540, -1540,
    1159, -1540, -1540, -1540, -1540,  1333,  1247, -1540,   561, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540,    73,    73, -1540,
      22, -1540, -1540,   568, -1540,  1401,    -5,  1339,  1249, 12377,
     -28,  1166,  1267, -1540, -1540, 11113, -1540, 11113,  1290, -1540,
   11113, -1540,  7637, 11113,  1093, -1540, -1540, -1540, 11113, 11113,
   -1540, -1540, -1540,  7637,  7637,  1347, 17288,  6057, 18194,    20,
   18194, 11113, 18194,    20,  7637, -1540,   579,    75,  1254, 18194,
   -1540,  1244,  1254, -1540, -1540, -1540, -1540, -1540, 11113, -1540,
   -1540, -1540,   207,   241,   248, 11113, -1540, -1540,  1192, 11113,
   -1540, -1540,  1390, -1540, -1540, -1540,   271, 11745, 11745,   635,
     709, -1540, -1540, -1540, -1540, -1540, -1540, 11113, -1540, 17288,
   -1540, 17288,  1353, -1540, -1540, -1540,  1419, -1540, -1540, -1540,
    1179,  1343, -1540, -1540,  1344, -1540,   822, 18194,  1334,  1225,
   18194, 12377, -1540, -1540, 11113, -1540, -1540, -1540,  1232, -1540,
   -1540, 17288, -1540, -1540, -1540,  1360, 11113,   851, -1540,  1362,
    7637, -1540, 18194,   577,   485, -1540,  1259,  1254, -1540,  1268,
   -1540,  1260,  1171,  1174,   444, -1540,  1192,  1346,   635,   635,
   11745,   481, -1540, -1540, 17288, -1540, -1540,  1339, 12377, -1540,
    1269,  1168, 18194,  1349,  1241,  1344, -1540,    20, 17288,  6057,
   17288,   851, -1540, -1540,  1376,   608, -1540, -1540, -1540, -1540,
    1291,   595, -1540, -1540, -1540,  1274, -1540,  7637,   869, -1540,
   -1540, 18194,   635, -1540, -1540, -1540, -1540, -1540, 11113,  1177,
   18194,  1355,  6057,    20, -1540, -1540,    20, 11113, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540,  1357, -1540, -1540,  1182,  1184,
   18194, -1540, -1540, 11113,  7637, 18194,  1185, 11113,  1186,   851,
   12377, -1540, 12377,  7637, -1540,  1277,  1187, 18194,  1251,  1366,
   18194,  1189, 12377, -1540
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       165,   473,   474,   818,   475,   168,   168,   168,     0,   841,
    1046,   120,   122,   647,   934,   943,   883,   846,   844,   820,
     935,   938,   890,   850,   821,   823,     0,   944,   825,   941,
     912,   892,   866,   822,   887,   888,   939,   936,   886,   827,
     942,   828,   829,   983,   995,   982,   884,   903,   897,   830,
     885,   832,   831,   984,   921,   922,   889,   863,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1029,
    1036,   911,   907,   898,   877,   819,     0,   906,   914,   923,
    1030,   902,   505,   878,   879,   937,  1031,  1037,   899,   916,
       0,   511,   462,   507,   909,   843,   900,   901,   930,   904,
     920,   929,  1035,  1038,   849,   891,   932,   506,   919,   925,
     824,   168,     0,     0,     0,   409,   917,   928,   933,   931,
     910,   896,   985,   894,   895,  1032,     0,   408,     0,  1033,
    1039,   926,   880,   905,  1044,  1034,   211,   440,     0,   472,
     927,   908,   915,   924,   918,   986,   871,   876,   875,   874,
     873,   872,   833,   893,     0,   842,  1045,   940,   864,  1041,
    1042,  1043,   976,   975,   977,   848,   847,   867,   974,   826,
     971,   979,   973,   972,   870,   913,   969,   981,   980,   968,
     868,   978,   990,   991,   988,   989,   987,   834,   992,   993,
     994,   960,   959,   946,   862,   855,   953,   949,   865,   861,
     961,     0,   851,   852,   845,   854,   958,   957,   954,   950,
     966,   967,   965,   956,   952,   945,   853,   964,   963,   857,
     859,   858,   951,   955,   947,   860,   948,   856,   962,  1016,
    1017,  1018,  1019,  1020,  1021,   997,   998,   996,  1002,  1003,
    1004,   999,  1000,  1001,   869,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,     0,     0,   835,   970,  1040,   837,   836,   838,
     839,   165,   165,     0,     2,   165,     9,    11,    23,     0,
      28,    31,    36,    37,    38,    39,    40,    41,    42,    32,
      58,    59,    33,    34,     0,    76,    79,    80,    35,    81,
      82,     0,   118,    83,    84,    85,    86,    18,   162,   163,
     164,   171,   174,   498,   175,     0,   176,   177,   178,   179,
     180,   181,   182,   185,   186,     0,   212,   220,   215,   249,
     255,     0,   247,     0,   248,   222,   216,   184,   217,   183,
     218,   221,   358,   360,   362,   364,   374,   376,   380,   382,
     385,   390,   393,   396,   398,   400,   402,     0,   406,   413,
     412,   414,     0,   431,   415,   436,   439,   441,   444,   446,
       0,   451,   448,     0,   459,   469,   471,   445,   476,   489,
     503,   490,   491,   492,   495,   496,   493,   497,   520,   521,
     494,   524,   526,   527,   528,   525,   573,   574,   575,   576,
     577,   578,   579,   468,   619,     0,   610,   618,   617,   616,
     615,   612,   614,   611,   613,   504,    43,   223,   224,   226,
     225,   227,   219,   500,   501,   502,   499,   229,   232,   228,
     230,   231,   470,   817,   840,   934,   943,   941,  1045,     0,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   280,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   464,   467,   454,     0,     0,   820,
     850,   823,   881,   944,   825,   892,   827,   903,   830,   832,
     831,   921,  1029,  1036,   819,  1030,   879,  1031,  1037,   904,
    1035,  1038,   928,   985,  1032,  1033,  1039,  1034,   986,   974,
     971,   973,   972,   868,   990,   991,   988,   834,   992,   882,
     852,   970,   460,   817,   452,     0,   192,   453,   456,   820,
     821,   823,   822,   827,   828,   829,   830,   819,   826,   508,
       0,   458,   457,     0,     0,   212,     0,   470,   825,   832,
     831,     0,   168,   795,   992,     0,   220,     0,   509,     0,
     540,     0,     0,   463,     0,   434,   435,     0,   466,   465,
     455,   438,     0,     0,   569,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   363,   797,     0,   799,     0,     0,
     165,     3,     4,     1,    10,    12,     0,     0,     0,     0,
       6,   165,     0,   165,     0,     0,   119,   172,     0,     0,
     190,     0,     0,   199,     0,     0,     0,     0,     0,     0,
     235,   236,     0,     0,   204,   233,     0,   254,   250,   256,
     251,   253,   252,   260,     0,     0,     0,     0,     0,     0,
       0,   425,     0,     0,   423,     0,   369,     0,   424,   417,
     422,   421,   420,   419,   418,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   411,   410,   407,     0,   168,   432,
     437,     0,     0,     0,   447,   486,   450,   449,   461,     0,
       0,     0,   477,     0,     0,     0,   581,   583,   587,   589,
       0,   124,     0,   816,    47,    44,    45,    48,    49,     0,
       0,     0,     0,    50,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   654,   655,   656,     0,   103,
     142,     0,     0,   112,     0,     0,     0,     0,   127,     0,
       0,   627,     0,     0,     0,   622,     0,     0,     0,   637,
       0,     0,   258,   263,     0,     0,   134,     0,   138,   168,
     523,     0,    60,     0,    69,     0,     0,     0,    61,     0,
       0,     0,     0,   625,     0,     0,   628,     0,     0,     0,
       0,   329,     0,     0,   626,     0,     0,     0,   645,     0,
       0,     0,     0,   631,     0,     0,   194,     0,     0,   188,
     187,     0,     0,   801,     0,     0,     0,     0,   508,     0,
     796,     0,   510,   541,   540,   537,     0,     0,     0,   571,
     570,   433,     0,   568,     0,   667,   668,     0,     0,     0,
       0,     0,   810,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   673,     0,   202,   203,     0,     0,     0,
       0,     0,   207,   208,   259,   798,   800,     0,     5,    24,
       0,    25,     0,     7,    29,     0,    15,     8,    30,     0,
      19,   934,    77,    16,    78,    20,   193,     0,   191,   213,
     214,     0,     0,     0,     0,   298,   205,   234,   237,   238,
     257,     0,     0,   359,   361,   367,   373,   372,   371,     0,
     368,   365,   366,     0,   377,   384,   383,   381,   387,   388,
     389,   386,   391,   392,   395,   394,     0,     0,     0,     0,
     416,     0,   442,   443,     0,   487,     0,   484,   485,   481,
     480,   516,   478,   518,     0,   620,   522,   514,     0,     0,
     121,   123,     0,     0,     0,   102,     0,    92,    94,    95,
      96,    97,    99,   100,   101,    93,    98,    88,    89,     0,
       0,   108,     0,   104,   106,   107,   114,     0,     0,    87,
      46,     0,     0,     0,     0,     0,     0,     0,   745,   750,
       0,     0,   746,   780,   733,   735,   736,   737,   739,   741,
     740,   738,   742,     0,     0,     0,     0,     0,   111,     0,
     144,     0,     0,   586,   580,   623,   624,     0,     0,   641,
       0,   638,     0,     0,     0,     0,     0,     0,     0,     0,
     140,     0,     0,   135,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,   279,   285,   282,     0,   630,   629,
     636,   644,     0,     0,     0,     0,   585,     0,     0,     0,
     426,     0,     0,     0,     0,   634,     0,   632,     0,   195,
       0,     0,   803,     0,   470,   802,     0,     0,     0,   540,
     538,     0,   529,     0,     0,   512,   513,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     0,
       0,   681,     0,   209,     0,     0,     0,     0,   165,     0,
     165,     0,   173,   246,     0,   313,   309,   311,     0,   306,
     299,   300,     0,     0,   239,   240,     0,   245,   370,     0,
       0,     0,     0,   711,   378,   684,   688,   690,   692,   694,
     697,   704,   705,   713,   944,   824,     0,   833,   837,   836,
     838,   839,   397,   592,   599,   600,   603,   648,   649,   604,
     605,   608,   399,   401,   404,   609,   403,   430,   488,   482,
       0,     0,   479,   515,   125,    56,    57,    54,    55,   131,
     130,     0,    90,     0,     0,     0,   109,   110,   115,    74,
      75,    52,    53,    73,   751,     0,   754,   781,     0,   744,
     743,   748,   747,   779,     0,     0,   756,     0,   752,   755,
     734,     0,     0,     0,     0,     0,     0,     0,   621,     0,
       0,     0,   143,   146,   148,     0,     0,     0,   113,   116,
       0,     0,     0,   168,     0,     0,   645,     0,     0,     0,
     265,     0,   591,     0,   266,     0,     0,     0,     0,     0,
       0,     0,   141,   136,   139,     0,   189,     0,     0,    71,
      65,    68,    67,     0,    63,   283,     0,     0,   168,     0,
     327,   331,     0,     0,     0,   334,     0,     0,   340,     0,
       0,   347,     0,   351,     0,   428,   427,   168,     0,     0,
     196,     0,   198,   328,     0,     0,     0,     0,     0,   541,
       0,   531,     0,   564,   561,     0,   565,   566,     0,     0,
     560,     0,   535,   563,   562,     0,     0,     0,     0,   660,
     661,   657,     0,     0,   665,   666,   662,   806,   807,   671,
     811,   669,     0,     0,     0,     0,   675,   825,   832,   831,
     992,   201,     0,     0,     0,   676,   677,     0,     0,   210,
     809,    26,     0,    17,    21,    22,   310,   322,     0,   323,
       0,   314,   315,   316,   317,     0,   508,     0,   307,     0,
       0,     0,   241,     0,     0,     0,     0,   292,     0,   289,
     294,   244,     0,     0,   695,   708,     0,   375,   379,     0,
     727,     0,     0,     0,     0,     0,     0,   683,   685,   686,
     722,   723,   724,   726,   725,     0,     0,   699,   698,     0,
     702,   706,   720,   718,   717,   710,   714,     0,     0,   595,
       0,     0,     0,     0,     0,     0,   596,   598,   597,   593,
     405,   483,   517,   519,   133,   132,    91,   105,   768,   749,
       0,   773,     0,   773,   762,   757,   147,   149,     0,     0,
       0,   117,   145,     0,    27,     0,   642,   643,   646,   639,
     640,   264,     0,     0,   278,   270,     0,   274,     0,   268,
       0,     0,     0,   137,     0,     0,    70,     0,    64,   284,
       0,     0,   330,   332,   337,     0,   335,     0,     0,     0,
       0,     0,   341,     0,     0,   355,     0,     0,   348,     0,
       0,   352,   429,     0,   635,   633,   197,   804,   805,     0,
       0,   540,     0,     0,   572,     0,   540,     0,   536,     0,
      14,     0,     0,     0,     0,     0,     0,     0,   674,     0,
       0,     0,     0,     0,     0,   678,   682,   326,   324,   325,
     318,   319,   320,   312,     0,     0,   308,   301,   287,     0,
       0,     0,   243,   290,   293,     0,   712,   703,   709,     0,
       0,   782,   783,   793,   792,   791,     0,     0,     0,     0,
     784,   689,   790,     0,   687,   691,     0,     0,   696,   700,
       0,   721,   716,   719,   715,     0,     0,   606,     0,   601,
     653,   594,   815,   814,   813,   602,   769,     0,     0,   767,
     774,   775,   771,     0,   766,     0,   764,     0,     0,     0,
       0,     0,     0,   582,   267,     0,   276,     0,     0,   272,
       0,   275,     0,     0,     0,    66,   286,   588,     0,     0,
     338,   342,   336,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   584,     0,     0,   540,     0,
     567,     0,   540,   590,   658,   659,   663,   664,     0,   670,
     812,   672,     0,     0,     0,     0,   679,   321,   302,     0,
     288,   296,   297,   291,   242,   707,   794,     0,     0,   786,
       0,   732,   731,   730,   729,   728,   693,     0,   785,     0,
     650,     0,     0,   778,   777,   776,     0,   770,   763,   761,
       0,   758,   759,   753,   150,   152,   154,     0,     0,     0,
       0,     0,   271,   269,     0,   277,   206,   357,    72,   333,
     339,     0,   356,   353,   349,     0,     0,     0,   343,     0,
       0,   345,     0,   550,   544,   539,     0,   540,   530,     0,
     808,     0,     0,     0,     0,   305,   303,     0,   788,   787,
       0,     0,   651,   607,     0,   772,   765,     0,     0,   156,
     155,     0,     0,     0,     0,   151,   273,     0,     0,     0,
       0,     0,   558,   552,     0,   551,   553,   559,   556,   546,
       0,   545,   547,   557,   532,     0,   533,     0,     0,   680,
     304,     0,   789,   701,   652,   760,   153,   157,     0,     0,
       0,     0,     0,     0,   346,   344,     0,     0,   543,   554,
     555,   542,   548,   549,   534,     0,   295,   158,     0,     0,
       0,   354,   350,     0,     0,     0,     0,     0,     0,     0,
       0,   160,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1540, -1540,  -236,  -208, -1540,  1221,  1222, -1540,  1223,  -565,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1024, -1540, -1540, -1540, -1540,  -248,  -598, -1540,   732,    -2,
   -1540, -1540, -1540, -1540, -1540,   274,   493, -1540, -1540,   -10,
    -170,  1053, -1540,  1051, -1540, -1540,  -654, -1540,   447, -1540,
     232, -1540,  -245,  -295, -1540,  -555, -1540,     7,    67,    34,
    -289,  -187, -1540,  -909, -1540, -1540,   203, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540,   618, -1540,   -55,
    1482,     0, -1540, -1540,  -239, -1540, -1540,   345, -1540, -1540,
    -311, -1540,    16, -1540, -1540,  -432,  -952,  -758,  -735, -1540,
   -1540,   701, -1540, -1540,   -79,   102, -1540, -1540, -1540,   112,
   -1539, -1540,   368,   120, -1540, -1540,   121, -1331, -1540,   963,
     215, -1540, -1540,   212, -1059, -1540, -1540,   213, -1540, -1540,
   -1281, -1267, -1540,   205, -1445, -1540, -1540,   853,  -152, -1540,
   -1540,  -577,   834, -1540, -1540,  -672,   365,  -663,   360,   362,
   -1540, -1540, -1540,   576, -1540, -1540,  1183, -1540, -1540, -1540,
   -1540, -1540,  -865,  -335,  -692, -1540,  -111, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540,   -13,  -835, -1540,  -548,   680,   272,
   -1540,  -434, -1540,   810, -1540, -1540, -1540, -1540, -1540,   801,
   -1540, -1540, -1540, -1540, -1043, -1540,   195, -1540,   687,  -816,
   -1540, -1540, -1540, -1540, -1540,  -278,  -271, -1213,  -829, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
    -774,  -876,  -195,  -877, -1540, -1540, -1540,  -711, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540,  1076,  1081,  -180,
     497,  -685, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
   -1540, -1540, -1540,   174, -1540, -1540,   161, -1540,   168, -1096,
   -1540, -1540, -1540,   116,   110,   -62,   386, -1540, -1540, -1540,
   -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540, -1540,
     124, -1540, -1540, -1540,   -54,   378,   530, -1540, -1540, -1540,
   -1540, -1540,   317, -1540, -1540, -1535, -1540, -1540, -1540,  -563,
   -1540,    82, -1540,   -74, -1540, -1540, -1540, -1540, -1350, -1540,
     132, -1540, -1540, -1540, -1540, -1540,   966, -1540, -1540, -1540,
   -1540, -1540,  -955,  -429,   979,   318, -1540
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   263,   642,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
    1289,   797,   281,   282,   283,   284,   285,   286,   987,   988,
     989,   287,   288,   289,   993,   994,   995,   290,   456,   291,
     292,   730,   293,   458,   459,   460,   470,   787,   788,   294,
    1252,   295,  1734,  1735,   296,   297,   298,   563,   299,   300,
     301,   302,   303,   790,   304,   305,   546,   306,   307,   308,
     309,   310,   311,   654,   312,   313,   882,   883,   314,   315,
     316,   576,   318,   655,  1671,   667,  1156,  1157,   319,   657,
     320,   659,   577,   322,   323,   782,   783,  1407,   477,   324,
     478,   479,   922,  1408,  1409,  1410,   660,   661,  1150,  1151,
    1398,   662,  1146,  1147,  1391,  1392,  1393,  1394,   325,   810,
     811,   326,  1304,  1305,  1517,   327,  1307,  1308,   328,   329,
    1310,  1311,  1312,  1313,  1524,   330,   331,   332,   333,   334,
     929,   335,   336,  1417,   337,   338,   339,   340,   341,   342,
     343,   344,   345,  1193,   346,   347,   348,   349,   685,   686,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   722,   715,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   964,
     377,   378,   379,   380,   381,   382,  1341,   844,   845,   846,
    1765,  1810,  1811,  1804,  1805,  1812,  1806,  1342,  1343,   383,
     384,  1344,   385,   386,   387,   388,   389,   390,   391,   392,
    1049,  1525,  1459,  1183,  1618,  1184,  1194,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   817,
    1265,   405,  1186,  1187,  1188,  1189,   406,   407,   408,   409,
     410,   411,   872,   873,   412,  1375,  1376,  1696,  1132,  1164,
    1427,  1428,  1165,  1166,  1167,  1168,  1169,  1437,  1608,  1609,
    1170,  1440,  1171,  1589,  1172,  1173,  1445,  1446,  1614,  1612,
    1429,  1430,  1431,  1432,  1714,   759,  1014,  1015,  1016,  1017,
    1018,  1019,  1238,  1638,  1731,  1239,  1636,  1729,  1020,  1473,
    1633,  1629,  1630,  1631,  1021,  1022,  1433,  1441,  1599,  1434,
    1595,  1418,   413,   414,   415,   416,   566,   417,   418,   419,
     420,   421,  1190,  1290,   422,   423,   424
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -883;
  const short int
  jsoniq_parser::yytable_[] =
  {
       317,   612,   731,   731,   457,   317,   317,   317,   317,   734,
     658,   637,   429,   432,   433,   950,   321,   709,  1306,   937,
     629,   321,   321,   321,   321,  1063,  1047,   591,  1101,   938,
     939,   940,   941,   632,   958,   902,   904,  1294,  1075,   431,
     431,   431,   435,  1528,   794,   798,  1131,  1540,   634,  1048,
     862,   614,  1089,   621,   622,   869,   630,   575,   579,   630,
    1340,  1571,  1572,   542,  1413,  1210,   894,   898,  1162,  1254,
    1182,  1192,   430,   430,   430,   434,   896,   900,   903,   905,
    1241,  1669,   656,  1278,  1673,  1242,   773,   974,  1043,  1610,
    1270,  1737,  1596,   925,  1243,   926,   927,   593,   928,  1153,
     930,  1244,  1732,  1245,   774,    11,    12,   630,   931,   932,
     630,   317,  1246,  1215,   733,   438,   439,  1124,   440,   441,
     630,   636,   849,    11,    12,   442,   630,   321,  1548,   630,
     630,   630,    11,    12,   630,   443,   444,  1275,   630,  1247,
     630,   630,   637,   442,  1045,   564,   637,  1044,   630,  1045,
     630,   630,   442,   445,   596,   630,   597,   630,   446,  1775,
    1627,   630,   443,   641,   630,  1518,   641,   630,  1272,  1763,
    1470,   445,  1377,   630,  1707,  1283,  -169,   630,   430,   897,
     445,   884,   743,   438,   439,   446,   440,   441,  1591,   689,
     447,   448,   449,  1333,  1334,  1711,  1279,   616,   618,  1388,
     604,  1046,  1712,  1738,   444,   605,   690,   650,   630,   765,
     651,  1137,  1713,   475,   641,  1256,   744,   447,   448,  1141,
    1596,  1390,  1218,  1296,  1257,  1628,   832,   641,  1592,  1378,
     691,  1472,  1666,   641,   920,  1185,  1185,  1820,   641,  1697,
     450,   641,   630,   598,   710,   638,   793,   641,  1521,   630,
    1125,   650,  1825,  1708,   651,   641,   630,  1597,   641,  1764,
    1382,   317,   317,  1154,   641,   317,   658,   476,   641,  1508,
     630,   641,  1248,  1528,   641,   637,  1282,   321,   321,  1185,
     641,   321,   594,  1330,   641,  1739,  1730,   636,  1335,  1340,
     850,  1280,   840,   902,   904,  1162,  1162,   630,  1340,  1450,
     317,   631,  1465,  1155,   451,  1254,  1797,   842,   450,  1336,
    1037,  1337,  1276,  1253,  1281,   641,   321,  1491,  1055,  1588,
     633,   889,  1211,  1000,   894,   898,   476,  1077,  1297,   891,
    1548,   476,  1138,  1185,    13,  1078,  1198,  1450,   841,  1338,
    1185,  1140,    13,   114,  1128,   452,  1381,   716,  1326,   641,
     718,  1327,  1158,  1833,  1328,  1836,   641,  1118,   476,   126,
    1461,  -169,   630,   641,  1249,  1250,  1251,   916,  1060,  -170,
     630,   453,   451,   476,   886,   885,   638,   641,  1401,   454,
     638,  1339,   630,   895,   899,  1597,  1598,   455,   639,   766,
     689,  1500,   890,   892,   543,  1771,   969,   767,   453,   154,
     831,   436,   907,   630,   641,  1789,   454,   690,   543,  1503,
     490,   778,   888,   452,   455,    82,   791,   599,  1109,   600,
    1107,  1044,   602,    82,   785,   630,   804,  1072,   437,  1772,
      93,   317,   543,   815,   816,   317,  1773,  1456,    93,   969,
    1067,  1122,   822,  1072,   543,   630,   543,   321,  1044,  1333,
    1334,   321,  1403,   773,  1083,   107,   461,  1404,  1003,  1827,
    1004,   708,   317,   107,   317,  1185,   464,  1159,  1457,   641,
    1160,   774,   640,   733,   696,  1074,   970,   641,   321,  1108,
     321,  1104,   630,   697,   128,  1481,   317,  1458,   491,   641,
     128,   317,  1818,   786,  1333,  1045,   435,  1062,   435,  1163,
    1340,   719,   321,  1185,  1005,  1711,   601,   321,  1073,   638,
     641,   603,  1712,  1493,  1808,   832,  1117,   924,  1419,   971,
     435,   476,  1713,  1113,  1091,   435,   847,   848,  1466,   770,
    1123,   772,   641,    11,    12,  1204,   720,   852,   721,  1131,
     902,   904,   902,  1566,  1335,  1501,  1105,  1110,  1111,  1253,
    1162,  1528,   641,   813,  -170,   878,   880,   795,   819,  1162,
     492,   493,  1112,  1478,   317,  1336,  1106,  1337,  1219,  1220,
    1162,  1617,   317,  1223,  1185,  1363,   749,  1161,   750,   698,
     321,  1038,  1802,  1383,  1384,  1385,  1333,  1130,   321,   641,
     637,  1420,   833,   699,  1040,  1338,   775,  1052,  1185,   114,
     952,   953,  1044,  1262,  1333,   796,   431,  1695,  1044,  1586,
    1336,   317,  1337,  1802,   724,   126,   457,  1333,  1142,   635,
     317,  1809,  1575,  1557,  1808,   725,  1084,   321,  1102,  1819,
    1748,   317,   317,   317,   317,   465,   321,  1542,   752,   430,
    1338,  1135,  1045,   485,  1045,   879,  1670,   321,   321,   321,
     321,  1088,  1114,  1115,  1086,   154,   317,  1201,   954,  1139,
    1006,  1039,  1400,   892,  1378,   954,  1823,  1116,  1201,  1721,
    1044,  1419,   321,  1007,  1041,  1008,  1726,  1053,   543,  1421,
    1422,   543,  1423,   749,  1331,   750,  1009,  1010,  1011,  1424,
    1012,   468,  1013,  -261,  1492,  1103,  1647,   469,  1762,  1425,
     753,   644,  1336,   545,  1337,   645,  1085,   613,   317,  -262,
     646,  1426,  1803,  1521,   650,   951,   692,   651,   751,  1574,
    1336,   471,  1337,    13,   321,  1677,  1163,  1163,  1229,   647,
    1681,  1842,  1338,  1336,  1087,  1337,  1185,  1202,  1235,  1230,
    1648,  1162,   431,  1839,  1420,   752,   693,  1415,  1203,  1722,
    1338,  1332,  1333,  1334,  1603,  1236,  1727,  -261,   480,   694,
     741,   543,  -261,  1338,   543,   663,   650,   494,   543,   651,
     128,   543,   543,  -262,   897,   430,   739,   483,  -262,   543,
    1096,  1097,  1098,   902,   880,   543,   543,  1333,  1334,   317,
    1752,  1642,   740,   543,   695,   689,  1054,  1303,  1303,  1237,
     543,   543,   543,   543,    82,   321,  1136,   753,   543,  -261,
    1515,  1520,   690,  1470,  1120,  1185,   543,   472,  1185,    93,
     317,   317,   627,   431,  1129,  -262,   473,   709,   648,   664,
    1471,   649,  1421,  1422,   665,  1423,   321,   321,   906,  1371,
     719,   990,   908,  1782,   107,  1783,   650,  1335,  1159,   651,
    1235,  1160,  1425,   474,   435,   435,   430,   719,  1264,  1506,
    1267,   735,  1766,   543,  1426,   484,  1769,  1236,  1336,   689,
    1337,   128,  1231,   652,  1472,   720,   736,   721,   543,   317,
     626,   666,  1335,  1232,  1205,   991,   690,  1081,  1082,   543,
     992,   457,   720,   907,   721,   321,   627,  1207,  1338,   892,
    1206,  1200,   114,  1336,  1318,  1337,  1319,   317,  1824,  1387,
    1780,   495,   496,  1208,  1403,   488,   863,  1044,   126,  1404,
    1388,   863,   653,   321,   543,  1709,  1710,  1706,  1209,  1388,
    1389,   543,  1464,  1338,  1807,  1813,   544,   114,  1405,   737,
    1547,   670,  1390,   497,   789,  1379,   498,  1736,   789,   671,
     672,  1815,   673,   126,   738,  1185,  1526,  1045,   154,  1567,
     674,  1347,  1790,  1348,   675,  1529,   676,  1526,  1576,  1527,
    1526,   677,   763,  1442,  1443,  1679,  1807,   764,  1530,  1406,
    1676,  1163,  1813,  1845,   543,  1212,   955,   678,  1593,   955,
    1163,   711,   712,   154,   955,  1594,  1444,  1212,  1504,   462,
     466,  1163,   463,   467,   991,  1224,  1225,  1226,  1185,   992,
    1185,  1227,   679,   680,   681,   682,   683,   684,   977,   978,
     979,   980,   981,   982,   983,   984,   985,   986,  1403,   481,
     489,   486,   482,  1404,   487,  1778,  1779,   543,   650,   714,
    1185,   651,   717,   755,   756,   757,  1352,   547,  1353,  1736,
    1221,  1222,  1568,  1569,   935,   936,   942,   943,  1476,  1477,
     944,   945,   658,   976,  1723,  1724,   543,  1519,   548,   559,
     560,   561,   562,  1185,   581,   595,   582,   583,  1655,   317,
     543,   588,   589,   590,   543,   543,   592,  1185,  -621,  1185,
     567,   606,   610,   580,   609,   321,  1736,   607,   611,   608,
     619,   623,   643,   543,  1412,   584,   668,   587,  1822,   669,
     688,   543,   687,   435,   543,   700,   701,   702,   543,   707,
     703,   713,   723,   733,   726,   727,  1559,   457,  1372,   745,
     728,   729,   747,   748,  1563,   758,   762,   771,   317,   317,
     317,   789,   792,   800,  1373,   801,  1314,   802,   803,   814,
     820,   821,   463,   827,   321,   321,   321,   467,   482,   831,
     487,   543,   498,   834,   835,   829,   836,   839,  1864,   837,
    1865,   843,  1163,   851,   854,   875,   876,   881,   853,   871,
    1873,   893,   911,   612,   913,   918,   919,   912,   921,   933,
     914,   946,   947,   948,   949,   965,   966,   972,   973,   543,
     975,  1001,  1002,   997,   998,  1024,  1025,  1023,  1027,  1032,
    1029,  1033,  1034,  1035,  1042,  1051,  1036,  1058,  1057,  1061,
    1068,  1069,  1070,  1071,  1119,  1079,   462,  1126,  1076,   543,
    1661,  1080,   466,   481,   486,   497,  1121,  1134,  1137,   543,
    1127,  1197,  1213,  1044,  1144,  1233,   992,  1260,  1234,  1263,
    1273,   785,  1271,  1255,  1277,  1261,  1285,  1287,  1288,  1286,
    1292,  1293,  1291,   317,   543,   543,   543,   543,  1298,  1299,
    1485,  1315,  1303,  1316,   916,  1309,  1658,  1302,  1659,   321,
    1317,  1663,  1664,  1321,  1322,  1667,  1324,   317,  1325,  1329,
    1345,  1674,  1346,   751,  1364,  1374,  1395,   431,   317,  1397,
    1447,  1399,  1435,   321,  1439,  1511,    13,  1402,   543,  1448,
    1469,  1451,  1416,  1452,   321,  1436,  1453,   317,  1454,  1460,
    1455,  1468,   543,  1474,  1533,  1484,  1486,  1488,  1483,  1496,
     430,  1487,   431,   321,  1480,  1489,  1498,  1490,   317,  1502,
    1507,  1510,  1532,  1479,  1526,   317,  1539,   543,  1541,  1544,
    1551,   431,  1555,  1552,   321,  1534,   543,  1535,   543,  1556,
     543,   321,   543,  1746,  1560,   430,  1553,  1561,  1550,   543,
    1562,  1377,   435,  1554,  1750,  1661,  1388,  1372,  1753,   435,
    1579,  1585,  1580,  1581,   430,  1761,  1587,  1606,  1611,  1613,
    1619,  1607,  1620,  1373,  1626,  1632,  1590,  1637,  1621,  1622,
    1639,  1600,   543,  1652,   543,  1545,  1623,  1624,  1625,  1643,
    1645,   879,  1549,  1653,  1635,  1650,  1654,  1641,  1657,  1675,
    1680,  1683,   742,  1699,  1705,   746,  1688,  1717,  1719,   754,
    1756,  1728,   760,   761,  1760,  1720,  1235,  1733,  1741,  1744,
     769,   863,  1751,  1768,  1777,  1718,   781,   784,  1784,  1785,
    1786,  1787,  1788,  1792,   799,  1798,  1793,  1800,  1814,  1740,
    1817,   807,   808,   809,   812,  1821,   543,  1816,  1830,   818,
    1838,  1753,  1831,  1844,  1850,  1841,  1855,   825,  1866,  1828,
    1867,  1856,  1869,   999,  1216,  1870,   624,   625,  1848,  1467,
     732,   628,  1482,  1826,   543,  1857,  1795,  1860,  1862,  1284,
    1133,  1872,  1411,  1066,  1703,  1692,  1693,  1694,   768,  1584,
    1834,  1577,  1386,  1570,  1512,  1573,  1516,  1531,  1799,   317,
    1522,   923,   934,   828,   826,  1196,   968,  1543,  1504,   957,
     706,  1100,   543,  1843,  1840,   321,  1565,  1268,  1558,   812,
    1601,   776,  1564,  1851,  1716,  1605,   777,  1414,  1438,  1715,
     838,   567,  1604,  1240,  1475,  1634,  1725,  1602,  1832,     0,
       0,     0,  1837,  1372,     0,  1851,     0,   867,     0,     0,
       0,     0,     0,     0,  1834,     0,     0,     0,     0,  1373,
     567,     0,     0,     0,     0,   874,     0,   543,     0,     0,
       0,   543,   784,   565,  1853,     0,     0,  1854,     0,     0,
       0,     0,     0,   543,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   543,     0,     0,
    1863,     0,     0,     0,     0,     0,     0,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1774,     0,     0,     0,     0,   784,     0,     0,     0,     0,
       0,     0,  1372,     0,     0,     0,     0,   543,     0,     0,
       0,     0,  1781,  1372,  1372,     0,     0,   317,  1373,     0,
       0,     0,     0,     0,  1372,     0,     0,     0,     0,  1373,
    1373,     0,   543,   321,     0,     0,     0,     0,     0,     0,
    1373,     0,   543,     0,     0,     0,   543,     0,   959,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   543,     0,     0,   996,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1026,     0,     0,     0,  1030,  1031,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1372,     0,     0,     0,  1050,   543,     0,     0,     0,     0,
       0,     0,  1056,     0,     0,  1059,  1373,     0,     0,  1064,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   543,     0,   317,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1094,     0,     0,     0,   321,     0,  1372,     0,     0,
       0,     0,  1099,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   317,  1373,     0,     0,     0,     0,     0,     0,
       0,   543,     0,     0,   543,     0,     0,   543,   321,     0,
       0,     0,     0,     0,  1372,     0,     0,     0,     0,     0,
     543,     0,     0,  1372,     0,   543,     0,     0,     0,     0,
    1373,     0,     0,     0,     0,     0,     0,     0,     0,  1373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1143,     0,     0,     0,     0,     0,     0,     0,   543,   543,
    1152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1191,  1191,  1195,  1195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1228,   543,     0,   543,     0,   543,     0,
     543,     0,     0,     0,     0,     0,     0,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1259,     0,
       0,     0,     0,     0,     0,     0,     0,  1266,     0,  1266,
       0,   784,     0,  1191,     0,     0,     0,     0,     0,     0,
    1191,     0,     0,     0,     0,     0,     0,   543,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   565,   543,     0,     0,   543,     0,
       0,     0,     0,   818,     0,   818,     0,     0,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,   855,   856,
     543,   864,   865,   866,   868,     0,   870,     0,     0,     0,
       0,   877,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   887,   543,     0,     0,     0,     0,     0,     0,     0,
     543,     0,     0,     0,     0,     0,   543,     0,   543,     0,
       0,     0,     0,   909,   910,     0,     0,  1396,     0,     0,
       0,     0,     0,     0,   915,     0,     0,     0,   917,   543,
       0,     0,     0,     0,     0,     0,     0,     0,   543,     0,
       0,     0,     0,     0,     0,  1191,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   543,     0,
       0,     0,     0,   543,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   543,     0,     0,   543,     0,
       0,     0,     0,  1191,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   963,     0,     0,     0,   963,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1028,     0,   784,     0,
       0,     0,  1494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   812,     0,
       0,     0,     0,  1065,     0,     0,     0,     0,  1191,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1090,
       0,     0,     0,  1092,  1093,     0,  1095,     0,  1546,     0,
       0,     0,     0,   917,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   874,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1583,     0,     0,     0,   910,
       0,     0,     0,     0,     0,  1145,  1149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1665,     0,     0,  1191,     0,     0,  1191,  1258,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1678,     0,     0,     0,     0,  1682,     0,  1274,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1300,  1301,     0,     0,  1701,
    1702,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1320,     0,     0,  1323,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1349,  1350,  1351,     0,  1354,  1355,  1356,  1357,
    1358,  1359,  1360,  1361,  1362,     0,     0,  1365,  1366,     0,
       0,     0,     0,     0,     0,     0,  1380,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1191,     0,  1755,     0,  1757,
       0,  1759,     0,     0,     0,     0,     0,     0,  1767,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1191,     0,
    1191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1791,     0,     0,  1794,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1801,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1495,     0,  1497,
       0,  1499,     0,  1191,     0,     0,     0,     0,     0,  1505,
       0,  1829,     0,     0,     0,     0,     0,  1191,  1509,  1191,
       0,     0,     0,     0,  1513,  1514,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1846,     0,     0,  1536,     0,     0,  1537,  1538,     0,  1849,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1858,
       0,     0,     0,     0,  1859,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1868,     0,     0,  1871,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1145,     0,     0,
       0,  1149,  1578,     0,     0,     0,     0,  1582,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1644,     0,     0,     0,  1646,     0,
       0,     0,  1649,     0,  1651,     0,     0,     0,     0,     0,
       0,     0,  1656,     0,     0,     0,     0,     0,     0,     0,
    1660,  1662,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1505,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1684,  1685,  1686,  1687,     0,  1689,  1690,
       0,  1691,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1698,     0,     0,     0,
       0,  1700,     0,     0,     0,     0,     0,  1704,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1742,     0,  1743,
       0,     0,  1745,     0,     0,  1747,     0,     0,     0,     0,
    1749,  1662,     0,     0,     0,     0,     0,     0,     0,  1754,
       0,     0,     0,  1758,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1770,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1776,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1796,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1754,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1835,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -165,   897,     0,     0,     0,     0,
    1847,     0,     0,     0,  1852,     1,     2,     0,     0,  1835,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,  1852,     0,    14,   426,  1861,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   254,   255,   256,   257,   258,   259,
     260,  -165,   897,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   901,   426,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     427,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   137,   138,     0,   139,     0,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,   152,   153,   154,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     0,   202,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   897,   253,
       0,   254,   255,   256,   257,   258,   259,   260,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     425,   426,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   427,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     137,   138,     0,   139,     0,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     0,     0,
     152,   153,   154,     0,   155,   428,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     0,   202,   203,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   897,   253,     0,   254,   255,   256,
     257,   258,   259,   260,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   425,   426,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   568,   427,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,   569,   570,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   516,    85,    86,    87,
      88,    89,   571,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   572,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,   135,     0,   137,   138,     0,   139,
       0,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,   152,   153,   154,     0,
     155,   428,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   534,   535,   536,
     185,   186,   537,   574,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     0,   202,   203,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,     0,   254,   255,   256,   257,   258,   259,   260,
    -881,   468,     0,  -261,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -881,     0,     0,     0,  -881,     0,     0,     0,
    -881,  -881,     0,     0,     0,     0,  -881,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -261,     0,     0,
    -881,     0,  -261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -881,     0,  -881,  -881,  -881,     0,     0,
    -881,  -881,  -881,  -881,     0,     0,     0,  -881,  -881,     0,
       0,     0,     0,     0,  -881,     0,     0,  -881,  -881,  -261,
       0,     0,     0,  -881,     0,     0,     0,     0,  -881,  -881,
       0,     0,     0,     0,  -881,     0,     0,     0,  -881,     0,
       0,     0,  -881,  -881,     0,  -881,     0,  -881,  -881,     0,
       0,     0,  -881,  -881,     0,     0,  -881,  -881,  -881,  -881,
    -881,  -881,     0,     0,  -881,     0,     0,     0,  -881,  -881,
       0,     0,  -881,     0,     0,     0,     0,  -881,     0,     0,
    -881,     0,     0,     0,     0,  -881,  -881,  -881,  -881,  -881,
    -881,     0,  -881,  -881,  -881,  -881,  -881,     0,     0,     0,
       0,  -881,  -881,  -881,     0,  -881,  -881,  -881,  -881,  -881,
    -881,     0,  -881,     0,  -881,     0,     0,     0,     0,     0,
    -881,     0,     0,     0,  -881,  -881,     0,  -882,   613,     0,
    -262,     0,     0,     0,     0,     0,     0,     0,     0,  -881,
       0,  -881,     0,  -881,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -881,     0,     0,     0,     0,
    -881,     0,     0,  -881,     0,     0,     0,     0,     0,  -882,
       0,     0,     0,  -882,     0,     0,     0,  -882,  -882,     0,
       0,     0,     0,  -882,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -262,     0,     0,  -882,     0,  -262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -881,     0,  -881,
    -882,     0,  -882,  -882,  -882,     0,     0,  -882,  -882,  -882,
    -882,     0,     0,     0,  -882,  -882,     0,     0,     0,     0,
       0,  -882,     0,     0,  -882,  -882,  -262,     0,     0,     0,
    -882,     0,     0,     0,     0,  -882,  -882,     0,     0,     0,
       0,  -882,     0,     0,     0,  -882,     0,     0,     0,  -882,
    -882,     0,  -882,     0,  -882,  -882,     0,     0,     0,  -882,
    -882,     0,     0,  -882,  -882,  -882,  -882,  -882,  -882,     0,
       0,  -882,     0,     0,     0,  -882,  -882,     0,     0,  -882,
       0,     0,     0,     0,  -882,     0,     0,  -882,     0,     0,
       0,     0,  -882,  -882,  -882,  -882,  -882,  -882,     0,  -882,
    -882,  -882,  -882,  -882,     0,     0,     0,     0,  -882,  -882,
    -882,     0,  -882,  -882,  -882,  -882,  -882,  -882,     0,  -882,
       0,  -882,     0,     0,     0,     0,     0,  -882,     0,     0,
       0,  -882,  -882,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -882,     0,  -882,     0,
    -882,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -882,     0,     0,     0,     0,  -882,     0,     0,
    -882,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,  -882,    13,  -882,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   137,   138,
       0,   139,     0,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,     0,   152,   153,
     154,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     202,   203,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,     0,   254,   255,   256,   257,   258,
     259,   260,   261,   262,     1,     2,     0,     0,     0,     3,
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
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   137,   138,     0,   139,
       0,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,   152,   153,   154,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     0,   202,   203,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,     0,   254,   255,   256,   257,   258,   259,   260,
       0,   620,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   425,   426,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     427,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,   830,     0,   132,     0,
     133,   134,   135,   136,   137,   138,     0,   139,     0,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,   152,   153,   154,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     0,   202,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
       0,   254,   255,   256,   257,   258,   259,   260,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     425,   426,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   427,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     137,   138,     0,   139,     0,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     0,     0,
     152,   153,   154,     0,   155,   428,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     0,   202,   203,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,   253,     0,   254,   255,   256,
     257,   258,   259,   260,     1,     2,     0,     0,     0,     3,
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
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,   135,   136,   137,   138,     0,   139,
       0,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,   152,   153,   154,     0,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     0,   202,   203,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,     0,   254,   255,   256,   257,   258,   259,   260,
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
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   137,   138,     0,   139,     0,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,     0,   152,   153,   154,     0,   155,   428,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,     0,   202,   203,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,     0,   254,
     255,   256,   257,   258,   259,   260,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,    14,   426,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,   135,   136,   137,   138,
       0,   139,     0,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,     0,   152,   153,
     154,     0,   155,   428,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     202,   203,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,     0,   254,   255,   256,   257,   258,
     259,   260,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   901,   426,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     427,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,   135,   136,   137,   138,     0,   139,     0,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,   152,   153,   154,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     0,   202,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
       0,   254,   255,   256,   257,   258,   259,   260,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     425,   426,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,  1367,   427,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
    1368,  1369,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     137,   138,     0,   139,     0,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     0,     0,
     152,   153,   154,     0,   155,   428,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,  1370,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     0,   202,   203,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,   253,     0,   254,   255,   256,
     257,   258,   259,   260,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   425,   426,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   568,   427,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,   569,   570,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   516,    85,    86,    87,
      88,    89,   571,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,   961,
       0,   104,   105,   106,   107,   108,   109,   110,   572,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,   962,   133,   134,   135,     0,   137,   138,     0,   139,
       0,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,   152,   153,   154,     0,
     155,   428,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   534,   535,   536,
     185,   186,   537,   574,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     0,   202,   203,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,     0,   254,   255,   256,   257,   258,   259,   260,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   425,   426,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   568,   427,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,   569,   570,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   516,    85,    86,    87,    88,    89,   571,    91,
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,   961,     0,   104,   105,   106,
     107,   108,   109,   110,   572,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,   967,   133,   134,
     135,     0,   137,   138,     0,   139,     0,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,     0,   152,   153,   154,     0,   155,   428,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   534,   535,   536,   185,   186,   537,   574,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,     0,   202,   203,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,     0,   254,
     255,   256,   257,   258,   259,   260,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   425,   426,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   568,   427,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   569,   570,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   516,    85,
      86,    87,    88,    89,   571,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     572,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,   573,   132,     0,   133,   134,   135,     0,   137,   138,
       0,   139,     0,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,     0,   152,   153,
     154,     0,   155,   428,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   534,
     535,   536,   185,   186,   537,   574,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     202,   203,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,     0,   254,   255,   256,   257,   258,
     259,   260,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   425,   426,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   568,
     427,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   569,   570,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   516,    85,    86,    87,    88,    89,
     571,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   572,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,   578,
     133,   134,   135,     0,   137,   138,     0,   139,     0,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,   152,   153,   154,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   534,   535,   536,   185,   186,
     537,   574,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     0,   202,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
       0,   254,   255,   256,   257,   258,   259,   260,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     425,   426,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   568,   427,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     569,   570,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     516,    85,    86,    87,    88,    89,   571,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   572,   112,     0,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   127,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,   135,     0,
     137,   138,     0,   139,     0,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     0,     0,
     152,   153,   154,     0,   155,   428,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   534,   535,   536,   185,   186,   537,   574,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     0,   202,   203,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   615,   253,     0,   254,   255,   256,
     257,   258,   259,   260,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   425,   426,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   568,   427,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,   569,   570,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   516,    85,    86,    87,
      88,    89,   571,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   572,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,   135,     0,   137,   138,     0,   139,
       0,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,   152,   153,   154,     0,
     155,   428,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   534,   535,   536,
     185,   186,   537,   574,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     0,   202,   203,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,   617,   254,   255,   256,   257,   258,   259,   260,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   425,   426,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   568,   427,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,    48,
      49,    50,   569,   570,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   516,    85,    86,    87,    88,    89,   571,    91,
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   572,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,   960,   132,     0,   133,   134,
     135,     0,   137,   138,     0,   139,     0,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,     0,   152,   153,   154,     0,   155,   428,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   534,   535,   536,   185,   186,   537,   574,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,     0,   202,   203,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,     0,   254,
     255,   256,   257,   258,   259,   260,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   425,   426,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   568,   427,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   569,   570,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   516,    85,
      86,    87,    88,    89,   571,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     572,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,  1199,   133,   134,   135,     0,   137,   138,
       0,   139,     0,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,     0,   152,   153,
     154,     0,   155,   428,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   534,
     535,   536,   185,   186,   537,   574,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     202,   203,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,     0,   254,   255,   256,   257,   258,
     259,   260,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   425,   426,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   568,
     427,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   569,   570,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   516,    85,    86,    87,    88,    89,
     571,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,  1462,     0,   104,
     105,   106,   107,   108,   109,   110,   572,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,   135,     0,   137,   138,     0,   139,     0,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,   152,   153,   154,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   534,   535,   536,   185,   186,
     537,   574,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     0,   202,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
       0,   254,   255,   256,   257,   258,   259,   260,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     425,   426,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   502,    27,   504,   427,    30,   505,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   507,     0,    48,    49,    50,
     509,   510,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     516,    85,    86,    87,    88,    89,   571,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   519,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   572,   112,     0,   113,   114,   704,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,   705,   128,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,   135,     0,
     137,   138,     0,   139,     0,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     0,     0,
     152,   153,   154,     0,   155,   428,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   529,   169,   530,
     171,   531,   532,   174,   175,   176,   177,   178,   179,   533,
     181,   534,   535,   536,   185,   186,   537,   538,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     539,     0,   202,   540,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,   253,     0,   254,   541,   256,
     257,   258,   259,   260,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   425,   426,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   568,   427,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,   569,   570,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   516,    85,    86,    87,
      88,    89,   571,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   572,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,   135,     0,   137,   138,     0,   139,
       0,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,   152,   153,   154,     0,
     155,   428,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   534,   535,   536,
     185,   186,   537,   574,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     0,   202,   203,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,     0,   254,   255,   256,   257,   258,   259,   260,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   425,   426,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   502,    27,   504,   427,    30,
     505,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,   507,     0,    48,
      49,    50,   509,   510,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   516,    85,    86,    87,    88,    89,   571,    91,
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   519,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   572,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
     135,     0,   137,   138,     0,   139,     0,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,     0,   152,   153,   154,     0,   155,   428,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   529,
     169,   530,   171,   531,   532,   174,   175,   176,   177,   178,
     179,   533,   181,   534,   535,   536,   185,   186,   537,   538,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   539,     0,   202,   203,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,     0,   254,
     541,   256,   257,   258,   259,   260,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   425,   426,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   502,    27,   504,   427,    30,   505,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   507,     0,    48,    49,    50,   509,   510,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   516,    85,
      86,    87,    88,    89,   571,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   519,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     572,   112,     0,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,   127,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,   135,     0,   137,   138,
       0,   139,     0,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,     0,   152,   153,
     154,     0,   155,   428,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   529,   169,   530,   171,   531,
     532,   174,   175,   176,   177,   178,   179,   533,   181,   534,
     535,   536,   185,   186,   537,   538,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   539,     0,
     202,   540,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,     0,   254,   541,   256,   257,   258,
     259,   260,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   425,   426,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   568,
     427,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   569,   570,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   516,    85,    86,    87,    88,    89,
    1148,    91,     0,    92,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   572,   112,     0,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   126,     0,   127,   128,
       0,     0,   129,   130,   131,     0,     0,     0,   132,     0,
     133,   134,   135,     0,   137,   138,     0,   139,     0,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,     0,   152,   153,   154,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   534,   535,   536,   185,   186,
     537,   574,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     0,   202,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,   253,
       0,   254,   255,   256,   257,   258,   259,   260,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     425,   426,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   502,    27,   504,   427,    30,   505,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   507,     0,    48,    49,    50,
     509,   510,    53,   511,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     516,    85,    86,    87,    88,    89,   571,    91,     0,    92,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   519,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   572,   112,     0,   113,   114,     0,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,     0,   126,     0,     0,     0,     0,     0,   129,   130,
     131,     0,     0,     0,   132,     0,   133,   134,   135,     0,
     137,   138,     0,   139,     0,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     0,     0,
     152,   153,   154,     0,   155,   428,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   529,   169,   530,
     171,   531,   532,   174,   175,   176,   177,   178,   179,   533,
     181,   534,   535,   536,   185,   186,   537,   538,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     539,     0,   202,   540,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,   253,     0,   254,   541,   256,
     257,   258,   259,   260,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   425,   426,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   502,
      27,   504,   427,    30,   505,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,   507,     0,    48,    49,    50,   509,   510,    53,   511,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   516,    85,    86,    87,
      88,    89,   571,    91,     0,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     519,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   572,   112,
       0,   113,   114,     0,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,   135,     0,     0,     0,     0,   139,
       0,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,     0,   152,   153,   154,     0,
     155,   428,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   529,   169,   530,   171,   531,   532,   174,
     175,   176,   177,   178,   179,   533,   181,   534,   535,   536,
     185,   186,   537,   538,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   539,     0,   202,   540,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,   253,     0,   254,   541,   256,   257,   258,   259,   260,
       1,     2,     0,     0,     0,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   425,   426,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   502,    27,   504,   427,    30,
     505,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,   507,     0,    48,
      49,    50,   509,   510,    53,   511,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,    75,    76,     0,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
      82,    83,   516,    85,    86,    87,    88,    89,   571,    91,
       0,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   519,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,     0,   109,   110,   572,   112,     0,   113,   114,     0,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,     0,     0,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
     135,     0,     0,     0,     0,   139,     0,   140,     0,   141,
       0,   143,     0,   145,   146,   147,   148,   149,   150,   151,
       0,     0,   152,   153,   154,     0,   155,   428,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   529,
     169,   530,   171,   531,   532,   174,   175,   176,   177,   178,
     179,   533,   181,   534,   535,   536,   185,   186,   537,   538,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   539,     0,   202,   540,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,   253,     0,   254,
     541,   256,   257,   258,   259,   260,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   425,   426,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   502,    27,   504,   427,    30,   505,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   507,     0,    48,    49,    50,   509,   510,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   516,    85,
      86,    87,    88,     0,   571,    91,     0,    92,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   519,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   105,   106,   107,     0,   109,   110,
     572,     0,     0,     0,   114,     0,     0,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   125,     0,
     126,     0,     0,   128,     0,     0,   129,   130,   131,     0,
       0,     0,   132,     0,   133,   134,   135,     0,     0,     0,
       0,     0,     0,   140,     0,   141,     0,   143,     0,   145,
     146,   147,   148,   149,   150,   151,     0,     0,   152,   153,
     154,     0,   155,   428,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   529,   169,   530,   171,   531,
     532,   174,   175,   176,   177,   178,   179,   533,   181,   534,
     535,   536,   185,   186,   537,   538,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   539,     0,
     202,   203,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,     0,   254,   541,   256,   257,   258,
     259,   260,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     0,     0,     0,     0,     9,    10,     0,     0,
       0,     0,     0,     0,   425,   426,     0,    16,    17,    18,
     499,    20,    21,    22,   500,    24,   501,   502,   503,   504,
     427,    30,   505,    32,    33,    34,     0,    35,    36,    37,
      38,   506,    40,    41,    42,    43,    44,    45,    46,   507,
       0,    48,   508,    50,   509,   510,    53,   511,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   512,   513,    71,     0,    72,    73,    74,   514,
       0,     0,    77,    78,    79,     0,     0,   515,    81,     0,
       0,     0,     0,    83,   516,    85,   517,   518,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   519,   100,
     101,   520,   521,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   522,     0,     0,     0,   118,   119,   120,
     121,   523,   123,   124,   524,     0,     0,     0,     0,     0,
       0,     0,   525,   526,   131,     0,     0,     0,   132,     0,
     133,   134,   527,     0,     0,     0,     0,   139,     0,   140,
       0,   141,   142,   143,   144,   528,   146,   147,   148,   149,
     150,   151,     0,     0,   152,   153,     0,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   529,   169,   530,   171,   531,   532,   174,   175,   176,
     177,   178,   179,   533,   181,   534,   535,   536,   185,   186,
     537,   538,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   539,     0,   202,   540,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,     0,     0,
       0,   254,   541,   256,   257,   258,   259,   260,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     0,     0,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
     425,   426,     0,    16,    17,    18,   549,    20,    21,    22,
     500,   550,   551,   502,   503,   504,   427,    30,   505,    32,
     552,    34,     0,    35,    36,    37,    38,   553,    40,   554,
     555,    43,    44,    45,    46,   507,     0,    48,   556,    50,
     509,   510,    53,   511,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   512,   513,
      71,     0,    72,    73,    74,   557,     0,     0,    77,    78,
      79,     0,     0,   515,    81,     0,     0,     0,     0,    83,
     516,    85,   517,   518,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   519,   100,   101,   520,   521,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   522,
       0,     0,     0,   118,   119,   120,   121,   523,   123,   124,
     524,     0,     0,     0,     0,     0,     0,     0,   525,   526,
     131,     0,     0,     0,   132,     0,   133,   134,   527,     0,
       0,     0,     0,   139,     0,   140,     0,   141,   142,   143,
     144,   528,   146,   147,   148,   149,   150,   151,     0,     0,
     152,   153,     0,     0,   155,   428,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   529,   558,   530,
     171,   531,   532,   174,   175,   176,   177,   178,   179,   533,
     181,   534,   535,   536,   185,   186,   537,   538,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     539,     0,   202,   540,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,     0,     0,     3,     0,   254,   541,   256,
     257,   258,   259,   260,     9,    10,     0,     0,     0,    13,
       0,     0,   425,   426,     0,    16,    17,    18,   549,    20,
      21,    22,   500,   550,   551,   502,   503,   504,   427,    30,
     505,    32,   552,    34,     0,    35,    36,    37,    38,   553,
      40,   554,   555,    43,    44,    45,    46,   507,     0,    48,
     556,    50,   509,   510,    53,   511,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     512,   513,    71,     0,    72,    73,    74,   557,     0,     0,
      77,    78,    79,     0,     0,   515,    81,     0,     0,     0,
       0,    83,   516,    85,   517,   518,    88,    89,   571,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   519,   100,   101,   520,
     521,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,   956,     0,     0,
     116,   522,     0,     0,     0,   118,   119,   120,   121,   523,
     123,   124,   524,     0,     0,     0,     0,     0,     0,     0,
     525,   526,   131,     0,     0,     0,   132,     0,   133,   134,
     527,     0,     0,     0,     0,     0,     0,   140,     0,   141,
     142,   143,   144,   528,   146,   147,   148,   149,   150,   151,
       0,     0,   152,   153,     0,     0,   155,   428,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   529,
     558,   530,   171,   531,   532,   174,   175,   176,   177,   178,
     179,   533,   181,   534,   535,   536,   185,   186,   537,   538,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   539,     0,   202,   540,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,     0,     0,     3,     0,   254,
     541,   256,   257,   258,   259,   260,     9,    10,     0,     0,
       0,     0,     0,     0,   425,   426,     0,    16,    17,    18,
     499,    20,    21,    22,   500,    24,   501,   502,  1174,   504,
     427,    30,   505,    32,    33,    34,     0,    35,    36,    37,
      38,   506,    40,    41,    42,    43,    44,    45,    46,   507,
       0,    48,   508,    50,   509,   510,    53,   511,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   512,   513,    71,     0,    72,    73,    74,   514,
       0,     0,    77,    78,    79,     0,     0,   515,    81,     0,
       0,     0,     0,    83,   516,    85,   517,   518,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   519,   100,
     101,   520,   521,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1175,     0,     0,     0,  1176,
       0,     0,   116,   522,     0,     0,     0,   118,   119,   120,
     121,   523,   123,   124,   524,     0,     0,     0,     0,     0,
       0,     0,   525,   526,   131,     0,     0,     0,   132,  1615,
     133,   134,   527,     0,     0,     0,     0,  1616,     0,   140,
       0,   141,   142,   143,   144,   528,   146,   147,   148,   149,
     150,   151,     0,     0,  1177,   153,     0,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   529,   169,   530,   171,   531,   532,   174,   175,   176,
     177,   178,   179,   533,   181,   534,   535,   536,   185,   186,
     537,   538,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   539,     0,   202,   540,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,     0,     0,
       0,   254,   541,   256,  1178,  1179,  1180,  1181,     3,     0,
     585,   586,     0,     0,     0,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,   425,   426,     0,    16,    17,
      18,   549,    20,    21,    22,   500,   550,   551,   502,   503,
     504,   427,    30,   505,    32,   552,    34,     0,    35,    36,
      37,    38,   553,    40,   554,   555,    43,    44,    45,    46,
     507,     0,    48,   556,    50,   509,   510,    53,   511,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   512,   513,    71,     0,    72,    73,    74,
     557,     0,     0,    77,    78,    79,     0,     0,   515,    81,
       0,     0,     0,     0,    83,   516,    85,   517,   518,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   519,
     100,   101,   520,   521,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   116,   522,     0,     0,     0,   118,   119,
     120,   121,   523,   123,   124,   524,     0,     0,     0,     0,
       0,     0,     0,   525,   526,   131,     0,     0,     0,   132,
       0,   133,   134,   527,     0,     0,     0,     0,     0,     0,
     140,     0,   141,   142,   143,   144,   528,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,     0,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   529,   558,   530,   171,   531,   532,   174,   175,
     176,   177,   178,   179,   533,   181,   534,   535,   536,   185,
     186,   537,   538,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   539,     0,   202,   540,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,     0,     0,
       3,     0,   254,   541,   256,   257,   258,   259,   260,     9,
      10,     0,     0,     0,     0,     0,     0,   425,   426,     0,
      16,    17,    18,   549,    20,    21,    22,   500,   550,   551,
     502,   503,   504,   427,    30,   505,    32,   552,    34,     0,
      35,    36,    37,    38,   553,    40,   554,   555,    43,    44,
      45,    46,   507,     0,    48,   556,    50,   509,   510,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   512,   513,    71,     0,    72,
      73,    74,   557,     0,     0,    77,    78,    79,     0,     0,
     515,    81,     0,     0,     0,     0,    83,   516,    85,   517,
     518,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   520,   521,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   116,   522,     0,     0,     0,
     118,   119,   120,   121,   523,   123,   124,   524,     0,     0,
       0,     0,     0,     0,     0,   525,   526,   131,     0,     0,
       0,   132,   779,   133,   134,   527,     0,     0,     0,     0,
     780,     0,   140,     0,   141,   142,   143,   144,   528,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,     0,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,   558,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,   537,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     540,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,     0,     3,     0,   254,   541,   256,   257,   258,   259,
     260,     9,    10,     0,     0,     0,   805,     0,     0,   425,
     426,     0,    16,    17,    18,   549,    20,    21,    22,   500,
     550,   551,   502,   503,   504,   427,    30,   505,    32,   552,
      34,     0,    35,    36,    37,    38,   553,    40,   554,   555,
      43,    44,    45,    46,   507,     0,    48,   556,    50,   509,
     510,    53,   511,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   512,   513,    71,
       0,    72,    73,    74,   557,     0,     0,    77,    78,    79,
       0,     0,   515,    81,     0,     0,     0,     0,    83,   516,
      85,   517,   518,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   520,   521,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   522,     0,
       0,     0,   118,   119,   120,   121,   523,   123,   124,   524,
       0,     0,     0,     0,     0,     0,     0,   525,   526,   131,
       0,     0,     0,   132,   806,   133,   134,   527,     0,     0,
       0,     0,     0,     0,   140,     0,   141,   142,   143,   144,
     528,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,     0,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   529,   558,   530,   171,
     531,   532,   174,   175,   176,   177,   178,   179,   533,   181,
     534,   535,   536,   185,   186,   537,   538,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   539,
       0,   202,   540,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,     0,     3,     0,   254,   541,   256,   257,
     258,   259,   260,     9,    10,     0,     0,     0,     0,     0,
       0,   425,   426,     0,    16,    17,    18,   549,    20,    21,
      22,   500,   550,   551,   502,   503,   504,   427,    30,   505,
      32,   552,    34,     0,    35,    36,    37,    38,   553,    40,
     554,   555,    43,    44,    45,    46,   507,     0,    48,   556,
      50,   509,   510,    53,   511,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   512,
     513,    71,     0,    72,    73,    74,   557,     0,     0,    77,
      78,    79,     0,     0,   515,    81,     0,     0,     0,     0,
      83,   516,    85,   517,   518,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,   100,   101,   520,   521,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     522,     0,     0,     0,   118,   119,   120,   121,   523,   123,
     124,   524,     0,     0,     0,     0,     0,     0,     0,   525,
     526,   131,     0,     0,     0,   132,   823,   133,   134,   527,
       0,     0,     0,     0,   824,     0,   140,     0,   141,   142,
     143,   144,   528,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,     0,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   529,   558,
     530,   171,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,   537,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   539,     0,   202,   540,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,     0,     3,     0,   254,   541,
     256,   257,   258,   259,   260,     9,    10,     0,     0,     0,
       0,     0,     0,   425,   426,     0,    16,    17,    18,   499,
      20,    21,    22,   500,    24,   501,   502,  1174,   504,   427,
      30,   505,    32,    33,    34,     0,    35,    36,    37,    38,
     506,    40,    41,    42,    43,    44,    45,    46,   507,     0,
      48,   508,    50,   509,   510,    53,   511,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   512,   513,    71,     0,    72,    73,    74,   514,     0,
       0,    77,    78,    79,     0,     0,   515,    81,     0,     0,
       0,     0,    83,   516,    85,   517,   518,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   519,   100,   101,
     520,   521,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1175,     0,     0,     0,  1214,     0,
       0,   116,   522,     0,     0,     0,   118,   119,   120,   121,
     523,   123,   124,   524,     0,     0,     0,     0,     0,     0,
       0,   525,   526,   131,     0,     0,     0,   132,  1449,   133,
     134,   527,     0,     0,     0,     0,     0,     0,   140,     0,
     141,   142,   143,   144,   528,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,     0,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     529,   169,   530,   171,   531,   532,   174,   175,   176,   177,
     178,   179,   533,   181,   534,   535,   536,   185,   186,   537,
     538,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   539,     0,   202,   540,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,     0,     3,     0,
     254,   541,   256,  1178,  1179,  1180,  1181,     9,    10,     0,
       0,     0,     0,     0,     0,   425,   426,     0,    16,    17,
      18,   499,    20,    21,    22,   500,    24,   501,   502,  1174,
     504,   427,    30,   505,    32,    33,    34,     0,    35,    36,
      37,    38,   506,    40,    41,    42,    43,    44,    45,    46,
     507,     0,    48,   508,    50,   509,   510,    53,   511,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   512,   513,    71,     0,    72,    73,    74,
     514,     0,     0,    77,    78,    79,     0,     0,   515,    81,
       0,     0,     0,     0,    83,   516,    85,   517,   518,    88,
      89,  1523,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   519,
     100,   101,   520,   521,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1175,     0,     0,     0,
    1176,     0,     0,   116,   522,     0,     0,     0,   118,   119,
     120,   121,   523,   123,   124,   524,     0,     0,     0,     0,
       0,     0,     0,   525,   526,   131,     0,     0,     0,   132,
       0,   133,   134,   527,     0,     0,     0,     0,     0,     0,
     140,     0,   141,   142,   143,   144,   528,   146,   147,   148,
     149,   150,   151,     0,     0,  1177,   153,     0,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   529,   169,   530,   171,   531,   532,   174,   175,
     176,   177,   178,   179,   533,   181,   534,   535,   536,   185,
     186,   537,   538,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   539,     0,   202,   540,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,     0,     0,
       3,     0,   254,   541,   256,  1178,  1179,  1180,  1181,     9,
      10,     0,     0,     0,     0,     0,     0,   425,   426,     0,
      16,    17,    18,   499,    20,    21,    22,   500,    24,   501,
     502,  1174,   504,   427,    30,   505,    32,    33,    34,     0,
      35,    36,    37,    38,   506,    40,    41,    42,    43,    44,
      45,    46,   507,     0,    48,   508,    50,   509,   510,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   512,   513,    71,     0,    72,
      73,    74,   514,     0,     0,    77,    78,    79,     0,     0,
     515,    81,     0,     0,     0,     0,    83,   516,    85,   517,
     518,    88,    89,  1668,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   520,   521,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,  1175,     0,
       0,     0,  1176,     0,     0,   116,   522,     0,     0,     0,
     118,   119,   120,   121,   523,   123,   124,   524,     0,     0,
       0,     0,     0,     0,     0,   525,   526,   131,     0,     0,
       0,   132,     0,   133,   134,   527,     0,     0,     0,     0,
       0,     0,   140,     0,   141,   142,   143,   144,   528,   146,
     147,   148,   149,   150,   151,     0,     0,  1177,   153,     0,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,   169,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,   537,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     540,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,     0,     3,     0,   254,   541,   256,  1178,  1179,  1180,
    1181,     9,    10,     0,     0,     0,     0,     0,     0,   425,
     426,     0,    16,    17,    18,   499,    20,    21,    22,   500,
      24,   501,   502,  1174,   504,   427,    30,   505,    32,    33,
      34,     0,    35,    36,    37,    38,   506,    40,    41,    42,
      43,    44,    45,    46,   507,     0,    48,   508,    50,   509,
     510,    53,   511,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   512,   513,    71,
       0,    72,    73,    74,   514,     0,     0,    77,    78,    79,
       0,     0,   515,    81,     0,     0,     0,     0,    83,   516,
      85,   517,   518,    88,    89,  1672,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   520,   521,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
    1175,     0,     0,     0,  1176,     0,     0,   116,   522,     0,
       0,     0,   118,   119,   120,   121,   523,   123,   124,   524,
       0,     0,     0,     0,     0,     0,     0,   525,   526,   131,
       0,     0,     0,   132,     0,   133,   134,   527,     0,     0,
       0,     0,     0,     0,   140,     0,   141,   142,   143,   144,
     528,   146,   147,   148,   149,   150,   151,     0,     0,  1177,
     153,     0,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   529,   169,   530,   171,
     531,   532,   174,   175,   176,   177,   178,   179,   533,   181,
     534,   535,   536,   185,   186,   537,   538,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   539,
       0,   202,   540,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,     0,     3,     0,   254,   541,   256,  1178,
    1179,  1180,  1181,     9,    10,     0,     0,     0,     0,     0,
       0,   425,   426,     0,    16,    17,    18,   499,    20,    21,
      22,   500,    24,   501,   502,  1174,   504,   427,    30,   505,
      32,    33,    34,     0,    35,    36,    37,    38,   506,    40,
      41,    42,    43,    44,    45,    46,   507,     0,    48,   508,
      50,   509,   510,    53,   511,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   512,
     513,    71,     0,    72,    73,    74,   514,     0,     0,    77,
      78,    79,     0,     0,   515,    81,     0,     0,     0,     0,
      83,   516,    85,   517,   518,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,   100,   101,   520,   521,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,  1175,     0,     0,     0,  1176,     0,     0,   116,
     522,     0,     0,     0,   118,   119,   120,   121,   523,   123,
     124,   524,     0,     0,     0,     0,     0,     0,     0,   525,
     526,   131,     0,     0,     0,   132,     0,   133,   134,   527,
       0,     0,     0,     0,     0,     0,   140,     0,   141,   142,
     143,   144,   528,   146,   147,   148,   149,   150,   151,     0,
       0,  1177,   153,     0,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   529,   169,
     530,   171,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,   537,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   539,     0,   202,   540,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,     0,     3,     0,   254,   541,
     256,  1178,  1179,  1180,  1181,     9,    10,     0,     0,     0,
       0,     0,     0,   425,   426,     0,    16,    17,    18,   499,
      20,    21,    22,   500,    24,   501,   502,  1174,   504,   427,
      30,   505,    32,    33,    34,     0,    35,    36,    37,    38,
     506,    40,    41,    42,    43,    44,    45,    46,   507,     0,
      48,   508,    50,   509,   510,    53,   511,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   512,   513,    71,     0,    72,    73,    74,   514,     0,
       0,    77,    78,    79,     0,     0,   515,    81,     0,     0,
       0,     0,    83,   516,    85,   517,   518,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   519,   100,   101,
     520,   521,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1175,     0,     0,     0,  1214,     0,
       0,   116,   522,     0,     0,     0,   118,   119,   120,   121,
     523,   123,   124,   524,     0,     0,     0,     0,     0,     0,
       0,   525,   526,   131,     0,     0,     0,   132,     0,   133,
     134,   527,     0,     0,     0,     0,     0,     0,   140,     0,
     141,   142,   143,   144,   528,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,     0,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     529,   169,   530,   171,   531,   532,   174,   175,   176,   177,
     178,   179,   533,   181,   534,   535,   536,   185,   186,   537,
     538,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   539,     0,   202,   540,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,     0,     3,     0,
     254,   541,   256,  1178,  1179,  1180,  1181,     9,    10,     0,
       0,     0,     0,     0,     0,   425,   426,     0,    16,    17,
      18,   549,    20,    21,    22,   500,   550,   551,   502,   503,
     504,   427,    30,   505,    32,   552,    34,     0,    35,    36,
      37,    38,   553,    40,   554,   555,    43,    44,    45,    46,
     507,     0,    48,   556,    50,   509,   510,    53,   511,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   512,   513,    71,     0,    72,    73,    74,
     557,     0,     0,    77,    78,    79,     0,     0,   515,    81,
       0,     0,     0,     0,    83,   516,    85,   517,   518,    88,
      89,  1269,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   519,
     100,   101,   520,   521,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   116,   522,     0,     0,     0,   118,   119,
     120,   121,   523,   123,   124,   524,     0,     0,     0,     0,
       0,     0,     0,   525,   526,   131,     0,     0,     0,   132,
       0,   133,   134,   527,     0,     0,     0,     0,     0,     0,
     140,     0,   141,   142,   143,   144,   528,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,     0,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   529,   558,   530,   171,   531,   532,   174,   175,
     176,   177,   178,   179,   533,   181,   534,   535,   536,   185,
     186,   537,   538,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   539,     0,   202,   540,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,     0,     0,
       3,     0,   254,   541,   256,   257,   258,   259,   260,     9,
      10,     0,     0,     0,     0,     0,     0,   425,   426,     0,
      16,    17,    18,   549,    20,    21,    22,   500,   550,   551,
     502,   503,   504,   427,    30,   505,    32,   552,    34,     0,
      35,    36,    37,    38,   553,    40,   554,   555,    43,    44,
      45,    46,   507,     0,    48,   556,    50,   509,   510,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   512,   513,    71,     0,    72,
      73,    74,   557,     0,     0,    77,    78,    79,     0,     0,
     515,    81,     0,     0,     0,     0,    83,   516,    85,   517,
     518,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   520,   521,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   116,   522,     0,     0,     0,
     118,   119,   120,   121,   523,   123,   124,   524,     0,     0,
       0,     0,     0,     0,     0,   525,   526,   131,     0,     0,
       0,   132,     0,   133,   134,   527,     0,     0,     0,     0,
       0,     0,   140,     0,   141,   142,   143,   144,   528,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,     0,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,   558,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,   537,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     540,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,     0,     0,     0,   254,   541,   256,   257,   258,   259,
     260,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,   857,
      20,    21,    22,    23,     0,   858,   502,    27,     0,   427,
      30,   505,    32,     0,    34,     0,    35,    36,    37,    38,
     859,    40,     0,     0,    43,    44,    45,    46,   507,     0,
      48,   860,    50,     0,     0,    53,   511,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   512,   513,    71,     0,    72,    73,    74,   861,     0,
       0,    77,    78,    79,     0,     0,   515,    81,     0,     0,
       0,    82,    83,   516,    85,   517,   518,    88,    89,   571,
      91,     0,     0,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   519,   100,   101,
     520,   521,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,   572,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   524,     0,   126,     0,     0,     0,     0,
       0,   525,   526,   131,     0,     0,     0,   132,     0,   133,
     134,   527,     0,     0,     0,     0,     0,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,     0,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     529,     0,   530,   171,   531,   532,   174,   175,   176,   177,
     178,   179,   533,   181,   534,   535,   536,   185,   186,     0,
     538,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   539,     0,   202,   540,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     9,
      10,   541,   256,     0,     0,     0,     0,   425,   426,     0,
      16,    17,    18,     0,    20,    21,    22,   500,     0,     0,
     502,   503,     0,   427,    30,   505,    32,     0,    34,     0,
      35,    36,    37,    38,     0,    40,     0,     0,    43,    44,
      45,    46,   507,     0,    48,     0,    50,     0,     0,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   512,   513,    71,     0,    72,
      73,    74,     0,     0,     0,    77,    78,    79,     0,     0,
     515,    81,     0,     0,     0,     0,    83,   516,    85,   517,
     518,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   520,   521,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,     0,     0,
       0,     0,     0,     0,     0,   116,   522,     0,     0,     0,
     118,   119,   120,   121,   523,   123,   124,   524,     0,     0,
       0,     0,     0,     0,     0,   525,   526,   131,     0,     0,
       0,   132,     0,   133,   134,   527,     0,     0,     0,     0,
       0,     0,   140,     0,   141,   142,   143,   144,   528,   146,
     147,   148,   149,   150,   151,     0,     0,     0,   153,     0,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,     0,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,     0,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     540,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,     0,     0,     0,     0,   541,   256
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,   188,   436,   437,    14,     5,     6,     7,     8,   438,
     321,   300,     5,     6,     7,   707,     0,   352,  1077,   691,
     268,     5,     6,     7,     8,   799,   784,   138,   844,   692,
     693,   694,   695,   269,   719,   633,   634,  1061,   812,     5,
       6,     7,     8,  1310,   473,   474,   881,  1328,   284,   784,
     598,   203,   826,   261,   262,   603,     1,   112,   113,     1,
    1103,  1392,  1393,    76,  1160,   974,   631,   632,   933,  1024,
     946,   947,     5,     6,     7,     8,   631,   632,   633,   634,
      39,  1526,   321,    36,  1529,    44,    45,   741,    36,  1439,
    1042,   119,    97,   670,    53,   672,   673,    31,   675,    56,
     677,    60,  1637,    62,    63,    27,    28,     1,   685,   686,
       1,   111,    71,   990,    30,    37,    38,   108,    40,    41,
       1,   291,     8,    27,    28,    47,     1,   111,  1341,     1,
       1,     1,    27,    28,     1,    57,    58,   149,     1,    98,
       1,     1,   431,    47,    97,   111,   435,    95,     1,    97,
       1,     1,    47,    75,   231,     1,   233,     1,    80,  1698,
     138,     1,    57,   108,     1,   101,   108,     1,  1044,    94,
      97,    75,   155,     1,    52,  1051,     0,     1,   111,     1,
      75,   613,   170,    37,    38,    80,    40,    41,   220,   160,
     112,   113,   114,     9,    10,   275,   149,   252,   253,   107,
     231,   149,   282,   231,    58,   236,   177,   187,     1,   113,
     190,    33,   292,   119,   108,   305,   204,   112,   113,   114,
      97,   129,   996,   144,   314,   203,   108,   108,   260,   212,
     201,   158,   212,   108,   666,   946,   947,  1776,   108,  1570,
     162,   108,     1,   320,   355,   300,   162,   108,  1307,     1,
     241,   187,  1787,   131,   190,   108,     1,   262,   108,   184,
     114,   261,   262,   220,   108,   265,   577,   279,   108,  1293,
       1,   108,   231,  1540,   108,   564,  1050,   261,   262,   990,
     108,   265,   216,  1099,   108,   313,  1636,   457,   104,  1332,
     176,  1049,   186,   891,   892,  1160,  1161,     1,  1341,  1176,
     300,   192,  1211,   260,   226,  1260,  1751,   188,   162,   125,
     185,   127,  1047,  1024,  1049,   108,   300,  1269,   188,  1415,
     192,   192,   976,   752,   889,   890,   279,   188,  1063,   192,
    1543,   279,   192,  1044,    30,   188,   186,  1214,   577,   155,
    1051,   192,    30,   159,   188,   267,   192,   360,   188,   108,
     363,   188,   929,  1798,   188,  1800,   108,   239,   279,   175,
     188,   185,     1,   108,   323,   324,   325,   656,   797,     0,
       1,   293,   226,   279,   319,   317,   431,   108,  1152,   301,
     435,   197,     1,   631,   632,   262,   263,   309,   108,   293,
     160,   149,   628,   629,    76,   188,   108,   301,   293,   215,
     123,   158,   638,     1,   108,  1736,   301,   177,    90,  1285,
      77,   466,   620,   267,   309,   111,   471,   231,    95,   233,
     133,    95,   231,   111,   119,     1,   481,   108,   158,   188,
     126,   431,   114,   488,   489,   435,   188,   146,   126,   108,
     185,   231,   497,   108,   126,     1,   128,   431,    95,     9,
      10,   435,    54,    45,   185,   151,   162,    59,    55,  1790,
      57,   155,   462,   151,   464,  1176,   155,   155,   177,   108,
     158,    63,   192,    30,   203,   149,   188,   108,   462,   192,
     464,   185,     1,   212,   178,  1259,   486,   196,   155,   108,
     178,   491,  1773,   188,     9,    97,   462,   144,   464,   933,
    1543,   121,   486,  1214,   101,   275,   320,   491,   189,   564,
     108,   320,   282,  1271,    29,   108,   239,   669,    97,   188,
     486,   279,   292,    95,   189,   491,   581,   582,  1213,   462,
     320,   464,   108,    27,    28,   969,   156,   592,   158,  1374,
    1138,  1139,  1140,  1378,   104,  1280,   185,   224,   225,  1260,
    1415,  1818,   108,   486,   185,   610,   611,   114,   491,  1424,
     227,   228,   239,  1255,   564,   125,   185,   127,   997,   998,
    1435,  1447,   572,  1002,  1285,  1123,    45,   265,    47,   138,
     564,   108,     5,  1138,  1139,  1140,     9,   185,   572,   108,
     879,   170,   185,   152,   108,   155,   188,   108,  1309,   159,
     711,   712,    95,  1032,     9,   162,   572,   155,    95,   185,
     125,   611,   127,     5,   147,   175,   626,     9,   907,   113,
     620,   136,  1396,   243,    29,   158,   108,   611,   132,   185,
    1654,   631,   632,   633,   634,   158,   620,   197,   107,   572,
     155,   889,    97,   119,    97,   611,   119,   631,   632,   633,
     634,   144,   224,   225,   108,   215,   656,   108,   713,   895,
     257,   188,   149,   899,   212,   720,   185,   239,   108,   108,
      95,    97,   656,   270,   188,   272,   108,   188,   360,   258,
     259,   363,   261,    45,   132,    47,   283,   284,   285,   268,
     287,     1,   289,     3,   149,   199,   149,   158,   119,   278,
     169,    42,   125,   119,   127,    46,   188,     1,   708,     3,
      51,   290,   135,  1772,   187,   708,   118,   190,    80,   144,
     125,   158,   127,    30,   708,  1541,  1160,  1161,   269,    70,
    1546,   136,   155,   125,   188,   127,  1447,   188,    97,   280,
    1498,  1606,   708,   135,   170,   107,   148,   155,   188,   188,
     155,   199,     9,    10,  1426,   114,   188,    67,   158,   161,
     442,   443,    72,   155,   446,     3,   187,   124,   450,   190,
     178,   453,   454,    67,     1,   708,   167,   158,    72,   461,
     835,   836,   837,  1381,   839,   467,   468,     9,    10,   789,
    1666,  1483,   183,   475,   196,   160,   789,   101,   101,   158,
     482,   483,   484,   485,   111,   789,    33,   169,   490,   119,
     114,   114,   177,    97,    95,  1526,   498,    25,  1529,   126,
     820,   821,    49,   789,   879,   119,    34,  1162,   169,    67,
     114,   172,   258,   259,    72,   261,   820,   821,   635,  1128,
     121,    95,   639,  1719,   151,  1721,   187,   104,   155,   190,
      97,   158,   278,    61,   820,   821,   789,   121,  1038,  1288,
    1040,   183,  1678,   545,   290,   158,  1682,   114,   125,   160,
     127,   178,   269,   214,   158,   156,   198,   158,   560,   879,
      33,   119,   104,   280,   150,   139,   177,   820,   821,   571,
     144,   901,   156,  1129,   158,   879,    49,   150,   155,  1135,
     166,   956,   159,   125,  1084,   127,  1086,   907,  1784,    96,
     201,   124,   124,   166,    54,   158,   598,    95,   175,    59,
     107,   603,   263,   907,   606,  1597,  1598,  1590,   139,   107,
     117,   613,   139,   155,  1763,  1764,   124,   159,    78,   183,
     197,   134,   129,   155,   155,  1132,   158,  1639,   155,   142,
     143,  1767,   145,   175,   198,  1666,   101,    97,   215,  1388,
     153,   238,  1736,   240,   157,   101,   159,   101,  1397,   114,
     101,   164,   139,   253,   254,   197,  1805,   144,   114,   119,
     114,  1415,  1811,   114,   666,   987,   714,   180,   274,   717,
    1424,   193,   194,   215,   722,   281,   276,   999,  1287,   155,
     155,  1435,   158,   158,   139,   283,   284,   285,  1719,   144,
    1721,   289,   205,   206,   207,   208,   209,   210,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    54,   155,
     158,   155,   158,    59,   158,  1707,  1708,   719,   187,   359,
    1751,   190,   362,   227,   228,   229,   238,   124,   240,  1741,
     130,   131,   130,   131,   689,   690,   696,   697,  1253,  1254,
     698,   699,  1373,   745,  1627,  1628,   748,  1306,   124,    90,
     119,   124,   124,  1784,   155,   219,   155,   124,  1507,  1079,
     762,   124,   124,   124,   766,   767,   155,  1798,   158,  1800,
     111,   119,   158,   114,   248,  1079,  1788,   247,   155,   247,
     320,     0,   192,   785,  1159,   126,   168,   128,  1780,    93,
     100,   793,   255,  1079,   796,    50,   202,   102,   800,   195,
     103,   156,   158,    30,   185,   185,  1365,  1137,  1128,    47,
     185,   185,   154,   119,  1373,   252,   310,   188,  1138,  1139,
    1140,   155,     1,   119,  1128,   144,  1079,   108,   188,   188,
     155,   155,   158,   144,  1138,  1139,  1140,   158,   158,   123,
     158,   843,   158,   123,   158,   185,   158,   155,  1860,   158,
    1862,    35,  1606,    17,    30,   192,   192,   251,   216,   237,
    1872,     3,   119,  1370,   171,   290,   290,   169,   119,    71,
     171,   237,    95,    95,    95,   188,   151,   108,   108,   881,
      30,   129,   134,   162,   162,    95,   305,   252,   144,   134,
     119,   185,   185,   188,   108,    95,   188,    45,    97,    97,
     188,   188,   188,   188,    95,   155,   155,   144,   185,   911,
    1519,   185,   155,   155,   155,   155,   243,   239,    33,   921,
     192,   185,   134,    95,   171,    30,   144,    95,   292,   155,
     119,   119,   129,   233,   149,   305,    95,   200,   134,   185,
     134,    97,   162,  1263,   946,   947,   948,   949,   155,   119,
    1263,   185,   101,   185,  1563,   101,  1515,   149,  1517,  1263,
     155,  1520,  1521,   144,   192,  1524,   123,  1287,   123,    35,
     155,  1530,    30,    80,   119,   251,   108,  1263,  1298,   107,
     158,   108,   264,  1287,   273,  1298,    30,   260,   990,   158,
      30,   158,   291,   158,  1298,   266,   158,  1317,   158,   146,
     158,   292,  1004,    30,  1317,   192,   188,   146,   233,   149,
    1263,   188,  1298,  1317,   312,   188,   129,   188,  1338,   149,
     108,   144,   185,   293,   101,  1345,   200,  1029,   134,     7,
     239,  1317,    97,   239,  1338,   188,  1038,   188,  1040,   243,
    1042,  1345,  1044,  1652,   158,  1298,   239,   158,   192,  1051,
     158,   155,  1338,   239,  1663,  1664,   107,  1377,  1667,  1345,
     149,    78,   119,   119,  1317,  1674,   188,   149,   292,    79,
     188,   288,   188,  1377,    30,    30,   256,   108,   188,   188,
     171,   256,  1084,   128,  1086,  1338,   188,   188,   188,   185,
     149,  1377,  1345,   128,   277,   149,    97,   263,   185,   185,
     185,   185,   443,   144,   185,   446,   322,   155,    95,   450,
    1669,    30,   453,   454,  1673,   188,    97,   188,   171,   149,
     461,  1123,    95,   199,    54,   286,   467,   468,    95,    30,
     271,   108,   108,   119,   475,    95,   231,    95,   199,   293,
     200,   482,   483,   484,   485,   119,  1148,   199,   119,   490,
      94,  1760,   231,   199,   119,   184,   119,   498,   201,   311,
     293,   299,   231,   751,   991,   119,   265,   265,   311,  1215,
     437,   268,  1260,  1788,  1176,   311,  1741,   312,   312,  1052,
     882,   312,  1157,   802,  1583,  1560,  1561,  1562,   457,  1407,
    1799,  1399,  1144,  1392,  1299,  1395,  1304,  1312,  1757,  1519,
    1307,   668,   688,   560,   545,   949,   725,  1332,  1817,   719,
     347,   844,  1214,  1811,  1805,  1519,  1375,  1040,  1364,   560,
    1424,   465,  1374,  1832,  1606,  1435,   465,  1161,  1170,  1603,
     571,   572,  1428,  1023,  1237,  1473,  1630,  1425,  1797,    -1,
      -1,    -1,  1801,  1563,    -1,  1854,    -1,   601,    -1,    -1,
      -1,    -1,    -1,    -1,  1863,    -1,    -1,    -1,    -1,  1563,
     601,    -1,    -1,    -1,    -1,   606,    -1,  1269,    -1,    -1,
      -1,  1273,   613,   111,  1833,    -1,    -1,  1836,    -1,    -1,
      -1,    -1,    -1,  1285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1299,    -1,    -1,
    1859,    -1,    -1,    -1,    -1,    -1,    -1,  1309,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1695,    -1,    -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,
      -1,    -1,  1652,    -1,    -1,    -1,    -1,  1339,    -1,    -1,
      -1,    -1,  1717,  1663,  1664,    -1,    -1,  1667,  1652,    -1,
      -1,    -1,    -1,    -1,  1674,    -1,    -1,    -1,    -1,  1663,
    1664,    -1,  1364,  1667,    -1,    -1,    -1,    -1,    -1,    -1,
    1674,    -1,  1374,    -1,    -1,    -1,  1378,    -1,   719,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1406,    -1,    -1,   748,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   762,    -1,    -1,    -1,   766,   767,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1760,    -1,    -1,    -1,   785,  1447,    -1,    -1,    -1,    -1,
      -1,    -1,   793,    -1,    -1,   796,  1760,    -1,    -1,   800,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1479,    -1,  1799,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   832,    -1,    -1,    -1,  1799,    -1,  1817,    -1,    -1,
      -1,    -1,   843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1832,  1817,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1523,    -1,    -1,  1526,    -1,    -1,  1529,  1832,    -1,
      -1,    -1,    -1,    -1,  1854,    -1,    -1,    -1,    -1,    -1,
    1542,    -1,    -1,  1863,    -1,  1547,    -1,    -1,    -1,    -1,
    1854,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1863,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     911,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1580,  1581,
     921,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   946,   947,   948,   949,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   990,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1004,  1666,    -1,  1668,    -1,  1670,    -1,
    1672,    -1,    -1,    -1,    -1,    -1,    -1,  1679,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1029,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1038,    -1,  1040,
      -1,  1042,    -1,  1044,    -1,    -1,    -1,    -1,    -1,    -1,
    1051,    -1,    -1,    -1,    -1,    -1,    -1,  1719,    -1,  1721,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   572,  1737,    -1,    -1,  1740,    -1,
      -1,    -1,    -1,  1084,    -1,  1086,    -1,    -1,    -1,  1751,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   596,   597,
    1762,   599,   600,   601,   602,    -1,   604,    -1,    -1,    -1,
      -1,   609,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   619,  1784,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1792,    -1,    -1,    -1,    -1,    -1,  1798,    -1,  1800,    -1,
      -1,    -1,    -1,   641,   642,    -1,    -1,  1148,    -1,    -1,
      -1,    -1,    -1,    -1,   652,    -1,    -1,    -1,   656,  1821,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1830,    -1,
      -1,    -1,    -1,    -1,    -1,  1176,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1850,    -1,
      -1,    -1,    -1,  1855,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1867,    -1,    -1,  1870,    -1,
      -1,    -1,    -1,  1214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   721,    -1,    -1,    -1,   725,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   764,    -1,  1269,    -1,
      -1,    -1,  1273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1285,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1299,    -1,
      -1,    -1,    -1,   801,    -1,    -1,    -1,    -1,  1309,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   827,
      -1,    -1,    -1,   831,   832,    -1,   834,    -1,  1339,    -1,
      -1,    -1,    -1,   841,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1406,    -1,    -1,    -1,   907,
      -1,    -1,    -1,    -1,    -1,   913,   914,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1447,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1479,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   992,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1523,    -1,    -1,  1526,    -1,    -1,  1529,  1027,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1542,    -1,    -1,    -1,    -1,  1547,    -1,  1046,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1062,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1073,  1074,    -1,    -1,  1580,
    1581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1088,    -1,    -1,  1091,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1110,  1111,  1112,    -1,  1114,  1115,  1116,  1117,
    1118,  1119,  1120,  1121,  1122,    -1,    -1,  1125,  1126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1666,    -1,  1668,    -1,  1670,
      -1,  1672,    -1,    -1,    -1,    -1,    -1,    -1,  1679,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1719,    -1,
    1721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1737,    -1,    -1,  1740,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1762,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1275,    -1,  1277,
      -1,  1279,    -1,  1784,    -1,    -1,    -1,    -1,    -1,  1287,
      -1,  1792,    -1,    -1,    -1,    -1,    -1,  1798,  1296,  1800,
      -1,    -1,    -1,    -1,  1302,  1303,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1821,    -1,    -1,  1321,    -1,    -1,  1324,  1325,    -1,  1830,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1850,
      -1,    -1,    -1,    -1,  1855,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1867,    -1,    -1,  1870,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1395,    -1,    -1,
      -1,  1399,  1400,    -1,    -1,    -1,    -1,  1405,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1492,    -1,    -1,    -1,  1496,    -1,
      -1,    -1,  1500,    -1,  1502,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1518,  1519,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1551,  1552,  1553,  1554,    -1,  1556,  1557,
      -1,  1559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1574,    -1,    -1,    -1,
      -1,  1579,    -1,    -1,    -1,    -1,    -1,  1585,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1645,    -1,  1647,
      -1,    -1,  1650,    -1,    -1,  1653,    -1,    -1,    -1,    -1,
    1658,  1659,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1667,
      -1,    -1,    -1,  1671,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1688,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1744,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1756,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,    -1,
    1828,    -1,    -1,    -1,  1832,    11,    12,    -1,    -1,  1837,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,  1853,    -1,    33,    34,  1857,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,   325,
     326,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,   192,   193,   194,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     1,   318,
      -1,   320,   321,   322,   323,   324,   325,   326,    11,    12,
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
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,    -1,   196,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     1,   318,    -1,   320,   321,   322,
     323,   324,   325,   326,    11,    12,    -1,    -1,    -1,    16,
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
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,    -1,   193,   194,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,   325,   326,
       0,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    95,    96,    97,    -1,    -1,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,   119,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,   138,    -1,
      -1,    -1,   142,   143,    -1,   145,    -1,   147,   148,    -1,
      -1,    -1,   152,   153,    -1,    -1,   156,   157,   158,   159,
     160,   161,    -1,    -1,   164,    -1,    -1,    -1,   168,   169,
      -1,    -1,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,
     180,    -1,    -1,    -1,    -1,   185,   186,   187,   188,   189,
     190,    -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,   206,   207,   208,   209,
     210,    -1,   212,    -1,   214,    -1,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,   224,   225,    -1,     0,     1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
      -1,   241,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,   319,
      93,    -1,    95,    96,    97,    -1,    -1,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,   117,   118,   119,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,
     143,    -1,   145,    -1,   147,   148,    -1,    -1,    -1,   152,
     153,    -1,    -1,   156,   157,   158,   159,   160,   161,    -1,
      -1,   164,    -1,    -1,    -1,   168,   169,    -1,    -1,   172,
      -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,    -1,
      -1,    -1,   185,   186,   187,   188,   189,   190,    -1,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,   208,   209,   210,    -1,   212,
      -1,   214,    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,   241,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   317,    30,   319,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,   191,   192,   193,   194,
      -1,   196,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
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
     325,   326,   327,   328,    11,    12,    -1,    -1,    -1,    16,
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
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,   325,   326,
      -1,   328,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,   185,    -1,   187,    -1,
     189,   190,   191,   192,   193,   194,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,   325,   326,    11,    12,
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
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,    -1,   196,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,    -1,   320,   321,   322,
     323,   324,   325,   326,    11,    12,    -1,    -1,    -1,    16,
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
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,   325,   326,
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
      -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,    -1,   196,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
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
     321,   322,   323,   324,   325,   326,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,   191,   192,   193,   194,
      -1,   196,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
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
     325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,   192,   193,   194,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,   325,   326,    11,    12,
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
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,    -1,   196,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,    -1,   320,   321,   322,
     323,   324,   325,   326,    11,    12,    -1,    -1,    -1,    16,
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
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,   146,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,   188,   189,   190,   191,    -1,   193,   194,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,   325,   326,
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
      -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,   188,   189,   190,
     191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
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
     321,   322,   323,   324,   325,   326,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,   186,   187,    -1,   189,   190,   191,    -1,   193,   194,
      -1,   196,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
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
     325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,   190,   191,    -1,   193,   194,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,   325,   326,    11,    12,
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
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,
     193,   194,    -1,   196,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,    -1,   320,   321,   322,
     323,   324,   325,   326,    11,    12,    -1,    -1,    -1,    16,
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
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,    -1,   193,   194,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,   319,   320,   321,   322,   323,   324,   325,   326,
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
      -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,    -1,   186,   187,    -1,   189,   190,
     191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
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
     321,   322,   323,   324,   325,   326,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,   188,   189,   190,   191,    -1,   193,   194,
      -1,   196,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
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
     325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,    -1,   193,   194,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,   325,   326,    11,    12,
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
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,
     193,   194,    -1,   196,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,    -1,   320,   321,   322,
     323,   324,   325,   326,    11,    12,    -1,    -1,    -1,    16,
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
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,    -1,   193,   194,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,   325,   326,
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
      -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
     191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
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
     321,   322,   323,   324,   325,   326,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,   191,    -1,   193,   194,
      -1,   196,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
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
     325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
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
     119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,    -1,   193,   194,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,   325,   326,    11,    12,
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
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,
     193,   194,    -1,   196,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,    -1,   320,   321,   322,
     323,   324,   325,   326,    11,    12,    -1,    -1,    -1,    16,
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
     117,   118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,   325,   326,
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
      -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,    -1,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,    -1,   153,   154,   155,   156,    -1,   158,   159,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,
      -1,   202,    -1,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
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
     321,   322,   323,   324,   325,   326,    11,    12,    -1,    -1,
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
     115,   116,   117,    -1,   119,   120,    -1,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,    -1,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,
     155,    -1,    -1,    -1,   159,    -1,    -1,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,    -1,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,    -1,   202,    -1,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
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
     325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    -1,
      -1,   320,   321,   322,   323,   324,   325,   326,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,    -1,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,    -1,    16,    -1,   320,   321,   322,
     323,   324,   325,   326,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,    -1,    16,    -1,   320,
     321,   322,   323,   324,   325,   326,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    -1,
      -1,   320,   321,   322,   323,   324,   325,   326,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      16,    -1,   320,   321,   322,   323,   324,   325,   326,    25,
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
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    16,    -1,   320,   321,   322,   323,   324,   325,
     326,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    16,    -1,   320,   321,   322,   323,
     324,   325,   326,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    16,    -1,   320,   321,
     322,   323,   324,   325,   326,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,    -1,    16,    -1,
     320,   321,   322,   323,   324,   325,   326,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      16,    -1,   320,   321,   322,   323,   324,   325,   326,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    16,    -1,   320,   321,   322,   323,   324,   325,
     326,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    16,    -1,   320,   321,   322,   323,
     324,   325,   326,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    16,    -1,   320,   321,
     322,   323,   324,   325,   326,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,    -1,    16,    -1,
     320,   321,   322,   323,   324,   325,   326,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      16,    -1,   320,   321,   322,   323,   324,   325,   326,    25,
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
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    -1,    -1,   320,   321,   322,   323,   324,   325,
     326,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    47,    -1,    49,
      50,    51,    52,    -1,    54,    -1,    56,    57,    58,    59,
      60,    61,    -1,    -1,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    25,
      26,   321,   322,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    -1,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    49,    50,    51,    52,    -1,    54,    -1,
      56,    57,    58,    59,    -1,    61,    -1,    -1,    64,    65,
      66,    67,    68,    -1,    70,    -1,    72,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    -1,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,   214,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,    -1,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    -1,    -1,    -1,   321,   322
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  jsoniq_parser::yystos_[] =
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
     119,   120,   122,   126,   128,   129,   130,   131,   133,   137,
     138,   139,   140,   141,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   158,   159,   160,   161,   162,   166,   167,
     168,   169,   170,   171,   172,   173,   175,   177,   178,   181,
     182,   183,   187,   189,   190,   191,   192,   193,   194,   196,
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
     314,   315,   316,   318,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   341,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   362,   363,   364,   365,   366,   367,   371,   372,   373,
     377,   379,   380,   382,   389,   391,   394,   395,   396,   398,
     399,   400,   401,   402,   404,   405,   407,   408,   409,   410,
     411,   412,   414,   415,   418,   419,   420,   421,   422,   428,
     430,   432,   433,   434,   439,   458,   461,   465,   468,   469,
     475,   476,   477,   478,   479,   481,   482,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   494,   495,   496,   497,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   530,   531,   532,
     533,   534,   535,   549,   550,   552,   553,   554,   555,   556,
     557,   558,   559,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   581,   586,   587,   588,   589,
     590,   591,   594,   652,   653,   654,   655,   657,   658,   659,
     660,   661,   664,   665,   666,    33,    34,    49,   218,   397,
     398,   399,   397,   397,   398,   399,   158,   158,    37,    38,
      40,    41,    47,    57,    58,    75,    80,   112,   113,   114,
     162,   226,   267,   293,   301,   309,   378,   379,   383,   384,
     385,   162,   155,   158,   155,   158,   155,   158,     1,   158,
     386,   158,    25,    34,    61,   119,   279,   438,   440,   441,
     158,   155,   158,   158,   158,   119,   155,   158,   158,   158,
      77,   155,   227,   228,   124,   124,   124,   155,   158,    39,
      43,    45,    46,    47,    48,    51,    60,    68,    71,    73,
      74,    76,    91,    92,    98,   106,   113,   115,   116,   137,
     140,   141,   162,   170,   173,   181,   182,   191,   204,   230,
     232,   234,   235,   242,   244,   245,   246,   249,   250,   263,
     266,   321,   514,   665,   124,   119,   406,   124,   124,    39,
      44,    45,    53,    60,    62,    63,    71,    98,   231,   664,
     119,   124,   124,   397,   399,   420,   656,   664,    48,    73,
      74,   119,   155,   186,   250,   419,   421,   432,   188,   419,
     664,   155,   155,   124,   664,    18,    19,   664,   124,   124,
     124,   506,   155,    31,   216,   219,   231,   233,   320,   231,
     233,   320,   231,   320,   231,   236,   119,   247,   247,   248,
     158,   155,   401,     1,   478,   317,   419,   319,   419,   320,
     328,   343,   343,     0,   345,   346,    33,    49,   348,   365,
       1,   192,   342,   192,   342,   113,   380,   400,   419,   108,
     192,   108,   342,   192,    42,    46,    51,    70,   169,   172,
     187,   190,   214,   263,   413,   423,   424,   429,   430,   431,
     446,   447,   451,     3,    67,    72,   119,   425,   168,    93,
     134,   142,   143,   145,   153,   157,   159,   164,   180,   205,
     206,   207,   208,   209,   210,   498,   499,   255,   100,   160,
     177,   201,   118,   148,   161,   196,   203,   212,   138,   152,
      50,   202,   102,   103,   160,   177,   496,   195,   155,   503,
     506,   193,   194,   156,   518,   519,   514,   518,   514,   121,
     156,   158,   518,   158,   147,   158,   185,   185,   185,   185,
     381,   521,   381,    30,   663,   183,   198,   183,   198,   167,
     183,   665,   664,   170,   204,    47,   664,   154,   119,    45,
      47,    80,   107,   169,   664,   227,   228,   229,   252,   625,
     664,   664,   310,   139,   144,   113,   293,   301,   383,   664,
     398,   188,   398,    45,    63,   188,   577,   578,   419,   188,
     196,   664,   435,   436,   664,   119,   188,   387,   388,   155,
     403,   419,     1,   162,   663,   114,   162,   361,   663,   664,
     119,   144,   108,   188,   419,    30,   188,   664,   664,   664,
     459,   460,   664,   398,   188,   419,   419,   579,   664,   398,
     155,   155,   419,   188,   196,   664,   664,   144,   459,   185,
     185,   123,   108,   185,   123,   158,   158,   158,   664,   155,
     186,   424,   188,    35,   537,   538,   539,   419,   419,     8,
     176,    17,   419,   216,    30,   420,   420,    39,    45,    60,
      71,    98,   517,   665,   420,   420,   420,   656,   420,   517,
     420,   237,   592,   593,   664,   192,   192,   420,   419,   399,
     419,   251,   416,   417,   435,   317,   319,   420,   343,   192,
     342,   192,   342,     3,   349,   365,   395,     1,   349,   365,
     395,    33,   366,   395,   366,   395,   406,   342,   406,   420,
     420,   119,   169,   171,   171,   420,   400,   420,   290,   290,
     435,   119,   442,   477,   478,   481,   481,   481,   481,   480,
     481,   481,   481,    71,   482,   486,   486,   485,   487,   487,
     487,   487,   488,   488,   489,   489,   237,    95,    95,    95,
     504,   397,   506,   506,   419,   519,   158,   523,   581,   664,
     186,   146,   188,   420,   529,   188,   151,   188,   529,   108,
     188,   188,   108,   108,   386,    30,   665,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   368,   369,   370,
      95,   139,   144,   374,   375,   376,   664,   162,   162,   368,
     663,   129,   134,    55,    57,   101,   257,   270,   272,   283,
     284,   285,   287,   289,   626,   627,   628,   629,   630,   631,
     638,   644,   645,   252,    95,   305,   664,   144,   420,   119,
     664,   664,   134,   185,   185,   188,   188,   185,   108,   188,
     108,   188,   108,    36,    95,    97,   149,   437,   438,   560,
     664,    95,   108,   188,   397,   188,   664,    97,    45,   664,
     663,    97,   144,   560,   664,   420,   441,   185,   188,   188,
     188,   188,   108,   189,   149,   560,   185,   188,   188,   155,
     185,   398,   398,   185,   108,   188,   108,   188,   144,   560,
     420,   189,   420,   420,   664,   420,   419,   419,   419,   664,
     538,   539,   132,   199,   185,   185,   185,   133,   192,    95,
     224,   225,   239,    95,   224,   225,   239,   239,   239,    95,
      95,   243,   231,   320,   108,   241,   144,   192,   188,   419,
     185,   515,   598,   417,   239,   365,    33,    33,   192,   342,
     192,   114,   400,   664,   171,   420,   452,   453,   119,   420,
     448,   449,   664,    56,   220,   260,   426,   427,   481,   155,
     158,   265,   502,   521,   599,   602,   603,   604,   605,   606,
     610,   612,   614,   615,    47,   154,   158,   213,   323,   324,
     325,   326,   561,   563,   565,   567,   582,   583,   584,   585,
     662,   664,   561,   493,   566,   664,   493,   185,   186,   188,
     419,   108,   188,   188,   521,   150,   166,   150,   166,   139,
     403,   386,   369,   134,   158,   563,   376,   420,   560,   663,
     663,   130,   131,   663,   283,   284,   285,   289,   664,   269,
     280,   269,   280,    30,   292,    97,   114,   158,   632,   635,
     626,    39,    44,    53,    60,    62,    71,    98,   231,   323,
     324,   325,   390,   567,   662,   233,   305,   314,   420,   664,
      95,   305,   663,   155,   579,   580,   664,   579,   580,   119,
     436,   129,   561,   119,   420,   149,   438,   149,    36,   149,
     437,   438,   560,   561,   388,    95,   185,   200,   134,   360,
     663,   162,   134,    97,   360,   420,   144,   438,   155,   119,
     420,   420,   149,   101,   462,   463,   464,   466,   467,   101,
     470,   471,   472,   473,   398,   185,   185,   155,   579,   579,
     420,   144,   192,   420,   123,   123,   188,   188,   188,    35,
     539,   132,   199,     9,    10,   104,   125,   127,   155,   197,
     534,   536,   547,   548,   551,   155,    30,   238,   240,   420,
     420,   420,   238,   240,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   517,   119,   420,   420,    48,    73,    74,
     250,   400,   421,   432,   251,   595,   596,   155,   212,   401,
     420,   192,   114,   395,   395,   395,   452,    96,   107,   117,
     129,   454,   455,   456,   457,   108,   664,   107,   450,   108,
     149,   560,   260,    54,    59,    78,   119,   437,   443,   444,
     445,   427,   419,   599,   606,   155,   291,   483,   651,    97,
     170,   258,   259,   261,   268,   278,   290,   600,   601,   620,
     621,   622,   623,   646,   649,   264,   266,   607,   625,   273,
     611,   647,   253,   254,   276,   616,   617,   158,   158,   188,
     563,   158,   158,   158,   158,   158,   146,   177,   196,   562,
     146,   188,   146,   420,   139,   403,   581,   375,   292,    30,
      97,   114,   158,   639,    30,   632,   562,   562,   504,   293,
     312,   560,   390,   233,   192,   397,   188,   188,   146,   188,
     188,   436,   149,   437,   664,   420,   149,   420,   129,   420,
     149,   438,   149,   561,   400,   420,   663,   108,   360,   420,
     144,   397,   460,   420,   420,   114,   463,   464,   101,   424,
     114,   464,   467,   119,   474,   561,   101,   114,   471,   101,
     114,   473,   185,   397,   188,   188,   420,   420,   420,   200,
     470,   134,   197,   536,     7,   398,   664,   197,   547,   398,
     192,   239,   239,   239,   239,    97,   243,   243,   593,   424,
     158,   158,   158,   424,   598,   596,   515,   663,   130,   131,
     456,   457,   457,   453,   144,   560,   663,   449,   420,   149,
     119,   119,   420,   664,   445,    78,   185,   188,   599,   613,
     256,   220,   260,   274,   281,   650,    97,   262,   263,   648,
     256,   603,   650,   485,   620,   604,   149,   288,   608,   609,
     648,   292,   619,    79,   618,   188,   196,   561,   564,   188,
     188,   188,   188,   188,   188,   188,    30,   138,   203,   641,
     642,   643,    30,   640,   641,   277,   636,   108,   633,   171,
     664,   263,   504,   185,   420,   149,   420,   149,   437,   420,
     149,   420,   128,   128,    97,   663,   420,   185,   424,   424,
     420,   400,   420,   424,   424,   664,   212,   424,   119,   474,
     119,   424,   119,   474,   424,   185,   114,   539,   664,   197,
     185,   539,   664,   185,   420,   420,   420,   420,   322,   420,
     420,   420,   419,   419,   419,   155,   597,   457,   420,   144,
     420,   664,   664,   444,   420,   185,   487,    52,   131,   485,
     485,   275,   282,   292,   624,   624,   605,   155,   286,    95,
     188,   108,   188,   639,   639,   643,   108,   188,    30,   637,
     648,   634,   635,   188,   392,   393,   504,   119,   231,   313,
     293,   171,   420,   420,   149,   420,   400,   420,   360,   420,
     400,    95,   561,   400,   420,   664,   424,   664,   420,   664,
     424,   400,   119,    94,   184,   540,   539,   664,   199,   539,
     420,   188,   188,   188,   419,   450,   420,    54,   485,   485,
     201,   419,   561,   561,    95,    30,   271,   108,   108,   457,
     560,   664,   119,   231,   664,   392,   420,   474,    95,   424,
      95,   664,     5,   135,   543,   544,   546,   548,    29,   136,
     541,   542,   545,   548,   199,   539,   199,   200,   470,   185,
     450,   119,   485,   185,   561,   635,   393,   457,   311,   664,
     119,   231,   424,   474,   400,   420,   474,   424,    94,   135,
     546,   184,   136,   545,   199,   114,   664,   420,   311,   664,
     119,   400,   420,   424,   424,   119,   299,   311,   664,   664,
     312,   420,   312,   424,   504,   504,   201,   293,   664,   231,
     119,   664,   312,   504
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
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   340,   341,   341,   341,   341,   342,   342,   342,   343,
     343,   343,   343,   344,   344,   345,   345,   345,   345,   345,
     345,   345,   345,   346,   346,   346,   346,   347,   348,   348,
     348,   349,   349,   349,   349,   349,   350,   350,   350,   350,
     350,   350,   350,   350,   351,   351,   352,   353,   354,   354,
     355,   355,   356,   356,   357,   357,   357,   357,   358,   358,
     358,   359,   359,   359,   359,   360,   360,   361,   361,   362,
     362,   362,   362,   363,   364,   364,   365,   365,   365,   366,
     366,   366,   366,   366,   366,   366,   366,   367,   367,   368,
     368,   369,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   371,   372,   373,   374,   374,   375,   375,   375,
     376,   377,   377,   377,   378,   378,   378,   378,   379,   379,
     380,   380,   380,   380,   381,   381,   382,   382,   383,   383,
     384,   384,   385,   385,   386,   386,   386,   386,   387,   387,
     388,   388,   389,   389,   389,   389,   390,   390,   390,   390,
     391,   391,   392,   392,   393,   393,   393,   393,   394,   394,
     394,   394,   395,   396,   396,   396,   397,   397,   397,   398,
     398,   399,   399,   399,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   401,   402,   403,
     404,   405,   405,   405,   406,   406,   406,   406,   407,   408,
     409,   410,   411,   411,   412,   413,   414,   415,   416,   416,
     417,   418,   419,   419,   419,   420,   420,   420,   420,   420,
     420,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   422,   423,   424,   424,   425,   425,   426,
     426,   426,   427,   427,   428,   428,   429,   430,   430,   430,
     431,   431,   431,   431,   431,   432,   432,   433,   433,   433,
     433,   434,   434,   435,   435,   435,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   437,   438,
     439,   440,   440,   441,   441,   441,   441,   442,   442,   443,
     443,   443,   444,   444,   444,   445,   445,   445,   446,   447,
     448,   448,   449,   449,   449,   449,   449,   449,   450,   451,
     451,   452,   452,   453,   453,   454,   454,   454,   454,   454,
     454,   454,   455,   455,   456,   456,   457,   458,   458,   459,
     459,   460,   460,   461,   462,   462,   463,   464,   464,   465,
     466,   466,   467,   468,   468,   469,   469,   470,   470,   471,
     471,   472,   472,   473,   473,   474,   474,   475,   476,   476,
     477,   477,   478,   478,   479,   479,   479,   479,   479,   480,
     479,   479,   479,   479,   481,   481,   482,   482,   483,   483,
     484,   484,   485,   485,   485,   486,   486,   486,   486,   486,
     487,   487,   487,   488,   488,   488,   489,   489,   490,   490,
     491,   491,   492,   492,   493,   493,   494,   494,   495,   495,
     495,   495,   496,   496,   496,   497,   497,   498,   498,   498,
     498,   498,   498,   499,   499,   499,   500,   500,   500,   500,
     501,   502,   502,   503,   503,   503,   504,   504,   504,   504,
     505,   506,   506,   506,   507,   507,   508,   508,   508,   508,
     509,   509,   510,   510,   510,   510,   510,   510,   510,   511,
     511,   512,   512,   513,   513,   513,   513,   513,   514,   514,
     515,   515,   516,   516,   516,   516,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   518,   518,   519,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   521,   521,   522,   522,   522,   523,   524,
     524,   525,   526,   527,   528,   528,   529,   529,   529,   529,
     530,   530,   531,   532,   533,   533,   534,   534,   534,   535,
     535,   535,   535,   535,   535,   536,   536,   537,   537,   538,
     539,   539,   540,   540,   541,   541,   542,   542,   542,   542,
     543,   543,   544,   544,   544,   544,   545,   545,   546,   546,
     547,   547,   547,   547,   548,   548,   548,   548,   549,   549,
     550,   550,   551,   552,   552,   552,   552,   552,   552,   552,
     553,   554,   554,   555,   555,   556,   557,   558,   558,   559,
     559,   560,   561,   561,   561,   561,   562,   562,   562,   563,
     563,   563,   563,   563,   563,   563,   564,   564,   565,   566,
     567,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     568,   569,   570,   570,   570,   571,   572,   573,   574,   574,
     574,   575,   575,   575,   575,   575,   576,   577,   577,   577,
     577,   577,   577,   577,   578,   579,   580,   581,   582,   582,
     583,   584,   584,   585,   586,   586,   586,   587,   587,   587,
     587,   587,   587,   587,   587,   587,   587,   588,   588,   589,
     589,   590,   591,   592,   592,   593,   594,   595,   595,   596,
     597,   598,   598,   599,   600,   600,   601,   601,   602,   602,
     603,   603,   604,   604,   605,   605,   606,   607,   607,   608,
     608,   609,   610,   610,   610,   611,   611,   612,   613,   613,
     614,   615,   615,   616,   616,   617,   617,   617,   618,   618,
     619,   619,   620,   620,   620,   620,   620,   621,   622,   623,
     624,   624,   624,   625,   625,   626,   626,   626,   626,   626,
     626,   626,   626,   627,   627,   627,   627,   628,   628,   629,
     630,   630,   631,   631,   631,   632,   632,   633,   633,   634,
     634,   635,   636,   636,   637,   637,   638,   638,   638,   639,
     639,   640,   640,   641,   641,   642,   642,   643,   643,   644,
     645,   645,   646,   646,   646,   647,   648,   648,   648,   648,
     649,   649,   650,   650,   651,   652,   652,   653,   653,   654,
     654,   655,   656,   656,   656,   656,   657,   657,   657,   658,
     659,   660,   661,   662,   662,   662,   663,   664,   664,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   666
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
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       2,     3,     2,     3,     2,     3,     4,     5,     5,     2,
       4,     5,     3,     3,     2,     2,     8,     3,     1,     2,
       3,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       2,     1,     1,     1,     4,     3,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       2,     1,     3,     4,     5,     3,     6,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     2,     3,
       1,     3,     4,     5,     6,     5,     1,     2,     2,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     2,     2,     2,     5,     5,     1,
       4,     3,     4,     8,     1,     2,     3,     2,     3,     8,
       1,     2,     3,     8,    10,     8,    10,     1,     2,     4,
       7,     1,     2,     4,     7,     1,     3,     8,     1,     3,
       1,     3,     1,     2,     1,     3,     3,     3,     3,     0,
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
       3,     3,     4,     5,     3,     3,     1,     2,     3,     1,
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
       7,     2,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     4,     4,     3,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     4,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     1,     1,
       4,     5,     6,     3,     3,     3,     3,     5,     7,     7,
       5,     5,     5,     7,     7,     5,     5,     3,     3,     5,
       7,     5,     7,     1,     4,     3,     5,     1,     2,     3,
       3,     1,     3,     2,     0,     1,     1,     2,     1,     3,
       1,     3,     1,     4,     1,     2,     3,     0,     1,     0,
       1,     4,     2,     3,     1,     0,     1,     4,     0,     1,
       2,     1,     3,     0,     1,     2,     2,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     3,
       1,     2,     2,     5,     2,     1,     1,     0,     2,     1,
       3,     4,     0,     2,     0,     2,     4,     4,     3,     2,
       3,     1,     3,     0,     1,     1,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     3,     2,     3,     3,     4,
       2,     2,     1,     1,     3,     2,     3,     2,     3,     2,
       3,     3,     3,     3,     5,     5,     5,     5,     8,     5,
       3,     5,     7,     3,     3,     3,     1,     1,     1,     1,
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
  "\"'$_'\"", "\"'.'\"", "\"'..'\"", "\"':'\"", "\"'::'\"", "\"'{{'\"",
  "\"'DOUBLE'\"", "\"'<double {>'\"", "\"'else'\"", "\"'empty'\"",
  "\"'greatest'\"", "\"'least'\"", "\"'/>'\"", "\"'encoding'\"", "\"'='\"",
  "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"", "\"'except'\"",
  "\"'external'\"", "\"'following'\"", "\"'following-sibling'\"",
  "\"'follows'\"", "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"", "\"'#'\"",
  "\"'idiv'\"", "\"'in'\"", "\"'inherit'\"", "\"'INTEGER'\"",
  "\"'intersect'\"", "\"'is'\"", "\"'item'\"", "\"'{'\"", "\"'['\"",
  "\"'<='\"", "\"'('\"", "\"'<'\"", "\"'-'\"", "\"'mod'\"",
  "\"'namespace'\"", "\"'nan'\"", "\"'!='\"", "\"'nodecomp'\"",
  "\"'<no inherit>'\"", "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"",
  "\"'ordered'\"", "\"'by'\"", "\"'group'\"", "\"'parent'\"", "\"'%'\"",
  "\"'<?'\"", "\"'?>'\"", "\"'+'\"", "\"'(#'\"", "\"'#)'\"", "\"'<<'\"",
  "\"'preceding'\"", "\"'preceding-sibling'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'select'\"", "\"'self'\"", "\"';'\"", "\"'/'\"",
  "\"'//'\"", "\"'!'\"", "\"'*'\"", "\"'</ (start tag end)'\"",
  "\"'strip'\"", "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"",
  "\"'treat'\"", "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"",
  "\"'|'\"", "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"",
  "\"'-->'\"", "\"'xquery'\"", "\"'jsoniq'\"", "\"'version'\"",
  "\"'start'\"", "\"'null'\"", "\"'true'\"", "\"'false'\"", "\"'after'\"",
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
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "UNARY_PREC",
  "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE", "MULTIPLICATIVE_REDUCE",
  "JSONLOOKUPEXPR_REDUCE", "$accept", "Module", "ERROR",
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
  "CatchStatement", "VoidStatement", "Expr", "ExprSingle", "ExprSimple",
  "FLWORExpr", "ReturnExpr", "ReturnOrSelect", "WindowType",
  "FLWORWinCondType", "FLWORWinCond", "WindowClause", "CountClause",
  "ForLetWinClause", "FLWORClause", "FLWORClauseList", "ForClause",
  "ForOrFrom", "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar",
  "LetClause", "VarGetsDeclList", "VarGetsDecl", "WindowVarDecl",
  "WindowVars", "WindowVars3", "WindowVars2", "WhereClause",
  "GroupByClause", "GroupSpecList", "GroupSpec", "GroupCollationSpec",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderModifier",
  "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "SwitchExpr", "SwitchCaseClauseList",
  "SwitchCaseClause", "SwitchCaseOperandList", "SwitchStatement",
  "SwitchCaseStatementList", "SwitchCaseStatement", "TypeswitchExpr",
  "TypeswitchStatement", "CaseClauseList", "CaseClause",
  "CaseStatementList", "CaseStatement", "SequenceTypeList", "IfExpr",
  "OrExpr", "AndExpr", "NotExpr", "ComparisonExpr", "$@1",
  "FTContainsExpr", "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr",
  "AdditiveExpr", "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
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
  const jsoniq_parser::rhs_number_type
  jsoniq_parser::yyrhs_[] =
  {
       341,     0,    -1,   343,    -1,   327,   343,    -1,   328,   343,
      -1,   327,   328,   343,    -1,     1,    -1,     1,     3,    -1,
     342,     1,    -1,   345,    -1,   344,   345,    -1,   346,    -1,
     344,   346,    -1,   218,   219,    30,   192,    -1,   218,   219,
      30,   133,    30,   192,    -1,   348,   192,   395,    -1,   365,
     192,   395,    -1,   348,   192,   365,   192,   395,    -1,   395,
      -1,   348,   342,   395,    -1,   365,   342,   395,    -1,   348,
     192,   365,   342,   395,    -1,   348,   342,   365,   192,   395,
      -1,   347,    -1,   347,   348,   192,    -1,   347,   365,   192,
      -1,   347,   348,   192,   365,   192,    -1,    34,   162,   664,
     134,   663,   192,    -1,   349,    -1,   348,   192,   349,    -1,
     348,   342,   349,    -1,   350,    -1,   358,    -1,   363,    -1,
     364,    -1,   372,    -1,   351,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   586,    -1,
      33,    38,   183,    -1,    33,    38,   198,    -1,    33,   114,
     107,   663,    -1,    33,    37,   663,    -1,    33,    40,   183,
      -1,    33,    40,   198,    -1,    33,    58,   170,    -1,    33,
      58,   204,    -1,    33,   114,   169,   129,   130,    -1,    33,
     114,   169,   129,   131,    -1,    33,    41,   183,   108,   150,
      -1,    33,    41,   183,   108,   166,    -1,    33,    41,   167,
     108,   150,    -1,    33,    41,   167,   108,   166,    -1,   359,
      -1,   362,    -1,    49,    25,     1,    -1,    49,    61,   663,
      -1,    49,    61,   361,   663,    -1,    49,    61,   663,    97,
     360,    -1,    49,    61,   361,   663,    97,   360,    -1,   663,
      -1,   360,   108,   663,    -1,   162,   664,   134,    -1,   114,
      45,   162,    -1,    49,    34,   663,    -1,    49,    34,   162,
     664,   134,   663,    -1,    49,    34,   663,    97,   360,    -1,
      49,    34,   162,   664,   134,   663,    97,   360,    -1,    33,
     162,   664,   134,   663,    -1,    33,   114,    45,   162,   663,
      -1,    33,   114,    47,   162,   663,    -1,   366,    -1,   365,
     192,   366,    -1,   365,   342,   366,    -1,   367,    -1,   371,
      -1,   373,    -1,   377,    -1,   382,    -1,   389,    -1,   391,
      -1,   394,    -1,    33,   114,    80,   368,    -1,    33,    80,
     664,   368,    -1,   369,    -1,   368,   369,    -1,   370,   134,
     581,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    33,    57,   664,    30,    -1,    33,   267,   625,
      -1,    33,   112,   154,   374,    -1,    95,   563,   375,    -1,
     375,    -1,   376,    -1,   139,    -1,   139,   376,    -1,   144,
     420,    -1,    33,   378,   144,   420,    -1,    33,   378,   139,
      -1,    33,   378,   139,   144,   420,    -1,   113,   119,   664,
      -1,   113,   119,   664,   560,    -1,   379,   113,   119,   664,
      -1,   379,   113,   119,   664,   560,    -1,   380,    -1,   379,
     380,    -1,    27,    -1,    27,   158,   381,   188,    -1,    28,
      -1,    28,   158,   381,   188,    -1,   521,    -1,   381,   108,
     521,    -1,    33,   383,    -1,    33,   379,   383,    -1,   384,
      -1,   385,    -1,    47,   665,   386,   403,    -1,    47,   665,
     386,   139,    -1,    75,    47,   665,   386,   403,    -1,    75,
      47,   665,   386,   139,    -1,   158,   188,    -1,   158,   387,
     188,    -1,   158,   188,    95,   561,    -1,   158,   387,   188,
      95,   561,    -1,   388,    -1,   387,   108,   388,    -1,   119,
     664,    -1,   119,   664,   560,    -1,    33,   293,   664,    -1,
      33,   293,   664,    95,   390,    -1,    33,   379,   293,   664,
      -1,    33,   379,   293,   664,    95,   390,    -1,   567,    -1,
     567,   562,    -1,   662,    -1,   662,   562,    -1,    33,   301,
     664,   305,   233,   504,   171,   392,    -1,    33,   379,   301,
     664,   305,   233,   504,   171,   392,    -1,   393,    -1,   392,
     108,   393,    -1,   504,    -1,   504,   560,    -1,   504,   457,
      -1,   504,   560,   457,    -1,    33,   309,   310,   664,   305,
     293,   664,   119,   664,   311,   420,    -1,    33,   309,   310,
     664,   305,   293,   664,   231,   119,   664,   311,   299,   312,
     504,    -1,    33,   309,   310,   664,   305,   293,   664,   313,
     231,   119,   664,   311,   420,    -1,    33,   309,   310,   664,
     314,   312,   263,   293,   664,   231,   119,   664,   312,   504,
     201,   293,   664,   231,   119,   664,   312,   504,    -1,   396,
      -1,   398,    -1,   399,    -1,    -1,   398,    -1,   399,    -1,
      -1,   419,    -1,   399,   419,    -1,   400,    -1,   399,   400,
      -1,   399,   419,   342,   400,    -1,   401,    -1,   404,    -1,
     407,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   414,    -1,   469,    -1,   465,    -1,   415,    -1,
     418,    -1,   155,   399,   185,    -1,   155,   397,   185,    -1,
     155,   397,   185,    -1,   405,   192,    -1,   405,   108,   406,
      -1,   113,   406,    -1,   379,   113,   406,    -1,   119,   664,
      -1,   119,   664,   560,    -1,   119,   664,   144,   420,    -1,
     119,   664,   560,   144,   420,    -1,   119,   664,   144,   420,
     192,    -1,   421,   192,    -1,   246,   248,   420,   192,    -1,
     249,   158,   419,   188,   400,    -1,   244,   247,   192,    -1,
     245,   247,   192,    -1,   432,   413,    -1,   424,   400,    -1,
      48,   158,   419,   188,   200,   400,   128,   400,    -1,   250,
     401,   416,    -1,   417,    -1,   416,   417,    -1,   251,   598,
     401,    -1,   192,    -1,   420,    -1,   419,   108,   420,    -1,
     419,   342,   420,    -1,   422,    -1,   461,    -1,   468,    -1,
     475,    -1,   594,    -1,   421,    -1,   476,    -1,   458,    -1,
     587,    -1,   588,    -1,   590,    -1,   589,    -1,   591,    -1,
     659,    -1,   657,    -1,   660,    -1,   661,    -1,   658,    -1,
     432,   423,    -1,   424,   420,    -1,   187,    -1,   190,    -1,
      67,   290,    -1,    72,   290,    -1,   220,    -1,   260,    -1,
      56,   260,    -1,   426,   443,    78,   420,    -1,   426,    78,
     420,    -1,   434,   425,   442,   427,   427,    -1,   434,   425,
     442,   427,    -1,    42,   119,   664,    -1,   433,    -1,   439,
      -1,   428,    -1,   430,    -1,   446,    -1,   451,    -1,   447,
      -1,   429,    -1,   430,    -1,   432,   431,    -1,   434,   119,
     435,    -1,    46,     1,   435,    -1,   263,     1,   435,    -1,
     434,     3,    -1,    46,    -1,   263,    -1,   436,    -1,   435,
     108,   119,   436,    -1,   435,   108,   436,    -1,   664,   149,
     420,    -1,   664,    36,   129,   149,   420,    -1,   664,   560,
     149,   420,    -1,   664,   560,    36,   129,   149,   420,    -1,
     664,   437,   149,   420,    -1,   664,    36,   129,   437,   149,
     420,    -1,   664,   560,   437,   149,   420,    -1,   664,   560,
      36,   129,   437,   149,   420,    -1,   664,   438,   149,   420,
      -1,   664,   560,   438,   149,   420,    -1,   664,   437,   438,
     149,   420,    -1,   664,   560,   437,   438,   149,   420,    -1,
      97,   119,   664,    -1,   279,   119,   664,    -1,    51,   440,
      -1,   441,    -1,   440,   108,   441,    -1,   119,   664,   144,
     420,    -1,   119,   664,   560,   144,   420,    -1,   438,   144,
     420,    -1,   119,   664,   560,   438,   144,   420,    -1,   119,
     664,   149,   420,    -1,   119,   664,   560,   149,   420,    -1,
     444,    -1,   119,   664,    -1,   119,   664,   444,    -1,   437,
      -1,   437,   445,    -1,   445,    -1,    59,   119,   664,    54,
     119,   664,    -1,    54,   119,   664,    -1,    59,   119,   664,
      -1,   214,   420,    -1,   172,   171,   448,    -1,   449,    -1,
     448,   108,   449,    -1,   119,   664,   144,   420,    -1,   119,
     664,   560,   144,   420,    -1,   119,   664,   560,   144,   420,
     450,    -1,   119,   664,   144,   420,   450,    -1,   420,    -1,
     420,   450,    -1,   107,   663,    -1,   169,   171,   452,    -1,
      70,   169,   171,   452,    -1,   453,    -1,   452,   108,   453,
      -1,   420,    -1,   420,   454,    -1,   455,    -1,   456,    -1,
     457,    -1,   455,   456,    -1,   455,   457,    -1,   456,   457,
      -1,   455,   456,   457,    -1,    96,    -1,   117,    -1,   129,
     130,    -1,   129,   131,    -1,   107,   663,    -1,    68,   119,
     459,   189,   420,    -1,   137,   119,   459,   189,   420,    -1,
     460,    -1,   459,   108,   119,   460,    -1,   664,   149,   420,
      -1,   664,   560,   149,   420,    -1,    73,   158,   419,   188,
     462,   114,   424,   420,    -1,   463,    -1,   462,   463,    -1,
     464,   424,   420,    -1,   101,   420,    -1,   464,   101,   420,
      -1,    73,   158,   419,   188,   466,   114,   424,   400,    -1,
     467,    -1,   466,   467,    -1,   464,   424,   400,    -1,    74,
     158,   419,   188,   470,   114,   424,   420,    -1,    74,   158,
     419,   188,   470,   114,   119,   664,   424,   420,    -1,    74,
     158,   419,   188,   472,   114,   424,   400,    -1,    74,   158,
     419,   188,   470,   114,   119,   664,   424,   400,    -1,   471,
      -1,   470,   471,    -1,   101,   474,   424,   420,    -1,   101,
     119,   664,    95,   474,   424,   420,    -1,   473,    -1,   472,
     473,    -1,   101,   474,   424,   400,    -1,   101,   119,   664,
      95,   474,   424,   400,    -1,   561,    -1,   474,   212,   561,
      -1,    48,   158,   419,   188,   200,   420,   128,   420,    -1,
     477,    -1,   476,   168,   477,    -1,   478,    -1,   477,    93,
     478,    -1,   479,    -1,   266,   478,    -1,   481,    -1,   481,
     498,   481,    -1,   481,   499,   481,    -1,   481,   134,   481,
      -1,   481,   164,   481,    -1,    -1,   481,   159,   480,   481,
      -1,   481,   157,   481,    -1,   481,   145,   481,    -1,   481,
     143,   481,    -1,   482,    -1,   482,   255,    71,   599,   483,
      -1,   484,    -1,   484,   100,   482,    -1,    -1,   651,    -1,
     485,    -1,   485,   201,   485,    -1,   486,    -1,   485,   177,
     486,    -1,   485,   160,   486,    -1,   487,    -1,   486,   196,
     487,    -1,   486,   118,   487,    -1,   486,   148,   487,    -1,
     486,   161,   487,    -1,   488,    -1,   487,   203,   488,    -1,
     487,   212,   488,    -1,   489,    -1,   488,   152,   489,    -1,
     488,   138,   489,    -1,   490,    -1,   490,    50,   237,   561,
      -1,   491,    -1,   491,   202,    95,   561,    -1,   492,    -1,
     492,   102,    95,   493,    -1,   494,    -1,   494,   103,    95,
     493,    -1,   566,    -1,   566,   146,    -1,   496,    -1,   495,
     496,    -1,   177,    -1,   160,    -1,   495,   177,    -1,   495,
     160,    -1,   500,    -1,   497,    -1,   501,    -1,   504,    -1,
     497,   195,   504,    -1,   205,    -1,   210,    -1,   209,    -1,
     208,    -1,   207,    -1,   206,    -1,   153,    -1,   180,    -1,
     142,    -1,    76,   155,   398,   185,    -1,    76,   228,   155,
     398,   185,    -1,    76,   227,   155,   398,   185,    -1,    76,
      77,   579,   155,   398,   185,    -1,   502,   155,   397,   185,
      -1,   503,    -1,   502,   503,    -1,   178,   664,    17,    -1,
     178,    18,    -1,   178,    19,    -1,   505,    -1,   505,   506,
      -1,   194,   506,    -1,   506,    -1,   193,    -1,   507,    -1,
     507,   193,   506,    -1,   507,   194,   506,    -1,   508,    -1,
     517,    -1,   509,    -1,   509,   518,    -1,   512,    -1,   512,
     518,    -1,   510,   514,    -1,   511,    -1,   106,   124,    -1,
     115,   124,    -1,    98,   124,    -1,   191,   124,    -1,   116,
     124,    -1,   141,   124,    -1,   140,   124,    -1,   514,    -1,
      99,   514,    -1,   513,   514,    -1,   122,    -1,   173,   124,
      -1,    91,   124,    -1,   182,   124,    -1,   181,   124,    -1,
      92,   124,    -1,   567,    -1,   515,    -1,   664,    -1,   516,
      -1,   196,    -1,    11,    -1,    12,    -1,    20,    -1,   520,
      -1,   517,   518,    -1,   517,   158,   188,    -1,   517,   158,
     529,   188,    -1,   517,   156,   186,    -1,   517,   121,   664,
      -1,   517,   121,   158,   188,    -1,   517,   121,   158,   419,
     188,    -1,   517,   121,   523,    -1,   517,   121,   581,    -1,
     519,    -1,   518,   519,    -1,   156,   419,   186,    -1,   521,
      -1,   523,    -1,   524,    -1,   525,    -1,   528,    -1,   533,
      -1,   526,    -1,   527,    -1,   530,    -1,   402,    -1,   655,
      -1,   652,    -1,   653,    -1,   654,    -1,   522,    -1,   581,
      -1,   111,    -1,   151,    -1,   126,    -1,   119,   664,    -1,
     158,   188,    -1,   158,   419,   188,    -1,   120,    -1,   170,
     155,   419,   185,    -1,   204,   155,   419,   185,    -1,   665,
     158,   188,    -1,   665,   158,   529,   188,    -1,   146,    -1,
     529,   108,   146,    -1,   420,    -1,   529,   108,   420,    -1,
     531,    -1,   532,    -1,   665,   147,   151,    -1,    47,   386,
     403,    -1,   534,    -1,   552,    -1,   535,    -1,   549,    -1,
     550,    -1,   159,   664,   539,   132,    -1,   159,   664,   539,
     199,   197,   664,   539,   199,    -1,   159,   664,   537,   539,
     132,    -1,   159,   664,   537,   539,   199,   197,   664,   539,
     199,    -1,   159,   664,   539,   199,   536,   197,   664,   539,
     199,    -1,   159,   664,   537,   539,   199,   536,   197,   664,
     539,   199,    -1,   547,    -1,   536,   547,    -1,   538,    -1,
     537,   538,    -1,    35,   664,   539,   134,   539,   540,    -1,
      -1,    35,    -1,   184,   541,   184,    -1,    94,   543,    94,
      -1,    -1,   542,    -1,   136,    -1,   545,    -1,   542,   136,
      -1,   542,   545,    -1,    -1,   544,    -1,   135,    -1,   546,
      -1,   544,   135,    -1,   544,   546,    -1,    29,    -1,   548,
      -1,     5,    -1,   548,    -1,   534,    -1,    10,    -1,   551,
      -1,   548,    -1,     9,    -1,   125,    -1,   127,    -1,   155,
     398,   185,    -1,   215,    31,   216,    -1,   215,   216,    -1,
     175,   664,   176,    -1,   175,   664,     8,    -1,   104,     7,
      -1,   553,    -1,   554,    -1,   555,    -1,   556,    -1,   557,
      -1,   558,    -1,   559,    -1,    43,   155,   398,   185,    -1,
      21,   397,   185,    -1,    45,   155,   419,   185,   155,   397,
     185,    -1,    22,   397,   185,    -1,    98,   155,   419,   185,
     155,   397,   185,    -1,    71,   155,   398,   185,    -1,    39,
     155,   398,   185,    -1,    23,   397,   185,    -1,    60,   155,
     419,   185,   155,   397,   185,    -1,    24,   398,   185,    -1,
     162,   155,   419,   185,   155,   398,   185,    -1,    95,   561,
      -1,   563,    -1,   563,   562,    -1,   213,   158,   188,    -1,
     158,   188,    -1,   146,    -1,   196,    -1,   177,    -1,   565,
      -1,   567,    -1,   154,   158,   188,    -1,   326,   158,   188,
      -1,   582,    -1,   585,    -1,   662,    -1,   561,    -1,   564,
     108,   561,    -1,   664,    -1,   664,    -1,   570,    -1,   577,
      -1,   575,    -1,   578,    -1,   576,    -1,   574,    -1,   573,
      -1,   572,    -1,   571,    -1,   568,    -1,   569,   158,   188,
      -1,   231,    -1,    44,   158,   188,    -1,    44,   158,   577,
     188,    -1,    44,   158,   578,   188,    -1,    53,   158,   188,
      -1,    71,   158,   188,    -1,    39,   158,   188,    -1,    60,
     158,   188,    -1,    60,   158,   664,   188,    -1,    60,   158,
      30,   188,    -1,    98,   158,   188,    -1,    98,   158,   664,
     188,    -1,    98,   158,   664,   108,   579,   188,    -1,    98,
     158,   196,   188,    -1,    98,   158,   196,   108,   579,   188,
      -1,    62,   158,   664,   188,    -1,    45,   158,   188,    -1,
      45,   158,   664,   188,    -1,    45,   158,   664,   108,   579,
     188,    -1,    45,   158,   664,   108,   580,   188,    -1,    45,
     158,   196,   188,    -1,    45,   158,   196,   108,   579,   188,
      -1,    45,   158,   196,   108,   580,   188,    -1,    63,   158,
     664,   188,    -1,   664,    -1,   664,   146,    -1,    30,    -1,
     583,    -1,   584,    -1,    47,   158,   196,   188,    -1,    47,
     158,   188,    95,   561,    -1,    47,   158,   564,   188,    95,
     561,    -1,   158,   563,   188,    -1,    33,   226,   227,    -1,
      33,   226,   228,    -1,    33,   226,   229,    -1,   232,   231,
     420,   239,   420,    -1,   232,   231,   420,    95,   238,   239,
     420,    -1,   232,   231,   420,    95,   240,   239,   420,    -1,
     232,   231,   420,   224,   420,    -1,   232,   231,   420,   225,
     420,    -1,   232,   233,   420,   239,   420,    -1,   232,   233,
     420,    95,   238,   239,   420,    -1,   232,   233,   420,    95,
     240,   239,   420,    -1,   232,   233,   420,   224,   420,    -1,
     232,   233,   420,   225,   420,    -1,   230,   231,   420,    -1,
     230,   233,   420,    -1,   235,   231,   420,   243,   420,    -1,
     235,   236,   237,   231,   420,   243,   420,    -1,   234,   231,
     420,    95,   420,    -1,   242,   119,   592,   241,   420,   424,
     420,    -1,   593,    -1,   592,   108,   119,   593,    -1,   664,
     144,   420,    -1,   250,   155,   419,   185,   595,    -1,   596,
      -1,   595,   596,    -1,   251,   598,   597,    -1,   155,   419,
     185,    -1,   515,    -1,   598,   212,   515,    -1,   602,   600,
      -1,    -1,   601,    -1,   620,    -1,   601,   620,    -1,   603,
      -1,   602,   268,   603,    -1,   604,    -1,   603,   264,   604,
      -1,   605,    -1,   604,   266,   149,   605,    -1,   606,    -1,
     265,   606,    -1,   610,   607,   608,    -1,    -1,   625,    -1,
      -1,   609,    -1,   288,   155,   419,   185,    -1,   614,   611,
      -1,   158,   599,   188,    -1,   612,    -1,    -1,   647,    -1,
     502,   155,   613,   185,    -1,    -1,   599,    -1,   615,   616,
      -1,   521,    -1,   155,   419,   185,    -1,    -1,   617,    -1,
     254,   618,    -1,   253,   619,    -1,   276,    -1,    -1,    79,
      -1,    -1,   292,    -1,   621,    -1,   622,    -1,   623,    -1,
     649,    -1,   646,    -1,   170,    -1,   290,   485,   624,    -1,
     259,   648,   624,    -1,   292,    -1,   282,    -1,   275,    -1,
     252,   626,    -1,   625,   252,   626,    -1,   627,    -1,   628,
      -1,   629,    -1,   644,    -1,   630,    -1,   638,    -1,   631,
      -1,   645,    -1,   101,   280,    -1,   101,   269,    -1,   272,
      -1,   287,    -1,   257,   280,    -1,   257,   269,    -1,    57,
     664,    30,    -1,   283,    -1,    55,   283,    -1,   285,   632,
      -1,   285,   158,   632,   633,   188,    -1,    55,   285,    -1,
     635,    -1,   114,    -1,    -1,   108,   634,    -1,   635,    -1,
     634,   108,   635,    -1,    97,    30,   636,   637,    -1,    -1,
     277,    30,    -1,    -1,   648,   271,    -1,   284,   292,   639,
     641,    -1,   284,   292,   114,   641,    -1,    55,   284,   292,
      -1,    97,    30,    -1,   158,   640,   188,    -1,    30,    -1,
     640,   108,    30,    -1,    -1,   642,    -1,   643,    -1,   642,
     643,    -1,   203,   639,    -1,   138,   639,    -1,   270,    30,
      -1,   289,    -1,    55,   289,    -1,    97,   220,    -1,    97,
     260,    -1,   261,   256,    -1,   273,   648,   286,    -1,   262,
     485,    -1,    97,   131,   485,    -1,    97,    52,   485,    -1,
     263,   485,   201,   485,    -1,   278,   650,    -1,   258,   650,
      -1,   281,    -1,   274,    -1,   291,   256,   487,    -1,   156,
     186,    -1,   156,   419,   186,    -1,   316,   317,    -1,   316,
     419,   317,    -1,   318,   319,    -1,   318,   419,   319,    -1,
     155,   656,   185,    -1,   664,   123,   420,    -1,   420,   123,
     420,    -1,   656,   108,   420,   123,   420,    -1,   656,   108,
     664,   123,   420,    -1,   232,   320,   420,   239,   420,    -1,
     232,   320,   656,   239,   420,    -1,   232,   320,   420,   239,
     420,    97,   322,   420,    -1,   321,   320,   420,   239,   420,
      -1,   230,   320,   517,    -1,   234,   320,   517,    95,   420,
      -1,   235,   236,   237,   320,   517,   243,   420,    -1,   325,
     158,   188,    -1,   324,   158,   188,    -1,   323,   158,   188,
      -1,    30,    -1,   665,    -1,    16,    -1,    98,    -1,    39,
      -1,    44,    -1,    53,    -1,    45,    -1,   154,    -1,    48,
      -1,   231,    -1,    60,    -1,    62,    -1,    63,    -1,    71,
      -1,    74,    -1,    73,    -1,   213,    -1,   249,    -1,   320,
      -1,   324,    -1,   323,    -1,   325,    -1,   326,    -1,   666,
      -1,    25,    -1,   217,    -1,   129,    -1,    38,    -1,   267,
      -1,    37,    -1,   228,    -1,   227,    -1,   148,    -1,    43,
      -1,   265,    -1,   266,    -1,   280,    -1,   269,    -1,   257,
      -1,   291,    -1,   283,    -1,   285,    -1,   284,    -1,   289,
      -1,   261,    -1,   256,    -1,    79,    -1,   220,    -1,   260,
      -1,    52,    -1,   229,    -1,   242,    -1,   308,    -1,   236,
      -1,   205,    -1,   210,    -1,   209,    -1,   208,    -1,   207,
      -1,   206,    -1,    97,    -1,   112,    -1,   113,    -1,   187,
      -1,    46,    -1,   263,    -1,    36,    -1,    67,    -1,    72,
      -1,    59,    -1,    54,    -1,    56,    -1,    78,    -1,    42,
      -1,   149,    -1,    51,    -1,   214,    -1,   171,    -1,   172,
      -1,   169,    -1,    70,    -1,    96,    -1,   117,    -1,   130,
      -1,   131,    -1,   107,    -1,    68,    -1,   137,    -1,   189,
      -1,   101,    -1,    95,    -1,   200,    -1,   128,    -1,   168,
      -1,    93,    -1,    50,    -1,   237,    -1,   102,    -1,   201,
      -1,   118,    -1,   161,    -1,   203,    -1,   152,    -1,   138,
      -1,    76,    -1,    77,    -1,   103,    -1,   202,    -1,   153,
      -1,   183,    -1,   198,    -1,   162,    -1,   139,    -1,   133,
      -1,   167,    -1,   150,    -1,   166,    -1,    33,    -1,    40,
      -1,    58,    -1,   114,    -1,    41,    -1,    57,    -1,   219,
      -1,    49,    -1,    61,    -1,    34,    -1,    47,    -1,   279,
      -1,   255,    -1,   288,    -1,   290,    -1,   259,    -1,   273,
      -1,   286,    -1,   278,    -1,   258,    -1,   272,    -1,   287,
      -1,   277,    -1,   271,    -1,   270,    -1,   254,    -1,   253,
      -1,   262,    -1,   292,    -1,   282,    -1,   281,    -1,   276,
      -1,   274,    -1,   275,    -1,   241,    -1,   238,    -1,   321,
      -1,   232,    -1,   235,    -1,   234,    -1,   230,    -1,   225,
      -1,   224,    -1,   226,    -1,   243,    -1,   233,    -1,   240,
      -1,   239,    -1,    66,    -1,    64,    -1,    75,    -1,   170,
      -1,   204,    -1,   248,    -1,   246,    -1,   247,    -1,   244,
      -1,   245,    -1,   250,    -1,   251,    -1,   252,    -1,    65,
      -1,   301,    -1,   299,    -1,   300,    -1,   305,    -1,   306,
      -1,   307,    -1,   302,    -1,   303,    -1,   304,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,   293,    -1,   294,    -1,   295,    -1,   296,    -1,   297,
      -1,   298,    -1,   309,    -1,   310,    -1,   311,    -1,   312,
      -1,   313,    -1,   314,    -1,   315,    -1,    91,    -1,   106,
      -1,   115,    -1,   173,    -1,   181,    -1,   191,    -1,   140,
      -1,    92,    -1,   116,    -1,   141,    -1,   182,    -1,   322,
      -1,   221,    -1,   222,    -1,   223,    -1,   190,    -1,   218,
      -1,    26,    -1
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
     688,   690,   692,   694,   696,   698,   700,   702,   706,   710,
     714,   717,   721,   724,   728,   731,   735,   740,   746,   752,
     755,   760,   766,   770,   774,   777,   780,   789,   793,   795,
     798,   802,   804,   806,   810,   814,   816,   818,   820,   822,
     824,   826,   828,   830,   832,   834,   836,   838,   840,   842,
     844,   846,   848,   850,   853,   856,   858,   860,   863,   866,
     868,   870,   873,   878,   882,   888,   893,   897,   899,   901,
     903,   905,   907,   909,   911,   913,   915,   918,   922,   926,
     930,   933,   935,   937,   939,   944,   948,   952,   958,   963,
     970,   975,   982,   988,   996,  1001,  1007,  1013,  1020,  1024,
    1028,  1031,  1033,  1037,  1042,  1048,  1052,  1059,  1064,  1070,
    1072,  1075,  1079,  1081,  1084,  1086,  1093,  1097,  1101,  1104,
    1108,  1110,  1114,  1119,  1125,  1132,  1138,  1140,  1143,  1146,
    1150,  1155,  1157,  1161,  1163,  1166,  1168,  1170,  1172,  1175,
    1178,  1181,  1185,  1187,  1189,  1192,  1195,  1198,  1204,  1210,
    1212,  1217,  1221,  1226,  1235,  1237,  1240,  1244,  1247,  1251,
    1260,  1262,  1265,  1269,  1278,  1289,  1298,  1309,  1311,  1314,
    1319,  1327,  1329,  1332,  1337,  1345,  1347,  1351,  1360,  1362,
    1366,  1368,  1372,  1374,  1377,  1379,  1383,  1387,  1391,  1395,
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
    1723,  1727,  1731,  1736,  1742,  1746,  1750,  1752,  1755,  1759,
    1761,  1763,  1765,  1767,  1769,  1771,  1773,  1775,  1777,  1779,
    1781,  1783,  1785,  1787,  1789,  1791,  1793,  1795,  1797,  1800,
    1803,  1807,  1809,  1814,  1819,  1823,  1828,  1830,  1834,  1836,
    1840,  1842,  1844,  1848,  1852,  1854,  1856,  1858,  1860,  1862,
    1867,  1876,  1882,  1892,  1902,  1913,  1915,  1918,  1920,  1923,
    1930,  1931,  1933,  1937,  1941,  1942,  1944,  1946,  1948,  1951,
    1954,  1955,  1957,  1959,  1961,  1964,  1967,  1969,  1971,  1973,
    1975,  1977,  1979,  1981,  1983,  1985,  1987,  1989,  1993,  1997,
    2000,  2004,  2008,  2011,  2013,  2015,  2017,  2019,  2021,  2023,
    2025,  2030,  2034,  2042,  2046,  2054,  2059,  2064,  2068,  2076,
    2080,  2088,  2091,  2093,  2096,  2100,  2103,  2105,  2107,  2109,
    2111,  2113,  2117,  2121,  2123,  2125,  2127,  2129,  2133,  2135,
    2137,  2139,  2141,  2143,  2145,  2147,  2149,  2151,  2153,  2155,
    2157,  2161,  2163,  2167,  2172,  2177,  2181,  2185,  2189,  2193,
    2198,  2203,  2207,  2212,  2219,  2224,  2231,  2236,  2240,  2245,
    2252,  2259,  2264,  2271,  2278,  2283,  2285,  2288,  2290,  2292,
    2294,  2299,  2305,  2312,  2316,  2320,  2324,  2328,  2334,  2342,
    2350,  2356,  2362,  2368,  2376,  2384,  2390,  2396,  2400,  2404,
    2410,  2418,  2424,  2432,  2434,  2439,  2443,  2449,  2451,  2454,
    2458,  2462,  2464,  2468,  2471,  2472,  2474,  2476,  2479,  2481,
    2485,  2487,  2491,  2493,  2498,  2500,  2503,  2507,  2508,  2510,
    2511,  2513,  2518,  2521,  2525,  2527,  2528,  2530,  2535,  2536,
    2538,  2541,  2543,  2547,  2548,  2550,  2553,  2556,  2558,  2559,
    2561,  2562,  2564,  2566,  2568,  2570,  2572,  2574,  2576,  2580,
    2584,  2586,  2588,  2590,  2593,  2597,  2599,  2601,  2603,  2605,
    2607,  2609,  2611,  2613,  2616,  2619,  2621,  2623,  2626,  2629,
    2633,  2635,  2638,  2641,  2647,  2650,  2652,  2654,  2655,  2658,
    2660,  2664,  2669,  2670,  2673,  2674,  2677,  2682,  2687,  2691,
    2694,  2698,  2700,  2704,  2705,  2707,  2709,  2712,  2715,  2718,
    2721,  2723,  2726,  2729,  2732,  2735,  2739,  2742,  2746,  2750,
    2755,  2758,  2761,  2763,  2765,  2769,  2772,  2776,  2779,  2783,
    2786,  2790,  2794,  2798,  2802,  2808,  2814,  2820,  2826,  2835,
    2841,  2845,  2851,  2859,  2863,  2867,  2871,  2873,  2875,  2877,
    2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,  2897,
    2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,
    2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,
    2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,
    2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,
    2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,
    2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,
    3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,
    3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,
    3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,
    3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,
    3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,
    3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,
    3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,
    3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,
    3179,  3181,  3183,  3185,  3187,  3189,  3191,  3193,  3195,  3197,
    3199,  3201,  3203,  3205,  3207,  3209,  3211,  3213,  3215,  3217,
    3219,  3221,  3223,  3225,  3227,  3229,  3231,  3233,  3235,  3237,
    3239,  3241,  3243,  3245,  3247,  3249,  3251,  3253,  3255,  3257,
    3259,  3261,  3263,  3265,  3267,  3269,  3271,  3273,  3275,  3277,
    3279,  3281,  3283,  3285,  3287,  3289,  3291,  3293,  3295,  3297,
    3299,  3301,  3303,  3305,  3307,  3309,  3311,  3313,  3315,  3317,
    3319,  3321,  3323,  3325,  3327,  3329,  3331
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1147,  1147,  1148,  1152,  1156,  1164,  1170,  1174,  1183,
    1189,  1197,  1203,  1214,  1219,  1228,  1235,  1242,  1251,  1258,
    1266,  1274,  1282,  1293,  1298,  1305,  1312,  1324,  1334,  1341,
    1348,  1360,  1361,  1362,  1363,  1364,  1369,  1370,  1371,  1372,
    1373,  1374,  1375,  1378,  1383,  1388,  1396,  1404,  1412,  1417,
    1425,  1430,  1438,  1443,  1451,  1456,  1461,  1466,  1474,  1476,
    1479,  1489,  1494,  1502,  1510,  1521,  1528,  1539,  1545,  1553,
    1560,  1567,  1576,  1590,  1599,  1606,  1616,  1623,  1630,  1641,
    1642,  1643,  1644,  1645,  1646,  1647,  1648,  1653,  1659,  1668,
    1675,  1685,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1709,  1728,  1736,  1744,  1751,  1759,  1766,  1771,
    1779,  1787,  1801,  1815,  1832,  1837,  1845,  1853,  1864,  1869,
    1878,  1883,  1890,  1895,  1905,  1910,  1919,  1925,  1938,  1939,
    1944,  1959,  1974,  1990,  2005,  2010,  2015,  2020,  2028,  2035,
    2046,  2051,  2061,  2070,  2079,  2088,  2100,  2104,  2110,  2114,
    2124,  2134,  2147,  2153,  2162,  2167,  2174,  2181,  2192,  2202,
    2212,  2222,  2240,  2260,  2264,  2269,  2276,  2280,  2285,  2292,
    2297,  2309,  2316,  2326,  2341,  2342,  2343,  2344,  2345,  2346,
    2347,  2349,  2350,  2351,  2352,  2353,  2354,  2359,  2367,  2399,
    2407,  2415,  2422,  2429,  2440,  2449,  2458,  2467,  2480,  2488,
    2496,  2504,  2519,  2524,  2532,  2546,  2563,  2588,  2596,  2603,
    2614,  2623,  2631,  2636,  2649,  2666,  2667,  2668,  2669,  2670,
    2671,  2676,  2677,  2680,  2681,  2682,  2683,  2684,  2687,  2688,
    2689,  2690,  2691,  2696,  2710,  2718,  2721,  2729,  2734,  2742,
    2747,  2752,  2760,  2769,  2781,  2791,  2804,  2812,  2813,  2814,
    2819,  2820,  2821,  2822,  2823,  2828,  2835,  2845,  2850,  2859,
    2868,  2878,  2881,  2890,  2897,  2905,  2917,  2927,  2937,  2947,
    2957,  2967,  2977,  2987,  2998,  3007,  3017,  3027,  3043,  3052,
    3061,  3069,  3075,  3087,  3095,  3105,  3113,  3125,  3131,  3142,
    3144,  3148,  3156,  3160,  3165,  3169,  3173,  3177,  3187,  3195,
    3202,  3208,  3218,  3222,  3230,  3238,  3246,  3254,  3266,  3274,
    3280,  3290,  3296,  3306,  3310,  3320,  3326,  3332,  3338,  3347,
    3356,  3365,  3378,  3382,  3390,  3396,  3406,  3414,  3423,  3436,
    3443,  3455,  3459,  3471,  3478,  3484,  3493,  3500,  3506,  3517,
    3524,  3530,  3539,  3548,  3555,  3566,  3573,  3585,  3591,  3603,
    3609,  3620,  3626,  3637,  3643,  3654,  3660,  3671,  3680,  3684,
    3697,  3707,  3718,  3722,  3737,  3741,  3751,  3758,  3767,  3777,
    3776,  3794,  3803,  3812,  3825,  3829,  3841,  3845,  3853,  3856,
    3863,  3867,  3876,  3880,  3884,  3892,  3896,  3902,  3908,  3914,
    3924,  3928,  3932,  3940,  3944,  3950,  3960,  3964,  3974,  3978,
    3988,  3992,  4002,  4006,  4016,  4020,  4029,  4033,  4041,  4045,
    4049,  4053,  4063,  4064,  4065,  4069,  4074,  4082,  4086,  4090,
    4094,  4098,  4102,  4110,  4114,  4118,  4126,  4130,  4134,  4138,
    4149,  4159,  4165,  4175,  4179,  4183,  4189,  4193,  4203,  4213,
    4266,  4275,  4285,  4289,  4298,  4299,  4305,  4311,  4319,  4325,
    4338,  4344,  4355,  4359,  4363,  4367,  4371,  4377,  4383,  4392,
    4396,  4405,  4409,  4421,  4425,  4429,  4435,  4439,  4454,  4455,
    4461,  4465,  4475,  4479,  4483,  4487,  4499,  4504,  4508,  4512,
    4518,  4522,  4528,  4534,  4540,  4544,  4553,  4559,  4570,  4578,
    4579,  4580,  4581,  4582,  4583,  4584,  4585,  4586,  4587,  4590,
    4591,  4592,  4593,  4598,  4602,  4610,  4617,  4624,  4635,  4643,
    4647,  4655,  4666,  4674,  4680,  4684,  4706,  4712,  4718,  4724,
    4734,  4738,  4746,  4754,  4766,  4767,  4772,  4773,  4774,  4779,
    4787,  4804,  4812,  4829,  4848,  4872,  4878,  4889,  4895,  4906,
    4915,  4917,  4921,  4926,  4936,  4939,  4946,  4952,  4958,  4965,
    4977,  4980,  4987,  4993,  4999,  5006,  5017,  5021,  5029,  5033,
    5041,  5045,  5049,  5054,  5063,  5067,  5071,  5075,  5083,  5088,
    5096,  5102,  5111,  5119,  5124,  5129,  5134,  5139,  5144,  5149,
    5155,  5163,  5167,  5173,  5177,  5185,  5193,  5201,  5205,  5213,
    5217,  5225,  5233,  5237,  5241,  5247,  5256,  5262,  5268,  5278,
    5322,  5326,  5330,  5334,  5338,  5342,  5349,  5355,  5365,  5373,
    5381,  5385,  5389,  5393,  5397,  5401,  5405,  5409,  5413,  5417,
    5425,  5432,  5439,  5443,  5447,  5455,  5462,  5470,  5478,  5482,
    5487,  5495,  5499,  5505,  5511,  5515,  5525,  5533,  5537,  5543,
    5552,  5561,  5567,  5573,  5583,  5589,  5596,  5602,  5608,  5612,
    5620,  5628,  5632,  5643,  5649,  5655,  5661,  5671,  5675,  5681,
    5687,  5691,  5697,  5701,  5707,  5713,  5720,  5730,  5735,  5743,
    5749,  5759,  5765,  5774,  5780,  5793,  5799,  5806,  5812,  5822,
    5831,  5839,  5845,  5854,  5862,  5866,  5873,  5878,  5886,  5890,
    5897,  5901,  5908,  5912,  5919,  5923,  5932,  5945,  5948,  5956,
    5959,  5967,  5975,  5983,  5987,  5995,  5998,  6006,  6018,  6021,
    6029,  6041,  6047,  6057,  6060,  6068,  6072,  6076,  6084,  6087,
    6095,  6098,  6106,  6110,  6114,  6118,  6122,  6130,  6138,  6150,
    6162,  6166,  6170,  6178,  6184,  6194,  6198,  6202,  6206,  6210,
    6214,  6218,  6222,  6230,  6234,  6238,  6242,  6250,  6256,  6266,
    6276,  6280,  6288,  6298,  6309,  6316,  6320,  6328,  6331,  6338,
    6343,  6352,  6362,  6365,  6372,  6376,  6384,  6393,  6400,  6410,
    6414,  6421,  6427,  6437,  6440,  6447,  6452,  6464,  6472,  6484,
    6492,  6496,  6504,  6508,  6512,  6520,  6528,  6532,  6536,  6540,
    6548,  6556,  6568,  6572,  6580,  6586,  6590,  6597,  6601,  6608,
    6612,  6620,  6630,  6644,  6650,  6659,  6672,  6678,  6688,  6695,
    6702,  6720,  6745,  6765,  6769,  6773,  6786,  6791,  6792,  6793,
    6794,  6795,  6796,  6797,  6798,  6799,  6800,  6801,  6802,  6803,
    6804,  6805,  6806,  6807,  6808,  6809,  6810,  6811,  6812,  6813,
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
    6977,  6978,  6979,  6980,  6981,  6982,  6983,  6984,  6985,  6986,
    6987,  6988,  6989,  6990,  6991,  6992,  6993,  6994,  6995,  6996,
    6997,  6998,  6999,  7000,  7001,  7002,  7003,  7004,  7005,  7006,
    7007,  7008,  7009,  7010,  7011,  7012,  7013,  7014,  7015,  7016,
    7017,  7019,  7020,  7021,  7022,  7023,  7029
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
     335,   336,   337,   338,   339
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 19116;
  const int jsoniq_parser::yynnts_ = 327;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 623;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 340;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 594;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba
/* Line 1106 of lalr1.cc  */
#line 16892 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.cpp"
/* Line 1107 of lalr1.cc  */
#line 7033 "/Users/zorba/Code/zorba/release/src/compiler/parser/jsoniq_parser.y"


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



      if ((msg.find("(missing comma \",\" between expressions?)") != string::npos &&
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
