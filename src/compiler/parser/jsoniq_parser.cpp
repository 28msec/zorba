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
#line 1 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"

#define JSONIQ_PARSER
/* Line 278 of lalr1.cc  */
#line 59 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"


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
#line 102 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"


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
#line 98 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */
/* Line 284 of lalr1.cc  */
#line 909 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"



template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}
/* Line 284 of lalr1.cc  */
#line 1048 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"

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
#line 212 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


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
#line 307 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 907 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).decval); };
/* Line 453 of lalr1.cc  */
#line 413 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "'DOUBLE'" */
/* Line 453 of lalr1.cc  */
#line 906 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).dval); };
/* Line 453 of lalr1.cc  */
#line 420 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "'INTEGER'" */
/* Line 453 of lalr1.cc  */
#line 905 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).ival); };
/* Line 453 of lalr1.cc  */
#line 427 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* VersionDecl */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 434 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* MainModule */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 441 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* LibraryModule */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 448 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* ModuleDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 455 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* SIND_DeclList */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 462 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* SIND_Decl */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 469 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* Setter */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 476 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* BoundarySpaceDecl */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 483 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* DefaultCollationDecl */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 490 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* BaseURIDecl */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 497 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* ConstructionDecl */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 504 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* OrderingModeDecl */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 511 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* EmptyOrderDecl */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 518 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* CopyNamespacesDecl */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 525 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* Import */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 532 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* SchemaImport */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 539 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* URILiteralList */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 546 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* SchemaPrefix */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 553 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* ModuleImport */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 560 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* NamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 567 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* DefaultNamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 574 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* VFO_DeclList */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 581 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* VFO_Decl */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 588 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* DecimalFormatDecl */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 595 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* DecimalFormatParamList */
/* Line 453 of lalr1.cc  */
#line 956 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).vstrpair); };
/* Line 453 of lalr1.cc  */
#line 602 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* DecimalFormatParam */
/* Line 453 of lalr1.cc  */
#line 956 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).strpair); };
/* Line 453 of lalr1.cc  */
#line 609 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* OptionDecl */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 616 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* FTOptionDecl */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 623 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* CtxItemDecl */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 630 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* CtxItemDecl2 */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 637 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* CtxItemDecl3 */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 644 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* CtxItemDecl4 */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 651 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* VarDecl */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 658 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* VarNameAndType */
/* Line 453 of lalr1.cc  */
#line 956 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).varnametype); };
/* Line 453 of lalr1.cc  */
#line 665 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* AnnotationList */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 672 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* Annotation */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 679 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* AnnotationLiteralList */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 686 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* FunctionDecl */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 693 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* FunctionDecl2 */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 700 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* FunctionDeclSimple */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 707 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* FunctionDeclUpdating */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 714 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* FunctionSig */
/* Line 453 of lalr1.cc  */
#line 956 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).fnsig); };
/* Line 453 of lalr1.cc  */
#line 721 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* ParamList */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 728 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* Param */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 735 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* CollectionDecl */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 742 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* IndexDecl */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 749 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* IndexKeyList */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 756 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* IndexKeySpec */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 763 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* IntegrityConstraintDecl */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 770 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* QueryBody */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 777 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* StatementsAndOptionalExprTop */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 784 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* StatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 791 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* StatementsAndExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 798 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* Statements */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 805 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* Statement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 812 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* BlockStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 819 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* BlockExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 826 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* EnclosedStatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 833 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 406: /* VarDeclStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 840 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* AssignStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 847 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* ApplyStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 854 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* ExitStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 861 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* WhileStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 868 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* FlowCtlStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 875 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* FLWORStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 882 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* ReturnStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 889 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* IfStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* TryStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 903 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* CatchListStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 910 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* CatchStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* VoidStatement */
/* Line 453 of lalr1.cc  */
#line 937 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* Expr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* ExprSingle */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 938 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* ExprSimple */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 945 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* FLWORExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 952 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 425: /* ReturnExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 959 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* FLWORWinCond */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 966 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* WindowClause */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 973 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 431: /* CountClause */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 980 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* ForLetWinClause */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 987 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 434: /* OffsetClause */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 994 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* LimitClause */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1001 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* FLWORClauseList */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1008 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* ForClause */
/* Line 453 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1015 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* VarInDeclList */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1022 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* VarInDecl */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1029 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* PositionalVar */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1036 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* FTScoreVar */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1043 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* LetClause */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1050 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* VarGetsDeclList */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1057 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* VarGetsDecl */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1064 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* WindowVarDecl */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1071 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* WindowVars */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1078 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* WindowVars3 */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1085 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* WindowVars2 */
/* Line 453 of lalr1.cc  */
#line 935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1092 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* WhereClause */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1099 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* GroupByClause */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1106 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* GroupSpecList */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1113 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* GroupSpec */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1120 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* GroupCollationSpec */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1127 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* OrderByClause */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1134 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* OrderSpecList */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1141 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* OrderSpec */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1148 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* OrderModifier */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1155 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* OrderDirSpec */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1162 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* OrderEmptySpec */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1169 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* OrderCollationSpec */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1176 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* QuantifiedExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1183 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* QVarInDeclList */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1190 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* QVarInDecl */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1197 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* SwitchExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1204 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 466: /* SwitchCaseClauseList */
/* Line 453 of lalr1.cc  */
#line 937 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1211 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 467: /* SwitchCaseClause */
/* Line 453 of lalr1.cc  */
#line 937 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1218 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* SwitchCaseOperandList */
/* Line 453 of lalr1.cc  */
#line 937 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1225 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* SwitchStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1232 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 472: /* TypeswitchExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1239 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 473: /* TypeswitchStatement */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1246 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* CaseClauseList */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1253 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* CaseClause */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1260 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* SequenceTypeList */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1267 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* IfExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1274 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* OrExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1281 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* AndExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1288 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* NotExpr */
/* Line 453 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1295 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* ComparisonExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1302 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* FTContainsExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1309 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* StringConcatExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1316 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* opt_FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1323 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* RangeExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1330 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* AdditiveExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1337 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* MultiplicativeExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1344 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* UnionExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1351 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* IntersectExceptExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1358 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* InstanceofExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1365 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* TreatExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1372 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* CastableExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1379 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* CastExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1386 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* SingleType */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1393 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* UnaryExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1400 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* SignList */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1407 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* ValueExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1414 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* SimpleMapExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1421 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* ValueComp */
/* Line 453 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1428 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* NodeComp */
/* Line 453 of lalr1.cc  */
#line 937 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1435 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* ValidateExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1442 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* ExtensionExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1449 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* Pragma_list */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1456 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* Pragma */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1463 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* PathExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1470 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* RelativePathExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1477 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* StepExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1484 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* AxisStep */
/* Line 453 of lalr1.cc  */
#line 950 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1491 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* ForwardStep */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1498 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* ForwardAxis */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1505 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* AbbrevForwardStep */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1512 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* ReverseStep */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1519 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* ReverseAxis */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1526 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* NodeTest */
/* Line 453 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1533 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* NameTest */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1540 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* Wildcard */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1547 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* PostfixExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1554 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* PredicateList */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1561 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 523: /* Predicate */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1568 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* PrimaryExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1575 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* Literal */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1582 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* NumericLiteral */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1589 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* VarRef */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1596 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* ParenthesizedExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1603 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* ContextItemExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1610 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* OrderedExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1617 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 531: /* UnorderedExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1624 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* FunctionCall */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1631 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* ArgList */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1638 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* Constructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1645 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* DirectConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1652 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* DirElemConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1659 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* DirElemContentList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1666 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* DirAttributeList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1673 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* DirAttr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1680 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* DirAttributeValue */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1687 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* opt_QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1694 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1701 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* opt_AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1708 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1715 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* QuoteAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1722 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* AposAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1729 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* DirElemContent */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1736 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* CommonContent */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1743 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* DirCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1750 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* DirPIConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1757 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* CDataSection */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1764 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* ComputedConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1771 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* CompDocConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1778 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* CompElemConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1785 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* CompAttrConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1792 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* CompTextConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1799 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* CompCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1806 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* CompPIConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1813 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* CompNamespaceConstructor */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1820 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* TypeDeclaration */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1827 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* SequenceType */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1834 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* OccurrenceIndicator */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1841 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* ItemType */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1848 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* TypeList */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1855 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* GeneralizedAtomicType */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1862 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* SimpleType */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1869 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* KindTest */
/* Line 453 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1876 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* AnyKindTest */
/* Line 453 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1883 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* DocumentTest */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1890 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* NamespaceTest */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1897 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* TextTest */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1904 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* CommentTest */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1911 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* PITest */
/* Line 453 of lalr1.cc  */
#line 931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* AttributeTest */
/* Line 453 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* SchemaAttributeTest */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* ElementTest */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1939 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* SchemaElementTest */
/* Line 453 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1946 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* TypeName */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* TypeName_WITH_HOOK */
/* Line 453 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1960 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* StringLiteral */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1967 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* AnyFunctionTest */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1974 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* TypedFunctionTest */
/* Line 453 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1981 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* InsertExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1988 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* DeleteExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1995 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* ReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2002 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* RenameExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2009 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* TransformExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2016 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* VarNameList */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2023 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* VarNameDecl */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2030 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* TryExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2037 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* CatchListExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2044 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* CatchExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2051 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* BracedExpr */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2058 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* NameTestList */
/* Line 453 of lalr1.cc  */
#line 956 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete ((*yyvaluep).name_test_list); };
/* Line 453 of lalr1.cc  */
#line 2065 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* FTSelection */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2072 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* FTOr */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2079 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* FTAnd */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2086 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 608: /* FTMildNot */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2093 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* FTUnaryNot */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2100 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* FTPrimaryWithOptions */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2107 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* opt_FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2114 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* FTWeight */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2121 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* FTPrimary */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2128 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* opt_FTTimes */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2135 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* FTExtensionSelection */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2142 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* FTWords */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2149 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* FTWordsValue */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2156 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* FTAnyallOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2163 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 624: /* FTPosFilter */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2170 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 625: /* FTOrder */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2177 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* FTWindow */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2184 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* FTDistance */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2191 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* FTUnit */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2198 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2205 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* FTMatchOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2212 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 631: /* FTCaseOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2219 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 632: /* FTDiacriticsOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2226 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 633: /* FTExtensionOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2233 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* FTStemOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2240 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* FTThesaurusOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2247 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* FTThesaurusID */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2254 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* FTStopWordOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2261 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* FTStopWords */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2268 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* FTStopWordsInclExcl */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2275 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* FTLanguageOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2282 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* FTWildCardOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2289 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* FTContent */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2296 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* FTTimes */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2303 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* FTRange */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2310 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* FTScope */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2317 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 654: /* FTBigUnit */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2324 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 655: /* FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2331 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 656: /* JSONArrayConstructor */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2338 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 657: /* JSONSimpleObjectUnion */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2345 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* JSONAccumulatorObjectUnion */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2352 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* JSONObjectConstructor */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2359 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* JSONPairList */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2366 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* JSONInsertExpr */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2373 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 662: /* JSONAppendExpr */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2380 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 663: /* JSONDeleteExpr */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2387 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 664: /* JSONRenameExpr */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2394 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 665: /* JSONReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2401 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 668: /* QNAME */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2408 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 669: /* FUNCTION_NAME */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2415 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 670: /* EQNAME */
/* Line 453 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2422 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
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

    YYCDEBUG << "Starting parse" << std::endl;


/* User initialization code.  */
/* Line 543 of lalr1.cc  */
#line 141 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}
/* Line 543 of lalr1.cc  */
#line 2518 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 1155 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:
/* Line 661 of lalr1.cc  */
#line 1159 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 1163 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 1177 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 1181 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 1190 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 1196 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 1204 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 1210 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 1221 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 1226 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 1235 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 1242 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 1249 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 1258 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 1265 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 1273 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 1281 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 1289 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 1300 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 1305 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 1312 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 1319 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 1331 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 1341 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 1348 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 1355 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 1390 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 1395 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 1403 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 1411 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 1419 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 1424 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 1432 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 1437 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 1445 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 1450 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 1458 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 1463 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 1468 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 1473 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\"");
      YYERROR;
    }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 1496 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 1501 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 1509 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 1517 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 1528 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 1535 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:
/* Line 661 of lalr1.cc  */
#line 1546 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 68:
/* Line 661 of lalr1.cc  */
#line 1552 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 1560 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 1567 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:
/* Line 661 of lalr1.cc  */
#line 1574 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 1583 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1597 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 1606 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 1613 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 1623 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 1630 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:
/* Line 661 of lalr1.cc  */
#line 1637 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 1660 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 1666 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 1675 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 1682 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 1692 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 1701 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 1702 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 1703 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 1704 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 1705 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 1706 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 1707 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 1708 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 1709 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 1710 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 1716 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1735 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 1743 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 1751 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 1758 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 1766 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 1773 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 1778 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 1786 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 1794 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1808 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1822 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1839 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 1844 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 1852 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 1860 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 1871 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 1876 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 1885 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 1890 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 1897 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 1902 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 1912 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 1917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 1926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 1932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 1951 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1966 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1981 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1997 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2012 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 2017 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 2022 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 2027 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 2035 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 2042 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 2053 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 2058 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 2068 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2077 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2086 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2095 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2107 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 2111 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 2117 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 2121 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 2131 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2141 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2154 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 2160 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 2169 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 2174 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 2181 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 2188 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 2200 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2210 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2220 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2231 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2247 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2267 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 2271 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 2275 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 2283 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 2287 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 2291 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 2299 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 2304 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 2316 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 2323 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 2333 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2366 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 2374 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2406 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 2414 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 2422 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 2429 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 2436 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 2447 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2456 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (3)].node)),
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 2465 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2474 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (3)].node)),
                                          (yysemantic_stack_[(5) - (5)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 2487 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 2495 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 2503 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 2511 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2526 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 2531 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 2539 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2553 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2570 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2595 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 2603 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 2610 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 2621 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 2630 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 2638 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 2643 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2656 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2703 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2717 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 2729 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
    }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 2736 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 2741 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 2749 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 2754 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 2759 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 2767 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2776 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2788 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2798 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2811 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 2836 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.node) = new OffsetClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
  }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 2843 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.node) = new LimitClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
  }
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 2850 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 260:
/* Line 661 of lalr1.cc  */
#line 2857 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 261:
/* Line 661 of lalr1.cc  */
#line 2867 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 2872 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2881 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 2890 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 2904 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

    }
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 2912 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 2919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 2927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 2939 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 271:
/* Line 661 of lalr1.cc  */
#line 2949 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 272:
/* Line 661 of lalr1.cc  */
#line 2959 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 273:
/* Line 661 of lalr1.cc  */
#line 2969 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 274:
/* Line 661 of lalr1.cc  */
#line 2979 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 275:
/* Line 661 of lalr1.cc  */
#line 2989 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 276:
/* Line 661 of lalr1.cc  */
#line 2999 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 277:
/* Line 661 of lalr1.cc  */
#line 3009 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 278:
/* Line 661 of lalr1.cc  */
#line 3020 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 3029 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 280:
/* Line 661 of lalr1.cc  */
#line 3039 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 281:
/* Line 661 of lalr1.cc  */
#line 3049 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 282:
/* Line 661 of lalr1.cc  */
#line 3065 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 3074 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 3083 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 3091 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 3097 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 3109 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 3117 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 3127 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 3135 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 3147 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 3153 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 3166 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 3170 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 3178 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 3182 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 3191 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 3195 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 3199 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 3209 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 3217 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 3224 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 3230 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 3240 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 3244 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 3252 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceTypeAST*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 3260 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 3268 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 3276 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 3288 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 3296 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 3302 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 3312 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 3318 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 3328 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 3332 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 3342 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 3348 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 3354 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 3360 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 3369 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 3378 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 3387 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 3400 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 3404 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 3412 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 3418 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 3428 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 3436 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 3445 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 3458 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 3465 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 3477 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 3481 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 3493 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 3500 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 3506 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 3515 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 3522 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 3528 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 3539 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 3546 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 3552 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 3561 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 3570 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 3577 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 3588 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 3595 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 3607 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 3613 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 3625 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 3631 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 3642 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 3648 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 3659 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 3665 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 3676 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceTypeAST*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 360:
/* Line 661 of lalr1.cc  */
#line 3682 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 3693 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 362:
/* Line 661 of lalr1.cc  */
#line 3702 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 3706 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 3720 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 3730 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 3740 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 3744 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new ComparisonExpr(
              LOC((yyloc)),
              new ValueComp( LOC((yyloc)), ParseConstants::op_val_not ),
              (yysemantic_stack_[(2) - (2)].expr),
              NULL
          );
        }
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 3759 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 3763 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 3773 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 3780 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 3789 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 3798 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {




            driver.getJsoniqLexer()->interpretAsLessThan();

        }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 3807 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 3816 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 3825 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 3834 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 3847 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 3851 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 3863 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 3867 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 3874 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 3878 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 3885 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 3889 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 3898 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 3902 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 3906 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 3914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 3918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 391:
/* Line 661 of lalr1.cc  */
#line 3924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 392:
/* Line 661 of lalr1.cc  */
#line 3930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 393:
/* Line 661 of lalr1.cc  */
#line 3936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 394:
/* Line 661 of lalr1.cc  */
#line 3946 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:
/* Line 661 of lalr1.cc  */
#line 3950 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 396:
/* Line 661 of lalr1.cc  */
#line 3954 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 397:
/* Line 661 of lalr1.cc  */
#line 3962 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:
/* Line 661 of lalr1.cc  */
#line 3966 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 399:
/* Line 661 of lalr1.cc  */
#line 3972 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 400:
/* Line 661 of lalr1.cc  */
#line 3982 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:
/* Line 661 of lalr1.cc  */
#line 3986 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 402:
/* Line 661 of lalr1.cc  */
#line 3996 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:
/* Line 661 of lalr1.cc  */
#line 4000 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 404:
/* Line 661 of lalr1.cc  */
#line 4010 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:
/* Line 661 of lalr1.cc  */
#line 4014 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 406:
/* Line 661 of lalr1.cc  */
#line 4024 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:
/* Line 661 of lalr1.cc  */
#line 4028 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 408:
/* Line 661 of lalr1.cc  */
#line 4038 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 409:
/* Line 661 of lalr1.cc  */
#line 4042 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 410:
/* Line 661 of lalr1.cc  */
#line 4051 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 411:
/* Line 661 of lalr1.cc  */
#line 4055 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 412:
/* Line 661 of lalr1.cc  */
#line 4063 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 413:
/* Line 661 of lalr1.cc  */
#line 4067 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 414:
/* Line 661 of lalr1.cc  */
#line 4071 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 415:
/* Line 661 of lalr1.cc  */
#line 4075 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 419:
/* Line 661 of lalr1.cc  */
#line 4091 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 420:
/* Line 661 of lalr1.cc  */
#line 4096 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 421:
/* Line 661 of lalr1.cc  */
#line 4104 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 422:
/* Line 661 of lalr1.cc  */
#line 4108 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 423:
/* Line 661 of lalr1.cc  */
#line 4112 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 424:
/* Line 661 of lalr1.cc  */
#line 4116 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 425:
/* Line 661 of lalr1.cc  */
#line 4120 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 426:
/* Line 661 of lalr1.cc  */
#line 4124 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 427:
/* Line 661 of lalr1.cc  */
#line 4132 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 428:
/* Line 661 of lalr1.cc  */
#line 4136 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 429:
/* Line 661 of lalr1.cc  */
#line 4140 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 430:
/* Line 661 of lalr1.cc  */
#line 4148 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 431:
/* Line 661 of lalr1.cc  */
#line 4152 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 432:
/* Line 661 of lalr1.cc  */
#line 4156 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 433:
/* Line 661 of lalr1.cc  */
#line 4160 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 434:
/* Line 661 of lalr1.cc  */
#line 4171 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 435:
/* Line 661 of lalr1.cc  */
#line 4181 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 436:
/* Line 661 of lalr1.cc  */
#line 4187 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 437:
/* Line 661 of lalr1.cc  */
#line 4197 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 438:
/* Line 661 of lalr1.cc  */
#line 4201 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 439:
/* Line 661 of lalr1.cc  */
#line 4205 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 440:
/* Line 661 of lalr1.cc  */
#line 4211 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 441:
/* Line 661 of lalr1.cc  */
#line 4215 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 442:
/* Line 661 of lalr1.cc  */
#line 4225 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 443:
/* Line 661 of lalr1.cc  */
#line 4235 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 444:
/* Line 661 of lalr1.cc  */
#line 4288 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 445:
/* Line 661 of lalr1.cc  */
#line 4297 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 446:
/* Line 661 of lalr1.cc  */
#line 4307 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 447:
/* Line 661 of lalr1.cc  */
#line 4311 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 450:
/* Line 661 of lalr1.cc  */
#line 4327 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 451:
/* Line 661 of lalr1.cc  */
#line 4333 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 452:
/* Line 661 of lalr1.cc  */
#line 4341 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 453:
/* Line 661 of lalr1.cc  */
#line 4347 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 454:
/* Line 661 of lalr1.cc  */
#line 4360 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 455:
/* Line 661 of lalr1.cc  */
#line 4366 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 456:
/* Line 661 of lalr1.cc  */
#line 4377 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 457:
/* Line 661 of lalr1.cc  */
#line 4381 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 458:
/* Line 661 of lalr1.cc  */
#line 4385 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 459:
/* Line 661 of lalr1.cc  */
#line 4389 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 460:
/* Line 661 of lalr1.cc  */
#line 4393 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 461:
/* Line 661 of lalr1.cc  */
#line 4399 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 462:
/* Line 661 of lalr1.cc  */
#line 4405 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 463:
/* Line 661 of lalr1.cc  */
#line 4414 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 464:
/* Line 661 of lalr1.cc  */
#line 4418 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 465:
/* Line 661 of lalr1.cc  */
#line 4427 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 466:
/* Line 661 of lalr1.cc  */
#line 4431 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 467:
/* Line 661 of lalr1.cc  */
#line 4443 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 468:
/* Line 661 of lalr1.cc  */
#line 4447 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 469:
/* Line 661 of lalr1.cc  */
#line 4451 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 470:
/* Line 661 of lalr1.cc  */
#line 4457 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 471:
/* Line 661 of lalr1.cc  */
#line 4461 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 474:
/* Line 661 of lalr1.cc  */
#line 4483 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 475:
/* Line 661 of lalr1.cc  */
#line 4487 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 476:
/* Line 661 of lalr1.cc  */
#line 4497 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 477:
/* Line 661 of lalr1.cc  */
#line 4501 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 478:
/* Line 661 of lalr1.cc  */
#line 4505 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 479:
/* Line 661 of lalr1.cc  */
#line 4509 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 480:
/* Line 661 of lalr1.cc  */
#line 4522 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 481:
/* Line 661 of lalr1.cc  */
#line 4526 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 482:
/* Line 661 of lalr1.cc  */
#line 4530 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 483:
/* Line 661 of lalr1.cc  */
#line 4534 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 484:
/* Line 661 of lalr1.cc  */
#line 4540 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new JSONArrayUnboxing(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
    }
    break;

  case 485:
/* Line 661 of lalr1.cc  */
#line 4544 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (3)].expr), (yylocation_stack_[(3) - (3)]));
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 486:
/* Line 661 of lalr1.cc  */
#line 4550 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(4) - (2)])),
                                 (yysemantic_stack_[(4) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), NULL));
     }
    break;

  case 487:
/* Line 661 of lalr1.cc  */
#line 4556 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(5) - (2)])),
                                 (yysemantic_stack_[(5) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (4)].expr)));
     }
    break;

  case 488:
/* Line 661 of lalr1.cc  */
#line 4562 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 489:
/* Line 661 of lalr1.cc  */
#line 4566 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 490:
/* Line 661 of lalr1.cc  */
#line 4570 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 491:
/* Line 661 of lalr1.cc  */
#line 4579 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 492:
/* Line 661 of lalr1.cc  */
#line 4585 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));

      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 493:
/* Line 661 of lalr1.cc  */
#line 4596 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 508:
/* Line 661 of lalr1.cc  */
#line 4624 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 509:
/* Line 661 of lalr1.cc  */
#line 4628 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 510:
/* Line 661 of lalr1.cc  */
#line 4636 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 511:
/* Line 661 of lalr1.cc  */
#line 4643 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 512:
/* Line 661 of lalr1.cc  */
#line 4650 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 513:
/* Line 661 of lalr1.cc  */
#line 4661 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 514:
/* Line 661 of lalr1.cc  */
#line 4669 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 515:
/* Line 661 of lalr1.cc  */
#line 4673 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 516:
/* Line 661 of lalr1.cc  */
#line 4681 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 517:
/* Line 661 of lalr1.cc  */
#line 4692 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 518:
/* Line 661 of lalr1.cc  */
#line 4700 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 519:
/* Line 661 of lalr1.cc  */
#line 4706 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 520:
/* Line 661 of lalr1.cc  */
#line 4710 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 521:
/* Line 661 of lalr1.cc  */
#line 4732 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 522:
/* Line 661 of lalr1.cc  */
#line 4738 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 523:
/* Line 661 of lalr1.cc  */
#line 4744 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 524:
/* Line 661 of lalr1.cc  */
#line 4750 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 525:
/* Line 661 of lalr1.cc  */
#line 4760 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:
/* Line 661 of lalr1.cc  */
#line 4764 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:
/* Line 661 of lalr1.cc  */
#line 4772 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 528:
/* Line 661 of lalr1.cc  */
#line 4780 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 534:
/* Line 661 of lalr1.cc  */
#line 4805 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 535:
/* Line 661 of lalr1.cc  */
#line 4813 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 536:
/* Line 661 of lalr1.cc  */
#line 4830 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 537:
/* Line 661 of lalr1.cc  */
#line 4838 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 538:
/* Line 661 of lalr1.cc  */
#line 4857 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 539:
/* Line 661 of lalr1.cc  */
#line 4876 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 540:
/* Line 661 of lalr1.cc  */
#line 4898 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 541:
/* Line 661 of lalr1.cc  */
#line 4904 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 542:
/* Line 661 of lalr1.cc  */
#line 4915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 543:
/* Line 661 of lalr1.cc  */
#line 4921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:
/* Line 661 of lalr1.cc  */
#line 4932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 547:
/* Line 661 of lalr1.cc  */
#line 4947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 548:
/* Line 661 of lalr1.cc  */
#line 4952 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 549:
/* Line 661 of lalr1.cc  */
#line 4961 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 550:
/* Line 661 of lalr1.cc  */
#line 4965 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 551:
/* Line 661 of lalr1.cc  */
#line 4972 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 552:
/* Line 661 of lalr1.cc  */
#line 4978 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 553:
/* Line 661 of lalr1.cc  */
#line 4984 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 554:
/* Line 661 of lalr1.cc  */
#line 4991 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 555:
/* Line 661 of lalr1.cc  */
#line 5002 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 556:
/* Line 661 of lalr1.cc  */
#line 5006 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 557:
/* Line 661 of lalr1.cc  */
#line 5013 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 558:
/* Line 661 of lalr1.cc  */
#line 5019 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 559:
/* Line 661 of lalr1.cc  */
#line 5025 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 560:
/* Line 661 of lalr1.cc  */
#line 5032 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 561:
/* Line 661 of lalr1.cc  */
#line 5043 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 562:
/* Line 661 of lalr1.cc  */
#line 5047 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 563:
/* Line 661 of lalr1.cc  */
#line 5055 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 564:
/* Line 661 of lalr1.cc  */
#line 5059 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 565:
/* Line 661 of lalr1.cc  */
#line 5067 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 566:
/* Line 661 of lalr1.cc  */
#line 5071 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 567:
/* Line 661 of lalr1.cc  */
#line 5075 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 568:
/* Line 661 of lalr1.cc  */
#line 5080 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 569:
/* Line 661 of lalr1.cc  */
#line 5089 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 570:
/* Line 661 of lalr1.cc  */
#line 5093 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 571:
/* Line 661 of lalr1.cc  */
#line 5097 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 572:
/* Line 661 of lalr1.cc  */
#line 5101 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 573:
/* Line 661 of lalr1.cc  */
#line 5109 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 574:
/* Line 661 of lalr1.cc  */
#line 5114 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 575:
/* Line 661 of lalr1.cc  */
#line 5122 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 576:
/* Line 661 of lalr1.cc  */
#line 5128 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 577:
/* Line 661 of lalr1.cc  */
#line 5137 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 578:
/* Line 661 of lalr1.cc  */
#line 5145 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 579:
/* Line 661 of lalr1.cc  */
#line 5150 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 580:
/* Line 661 of lalr1.cc  */
#line 5155 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 581:
/* Line 661 of lalr1.cc  */
#line 5160 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 582:
/* Line 661 of lalr1.cc  */
#line 5165 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 583:
/* Line 661 of lalr1.cc  */
#line 5170 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 585:
/* Line 661 of lalr1.cc  */
#line 5181 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 586:
/* Line 661 of lalr1.cc  */
#line 5189 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 587:
/* Line 661 of lalr1.cc  */
#line 5193 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 588:
/* Line 661 of lalr1.cc  */
#line 5199 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 589:
/* Line 661 of lalr1.cc  */
#line 5203 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 590:
/* Line 661 of lalr1.cc  */
#line 5211 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 591:
/* Line 661 of lalr1.cc  */
#line 5219 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 592:
/* Line 661 of lalr1.cc  */
#line 5227 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 593:
/* Line 661 of lalr1.cc  */
#line 5231 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 594:
/* Line 661 of lalr1.cc  */
#line 5239 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 595:
/* Line 661 of lalr1.cc  */
#line 5243 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 596:
/* Line 661 of lalr1.cc  */
#line 5251 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 597:
/* Line 661 of lalr1.cc  */
#line 5259 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 598:
/* Line 661 of lalr1.cc  */
#line 5263 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 599:
/* Line 661 of lalr1.cc  */
#line 5267 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 600:
/* Line 661 of lalr1.cc  */
#line 5273 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

            driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_JSONIQ_EMPTY_SEQUENCE));
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 601:
/* Line 661 of lalr1.cc  */
#line 5282 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 602:
/* Line 661 of lalr1.cc  */
#line 5288 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 603:
/* Line 661 of lalr1.cc  */
#line 5294 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 604:
/* Line 661 of lalr1.cc  */
#line 5304 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 605:
/* Line 661 of lalr1.cc  */
#line 5348 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 606:
/* Line 661 of lalr1.cc  */
#line 5352 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 607:
/* Line 661 of lalr1.cc  */
#line 5356 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 608:
/* Line 661 of lalr1.cc  */
#line 5360 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 609:
/* Line 661 of lalr1.cc  */
#line 5364 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 610:
/* Line 661 of lalr1.cc  */
#line 5368 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 611:
/* Line 661 of lalr1.cc  */
#line 5375 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 612:
/* Line 661 of lalr1.cc  */
#line 5381 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 613:
/* Line 661 of lalr1.cc  */
#line 5391 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 614:
/* Line 661 of lalr1.cc  */
#line 5399 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 615:
/* Line 661 of lalr1.cc  */
#line 5407 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 616:
/* Line 661 of lalr1.cc  */
#line 5411 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:
/* Line 661 of lalr1.cc  */
#line 5415 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:
/* Line 661 of lalr1.cc  */
#line 5419 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 619:
/* Line 661 of lalr1.cc  */
#line 5423 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 620:
/* Line 661 of lalr1.cc  */
#line 5427 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:
/* Line 661 of lalr1.cc  */
#line 5431 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 622:
/* Line 661 of lalr1.cc  */
#line 5435 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 623:
/* Line 661 of lalr1.cc  */
#line 5439 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 624:
/* Line 661 of lalr1.cc  */
#line 5443 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 625:
/* Line 661 of lalr1.cc  */
#line 5451 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 626:
/* Line 661 of lalr1.cc  */
#line 5458 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 627:
/* Line 661 of lalr1.cc  */
#line 5465 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 628:
/* Line 661 of lalr1.cc  */
#line 5469 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 629:
/* Line 661 of lalr1.cc  */
#line 5473 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 630:
/* Line 661 of lalr1.cc  */
#line 5481 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 631:
/* Line 661 of lalr1.cc  */
#line 5488 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 632:
/* Line 661 of lalr1.cc  */
#line 5496 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 633:
/* Line 661 of lalr1.cc  */
#line 5504 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 634:
/* Line 661 of lalr1.cc  */
#line 5508 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 635:
/* Line 661 of lalr1.cc  */
#line 5513 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 636:
/* Line 661 of lalr1.cc  */
#line 5521 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 637:
/* Line 661 of lalr1.cc  */
#line 5525 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 638:
/* Line 661 of lalr1.cc  */
#line 5531 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 639:
/* Line 661 of lalr1.cc  */
#line 5537 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 640:
/* Line 661 of lalr1.cc  */
#line 5541 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 641:
/* Line 661 of lalr1.cc  */
#line 5551 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 642:
/* Line 661 of lalr1.cc  */
#line 5559 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 643:
/* Line 661 of lalr1.cc  */
#line 5563 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 644:
/* Line 661 of lalr1.cc  */
#line 5569 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 645:
/* Line 661 of lalr1.cc  */
#line 5578 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 646:
/* Line 661 of lalr1.cc  */
#line 5587 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 647:
/* Line 661 of lalr1.cc  */
#line 5593 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 648:
/* Line 661 of lalr1.cc  */
#line 5599 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 649:
/* Line 661 of lalr1.cc  */
#line 5609 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 650:
/* Line 661 of lalr1.cc  */
#line 5615 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 651:
/* Line 661 of lalr1.cc  */
#line 5622 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 652:
/* Line 661 of lalr1.cc  */
#line 5628 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 653:
/* Line 661 of lalr1.cc  */
#line 5634 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 654:
/* Line 661 of lalr1.cc  */
#line 5638 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 655:
/* Line 661 of lalr1.cc  */
#line 5646 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 656:
/* Line 661 of lalr1.cc  */
#line 5654 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 657:
/* Line 661 of lalr1.cc  */
#line 5658 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 658:
/* Line 661 of lalr1.cc  */
#line 5669 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 659:
/* Line 661 of lalr1.cc  */
#line 5675 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 660:
/* Line 661 of lalr1.cc  */
#line 5681 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 661:
/* Line 661 of lalr1.cc  */
#line 5687 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 662:
/* Line 661 of lalr1.cc  */
#line 5697 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 663:
/* Line 661 of lalr1.cc  */
#line 5701 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 664:
/* Line 661 of lalr1.cc  */
#line 5707 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 665:
/* Line 661 of lalr1.cc  */
#line 5713 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 666:
/* Line 661 of lalr1.cc  */
#line 5717 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 667:
/* Line 661 of lalr1.cc  */
#line 5723 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 668:
/* Line 661 of lalr1.cc  */
#line 5727 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 669:
/* Line 661 of lalr1.cc  */
#line 5733 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 670:
/* Line 661 of lalr1.cc  */
#line 5739 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 671:
/* Line 661 of lalr1.cc  */
#line 5746 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 672:
/* Line 661 of lalr1.cc  */
#line 5756 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 673:
/* Line 661 of lalr1.cc  */
#line 5761 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 674:
/* Line 661 of lalr1.cc  */
#line 5769 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 675:
/* Line 661 of lalr1.cc  */
#line 5775 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 676:
/* Line 661 of lalr1.cc  */
#line 5785 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 677:
/* Line 661 of lalr1.cc  */
#line 5791 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 678:
/* Line 661 of lalr1.cc  */
#line 5800 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 679:
/* Line 661 of lalr1.cc  */
#line 5806 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 680:
/* Line 661 of lalr1.cc  */
#line 5819 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 681:
/* Line 661 of lalr1.cc  */
#line 5825 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 682:
/* Line 661 of lalr1.cc  */
#line 5832 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 683:
/* Line 661 of lalr1.cc  */
#line 5838 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 684:
/* Line 661 of lalr1.cc  */
#line 5848 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 685:
/* Line 661 of lalr1.cc  */
#line 5857 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 686:
/* Line 661 of lalr1.cc  */
#line 5865 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 687:
/* Line 661 of lalr1.cc  */
#line 5871 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 688:
/* Line 661 of lalr1.cc  */
#line 5880 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 689:
/* Line 661 of lalr1.cc  */
#line 5888 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 690:
/* Line 661 of lalr1.cc  */
#line 5892 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 691:
/* Line 661 of lalr1.cc  */
#line 5899 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 692:
/* Line 661 of lalr1.cc  */
#line 5904 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 693:
/* Line 661 of lalr1.cc  */
#line 5912 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:
/* Line 661 of lalr1.cc  */
#line 5916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 695:
/* Line 661 of lalr1.cc  */
#line 5923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:
/* Line 661 of lalr1.cc  */
#line 5927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 697:
/* Line 661 of lalr1.cc  */
#line 5934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:
/* Line 661 of lalr1.cc  */
#line 5938 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 699:
/* Line 661 of lalr1.cc  */
#line 5945 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:
/* Line 661 of lalr1.cc  */
#line 5949 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 701:
/* Line 661 of lalr1.cc  */
#line 5958 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 702:
/* Line 661 of lalr1.cc  */
#line 5970 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 703:
/* Line 661 of lalr1.cc  */
#line 5974 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:
/* Line 661 of lalr1.cc  */
#line 5981 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 705:
/* Line 661 of lalr1.cc  */
#line 5985 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:
/* Line 661 of lalr1.cc  */
#line 5993 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 707:
/* Line 661 of lalr1.cc  */
#line 6001 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 708:
/* Line 661 of lalr1.cc  */
#line 6009 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 709:
/* Line 661 of lalr1.cc  */
#line 6013 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:
/* Line 661 of lalr1.cc  */
#line 6020 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 711:
/* Line 661 of lalr1.cc  */
#line 6024 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:
/* Line 661 of lalr1.cc  */
#line 6032 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 713:
/* Line 661 of lalr1.cc  */
#line 6043 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 714:
/* Line 661 of lalr1.cc  */
#line 6047 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:
/* Line 661 of lalr1.cc  */
#line 6055 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 716:
/* Line 661 of lalr1.cc  */
#line 6067 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 717:
/* Line 661 of lalr1.cc  */
#line 6073 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 718:
/* Line 661 of lalr1.cc  */
#line 6082 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 719:
/* Line 661 of lalr1.cc  */
#line 6086 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 720:
/* Line 661 of lalr1.cc  */
#line 6094 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 721:
/* Line 661 of lalr1.cc  */
#line 6098 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 722:
/* Line 661 of lalr1.cc  */
#line 6102 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 723:
/* Line 661 of lalr1.cc  */
#line 6109 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 724:
/* Line 661 of lalr1.cc  */
#line 6113 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 725:
/* Line 661 of lalr1.cc  */
#line 6120 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 726:
/* Line 661 of lalr1.cc  */
#line 6124 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 727:
/* Line 661 of lalr1.cc  */
#line 6132 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:
/* Line 661 of lalr1.cc  */
#line 6136 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:
/* Line 661 of lalr1.cc  */
#line 6140 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:
/* Line 661 of lalr1.cc  */
#line 6144 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:
/* Line 661 of lalr1.cc  */
#line 6148 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 732:
/* Line 661 of lalr1.cc  */
#line 6156 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 733:
/* Line 661 of lalr1.cc  */
#line 6164 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 734:
/* Line 661 of lalr1.cc  */
#line 6176 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 735:
/* Line 661 of lalr1.cc  */
#line 6188 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 736:
/* Line 661 of lalr1.cc  */
#line 6192 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 737:
/* Line 661 of lalr1.cc  */
#line 6196 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 738:
/* Line 661 of lalr1.cc  */
#line 6204 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 739:
/* Line 661 of lalr1.cc  */
#line 6210 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 740:
/* Line 661 of lalr1.cc  */
#line 6220 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 741:
/* Line 661 of lalr1.cc  */
#line 6224 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 742:
/* Line 661 of lalr1.cc  */
#line 6228 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:
/* Line 661 of lalr1.cc  */
#line 6232 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 744:
/* Line 661 of lalr1.cc  */
#line 6236 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 745:
/* Line 661 of lalr1.cc  */
#line 6240 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 746:
/* Line 661 of lalr1.cc  */
#line 6244 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 747:
/* Line 661 of lalr1.cc  */
#line 6248 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 748:
/* Line 661 of lalr1.cc  */
#line 6256 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 749:
/* Line 661 of lalr1.cc  */
#line 6260 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 750:
/* Line 661 of lalr1.cc  */
#line 6264 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 751:
/* Line 661 of lalr1.cc  */
#line 6268 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 752:
/* Line 661 of lalr1.cc  */
#line 6276 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 753:
/* Line 661 of lalr1.cc  */
#line 6282 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 754:
/* Line 661 of lalr1.cc  */
#line 6292 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 755:
/* Line 661 of lalr1.cc  */
#line 6302 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 756:
/* Line 661 of lalr1.cc  */
#line 6306 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 757:
/* Line 661 of lalr1.cc  */
#line 6314 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 758:
/* Line 661 of lalr1.cc  */
#line 6324 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 759:
/* Line 661 of lalr1.cc  */
#line 6335 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 760:
/* Line 661 of lalr1.cc  */
#line 6342 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 761:
/* Line 661 of lalr1.cc  */
#line 6346 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 762:
/* Line 661 of lalr1.cc  */
#line 6353 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 763:
/* Line 661 of lalr1.cc  */
#line 6357 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 764:
/* Line 661 of lalr1.cc  */
#line 6364 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 765:
/* Line 661 of lalr1.cc  */
#line 6369 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 766:
/* Line 661 of lalr1.cc  */
#line 6378 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 767:
/* Line 661 of lalr1.cc  */
#line 6387 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 768:
/* Line 661 of lalr1.cc  */
#line 6391 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 769:
/* Line 661 of lalr1.cc  */
#line 6398 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 770:
/* Line 661 of lalr1.cc  */
#line 6402 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 771:
/* Line 661 of lalr1.cc  */
#line 6410 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 772:
/* Line 661 of lalr1.cc  */
#line 6419 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 773:
/* Line 661 of lalr1.cc  */
#line 6426 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 774:
/* Line 661 of lalr1.cc  */
#line 6436 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 775:
/* Line 661 of lalr1.cc  */
#line 6440 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 776:
/* Line 661 of lalr1.cc  */
#line 6447 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 777:
/* Line 661 of lalr1.cc  */
#line 6453 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 778:
/* Line 661 of lalr1.cc  */
#line 6462 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 779:
/* Line 661 of lalr1.cc  */
#line 6466 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 780:
/* Line 661 of lalr1.cc  */
#line 6473 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 781:
/* Line 661 of lalr1.cc  */
#line 6478 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 782:
/* Line 661 of lalr1.cc  */
#line 6490 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 783:
/* Line 661 of lalr1.cc  */
#line 6498 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 784:
/* Line 661 of lalr1.cc  */
#line 6510 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 785:
/* Line 661 of lalr1.cc  */
#line 6518 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 786:
/* Line 661 of lalr1.cc  */
#line 6522 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 787:
/* Line 661 of lalr1.cc  */
#line 6530 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 788:
/* Line 661 of lalr1.cc  */
#line 6534 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 789:
/* Line 661 of lalr1.cc  */
#line 6538 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 790:
/* Line 661 of lalr1.cc  */
#line 6546 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 791:
/* Line 661 of lalr1.cc  */
#line 6554 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 792:
/* Line 661 of lalr1.cc  */
#line 6558 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 793:
/* Line 661 of lalr1.cc  */
#line 6562 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 794:
/* Line 661 of lalr1.cc  */
#line 6566 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 795:
/* Line 661 of lalr1.cc  */
#line 6574 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 796:
/* Line 661 of lalr1.cc  */
#line 6582 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 797:
/* Line 661 of lalr1.cc  */
#line 6594 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 798:
/* Line 661 of lalr1.cc  */
#line 6598 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 799:
/* Line 661 of lalr1.cc  */
#line 6606 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 800:
/* Line 661 of lalr1.cc  */
#line 6612 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 801:
/* Line 661 of lalr1.cc  */
#line 6616 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 802:
/* Line 661 of lalr1.cc  */
#line 6623 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 803:
/* Line 661 of lalr1.cc  */
#line 6627 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 804:
/* Line 661 of lalr1.cc  */
#line 6634 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 805:
/* Line 661 of lalr1.cc  */
#line 6638 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 806:
/* Line 661 of lalr1.cc  */
#line 6646 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 807:
/* Line 661 of lalr1.cc  */
#line 6656 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (1)].expr), (yylocation_stack_[(3) - (1)]));


          driver.addCommonLanguageWarning((yylocation_stack_[(3) - (1)]), ZED(ZWST0009_OBJECT_KEY_NOT_QUOTED));

          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 808:
/* Line 661 of lalr1.cc  */
#line 6670 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 809:
/* Line 661 of lalr1.cc  */
#line 6676 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 810:
/* Line 661 of lalr1.cc  */
#line 6685 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 811:
/* Line 661 of lalr1.cc  */
#line 6698 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 812:
/* Line 661 of lalr1.cc  */
#line 6704 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 813:
/* Line 661 of lalr1.cc  */
#line 6714 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 814:
/* Line 661 of lalr1.cc  */
#line 6721 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 815:
/* Line 661 of lalr1.cc  */
#line 6728 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 816:
/* Line 661 of lalr1.cc  */
#line 6746 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 817:
/* Line 661 of lalr1.cc  */
#line 6771 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 818:
/* Line 661 of lalr1.cc  */
#line 6791 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 819:
/* Line 661 of lalr1.cc  */
#line 6795 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 820:
/* Line 661 of lalr1.cc  */
#line 6799 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 823:
/* Line 661 of lalr1.cc  */
#line 6817 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 824:
/* Line 661 of lalr1.cc  */
#line 6818 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 825:
/* Line 661 of lalr1.cc  */
#line 6819 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 826:
/* Line 661 of lalr1.cc  */
#line 6820 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 827:
/* Line 661 of lalr1.cc  */
#line 6821 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 828:
/* Line 661 of lalr1.cc  */
#line 6822 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 829:
/* Line 661 of lalr1.cc  */
#line 6823 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 830:
/* Line 661 of lalr1.cc  */
#line 6824 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 831:
/* Line 661 of lalr1.cc  */
#line 6825 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 832:
/* Line 661 of lalr1.cc  */
#line 6826 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 833:
/* Line 661 of lalr1.cc  */
#line 6827 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 834:
/* Line 661 of lalr1.cc  */
#line 6828 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 835:
/* Line 661 of lalr1.cc  */
#line 6829 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 836:
/* Line 661 of lalr1.cc  */
#line 6830 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 837:
/* Line 661 of lalr1.cc  */
#line 6831 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 838:
/* Line 661 of lalr1.cc  */
#line 6832 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 839:
/* Line 661 of lalr1.cc  */
#line 6833 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 840:
/* Line 661 of lalr1.cc  */
#line 6834 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 841:
/* Line 661 of lalr1.cc  */
#line 6835 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 842:
/* Line 661 of lalr1.cc  */
#line 6836 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 843:
/* Line 661 of lalr1.cc  */
#line 6837 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 844:
/* Line 661 of lalr1.cc  */
#line 6838 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 846:
/* Line 661 of lalr1.cc  */
#line 6843 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 847:
/* Line 661 of lalr1.cc  */
#line 6844 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 848:
/* Line 661 of lalr1.cc  */
#line 6845 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 849:
/* Line 661 of lalr1.cc  */
#line 6846 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 850:
/* Line 661 of lalr1.cc  */
#line 6847 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 851:
/* Line 661 of lalr1.cc  */
#line 6848 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 852:
/* Line 661 of lalr1.cc  */
#line 6849 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 853:
/* Line 661 of lalr1.cc  */
#line 6850 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 854:
/* Line 661 of lalr1.cc  */
#line 6851 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 855:
/* Line 661 of lalr1.cc  */
#line 6852 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 856:
/* Line 661 of lalr1.cc  */
#line 6853 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 857:
/* Line 661 of lalr1.cc  */
#line 6854 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 858:
/* Line 661 of lalr1.cc  */
#line 6855 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 859:
/* Line 661 of lalr1.cc  */
#line 6856 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 860:
/* Line 661 of lalr1.cc  */
#line 6857 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 861:
/* Line 661 of lalr1.cc  */
#line 6858 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 862:
/* Line 661 of lalr1.cc  */
#line 6859 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 863:
/* Line 661 of lalr1.cc  */
#line 6860 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 864:
/* Line 661 of lalr1.cc  */
#line 6861 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 865:
/* Line 661 of lalr1.cc  */
#line 6862 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 866:
/* Line 661 of lalr1.cc  */
#line 6863 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 867:
/* Line 661 of lalr1.cc  */
#line 6864 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 868:
/* Line 661 of lalr1.cc  */
#line 6865 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 869:
/* Line 661 of lalr1.cc  */
#line 6866 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 870:
/* Line 661 of lalr1.cc  */
#line 6867 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 871:
/* Line 661 of lalr1.cc  */
#line 6868 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 872:
/* Line 661 of lalr1.cc  */
#line 6869 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 873:
/* Line 661 of lalr1.cc  */
#line 6870 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 874:
/* Line 661 of lalr1.cc  */
#line 6871 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 875:
/* Line 661 of lalr1.cc  */
#line 6872 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 876:
/* Line 661 of lalr1.cc  */
#line 6873 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 877:
/* Line 661 of lalr1.cc  */
#line 6874 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 878:
/* Line 661 of lalr1.cc  */
#line 6875 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 879:
/* Line 661 of lalr1.cc  */
#line 6876 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 880:
/* Line 661 of lalr1.cc  */
#line 6877 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 881:
/* Line 661 of lalr1.cc  */
#line 6878 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 882:
/* Line 661 of lalr1.cc  */
#line 6879 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 883:
/* Line 661 of lalr1.cc  */
#line 6880 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 884:
/* Line 661 of lalr1.cc  */
#line 6881 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 885:
/* Line 661 of lalr1.cc  */
#line 6882 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 886:
/* Line 661 of lalr1.cc  */
#line 6883 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 887:
/* Line 661 of lalr1.cc  */
#line 6884 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 888:
/* Line 661 of lalr1.cc  */
#line 6885 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 889:
/* Line 661 of lalr1.cc  */
#line 6886 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 890:
/* Line 661 of lalr1.cc  */
#line 6887 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 891:
/* Line 661 of lalr1.cc  */
#line 6888 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 892:
/* Line 661 of lalr1.cc  */
#line 6889 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 893:
/* Line 661 of lalr1.cc  */
#line 6890 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 894:
/* Line 661 of lalr1.cc  */
#line 6891 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 895:
/* Line 661 of lalr1.cc  */
#line 6892 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 896:
/* Line 661 of lalr1.cc  */
#line 6893 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 897:
/* Line 661 of lalr1.cc  */
#line 6894 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 898:
/* Line 661 of lalr1.cc  */
#line 6895 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 899:
/* Line 661 of lalr1.cc  */
#line 6896 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("offset"))); }
    break;

  case 900:
/* Line 661 of lalr1.cc  */
#line 6897 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("limit"))); }
    break;

  case 901:
/* Line 661 of lalr1.cc  */
#line 6898 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 902:
/* Line 661 of lalr1.cc  */
#line 6899 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 903:
/* Line 661 of lalr1.cc  */
#line 6900 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 904:
/* Line 661 of lalr1.cc  */
#line 6901 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 905:
/* Line 661 of lalr1.cc  */
#line 6902 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 906:
/* Line 661 of lalr1.cc  */
#line 6903 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 907:
/* Line 661 of lalr1.cc  */
#line 6904 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 908:
/* Line 661 of lalr1.cc  */
#line 6905 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 909:
/* Line 661 of lalr1.cc  */
#line 6906 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 910:
/* Line 661 of lalr1.cc  */
#line 6907 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 911:
/* Line 661 of lalr1.cc  */
#line 6908 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 912:
/* Line 661 of lalr1.cc  */
#line 6909 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 913:
/* Line 661 of lalr1.cc  */
#line 6910 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 914:
/* Line 661 of lalr1.cc  */
#line 6911 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 915:
/* Line 661 of lalr1.cc  */
#line 6912 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 916:
/* Line 661 of lalr1.cc  */
#line 6913 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 917:
/* Line 661 of lalr1.cc  */
#line 6914 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 918:
/* Line 661 of lalr1.cc  */
#line 6915 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 919:
/* Line 661 of lalr1.cc  */
#line 6916 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 920:
/* Line 661 of lalr1.cc  */
#line 6917 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 921:
/* Line 661 of lalr1.cc  */
#line 6918 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 922:
/* Line 661 of lalr1.cc  */
#line 6919 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 923:
/* Line 661 of lalr1.cc  */
#line 6920 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 924:
/* Line 661 of lalr1.cc  */
#line 6921 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 925:
/* Line 661 of lalr1.cc  */
#line 6922 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 926:
/* Line 661 of lalr1.cc  */
#line 6923 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 927:
/* Line 661 of lalr1.cc  */
#line 6924 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 928:
/* Line 661 of lalr1.cc  */
#line 6925 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 929:
/* Line 661 of lalr1.cc  */
#line 6926 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 930:
/* Line 661 of lalr1.cc  */
#line 6927 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 931:
/* Line 661 of lalr1.cc  */
#line 6928 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 932:
/* Line 661 of lalr1.cc  */
#line 6929 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 933:
/* Line 661 of lalr1.cc  */
#line 6930 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 934:
/* Line 661 of lalr1.cc  */
#line 6931 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 935:
/* Line 661 of lalr1.cc  */
#line 6932 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 936:
/* Line 661 of lalr1.cc  */
#line 6933 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 937:
/* Line 661 of lalr1.cc  */
#line 6934 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 938:
/* Line 661 of lalr1.cc  */
#line 6935 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 939:
/* Line 661 of lalr1.cc  */
#line 6936 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 940:
/* Line 661 of lalr1.cc  */
#line 6937 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 941:
/* Line 661 of lalr1.cc  */
#line 6938 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 942:
/* Line 661 of lalr1.cc  */
#line 6939 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 943:
/* Line 661 of lalr1.cc  */
#line 6940 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 944:
/* Line 661 of lalr1.cc  */
#line 6941 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 945:
/* Line 661 of lalr1.cc  */
#line 6942 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 946:
/* Line 661 of lalr1.cc  */
#line 6943 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 947:
/* Line 661 of lalr1.cc  */
#line 6944 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 948:
/* Line 661 of lalr1.cc  */
#line 6945 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 949:
/* Line 661 of lalr1.cc  */
#line 6946 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 950:
/* Line 661 of lalr1.cc  */
#line 6947 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 951:
/* Line 661 of lalr1.cc  */
#line 6948 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 952:
/* Line 661 of lalr1.cc  */
#line 6949 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 953:
/* Line 661 of lalr1.cc  */
#line 6950 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 954:
/* Line 661 of lalr1.cc  */
#line 6951 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 955:
/* Line 661 of lalr1.cc  */
#line 6952 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 956:
/* Line 661 of lalr1.cc  */
#line 6953 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 957:
/* Line 661 of lalr1.cc  */
#line 6954 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 958:
/* Line 661 of lalr1.cc  */
#line 6955 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 959:
/* Line 661 of lalr1.cc  */
#line 6956 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 960:
/* Line 661 of lalr1.cc  */
#line 6957 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 961:
/* Line 661 of lalr1.cc  */
#line 6958 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 962:
/* Line 661 of lalr1.cc  */
#line 6959 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 963:
/* Line 661 of lalr1.cc  */
#line 6960 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 964:
/* Line 661 of lalr1.cc  */
#line 6961 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 965:
/* Line 661 of lalr1.cc  */
#line 6962 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 966:
/* Line 661 of lalr1.cc  */
#line 6963 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 967:
/* Line 661 of lalr1.cc  */
#line 6964 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 968:
/* Line 661 of lalr1.cc  */
#line 6965 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 969:
/* Line 661 of lalr1.cc  */
#line 6966 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 970:
/* Line 661 of lalr1.cc  */
#line 6967 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 971:
/* Line 661 of lalr1.cc  */
#line 6968 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 972:
/* Line 661 of lalr1.cc  */
#line 6969 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 973:
/* Line 661 of lalr1.cc  */
#line 6970 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 974:
/* Line 661 of lalr1.cc  */
#line 6971 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 975:
/* Line 661 of lalr1.cc  */
#line 6972 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 976:
/* Line 661 of lalr1.cc  */
#line 6973 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 977:
/* Line 661 of lalr1.cc  */
#line 6974 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 978:
/* Line 661 of lalr1.cc  */
#line 6975 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 979:
/* Line 661 of lalr1.cc  */
#line 6976 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 980:
/* Line 661 of lalr1.cc  */
#line 6977 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 981:
/* Line 661 of lalr1.cc  */
#line 6978 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 982:
/* Line 661 of lalr1.cc  */
#line 6979 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 983:
/* Line 661 of lalr1.cc  */
#line 6980 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 984:
/* Line 661 of lalr1.cc  */
#line 6981 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 985:
/* Line 661 of lalr1.cc  */
#line 6982 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 986:
/* Line 661 of lalr1.cc  */
#line 6983 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 987:
/* Line 661 of lalr1.cc  */
#line 6984 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 988:
/* Line 661 of lalr1.cc  */
#line 6985 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 989:
/* Line 661 of lalr1.cc  */
#line 6986 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 990:
/* Line 661 of lalr1.cc  */
#line 6987 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 991:
/* Line 661 of lalr1.cc  */
#line 6988 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 992:
/* Line 661 of lalr1.cc  */
#line 6989 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 993:
/* Line 661 of lalr1.cc  */
#line 6990 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 994:
/* Line 661 of lalr1.cc  */
#line 6991 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 995:
/* Line 661 of lalr1.cc  */
#line 6992 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 996:
/* Line 661 of lalr1.cc  */
#line 6993 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 997:
/* Line 661 of lalr1.cc  */
#line 6994 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 998:
/* Line 661 of lalr1.cc  */
#line 6995 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 999:
/* Line 661 of lalr1.cc  */
#line 6996 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 1000:
/* Line 661 of lalr1.cc  */
#line 6997 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 1001:
/* Line 661 of lalr1.cc  */
#line 6998 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 1002:
/* Line 661 of lalr1.cc  */
#line 6999 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 1003:
/* Line 661 of lalr1.cc  */
#line 7000 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 1004:
/* Line 661 of lalr1.cc  */
#line 7001 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 1005:
/* Line 661 of lalr1.cc  */
#line 7002 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 1006:
/* Line 661 of lalr1.cc  */
#line 7003 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 1007:
/* Line 661 of lalr1.cc  */
#line 7004 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 1008:
/* Line 661 of lalr1.cc  */
#line 7005 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 1009:
/* Line 661 of lalr1.cc  */
#line 7006 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 1010:
/* Line 661 of lalr1.cc  */
#line 7007 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 1011:
/* Line 661 of lalr1.cc  */
#line 7008 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 1012:
/* Line 661 of lalr1.cc  */
#line 7009 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 1013:
/* Line 661 of lalr1.cc  */
#line 7010 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 1014:
/* Line 661 of lalr1.cc  */
#line 7011 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 1015:
/* Line 661 of lalr1.cc  */
#line 7012 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 1016:
/* Line 661 of lalr1.cc  */
#line 7013 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 1017:
/* Line 661 of lalr1.cc  */
#line 7014 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 1018:
/* Line 661 of lalr1.cc  */
#line 7015 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 1019:
/* Line 661 of lalr1.cc  */
#line 7016 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1020:
/* Line 661 of lalr1.cc  */
#line 7017 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1021:
/* Line 661 of lalr1.cc  */
#line 7018 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1022:
/* Line 661 of lalr1.cc  */
#line 7019 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1023:
/* Line 661 of lalr1.cc  */
#line 7020 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1024:
/* Line 661 of lalr1.cc  */
#line 7021 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1025:
/* Line 661 of lalr1.cc  */
#line 7022 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1026:
/* Line 661 of lalr1.cc  */
#line 7023 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1027:
/* Line 661 of lalr1.cc  */
#line 7024 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1028:
/* Line 661 of lalr1.cc  */
#line 7025 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1029:
/* Line 661 of lalr1.cc  */
#line 7026 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1030:
/* Line 661 of lalr1.cc  */
#line 7027 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1031:
/* Line 661 of lalr1.cc  */
#line 7028 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1032:
/* Line 661 of lalr1.cc  */
#line 7029 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1033:
/* Line 661 of lalr1.cc  */
#line 7030 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1034:
/* Line 661 of lalr1.cc  */
#line 7031 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1035:
/* Line 661 of lalr1.cc  */
#line 7032 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1036:
/* Line 661 of lalr1.cc  */
#line 7033 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1037:
/* Line 661 of lalr1.cc  */
#line 7034 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1038:
/* Line 661 of lalr1.cc  */
#line 7035 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1039:
/* Line 661 of lalr1.cc  */
#line 7036 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1040:
/* Line 661 of lalr1.cc  */
#line 7037 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1041:
/* Line 661 of lalr1.cc  */
#line 7038 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1042:
/* Line 661 of lalr1.cc  */
#line 7039 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1043:
/* Line 661 of lalr1.cc  */
#line 7040 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1044:
/* Line 661 of lalr1.cc  */
#line 7041 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1045:
/* Line 661 of lalr1.cc  */
#line 7042 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1046:
/* Line 661 of lalr1.cc  */
#line 7043 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1047:
/* Line 661 of lalr1.cc  */
#line 7044 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1048:
/* Line 661 of lalr1.cc  */
#line 7046 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("null"))); }
    break;

  case 1049:
/* Line 661 of lalr1.cc  */
#line 7047 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("true"))); }
    break;

  case 1050:
/* Line 661 of lalr1.cc  */
#line 7048 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("false"))); }
    break;

  case 1051:
/* Line 661 of lalr1.cc  */
#line 7049 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("select"))); }
    break;

  case 1052:
/* Line 661 of lalr1.cc  */
#line 7050 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("jsoniq"))); }
    break;

  case 1053:
/* Line 661 of lalr1.cc  */
#line 7056 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 661 of lalr1.cc  */
#line 11036 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1563;
  const short int
  jsoniq_parser::yypact_[] =
  {
      5108, -1563, -1563, -1563, -1563,  6066,  6066,  6066,  6066, -1563,
   -1563,   315,   461, -1563,   144,   351, -1563, -1563, -1563,   549,
   -1563, -1563, -1563,   514,   539,   613,  4589,   580,   654,   716,
   -1563,    74, -1563,   683, -1563, -1563, -1563, -1563, -1563,   836,
   -1563,   779,   783, -1563, -1563, -1563, -1563,   806, -1563,   848,
   -1563,   814,   841, -1563,   332, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,   869,
     884, -1563, -1563, -1563, -1563,   728, 13698, -1563, -1563, -1563,
     890, -1563, -1563, -1563,   901, -1563,   908,   919, -1563, -1563,
   18281, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,   925,
   -1563, -1563,   922,   923, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563,  6066,  8610,  8928, 18281, -1563, -1563,   893, -1563, -1563,
   -1563, -1563,   894, -1563, -1563,   926, 18281, -1563, 14937,   929,
     932, -1563, -1563, -1563, -1563, -1563, -1563,   933, -1563, -1563,
   12744, -1563, -1563, -1563, -1563, -1563, -1563,   903, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563,    66, -1563,   838, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
     194,   902,   210, -1563,   -70,   564, -1563, -1563, -1563, -1563,
   -1563, -1563,   942, -1563,   813,   815,   816, -1563, -1563,   907,
     912, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563,  4818, -1563, 13380, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563,  9246,  9564, -1563,   746, -1563, -1563,
   -1563, -1563, -1563,  5428,  6384,  1069, -1563,  6702, -1563, -1563,
     159,   100, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563,   104, -1563, -1563, -1563,
   -1563, -1563, -1563,   484, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563,  6066, -1563, -1563, -1563, -1563,    33, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563,   382, -1563,   877,
   -1563, -1563, -1563,   659, -1563,   575, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563,   905,   981, -1563, -1563,   997,   819,   977,
     720,   578,   559,   701, -1563,  1029,   876,   980,   982, 10836,
   -1563,   895, -1563, -1563,   279, -1563, -1563, 13062, -1563,    -1,
   -1563,   927, 13698, -1563,   927, 13698, -1563, -1563, -1563,   763,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563,   935, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563,   713, -1563, -1563, -1563, -1563,
   -1563,   906, -1563,  6066,   909,   910,   911,  6066,   492,   492,
    1060,   635,   676,   293, 18885, 18281,   434,  1050, 18281,   945,
     986,   610, 18281,   781,   852, 18281, 18281,   788,   831,    41,
   -1563, -1563, -1563, 18281,  6066,   917,  6066,   345, 11154, 15241,
   18281,    55,   953, 11154,  1108,   185,   469, 18281,   993,   969,
    1006, -1563,   928, 11154, 15545, 18281, 18281, 18281,  6066,   930,
   11154, 11154, 18281,  6066,   960,   967, -1563, -1563, -1563, 11154,
   15849,   958, -1563,   965, -1563, -1563, -1563, -1563,   966, -1563,
     968, -1563, -1563, -1563, -1563, -1563,   970, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, 18281, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563,   983, 18281, -1563, -1563,   940,  5748,  1007,   299,  1010,
     976,   985,   987, 18281,  6066, -1563,   989,   373, -1563,   659,
   -1563,    99,  1100, 11154, 11154, -1563,    96, -1563, -1563,  1121,
   -1563, -1563, -1563, -1563, 11154,   934, -1563,  1116, 11154, 11154,
   18589, 11154, 11154, 11154, 11154, 18589, 11154,   918, 18281,   957,
     964, 11154, 11154,  6066,   913, 18281, -1563, -1563,    61, -1563,
      58, 11154,  6384, -1563, -1563, -1563, -1563, -1563,   144,   716,
     107,   116,  1156,  7020,  3295,  7338,  3624,   901, -1563, -1563,
     386,   901, -1563, 11154,  4260, -1563,  1041,   690,    74,   998,
     991,  1000, 11154, 11154, -1563, -1563, 11154,   807, -1563, -1563,
    6066, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
     882,   889, 18281,  1049, 11472, 11472, 11790, -1563, 11790, 11790,
   -1563, 11790, -1563, 11790, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, 11790, 11790,  1098, 11790, 11790, 11790, 11790, 11790, 11790,
   11790, 11790, 11790, 11790, 11790, 11790,   937,  1083,  1087,  1088,
   -1563, -1563, -1563, 12426,  6066, -1563, -1563, 12744, 12744, 11154,
     927, -1563, -1563,   927, -1563, 14320,  9882,  7974,   927,   994,
    1035,  8292, -1563, -1563, -1563, -1563,    35, -1563,    38, -1563,
   -1563, -1563, -1563, -1563, -1563,  1079,  1080,   580,  1159, -1563,
   -1563, 18885,   941,   569, 18281,  1028,  1030,   941,  1060,  1064,
    1061, -1563, -1563, -1563,   176,   943,  1099,   891, 18281,  1052,
   11154,  1081, 18281, 18281, -1563,  1065,  1016, -1563,  1018,   965,
     783, -1563,  1020,  1021,   130, -1563,   229,   310,  1104, -1563,
      40, 18281,  1118,   313, -1563,  6066, -1563,   106, -1563, 18281,
    1117,  1170, 18281,  1060,  1119,   429, 18281, 11154,    74, -1563,
     139,  1031, -1563,  1032,  1033,  1034,    52, -1563,   475,  1040,
   -1563,   114,   122,  1063, -1563,  1043,  6066,  6066,   253, -1563,
     420,   478,   617, 11154,   286, -1563, -1563, 11154, 11154, -1563,
   11154, 11154, 11154, 11154, -1563, 11154, -1563, 11154, -1563, 18281,
    1100, -1563,    15,   362,   364, -1563, -1563, -1563,   390, -1563,
     326, -1563, -1563,  1071,  1074,  1075,  1076,  1077,   763,   713,
     140,   300,     3,    14,  1124,   663,   975,   -54,   249, -1563,
    1089, -1563, -1563,  1042,   132,  5748,   409, 14016,   913, -1563,
    1104, -1563, -1563,   996, -1563,   159,   163,  1201,   629, -1563,
   -1563,   117, -1563, -1563, -1563,   119, -1563,    39, -1563, -1563,
   -1563, -1563, -1563,  3942, -1563, -1563, -1563, 18281,  1067, 11154,
   12108, -1563, -1563, -1563, -1563, -1563, -1563, -1563,  1104, 18281,
      83,   981, -1563, -1563, -1563, -1563, -1563, 11790, -1563, -1563,
   -1563,    95, -1563,   578,   578,   754,   559,   559,   559,   559,
     701,   701, -1563, -1563, 17369, 17369, 18281, 18281, -1563,  1054,
   -1563, -1563,   383, -1563, 10200, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563,   480, -1563, -1563, -1563,   481,   492, -1563,
   -1563,   532,   534,   734, -1563,   580, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563,   941, -1563,  1106, 17673,
    1097, 11154, -1563, -1563, -1563,  1147,  1060,  1060,   941, -1563,
     835,  1060,   697, 18281,   686,   692,  1213, -1563, -1563,   950,
     605, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563,   176,   105,  1011,   642, 11154, -1563, 18281,  1150,
     946,  1060, -1563, -1563, -1563, -1563,  1093, 18281, -1563, 18281,
   -1563, 17977,  1123, 17369,  1131, 11154,   136,  1105,    62,  1147,
   17369,  1136,  1161,  1072,  1056,  1126,  1060,  1102,  1128,  1168,
    1060, 11154,   -20, -1563, -1563, -1563,  1113, -1563, -1563, -1563,
   -1563,  1154, 11154, 11154,  1120, -1563,  1173,  1174,  6066, -1563,
    1092,  1094,  1127, 18281, -1563, 18281, -1563, 11154,  1137,  1095,
   11154, -1563,  1160,  1167, -1563,   133,   141,   161,  1256, -1563,
     304, -1563,   665,  1138, -1563, -1563,  1262, -1563,   525, 11154,
   11154, 11154,   773, 11154, 11154, 11154, 11154, 11154, 11154, 11154,
   11154, 11154, 18589,  1175, 11154, 11154, -1563,  7656,   128,  1044,
   -1563,    28, -1563, 11154,   120,    72,    39,  7338,  3624,  7338,
    1215, -1563, -1563, 11154,   826,  1190, -1563, 18281,  1192,  1193,
   -1563,   512,  1038, -1563, -1563,   694,    83, -1563, 11154,    95,
     528,   296, -1563,  1009,   108,  1037,  1036, -1563, -1563,   852,
   -1563,  1039,   662,  1148,  1151, 16153,  1152,  1153,  1157,  1158,
    1162, -1563,   652, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563,  1171, -1563, -1563, -1563, -1563, -1563,   174,
   10518, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
     756, -1563,  1275, 17673,   842, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563,  1014, -1563, -1563,  1288, -1563, -1563,
   -1563, -1563, -1563,   645,  1289, -1563,   818, -1563, -1563, -1563,
     958,   539,   683,   966,   779,   968,   970, -1563,  1153,  1157,
    1158, -1563,   652,   652, 12426,  1026,  1008, -1563,  1147,   105,
    1090,  1130,  6066,  1140,  1141,  1181,  1143,  1144, 18281, -1563,
      64, -1563, 18281, -1563, 11154,  1179, 11154,  1206, 11154,   275,
    1187, -1563, -1563, -1563, 17369, -1563,  6066,  1060,  1229, -1563,
   -1563, -1563,  1060,  1229, -1563, 11154,  1194,  6066, 18281, -1563,
   -1563, 11154, 11154,   558, -1563,    37,   767, -1563, 16457,   845,
   -1563,   847, -1563,  1155, -1563, -1563,  6066,  1163,  1165, -1563,
   11154, -1563, -1563, 11154, 11154,  1139,  1173,  1243, -1563,  1211,
   -1563,   679, -1563, -1563,  1339, -1563, -1563,  6066, 18281, -1563,
     745, -1563, -1563, -1563,  6066,  1164,  1107,  1109, -1563, -1563,
   -1563,  1110,  1111, -1563, -1563, -1563,  1252, -1563, -1563, -1563,
   -1563,  1112,   458, 18281,   808, -1563,  1198,  1203,  1204,  1209,
   -1563,   877,   659, 14016,  1044, -1563,  7656, 14016, -1563, -1563,
    1201,   518, -1563, -1563, -1563,  1190, -1563,  1060, -1563,   886,
   -1563,   620,  1258, -1563, 11154,   693,  1060, -1563, 12108, 11154,
    1210, -1563,  1247,  1248, 11154, 18281,   931,  1291, -1563, -1563,
   -1563,   410,  1183, -1563,    95,  1122, -1563, -1563,   -45, -1563,
     281,   243,  1129,    95,   281, 11790, -1563,   162, -1563, -1563,
   -1563, -1563, -1563, -1563,    95,  1227,  1101,   943,   243, -1563,
   -1563,  1084,  1305, -1563, -1563, -1563, 14624,  1195, -1563,  1199,
    1202,  1205,  1207,  1208,  1214, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,  1358,
      32,  1364,    32,  1132,  1292, -1563, -1563,  1225, 18281,  1134,
   -1563, -1563, 12426, -1563,  1216, -1563, -1563, -1563, -1563, -1563,
   -1563, 11154,  1254, -1563, -1563, 11154, -1563,   529, -1563, 11154,
    1259, 11154, -1563,  1277,  1279,  1313,  1060,  1229, -1563, 11154,
    1233, -1563, -1563, -1563,   808, -1563,    37, 11154,  6066,   808,
      37, -1563, 18281,   698, -1563, 16761,   526, -1563, 17065,   808,
   -1563, -1563,  1235, -1563, -1563, -1563, -1563, -1563, 11154,   850,
    1256, 18281,   846, -1563,  1237,  1256, 18281, -1563,  1241, -1563,
   11154, 11154, 11154, 11154,  1103, 11154, 11154, -1563, 11154, 11154,
   11154, 11154,  7656,   316, -1563, -1563, -1563, -1563, -1563,  1258,
   -1563, -1563, -1563, 11154,  1268, -1563, -1563, -1563, 11154, 18281,
   18281, -1563,   735, -1563, 11154, -1563, -1563, -1563,  1244, 11790,
   -1563, -1563, -1563, -1563, -1563,   347, 11790, 11790,  -104, -1563,
    1037, -1563,   369, -1563,  1036,    95,  1273, -1563, -1563,  1145,
   -1563, -1563, -1563, -1563,  1337,  1245, -1563,   491, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563,   551,   551, -1563,    32,
   -1563, -1563,   509, -1563,  1404,     2,  1340,  1246, 12426,   -24,
    1146,  1269, -1563, -1563, 11154, -1563, 11154,  1290, -1563, 11154,
   -1563,  7656, 11154,  1060, -1563, -1563, -1563, 11154, 11154, -1563,
   -1563, -1563,  7656,  7656,  1347, 17369,  6066, 18281,   698, 18281,
   11154, 18281,   698,  7656, -1563,   548,    34,  1256, 18281, -1563,
    1242,  1256, -1563, -1563, -1563, -1563, -1563, 11154, -1563, -1563,
   -1563,   187,   238,   250, 11154, -1563, -1563,  1192, 11154, -1563,
   -1563,  1390, -1563, -1563, -1563,   559, 11790, 11790,   754,   731,
   -1563, -1563, -1563, -1563, -1563, -1563, 11154, -1563, 17369, -1563,
   17369,  1354, -1563, -1563, -1563,  1420, -1563, -1563, -1563,  1178,
    1344, -1563, -1563,  1346, -1563,   537, 18281,  1336,  1223, 18281,
   12426, -1563, -1563, 11154, -1563, -1563, -1563,  1229, -1563, -1563,
   17369, -1563, -1563, -1563,  1362, 11154,   808, -1563,  1363,  7656,
   -1563, 18281,   596,   417, -1563,  1264,  1256, -1563,  1265, -1563,
    1257,  1173,  1174,   413, -1563,  1192,  1341,   754,   754, 11790,
     415, -1563, -1563, 17369, -1563, -1563,  1340, 12426, -1563,  1258,
    1166, 18281,  1348,  1230,  1346, -1563,   698, 17369,  6066, 17369,
     808, -1563, -1563,  1375,   597, -1563, -1563, -1563, -1563,  1286,
     460, -1563, -1563, -1563,  1274, -1563,  7656,   855, -1563, -1563,
   18281,   754, -1563, -1563, -1563, -1563, -1563, 11154,  1169, 18281,
    1355,  6066,   698, -1563, -1563,   698, 11154, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563,  1357, -1563, -1563,  1176,  1172, 18281,
   -1563, -1563, 11154,  7656, 18281,  1177, 11154,  1180,   808, 12426,
   -1563, 12426,  7656, -1563,  1278,  1185, 18281,  1250,  1359, 18281,
    1182, 12426, -1563
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       165,   477,   478,   823,   479,   168,   168,   168,     0,   846,
    1053,   120,   122,   652,   941,   950,   888,   851,   849,   825,
     942,   945,   895,   855,   826,   828,     0,   951,   830,   948,
     919,   897,   871,   827,   892,   893,   946,   943,   891,   832,
     949,   833,   834,   990,  1002,   989,   889,   910,   904,   835,
     890,   837,   836,   991,   928,   929,   894,   868,  1012,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1036,
    1043,   918,   914,   905,   882,   824,     0,   913,   921,   930,
    1037,   909,   510,   883,   884,   944,  1038,  1044,   906,   923,
       0,   516,   466,   512,   916,   848,   907,   908,   937,   911,
     927,   936,  1042,  1045,   854,   896,   939,   511,   926,   932,
     829,   168,     0,     0,     0,   413,   924,   935,   940,   938,
     917,   903,   992,   901,   902,  1039,     0,   412,     0,  1040,
    1046,   933,   899,   900,   885,   912,  1051,  1041,   211,   444,
       0,   476,   934,   915,   922,   931,   925,   993,   876,   881,
     880,   879,   878,   877,   838,   898,     0,   847,  1052,   947,
     869,  1048,  1049,  1050,   983,   982,   984,   853,   852,   872,
     981,   831,   978,   986,   980,   979,   875,   920,   976,   988,
     987,   975,   873,   985,   997,   998,   995,   996,   994,   839,
     999,  1000,  1001,   967,   966,   953,   867,   860,   960,   956,
     870,   866,   968,     0,   856,   857,   850,   859,   965,   964,
     961,   957,   973,   974,   972,   963,   959,   952,   858,   971,
     970,   862,   864,   863,   958,   962,   954,   865,   955,   861,
     969,  1023,  1024,  1025,  1026,  1027,  1028,  1004,  1005,  1003,
    1009,  1010,  1011,  1006,  1007,  1008,   874,  1029,  1030,  1031,
    1032,  1033,  1034,  1035,     0,     0,   840,   977,  1047,   842,
     841,   843,   844,   165,   165,     0,     2,   165,     9,    11,
      23,     0,    28,    31,    36,    37,    38,    39,    40,    41,
      42,    32,    58,    59,    33,    34,     0,    76,    79,    80,
      35,    81,    82,     0,   118,    83,    84,    85,    86,    18,
     162,   163,   164,   171,   174,   503,   175,     0,   176,   177,
     178,   179,   180,   181,   182,   185,   186,     0,   212,   220,
     215,   249,   259,     0,   247,     0,   248,   222,   216,   184,
     217,   183,   218,   221,   362,   364,   366,   368,   378,   380,
     384,   386,   389,   394,   397,   400,   402,   404,   406,     0,
     410,   417,   416,   418,     0,   435,   419,   440,   443,   445,
     448,   450,     0,   455,   452,     0,   463,   473,   475,   449,
     480,   494,   508,   495,   496,   497,   500,   501,   498,   502,
     525,   526,   499,   529,   531,   532,   533,   530,   578,   579,
     580,   581,   582,   583,   584,   472,   624,     0,   615,   623,
     622,   621,   620,   617,   619,   616,   618,   509,    43,   223,
     224,   226,   225,   227,   219,   505,   506,   507,   504,   229,
     232,   228,   230,   231,   474,   822,   845,   941,   950,   948,
    1052,     0,   166,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,   285,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   468,   471,   458,     0,
       0,   825,   855,   828,   886,   951,   830,   897,   832,   910,
     835,   837,   836,   928,  1036,  1043,   824,  1037,   884,  1038,
    1044,   911,  1042,  1045,   935,   992,  1039,  1040,  1046,  1041,
     993,   981,   978,   980,   979,   873,   997,   998,   995,   839,
     999,   887,   857,   977,   464,   822,   456,     0,   192,   457,
     460,   825,   826,   828,   827,   832,   833,   834,   835,   824,
     831,   513,     0,   462,   461,     0,     0,   212,     0,   474,
     830,   837,   836,     0,   168,   800,   999,     0,   220,     0,
     514,     0,   545,     0,     0,   467,     0,   438,   439,     0,
     470,   469,   459,   442,     0,     0,   574,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   367,   802,     0,   804,
       0,     0,   165,     3,     4,     1,    10,    12,     0,     0,
       0,     0,     6,   165,     0,   165,     0,     0,   119,   172,
       0,     0,   190,     0,     0,   199,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   236,     0,     0,   204,   233,
       0,   254,   250,   260,   255,   256,   251,   253,   252,   264,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
     427,     0,   373,     0,   428,   421,   426,   425,   424,   423,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     415,   414,   411,     0,   168,   436,   441,     0,     0,     0,
     451,   491,   454,   453,   465,     0,     0,     0,   481,     0,
       0,     0,   586,   588,   592,   594,     0,   124,     0,   821,
      47,    44,    45,    48,    49,     0,     0,     0,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   659,   660,   661,     0,   103,   142,     0,     0,   112,
       0,     0,     0,     0,   127,     0,     0,   632,     0,     0,
       0,   627,     0,     0,     0,   642,     0,     0,   262,   267,
       0,     0,   134,     0,   138,   168,   528,     0,    60,     0,
      69,     0,     0,     0,    61,     0,     0,     0,     0,   630,
       0,     0,   633,     0,     0,     0,     0,   333,     0,     0,
     631,     0,     0,     0,   650,     0,     0,     0,     0,   636,
       0,     0,   194,     0,     0,   188,   187,     0,     0,   806,
       0,     0,     0,     0,   513,     0,   801,     0,   515,   546,
     545,   542,     0,     0,     0,   576,   575,   437,     0,   573,
       0,   672,   673,     0,     0,     0,     0,     0,   815,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   678,
       0,   202,   203,     0,     0,     0,     0,     0,   207,   208,
     263,   803,   805,     0,     5,    24,     0,    25,     0,     7,
      29,     0,    15,     8,    30,     0,    19,   941,    77,    16,
      78,    20,   193,     0,   191,   213,   214,     0,     0,     0,
       0,   257,   258,   302,   205,   234,   237,   238,   261,     0,
       0,   363,   365,   371,   377,   376,   375,     0,   372,   369,
     370,     0,   381,   388,   387,   385,   391,   392,   393,   390,
     395,   396,   399,   398,     0,     0,     0,     0,   420,     0,
     446,   447,     0,   492,     0,   488,   489,   490,   485,   484,
     521,   482,   523,     0,   625,   527,   519,     0,     0,   121,
     123,     0,     0,     0,   102,     0,    92,    94,    95,    96,
      97,    99,   100,   101,    93,    98,    88,    89,     0,     0,
     108,     0,   104,   106,   107,   114,     0,     0,    87,    46,
       0,     0,     0,     0,     0,     0,     0,   750,   755,     0,
       0,   751,   785,   738,   740,   741,   742,   744,   746,   745,
     743,   747,     0,     0,     0,     0,     0,   111,     0,   144,
       0,     0,   591,   585,   628,   629,     0,     0,   646,     0,
     643,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,   135,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,   283,   289,   286,     0,   635,   634,   641,
     649,     0,     0,     0,     0,   590,     0,     0,     0,   430,
       0,     0,     0,     0,   639,     0,   637,     0,   195,     0,
       0,   808,     0,   474,   807,     0,     0,     0,   545,   543,
       0,   534,     0,     0,   517,   518,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,     0,
     686,     0,   209,     0,     0,     0,     0,   165,     0,   165,
       0,   173,   246,     0,   317,   313,   315,     0,   310,   303,
     304,     0,     0,   239,   240,     0,   245,   374,     0,     0,
       0,     0,   716,   382,   689,   693,   695,   697,   699,   702,
     709,   710,   718,   951,   829,     0,   838,   842,   841,   843,
     844,   401,   597,   604,   605,   608,   653,   654,   609,   610,
     613,   403,   405,   408,   614,   407,   434,   493,   486,     0,
       0,   483,   520,   125,    56,    57,    54,    55,   131,   130,
       0,    90,     0,     0,     0,   109,   110,   115,    74,    75,
      52,    53,    73,   756,     0,   759,   786,     0,   749,   748,
     753,   752,   784,     0,     0,   761,     0,   757,   760,   739,
       0,     0,     0,     0,     0,     0,     0,   626,     0,     0,
       0,   143,   146,   148,     0,     0,     0,   113,   116,     0,
       0,     0,   168,     0,     0,   650,     0,     0,     0,   269,
       0,   596,     0,   270,     0,     0,     0,     0,     0,     0,
       0,   141,   136,   139,     0,   189,     0,     0,    71,    65,
      68,    67,     0,    63,   287,     0,     0,   168,     0,   331,
     335,     0,     0,     0,   338,     0,     0,   344,     0,     0,
     351,     0,   355,     0,   432,   431,   168,     0,     0,   196,
       0,   198,   332,     0,     0,     0,     0,     0,   546,     0,
     536,     0,   569,   566,     0,   570,   571,     0,     0,   565,
       0,   540,   568,   567,     0,     0,     0,     0,   665,   666,
     662,     0,     0,   670,   671,   667,   811,   812,   676,   816,
     674,     0,     0,     0,     0,   680,   830,   837,   836,   999,
     201,     0,     0,     0,   681,   682,     0,     0,   210,   814,
      26,     0,    17,    21,    22,   314,   326,     0,   327,     0,
     318,   319,   320,   321,     0,   513,     0,   311,     0,     0,
       0,   241,     0,     0,     0,     0,   296,     0,   293,   298,
     244,     0,     0,   700,   713,     0,   379,   383,     0,   732,
       0,     0,     0,     0,     0,     0,   688,   690,   691,   727,
     728,   729,   731,   730,     0,     0,   704,   703,     0,   707,
     711,   725,   723,   722,   715,   719,     0,     0,   600,     0,
       0,     0,     0,     0,     0,   601,   603,   602,   598,   409,
     487,   522,   524,   133,   132,    91,   105,   773,   754,     0,
     778,     0,   778,   767,   762,   147,   149,     0,     0,     0,
     117,   145,     0,    27,     0,   647,   648,   651,   644,   645,
     268,     0,     0,   282,   274,     0,   278,     0,   272,     0,
       0,     0,   137,     0,     0,    70,     0,    64,   288,     0,
       0,   334,   336,   341,     0,   339,     0,     0,     0,     0,
       0,   345,     0,     0,   359,     0,     0,   352,     0,     0,
     356,   433,     0,   640,   638,   197,   809,   810,     0,     0,
     545,     0,     0,   577,     0,   545,     0,   541,     0,    14,
       0,     0,     0,     0,     0,     0,     0,   679,     0,     0,
       0,     0,     0,     0,   683,   687,   330,   328,   329,   322,
     323,   324,   316,     0,     0,   312,   305,   291,     0,     0,
       0,   243,   294,   297,     0,   717,   708,   714,     0,     0,
     787,   788,   798,   797,   796,     0,     0,     0,     0,   789,
     694,   795,     0,   692,   696,     0,     0,   701,   705,     0,
     726,   721,   724,   720,     0,     0,   611,     0,   606,   658,
     599,   820,   819,   818,   607,   774,     0,     0,   772,   779,
     780,   776,     0,   771,     0,   769,     0,     0,     0,     0,
       0,     0,   587,   271,     0,   280,     0,     0,   276,     0,
     279,     0,     0,     0,    66,   290,   593,     0,     0,   342,
     346,   340,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   589,     0,     0,   545,     0,   572,
       0,   545,   595,   663,   664,   668,   669,     0,   675,   817,
     677,     0,     0,     0,     0,   684,   325,   306,     0,   292,
     300,   301,   295,   242,   712,   799,     0,     0,   791,     0,
     737,   736,   735,   734,   733,   698,     0,   790,     0,   655,
       0,     0,   783,   782,   781,     0,   775,   768,   766,     0,
     763,   764,   758,   150,   152,   154,     0,     0,     0,     0,
       0,   275,   273,     0,   281,   206,   361,    72,   337,   343,
       0,   360,   357,   353,     0,     0,     0,   347,     0,     0,
     349,     0,   555,   549,   544,     0,   545,   535,     0,   813,
       0,     0,     0,     0,   309,   307,     0,   793,   792,     0,
       0,   656,   612,     0,   777,   770,     0,     0,   156,   155,
       0,     0,     0,     0,   151,   277,     0,     0,     0,     0,
       0,   563,   557,     0,   556,   558,   564,   561,   551,     0,
     550,   552,   562,   537,     0,   538,     0,     0,   685,   308,
       0,   794,   706,   657,   765,   153,   157,     0,     0,     0,
       0,     0,     0,   350,   348,     0,     0,   548,   559,   560,
     547,   553,   554,   539,     0,   299,   158,     0,     0,     0,
     358,   354,     0,     0,     0,     0,     0,     0,     0,     0,
     160,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1563, -1563,  -228,  -207, -1563,  1217,  1219, -1563,  1218,  -569,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1026, -1563, -1563, -1563, -1563,  -229,  -610, -1563,   732,  -163,
   -1563, -1563, -1563, -1563, -1563,   266,   493, -1563, -1563,    -5,
    -106,  1053, -1563,  1045, -1563, -1563,  -676, -1563,   436, -1563,
     226, -1563,  -252,  -297, -1563,  -556, -1563,     6,    67,   192,
    -301,  -188, -1563,  -900, -1563, -1563,   355, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563,   614, -1563,   -98,
    1464,     0, -1563, -1563,  -263, -1563, -1563,   339, -1563, -1563,
    -304, -1563, -1563, -1563,    16, -1563, -1563,  -118,  -970,  -761,
    -739, -1563, -1563,   702, -1563, -1563,   -91,    90, -1563, -1563,
   -1563,   101, -1562, -1563,   358,   109, -1563, -1563,   111, -1347,
   -1563,   952,   208, -1563, -1563,   204, -1056, -1563, -1563,   203,
   -1563, -1563, -1303, -1287, -1563,   199, -1453, -1563, -1563,   853,
    -165, -1563, -1563,  -589,   827, -1563, -1563,  -679,   283,  -663,
     331,   335, -1563, -1563, -1563,   565, -1563, -1563,  1184, -1563,
   -1563, -1563, -1563, -1563,  -899,  -327,  -696, -1563,  -109, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563,   -13,  -835, -1563,  -552,
     643,   219, -1563,  -435, -1563,   799, -1563,   801, -1563, -1563,
   -1563,   798, -1563, -1563, -1563, -1563, -1051, -1563,   189, -1563,
     681,  -822, -1563, -1563, -1563, -1563, -1563,  -288,  -278, -1259,
    -915, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563,  -785,  -905,  -227,  -893, -1563, -1563, -1563,  -558,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,  1070,
    1078,  -186,   489,  -686, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563, -1563, -1563, -1563,   168, -1563, -1563,   158, -1563,
     165, -1099, -1563, -1563, -1563,   118,   110,   -66,   380, -1563,
   -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563, -1563,
   -1563, -1563,   115, -1563, -1563, -1563,   -57,   377,   527, -1563,
   -1563, -1563, -1563, -1563,   311, -1563, -1563, -1436, -1563, -1563,
   -1563,  -595, -1563,    76, -1563,   -79, -1563, -1563, -1563, -1563,
   -1364, -1563,   127, -1563, -1563, -1563, -1563, -1563,   962, -1563,
   -1563, -1563, -1563, -1563,  -940,  -430,   961,   330, -1563
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   265,   644,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
    1298,   803,   283,   284,   285,   286,   287,   288,   996,   997,
     998,   289,   290,   291,  1002,  1003,  1004,   292,   458,   293,
     294,   736,   295,   460,   461,   462,   472,   793,   794,   296,
    1261,   297,  1743,  1744,   298,   299,   300,   565,   301,   302,
     303,   304,   305,   796,   306,   307,   548,   308,   309,   310,
     311,   312,   313,   658,   314,   315,   888,   889,   316,   317,
     318,   578,   320,   659,  1680,   673,  1165,  1166,   321,   661,
     322,   663,   664,   665,   579,   324,   325,   788,   789,  1416,
     479,   326,   480,   481,   930,  1417,  1418,  1419,   666,   667,
    1159,  1160,  1407,   668,  1155,  1156,  1400,  1401,  1402,  1403,
     327,   816,   817,   328,  1313,  1314,  1526,   329,  1316,  1317,
     330,   331,  1319,  1320,  1321,  1322,  1533,   332,   333,   334,
     335,   336,   937,   337,   338,  1426,   339,   340,   341,   342,
     343,   344,   345,   346,   347,  1202,   348,   349,   350,   351,
     691,   692,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     728,   721,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   973,   379,   380,   381,   382,   383,   384,  1350,   850,
     851,   852,  1774,  1819,  1820,  1813,  1814,  1821,  1815,  1351,
    1352,   385,   386,  1353,   387,   388,   389,   390,   391,   392,
     393,   394,  1058,  1534,  1468,  1192,  1627,  1193,  1203,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   823,  1274,   407,  1195,  1196,  1197,  1198,   408,   409,
     410,   411,   412,   413,   878,   879,   414,  1384,  1385,  1705,
    1141,  1173,  1436,  1437,  1174,  1175,  1176,  1177,  1178,  1446,
    1617,  1618,  1179,  1449,  1180,  1598,  1181,  1182,  1454,  1455,
    1623,  1621,  1438,  1439,  1440,  1441,  1723,   765,  1023,  1024,
    1025,  1026,  1027,  1028,  1247,  1647,  1740,  1248,  1645,  1738,
    1029,  1482,  1642,  1638,  1639,  1640,  1030,  1031,  1442,  1450,
    1608,  1443,  1604,  1427,   415,   416,   417,   418,   568,   419,
     420,   421,   422,   423,  1199,  1299,   424,   425,   426
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -888;
  const short int
  jsoniq_parser::yytable_[] =
  {
       319,   639,   614,   737,   737,   319,   319,   319,   319,   459,
     740,   431,   434,   435,   577,   581,   323,   958,   945,   662,
    1072,   323,   323,   323,   323,   908,   910,   715,  1110,  1056,
    1315,   593,  1537,  1084,  1549,   946,   947,   948,   949,   967,
     616,   631,  1171,   634,  1303,   800,   804,  1098,   868,  1191,
    1201,  1057,  1140,   875,  1580,  1581,   623,   624,   636,   632,
     660,  1349,   632,   544,   900,   904,    11,    12,    11,    12,
    1422,   983,   432,   432,   432,   436,  1052,   902,   906,   909,
     911,  1279,  1678,  1219,  1619,  1682,   444,   933,   444,   934,
     935,  1557,   936,  1263,   938,  1746,   445,   595,  1287,  1605,
     632,   632,   939,   940,   855,   632,  1224,   632,   632,   440,
     441,   319,   442,   443,   447,   632,   447,   632,   632,   448,
     632,   632,   838,   632,  1305,    13,   837,   323,  1772,   632,
     446,   632,   639,   632,   632,  1053,   639,  1054,  1527,  1162,
     632,   641,   632,   978,  1250,  1784,   978,  1111,  1281,  1251,
     779,   449,   450,  1150,   771,  1292,   618,   620,  1252,  1054,
    1081,  1054,   632,   604,   903,  1253,   643,  1254,   780,   643,
    1636,    11,    12,  1720,   791,   632,  1255,  1600,   432,  1131,
    1721,   440,   441,  1386,   442,   443,  1391,   638,   632,  1055,
    1722,   444,   628,   477,   717,   718,  1145,   433,   433,   433,
     437,   445,   446,  1256,   640,  1428,    82,   643,   629,  1747,
    1741,  1288,   629,  1501,   643,   739,  1112,  1601,  1773,   447,
    1227,    93,   643,  1829,   448,   979,   654,   642,   980,   655,
     643,  1012,  1706,  1013,   452,  1118,   643,  1637,   643,   632,
     643,   643,  1387,  1082,  1126,   792,   107,   643,   716,   643,
    1168,   632,   605,  1169,   632,  1127,   449,   450,   451,  1428,
    1530,   478,  1537,   319,   319,   639,  1606,   319,  1132,   643,
    1171,  1171,   856,   128,  1291,   662,  1517,  1014,  1429,   323,
     323,  1739,   643,   323,   596,  1284,  1339,   908,   910,   848,
    1349,  1748,  1459,  1557,   633,   643,  1064,  1289,   635,  1349,
     453,   895,   319,   566,  1086,  1163,   452,  1806,  1500,  1220,
     897,  1147,  1087,  1149,  1390,  1046,   847,  1285,   323,  1290,
    1474,   478,  1137,  1335,  1076,  1597,   900,   904,  1009,  1263,
    1459,  1336,  1429,  1306,   455,   640,   772,  1047,  1257,   640,
    1605,   454,   456,   478,   773,  1164,   643,   799,  1167,   722,
     457,  1337,   724,   638,  1842,   478,  1845,  1133,   643,   924,
    1834,   643,  1170,   632,  1470,   632,  1119,  1120,  1430,  1431,
     784,  1432,   453,  1069,   632,   797,  1410,  1780,  1433,   892,
     891,  1121,  -169,   632,   632,   810,  -170,   632,  1434,  1512,
     779,   632,   821,   822,  1081,  1122,  1194,  1194,  1798,  1716,
    1435,   828,   896,   898,   901,   905,   545,   838,   780,   492,
     632,   632,   913,   454,   632,   894,   632,   478,  1049,  1048,
     545,  1061,  1430,  1431,  1509,  1432,  1342,   598,  1781,   599,
    1258,  1259,  1260,   319,   714,  1015,  1340,   319,  1092,   455,
    1782,  1194,  1434,   601,   545,   602,  1817,   456,  1016,   323,
    1017,  1424,  1836,   323,  1435,   457,   545,   128,   545,  1116,
     745,  1018,  1019,  1020,   319,  1021,   319,  1022,   640,  1342,
     643,  1704,   643,   438,   128,  1262,   746,  1100,  1717,  1827,
     323,   643,   323,  1490,   839,   853,   854,   493,   319,  1817,
     643,   643,  1134,   319,   643,  1194,   858,   890,   643,   739,
    1050,  1349,  1194,  1062,   323,  1341,  1172,  1606,  1607,   323,
     932,    11,    12,   463,   884,   886,   600,   643,   643,  1502,
    1117,   643,    13,   643,  1053,  1171,  1123,  1124,  1093,   695,
    1387,   776,   603,   778,  1171,   781,  1475,   908,   910,   908,
    1537,  1125,  1345,  1213,  1346,  1171,   696,  1113,  1140,  1114,
    1510,  1626,  1575,  1818,   928,   819,   478,  1602,    13,   846,
     825,   494,   495,   755,  1603,   756,   319,  -169,  1487,  1207,
    1053,  -170,  1347,  1071,   319,  1115,  1228,  1229,   669,   725,
    1372,  1232,   323,   801,   639,  1345,  1095,  1346,  1210,  1210,
     323,  1392,  1393,  1394,  1139,  1595,  1851,   637,  1828,  1730,
    1832,  1811,  1811,    82,   749,  1342,  1342,  1053,   960,   961,
    1094,  1271,  1151,   319,   726,  1347,   727,  1735,    93,   439,
    1584,   962,   319,   459,  1083,   758,  1054,  1194,   962,   323,
     903,   802,  1053,   319,   319,   319,   319,  1757,   323,    82,
     750,   432,   670,   107,  1397,  1679,  1720,   671,  1479,   323,
     323,   323,   323,  1721,    93,   755,   437,   756,   437,  1312,
     319,  1409,  1146,  1722,   999,  1194,  1144,  1771,  1096,   466,
    1211,  1212,  1524,  1148,  1342,  1343,   323,   898,  1656,   107,
     437,  1731,  1214,  1168,  1216,   437,  1169,   759,  1342,  1343,
     757,   470,   545,  -265,   672,   545,   698,   467,  1215,  1736,
    1217,   646,  1244,  1566,   464,   647,   128,   465,  1000,  1481,
     648,  1262,  1053,  1001,   319,   654,  1171,   758,   655,  1245,
     959,  1345,  1345,  1346,  1346,  1530,   699,  1397,  1686,   649,
     323,  1812,  1848,  1690,  1172,  1172,  1194,   654,   471,   700,
     655,   474,  1479,  1105,  1106,  1107,  1657,   886,  1412,  1399,
     475,  1347,  1347,  1413,  1342,  1343,  1612,  -265,  1129,  1480,
    1194,  1097,  -265,  1246,   702,  1356,   433,  1357,   468,  1344,
    1761,   469,  1414,   703,   747,   545,   701,   476,   545,   759,
     908,   432,   545,  1344,   725,   545,   545,  1138,  1053,  1412,
    1345,  1054,  1346,   545,  1413,   319,  1651,   606,  1465,   545,
     545,  1063,   607,  1481,  1345,   885,  1346,   545,   615,  -265,
    -266,   323,   473,  1415,   545,   545,   545,   545,   741,   726,
    1347,   727,   545,  1791,   114,  1792,   319,   319,   650,  1466,
     545,   651,  1054,  1221,  1347,   742,  1380,  1583,   114,   704,
     126,   482,   323,   323,   715,  1221,   652,   653,   654,  1344,
    1467,   655,   498,   705,   126,  1342,  1343,  1816,  1822,   743,
     730,  1273,   432,  1276,  1348,  1775,  1209,  1515,  1312,  1778,
    1345,   731,  1346,  1218,  -266,   656,   744,   545,  1551,  -266,
     695,  1529,   156,   499,   725,   319,   500,   654,  1833,   795,
     655,   695,   545,  1090,  1091,  1473,   156,   696,  1194,  1816,
    1347,   323,   459,   545,   114,  1822,   433,  1327,   696,  1328,
     913,   795,  1675,   319,   695,  1244,   898,  1451,  1452,   726,
     126,   727,  1396,   697,   657,   487,  -266,  1718,  1719,   323,
     869,   696,  1245,  1397,  1789,   869,  1715,   485,   545,   963,
    1453,   486,   963,  1398,  1556,   545,  1535,   963,  1538,  1265,
    1344,  1535,  1745,  1388,  1824,  1399,  1535,  1238,  1266,  1536,
    1799,  1539,   156,  1240,  1685,  1230,  1231,  1576,  1239,  1854,
     769,  1345,   490,  1346,  1241,   770,  1585,  1194,   943,   944,
    1194,  1000,  1233,  1234,  1235,  1412,  1001,   433,  1236,  1172,
    1413,   483,   912,   496,   484,  1513,   914,   654,  1172,   491,
     655,  1347,   545,   488,   720,   114,   489,   723,   497,  1172,
     761,   762,   763,  1361,   546,  1362,  1577,  1578,   437,   437,
     547,   126,   986,   987,   988,   989,   990,   991,   992,   993,
     994,   995,   549,   950,   951,  1485,  1486,  1787,  1788,   952,
     953,  1732,  1733,   550,   562,  1688,   563,   564,   583,   584,
     585,   561,  1528,   590,  1745,   545,   591,   592,   594,   597,
    -626,   608,   609,   156,   610,   612,   611,   613,   621,   625,
    1421,   645,   569,   674,   675,   582,   693,   694,   662,   706,
     707,   985,   708,   719,   545,   709,  1664,   586,   319,   589,
     739,   732,   713,   729,   733,   734,   735,   751,   545,   753,
     768,  1745,   545,   545,   323,   754,   764,   777,   795,   798,
    1831,  1568,   806,   807,   808,   826,   465,  1194,   809,  1572,
     820,   545,   827,   469,   484,   835,   489,   833,   500,   545,
     837,   676,   545,   840,   841,   849,   545,  1381,   857,   677,
     678,   459,   679,   842,   845,   843,   860,   319,   319,   319,
     680,   881,   859,  1382,   681,  1323,   682,   877,   882,   899,
     917,   683,   919,   323,   323,   323,   887,   918,   929,   941,
    1194,   920,  1194,  1873,   926,  1874,   954,   684,   955,   545,
    1172,   927,   956,   957,   974,  1882,   975,   981,   982,   984,
    1006,   614,  1007,  1010,  1033,  1011,  1036,  1032,  1034,  1041,
    1038,  1042,  1194,  1043,   685,   686,   687,   688,   689,   690,
    1044,  1045,  1051,  1060,  1066,  1067,  1070,   545,  1088,  1128,
    1130,  1077,  1078,  1079,  1080,  1085,   464,  1670,  1089,   468,
     483,   488,   499,  1135,  1146,  1194,  1136,  1143,  1153,  1206,
    1222,  1001,  1053,  1242,  1243,  1269,  1264,   545,  1272,  1194,
    1282,  1194,  1280,  1270,  1286,   791,  1294,  1295,  1296,   545,
    1297,  1667,  1301,  1668,  1300,  1302,  1672,  1673,  1307,  1311,
    1676,   924,   319,  1308,  1312,  1318,  1683,  1324,  1494,  1325,
     437,  1330,  1326,  1333,   545,   545,   545,   545,   323,  1331,
    1334,  1338,  1355,  1354,  1373,   757,   319,  1383,  1404,  1406,
    1411,  1408,  1425,  1444,  1445,    13,  1456,   319,  1477,  1457,
    1460,  1461,   323,  1520,  1448,  1462,  1463,  1469,  1478,  1483,
    1464,  1488,  1489,   323,  1493,  1492,   319,  1497,  1505,   545,
    1495,  1496,  1542,  1498,  1499,  1507,  1511,  1516,  1519,   432,
    1541,  1548,   323,   545,  1535,  1550,  1553,   319,  1560,  1564,
    1561,  1562,  1563,  1543,   319,  1544,  1569,  1565,  1559,  1588,
    1755,  1570,  1571,   323,  1386,  1397,  1589,  1590,   545,  1594,
     323,  1759,  1670,  1596,   432,  1762,  1615,   545,  1620,   545,
    1599,   545,  1770,   545,  1622,  1628,  1381,  1609,  1635,  1629,
     545,  1616,  1630,   432,  1641,  1631,  1648,  1632,  1633,  1650,
    1646,  1652,  1382,  1654,  1634,  1661,   748,  1662,  1659,   752,
    1663,  1644,  1708,   760,  1554,  1765,   766,   767,  1666,  1769,
    1684,  1558,  1689,   545,   775,   545,  1692,  1697,  1726,  1714,
     787,   790,  1728,  1727,  1737,  1729,  1742,  1244,   805,  1753,
    1750,  1749,  1760,  1777,  1786,   813,   814,   815,   818,  1793,
    1794,  1795,  1796,   824,  1797,  1801,  1802,  1807,  1809,  1826,
    1830,   831,   869,  1840,   433,  1823,  1825,  1839,  1762,  1847,
    1850,  1701,  1702,  1703,  1859,  1853,  1864,  1865,  1879,  1837,
    1876,  1875,  1857,  1878,   626,  1866,   627,   545,   630,  1008,
    1476,  1869,   738,  1225,  1871,  1491,  1881,  1293,  1804,   433,
    1835,  1712,  1142,  1808,   774,  1420,  1593,  1843,   832,  1586,
    1075,  1395,  1579,  1582,   834,   545,  1521,  1525,   433,  1531,
    1540,   942,  1205,   818,   965,  1513,   966,   931,   319,   977,
    1552,  1109,  1852,   712,   844,   569,  1849,   782,  1277,   437,
    1860,  1567,  1574,  1841,   323,   783,   437,  1846,  1573,  1725,
    1423,  1610,  1613,   545,  1614,  1724,  1447,  1484,  1643,  1249,
    1734,  1611,  1860,     0,   569,   873,     0,     0,     0,   880,
       0,  1843,  1381,     0,     0,   567,   790,     0,   885,  1862,
       0,     0,  1863,     0,     0,     0,     0,     0,  1382,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1872,  1783,     0,   545,     0,
       0,     0,   545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   545,     0,     0,     0,  1790,     0,
       0,     0,     0,   790,     0,     0,     0,     0,   545,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   545,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1381,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1381,  1381,     0,     0,   319,  1382,   545,     0,
       0,     0,     0,  1381,     0,     0,   968,     0,  1382,  1382,
       0,     0,   323,     0,     0,     0,     0,     0,     0,  1382,
       0,     0,     0,   545,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   545,     0,  1005,     0,   545,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1035,
       0,     0,     0,  1039,  1040,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   545,     0,     0,     0,     0,
       0,     0,  1059,     0,     0,     0,     0,     0,     0,     0,
    1065,     0,     0,  1068,     0,     0,     0,  1073,     0,  1381,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1382,   545,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,   319,     0,
    1108,     0,     0,     0,     0,     0,     0,     0,   545,     0,
       0,     0,     0,     0,   323,     0,  1381,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,  1382,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   323,     0,     0,
       0,     0,   545,  1381,     0,   545,     0,     0,   545,     0,
       0,     0,  1381,     0,     0,     0,     0,     0,  1152,  1382,
       0,   545,     0,     0,     0,     0,   545,     0,  1382,     0,
    1161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1200,  1200,  1204,  1204,   545,
     545,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1268,
       0,     0,     0,     0,     0,   545,     0,   545,  1275,   545,
    1275,   545,   790,     0,  1200,     0,     0,     0,   545,     0,
       0,  1200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   824,     0,   824,     0,   545,     0,
     545,     0,   861,   862,     0,   870,   871,   872,   874,     0,
     876,     0,     0,     0,     0,   883,   545,     0,     0,   545,
       0,     0,     0,     0,     0,   893,     0,     0,     0,     0,
     545,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   545,     0,     0,     0,     0,     0,   915,   916,     0,
       0,     0,     0,     0,     0,     0,   921,   922,  1405,     0,
     923,     0,     0,   545,   925,     0,     0,     0,     0,     0,
       0,   545,     0,     0,     0,     0,     0,   545,     0,   545,
       0,     0,     0,     0,     0,     0,  1200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     545,     0,     0,     0,     0,     0,     0,     0,     0,   545,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1200,     0,     0,     0,     0,   545,
       0,   972,     0,     0,   545,   972,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   545,     0,     0,   545,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1037,     0,     0,     0,     0,   790,
       0,     0,     0,  1503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   818,
       0,  1074,     0,     0,     0,     0,     0,     0,     0,  1200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1099,     0,     0,
       0,  1101,  1102,     0,  1104,     0,     0,     0,     0,  1555,
       0,   925,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   880,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1592,   916,     0,     0,
       0,     0,     0,  1154,  1158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1649,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1674,     0,     0,  1200,     0,     0,  1200,
    1267,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1687,     0,     0,     0,     0,  1691,     0,  1283,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1309,  1310,     0,     0,
    1710,  1711,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1329,     0,     0,  1332,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1358,  1359,  1360,     0,  1363,  1364,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,     0,     0,  1374,  1375,
       0,     0,     0,     0,     0,     0,     0,  1389,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1200,     0,  1764,     0,
    1766,     0,  1768,     0,     0,     0,     0,     0,     0,  1776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1472,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1200,
       0,  1200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1800,     0,     0,
    1803,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1810,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1504,     0,
    1506,     0,  1508,     0,  1200,     0,     0,     0,     0,     0,
    1514,     0,  1838,     0,     0,     0,     0,     0,  1200,  1518,
    1200,     0,     0,     0,     0,  1522,  1523,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1855,     0,     0,  1545,     0,     0,  1546,  1547,     0,
    1858,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1867,     0,     0,     0,     0,  1868,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1877,     0,     0,
    1880,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1154,     0,
       0,     0,  1158,  1587,     0,     0,     0,     0,  1591,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1653,     0,     0,     0,  1655,
       0,     0,     0,  1658,     0,  1660,     0,     0,     0,     0,
       0,     0,     0,  1665,     0,     0,     0,     0,     0,     0,
       0,  1669,  1671,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1693,  1694,  1695,  1696,     0,  1698,
    1699,     0,  1700,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1707,     0,     0,
       0,     0,  1709,     0,     0,     0,     0,     0,  1713,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1751,     0,
    1752,     0,     0,  1754,     0,     0,  1756,     0,     0,     0,
       0,  1758,  1671,     0,     0,     0,     0,     0,     0,     0,
    1763,     0,     0,     0,  1767,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1779,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1785,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1805,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1763,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1844,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -165,   903,     0,     0,     0,
       0,  1856,     0,     0,     0,  1861,     1,     2,     0,     0,
    1844,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,  1861,     0,    14,   428,
    1870,    16,    17,    18,    19,    20,    21,    22,    23,    24,
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
       0,     0,   132,   133,   134,     0,   135,   136,   137,   138,
     139,   140,     0,   141,     0,   142,     0,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     0,     0,
     154,   155,   156,     0,   157,   430,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,     0,   204,   205,   206,     0,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     0,   255,     0,   256,   257,   258,
     259,   260,   261,   262,  -165,   903,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   907,   428,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   429,    30,    31,    32,    33,    34,     0,
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
       0,   132,   133,   134,     0,   135,   136,   137,   138,   139,
     140,     0,   141,     0,   142,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,   154,
     155,   156,     0,   157,   430,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,   204,   205,   206,     0,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   903,   255,     0,   256,   257,   258,   259,
     260,   261,   262,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,   427,   428,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   429,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,   137,   138,   139,   140,     0,
     141,     0,   142,     0,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,   154,   155,   156,
       0,   157,   430,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
     205,   206,     0,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   903,   255,     0,   256,   257,   258,   259,   260,   261,
     262,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   427,   428,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   570,   429,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   571,   572,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   518,    85,    86,    87,    88,    89,   573,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   574,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   133,   134,
       0,   135,   136,   137,     0,   139,   140,     0,   141,     0,
     142,     0,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,   154,   155,   156,     0,   157,
     430,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   536,   537,   538,   187,
     188,   539,   576,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,     0,   204,   205,   206,
       0,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
     255,     0,   256,   257,   258,   259,   260,   261,   262,  -886,
     470,     0,  -265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -886,     0,     0,     0,  -886,     0,     0,     0,  -886,
    -886,     0,     0,     0,     0,  -886,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -265,     0,     0,  -886,
       0,  -265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -886,     0,  -886,  -886,  -886,     0,     0,  -886,
    -886,  -886,  -886,     0,     0,     0,  -886,  -886,     0,     0,
       0,     0,     0,  -886,     0,     0,  -886,  -886,  -265,     0,
       0,     0,  -886,     0,     0,     0,     0,  -886,  -886,     0,
       0,     0,     0,  -886,     0,     0,     0,  -886,     0,     0,
       0,  -886,  -886,     0,  -886,     0,  -886,  -886,     0,     0,
       0,  -886,  -886,     0,     0,  -886,  -886,  -886,  -886,  -886,
    -886,     0,     0,  -886,     0,     0,     0,  -886,  -886,     0,
       0,  -886,     0,     0,     0,     0,  -886,     0,     0,  -886,
       0,     0,     0,     0,  -886,  -886,  -886,  -886,  -886,  -886,
    -886,  -886,     0,  -886,  -886,  -886,  -886,  -886,     0,     0,
       0,     0,  -886,  -886,  -886,     0,  -886,  -886,  -886,  -886,
    -886,  -886,     0,  -886,     0,  -886,     0,     0,     0,     0,
       0,  -886,     0,     0,     0,  -886,  -886,     0,  -887,   615,
       0,  -266,     0,     0,     0,     0,     0,     0,     0,     0,
    -886,     0,  -886,     0,  -886,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -886,     0,     0,     0,
       0,  -886,     0,     0,  -886,     0,     0,     0,     0,     0,
    -887,     0,     0,     0,  -887,     0,     0,     0,  -887,  -887,
       0,     0,     0,     0,  -887,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -266,     0,     0,  -887,     0,
    -266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -886,     0,
    -886,  -887,     0,  -887,  -887,  -887,     0,     0,  -887,  -887,
    -887,  -887,     0,     0,     0,  -887,  -887,     0,     0,     0,
       0,     0,  -887,     0,     0,  -887,  -887,  -266,     0,     0,
       0,  -887,     0,     0,     0,     0,  -887,  -887,     0,     0,
       0,     0,  -887,     0,     0,     0,  -887,     0,     0,     0,
    -887,  -887,     0,  -887,     0,  -887,  -887,     0,     0,     0,
    -887,  -887,     0,     0,  -887,  -887,  -887,  -887,  -887,  -887,
       0,     0,  -887,     0,     0,     0,  -887,  -887,     0,     0,
    -887,     0,     0,     0,     0,  -887,     0,     0,  -887,     0,
       0,     0,     0,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,     0,  -887,  -887,  -887,  -887,  -887,     0,     0,     0,
       0,  -887,  -887,  -887,     0,  -887,  -887,  -887,  -887,  -887,
    -887,     0,  -887,     0,  -887,     0,     0,     0,     0,     0,
    -887,     0,     0,     0,  -887,  -887,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -887,
       0,  -887,     0,  -887,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -887,     0,     0,     0,     0,
    -887,     0,     0,  -887,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,  -887,    13,  -887,
       0,    14,    15,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,   137,   138,   139,   140,     0,   141,     0,   142,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   154,   155,   156,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,     0,
     256,   257,   258,   259,   260,   261,   262,   263,   264,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,    14,    15,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,   137,   138,   139,   140,     0,   141,     0,   142,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   154,   155,   156,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,     0,
     256,   257,   258,   259,   260,   261,   262,     0,   622,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   427,   428,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   429,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,   836,     0,   132,   133,   134,     0,   135,
     136,   137,   138,   139,   140,     0,   141,     0,   142,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   154,   155,   156,     0,   157,   430,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,     0,
     256,   257,   258,   259,   260,   261,   262,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   427,
     428,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   429,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,   137,
     138,   139,   140,     0,   141,     0,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,   154,   155,   156,     0,   157,   430,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,     0,   204,   205,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,   255,     0,   256,   257,
     258,   259,   260,   261,   262,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,    14,    15,     0,
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
       0,   132,   133,   134,     0,   135,   136,   137,   138,   139,
     140,     0,   141,     0,   142,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,   154,
     155,   156,     0,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,   204,   205,   206,     0,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,   255,     0,   256,   257,   258,   259,
     260,   261,   262,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,    14,    15,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,   137,   138,   139,   140,     0,
     141,     0,   142,     0,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,   154,   155,   156,
       0,   157,   430,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
     205,   206,     0,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,   255,     0,   256,   257,   258,   259,   260,   261,
     262,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,    14,   428,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   133,   134,
       0,   135,   136,   137,   138,   139,   140,     0,   141,     0,
     142,     0,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,   154,   155,   156,     0,   157,
     430,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,     0,   204,   205,   206,
       0,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
     255,     0,   256,   257,   258,   259,   260,   261,   262,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,     0,
       0,   907,   428,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   429,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,   137,   138,   139,   140,     0,   141,     0,   142,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   154,   155,   156,     0,   157,   430,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,     0,
     256,   257,   258,   259,   260,   261,   262,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   427,
     428,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,  1376,   429,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,  1377,
    1378,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,   137,
     138,   139,   140,     0,   141,     0,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,   154,   155,   156,     0,   157,   430,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,  1379,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,     0,   204,   205,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,   255,     0,   256,   257,
     258,   259,   260,   261,   262,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   427,   428,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   570,   429,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   571,   572,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   518,    85,    86,
      87,    88,    89,   573,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     970,     0,   104,   105,   106,   107,   108,   109,   110,   574,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   133,   134,   971,   135,   136,   137,     0,   139,
     140,     0,   141,     0,   142,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,   154,
     155,   156,     0,   157,   430,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     536,   537,   538,   187,   188,   539,   576,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,   204,   205,   206,     0,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,   255,     0,   256,   257,   258,   259,
     260,   261,   262,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   427,   428,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     570,   429,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,   571,   572,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   518,    85,    86,    87,    88,
      89,   573,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   970,     0,
     104,   105,   106,   107,   108,   109,   110,   574,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,   976,   135,   136,   137,     0,   139,   140,     0,
     141,     0,   142,     0,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,   154,   155,   156,
       0,   157,   430,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   536,   537,
     538,   187,   188,   539,   576,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
     205,   206,     0,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,   255,     0,   256,   257,   258,   259,   260,   261,
     262,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   427,   428,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   570,   429,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   571,   572,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   518,    85,    86,    87,    88,    89,   573,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   574,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,   575,   132,   133,   134,
       0,   135,   136,   137,     0,   139,   140,     0,   141,     0,
     142,     0,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,   154,   155,   156,     0,   157,
     430,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   536,   537,   538,   187,
     188,   539,   576,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,     0,   204,   205,   206,
       0,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
     255,     0,   256,   257,   258,   259,   260,   261,   262,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   427,   428,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   570,   429,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   571,   572,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   518,    85,    86,    87,    88,    89,   573,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   574,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,   580,   135,
     136,   137,     0,   139,   140,     0,   141,     0,   142,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   154,   155,   156,     0,   157,   430,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   536,   537,   538,   187,   188,   539,
     576,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,     0,
     256,   257,   258,   259,   260,   261,   262,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   427,
     428,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   570,   429,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   571,
     572,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   518,
      85,    86,    87,    88,    89,   573,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   574,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,   137,
       0,   139,   140,     0,   141,     0,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,   154,   155,   156,     0,   157,   430,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   536,   537,   538,   187,   188,   539,   576,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,     0,   204,   205,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   617,   255,     0,   256,   257,
     258,   259,   260,   261,   262,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   427,   428,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   570,   429,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   571,   572,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   518,    85,    86,
      87,    88,    89,   573,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   574,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   133,   134,     0,   135,   136,   137,     0,   139,
     140,     0,   141,     0,   142,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,   154,
     155,   156,     0,   157,   430,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     536,   537,   538,   187,   188,   539,   576,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,   204,   205,   206,     0,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,   255,   619,   256,   257,   258,   259,
     260,   261,   262,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   427,   428,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     570,   429,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,   571,   572,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   518,    85,    86,    87,    88,
      89,   573,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   574,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,   969,   132,
     133,   134,     0,   135,   136,   137,     0,   139,   140,     0,
     141,     0,   142,     0,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,   154,   155,   156,
       0,   157,   430,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   536,   537,
     538,   187,   188,   539,   576,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,   204,
     205,   206,     0,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,   255,     0,   256,   257,   258,   259,   260,   261,
     262,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   427,   428,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   570,   429,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   571,   572,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   518,    85,    86,    87,    88,    89,   573,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   574,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   133,   134,
    1208,   135,   136,   137,     0,   139,   140,     0,   141,     0,
     142,     0,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,   154,   155,   156,     0,   157,
     430,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   536,   537,   538,   187,
     188,   539,   576,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,     0,   204,   205,   206,
       0,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
     255,     0,   256,   257,   258,   259,   260,   261,   262,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   427,   428,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   570,   429,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   571,   572,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   518,    85,    86,    87,    88,    89,   573,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,  1471,     0,   104,   105,   106,   107,
     108,   109,   110,   574,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,   137,     0,   139,   140,     0,   141,     0,   142,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   154,   155,   156,     0,   157,   430,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   536,   537,   538,   187,   188,   539,
     576,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,     0,
     256,   257,   258,   259,   260,   261,   262,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   427,
     428,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   504,    27,   506,   429,    30,   507,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   509,     0,    48,    49,    50,   511,
     512,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   518,
      85,    86,    87,    88,    89,   573,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   521,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   574,   112,     0,   113,   114,   710,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   711,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,   137,
       0,   139,   140,     0,   141,     0,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,   154,   155,   156,     0,   157,   430,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   531,   171,
     532,   173,   533,   534,   176,   177,   178,   179,   180,   181,
     535,   183,   536,   537,   538,   187,   188,   539,   540,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   541,     0,   204,   542,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,   255,     0,   256,   543,
     258,   259,   260,   261,   262,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   427,   428,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   570,   429,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   571,   572,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   518,    85,    86,
      87,    88,    89,   573,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   574,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   133,   134,     0,   135,   136,   137,     0,   139,
     140,     0,   141,     0,   142,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,   154,
     155,   156,     0,   157,   430,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     536,   537,   538,   187,   188,   539,   576,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,   204,   205,   206,     0,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,   255,     0,   256,   257,   258,   259,
     260,   261,   262,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   427,   428,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   504,    27,
     506,   429,    30,   507,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
     509,     0,    48,    49,    50,   511,   512,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   518,    85,    86,    87,    88,
      89,   573,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   521,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   574,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,   137,     0,   139,   140,     0,
     141,     0,   142,     0,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,   154,   155,   156,
       0,   157,   430,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   531,   171,   532,   173,   533,   534,
     176,   177,   178,   179,   180,   181,   535,   183,   536,   537,
     538,   187,   188,   539,   540,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   541,     0,   204,
     205,   206,     0,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,   255,     0,   256,   543,   258,   259,   260,   261,
     262,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   427,   428,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   504,    27,   506,   429,
      30,   507,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   509,     0,
      48,    49,    50,   511,   512,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   518,    85,    86,    87,    88,    89,   573,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   521,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   574,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   133,   134,
       0,   135,   136,   137,     0,   139,   140,     0,   141,     0,
     142,     0,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,     0,   154,   155,   156,     0,   157,
     430,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   531,   171,   532,   173,   533,   534,   176,   177,
     178,   179,   180,   181,   535,   183,   536,   537,   538,   187,
     188,   539,   540,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   541,     0,   204,   542,   206,
       0,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
     255,     0,   256,   543,   258,   259,   260,   261,   262,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   427,   428,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   570,   429,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   571,   572,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   518,    85,    86,    87,    88,    89,  1157,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   574,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,   137,     0,   139,   140,     0,   141,     0,   142,     0,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   154,   155,   156,     0,   157,   430,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   536,   537,   538,   187,   188,   539,
     576,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,   204,   205,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     0,   255,     0,
     256,   257,   258,   259,   260,   261,   262,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   427,
     428,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   504,    27,   506,   429,    30,   507,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   509,     0,    48,    49,    50,   511,
     512,    53,   513,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   518,
      85,    86,    87,    88,    89,   573,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   521,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   574,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,   137,
       0,   139,   140,     0,   141,     0,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,   154,   155,   156,     0,   157,   430,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   531,   171,
     532,   173,   533,   534,   176,   177,   178,   179,   180,   181,
     535,   183,   536,   537,   538,   187,   188,   539,   540,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   541,     0,   204,   542,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     0,   255,     0,   256,   543,
     258,   259,   260,   261,   262,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   427,   428,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     504,    27,   506,   429,    30,   507,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   509,     0,    48,    49,    50,   511,   512,    53,
     513,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   518,    85,    86,
      87,    88,    89,   573,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   521,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   574,
     112,     0,   113,   114,     0,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   133,   134,     0,   135,   136,   137,     0,     0,
       0,     0,   141,     0,   142,     0,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,   154,
     155,   156,     0,   157,   430,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   531,   171,   532,   173,
     533,   534,   176,   177,   178,   179,   180,   181,   535,   183,
     536,   537,   538,   187,   188,   539,   540,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   541,
       0,   204,   542,   206,     0,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,     0,   255,     0,   256,   543,   258,   259,
     260,   261,   262,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   427,   428,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   504,    27,
     506,   429,    30,   507,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
     509,     0,    48,    49,    50,   511,   512,    53,   513,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   518,    85,    86,    87,    88,
      89,   573,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   521,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,     0,   109,   110,   574,   112,     0,
     113,   114,     0,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,     0,
       0,     0,     0,   129,   130,   131,     0,     0,     0,   132,
     133,   134,     0,   135,   136,   137,     0,     0,     0,     0,
     141,     0,   142,     0,   143,     0,   145,     0,   147,   148,
     149,   150,   151,   152,   153,     0,     0,   154,   155,   156,
       0,   157,   430,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   531,   171,   532,   173,   533,   534,
     176,   177,   178,   179,   180,   181,   535,   183,   536,   537,
     538,   187,   188,   539,   540,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   541,     0,   204,
     542,   206,     0,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,   255,     0,   256,   543,   258,   259,   260,   261,
     262,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   427,   428,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   504,    27,   506,   429,
      30,   507,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   509,     0,
      48,    49,    50,   511,   512,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   518,    85,    86,    87,    88,     0,   573,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   521,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,     0,   109,   110,   574,     0,     0,     0,   114,
       0,     0,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   133,   134,
       0,   135,   136,   137,     0,     0,     0,     0,     0,     0,
     142,     0,   143,     0,   145,     0,   147,   148,   149,   150,
     151,   152,   153,     0,     0,   154,   155,   156,     0,   157,
     430,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   531,   171,   532,   173,   533,   534,   176,   177,
     178,   179,   180,   181,   535,   183,   536,   537,   538,   187,
     188,   539,   540,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   541,     0,   204,   205,   206,
       0,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     0,
     255,     0,   256,   543,   258,   259,   260,   261,   262,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     0,
       0,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,   427,   428,     0,    16,    17,    18,   501,    20,    21,
      22,   502,    24,   503,   504,   505,   506,   429,    30,   507,
      32,    33,    34,     0,    35,    36,    37,    38,   508,    40,
      41,    42,    43,    44,    45,    46,   509,     0,    48,   510,
      50,   511,   512,    53,   513,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   514,
     515,    71,     0,    72,    73,    74,   516,     0,     0,    77,
      78,    79,     0,     0,   517,    81,     0,     0,     0,     0,
      83,   518,    85,   519,   520,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   521,   100,   101,   522,   523,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     524,     0,     0,     0,   118,   119,   120,   121,   525,   123,
     124,   526,     0,     0,     0,     0,     0,     0,     0,   527,
     528,   131,     0,     0,     0,   132,   133,   134,     0,   135,
     136,   529,     0,     0,     0,     0,   141,     0,   142,     0,
     143,   144,   145,   146,   530,   148,   149,   150,   151,   152,
     153,     0,     0,   154,   155,     0,     0,   157,   430,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     531,   171,   532,   173,   533,   534,   176,   177,   178,   179,
     180,   181,   535,   183,   536,   537,   538,   187,   188,   539,
     540,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   541,     0,   204,   542,   206,     0,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
     256,   543,   258,   259,   260,   261,   262,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     0,     0,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,   427,
     428,     0,    16,    17,    18,   551,    20,    21,    22,   502,
     552,   553,   504,   505,   506,   429,    30,   507,    32,   554,
      34,     0,    35,    36,    37,    38,   555,    40,   556,   557,
      43,    44,    45,    46,   509,     0,    48,   558,    50,   511,
     512,    53,   513,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   514,   515,    71,
       0,    72,    73,    74,   559,     0,     0,    77,    78,    79,
       0,     0,   517,    81,     0,     0,     0,     0,    83,   518,
      85,   519,   520,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   521,   100,   101,   522,   523,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   524,     0,
       0,     0,   118,   119,   120,   121,   525,   123,   124,   526,
       0,     0,     0,     0,     0,     0,     0,   527,   528,   131,
       0,     0,     0,   132,   133,   134,     0,   135,   136,   529,
       0,     0,     0,     0,   141,     0,   142,     0,   143,   144,
     145,   146,   530,   148,   149,   150,   151,   152,   153,     0,
       0,   154,   155,     0,     0,   157,   430,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   531,   560,
     532,   173,   533,   534,   176,   177,   178,   179,   180,   181,
     535,   183,   536,   537,   538,   187,   188,   539,   540,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   541,     0,   204,   542,   206,     0,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,     0,     0,     3,     0,   256,   543,
     258,   259,   260,   261,   262,     9,    10,     0,     0,     0,
      13,     0,     0,   427,   428,     0,    16,    17,    18,   551,
      20,    21,    22,   502,   552,   553,   504,   505,   506,   429,
      30,   507,    32,   554,    34,     0,    35,    36,    37,    38,
     555,    40,   556,   557,    43,    44,    45,    46,   509,     0,
      48,   558,    50,   511,   512,    53,   513,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   514,   515,    71,     0,    72,    73,    74,   559,     0,
       0,    77,    78,    79,     0,     0,   517,    81,     0,     0,
       0,     0,    83,   518,    85,   519,   520,    88,    89,   573,
      91,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   521,   100,   101,
     522,   523,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,   110,     0,     0,     0,   964,     0,
       0,   116,   524,     0,     0,     0,   118,   119,   120,   121,
     525,   123,   124,   526,     0,     0,     0,     0,     0,     0,
       0,   527,   528,   131,     0,     0,     0,   132,   133,   134,
       0,   135,   136,   529,     0,     0,     0,     0,     0,     0,
     142,     0,   143,   144,   145,   146,   530,   148,   149,   150,
     151,   152,   153,     0,     0,   154,   155,     0,     0,   157,
     430,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   531,   560,   532,   173,   533,   534,   176,   177,
     178,   179,   180,   181,   535,   183,   536,   537,   538,   187,
     188,   539,   540,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   541,     0,   204,   542,   206,
       0,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       3,     0,   256,   543,   258,   259,   260,   261,   262,     9,
      10,     0,     0,     0,     0,     0,     0,   427,   428,     0,
      16,    17,    18,   501,    20,    21,    22,   502,    24,   503,
     504,  1183,   506,   429,    30,   507,    32,    33,    34,     0,
      35,    36,    37,    38,   508,    40,    41,    42,    43,    44,
      45,    46,   509,     0,    48,   510,    50,   511,   512,    53,
     513,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   514,   515,    71,     0,    72,
      73,    74,   516,     0,     0,    77,    78,    79,     0,     0,
     517,    81,     0,     0,     0,     0,    83,   518,    85,   519,
     520,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   521,   100,   101,   522,   523,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,  1184,     0,
       0,     0,  1185,     0,     0,   116,   524,     0,     0,     0,
     118,   119,   120,   121,   525,   123,   124,   526,     0,     0,
       0,     0,     0,     0,     0,   527,   528,   131,     0,     0,
       0,   132,   133,   134,  1624,   135,   136,   529,     0,     0,
       0,     0,  1625,     0,   142,     0,   143,   144,   145,   146,
     530,   148,   149,   150,   151,   152,   153,     0,     0,  1186,
     155,     0,     0,   157,   430,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   531,   171,   532,   173,
     533,   534,   176,   177,   178,   179,   180,   181,   535,   183,
     536,   537,   538,   187,   188,   539,   540,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   541,
       0,   204,   542,   206,     0,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,   256,   543,   258,  1187,
    1188,  1189,  1190,     3,     0,   587,   588,     0,     0,     0,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
     427,   428,     0,    16,    17,    18,   551,    20,    21,    22,
     502,   552,   553,   504,   505,   506,   429,    30,   507,    32,
     554,    34,     0,    35,    36,    37,    38,   555,    40,   556,
     557,    43,    44,    45,    46,   509,     0,    48,   558,    50,
     511,   512,    53,   513,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   514,   515,
      71,     0,    72,    73,    74,   559,     0,     0,    77,    78,
      79,     0,     0,   517,    81,     0,     0,     0,     0,    83,
     518,    85,   519,   520,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   521,   100,   101,   522,   523,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   524,
       0,     0,     0,   118,   119,   120,   121,   525,   123,   124,
     526,     0,     0,     0,     0,     0,     0,     0,   527,   528,
     131,     0,     0,     0,   132,   133,   134,     0,   135,   136,
     529,     0,     0,     0,     0,     0,     0,   142,     0,   143,
     144,   145,   146,   530,   148,   149,   150,   151,   152,   153,
       0,     0,   154,   155,     0,     0,   157,   430,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   531,
     560,   532,   173,   533,   534,   176,   177,   178,   179,   180,
     181,   535,   183,   536,   537,   538,   187,   188,   539,   540,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   541,     0,   204,   542,   206,     0,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     3,     0,   256,
     543,   258,   259,   260,   261,   262,     9,    10,     0,     0,
       0,     0,     0,     0,   427,   428,     0,    16,    17,    18,
     551,    20,    21,    22,   502,   552,   553,   504,   505,   506,
     429,    30,   507,    32,   554,    34,     0,    35,    36,    37,
      38,   555,    40,   556,   557,    43,    44,    45,    46,   509,
       0,    48,   558,    50,   511,   512,    53,   513,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   514,   515,    71,     0,    72,    73,    74,   559,
       0,     0,    77,    78,    79,     0,     0,   517,    81,     0,
       0,     0,     0,    83,   518,    85,   519,   520,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   521,   100,
     101,   522,   523,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   524,     0,     0,     0,   118,   119,   120,
     121,   525,   123,   124,   526,     0,     0,     0,     0,     0,
       0,     0,   527,   528,   131,     0,     0,     0,   132,   133,
     134,   785,   135,   136,   529,     0,     0,     0,     0,   786,
       0,   142,     0,   143,   144,   145,   146,   530,   148,   149,
     150,   151,   152,   153,     0,     0,   154,   155,     0,     0,
     157,   430,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   531,   560,   532,   173,   533,   534,   176,
     177,   178,   179,   180,   181,   535,   183,   536,   537,   538,
     187,   188,   539,   540,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   541,     0,   204,   542,
     206,     0,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,     3,     0,   256,   543,   258,   259,   260,   261,   262,
       9,    10,     0,     0,     0,   811,     0,     0,   427,   428,
       0,    16,    17,    18,   551,    20,    21,    22,   502,   552,
     553,   504,   505,   506,   429,    30,   507,    32,   554,    34,
       0,    35,    36,    37,    38,   555,    40,   556,   557,    43,
      44,    45,    46,   509,     0,    48,   558,    50,   511,   512,
      53,   513,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   514,   515,    71,     0,
      72,    73,    74,   559,     0,     0,    77,    78,    79,     0,
       0,   517,    81,     0,     0,     0,     0,    83,   518,    85,
     519,   520,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   521,   100,   101,   522,   523,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   524,     0,     0,
       0,   118,   119,   120,   121,   525,   123,   124,   526,     0,
       0,     0,     0,     0,     0,     0,   527,   528,   131,     0,
       0,     0,   132,   133,   134,   812,   135,   136,   529,     0,
       0,     0,     0,     0,     0,   142,     0,   143,   144,   145,
     146,   530,   148,   149,   150,   151,   152,   153,     0,     0,
     154,   155,     0,     0,   157,   430,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   531,   560,   532,
     173,   533,   534,   176,   177,   178,   179,   180,   181,   535,
     183,   536,   537,   538,   187,   188,   539,   540,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     541,     0,   204,   542,   206,     0,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,     0,     3,     0,   256,   543,   258,
     259,   260,   261,   262,     9,    10,     0,     0,     0,     0,
       0,     0,   427,   428,     0,    16,    17,    18,   551,    20,
      21,    22,   502,   552,   553,   504,   505,   506,   429,    30,
     507,    32,   554,    34,     0,    35,    36,    37,    38,   555,
      40,   556,   557,    43,    44,    45,    46,   509,     0,    48,
     558,    50,   511,   512,    53,   513,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     514,   515,    71,     0,    72,    73,    74,   559,     0,     0,
      77,    78,    79,     0,     0,   517,    81,     0,     0,     0,
       0,    83,   518,    85,   519,   520,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   521,   100,   101,   522,
     523,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   524,     0,     0,     0,   118,   119,   120,   121,   525,
     123,   124,   526,     0,     0,     0,     0,     0,     0,     0,
     527,   528,   131,     0,     0,     0,   132,   133,   134,   829,
     135,   136,   529,     0,     0,     0,     0,   830,     0,   142,
       0,   143,   144,   145,   146,   530,   148,   149,   150,   151,
     152,   153,     0,     0,   154,   155,     0,     0,   157,   430,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   531,   560,   532,   173,   533,   534,   176,   177,   178,
     179,   180,   181,   535,   183,   536,   537,   538,   187,   188,
     539,   540,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   541,     0,   204,   542,   206,     0,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     3,
       0,   256,   543,   258,   259,   260,   261,   262,     9,    10,
       0,     0,     0,     0,     0,     0,   427,   428,     0,    16,
      17,    18,   501,    20,    21,    22,   502,    24,   503,   504,
    1183,   506,   429,    30,   507,    32,    33,    34,     0,    35,
      36,    37,    38,   508,    40,    41,    42,    43,    44,    45,
      46,   509,     0,    48,   510,    50,   511,   512,    53,   513,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   514,   515,    71,     0,    72,    73,
      74,   516,     0,     0,    77,    78,    79,     0,     0,   517,
      81,     0,     0,     0,     0,    83,   518,    85,   519,   520,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     521,   100,   101,   522,   523,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1184,     0,     0,
       0,  1223,     0,     0,   116,   524,     0,     0,     0,   118,
     119,   120,   121,   525,   123,   124,   526,     0,     0,     0,
       0,     0,     0,     0,   527,   528,   131,     0,     0,     0,
     132,   133,   134,  1458,   135,   136,   529,     0,     0,     0,
       0,     0,     0,   142,     0,   143,   144,   145,   146,   530,
     148,   149,   150,   151,   152,   153,     0,     0,   154,   155,
       0,     0,   157,   430,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   531,   171,   532,   173,   533,
     534,   176,   177,   178,   179,   180,   181,   535,   183,   536,
     537,   538,   187,   188,   539,   540,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   541,     0,
     204,   542,   206,     0,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     0,     0,     3,     0,   256,   543,   258,  1187,  1188,
    1189,  1190,     9,    10,     0,     0,     0,     0,     0,     0,
     427,   428,     0,    16,    17,    18,   501,    20,    21,    22,
     502,    24,   503,   504,  1183,   506,   429,    30,   507,    32,
      33,    34,     0,    35,    36,    37,    38,   508,    40,    41,
      42,    43,    44,    45,    46,   509,     0,    48,   510,    50,
     511,   512,    53,   513,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   514,   515,
      71,     0,    72,    73,    74,   516,     0,     0,    77,    78,
      79,     0,     0,   517,    81,     0,     0,     0,     0,    83,
     518,    85,   519,   520,    88,    89,  1532,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   521,   100,   101,   522,   523,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1184,     0,     0,     0,  1185,     0,     0,   116,   524,
       0,     0,     0,   118,   119,   120,   121,   525,   123,   124,
     526,     0,     0,     0,     0,     0,     0,     0,   527,   528,
     131,     0,     0,     0,   132,   133,   134,     0,   135,   136,
     529,     0,     0,     0,     0,     0,     0,   142,     0,   143,
     144,   145,   146,   530,   148,   149,   150,   151,   152,   153,
       0,     0,  1186,   155,     0,     0,   157,   430,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   531,
     171,   532,   173,   533,   534,   176,   177,   178,   179,   180,
     181,   535,   183,   536,   537,   538,   187,   188,   539,   540,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   541,     0,   204,   542,   206,     0,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     3,     0,   256,
     543,   258,  1187,  1188,  1189,  1190,     9,    10,     0,     0,
       0,     0,     0,     0,   427,   428,     0,    16,    17,    18,
     501,    20,    21,    22,   502,    24,   503,   504,  1183,   506,
     429,    30,   507,    32,    33,    34,     0,    35,    36,    37,
      38,   508,    40,    41,    42,    43,    44,    45,    46,   509,
       0,    48,   510,    50,   511,   512,    53,   513,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   514,   515,    71,     0,    72,    73,    74,   516,
       0,     0,    77,    78,    79,     0,     0,   517,    81,     0,
       0,     0,     0,    83,   518,    85,   519,   520,    88,    89,
    1677,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   521,   100,
     101,   522,   523,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1184,     0,     0,     0,  1185,
       0,     0,   116,   524,     0,     0,     0,   118,   119,   120,
     121,   525,   123,   124,   526,     0,     0,     0,     0,     0,
       0,     0,   527,   528,   131,     0,     0,     0,   132,   133,
     134,     0,   135,   136,   529,     0,     0,     0,     0,     0,
       0,   142,     0,   143,   144,   145,   146,   530,   148,   149,
     150,   151,   152,   153,     0,     0,  1186,   155,     0,     0,
     157,   430,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   531,   171,   532,   173,   533,   534,   176,
     177,   178,   179,   180,   181,   535,   183,   536,   537,   538,
     187,   188,   539,   540,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   541,     0,   204,   542,
     206,     0,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,     3,     0,   256,   543,   258,  1187,  1188,  1189,  1190,
       9,    10,     0,     0,     0,     0,     0,     0,   427,   428,
       0,    16,    17,    18,   501,    20,    21,    22,   502,    24,
     503,   504,  1183,   506,   429,    30,   507,    32,    33,    34,
       0,    35,    36,    37,    38,   508,    40,    41,    42,    43,
      44,    45,    46,   509,     0,    48,   510,    50,   511,   512,
      53,   513,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   514,   515,    71,     0,
      72,    73,    74,   516,     0,     0,    77,    78,    79,     0,
       0,   517,    81,     0,     0,     0,     0,    83,   518,    85,
     519,   520,    88,    89,  1681,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   521,   100,   101,   522,   523,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1184,
       0,     0,     0,  1185,     0,     0,   116,   524,     0,     0,
       0,   118,   119,   120,   121,   525,   123,   124,   526,     0,
       0,     0,     0,     0,     0,     0,   527,   528,   131,     0,
       0,     0,   132,   133,   134,     0,   135,   136,   529,     0,
       0,     0,     0,     0,     0,   142,     0,   143,   144,   145,
     146,   530,   148,   149,   150,   151,   152,   153,     0,     0,
    1186,   155,     0,     0,   157,   430,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   531,   171,   532,
     173,   533,   534,   176,   177,   178,   179,   180,   181,   535,
     183,   536,   537,   538,   187,   188,   539,   540,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     541,     0,   204,   542,   206,     0,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,     0,     3,     0,   256,   543,   258,
    1187,  1188,  1189,  1190,     9,    10,     0,     0,     0,     0,
       0,     0,   427,   428,     0,    16,    17,    18,   501,    20,
      21,    22,   502,    24,   503,   504,  1183,   506,   429,    30,
     507,    32,    33,    34,     0,    35,    36,    37,    38,   508,
      40,    41,    42,    43,    44,    45,    46,   509,     0,    48,
     510,    50,   511,   512,    53,   513,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     514,   515,    71,     0,    72,    73,    74,   516,     0,     0,
      77,    78,    79,     0,     0,   517,    81,     0,     0,     0,
       0,    83,   518,    85,   519,   520,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   521,   100,   101,   522,
     523,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,  1184,     0,     0,     0,  1185,     0,     0,
     116,   524,     0,     0,     0,   118,   119,   120,   121,   525,
     123,   124,   526,     0,     0,     0,     0,     0,     0,     0,
     527,   528,   131,     0,     0,     0,   132,   133,   134,     0,
     135,   136,   529,     0,     0,     0,     0,     0,     0,   142,
       0,   143,   144,   145,   146,   530,   148,   149,   150,   151,
     152,   153,     0,     0,  1186,   155,     0,     0,   157,   430,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   531,   171,   532,   173,   533,   534,   176,   177,   178,
     179,   180,   181,   535,   183,   536,   537,   538,   187,   188,
     539,   540,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   541,     0,   204,   542,   206,     0,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     3,
       0,   256,   543,   258,  1187,  1188,  1189,  1190,     9,    10,
       0,     0,     0,     0,     0,     0,   427,   428,     0,    16,
      17,    18,   501,    20,    21,    22,   502,    24,   503,   504,
    1183,   506,   429,    30,   507,    32,    33,    34,     0,    35,
      36,    37,    38,   508,    40,    41,    42,    43,    44,    45,
      46,   509,     0,    48,   510,    50,   511,   512,    53,   513,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   514,   515,    71,     0,    72,    73,
      74,   516,     0,     0,    77,    78,    79,     0,     0,   517,
      81,     0,     0,     0,     0,    83,   518,    85,   519,   520,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     521,   100,   101,   522,   523,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1184,     0,     0,
       0,  1223,     0,     0,   116,   524,     0,     0,     0,   118,
     119,   120,   121,   525,   123,   124,   526,     0,     0,     0,
       0,     0,     0,     0,   527,   528,   131,     0,     0,     0,
     132,   133,   134,     0,   135,   136,   529,     0,     0,     0,
       0,     0,     0,   142,     0,   143,   144,   145,   146,   530,
     148,   149,   150,   151,   152,   153,     0,     0,   154,   155,
       0,     0,   157,   430,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   531,   171,   532,   173,   533,
     534,   176,   177,   178,   179,   180,   181,   535,   183,   536,
     537,   538,   187,   188,   539,   540,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   541,     0,
     204,   542,   206,     0,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     0,     0,     3,     0,   256,   543,   258,  1187,  1188,
    1189,  1190,     9,    10,     0,     0,     0,     0,     0,     0,
     427,   428,     0,    16,    17,    18,   551,    20,    21,    22,
     502,   552,   553,   504,   505,   506,   429,    30,   507,    32,
     554,    34,     0,    35,    36,    37,    38,   555,    40,   556,
     557,    43,    44,    45,    46,   509,     0,    48,   558,    50,
     511,   512,    53,   513,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   514,   515,
      71,     0,    72,    73,    74,   559,     0,     0,    77,    78,
      79,     0,     0,   517,    81,     0,     0,     0,     0,    83,
     518,    85,   519,   520,    88,    89,  1278,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   521,   100,   101,   522,   523,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   524,
       0,     0,     0,   118,   119,   120,   121,   525,   123,   124,
     526,     0,     0,     0,     0,     0,     0,     0,   527,   528,
     131,     0,     0,     0,   132,   133,   134,     0,   135,   136,
     529,     0,     0,     0,     0,     0,     0,   142,     0,   143,
     144,   145,   146,   530,   148,   149,   150,   151,   152,   153,
       0,     0,   154,   155,     0,     0,   157,   430,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   531,
     560,   532,   173,   533,   534,   176,   177,   178,   179,   180,
     181,   535,   183,   536,   537,   538,   187,   188,   539,   540,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   541,     0,   204,   542,   206,     0,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     3,     0,   256,
     543,   258,   259,   260,   261,   262,     9,    10,     0,     0,
       0,     0,     0,     0,   427,   428,     0,    16,    17,    18,
     551,    20,    21,    22,   502,   552,   553,   504,   505,   506,
     429,    30,   507,    32,   554,    34,     0,    35,    36,    37,
      38,   555,    40,   556,   557,    43,    44,    45,    46,   509,
       0,    48,   558,    50,   511,   512,    53,   513,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   514,   515,    71,     0,    72,    73,    74,   559,
       0,     0,    77,    78,    79,     0,     0,   517,    81,     0,
       0,     0,     0,    83,   518,    85,   519,   520,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   521,   100,
     101,   522,   523,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   524,     0,     0,     0,   118,   119,   120,
     121,   525,   123,   124,   526,     0,     0,     0,     0,     0,
       0,     0,   527,   528,   131,     0,     0,     0,   132,   133,
     134,     0,   135,   136,   529,     0,     0,     0,     0,     0,
       0,   142,     0,   143,   144,   145,   146,   530,   148,   149,
     150,   151,   152,   153,     0,     0,   154,   155,     0,     0,
     157,   430,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   531,   560,   532,   173,   533,   534,   176,
     177,   178,   179,   180,   181,   535,   183,   536,   537,   538,
     187,   188,   539,   540,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   541,     0,   204,   542,
     206,     0,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,     0,     0,   256,   543,   258,   259,   260,   261,   262,
       5,     6,     7,     8,     9,    10,     0,     0,     0,    13,
       0,     0,   427,   428,     0,    16,    17,    18,   863,    20,
      21,    22,    23,     0,   864,   504,    27,     0,   429,    30,
     507,    32,     0,    34,     0,    35,    36,    37,    38,   865,
      40,     0,     0,    43,    44,    45,    46,   509,     0,    48,
     866,    50,     0,     0,    53,   513,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     514,   515,    71,     0,    72,    73,    74,   867,     0,     0,
      77,    78,    79,     0,     0,   517,    81,     0,     0,     0,
      82,    83,   518,    85,   519,   520,    88,    89,   573,    91,
       0,     0,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   521,   100,   101,   522,
     523,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,     0,   574,   112,     0,   113,   114,     0,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   526,     0,   126,     0,     0,     0,     0,     0,
     527,   528,   131,     0,     0,     0,   132,   133,   134,     0,
     135,   136,   529,     0,     0,     0,     0,     0,     0,   142,
       0,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,     0,   155,   156,     0,   157,   430,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   531,     0,   532,   173,   533,   534,   176,   177,   178,
     179,   180,   181,   535,   183,   536,   537,   538,   187,   188,
       0,   540,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   541,     0,   204,   542,   206,     0,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     0,   255,
       9,    10,   543,   258,     0,     0,     0,     0,   427,   428,
       0,    16,    17,    18,     0,    20,    21,    22,   502,     0,
       0,   504,   505,     0,   429,    30,   507,    32,     0,    34,
       0,    35,    36,    37,    38,     0,    40,     0,     0,    43,
      44,    45,    46,   509,     0,    48,     0,    50,     0,     0,
      53,   513,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   514,   515,    71,     0,
      72,    73,    74,     0,     0,     0,    77,    78,    79,     0,
       0,   517,    81,     0,     0,     0,     0,    83,   518,    85,
     519,   520,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   521,   100,   101,   522,   523,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,     0,
       0,     0,     0,     0,     0,     0,   116,   524,     0,     0,
       0,   118,   119,   120,   121,   525,   123,   124,   526,     0,
       0,     0,     0,     0,     0,     0,   527,   528,   131,     0,
       0,     0,   132,   133,   134,     0,   135,   136,   529,     0,
       0,     0,     0,     0,     0,   142,     0,   143,   144,   145,
     146,   530,   148,   149,   150,   151,   152,   153,     0,     0,
       0,   155,     0,     0,   157,   430,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   531,     0,   532,
     173,   533,   534,   176,   177,   178,   179,   180,   181,   535,
     183,   536,   537,   538,   187,   188,     0,   540,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     541,     0,   204,   542,   206,     0,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,     0,     0,     0,     0,   543,   258
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,   302,   190,   438,   439,     5,     6,     7,     8,    14,
     440,     5,     6,     7,   112,   113,     0,   713,   697,   323,
     805,     5,     6,     7,     8,   635,   636,   354,   850,   790,
    1086,   140,  1319,   818,  1337,   698,   699,   700,   701,   725,
     205,   270,   941,   271,  1070,   475,   476,   832,   600,   954,
     955,   790,   887,   605,  1401,  1402,   263,   264,   286,     1,
     323,  1112,     1,    76,   633,   634,    27,    28,    27,    28,
    1169,   747,     5,     6,     7,     8,    36,   633,   634,   635,
     636,  1051,  1535,   983,  1448,  1538,    47,   676,    47,   678,
     679,  1350,   681,  1033,   683,   119,    57,    31,    36,    97,
       1,     1,   691,   692,     8,     1,   999,     1,     1,    37,
      38,   111,    40,    41,    75,     1,    75,     1,     1,    80,
       1,     1,   108,     1,   144,    30,   123,   111,    94,     1,
      58,     1,   433,     1,     1,    95,   437,    97,   101,    56,
       1,   108,     1,   108,    39,  1707,   108,   132,  1053,    44,
      45,   112,   113,   114,   113,  1060,   254,   255,    53,    97,
     108,    97,     1,   233,     1,    60,   108,    62,    63,   108,
     138,    27,    28,   277,   119,     1,    71,   222,   111,   233,
     284,    37,    38,   155,    40,    41,   114,   293,     1,   149,
     294,    47,    33,   119,   195,   196,    33,     5,     6,     7,
       8,    57,    58,    98,   302,    97,   111,   108,    49,   233,
    1646,   149,    49,   149,   108,    30,   201,   262,   184,    75,
    1005,   126,   108,  1785,    80,   190,   189,   194,   190,   192,
     108,    55,  1579,    57,   162,    95,   108,   205,   108,     1,
     108,   108,   214,   191,   241,   190,   151,   108,   357,   108,
     155,     1,   322,   158,     1,   241,   112,   113,   114,    97,
    1316,   281,  1549,   263,   264,   566,   264,   267,   322,   108,
    1169,  1170,   176,   178,  1059,   579,  1302,   101,   170,   263,
     264,  1645,   108,   267,   218,   149,  1108,   897,   898,   190,
    1341,   315,  1185,  1552,   194,   108,   190,  1058,   194,  1350,
     228,   194,   302,   111,   190,   222,   162,  1760,  1278,   985,
     194,   194,   190,   194,   194,   185,   579,  1056,   302,  1058,
    1220,   281,   190,   190,   185,  1424,   895,   896,   758,  1269,
    1223,   190,   170,  1072,   295,   433,   295,   108,   233,   437,
      97,   269,   303,   281,   303,   262,   108,   162,   937,   362,
     311,   190,   365,   459,  1807,   281,  1809,   108,   108,   660,
    1796,   108,   267,     1,   190,     1,   226,   227,   260,   261,
     468,   263,   228,   803,     1,   473,  1161,   190,   270,   321,
     319,   241,     0,     1,     1,   483,     0,     1,   280,  1294,
      45,     1,   490,   491,   108,    95,   954,   955,  1745,    52,
     292,   499,   630,   631,   633,   634,    76,   108,    63,    77,
       1,     1,   640,   269,     1,   622,     1,   281,   108,   190,
      90,   108,   260,   261,   149,   263,     9,   233,   190,   235,
     325,   326,   327,   433,   155,   259,   132,   437,   185,   295,
     190,   999,   280,   233,   114,   235,    29,   303,   272,   433,
     274,   155,  1799,   437,   292,   311,   126,   178,   128,   133,
     167,   285,   286,   287,   464,   289,   466,   291,   566,     9,
     108,   155,   108,   158,   178,  1033,   183,   191,   131,  1782,
     464,   108,   466,  1268,   185,   583,   584,   155,   488,    29,
     108,   108,   243,   493,   108,  1053,   594,   615,   108,    30,
     190,  1552,  1060,   190,   488,   201,   941,   264,   265,   493,
     675,    27,    28,   162,   612,   613,   322,   108,   108,  1280,
     194,   108,    30,   108,    95,  1424,   226,   227,   108,   160,
     214,   464,   322,   466,  1433,   190,  1222,  1147,  1148,  1149,
    1827,   241,   125,   978,   127,  1444,   177,   185,  1383,   185,
    1289,  1456,  1387,   136,   672,   488,   281,   276,    30,   186,
     493,   229,   230,    45,   283,    47,   566,   185,  1264,   186,
      95,   185,   155,   144,   574,   185,  1006,  1007,     3,   121,
    1132,  1011,   566,   114,   885,   125,   108,   127,   108,   108,
     574,  1147,  1148,  1149,   185,   185,   136,   113,   185,   108,
     185,     5,     5,   111,   170,     9,     9,    95,   717,   718,
     190,  1041,   913,   613,   156,   155,   158,   108,   126,   158,
    1405,   719,   622,   628,   149,   107,    97,  1185,   726,   613,
       1,   162,    95,   633,   634,   635,   636,  1663,   622,   111,
     206,   574,    67,   151,   107,   119,   277,    72,    97,   633,
     634,   635,   636,   284,   126,    45,   464,    47,   466,   101,
     660,   149,    33,   294,    95,  1223,   895,   119,   190,   155,
     190,   190,   114,   901,     9,    10,   660,   905,   149,   151,
     488,   190,   150,   155,   150,   493,   158,   169,     9,    10,
      80,     1,   362,     3,   119,   365,   118,   158,   166,   190,
     166,    42,    97,   245,   155,    46,   178,   158,   139,   158,
      51,  1269,    95,   144,   714,   189,  1615,   107,   192,   114,
     714,   125,   125,   127,   127,  1781,   148,   107,  1550,    70,
     714,   135,   135,  1555,  1169,  1170,  1294,   189,   158,   161,
     192,    25,    97,   841,   842,   843,  1507,   845,    54,   129,
      34,   155,   155,    59,     9,    10,  1435,    67,    95,   114,
    1318,   144,    72,   158,   205,   240,   574,   242,   155,   104,
    1675,   158,    78,   214,   444,   445,   198,    61,   448,   169,
    1390,   714,   452,   104,   121,   455,   456,   885,    95,    54,
     125,    97,   127,   463,    59,   795,  1492,   233,   146,   469,
     470,   795,   238,   158,   125,   613,   127,   477,     1,   119,
       3,   795,   158,   119,   484,   485,   486,   487,   183,   156,
     155,   158,   492,  1728,   159,  1730,   826,   827,   169,   177,
     500,   172,    97,   996,   155,   200,  1137,   144,   159,   138,
     175,   158,   826,   827,  1171,  1008,   187,   188,   189,   104,
     198,   192,   124,   152,   175,     9,    10,  1772,  1773,   183,
     147,  1047,   795,  1049,   199,  1687,   964,  1297,   101,  1691,
     125,   158,   127,   139,    67,   216,   200,   547,   199,    72,
     160,   114,   217,   155,   121,   885,   158,   189,  1793,   155,
     192,   160,   562,   826,   827,   139,   217,   177,  1456,  1814,
     155,   885,   907,   573,   159,  1820,   714,  1093,   177,  1095,
    1138,   155,   214,   913,   160,    97,  1144,   255,   256,   156,
     175,   158,    96,   203,   265,   119,   119,  1606,  1607,   913,
     600,   177,   114,   107,   203,   605,  1599,   158,   608,   720,
     278,   158,   723,   117,   199,   615,   101,   728,   101,   307,
     104,   101,  1648,  1141,  1776,   129,   101,   271,   316,   114,
    1745,   114,   217,   271,   114,   130,   131,  1397,   282,   114,
     139,   125,   158,   127,   282,   144,  1406,  1535,   695,   696,
    1538,   139,   285,   286,   287,    54,   144,   795,   291,  1424,
      59,   155,   637,   124,   158,  1296,   641,   189,  1433,   158,
     192,   155,   672,   155,   361,   159,   158,   364,   124,  1444,
     229,   230,   231,   240,   124,   242,   130,   131,   826,   827,
     119,   175,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,   124,   702,   703,  1262,  1263,  1716,  1717,   704,
     705,  1636,  1637,   124,   119,   199,   124,   124,   155,   155,
     124,    90,  1315,   124,  1750,   725,   124,   124,   155,   221,
     158,   119,   249,   217,   249,   158,   250,   155,   322,     0,
    1168,   194,   111,   168,    93,   114,   257,   100,  1382,    50,
     204,   751,   102,   156,   754,   103,  1516,   126,  1088,   128,
      30,   185,   197,   158,   185,   185,   185,    47,   768,   154,
     312,  1797,   772,   773,  1088,   119,   254,   190,   155,     1,
    1789,  1374,   119,   144,   108,   155,   158,  1675,   190,  1382,
     190,   791,   155,   158,   158,   185,   158,   144,   158,   799,
     123,   134,   802,   123,   158,    35,   806,  1137,    17,   142,
     143,  1146,   145,   158,   155,   158,    30,  1147,  1148,  1149,
     153,   194,   218,  1137,   157,  1088,   159,   239,   194,     3,
     119,   164,   171,  1147,  1148,  1149,   253,   169,   119,    71,
    1728,   171,  1730,  1869,   292,  1871,   239,   180,    95,   849,
    1615,   292,    95,    95,   190,  1881,   151,   108,   108,    30,
     162,  1379,   162,   129,    95,   134,   144,   254,   307,   134,
     119,   185,  1760,   185,   207,   208,   209,   210,   211,   212,
     190,   190,   108,    95,    97,    45,    97,   887,   155,    95,
     245,   190,   190,   190,   190,   185,   155,  1528,   185,   155,
     155,   155,   155,   144,    33,  1793,   194,   241,   171,   185,
     134,   144,    95,    30,   294,    95,   235,   917,   155,  1807,
     119,  1809,   129,   307,   149,   119,    95,   185,   202,   929,
     134,  1524,   134,  1526,   162,    97,  1529,  1530,   155,   149,
    1533,  1572,  1272,   119,   101,   101,  1539,   185,  1272,   185,
    1088,   144,   155,   123,   954,   955,   956,   957,  1272,   194,
     123,    35,    30,   155,   119,    80,  1296,   253,   108,   107,
     262,   108,   293,   266,   268,    30,   158,  1307,   294,   158,
     158,   158,  1296,  1307,   275,   158,   158,   146,    30,    30,
     158,   295,   314,  1307,   194,   235,  1326,   146,   149,   999,
     190,   190,  1326,   190,   190,   129,   149,   108,   144,  1272,
     185,   202,  1326,  1013,   101,   134,     7,  1347,   241,    97,
     241,   241,   241,   190,  1354,   190,   158,   245,   194,   149,
    1661,   158,   158,  1347,   155,   107,   119,   119,  1038,    78,
    1354,  1672,  1673,   190,  1307,  1676,   149,  1047,   294,  1049,
     258,  1051,  1683,  1053,    79,   190,  1386,   258,    30,   190,
    1060,   290,   190,  1326,    30,   190,   171,   190,   190,   265,
     108,   185,  1386,   149,   190,   128,   445,   128,   149,   448,
      97,   279,   144,   452,  1347,  1678,   455,   456,   185,  1682,
     185,  1354,   185,  1093,   463,  1095,   185,   324,   155,   185,
     469,   470,    95,   288,    30,   190,   190,    97,   477,   149,
     171,   295,    95,   201,    54,   484,   485,   486,   487,    95,
      30,   273,   108,   492,   108,   119,   233,    95,    95,   202,
     119,   500,  1132,   233,  1272,   201,   201,   119,  1769,    94,
     184,  1569,  1570,  1571,   119,   201,   119,   301,   119,   313,
     295,   203,   313,   233,   267,   313,   267,  1157,   270,   757,
    1224,   314,   439,  1000,   314,  1269,   314,  1061,  1750,  1307,
    1797,  1592,   888,  1766,   459,  1166,  1416,  1808,   547,  1408,
     808,  1153,  1401,  1404,   562,  1185,  1308,  1313,  1326,  1316,
    1321,   694,   957,   562,   725,  1826,   725,   674,  1528,   731,
    1341,   850,  1820,   349,   573,   574,  1814,   467,  1049,  1347,
    1841,  1373,  1384,  1806,  1528,   467,  1354,  1810,  1383,  1615,
    1170,  1433,  1437,  1223,  1444,  1612,  1179,  1246,  1482,  1032,
    1639,  1434,  1863,    -1,   603,   603,    -1,    -1,    -1,   608,
      -1,  1872,  1572,    -1,    -1,   111,   615,    -1,  1386,  1842,
      -1,    -1,  1845,    -1,    -1,    -1,    -1,    -1,  1572,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1868,  1704,    -1,  1278,    -1,
      -1,    -1,  1282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1294,    -1,    -1,    -1,  1726,    -1,
      -1,    -1,    -1,   672,    -1,    -1,    -1,    -1,  1308,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1661,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1672,  1673,    -1,    -1,  1676,  1661,  1348,    -1,
      -1,    -1,    -1,  1683,    -1,    -1,   725,    -1,  1672,  1673,
      -1,    -1,  1676,    -1,    -1,    -1,    -1,    -1,    -1,  1683,
      -1,    -1,    -1,  1373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1383,    -1,   754,    -1,  1387,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   768,
      -1,    -1,    -1,   772,   773,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1415,    -1,    -1,    -1,    -1,
      -1,    -1,   791,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     799,    -1,    -1,   802,    -1,    -1,    -1,   806,    -1,  1769,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1769,  1456,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   838,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1808,    -1,
     849,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1488,    -1,
      -1,    -1,    -1,    -1,  1808,    -1,  1826,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1841,  1826,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1841,    -1,    -1,
      -1,    -1,  1532,  1863,    -1,  1535,    -1,    -1,  1538,    -1,
      -1,    -1,  1872,    -1,    -1,    -1,    -1,    -1,   917,  1863,
      -1,  1551,    -1,    -1,    -1,    -1,  1556,    -1,  1872,    -1,
     929,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   954,   955,   956,   957,  1589,
    1590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     999,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1013,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1038,
      -1,    -1,    -1,    -1,    -1,  1675,    -1,  1677,  1047,  1679,
    1049,  1681,  1051,    -1,  1053,    -1,    -1,    -1,  1688,    -1,
      -1,  1060,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1093,    -1,  1095,    -1,  1728,    -1,
    1730,    -1,   598,   599,    -1,   601,   602,   603,   604,    -1,
     606,    -1,    -1,    -1,    -1,   611,  1746,    -1,    -1,  1749,
      -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,
    1760,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1771,    -1,    -1,    -1,    -1,    -1,   643,   644,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   652,   653,  1157,    -1,
     656,    -1,    -1,  1793,   660,    -1,    -1,    -1,    -1,    -1,
      -1,  1801,    -1,    -1,    -1,    -1,    -1,  1807,    -1,  1809,
      -1,    -1,    -1,    -1,    -1,    -1,  1185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1830,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1839,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1223,    -1,    -1,    -1,    -1,  1859,
      -1,   727,    -1,    -1,  1864,   731,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1876,    -1,    -1,  1879,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   770,    -1,    -1,    -1,    -1,  1278,
      -1,    -1,    -1,  1282,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1294,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1308,
      -1,   807,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1318,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   833,    -1,    -1,
      -1,   837,   838,    -1,   840,    -1,    -1,    -1,    -1,  1348,
      -1,   847,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1415,   913,    -1,    -1,
      -1,    -1,    -1,   919,   920,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1456,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1488,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1001,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1532,    -1,    -1,  1535,    -1,    -1,  1538,
    1036,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1551,    -1,    -1,    -1,    -1,  1556,    -1,  1055,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1071,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1082,  1083,    -1,    -1,
    1589,  1590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1097,    -1,    -1,  1100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1119,  1120,  1121,    -1,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,    -1,    -1,  1134,  1135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1675,    -1,  1677,    -1,
    1679,    -1,  1681,    -1,    -1,    -1,    -1,    -1,    -1,  1688,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1728,
      -1,  1730,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1746,    -1,    -1,
    1749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1760,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1771,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1284,    -1,
    1286,    -1,  1288,    -1,  1793,    -1,    -1,    -1,    -1,    -1,
    1296,    -1,  1801,    -1,    -1,    -1,    -1,    -1,  1807,  1305,
    1809,    -1,    -1,    -1,    -1,  1311,  1312,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1830,    -1,    -1,  1330,    -1,    -1,  1333,  1334,    -1,
    1839,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1859,    -1,    -1,    -1,    -1,  1864,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1876,    -1,    -1,
    1879,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1404,    -1,
      -1,    -1,  1408,  1409,    -1,    -1,    -1,    -1,  1414,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1501,    -1,    -1,    -1,  1505,
      -1,    -1,    -1,  1509,    -1,  1511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1519,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1527,  1528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1560,  1561,  1562,  1563,    -1,  1565,
    1566,    -1,  1568,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1583,    -1,    -1,
      -1,    -1,  1588,    -1,    -1,    -1,    -1,    -1,  1594,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1654,    -1,
    1656,    -1,    -1,  1659,    -1,    -1,  1662,    -1,    -1,    -1,
      -1,  1667,  1668,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1676,    -1,    -1,    -1,  1680,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1697,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1708,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1753,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1765,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1808,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,
      -1,  1837,    -1,    -1,    -1,  1841,    11,    12,    -1,    -1,
    1846,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,  1862,    -1,    33,    34,
    1866,    36,    37,    38,    39,    40,    41,    42,    43,    44,
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
      -1,    -1,   187,   188,   189,    -1,   191,   192,   193,   194,
     195,   196,    -1,   198,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
     215,   216,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,    -1,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    -1,   320,    -1,   322,   323,   324,
     325,   326,   327,   328,     0,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,
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
      -1,   187,   188,   189,    -1,   191,   192,   193,   194,   195,
     196,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,   215,
     216,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,    -1,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,     1,   320,    -1,   322,   323,   324,   325,
     326,   327,   328,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,    -1,   191,   192,   193,   194,   195,   196,    -1,
     198,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,    -1,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,     1,   320,    -1,   322,   323,   324,   325,   326,   327,
     328,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
      -1,   191,   192,   193,    -1,   195,   196,    -1,   198,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,   215,   216,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
      -1,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,   324,   325,   326,   327,   328,     0,
       1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    95,    96,    97,    -1,    -1,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,   117,   118,   119,    -1,
      -1,    -1,   123,    -1,    -1,    -1,    -1,   128,   129,    -1,
      -1,    -1,    -1,   134,    -1,    -1,    -1,   138,    -1,    -1,
      -1,   142,   143,    -1,   145,    -1,   147,   148,    -1,    -1,
      -1,   152,   153,    -1,    -1,   156,   157,   158,   159,   160,
     161,    -1,    -1,   164,    -1,    -1,    -1,   168,   169,    -1,
      -1,   172,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,
      -1,    -1,    -1,    -1,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,   194,   195,   196,   197,   198,    -1,    -1,
      -1,    -1,   203,   204,   205,    -1,   207,   208,   209,   210,
     211,   212,    -1,   214,    -1,   216,    -1,    -1,    -1,    -1,
      -1,   222,    -1,    -1,    -1,   226,   227,    -1,     0,     1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,    -1,   243,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,    -1,
     321,    93,    -1,    95,    96,    97,    -1,    -1,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   118,   119,    -1,    -1,
      -1,   123,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,   138,    -1,    -1,    -1,
     142,   143,    -1,   145,    -1,   147,   148,    -1,    -1,    -1,
     152,   153,    -1,    -1,   156,   157,   158,   159,   160,   161,
      -1,    -1,   164,    -1,    -1,    -1,   168,   169,    -1,    -1,
     172,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,   194,   195,   196,   197,   198,    -1,    -1,    -1,
      -1,   203,   204,   205,    -1,   207,   208,   209,   210,   211,
     212,    -1,   214,    -1,   216,    -1,    -1,    -1,    -1,    -1,
     222,    -1,    -1,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
      -1,   243,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,   319,    30,   321,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,    -1,   191,
     192,   193,   194,   195,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,    -1,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,   324,   325,   326,   327,   328,   329,   330,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,    -1,   191,
     192,   193,   194,   195,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,    -1,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,   324,   325,   326,   327,   328,    -1,   330,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,   185,    -1,   187,   188,   189,    -1,   191,
     192,   193,   194,   195,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,    -1,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,   324,   325,   326,   327,   328,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,   188,   189,    -1,   191,   192,   193,
     194,   195,   196,    -1,   198,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,   215,   216,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,    -1,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,    -1,   320,    -1,   322,   323,
     324,   325,   326,   327,   328,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    34,    -1,
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
      -1,   187,   188,   189,    -1,   191,   192,   193,   194,   195,
     196,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,   215,
     216,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,    -1,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,    -1,   320,    -1,   322,   323,   324,   325,
     326,   327,   328,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,    -1,   191,   192,   193,   194,   195,   196,    -1,
     198,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,    -1,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    -1,   320,    -1,   322,   323,   324,   325,   326,   327,
     328,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
      -1,   191,   192,   193,   194,   195,   196,    -1,   198,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,   215,   216,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
      -1,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,   324,   325,   326,   327,   328,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,    -1,   191,
     192,   193,   194,   195,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,    -1,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,   324,   325,   326,   327,   328,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,   188,   189,    -1,   191,   192,   193,
     194,   195,   196,    -1,   198,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,   215,   216,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,    -1,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,    -1,   320,    -1,   322,   323,
     324,   325,   326,   327,   328,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
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
     146,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,   188,   189,   190,   191,   192,   193,    -1,   195,
     196,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,   215,
     216,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,    -1,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,    -1,   320,    -1,   322,   323,   324,   325,
     326,   327,   328,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,   146,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,   190,   191,   192,   193,    -1,   195,   196,    -1,
     198,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,    -1,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    -1,   320,    -1,   322,   323,   324,   325,   326,   327,
     328,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,   186,   187,   188,   189,
      -1,   191,   192,   193,    -1,   195,   196,    -1,   198,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,   215,   216,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
      -1,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,   324,   325,   326,   327,   328,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,   191,
     192,   193,    -1,   195,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,    -1,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,   324,   325,   326,   327,   328,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,   188,   189,    -1,   191,   192,   193,
      -1,   195,   196,    -1,   198,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,   215,   216,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,    -1,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,    -1,   322,   323,
     324,   325,   326,   327,   328,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
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
      -1,   187,   188,   189,    -1,   191,   192,   193,    -1,   195,
     196,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,   215,
     216,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,    -1,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,    -1,   320,   321,   322,   323,   324,   325,
     326,   327,   328,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,   186,   187,
     188,   189,    -1,   191,   192,   193,    -1,   195,   196,    -1,
     198,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,    -1,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    -1,   320,    -1,   322,   323,   324,   325,   326,   327,
     328,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,   191,   192,   193,    -1,   195,   196,    -1,   198,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,   215,   216,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
      -1,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,   324,   325,   326,   327,   328,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,   146,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,    -1,   191,
     192,   193,    -1,   195,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,    -1,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,   324,   325,   326,   327,   328,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,   188,   189,    -1,   191,   192,   193,
      -1,   195,   196,    -1,   198,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,   215,   216,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,    -1,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,    -1,   320,    -1,   322,   323,
     324,   325,   326,   327,   328,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
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
      -1,   187,   188,   189,    -1,   191,   192,   193,    -1,   195,
     196,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,   215,
     216,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,    -1,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,    -1,   320,    -1,   322,   323,   324,   325,
     326,   327,   328,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,    -1,   191,   192,   193,    -1,   195,   196,    -1,
     198,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,    -1,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    -1,   320,    -1,   322,   323,   324,   325,   326,   327,
     328,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
      -1,   191,   192,   193,    -1,   195,   196,    -1,   198,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,   215,   216,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
      -1,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,   324,   325,   326,   327,   328,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,   188,   189,    -1,   191,
     192,   193,    -1,   195,   196,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,    -1,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,   320,    -1,
     322,   323,   324,   325,   326,   327,   328,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,   188,   189,    -1,   191,   192,   193,
      -1,   195,   196,    -1,   198,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,   215,   216,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,    -1,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,    -1,   320,    -1,   322,   323,
     324,   325,   326,   327,   328,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
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
     156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,   188,   189,    -1,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,   215,
     216,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,    -1,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,    -1,   320,    -1,   322,   323,   324,   325,
     326,   327,   328,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,    -1,   106,   107,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
      -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
     198,    -1,   200,    -1,   202,    -1,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,    -1,   267,
     268,   269,    -1,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    -1,   320,    -1,   322,   323,   324,   325,   326,   327,
     328,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
     120,    -1,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,   153,   154,   155,    -1,    -1,    -1,   159,
      -1,    -1,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,    -1,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,   202,    -1,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,   215,   216,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
      -1,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
     320,    -1,   322,   323,   324,   325,   326,   327,   328,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
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
     182,   183,    -1,    -1,    -1,   187,   188,   189,    -1,   191,
     192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,    -1,    -1,   215,   216,    -1,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,   268,   269,    -1,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,    -1,    -1,    -1,    -1,
     322,   323,   324,   325,   326,   327,   328,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
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
      -1,    -1,    -1,   187,   188,   189,    -1,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,   215,   216,    -1,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,    -1,   267,   268,   269,    -1,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,    -1,    16,    -1,   322,   323,
     324,   325,   326,   327,   328,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    98,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,    -1,    -1,   215,   216,    -1,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,    -1,   267,   268,   269,
      -1,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    -1,    -1,
      16,    -1,   322,   323,   324,   325,   326,   327,   328,    25,
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
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,    -1,    -1,   215,
     216,    -1,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
      -1,   267,   268,   269,    -1,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,    -1,    -1,    -1,   322,   323,   324,   325,
     326,   327,   328,    16,    -1,    18,    19,    -1,    -1,    -1,
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
     183,    -1,    -1,    -1,   187,   188,   189,    -1,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,   215,   216,    -1,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,    -1,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    -1,    -1,    16,    -1,   322,
     323,   324,   325,   326,   327,   328,    25,    26,    -1,    -1,
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
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
      -1,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,   215,   216,    -1,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,    -1,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
      -1,    16,    -1,   322,   323,   324,   325,   326,   327,   328,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
     215,   216,    -1,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,    -1,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,    -1,    16,    -1,   322,   323,   324,
     325,   326,   327,   328,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,    -1,    -1,   198,    -1,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,   215,   216,    -1,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,    -1,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,    -1,    16,
      -1,   322,   323,   324,   325,   326,   327,   328,    25,    26,
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
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,   215,   216,
      -1,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,    -1,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    -1,    -1,    16,    -1,   322,   323,   324,   325,   326,
     327,   328,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,   188,   189,    -1,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,   215,   216,    -1,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,    -1,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    -1,    -1,    16,    -1,   322,
     323,   324,   325,   326,   327,   328,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,   215,   216,    -1,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,    -1,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
      -1,    16,    -1,   322,   323,   324,   325,   326,   327,   328,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,   188,   189,    -1,   191,   192,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
     215,   216,    -1,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,    -1,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,    -1,    16,    -1,   322,   323,   324,
     325,   326,   327,   328,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,   188,   189,    -1,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,   215,   216,    -1,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,    -1,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,    -1,    16,
      -1,   322,   323,   324,   325,   326,   327,   328,    25,    26,
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
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,   188,   189,    -1,   191,   192,   193,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,   215,   216,
      -1,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,    -1,
     267,   268,   269,    -1,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    -1,    -1,    16,    -1,   322,   323,   324,   325,   326,
     327,   328,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,   188,   189,    -1,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
      -1,    -1,   215,   216,    -1,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,    -1,   267,   268,   269,    -1,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    -1,    -1,    16,    -1,   322,
     323,   324,   325,   326,   327,   328,    25,    26,    -1,    -1,
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
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,    -1,    -1,   215,   216,    -1,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,    -1,   267,   268,
     269,    -1,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
      -1,    -1,    -1,   322,   323,   324,   325,   326,   327,   328,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    58,    59,    60,
      61,    -1,    -1,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,    -1,   155,   156,    -1,   158,   159,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,   188,   189,    -1,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    -1,    -1,    -1,   216,   217,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,    -1,   267,   268,   269,    -1,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,    -1,   320,
      25,    26,   323,   324,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,    58,    59,    -1,    61,    -1,    -1,    64,
      65,    66,    67,    68,    -1,    70,    -1,    72,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    -1,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,   188,   189,    -1,   191,   192,   193,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,   216,    -1,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    -1,   267,   268,   269,    -1,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,    -1,    -1,    -1,    -1,   323,   324
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
     182,   183,   187,   188,   189,   191,   192,   193,   194,   195,
     196,   198,   200,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   215,   216,   217,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   267,   268,   269,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   320,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   343,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   364,   365,   366,   367,   368,   369,   373,
     374,   375,   379,   381,   382,   384,   391,   393,   396,   397,
     398,   400,   401,   402,   403,   404,   406,   407,   409,   410,
     411,   412,   413,   414,   416,   417,   420,   421,   422,   423,
     424,   430,   432,   436,   437,   438,   443,   462,   465,   469,
     472,   473,   479,   480,   481,   482,   483,   485,   486,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   498,   499,
     500,   501,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   534,
     535,   536,   537,   538,   539,   553,   554,   556,   557,   558,
     559,   560,   561,   562,   563,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   585,   590,   591,
     592,   593,   594,   595,   598,   656,   657,   658,   659,   661,
     662,   663,   664,   665,   668,   669,   670,    33,    34,    49,
     220,   399,   400,   401,   399,   399,   400,   401,   158,   158,
      37,    38,    40,    41,    47,    57,    58,    75,    80,   112,
     113,   114,   162,   228,   269,   295,   303,   311,   380,   381,
     385,   386,   387,   162,   155,   158,   155,   158,   155,   158,
       1,   158,   388,   158,    25,    34,    61,   119,   281,   442,
     444,   445,   158,   155,   158,   158,   158,   119,   155,   158,
     158,   158,    77,   155,   229,   230,   124,   124,   124,   155,
     158,    39,    43,    45,    46,    47,    48,    51,    60,    68,
      71,    73,    74,    76,    91,    92,    98,   106,   113,   115,
     116,   137,   140,   141,   162,   170,   173,   181,   182,   193,
     206,   232,   234,   236,   237,   244,   246,   247,   248,   251,
     252,   265,   268,   323,   518,   669,   124,   119,   408,   124,
     124,    39,    44,    45,    53,    60,    62,    63,    71,    98,
     233,   668,   119,   124,   124,   399,   401,   422,   660,   668,
      48,    73,    74,   119,   155,   186,   252,   421,   423,   436,
     190,   421,   668,   155,   155,   124,   668,    18,    19,   668,
     124,   124,   124,   510,   155,    31,   218,   221,   233,   235,
     322,   233,   235,   322,   233,   322,   233,   238,   119,   249,
     249,   250,   158,   155,   403,     1,   482,   319,   421,   321,
     421,   322,   330,   345,   345,     0,   347,   348,    33,    49,
     350,   367,     1,   194,   344,   194,   344,   113,   382,   402,
     421,   108,   194,   108,   344,   194,    42,    46,    51,    70,
     169,   172,   187,   188,   189,   192,   216,   265,   415,   425,
     426,   431,   432,   433,   434,   435,   450,   451,   455,     3,
      67,    72,   119,   427,   168,    93,   134,   142,   143,   145,
     153,   157,   159,   164,   180,   207,   208,   209,   210,   211,
     212,   502,   503,   257,   100,   160,   177,   203,   118,   148,
     161,   198,   205,   214,   138,   152,    50,   204,   102,   103,
     160,   177,   500,   197,   155,   507,   510,   195,   196,   156,
     522,   523,   518,   522,   518,   121,   156,   158,   522,   158,
     147,   158,   185,   185,   185,   185,   383,   525,   383,    30,
     667,   183,   200,   183,   200,   167,   183,   669,   668,   170,
     206,    47,   668,   154,   119,    45,    47,    80,   107,   169,
     668,   229,   230,   231,   254,   629,   668,   668,   312,   139,
     144,   113,   295,   303,   385,   668,   400,   190,   400,    45,
      63,   190,   581,   582,   421,   190,   198,   668,   439,   440,
     668,   119,   190,   389,   390,   155,   405,   421,     1,   162,
     667,   114,   162,   363,   667,   668,   119,   144,   108,   190,
     421,    30,   190,   668,   668,   668,   463,   464,   668,   400,
     190,   421,   421,   583,   668,   400,   155,   155,   421,   190,
     198,   668,   668,   144,   463,   185,   185,   123,   108,   185,
     123,   158,   158,   158,   668,   155,   186,   426,   190,    35,
     541,   542,   543,   421,   421,     8,   176,    17,   421,   218,
      30,   422,   422,    39,    45,    60,    71,    98,   521,   669,
     422,   422,   422,   660,   422,   521,   422,   239,   596,   597,
     668,   194,   194,   422,   421,   401,   421,   253,   418,   419,
     439,   319,   321,   422,   345,   194,   344,   194,   344,     3,
     351,   367,   397,     1,   351,   367,   397,    33,   368,   397,
     368,   397,   408,   344,   408,   422,   422,   119,   169,   171,
     171,   422,   422,   422,   402,   422,   292,   292,   439,   119,
     446,   481,   482,   485,   485,   485,   485,   484,   485,   485,
     485,    71,   486,   490,   490,   489,   491,   491,   491,   491,
     492,   492,   493,   493,   239,    95,    95,    95,   508,   399,
     510,   510,   421,   523,   158,   527,   529,   585,   668,   186,
     146,   190,   422,   533,   190,   151,   190,   533,   108,   190,
     190,   108,   108,   388,    30,   669,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   370,   371,   372,    95,
     139,   144,   376,   377,   378,   668,   162,   162,   370,   667,
     129,   134,    55,    57,   101,   259,   272,   274,   285,   286,
     287,   289,   291,   630,   631,   632,   633,   634,   635,   642,
     648,   649,   254,    95,   307,   668,   144,   422,   119,   668,
     668,   134,   185,   185,   190,   190,   185,   108,   190,   108,
     190,   108,    36,    95,    97,   149,   441,   442,   564,   668,
      95,   108,   190,   399,   190,   668,    97,    45,   668,   667,
      97,   144,   564,   668,   422,   445,   185,   190,   190,   190,
     190,   108,   191,   149,   564,   185,   190,   190,   155,   185,
     400,   400,   185,   108,   190,   108,   190,   144,   564,   422,
     191,   422,   422,   668,   422,   421,   421,   421,   668,   542,
     543,   132,   201,   185,   185,   185,   133,   194,    95,   226,
     227,   241,    95,   226,   227,   241,   241,   241,    95,    95,
     245,   233,   322,   108,   243,   144,   194,   190,   421,   185,
     519,   602,   419,   241,   367,    33,    33,   194,   344,   194,
     114,   402,   668,   171,   422,   456,   457,   119,   422,   452,
     453,   668,    56,   222,   262,   428,   429,   485,   155,   158,
     267,   506,   525,   603,   606,   607,   608,   609,   610,   614,
     616,   618,   619,    47,   154,   158,   215,   325,   326,   327,
     328,   565,   567,   569,   571,   586,   587,   588,   589,   666,
     668,   565,   497,   570,   668,   497,   185,   186,   190,   421,
     108,   190,   190,   525,   150,   166,   150,   166,   139,   405,
     388,   371,   134,   158,   567,   378,   422,   564,   667,   667,
     130,   131,   667,   285,   286,   287,   291,   668,   271,   282,
     271,   282,    30,   294,    97,   114,   158,   636,   639,   630,
      39,    44,    53,    60,    62,    71,    98,   233,   325,   326,
     327,   392,   571,   666,   235,   307,   316,   422,   668,    95,
     307,   667,   155,   583,   584,   668,   583,   584,   119,   440,
     129,   565,   119,   422,   149,   442,   149,    36,   149,   441,
     442,   564,   565,   390,    95,   185,   202,   134,   362,   667,
     162,   134,    97,   362,   422,   144,   442,   155,   119,   422,
     422,   149,   101,   466,   467,   468,   470,   471,   101,   474,
     475,   476,   477,   400,   185,   185,   155,   583,   583,   422,
     144,   194,   422,   123,   123,   190,   190,   190,    35,   543,
     132,   201,     9,    10,   104,   125,   127,   155,   199,   538,
     540,   551,   552,   555,   155,    30,   240,   242,   422,   422,
     422,   240,   242,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   521,   119,   422,   422,    48,    73,    74,   252,
     402,   423,   436,   253,   599,   600,   155,   214,   403,   422,
     194,   114,   397,   397,   397,   456,    96,   107,   117,   129,
     458,   459,   460,   461,   108,   668,   107,   454,   108,   149,
     564,   262,    54,    59,    78,   119,   441,   447,   448,   449,
     429,   421,   603,   610,   155,   293,   487,   655,    97,   170,
     260,   261,   263,   270,   280,   292,   604,   605,   624,   625,
     626,   627,   650,   653,   266,   268,   611,   629,   275,   615,
     651,   255,   256,   278,   620,   621,   158,   158,   190,   567,
     158,   158,   158,   158,   158,   146,   177,   198,   566,   146,
     190,   146,   422,   139,   405,   585,   377,   294,    30,    97,
     114,   158,   643,    30,   636,   566,   566,   508,   295,   314,
     564,   392,   235,   194,   399,   190,   190,   146,   190,   190,
     440,   149,   441,   668,   422,   149,   422,   129,   422,   149,
     442,   149,   565,   402,   422,   667,   108,   362,   422,   144,
     399,   464,   422,   422,   114,   467,   468,   101,   426,   114,
     468,   471,   119,   478,   565,   101,   114,   475,   101,   114,
     477,   185,   399,   190,   190,   422,   422,   422,   202,   474,
     134,   199,   540,     7,   400,   668,   199,   551,   400,   194,
     241,   241,   241,   241,    97,   245,   245,   597,   426,   158,
     158,   158,   426,   602,   600,   519,   667,   130,   131,   460,
     461,   461,   457,   144,   564,   667,   453,   422,   149,   119,
     119,   422,   668,   449,    78,   185,   190,   603,   617,   258,
     222,   262,   276,   283,   654,    97,   264,   265,   652,   258,
     607,   654,   489,   624,   608,   149,   290,   612,   613,   652,
     294,   623,    79,   622,   190,   198,   565,   568,   190,   190,
     190,   190,   190,   190,   190,    30,   138,   205,   645,   646,
     647,    30,   644,   645,   279,   640,   108,   637,   171,   668,
     265,   508,   185,   422,   149,   422,   149,   441,   422,   149,
     422,   128,   128,    97,   667,   422,   185,   426,   426,   422,
     402,   422,   426,   426,   668,   214,   426,   119,   478,   119,
     426,   119,   478,   426,   185,   114,   543,   668,   199,   185,
     543,   668,   185,   422,   422,   422,   422,   324,   422,   422,
     422,   421,   421,   421,   155,   601,   461,   422,   144,   422,
     668,   668,   448,   422,   185,   491,    52,   131,   489,   489,
     277,   284,   294,   628,   628,   609,   155,   288,    95,   190,
     108,   190,   643,   643,   647,   108,   190,    30,   641,   652,
     638,   639,   190,   394,   395,   508,   119,   233,   315,   295,
     171,   422,   422,   149,   422,   402,   422,   362,   422,   402,
      95,   565,   402,   422,   668,   426,   668,   422,   668,   426,
     402,   119,    94,   184,   544,   543,   668,   201,   543,   422,
     190,   190,   190,   421,   454,   422,    54,   489,   489,   203,
     421,   565,   565,    95,    30,   273,   108,   108,   461,   564,
     668,   119,   233,   668,   394,   422,   478,    95,   426,    95,
     668,     5,   135,   547,   548,   550,   552,    29,   136,   545,
     546,   549,   552,   201,   543,   201,   202,   474,   185,   454,
     119,   489,   185,   565,   639,   395,   461,   313,   668,   119,
     233,   426,   478,   402,   422,   478,   426,    94,   135,   550,
     184,   136,   549,   201,   114,   668,   422,   313,   668,   119,
     402,   422,   426,   426,   119,   301,   313,   668,   668,   314,
     422,   314,   426,   508,   508,   203,   295,   668,   233,   119,
     668,   314,   508
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
     595,   596
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   342,   343,   343,   343,   343,   344,   344,   344,   345,
     345,   345,   345,   346,   346,   347,   347,   347,   347,   347,
     347,   347,   347,   348,   348,   348,   348,   349,   350,   350,
     350,   351,   351,   351,   351,   351,   352,   352,   352,   352,
     352,   352,   352,   352,   353,   353,   354,   355,   356,   356,
     357,   357,   358,   358,   359,   359,   359,   359,   360,   360,
     360,   361,   361,   361,   361,   362,   362,   363,   363,   364,
     364,   364,   364,   365,   366,   366,   367,   367,   367,   368,
     368,   368,   368,   368,   368,   368,   368,   369,   369,   370,
     370,   371,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   373,   374,   375,   376,   376,   377,   377,   377,
     378,   379,   379,   379,   380,   380,   380,   380,   381,   381,
     382,   382,   382,   382,   383,   383,   384,   384,   385,   385,
     386,   386,   387,   387,   388,   388,   388,   388,   389,   389,
     390,   390,   391,   391,   391,   391,   392,   392,   392,   392,
     393,   393,   394,   394,   395,   395,   395,   395,   396,   396,
     396,   396,   397,   398,   398,   398,   399,   399,   399,   400,
     400,   401,   401,   401,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   403,   404,   405,
     406,   407,   407,   407,   408,   408,   408,   408,   409,   410,
     411,   412,   413,   413,   414,   415,   416,   417,   418,   418,
     419,   420,   421,   421,   421,   422,   422,   422,   422,   422,
     422,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   424,   425,   426,   426,   427,   427,   428,
     428,   428,   429,   429,   430,   430,   431,   432,   432,   432,
     433,   433,   433,   433,   433,   433,   433,   434,   435,   436,
     436,   437,   437,   437,   437,   438,   438,   439,   439,   439,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   441,   442,   443,   444,   444,   445,   445,   445,
     445,   446,   446,   447,   447,   447,   448,   448,   448,   449,
     449,   449,   450,   451,   452,   452,   453,   453,   453,   453,
     453,   453,   454,   455,   455,   456,   456,   457,   457,   458,
     458,   458,   458,   458,   458,   458,   459,   459,   460,   460,
     461,   462,   462,   463,   463,   464,   464,   465,   466,   466,
     467,   468,   468,   469,   470,   470,   471,   472,   472,   473,
     473,   474,   474,   475,   475,   476,   476,   477,   477,   478,
     478,   479,   480,   480,   481,   481,   482,   482,   483,   483,
     483,   483,   483,   484,   483,   483,   483,   483,   485,   485,
     486,   486,   487,   487,   488,   488,   489,   489,   489,   490,
     490,   490,   490,   490,   491,   491,   491,   492,   492,   492,
     493,   493,   494,   494,   495,   495,   496,   496,   497,   497,
     498,   498,   499,   499,   499,   499,   500,   500,   500,   501,
     501,   502,   502,   502,   502,   502,   502,   503,   503,   503,
     504,   504,   504,   504,   505,   506,   506,   507,   507,   507,
     508,   508,   508,   508,   509,   510,   510,   510,   511,   511,
     512,   512,   512,   512,   513,   513,   514,   514,   514,   514,
     514,   514,   514,   515,   515,   516,   516,   517,   517,   517,
     517,   517,   518,   518,   519,   519,   520,   520,   520,   520,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   522,   522,   523,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   525,   525,
     526,   526,   526,   527,   528,   528,   529,   530,   531,   532,
     532,   533,   533,   533,   533,   534,   534,   535,   536,   537,
     537,   538,   538,   538,   539,   539,   539,   539,   539,   539,
     540,   540,   541,   541,   542,   543,   543,   544,   544,   545,
     545,   546,   546,   546,   546,   547,   547,   548,   548,   548,
     548,   549,   549,   550,   550,   551,   551,   551,   551,   552,
     552,   552,   552,   553,   553,   554,   554,   555,   556,   556,
     556,   556,   556,   556,   556,   557,   558,   558,   559,   559,
     560,   561,   562,   562,   563,   563,   564,   565,   565,   565,
     565,   566,   566,   566,   567,   567,   567,   567,   567,   567,
     567,   568,   568,   569,   570,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   572,   573,   574,   574,   574,
     575,   576,   577,   578,   578,   578,   579,   579,   579,   579,
     579,   580,   581,   581,   581,   581,   581,   581,   581,   582,
     583,   584,   585,   586,   586,   587,   588,   588,   589,   590,
     590,   590,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   592,   592,   593,   593,   594,   595,   596,   596,
     597,   598,   599,   599,   600,   601,   602,   602,   603,   604,
     604,   605,   605,   606,   606,   607,   607,   608,   608,   609,
     609,   610,   611,   611,   612,   612,   613,   614,   614,   614,
     615,   615,   616,   617,   617,   618,   619,   619,   620,   620,
     621,   621,   621,   622,   622,   623,   623,   624,   624,   624,
     624,   624,   625,   626,   627,   628,   628,   628,   629,   629,
     630,   630,   630,   630,   630,   630,   630,   630,   631,   631,
     631,   631,   632,   632,   633,   634,   634,   635,   635,   635,
     636,   636,   637,   637,   638,   638,   639,   640,   640,   641,
     641,   642,   642,   642,   643,   643,   644,   644,   645,   645,
     646,   646,   647,   647,   648,   649,   649,   650,   650,   650,
     651,   652,   652,   652,   652,   653,   653,   654,   654,   655,
     656,   656,   657,   657,   658,   658,   659,   660,   660,   660,
     660,   661,   661,   661,   662,   663,   664,   665,   666,   666,
     666,   667,   668,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,   668,   668,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   670
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
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     3,     3,     3,     2,     1,     1,     1,     4,     3,
       3,     5,     4,     6,     4,     6,     5,     7,     4,     5,
       5,     6,     3,     3,     2,     1,     3,     4,     5,     3,
       6,     4,     5,     1,     2,     3,     1,     2,     1,     6,
       3,     3,     2,     3,     1,     3,     4,     5,     6,     5,
       1,     2,     2,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     2,     2,
       2,     5,     5,     1,     4,     3,     4,     8,     1,     2,
       3,     2,     3,     8,     1,     2,     3,     8,    10,     8,
      10,     1,     2,     4,     7,     1,     2,     4,     7,     1,
       3,     8,     1,     3,     1,     3,     1,     2,     1,     3,
       3,     3,     3,     0,     4,     3,     3,     3,     1,     5,
       1,     3,     0,     1,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     4,     1,     4,     1,     4,     1,     4,     1,     2,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     4,     1,     2,     3,     2,     2,
       1,     2,     2,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     1,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     3,     3,     4,     5,     3,     3,
       3,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     4,     3,
       4,     1,     3,     1,     3,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     4,     8,     5,     9,     9,    10,
       1,     2,     1,     2,     6,     0,     1,     3,     3,     0,
       1,     1,     1,     2,     2,     0,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     7,     3,     7,
       4,     4,     3,     7,     3,     7,     2,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     4,     4,
       3,     3,     3,     3,     4,     4,     3,     4,     6,     4,
       6,     4,     3,     4,     6,     6,     4,     6,     6,     4,
       1,     2,     1,     1,     1,     4,     5,     6,     3,     3,
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
       2,     3,     2,     3,     2,     3,     3,     3,     3,     5,
       5,     5,     5,     8,     5,     3,     5,     7,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'offset'\"", "\"'limit'\"",
  "\"'return'\"", "\"')'\"", "\"'satisfies'\"", "\"'select'\"",
  "\"'self'\"", "\"';'\"", "\"'/'\"", "\"'//'\"", "\"'!'\"", "\"'*'\"",
  "\"'</ (start tag end)'\"", "\"'strip'\"", "\"'> (tag end)'\"",
  "\"'then'\"", "\"'to'\"", "\"'treat'\"", "\"'union'\"",
  "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"", "\"'gt'\"", "\"'le'\"",
  "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"", "\"'|'\"",
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
  "UNARY_PREC", "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE",
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
       343,     0,    -1,   345,    -1,   329,   345,    -1,   330,   345,
      -1,   329,   330,   345,    -1,     1,    -1,     1,     3,    -1,
     344,     1,    -1,   347,    -1,   346,   347,    -1,   348,    -1,
     346,   348,    -1,   220,   221,    30,   194,    -1,   220,   221,
      30,   133,    30,   194,    -1,   350,   194,   397,    -1,   367,
     194,   397,    -1,   350,   194,   367,   194,   397,    -1,   397,
      -1,   350,   344,   397,    -1,   367,   344,   397,    -1,   350,
     194,   367,   344,   397,    -1,   350,   344,   367,   194,   397,
      -1,   349,    -1,   349,   350,   194,    -1,   349,   367,   194,
      -1,   349,   350,   194,   367,   194,    -1,    34,   162,   668,
     134,   667,   194,    -1,   351,    -1,   350,   194,   351,    -1,
     350,   344,   351,    -1,   352,    -1,   360,    -1,   365,    -1,
     366,    -1,   374,    -1,   353,    -1,   354,    -1,   355,    -1,
     356,    -1,   357,    -1,   358,    -1,   359,    -1,   590,    -1,
      33,    38,   183,    -1,    33,    38,   200,    -1,    33,   114,
     107,   667,    -1,    33,    37,   667,    -1,    33,    40,   183,
      -1,    33,    40,   200,    -1,    33,    58,   170,    -1,    33,
      58,   206,    -1,    33,   114,   169,   129,   130,    -1,    33,
     114,   169,   129,   131,    -1,    33,    41,   183,   108,   150,
      -1,    33,    41,   183,   108,   166,    -1,    33,    41,   167,
     108,   150,    -1,    33,    41,   167,   108,   166,    -1,   361,
      -1,   364,    -1,    49,    25,     1,    -1,    49,    61,   667,
      -1,    49,    61,   363,   667,    -1,    49,    61,   667,    97,
     362,    -1,    49,    61,   363,   667,    97,   362,    -1,   667,
      -1,   362,   108,   667,    -1,   162,   668,   134,    -1,   114,
      45,   162,    -1,    49,    34,   667,    -1,    49,    34,   162,
     668,   134,   667,    -1,    49,    34,   667,    97,   362,    -1,
      49,    34,   162,   668,   134,   667,    97,   362,    -1,    33,
     162,   668,   134,   667,    -1,    33,   114,    45,   162,   667,
      -1,    33,   114,    47,   162,   667,    -1,   368,    -1,   367,
     194,   368,    -1,   367,   344,   368,    -1,   369,    -1,   373,
      -1,   375,    -1,   379,    -1,   384,    -1,   391,    -1,   393,
      -1,   396,    -1,    33,   114,    80,   370,    -1,    33,    80,
     668,   370,    -1,   371,    -1,   370,   371,    -1,   372,   134,
     585,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    33,    57,   668,    30,    -1,    33,   269,   629,
      -1,    33,   112,   154,   376,    -1,    95,   567,   377,    -1,
     377,    -1,   378,    -1,   139,    -1,   139,   378,    -1,   144,
     422,    -1,    33,   380,   144,   422,    -1,    33,   380,   139,
      -1,    33,   380,   139,   144,   422,    -1,   113,   119,   668,
      -1,   113,   119,   668,   564,    -1,   381,   113,   119,   668,
      -1,   381,   113,   119,   668,   564,    -1,   382,    -1,   381,
     382,    -1,    27,    -1,    27,   158,   383,   190,    -1,    28,
      -1,    28,   158,   383,   190,    -1,   525,    -1,   383,   108,
     525,    -1,    33,   385,    -1,    33,   381,   385,    -1,   386,
      -1,   387,    -1,    47,   669,   388,   405,    -1,    47,   669,
     388,   139,    -1,    75,    47,   669,   388,   405,    -1,    75,
      47,   669,   388,   139,    -1,   158,   190,    -1,   158,   389,
     190,    -1,   158,   190,    95,   565,    -1,   158,   389,   190,
      95,   565,    -1,   390,    -1,   389,   108,   390,    -1,   119,
     668,    -1,   119,   668,   564,    -1,    33,   295,   668,    -1,
      33,   295,   668,    95,   392,    -1,    33,   381,   295,   668,
      -1,    33,   381,   295,   668,    95,   392,    -1,   571,    -1,
     571,   566,    -1,   666,    -1,   666,   566,    -1,    33,   303,
     668,   307,   235,   508,   171,   394,    -1,    33,   381,   303,
     668,   307,   235,   508,   171,   394,    -1,   395,    -1,   394,
     108,   395,    -1,   508,    -1,   508,   564,    -1,   508,   461,
      -1,   508,   564,   461,    -1,    33,   311,   312,   668,   307,
     295,   668,   119,   668,   313,   422,    -1,    33,   311,   312,
     668,   307,   295,   668,   233,   119,   668,   313,   301,   314,
     508,    -1,    33,   311,   312,   668,   307,   295,   668,   315,
     233,   119,   668,   313,   422,    -1,    33,   311,   312,   668,
     316,   314,   265,   295,   668,   233,   119,   668,   314,   508,
     203,   295,   668,   233,   119,   668,   314,   508,    -1,   398,
      -1,   400,    -1,   401,    -1,    -1,   400,    -1,   401,    -1,
      -1,   421,    -1,   401,   421,    -1,   402,    -1,   401,   402,
      -1,   401,   421,   344,   402,    -1,   403,    -1,   406,    -1,
     409,    -1,   410,    -1,   411,    -1,   412,    -1,   413,    -1,
     414,    -1,   416,    -1,   473,    -1,   469,    -1,   417,    -1,
     420,    -1,   155,   401,   185,    -1,   155,   399,   185,    -1,
     155,   399,   185,    -1,   407,   194,    -1,   407,   108,   408,
      -1,   113,   408,    -1,   381,   113,   408,    -1,   119,   668,
      -1,   119,   668,   564,    -1,   119,   668,   144,   422,    -1,
     119,   668,   564,   144,   422,    -1,   119,   668,   144,   422,
     194,    -1,   423,   194,    -1,   248,   250,   422,   194,    -1,
     251,   158,   421,   190,   402,    -1,   246,   249,   194,    -1,
     247,   249,   194,    -1,   436,   415,    -1,   426,   402,    -1,
      48,   158,   421,   190,   202,   402,   128,   402,    -1,   252,
     403,   418,    -1,   419,    -1,   418,   419,    -1,   253,   602,
     403,    -1,   194,    -1,   422,    -1,   421,   108,   422,    -1,
     421,   344,   422,    -1,   424,    -1,   465,    -1,   472,    -1,
     479,    -1,   598,    -1,   423,    -1,   480,    -1,   462,    -1,
     591,    -1,   592,    -1,   594,    -1,   593,    -1,   595,    -1,
     663,    -1,   661,    -1,   664,    -1,   665,    -1,   662,    -1,
     436,   425,    -1,   426,   422,    -1,   189,    -1,   192,    -1,
      67,   292,    -1,    72,   292,    -1,   222,    -1,   262,    -1,
      56,   262,    -1,   428,   447,    78,   422,    -1,   428,    78,
     422,    -1,   438,   427,   446,   429,   429,    -1,   438,   427,
     446,   429,    -1,    42,   119,   668,    -1,   437,    -1,   443,
      -1,   430,    -1,   432,    -1,   450,    -1,   455,    -1,   451,
      -1,   431,    -1,   434,    -1,   435,    -1,   187,   422,    -1,
     188,   422,    -1,   432,    -1,   436,   433,    -1,   438,   119,
     439,    -1,    46,     1,   439,    -1,   265,     1,   439,    -1,
     438,     3,    -1,    46,    -1,   265,    -1,   440,    -1,   439,
     108,   119,   440,    -1,   439,   108,   440,    -1,   668,   149,
     422,    -1,   668,    36,   129,   149,   422,    -1,   668,   564,
     149,   422,    -1,   668,   564,    36,   129,   149,   422,    -1,
     668,   441,   149,   422,    -1,   668,    36,   129,   441,   149,
     422,    -1,   668,   564,   441,   149,   422,    -1,   668,   564,
      36,   129,   441,   149,   422,    -1,   668,   442,   149,   422,
      -1,   668,   564,   442,   149,   422,    -1,   668,   441,   442,
     149,   422,    -1,   668,   564,   441,   442,   149,   422,    -1,
      97,   119,   668,    -1,   281,   119,   668,    -1,    51,   444,
      -1,   445,    -1,   444,   108,   445,    -1,   119,   668,   144,
     422,    -1,   119,   668,   564,   144,   422,    -1,   442,   144,
     422,    -1,   119,   668,   564,   442,   144,   422,    -1,   119,
     668,   149,   422,    -1,   119,   668,   564,   149,   422,    -1,
     448,    -1,   119,   668,    -1,   119,   668,   448,    -1,   441,
      -1,   441,   449,    -1,   449,    -1,    59,   119,   668,    54,
     119,   668,    -1,    54,   119,   668,    -1,    59,   119,   668,
      -1,   216,   422,    -1,   172,   171,   452,    -1,   453,    -1,
     452,   108,   453,    -1,   119,   668,   144,   422,    -1,   119,
     668,   564,   144,   422,    -1,   119,   668,   564,   144,   422,
     454,    -1,   119,   668,   144,   422,   454,    -1,   422,    -1,
     422,   454,    -1,   107,   667,    -1,   169,   171,   456,    -1,
      70,   169,   171,   456,    -1,   457,    -1,   456,   108,   457,
      -1,   422,    -1,   422,   458,    -1,   459,    -1,   460,    -1,
     461,    -1,   459,   460,    -1,   459,   461,    -1,   460,   461,
      -1,   459,   460,   461,    -1,    96,    -1,   117,    -1,   129,
     130,    -1,   129,   131,    -1,   107,   667,    -1,    68,   119,
     463,   191,   422,    -1,   137,   119,   463,   191,   422,    -1,
     464,    -1,   463,   108,   119,   464,    -1,   668,   149,   422,
      -1,   668,   564,   149,   422,    -1,    73,   158,   421,   190,
     466,   114,   426,   422,    -1,   467,    -1,   466,   467,    -1,
     468,   426,   422,    -1,   101,   422,    -1,   468,   101,   422,
      -1,    73,   158,   421,   190,   470,   114,   426,   402,    -1,
     471,    -1,   470,   471,    -1,   468,   426,   402,    -1,    74,
     158,   421,   190,   474,   114,   426,   422,    -1,    74,   158,
     421,   190,   474,   114,   119,   668,   426,   422,    -1,    74,
     158,   421,   190,   476,   114,   426,   402,    -1,    74,   158,
     421,   190,   474,   114,   119,   668,   426,   402,    -1,   475,
      -1,   474,   475,    -1,   101,   478,   426,   422,    -1,   101,
     119,   668,    95,   478,   426,   422,    -1,   477,    -1,   476,
     477,    -1,   101,   478,   426,   402,    -1,   101,   119,   668,
      95,   478,   426,   402,    -1,   565,    -1,   478,   214,   565,
      -1,    48,   158,   421,   190,   202,   422,   128,   422,    -1,
     481,    -1,   480,   168,   481,    -1,   482,    -1,   481,    93,
     482,    -1,   483,    -1,   268,   482,    -1,   485,    -1,   485,
     502,   485,    -1,   485,   503,   485,    -1,   485,   134,   485,
      -1,   485,   164,   485,    -1,    -1,   485,   159,   484,   485,
      -1,   485,   157,   485,    -1,   485,   145,   485,    -1,   485,
     143,   485,    -1,   486,    -1,   486,   257,    71,   603,   487,
      -1,   488,    -1,   488,   100,   486,    -1,    -1,   655,    -1,
     489,    -1,   489,   203,   489,    -1,   490,    -1,   489,   177,
     490,    -1,   489,   160,   490,    -1,   491,    -1,   490,   198,
     491,    -1,   490,   118,   491,    -1,   490,   148,   491,    -1,
     490,   161,   491,    -1,   492,    -1,   491,   205,   492,    -1,
     491,   214,   492,    -1,   493,    -1,   492,   152,   493,    -1,
     492,   138,   493,    -1,   494,    -1,   494,    50,   239,   565,
      -1,   495,    -1,   495,   204,    95,   565,    -1,   496,    -1,
     496,   102,    95,   497,    -1,   498,    -1,   498,   103,    95,
     497,    -1,   570,    -1,   570,   146,    -1,   500,    -1,   499,
     500,    -1,   177,    -1,   160,    -1,   499,   177,    -1,   499,
     160,    -1,   504,    -1,   501,    -1,   505,    -1,   508,    -1,
     501,   197,   508,    -1,   207,    -1,   212,    -1,   211,    -1,
     210,    -1,   209,    -1,   208,    -1,   153,    -1,   180,    -1,
     142,    -1,    76,   155,   400,   185,    -1,    76,   230,   155,
     400,   185,    -1,    76,   229,   155,   400,   185,    -1,    76,
      77,   583,   155,   400,   185,    -1,   506,   155,   399,   185,
      -1,   507,    -1,   506,   507,    -1,   178,   668,    17,    -1,
     178,    18,    -1,   178,    19,    -1,   509,    -1,   509,   510,
      -1,   196,   510,    -1,   510,    -1,   195,    -1,   511,    -1,
     511,   195,   510,    -1,   511,   196,   510,    -1,   512,    -1,
     521,    -1,   513,    -1,   513,   522,    -1,   516,    -1,   516,
     522,    -1,   514,   518,    -1,   515,    -1,   106,   124,    -1,
     115,   124,    -1,    98,   124,    -1,   193,   124,    -1,   116,
     124,    -1,   141,   124,    -1,   140,   124,    -1,   518,    -1,
      99,   518,    -1,   517,   518,    -1,   122,    -1,   173,   124,
      -1,    91,   124,    -1,   182,   124,    -1,   181,   124,    -1,
      92,   124,    -1,   571,    -1,   519,    -1,   668,    -1,   520,
      -1,   198,    -1,    11,    -1,    12,    -1,    20,    -1,   524,
      -1,   521,   522,    -1,   521,   158,   190,    -1,   521,   158,
     533,   190,    -1,   521,   156,   186,    -1,   521,   121,   668,
      -1,   521,   121,   158,   190,    -1,   521,   121,   158,   421,
     190,    -1,   521,   121,   527,    -1,   521,   121,   529,    -1,
     521,   121,   585,    -1,   523,    -1,   522,   523,    -1,   156,
     421,   186,    -1,   525,    -1,   527,    -1,   528,    -1,   529,
      -1,   532,    -1,   537,    -1,   530,    -1,   531,    -1,   534,
      -1,   404,    -1,   659,    -1,   656,    -1,   657,    -1,   658,
      -1,   526,    -1,   585,    -1,   111,    -1,   151,    -1,   126,
      -1,   119,   668,    -1,   158,   190,    -1,   158,   421,   190,
      -1,   120,    -1,   170,   155,   421,   185,    -1,   206,   155,
     421,   185,    -1,   669,   158,   190,    -1,   669,   158,   533,
     190,    -1,   146,    -1,   533,   108,   146,    -1,   422,    -1,
     533,   108,   422,    -1,   535,    -1,   536,    -1,   669,   147,
     151,    -1,    47,   388,   405,    -1,   538,    -1,   556,    -1,
     539,    -1,   553,    -1,   554,    -1,   159,   668,   543,   132,
      -1,   159,   668,   543,   201,   199,   668,   543,   201,    -1,
     159,   668,   541,   543,   132,    -1,   159,   668,   541,   543,
     201,   199,   668,   543,   201,    -1,   159,   668,   543,   201,
     540,   199,   668,   543,   201,    -1,   159,   668,   541,   543,
     201,   540,   199,   668,   543,   201,    -1,   551,    -1,   540,
     551,    -1,   542,    -1,   541,   542,    -1,    35,   668,   543,
     134,   543,   544,    -1,    -1,    35,    -1,   184,   545,   184,
      -1,    94,   547,    94,    -1,    -1,   546,    -1,   136,    -1,
     549,    -1,   546,   136,    -1,   546,   549,    -1,    -1,   548,
      -1,   135,    -1,   550,    -1,   548,   135,    -1,   548,   550,
      -1,    29,    -1,   552,    -1,     5,    -1,   552,    -1,   538,
      -1,    10,    -1,   555,    -1,   552,    -1,     9,    -1,   125,
      -1,   127,    -1,   155,   400,   185,    -1,   217,    31,   218,
      -1,   217,   218,    -1,   175,   668,   176,    -1,   175,   668,
       8,    -1,   104,     7,    -1,   557,    -1,   558,    -1,   559,
      -1,   560,    -1,   561,    -1,   562,    -1,   563,    -1,    43,
     155,   400,   185,    -1,    21,   399,   185,    -1,    45,   155,
     421,   185,   155,   399,   185,    -1,    22,   399,   185,    -1,
      98,   155,   421,   185,   155,   399,   185,    -1,    71,   155,
     400,   185,    -1,    39,   155,   400,   185,    -1,    23,   399,
     185,    -1,    60,   155,   421,   185,   155,   399,   185,    -1,
      24,   400,   185,    -1,   162,   155,   421,   185,   155,   400,
     185,    -1,    95,   565,    -1,   567,    -1,   567,   566,    -1,
     215,   158,   190,    -1,   158,   190,    -1,   146,    -1,   198,
      -1,   177,    -1,   569,    -1,   571,    -1,   154,   158,   190,
      -1,   328,   158,   190,    -1,   586,    -1,   589,    -1,   666,
      -1,   565,    -1,   568,   108,   565,    -1,   668,    -1,   668,
      -1,   574,    -1,   581,    -1,   579,    -1,   582,    -1,   580,
      -1,   578,    -1,   577,    -1,   576,    -1,   575,    -1,   572,
      -1,   573,   158,   190,    -1,   233,    -1,    44,   158,   190,
      -1,    44,   158,   581,   190,    -1,    44,   158,   582,   190,
      -1,    53,   158,   190,    -1,    71,   158,   190,    -1,    39,
     158,   190,    -1,    60,   158,   190,    -1,    60,   158,   668,
     190,    -1,    60,   158,    30,   190,    -1,    98,   158,   190,
      -1,    98,   158,   668,   190,    -1,    98,   158,   668,   108,
     583,   190,    -1,    98,   158,   198,   190,    -1,    98,   158,
     198,   108,   583,   190,    -1,    62,   158,   668,   190,    -1,
      45,   158,   190,    -1,    45,   158,   668,   190,    -1,    45,
     158,   668,   108,   583,   190,    -1,    45,   158,   668,   108,
     584,   190,    -1,    45,   158,   198,   190,    -1,    45,   158,
     198,   108,   583,   190,    -1,    45,   158,   198,   108,   584,
     190,    -1,    63,   158,   668,   190,    -1,   668,    -1,   668,
     146,    -1,    30,    -1,   587,    -1,   588,    -1,    47,   158,
     198,   190,    -1,    47,   158,   190,    95,   565,    -1,    47,
     158,   568,   190,    95,   565,    -1,   158,   567,   190,    -1,
      33,   228,   229,    -1,    33,   228,   230,    -1,    33,   228,
     231,    -1,   234,   233,   422,   241,   422,    -1,   234,   233,
     422,    95,   240,   241,   422,    -1,   234,   233,   422,    95,
     242,   241,   422,    -1,   234,   233,   422,   226,   422,    -1,
     234,   233,   422,   227,   422,    -1,   234,   235,   422,   241,
     422,    -1,   234,   235,   422,    95,   240,   241,   422,    -1,
     234,   235,   422,    95,   242,   241,   422,    -1,   234,   235,
     422,   226,   422,    -1,   234,   235,   422,   227,   422,    -1,
     232,   233,   422,    -1,   232,   235,   422,    -1,   237,   233,
     422,   245,   422,    -1,   237,   238,   239,   233,   422,   245,
     422,    -1,   236,   233,   422,    95,   422,    -1,   244,   119,
     596,   243,   422,   426,   422,    -1,   597,    -1,   596,   108,
     119,   597,    -1,   668,   144,   422,    -1,   252,   155,   421,
     185,   599,    -1,   600,    -1,   599,   600,    -1,   253,   602,
     601,    -1,   155,   421,   185,    -1,   519,    -1,   602,   214,
     519,    -1,   606,   604,    -1,    -1,   605,    -1,   624,    -1,
     605,   624,    -1,   607,    -1,   606,   270,   607,    -1,   608,
      -1,   607,   266,   608,    -1,   609,    -1,   608,   268,   149,
     609,    -1,   610,    -1,   267,   610,    -1,   614,   611,   612,
      -1,    -1,   629,    -1,    -1,   613,    -1,   290,   155,   421,
     185,    -1,   618,   615,    -1,   158,   603,   190,    -1,   616,
      -1,    -1,   651,    -1,   506,   155,   617,   185,    -1,    -1,
     603,    -1,   619,   620,    -1,   525,    -1,   155,   421,   185,
      -1,    -1,   621,    -1,   256,   622,    -1,   255,   623,    -1,
     278,    -1,    -1,    79,    -1,    -1,   294,    -1,   625,    -1,
     626,    -1,   627,    -1,   653,    -1,   650,    -1,   170,    -1,
     292,   489,   628,    -1,   261,   652,   628,    -1,   294,    -1,
     284,    -1,   277,    -1,   254,   630,    -1,   629,   254,   630,
      -1,   631,    -1,   632,    -1,   633,    -1,   648,    -1,   634,
      -1,   642,    -1,   635,    -1,   649,    -1,   101,   282,    -1,
     101,   271,    -1,   274,    -1,   289,    -1,   259,   282,    -1,
     259,   271,    -1,    57,   668,    30,    -1,   285,    -1,    55,
     285,    -1,   287,   636,    -1,   287,   158,   636,   637,   190,
      -1,    55,   287,    -1,   639,    -1,   114,    -1,    -1,   108,
     638,    -1,   639,    -1,   638,   108,   639,    -1,    97,    30,
     640,   641,    -1,    -1,   279,    30,    -1,    -1,   652,   273,
      -1,   286,   294,   643,   645,    -1,   286,   294,   114,   645,
      -1,    55,   286,   294,    -1,    97,    30,    -1,   158,   644,
     190,    -1,    30,    -1,   644,   108,    30,    -1,    -1,   646,
      -1,   647,    -1,   646,   647,    -1,   205,   643,    -1,   138,
     643,    -1,   272,    30,    -1,   291,    -1,    55,   291,    -1,
      97,   222,    -1,    97,   262,    -1,   263,   258,    -1,   275,
     652,   288,    -1,   264,   489,    -1,    97,   131,   489,    -1,
      97,    52,   489,    -1,   265,   489,   203,   489,    -1,   280,
     654,    -1,   260,   654,    -1,   283,    -1,   276,    -1,   293,
     258,   491,    -1,   156,   186,    -1,   156,   421,   186,    -1,
     318,   319,    -1,   318,   421,   319,    -1,   320,   321,    -1,
     320,   421,   321,    -1,   155,   660,   185,    -1,   668,   123,
     422,    -1,   422,   123,   422,    -1,   660,   108,   422,   123,
     422,    -1,   660,   108,   668,   123,   422,    -1,   234,   322,
     422,   241,   422,    -1,   234,   322,   660,   241,   422,    -1,
     234,   322,   422,   241,   422,    97,   324,   422,    -1,   323,
     322,   422,   241,   422,    -1,   232,   322,   521,    -1,   236,
     322,   521,    95,   422,    -1,   237,   238,   239,   322,   521,
     245,   422,    -1,   327,   158,   190,    -1,   326,   158,   190,
      -1,   325,   158,   190,    -1,    30,    -1,   669,    -1,    16,
      -1,    98,    -1,    39,    -1,    44,    -1,    53,    -1,    45,
      -1,   154,    -1,    48,    -1,   233,    -1,    60,    -1,    62,
      -1,    63,    -1,    71,    -1,    74,    -1,    73,    -1,   215,
      -1,   251,    -1,   322,    -1,   326,    -1,   325,    -1,   327,
      -1,   328,    -1,   670,    -1,    25,    -1,   219,    -1,   129,
      -1,    38,    -1,   269,    -1,    37,    -1,   230,    -1,   229,
      -1,   148,    -1,    43,    -1,   267,    -1,   268,    -1,   282,
      -1,   271,    -1,   259,    -1,   293,    -1,   285,    -1,   287,
      -1,   286,    -1,   291,    -1,   263,    -1,   258,    -1,    79,
      -1,   222,    -1,   262,    -1,    52,    -1,   231,    -1,   244,
      -1,   310,    -1,   238,    -1,   207,    -1,   212,    -1,   211,
      -1,   210,    -1,   209,    -1,   208,    -1,    97,    -1,   112,
      -1,   113,    -1,   189,    -1,    46,    -1,   265,    -1,    36,
      -1,    67,    -1,    72,    -1,    59,    -1,    54,    -1,    56,
      -1,    78,    -1,    42,    -1,   149,    -1,    51,    -1,   216,
      -1,   187,    -1,   188,    -1,   171,    -1,   172,    -1,   169,
      -1,    70,    -1,    96,    -1,   117,    -1,   130,    -1,   131,
      -1,   107,    -1,    68,    -1,   137,    -1,   191,    -1,   101,
      -1,    95,    -1,   202,    -1,   128,    -1,   168,    -1,    93,
      -1,    50,    -1,   239,    -1,   102,    -1,   203,    -1,   118,
      -1,   161,    -1,   205,    -1,   152,    -1,   138,    -1,    76,
      -1,    77,    -1,   103,    -1,   204,    -1,   153,    -1,   183,
      -1,   200,    -1,   162,    -1,   139,    -1,   133,    -1,   167,
      -1,   150,    -1,   166,    -1,    33,    -1,    40,    -1,    58,
      -1,   114,    -1,    41,    -1,    57,    -1,   221,    -1,    49,
      -1,    61,    -1,    34,    -1,    47,    -1,   281,    -1,   257,
      -1,   290,    -1,   292,    -1,   261,    -1,   275,    -1,   288,
      -1,   280,    -1,   260,    -1,   274,    -1,   289,    -1,   279,
      -1,   273,    -1,   272,    -1,   256,    -1,   255,    -1,   264,
      -1,   294,    -1,   284,    -1,   283,    -1,   278,    -1,   276,
      -1,   277,    -1,   243,    -1,   240,    -1,   323,    -1,   234,
      -1,   237,    -1,   236,    -1,   232,    -1,   227,    -1,   226,
      -1,   228,    -1,   245,    -1,   235,    -1,   242,    -1,   241,
      -1,    66,    -1,    64,    -1,    75,    -1,   170,    -1,   206,
      -1,   250,    -1,   248,    -1,   249,    -1,   246,    -1,   247,
      -1,   252,    -1,   253,    -1,   254,    -1,    65,    -1,   303,
      -1,   301,    -1,   302,    -1,   307,    -1,   308,    -1,   309,
      -1,   304,    -1,   305,    -1,   306,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,   295,
      -1,   296,    -1,   297,    -1,   298,    -1,   299,    -1,   300,
      -1,   311,    -1,   312,    -1,   313,    -1,   314,    -1,   315,
      -1,   316,    -1,   317,    -1,    91,    -1,   106,    -1,   115,
      -1,   173,    -1,   181,    -1,   193,    -1,   140,    -1,    92,
      -1,   116,    -1,   141,    -1,   182,    -1,   324,    -1,   223,
      -1,   224,    -1,   225,    -1,   192,    -1,   220,    -1,    26,
      -1
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
     903,   905,   907,   909,   911,   913,   915,   917,   920,   923,
     925,   928,   932,   936,   940,   943,   945,   947,   949,   954,
     958,   962,   968,   973,   980,   985,   992,   998,  1006,  1011,
    1017,  1023,  1030,  1034,  1038,  1041,  1043,  1047,  1052,  1058,
    1062,  1069,  1074,  1080,  1082,  1085,  1089,  1091,  1094,  1096,
    1103,  1107,  1111,  1114,  1118,  1120,  1124,  1129,  1135,  1142,
    1148,  1150,  1153,  1156,  1160,  1165,  1167,  1171,  1173,  1176,
    1178,  1180,  1182,  1185,  1188,  1191,  1195,  1197,  1199,  1202,
    1205,  1208,  1214,  1220,  1222,  1227,  1231,  1236,  1245,  1247,
    1250,  1254,  1257,  1261,  1270,  1272,  1275,  1279,  1288,  1299,
    1308,  1319,  1321,  1324,  1329,  1337,  1339,  1342,  1347,  1355,
    1357,  1361,  1370,  1372,  1376,  1378,  1382,  1384,  1387,  1389,
    1393,  1397,  1401,  1405,  1406,  1411,  1415,  1419,  1423,  1425,
    1431,  1433,  1437,  1438,  1440,  1442,  1446,  1448,  1452,  1456,
    1458,  1462,  1466,  1470,  1474,  1476,  1480,  1484,  1486,  1490,
    1494,  1496,  1501,  1503,  1508,  1510,  1515,  1517,  1522,  1524,
    1527,  1529,  1532,  1534,  1536,  1539,  1542,  1544,  1546,  1548,
    1550,  1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1570,
    1572,  1577,  1583,  1589,  1596,  1601,  1603,  1606,  1610,  1613,
    1616,  1618,  1621,  1624,  1626,  1628,  1630,  1634,  1638,  1640,
    1642,  1644,  1647,  1649,  1652,  1655,  1657,  1660,  1663,  1666,
    1669,  1672,  1675,  1678,  1680,  1683,  1686,  1688,  1691,  1694,
    1697,  1700,  1703,  1705,  1707,  1709,  1711,  1713,  1715,  1717,
    1719,  1721,  1724,  1728,  1733,  1737,  1741,  1746,  1752,  1756,
    1760,  1764,  1766,  1769,  1773,  1775,  1777,  1779,  1781,  1783,
    1785,  1787,  1789,  1791,  1793,  1795,  1797,  1799,  1801,  1803,
    1805,  1807,  1809,  1811,  1814,  1817,  1821,  1823,  1828,  1833,
    1837,  1842,  1844,  1848,  1850,  1854,  1856,  1858,  1862,  1866,
    1868,  1870,  1872,  1874,  1876,  1881,  1890,  1896,  1906,  1916,
    1927,  1929,  1932,  1934,  1937,  1944,  1945,  1947,  1951,  1955,
    1956,  1958,  1960,  1962,  1965,  1968,  1969,  1971,  1973,  1975,
    1978,  1981,  1983,  1985,  1987,  1989,  1991,  1993,  1995,  1997,
    1999,  2001,  2003,  2007,  2011,  2014,  2018,  2022,  2025,  2027,
    2029,  2031,  2033,  2035,  2037,  2039,  2044,  2048,  2056,  2060,
    2068,  2073,  2078,  2082,  2090,  2094,  2102,  2105,  2107,  2110,
    2114,  2117,  2119,  2121,  2123,  2125,  2127,  2131,  2135,  2137,
    2139,  2141,  2143,  2147,  2149,  2151,  2153,  2155,  2157,  2159,
    2161,  2163,  2165,  2167,  2169,  2171,  2175,  2177,  2181,  2186,
    2191,  2195,  2199,  2203,  2207,  2212,  2217,  2221,  2226,  2233,
    2238,  2245,  2250,  2254,  2259,  2266,  2273,  2278,  2285,  2292,
    2297,  2299,  2302,  2304,  2306,  2308,  2313,  2319,  2326,  2330,
    2334,  2338,  2342,  2348,  2356,  2364,  2370,  2376,  2382,  2390,
    2398,  2404,  2410,  2414,  2418,  2424,  2432,  2438,  2446,  2448,
    2453,  2457,  2463,  2465,  2468,  2472,  2476,  2478,  2482,  2485,
    2486,  2488,  2490,  2493,  2495,  2499,  2501,  2505,  2507,  2512,
    2514,  2517,  2521,  2522,  2524,  2525,  2527,  2532,  2535,  2539,
    2541,  2542,  2544,  2549,  2550,  2552,  2555,  2557,  2561,  2562,
    2564,  2567,  2570,  2572,  2573,  2575,  2576,  2578,  2580,  2582,
    2584,  2586,  2588,  2590,  2594,  2598,  2600,  2602,  2604,  2607,
    2611,  2613,  2615,  2617,  2619,  2621,  2623,  2625,  2627,  2630,
    2633,  2635,  2637,  2640,  2643,  2647,  2649,  2652,  2655,  2661,
    2664,  2666,  2668,  2669,  2672,  2674,  2678,  2683,  2684,  2687,
    2688,  2691,  2696,  2701,  2705,  2708,  2712,  2714,  2718,  2719,
    2721,  2723,  2726,  2729,  2732,  2735,  2737,  2740,  2743,  2746,
    2749,  2753,  2756,  2760,  2764,  2769,  2772,  2775,  2777,  2779,
    2783,  2786,  2790,  2793,  2797,  2800,  2804,  2808,  2812,  2816,
    2822,  2828,  2834,  2840,  2849,  2855,  2859,  2865,  2873,  2877,
    2881,  2885,  2887,  2889,  2891,  2893,  2895,  2897,  2899,  2901,
    2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,  2919,  2921,
    2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,  2939,  2941,
    2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,  2959,  2961,
    2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,  2979,  2981,
    2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,  2999,  3001,
    3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,  3019,  3021,
    3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,  3039,  3041,
    3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,  3059,  3061,
    3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,  3079,  3081,
    3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,  3099,  3101,
    3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,  3119,  3121,
    3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,  3139,  3141,
    3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,  3159,  3161,
    3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,  3179,  3181,
    3183,  3185,  3187,  3189,  3191,  3193,  3195,  3197,  3199,  3201,
    3203,  3205,  3207,  3209,  3211,  3213,  3215,  3217,  3219,  3221,
    3223,  3225,  3227,  3229,  3231,  3233,  3235,  3237,  3239,  3241,
    3243,  3245,  3247,  3249,  3251,  3253,  3255,  3257,  3259,  3261,
    3263,  3265,  3267,  3269,  3271,  3273,  3275,  3277,  3279,  3281,
    3283,  3285,  3287,  3289,  3291,  3293,  3295,  3297,  3299,  3301,
    3303,  3305,  3307,  3309,  3311,  3313,  3315,  3317,  3319,  3321,
    3323,  3325,  3327,  3329,  3331,  3333,  3335,  3337,  3339,  3341,
    3343,  3345,  3347,  3349
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1153,  1153,  1154,  1158,  1162,  1170,  1176,  1180,  1189,
    1195,  1203,  1209,  1220,  1225,  1234,  1241,  1248,  1257,  1264,
    1272,  1280,  1288,  1299,  1304,  1311,  1318,  1330,  1340,  1347,
    1354,  1366,  1367,  1368,  1369,  1370,  1375,  1376,  1377,  1378,
    1379,  1380,  1381,  1384,  1389,  1394,  1402,  1410,  1418,  1423,
    1431,  1436,  1444,  1449,  1457,  1462,  1467,  1472,  1480,  1482,
    1485,  1495,  1500,  1508,  1516,  1527,  1534,  1545,  1551,  1559,
    1566,  1573,  1582,  1596,  1605,  1612,  1622,  1629,  1636,  1647,
    1648,  1649,  1650,  1651,  1652,  1653,  1654,  1659,  1665,  1674,
    1681,  1691,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,
    1709,  1710,  1715,  1734,  1742,  1750,  1757,  1765,  1772,  1777,
    1785,  1793,  1807,  1821,  1838,  1843,  1851,  1859,  1870,  1875,
    1884,  1889,  1896,  1901,  1911,  1916,  1925,  1931,  1944,  1945,
    1950,  1965,  1980,  1996,  2011,  2016,  2021,  2026,  2034,  2041,
    2052,  2057,  2067,  2076,  2085,  2094,  2106,  2110,  2116,  2120,
    2130,  2140,  2153,  2159,  2168,  2173,  2180,  2187,  2198,  2208,
    2218,  2228,  2246,  2266,  2270,  2275,  2282,  2286,  2291,  2298,
    2303,  2315,  2322,  2332,  2347,  2348,  2349,  2350,  2351,  2352,
    2353,  2355,  2356,  2357,  2358,  2359,  2360,  2365,  2373,  2405,
    2413,  2421,  2428,  2435,  2446,  2455,  2464,  2473,  2486,  2494,
    2502,  2510,  2525,  2530,  2538,  2552,  2569,  2594,  2602,  2609,
    2620,  2629,  2637,  2642,  2655,  2672,  2673,  2674,  2675,  2676,
    2677,  2682,  2683,  2686,  2687,  2688,  2689,  2690,  2693,  2694,
    2695,  2696,  2697,  2702,  2716,  2724,  2727,  2735,  2740,  2748,
    2753,  2758,  2766,  2775,  2787,  2797,  2810,  2818,  2819,  2820,
    2825,  2826,  2827,  2828,  2829,  2830,  2831,  2835,  2842,  2849,
    2856,  2866,  2871,  2880,  2889,  2899,  2902,  2911,  2918,  2926,
    2938,  2948,  2958,  2968,  2978,  2988,  2998,  3008,  3019,  3028,
    3038,  3048,  3064,  3073,  3082,  3090,  3096,  3108,  3116,  3126,
    3134,  3146,  3152,  3163,  3165,  3169,  3177,  3181,  3186,  3190,
    3194,  3198,  3208,  3216,  3223,  3229,  3239,  3243,  3251,  3259,
    3267,  3275,  3287,  3295,  3301,  3311,  3317,  3327,  3331,  3341,
    3347,  3353,  3359,  3368,  3377,  3386,  3399,  3403,  3411,  3417,
    3427,  3435,  3444,  3457,  3464,  3476,  3480,  3492,  3499,  3505,
    3514,  3521,  3527,  3538,  3545,  3551,  3560,  3569,  3576,  3587,
    3594,  3606,  3612,  3624,  3630,  3641,  3647,  3658,  3664,  3675,
    3681,  3692,  3701,  3705,  3718,  3728,  3739,  3743,  3758,  3762,
    3772,  3779,  3788,  3798,  3797,  3815,  3824,  3833,  3846,  3850,
    3862,  3866,  3874,  3877,  3884,  3888,  3897,  3901,  3905,  3913,
    3917,  3923,  3929,  3935,  3945,  3949,  3953,  3961,  3965,  3971,
    3981,  3985,  3995,  3999,  4009,  4013,  4023,  4027,  4037,  4041,
    4050,  4054,  4062,  4066,  4070,  4074,  4084,  4085,  4086,  4090,
    4095,  4103,  4107,  4111,  4115,  4119,  4123,  4131,  4135,  4139,
    4147,  4151,  4155,  4159,  4170,  4180,  4186,  4196,  4200,  4204,
    4210,  4214,  4224,  4234,  4287,  4296,  4306,  4310,  4319,  4320,
    4326,  4332,  4340,  4346,  4359,  4365,  4376,  4380,  4384,  4388,
    4392,  4398,  4404,  4413,  4417,  4426,  4430,  4442,  4446,  4450,
    4456,  4460,  4475,  4476,  4482,  4486,  4496,  4500,  4504,  4508,
    4520,  4525,  4529,  4533,  4539,  4543,  4549,  4555,  4561,  4565,
    4569,  4578,  4584,  4595,  4603,  4604,  4605,  4606,  4607,  4608,
    4609,  4610,  4611,  4612,  4615,  4616,  4617,  4618,  4623,  4627,
    4635,  4642,  4649,  4660,  4668,  4672,  4680,  4691,  4699,  4705,
    4709,  4731,  4737,  4743,  4749,  4759,  4763,  4771,  4779,  4791,
    4792,  4797,  4798,  4799,  4804,  4812,  4829,  4837,  4854,  4873,
    4897,  4903,  4914,  4920,  4931,  4940,  4942,  4946,  4951,  4961,
    4964,  4971,  4977,  4983,  4990,  5002,  5005,  5012,  5018,  5024,
    5031,  5042,  5046,  5054,  5058,  5066,  5070,  5074,  5079,  5088,
    5092,  5096,  5100,  5108,  5113,  5121,  5127,  5136,  5144,  5149,
    5154,  5159,  5164,  5169,  5174,  5180,  5188,  5192,  5198,  5202,
    5210,  5218,  5226,  5230,  5238,  5242,  5250,  5258,  5262,  5266,
    5272,  5281,  5287,  5293,  5303,  5347,  5351,  5355,  5359,  5363,
    5367,  5374,  5380,  5390,  5398,  5406,  5410,  5414,  5418,  5422,
    5426,  5430,  5434,  5438,  5442,  5450,  5457,  5464,  5468,  5472,
    5480,  5487,  5495,  5503,  5507,  5512,  5520,  5524,  5530,  5536,
    5540,  5550,  5558,  5562,  5568,  5577,  5586,  5592,  5598,  5608,
    5614,  5621,  5627,  5633,  5637,  5645,  5653,  5657,  5668,  5674,
    5680,  5686,  5696,  5700,  5706,  5712,  5716,  5722,  5726,  5732,
    5738,  5745,  5755,  5760,  5768,  5774,  5784,  5790,  5799,  5805,
    5818,  5824,  5831,  5837,  5847,  5856,  5864,  5870,  5879,  5887,
    5891,  5898,  5903,  5911,  5915,  5922,  5926,  5933,  5937,  5944,
    5948,  5957,  5970,  5973,  5981,  5984,  5992,  6000,  6008,  6012,
    6020,  6023,  6031,  6043,  6046,  6054,  6066,  6072,  6082,  6085,
    6093,  6097,  6101,  6109,  6112,  6120,  6123,  6131,  6135,  6139,
    6143,  6147,  6155,  6163,  6175,  6187,  6191,  6195,  6203,  6209,
    6219,  6223,  6227,  6231,  6235,  6239,  6243,  6247,  6255,  6259,
    6263,  6267,  6275,  6281,  6291,  6301,  6305,  6313,  6323,  6334,
    6341,  6345,  6353,  6356,  6363,  6368,  6377,  6387,  6390,  6397,
    6401,  6409,  6418,  6425,  6435,  6439,  6446,  6452,  6462,  6465,
    6472,  6477,  6489,  6497,  6509,  6517,  6521,  6529,  6533,  6537,
    6545,  6553,  6557,  6561,  6565,  6573,  6581,  6593,  6597,  6605,
    6611,  6615,  6622,  6626,  6633,  6637,  6645,  6655,  6669,  6675,
    6684,  6697,  6703,  6713,  6720,  6727,  6745,  6770,  6790,  6794,
    6798,  6811,  6816,  6817,  6818,  6819,  6820,  6821,  6822,  6823,
    6824,  6825,  6826,  6827,  6828,  6829,  6830,  6831,  6832,  6833,
    6834,  6835,  6836,  6837,  6838,  6842,  6843,  6844,  6845,  6846,
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
    7017,  7018,  7019,  7020,  7021,  7022,  7023,  7024,  7025,  7026,
    7027,  7028,  7029,  7030,  7031,  7032,  7033,  7034,  7035,  7036,
    7037,  7038,  7039,  7040,  7041,  7042,  7043,  7044,  7046,  7047,
    7048,  7049,  7050,  7056
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
     335,   336,   337,   338,   339,   340,   341
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 19209;
  const int jsoniq_parser::yynnts_ = 329;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 625;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 342;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 596;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba
/* Line 1106 of lalr1.cc  */
#line 16971 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
/* Line 1107 of lalr1.cc  */
#line 7060 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/jsoniq_parser.y"


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
