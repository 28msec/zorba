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
#line 1 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"

#define JSONIQ_PARSER

/* Line 293 of lalr1.cc  */
#line 59 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"


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


/* Line 293 of lalr1.cc  */
#line 102 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"


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



/* Line 293 of lalr1.cc  */
#line 102 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 792 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 849 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"

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


/* Line 299 of lalr1.cc  */
#line 207 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 293 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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
        case 111: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 344: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 407: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "VoidStatement" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "NotExpr" */

/* Line 480 of lalr1.cc  */
#line 814 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "PostfixExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 523: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 623: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 624: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 625: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 631: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2783 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2792 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2819 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2828 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2837 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2846 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2855 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2864 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 654: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2873 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 655: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2882 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 656: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2891 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 657: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2900 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2909 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2918 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2927 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2936 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 664: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2945 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 665: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2954 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 666: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2963 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
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
#line 129 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 3060 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 938 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 942 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 946 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 952 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 956 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 960 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 966 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 972 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 980 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 986 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 995 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1000 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1006 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1012 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1018 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1026 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1031 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1039 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1047 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1055 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1064 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1069 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1075 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1081 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1090 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1098 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1105 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1111 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1137 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1142 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1148 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1154 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1160 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1165 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1171 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1176 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1187 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1193 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1198 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1203 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1208 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1218 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\"");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1226 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1231 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1239 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1247 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1263 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1271 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1277 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1283 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1289 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1296 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1304 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1315 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1322 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1329 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1344 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1350 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1375 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1382 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1389 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1404 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1405 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1406 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1407 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1408 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1409 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1411 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1412 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1413 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1417 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1431 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1437 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1443 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1450 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1456 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1463 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1468 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1474 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1480 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1492 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1504 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1517 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1522 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1530 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1538 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1547 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1552 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1559 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1564 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1571 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1576 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1584 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1589 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1596 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1615 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1629 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1642 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1657 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1670 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1675 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1680 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1685 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1691 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1698 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1706 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1711 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1719 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1727 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (5)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1735 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1743 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceTypeAST*>((yysemantic_stack_[(6) - (6)].node)));
      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1753 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1757 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1763 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1767 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1774 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1783 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1794 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1819 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1826 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1836 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1846 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1856 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1867 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1880 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 1896 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1900 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1904 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1910 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1914 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1918 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1924 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1929 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1937 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1944 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1951 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1979 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1985 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2011 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2017 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2023 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2030 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2037 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2046 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2055 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2064 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2073 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2084 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2090 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2096 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2102 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2114 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2119 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2125 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2137 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2150 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2170 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2176 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2183 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2192 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2199 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2205 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2210 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2222 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2256 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2268 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2275 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2280 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2285 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2291 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2296 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2301 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2307 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2316 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2326 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2336 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2347 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2365 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2372 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2380 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2384 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2392 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2400 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2409 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2414 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2421 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2428 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 266:

/* Line 690 of lalr1.cc  */
#line 2438 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2448 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2458 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 269:

/* Line 690 of lalr1.cc  */
#line 2468 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 270:

/* Line 690 of lalr1.cc  */
#line 2478 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2488 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2498 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 273:

/* Line 690 of lalr1.cc  */
#line 2508 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 274:

/* Line 690 of lalr1.cc  */
#line 2518 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2527 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 276:

/* Line 690 of lalr1.cc  */
#line 2537 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2547 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 278:

/* Line 690 of lalr1.cc  */
#line 2559 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2565 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2571 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2577 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2583 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2591 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2599 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2607 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2615 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2625 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2631 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2641 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2645 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2652 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2656 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2664 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2668 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2672 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2678 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2684 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2690 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2696 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2704 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2708 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceTypeAST*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2716 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceTypeAST*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2724 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
#line 2732 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2740 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2750 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2756 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2762 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2770 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2776 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2784 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2788 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2796 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2814 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2823 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2832 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2841 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2852 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2856 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2862 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2868 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2876 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2882 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2891 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 2902 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2908 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2916 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2920 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2929 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2935 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2941 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2949 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2955 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2961 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2969 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2975 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2981 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2989 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2995 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3002 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3012 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3019 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3029 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3035 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3043 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3049 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3058 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3064 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3072 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3078 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3087 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceTypeAST*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3093 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceTypeAST*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3101 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3107 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3111 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3117 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3122 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3128 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3132 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3143 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3147 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3156 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3162 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3171 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3180 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.getJsoniqLexer()->interpretAsLessThan();
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3184 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3193 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3202 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3211 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3222 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3226 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3237 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3241 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3246 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3250 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3256 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3260 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3266 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3270 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3274 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3280 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3284 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3290 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3296 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3302 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3310 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3314 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3318 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3324 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3328 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3334 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3342 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3346 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3354 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3358 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceTypeAST*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3366 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3378 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3382 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3390 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3394 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3400 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3404 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3410 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3414 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3418 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3422 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3435 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3440 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3446 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3450 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3454 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3458 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3462 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3466 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3472 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3476 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3480 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3486 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3490 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3494 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3498 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3507 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 3515 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 3521 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 3529 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 3537 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 3543 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 3547 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 3555 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 3563 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3599 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 3605 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3615 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 3619 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3629 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3635 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3643 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3649 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3659 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3665 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3673 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3677 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3681 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3685 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3689 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3695 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3701 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3707 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3711 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3717 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 3721 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 3730 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 3734 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3738 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3744 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3748 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3760 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3770 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3774 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3778 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3788 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 3796 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 3800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 3804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new JSONArrayUnboxing(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 3808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (3)].expr), (yylocation_stack_[(3) - (3)]));
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 3814 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(4) - (2)])),
                                 (yysemantic_stack_[(4) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), NULL));
     }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 3820 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(5) - (2)])),
                                 (yysemantic_stack_[(5) - (1)].expr),
                                 new ParenthesizedExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (4)].expr)));
     }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 3826 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 3830 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 3834 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), LOC((yylocation_stack_[(3) - (2)])), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 3840 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 3846 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 3854 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 3876 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3880 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3886 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3893 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3900 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3909 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3915 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3919 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 3925 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 3932 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 3938 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 3944 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 3948 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 517:

/* Line 690 of lalr1.cc  */
#line 3966 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 3972 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 3984 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 3992 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 3996 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4002 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4008 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4027 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4035 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 532:

/* Line 690 of lalr1.cc  */
#line 4051 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4059 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 534:

/* Line 690 of lalr1.cc  */
#line 4077 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 535:

/* Line 690 of lalr1.cc  */
#line 4095 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 536:

/* Line 690 of lalr1.cc  */
#line 4113 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4119 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4128 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4134 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4143 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4153 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4158 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4164 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4168 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4174 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4186 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4193 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4201 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4205 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4211 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4217 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4223 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4230 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4239 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4243 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4249 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4253 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4259 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4263 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4267 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4272 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4279 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4283 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 4287 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4291 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4297 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4302 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4308 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4314 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4321 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4327 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4332 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4337 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4342 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4347 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4352 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4360 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4366 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4370 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4376 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4380 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4386 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4392 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4398 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4402 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4408 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4418 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4424 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4428 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceTypeAST(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4432 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4436 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_JSONIQ_EMPTY_SEQUENCE));
            (yyval.node) = new SequenceTypeAST( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4443 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4449 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4455 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            GeneralizedAtomicType* gat = static_cast<GeneralizedAtomicType*>((yysemantic_stack_[(1) - (1)].node));
            QName* q = gat->get_qname();
            if (q->get_qname() == "item")
            {
              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new ItemType( LOC((yyloc)), true );
              delete gat;
            }
            else if (q->get_qname() == "array")
            {
              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
              delete gat;
            }
            else if (q->get_qname() == "object")
            {
              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
              delete gat;
            }
            else if (q->get_qname() == "json-item")
            {
              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
              delete gat;
            }
            else if (q->get_qname() == "structured-item")
            {
              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new StructuredItemType(LOC((yyloc)));
              delete gat;
            }
            else
            {
              (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            }
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4502 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4506 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4510 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4514 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4518 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4522 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4528 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4534 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4542 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4548 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4554 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4558 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4562 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4566 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4570 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4574 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4578 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4582 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4586 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4590 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4596 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4602 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4608 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4612 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4616 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4622 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 4627 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 4633 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4639 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4643 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4648 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4654 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4658 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4664 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4670 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4674 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4682 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4688 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4692 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4698 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4707 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4716 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4722 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4728 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4736 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4742 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4748 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4754 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4760 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4764 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4770 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4776 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4780 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceTypeAST *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4788 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4794 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4814 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4818 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4824 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4830 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4834 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4840 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4844 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4850 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4856 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4863 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4871 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4876 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4882 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4888 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4896 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4902 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4909 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4915 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4924 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4930 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4936 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4942 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4958 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4964 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4970 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 4979 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4986 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4990 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4996 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5008 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5012 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5018 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5022 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5028 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5032 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5038 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5042 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5050 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 5060 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 5064 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 5069 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 5073 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 5079 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 5085 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 5093 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 5097 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 5102 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 5106 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 5112 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 5121 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 5125 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 5131 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 5141 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 5147 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5154 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5158 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 5164 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 5168 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5172 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5177 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5181 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5190 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5196 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5200 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5204 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5208 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5212 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5218 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5224 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5234 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5244 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5248 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5252 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5258 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5264 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5272 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5276 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5280 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5284 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 5288 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 5292 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5296 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5300 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5306 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5324 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5330 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5338 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5346 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5350 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5356 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 754:

/* Line 690 of lalr1.cc  */
#line 5366 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 755:

/* Line 690 of lalr1.cc  */
#line 5377 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5383 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5387 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5392 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5396 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5402 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5407 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5414 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5421 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 5425 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 5431 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 5435 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5441 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5450 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5457 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5465 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5469 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5475 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5481 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5488 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5492 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5498 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5503 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5513 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5521 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5531 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5537 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5541 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5547 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5551 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5555 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5561 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5567 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5571 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5575 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5579 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5585 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5607 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 5623 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5633 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5643 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (1)].expr), (yylocation_stack_[(3) - (1)]));
          driver.addCommonLanguageWarning((yylocation_stack_[(3) - (1)]), ZED(ZWST0009_OBJECT_KEY_NOT_QUOTED));
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5690 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 809:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 812:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 813:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 814:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5800 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5804 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5806 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5808 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5809 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5811 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5812 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5813 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5814 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5820 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5824 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5825 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5826 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5829 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5830 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5831 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5832 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5834 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5835 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5837 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5838 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5839 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5840 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5841 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5844 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5846 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5848 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5849 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5852 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5853 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5854 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5855 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5857 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5858 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5859 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5860 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5861 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5862 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5863 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5864 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5865 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5866 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5868 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5869 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5870 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5871 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5872 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5873 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5874 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5875 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5877 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5879 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5880 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5881 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5882 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5883 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5884 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5885 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5886 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5888 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5889 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5890 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5891 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5892 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5893 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5894 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5895 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5896 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5897 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5898 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5899 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5900 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5901 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5902 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5903 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5904 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5905 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5906 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5907 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5908 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5909 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5910 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5911 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5912 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5913 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5914 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5915 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5916 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5917 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5918 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5919 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5921 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5923 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5924 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5925 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5927 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5928 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5929 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5931 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5932 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5933 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5934 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5935 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5936 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5937 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5938 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5940 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5941 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5944 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5945 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5946 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5947 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5948 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5950 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5952 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5954 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5955 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5956 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5957 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5958 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5960 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5962 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5963 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5964 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5965 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5967 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5968 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5969 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5970 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5971 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5972 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5973 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5974 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5975 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5976 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5977 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5978 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5979 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5980 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5981 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5982 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5983 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5985 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5986 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5987 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5988 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5989 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5990 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5991 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5992 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5993 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5994 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5995 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5996 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5997 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5998 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5999 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 6000 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 6001 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 6002 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 6003 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 6004 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 6005 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 6006 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1029:

/* Line 690 of lalr1.cc  */
#line 6007 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1030:

/* Line 690 of lalr1.cc  */
#line 6008 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1031:

/* Line 690 of lalr1.cc  */
#line 6009 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1032:

/* Line 690 of lalr1.cc  */
#line 6010 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1033:

/* Line 690 of lalr1.cc  */
#line 6011 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1034:

/* Line 690 of lalr1.cc  */
#line 6012 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1035:

/* Line 690 of lalr1.cc  */
#line 6013 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1036:

/* Line 690 of lalr1.cc  */
#line 6014 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1037:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1038:

/* Line 690 of lalr1.cc  */
#line 6016 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1039:

/* Line 690 of lalr1.cc  */
#line 6017 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1040:

/* Line 690 of lalr1.cc  */
#line 6018 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1041:

/* Line 690 of lalr1.cc  */
#line 6019 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1042:

/* Line 690 of lalr1.cc  */
#line 6020 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("null"))); }
    break;

  case 1043:

/* Line 690 of lalr1.cc  */
#line 6021 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("true"))); }
    break;

  case 1044:

/* Line 690 of lalr1.cc  */
#line 6022 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("false"))); }
    break;

  case 1045:

/* Line 690 of lalr1.cc  */
#line 6023 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("select"))); }
    break;

  case 1046:

/* Line 690 of lalr1.cc  */
#line 6024 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("jsoniq"))); }
    break;

  case 1047:

/* Line 690 of lalr1.cc  */
#line 6027 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12403 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1544;
  const short int
  jsoniq_parser::yypact_[] =
  {
      5520, -1544, -1544, -1544, -1544,  6472,  6472,  6472,  6472, -1544,
   -1544,    33,    41, -1544,  1001,   313, -1544, -1544, -1544,   820,
   -1544, -1544, -1544,   233,   364,   822,  5005,   411,   451,   148,
   -1544,    17, -1544,   589, -1544, -1544, -1544, -1544, -1544,   827,
   -1544,   606,   608, -1544, -1544, -1544, -1544,   458, -1544,   828,
   -1544,   634,   674, -1544,   357, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,   728,
     758, -1544, -1544, -1544, -1544,   698, 14056, -1544, -1544, -1544,
     786, -1544, -1544, -1544,   599, -1544,   852,   857, -1544, -1544,
   18609, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,   802,
   -1544, -1544,   873,   880, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544,  6472,  9000,  9316, 18609, -1544, -1544,   782, -1544, -1544,
   -1544, -1544,   790, -1544, -1544,   884, 18609, -1544, 15287,   896,
     900, -1544, -1544, -1544, -1544,   902, -1544, -1544, 13108, -1544,
   -1544, -1544, -1544, -1544, -1544,   875, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544,   149, -1544,   808, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,   280,   876,
     303, -1544,   -65,   212, -1544, -1544, -1544, -1544, -1544, -1544,
     912, -1544,   788,   789,   785, -1544, -1544,   879,   885, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544,  5232, -1544, 13740, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544,  9632,  9948, -1544,   725, -1544, -1544, -1544, -1544,
   -1544,  5838,  6788,  1047, -1544,  7104, -1544, -1544,   627,    96,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544,   103, -1544, -1544, -1544, -1544, -1544,
   -1544,   405, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
    6472, -1544, -1544, -1544, -1544,   293, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544,   226, -1544,   859, -1544, -1544,
   -1544,   146, -1544,   640, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544,   881,   960, -1544, -1544,  1164,   800,   956,   670,   526,
     323,   529, -1544,  1007,   858,   959,   961, 11212, -1544,   867,
   -1544, -1544,    32, -1544, -1544, 13424, -1544,   769, -1544,   907,
   14056, -1544,   907, 14056, -1544, -1544, -1544,   675, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544,   908, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544,    47, -1544, -1544, -1544, -1544, -1544,   882,
   -1544,  6472,   886,   887,   888,  6472,   639,   639,  1035,   301,
     715,   590, 19209, 18609,    -3,  1022, 18609,   916,   955,   577,
   18609,   772,   823, 18609, 18609,   767,   797,   102, -1544, -1544,
   -1544, 18609,  6472,   890,  6472,    95, 11528, 15589, 18609,   317,
     924, 11528,  1081,   178,   380, 18609,   964,   940,   979, -1544,
     901, 11528, 15891, 18609, 18609, 18609,  6472,   903, 11528, 11528,
   18609,  6472,   933,   935, -1544, -1544, -1544, 11528, 16193,   934,
   -1544,   936, -1544, -1544, -1544, -1544,   937, -1544,   939, -1544,
   -1544, -1544, -1544, -1544,   942, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, 18609, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,   949,
   18609, -1544, -1544,   913,  6156,   978,   294,   981,   944,   947,
     948, 18609,  6472, -1544,   952,   112, -1544,   146, -1544,   113,
    1073, 11528, 11528, -1544,    72, -1544, -1544,  1092, -1544, -1544,
   -1544, -1544, 11528,   894, -1544,  1082, 11528, 11528, 18915, 11528,
   11528, 11528, 11528, 18915, 11528,   874, 18609,   938,   941, 11528,
   11528,  6472,   877, 18609, -1544, -1544,    63, -1544,    66, 11528,
    6788, -1544, -1544, -1544, -1544, -1544,  1001,   148,   119,   150,
    1124,  7420,  3719,  7736,  4046,   599, -1544, -1544,   412,   599,
   -1544, 11528,  4678, -1544,  1012,   796,    17,   963,   965,   966,
   -1544, -1544, 11528,   811, -1544, -1544,  6472, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544,   844,   845, 18609,  1023, 11844, 11844,
   12160, -1544, 12160, 12160, -1544, 12160, -1544, 12160, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, 12160, 12160,  1072, 12160, 12160,
   12160, 12160, 12160, 12160, 12160, 12160, 12160, 12160, 12160, 12160,
     909,  1049,  1052,  1053, -1544, -1544, -1544, 12792,  6472, -1544,
   -1544, 13108, 13108, 11528,   907, -1544, -1544,   907, -1544, 14674,
   10264,  8368,   907,   962,  1000,  8684, -1544, -1544, -1544, -1544,
      23, -1544,    56, -1544, -1544, -1544, -1544, -1544, -1544,  1044,
    1045,   411,  1128, -1544, -1544, 19209,  1036,   711, 18609,   992,
     997,  1036,  1035,  1031,  1027, -1544, -1544, -1544,   157,   910,
    1070,   861, 18609,  1024, 11528,  1050, 18609, 18609, -1544,  1038,
     985, -1544,   989,   936,   608, -1544,   987,   988,   353, -1544,
     281,   315,  1069, -1544,    49, 18609,  1083,   388, -1544,  6472,
   -1544,   124, -1544, 18609,  1085,  1134, 18609,  1035,  1087,    86,
   18609, 11528,    17, -1544,   390,  1002, -1544,  1003,  1004,  1005,
     341, -1544,    88,  1009, -1544,   151,   164,  1033, -1544,  1010,
    6472,  6472,   407, -1544,   433,   452,   550, 11528,   351, -1544,
   -1544, 11528, 11528, -1544, 11528, 11528, 11528, 11528, -1544, 11528,
   -1544, 11528, -1544, 18609,  1073, -1544,    40,   416,   417, -1544,
   -1544, -1544,   420, -1544,    14, -1544, -1544,  1034,  1042,  1048,
    1051,  1054,   675,    47,    21,   467,     3,   133,  1104,   682,
     957,   145,    85, -1544,  1064, -1544, -1544,  1018,   185,  6156,
     421, 14372,   877, -1544,  1069, -1544, -1544,   974, -1544,   627,
     174,  1181,   184, -1544, -1544,   152, -1544, -1544, -1544,   154,
   -1544,    48, -1544, -1544, -1544, -1544, -1544,  4362, -1544, -1544,
   -1544, 18609,  1046, 11528, 12476, -1544, -1544, -1544, -1544, -1544,
    1069, 18609,    34,   960, -1544, -1544, -1544, -1544, -1544, 12160,
   -1544, -1544, -1544,    78, -1544,   526,   526,   579,   323,   323,
     323,   323,   529,   529, -1544, -1544, 17703, 17703, 18609, 18609,
   -1544,  1037, -1544, -1544,   123, -1544, 10580, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544,   478, -1544, -1544, -1544,   491,
     639, -1544, -1544,   601,   710,    45, -1544,   411, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,  1036, -1544,
    1084, 18005,  1076, 11528, -1544, -1544, -1544,  1121,  1035,  1035,
    1036, -1544,   840,  1035,   683, 18609,   554,   597,  1191, -1544,
   -1544,   931,   515, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544,   157,    39,   991,   615, 11528, -1544,
   18609,  1130,   921,  1035, -1544, -1544, -1544, -1544,  1074, 18609,
   -1544, 18609, -1544, 18307,  1099, 17703,  1111, 11528,   104,  1086,
      53,  1121, 17703,  1112,  1137,  1055,  1039,  1100,  1035,  1071,
    1102,  1140,  1035, 11528,    -6, -1544, -1544, -1544,  1088, -1544,
   -1544, -1544, -1544,  1119, 11528, 11528,  1093, -1544,  1143,  1144,
    6472, -1544,  1056,  1061,  1094, 18609, -1544, 18609, -1544, 11528,
    1103,  1058, 11528, -1544,  1129,  1131, -1544,   202,   227,   251,
    1216, -1544,   382, -1544,   241,  1098, -1544, -1544,  1225, -1544,
     718, 11528, 11528, 11528,   756, 11528, 11528, 11528, 11528, 11528,
   11528, 11528, 11528, 11528, 18915,  1138, 11528, 11528, -1544,  8052,
     373,  1008, -1544,   265, -1544, 11528,   175,    81,    48,  7736,
    4046,  7736,  1176, -1544, -1544, 11528,   768,  1150, -1544, 18609,
    1153,  1155, -1544,   372,  1006, -1544, -1544,   732,    34, -1544,
   11528,    78,   629,   298, -1544,   970,   393,  1011,   999, -1544,
   -1544,   823, -1544,   994,   314,  1113,  1114, 16495,  1115,  1116,
    1118,  1120,  1123, -1544,   671, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544,  1133, -1544, -1544, -1544, -1544,
   -1544,   262, 10896, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544,   686, -1544,  1239, 18005,   816, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544,   990, -1544, -1544,  1253,
   -1544, -1544, -1544, -1544, -1544,   646,  1254, -1544,    82, -1544,
   -1544, -1544,   934,   364,   589,   937,   606,   939,   942, -1544,
    1116,  1118,  1120, -1544,   671,   671, 12792,   993,   973, -1544,
    1121,    39,  1057,  1095,  6472,  1101,  1105,  1145,  1107,  1108,
   18609, -1544,   556, -1544, 18609, -1544, 11528,  1148, 11528,  1172,
   11528,   237,  1154, -1544, -1544, -1544, 17703, -1544,  6472,  1035,
    1200, -1544, -1544, -1544,  1035,  1200, -1544, 11528,  1167,  6472,
   18609, -1544, -1544, 11528, 11528,   810, -1544,   276,   813, -1544,
   16797,   821, -1544,   824, -1544,  1135, -1544, -1544,  6472,  1125,
    1126, -1544, 11528, -1544, -1544, 11528, 11528,  1122,  1143,  1215,
   -1544,  1185, -1544,   561, -1544, -1544,  1318, -1544, -1544,  6472,
   18609, -1544,   573, -1544, -1544, -1544,  6472,  1141,  1090,  1096,
   -1544, -1544, -1544,  1097,  1109, -1544, -1544, -1544,  1229, -1544,
   -1544, -1544, -1544,  1089,   331, 18609,   801, -1544,  1169,  1179,
    1180,  1186, -1544,   859,   146, 14372,  1008, -1544,  8052, 14372,
   -1544, -1544,  1181,   472, -1544, -1544, -1544,  1150, -1544,  1035,
   -1544,   872, -1544,   594,  1235, -1544, 11528,   560,  1035, -1544,
   12476, 11528,  1194, -1544,  1228,  1230, 11528, 18609,   898,  1273,
   -1544, -1544, -1544,   423,  1165, -1544,    78,  1127, -1544, -1544,
     -42, -1544,   680,    57,  1132,    78,   680, 12160, -1544,   167,
   -1544, -1544, -1544, -1544, -1544, -1544,    78,  1207,  1075,   910,
      57, -1544, -1544,  1065,  1279, -1544, -1544, -1544, 14976,  1171,
   -1544,  1173,  1187,  1188,  1189,  1192,  1197, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544,  1330,    19,  1334,    19,  1110,  1271, -1544, -1544,  1211,
   18609,  1136, -1544, -1544, 12792, -1544,  1201, -1544, -1544, -1544,
   -1544, -1544, -1544, 11528,  1240, -1544, -1544, 11528, -1544,   588,
   -1544, 11528,  1241, 11528, -1544,  1267,  1269,  1301,  1035,  1200,
   -1544, 11528,  1217, -1544, -1544, -1544,   801, -1544,   276, 11528,
    6472,   801,   276, -1544, 18609,   706, -1544, 17099,   584, -1544,
   17401,   801, -1544, -1544,  1219, -1544, -1544, -1544, -1544, -1544,
   11528,   825,  1216, 18609,   586, -1544,  1220,  1216, 18609, -1544,
    1221, -1544, 11528, 11528, 11528, 11528,  1078, 11528, 11528, -1544,
   11528, 11528, 11528, 11528,  8052,   503, -1544, -1544, -1544, -1544,
   -1544,  1235, -1544, -1544, -1544, 11528,  1257, -1544, -1544, -1544,
   11528, 18609, 18609, -1544,   795, -1544, 11528, -1544, -1544, -1544,
    1222, 12160, -1544, -1544, -1544, -1544, -1544,   118, 12160, 12160,
     493, -1544,  1011, -1544,   427, -1544,   999,    78,  1256, -1544,
   -1544,  1139, -1544, -1544, -1544, -1544,  1313,  1224, -1544,   507,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,   522,   522,
   -1544,    19, -1544, -1544,   508, -1544,  1379,    18,  1316,  1226,
   12792,    -7,  1142,  1244, -1544, -1544, 11528, -1544, 11528,  1268,
   -1544, 11528, -1544,  8052, 11528,  1035, -1544, -1544, -1544, 11528,
   11528, -1544, -1544, -1544,  8052,  8052,  1321, 17703,  6472, 18609,
     706, 18609, 11528, 18609,   706,  8052, -1544,   591,    51,  1216,
   18609, -1544,  1223,  1216, -1544, -1544, -1544, -1544, -1544, 11528,
   -1544, -1544, -1544,   267,   285,   286, 11528, -1544, -1544,  1153,
   11528, -1544, -1544,  1364, -1544, -1544, -1544,   323, 12160, 12160,
     579,   731, -1544, -1544, -1544, -1544, -1544, -1544, 11528, -1544,
   17703, -1544, 17703,  1324, -1544, -1544, -1544,  1390, -1544, -1544,
   -1544,  1152,  1319, -1544, -1544,  1320, -1544,   568, 18609,  1302,
    1198, 18609, 12792, -1544, -1544, 11528, -1544, -1544, -1544,  1200,
   -1544, -1544, 17703, -1544, -1544, -1544,  1335, 11528,   801, -1544,
    1336,  8052, -1544, 18609,   673,   617, -1544,  1233,  1216, -1544,
    1234, -1544,  1236,  1143,  1144,   429, -1544,  1153,  1315,   579,
     579, 12160,   457, -1544, -1544, 17703, -1544, -1544,  1316, 12792,
   -1544,  1235,  1146, 18609,  1322,  1206,  1320, -1544,   706, 17703,
    6472, 17703,   801, -1544, -1544,  1345,   684, -1544, -1544, -1544,
   -1544,  1258,   688, -1544, -1544, -1544,  1245, -1544,  8052,   839,
   -1544, -1544, 18609,   579, -1544, -1544, -1544, -1544, -1544, 11528,
    1156, 18609,  1327,  6472,   706, -1544, -1544,   706, 11528, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544,  1328, -1544, -1544,  1149,
    1157, 18609, -1544, -1544, 11528,  8052, 18609,  1147, 11528,  1151,
     801, 12792, -1544, 12792,  8052, -1544,  1242,  1161, 18609,  1209,
    1331, 18609,  1158, 12792, -1544
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       165,   473,   474,   819,   475,   168,   168,   168,     0,   842,
    1047,   120,   122,   648,   935,   944,   884,   847,   845,   821,
     936,   939,   891,   851,   822,   824,     0,   945,   826,   942,
     913,   893,   867,   823,   888,   889,   940,   937,   887,   828,
     943,   829,   830,   984,   996,   983,   885,   904,   898,   831,
     886,   833,   832,   985,   922,   923,   890,   864,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1030,
    1037,   912,   908,   899,   878,   820,     0,   907,   915,   924,
    1031,   903,   506,   879,   880,   938,  1032,  1038,   900,   917,
       0,   512,   462,   508,   910,   844,   901,   902,   931,   905,
     921,   930,  1036,  1039,   850,   892,   933,   507,   920,   926,
     825,   168,     0,     0,     0,   409,   918,   929,   934,   932,
     911,   897,   986,   895,   896,  1033,     0,   408,     0,  1034,
    1040,   927,   881,   906,  1045,  1035,   211,   440,     0,   472,
     928,   909,   916,   925,   919,   987,   872,   877,   876,   875,
     874,   873,   834,   894,     0,   843,  1046,   941,   865,  1042,
    1043,  1044,   977,   976,   978,   849,   848,   868,   975,   827,
     972,   980,   974,   973,   871,   914,   970,   982,   981,   969,
     869,   979,   991,   992,   989,   990,   988,   835,   993,   994,
     995,   961,   960,   947,   863,   856,   954,   950,   866,   862,
     962,     0,   852,   853,   846,   855,   959,   958,   955,   951,
     967,   968,   966,   957,   953,   946,   854,   965,   964,   858,
     860,   859,   952,   956,   948,   861,   949,   857,   963,  1017,
    1018,  1019,  1020,  1021,  1022,   998,   999,   997,  1003,  1004,
    1005,  1000,  1001,  1002,   870,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,     0,     0,   836,   971,  1041,   838,   837,   839,
     840,   165,   165,     0,     2,   165,     9,    11,    23,     0,
      28,    31,    36,    37,    38,    39,    40,    41,    42,    32,
      58,    59,    33,    34,     0,    76,    79,    80,    35,    81,
      82,     0,   118,    83,    84,    85,    86,    18,   162,   163,
     164,   171,   174,   499,   175,     0,   176,   177,   178,   179,
     180,   181,   182,   185,   186,     0,   212,   220,   215,   249,
     255,     0,   247,     0,   248,   222,   216,   184,   217,   183,
     218,   221,   358,   360,   362,   364,   374,   376,   380,   382,
     385,   390,   393,   396,   398,   400,   402,     0,   406,   413,
     412,   414,     0,   431,   415,   436,   439,   441,   444,   446,
       0,   451,   448,     0,   459,   469,   471,   445,   476,   490,
     504,   491,   492,   493,   496,   497,   494,   498,   521,   522,
     495,   525,   527,   528,   529,   526,   574,   575,   576,   577,
     578,   579,   580,   468,   620,     0,   611,   619,   618,   617,
     616,   613,   615,   612,   614,   505,    43,   223,   224,   226,
     225,   227,   219,   501,   502,   503,   500,   229,   232,   228,
     230,   231,   470,   818,   841,   935,   944,   942,  1046,     0,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   280,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   464,   467,   454,     0,     0,   821,
     851,   824,   882,   945,   826,   893,   828,   904,   831,   833,
     832,   922,  1030,  1037,   820,  1031,   880,  1032,  1038,   905,
    1036,  1039,   929,   986,  1033,  1034,  1040,  1035,   987,   975,
     972,   974,   973,   869,   991,   992,   989,   835,   993,   883,
     853,   971,   460,   818,   452,     0,   192,   453,   456,   821,
     822,   824,   823,   828,   829,   830,   831,   820,   827,   509,
       0,   458,   457,     0,     0,   212,     0,   470,   826,   833,
     832,     0,   168,   796,   993,     0,   220,     0,   510,     0,
     541,     0,     0,   463,     0,   434,   435,     0,   466,   465,
     455,   438,     0,     0,   570,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   363,   798,     0,   800,     0,     0,
     165,     3,     4,     1,    10,    12,     0,     0,     0,     0,
       6,   165,     0,   165,     0,     0,   119,   172,     0,     0,
     190,     0,     0,   199,     0,     0,     0,     0,     0,     0,
     235,   236,     0,     0,   204,   233,     0,   254,   250,   256,
     251,   253,   252,   260,     0,     0,     0,     0,     0,     0,
       0,   425,     0,     0,   423,     0,   369,     0,   424,   417,
     422,   421,   420,   419,   418,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   411,   410,   407,     0,   168,   432,
     437,     0,     0,     0,   447,   487,   450,   449,   461,     0,
       0,     0,   477,     0,     0,     0,   582,   584,   588,   590,
       0,   124,     0,   817,    47,    44,    45,    48,    49,     0,
       0,     0,     0,    50,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   655,   656,   657,     0,   103,
     142,     0,     0,   112,     0,     0,     0,     0,   127,     0,
       0,   628,     0,     0,     0,   623,     0,     0,     0,   638,
       0,     0,   258,   263,     0,     0,   134,     0,   138,   168,
     524,     0,    60,     0,    69,     0,     0,     0,    61,     0,
       0,     0,     0,   626,     0,     0,   629,     0,     0,     0,
       0,   329,     0,     0,   627,     0,     0,     0,   646,     0,
       0,     0,     0,   632,     0,     0,   194,     0,     0,   188,
     187,     0,     0,   802,     0,     0,     0,     0,   509,     0,
     797,     0,   511,   542,   541,   538,     0,     0,     0,   572,
     571,   433,     0,   569,     0,   668,   669,     0,     0,     0,
       0,     0,   811,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   674,     0,   202,   203,     0,     0,     0,
       0,     0,   207,   208,   259,   799,   801,     0,     5,    24,
       0,    25,     0,     7,    29,     0,    15,     8,    30,     0,
      19,   935,    77,    16,    78,    20,   193,     0,   191,   213,
     214,     0,     0,     0,     0,   298,   205,   234,   237,   238,
     257,     0,     0,   359,   361,   367,   373,   372,   371,     0,
     368,   365,   366,     0,   377,   384,   383,   381,   387,   388,
     389,   386,   391,   392,   395,   394,     0,     0,     0,     0,
     416,     0,   442,   443,     0,   488,     0,   484,   485,   486,
     481,   480,   517,   478,   519,     0,   621,   523,   515,     0,
       0,   121,   123,     0,     0,     0,   102,     0,    92,    94,
      95,    96,    97,    99,   100,   101,    93,    98,    88,    89,
       0,     0,   108,     0,   104,   106,   107,   114,     0,     0,
      87,    46,     0,     0,     0,     0,     0,     0,     0,   746,
     751,     0,     0,   747,   781,   734,   736,   737,   738,   740,
     742,   741,   739,   743,     0,     0,     0,     0,     0,   111,
       0,   144,     0,     0,   587,   581,   624,   625,     0,     0,
     642,     0,   639,     0,     0,     0,     0,     0,     0,     0,
       0,   140,     0,     0,   135,     0,     0,     0,     0,     0,
       0,    62,     0,     0,     0,   279,   285,   282,     0,   631,
     630,   637,   645,     0,     0,     0,     0,   586,     0,     0,
       0,   426,     0,     0,     0,     0,   635,     0,   633,     0,
     195,     0,     0,   804,     0,   470,   803,     0,     0,     0,
     541,   539,     0,   530,     0,     0,   513,   514,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,     0,   682,     0,   209,     0,     0,     0,     0,   165,
       0,   165,     0,   173,   246,     0,   313,   309,   311,     0,
     306,   299,   300,     0,     0,   239,   240,     0,   245,   370,
       0,     0,     0,     0,   712,   378,   685,   689,   691,   693,
     695,   698,   705,   706,   714,   945,   825,     0,   834,   838,
     837,   839,   840,   397,   593,   600,   601,   604,   649,   650,
     605,   606,   609,   399,   401,   404,   610,   403,   430,   489,
     482,     0,     0,   479,   516,   125,    56,    57,    54,    55,
     131,   130,     0,    90,     0,     0,     0,   109,   110,   115,
      74,    75,    52,    53,    73,   752,     0,   755,   782,     0,
     745,   744,   749,   748,   780,     0,     0,   757,     0,   753,
     756,   735,     0,     0,     0,     0,     0,     0,     0,   622,
       0,     0,     0,   143,   146,   148,     0,     0,     0,   113,
     116,     0,     0,     0,   168,     0,     0,   646,     0,     0,
       0,   265,     0,   592,     0,   266,     0,     0,     0,     0,
       0,     0,     0,   141,   136,   139,     0,   189,     0,     0,
      71,    65,    68,    67,     0,    63,   283,     0,     0,   168,
       0,   327,   331,     0,     0,     0,   334,     0,     0,   340,
       0,     0,   347,     0,   351,     0,   428,   427,   168,     0,
       0,   196,     0,   198,   328,     0,     0,     0,     0,     0,
     542,     0,   532,     0,   565,   562,     0,   566,   567,     0,
       0,   561,     0,   536,   564,   563,     0,     0,     0,     0,
     661,   662,   658,     0,     0,   666,   667,   663,   807,   808,
     672,   812,   670,     0,     0,     0,     0,   676,   826,   833,
     832,   993,   201,     0,     0,     0,   677,   678,     0,     0,
     210,   810,    26,     0,    17,    21,    22,   310,   322,     0,
     323,     0,   314,   315,   316,   317,     0,   509,     0,   307,
       0,     0,     0,   241,     0,     0,     0,     0,   292,     0,
     289,   294,   244,     0,     0,   696,   709,     0,   375,   379,
       0,   728,     0,     0,     0,     0,     0,     0,   684,   686,
     687,   723,   724,   725,   727,   726,     0,     0,   700,   699,
       0,   703,   707,   721,   719,   718,   711,   715,     0,     0,
     596,     0,     0,     0,     0,     0,     0,   597,   599,   598,
     594,   405,   483,   518,   520,   133,   132,    91,   105,   769,
     750,     0,   774,     0,   774,   763,   758,   147,   149,     0,
       0,     0,   117,   145,     0,    27,     0,   643,   644,   647,
     640,   641,   264,     0,     0,   278,   270,     0,   274,     0,
     268,     0,     0,     0,   137,     0,     0,    70,     0,    64,
     284,     0,     0,   330,   332,   337,     0,   335,     0,     0,
       0,     0,     0,   341,     0,     0,   355,     0,     0,   348,
       0,     0,   352,   429,     0,   636,   634,   197,   805,   806,
       0,     0,   541,     0,     0,   573,     0,   541,     0,   537,
       0,    14,     0,     0,     0,     0,     0,     0,     0,   675,
       0,     0,     0,     0,     0,     0,   679,   683,   326,   324,
     325,   318,   319,   320,   312,     0,     0,   308,   301,   287,
       0,     0,     0,   243,   290,   293,     0,   713,   704,   710,
       0,     0,   783,   784,   794,   793,   792,     0,     0,     0,
       0,   785,   690,   791,     0,   688,   692,     0,     0,   697,
     701,     0,   722,   717,   720,   716,     0,     0,   607,     0,
     602,   654,   595,   816,   815,   814,   603,   770,     0,     0,
     768,   775,   776,   772,     0,   767,     0,   765,     0,     0,
       0,     0,     0,     0,   583,   267,     0,   276,     0,     0,
     272,     0,   275,     0,     0,     0,    66,   286,   589,     0,
       0,   338,   342,   336,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   585,     0,     0,   541,
       0,   568,     0,   541,   591,   659,   660,   664,   665,     0,
     671,   813,   673,     0,     0,     0,     0,   680,   321,   302,
       0,   288,   296,   297,   291,   242,   708,   795,     0,     0,
     787,     0,   733,   732,   731,   730,   729,   694,     0,   786,
       0,   651,     0,     0,   779,   778,   777,     0,   771,   764,
     762,     0,   759,   760,   754,   150,   152,   154,     0,     0,
       0,     0,     0,   271,   269,     0,   277,   206,   357,    72,
     333,   339,     0,   356,   353,   349,     0,     0,     0,   343,
       0,     0,   345,     0,   551,   545,   540,     0,   541,   531,
       0,   809,     0,     0,     0,     0,   305,   303,     0,   789,
     788,     0,     0,   652,   608,     0,   773,   766,     0,     0,
     156,   155,     0,     0,     0,     0,   151,   273,     0,     0,
       0,     0,     0,   559,   553,     0,   552,   554,   560,   557,
     547,     0,   546,   548,   558,   533,     0,   534,     0,     0,
     681,   304,     0,   790,   702,   653,   761,   153,   157,     0,
       0,     0,     0,     0,     0,   346,   344,     0,     0,   544,
     555,   556,   543,   549,   550,   535,     0,   295,   158,     0,
       0,     0,   354,   350,     0,     0,     0,     0,     0,     0,
       0,     0,   160,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1544, -1544,  -231,  -201, -1544,  1190,  1196, -1544,  1204,  -559,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1025, -1544, -1544, -1544, -1544,  -227,  -589, -1544,   705,   -69,
   -1544, -1544, -1544, -1544, -1544,   249,   477, -1544, -1544,    11,
    -182,  1040, -1544,  1017, -1544, -1544,  -660, -1544,   422, -1544,
     215, -1544,  -263,  -309, -1544,  -583, -1544,    13,   127,     6,
    -272,  -184, -1544,  -898, -1544, -1544,   334, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544,   602, -1544,  -110,
    1896,     0, -1544, -1544,  -320, -1544, -1544,   325, -1544, -1544,
    -306, -1544,    16, -1544, -1544,  -120,  -957,  -745,  -726, -1544,
   -1544,   679, -1544, -1544,   -99,    79, -1544, -1544, -1544,    90,
   -1543, -1544,   343,    97, -1544, -1544,    93, -1331, -1544,   932,
     191, -1544, -1544,   189, -1042, -1544, -1544,   187, -1544, -1544,
   -1270, -1265, -1544,   183, -1448, -1544, -1544,   829,  -146, -1544,
   -1544,  -579,   812, -1544, -1544,  -665,   316,  -663,   318,   312,
   -1544, -1544, -1544,   549, -1544, -1544,  1160, -1544, -1544, -1544,
   -1544, -1544,  -877,  -318,  -690, -1544,   -73, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544,    -5,  -826, -1544,  -551,   633,   229,
   -1544,  -427, -1544,   780, -1544,   783, -1544, -1544, -1544,   776,
   -1544, -1544, -1544, -1544, -1034, -1544,   170, -1544,   661,  -809,
   -1544, -1544, -1544, -1544, -1544,  -304,  -297, -1254,  -906, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
    -772,  -904,  -242,  -888, -1544, -1544, -1544,  -778, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544,  1059,  1060,  -197,
     469,  -653, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
   -1544, -1544, -1544,   147, -1544, -1544,   135, -1544,   138, -1087,
   -1544, -1544, -1544,    91,    83,   -92,   356, -1544, -1544, -1544,
   -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544, -1544,
      92, -1544, -1544, -1544,   -82,   352,   502, -1544, -1544, -1544,
   -1544, -1544,   289, -1544, -1544, -1419, -1544, -1544, -1544,  -610,
   -1544,    58, -1544,  -101, -1544, -1544, -1544, -1544, -1340, -1544,
     105, -1544, -1544, -1544, -1544, -1544,   943, -1544, -1544, -1544,
   -1544, -1544,  -938,  -405,  1439,   419, -1544
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   263,   642,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
    1290,   797,   281,   282,   283,   284,   285,   286,   988,   989,
     990,   287,   288,   289,   994,   995,   996,   290,   456,   291,
     292,   730,   293,   458,   459,   460,   470,   787,   788,   294,
    1253,   295,  1735,  1736,   296,   297,   298,   563,   299,   300,
     301,   302,   303,   790,   304,   305,   546,   306,   307,   308,
     309,   310,   311,   654,   312,   313,   882,   883,   314,   315,
     316,   576,   318,   655,  1672,   667,  1157,  1158,   319,   657,
     320,   659,   577,   322,   323,   782,   783,  1408,   477,   324,
     478,   479,   922,  1409,  1410,  1411,   660,   661,  1151,  1152,
    1399,   662,  1147,  1148,  1392,  1393,  1394,  1395,   325,   810,
     811,   326,  1305,  1306,  1518,   327,  1308,  1309,   328,   329,
    1311,  1312,  1313,  1314,  1525,   330,   331,   332,   333,   334,
     929,   335,   336,  1418,   337,   338,   339,   340,   341,   342,
     343,   344,   345,  1194,   346,   347,   348,   349,   685,   686,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   722,   715,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   965,
     377,   378,   379,   380,   381,   382,  1342,   844,   845,   846,
    1766,  1811,  1812,  1805,  1806,  1813,  1807,  1343,  1344,   383,
     384,  1345,   385,   386,   387,   388,   389,   390,   391,   392,
    1050,  1526,  1460,  1184,  1619,  1185,  1195,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   817,
    1266,   405,  1187,  1188,  1189,  1190,   406,   407,   408,   409,
     410,   411,   872,   873,   412,  1376,  1377,  1697,  1133,  1165,
    1428,  1429,  1166,  1167,  1168,  1169,  1170,  1438,  1609,  1610,
    1171,  1441,  1172,  1590,  1173,  1174,  1446,  1447,  1615,  1613,
    1430,  1431,  1432,  1433,  1715,   759,  1015,  1016,  1017,  1018,
    1019,  1020,  1239,  1639,  1732,  1240,  1637,  1730,  1021,  1474,
    1634,  1630,  1631,  1632,  1022,  1023,  1434,  1442,  1600,  1435,
    1596,  1419,   413,   414,   415,   416,   566,   417,   418,   419,
     420,   421,  1191,  1291,   422,   423,   424
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -884;
  const short int
  jsoniq_parser::yytable_[] =
  {
       317,   656,   575,   579,   612,   317,   317,   317,   317,   731,
     731,   431,   431,   431,   435,   658,   321,   950,   429,   432,
     433,   321,   321,   321,   321,   457,   937,  1064,   637,   938,
     939,   940,   941,   734,   709,  1102,  1307,  1295,   632,  1048,
    1076,   629,  1183,  1193,   902,   904,  1529,   862,   896,   900,
     903,   905,   869,   634,  1090,  1132,  1163,   614,  1049,  1541,
     621,   622,  1572,  1573,   630,   591,   959,   630,   794,   798,
    1341,   542,   894,   898,  1414,    11,    12,  1211,  1242,  1670,
     849,   975,  1674,  1243,   773,  1044,  1271,  1255,  1549,  1279,
    1154,   925,  1244,   926,   927,   442,   928,   630,   930,  1245,
    1611,  1246,   774,  1216,   630,   443,   931,   932,    13,   636,
    1247,   317,  1738,   630,   630,  1597,  1110,   564,   438,   439,
     630,   440,   441,   445,   630,   630,   831,   321,   446,    11,
      12,   970,   430,   430,   430,   434,   475,  1248,  1297,   444,
     773,  1273,   616,   618,  1045,  1764,  1046,  1108,  1284,   442,
    1046,   630,   630,   630,  1597,   630,  1776,  1628,   774,   637,
     447,   448,  1142,   637,   970,   630,   602,   743,  1186,  1186,
    1708,   641,  1103,   472,   641,   897,   630,   445,  1592,  1236,
     593,  1045,   473,  1045,  1210,   897,   630,   708,   644,    82,
     638,   436,   645,  1125,   724,  1383,  1237,   646,  1047,   437,
     789,   744,  1280,   630,    93,   725,  1109,  1137,   733,   474,
     128,   971,  1004,  1186,  1005,   765,   647,  1138,  1593,  1733,
     641,   641,  1629,   627,  1739,  1219,  -169,   630,   630,   107,
    1063,   641,   641,  1160,  1821,  1765,  1161,  1075,   430,  1104,
    1698,   832,  1118,   450,   972,  1111,  1112,  1254,   850,  1709,
    1334,  1335,   630,  1276,  1155,   603,   128,   841,  1006,   641,
    1113,   317,   317,   630,  1420,   317,  1522,  1186,   630,  1509,
    1249,   658,   641,   476,  1186,   636,  1529,   321,   321,  1283,
    1598,   321,   710,   775,  1163,  1163,   630,   630,   631,  1451,
    1549,  1331,   637,   641,  1156,   633,   476,  1731,   840,  1341,
     317,   842,   902,   904,  1798,  1281,  1740,   451,  1341,  1199,
     641,   889,  1056,  1492,  1466,   648,   321,  1212,   649,  1598,
    1599,   638,  1277,  1255,  1282,   638,  1126,  1451,   476,  1589,
     894,   898,   476,   650,   641,   641,   651,  1421,  1298,  1078,
     793,   453,   891,  1162,  1139,  1336,  1141,  1001,   452,   454,
    1159,  1834,  1079,  1837,   630,   716,   778,   455,   718,   641,
     652,   791,  1250,  1251,  1252,   594,  1337,  1382,  1338,  1826,
     641,   804,  1119,  1129,   630,   641,  1123,  1519,   815,   816,
     885,  1402,  1504,   476,   916,   886,  1501,   822,   464,  1039,
    1327,   630,  1061,   641,   641,   766,  1339,   890,   892,  1186,
     114,   639,   832,   767,   895,   899,  1790,   907,   630,   653,
     733,  -169,  -170,   630,  1007,  1328,   126,   630,   630,   888,
    1378,   630,   630,  1041,   630,  1422,  1423,  1008,  1424,  1009,
     630,   317,    11,    12,   490,   317,   785,  1186,  1340,  1329,
    1010,  1011,  1012,   604,  1013,  1426,  1014,   321,   605,  1073,
    1462,   321,   719,  1416,   638,  1772,   154,  1427,   630,  1073,
    1828,   641,   317,   650,   317,  1124,   651,  1045,   435,  1040,
     435,   847,   848,  1773,  1774,   461,   128,  1379,   321,   833,
     321,   641,   852,  1254,   735,   640,   317,   720,  1482,   721,
    1420,   317,   435,   884,   795,   543,  1053,   435,   641,   736,
     878,   880,   321,  1042,  1819,   786,  1164,   321,  1186,   543,
    1341,   596,   491,   597,  1332,   641,   476,   749,   635,   750,
     641,  1401,   465,   924,   641,   641,   696,  1494,   641,   641,
    1074,   641,  1186,   543,   599,   697,   600,   641,  1038,  1163,
    1092,  1085,   796,  1205,  1618,   543,   920,   543,  1163,  1132,
     902,   904,   902,  1567,  1529,  1502,  1384,  1385,  1386,  1163,
    1087,  1467,  1114,  1421,   317,   641,  1479,  1443,  1444,   469,
    1334,  1335,   317,  1364,  1558,  1068,  1054,   485,   431,   752,
     321,  1333,  1334,  1335,   492,   493,  1202,   689,   321,   770,
    1445,   772,  1084,  1220,  1221,  1334,  1335,  -170,  1224,  1202,
     598,  1105,  1106,   954,   690,  1107,  1131,   637,  1587,   471,
     954,   317,  1236,   813,  1820,  1722,  1727,   879,   819,  1471,
     317,  1086,   749,   601,   750,  1576,  1334,   321,  1263,  1237,
    1749,   317,   317,   317,   317,  1143,   321,   457,   952,   953,
    1088,   753,  1824,   663,   692,  1045,  1809,   321,   321,   321,
     321,  1422,  1423,  1046,  1424,  1045,   317,   751,  1696,    13,
     626,  1425,  1136,  1045,  1140,  1336,  1203,   698,   892,    13,
    1186,  1426,   321,  1238,   693,  1389,   627,  1336,  1803,  1204,
    1473,   699,  1334,  1427,   752,  1046,  1337,   694,  1338,  1803,
    1336,  1115,  1116,  1334,  1089,  1723,  1728,  1334,  1337,   430,
    1338,  1389,  1712,  1671,  1575,  1493,  1117,   664,   317,  1713,
    1763,  1337,   665,  1338,   431,  1379,  1339,  1809,   545,  1714,
     114,   951,   695,  1391,   321,  1097,  1098,  1099,  1339,   880,
    1163,  1522,   114,  1678,  1164,  1164,   126,  1648,  1682,   689,
      82,  1339,  1337,  1471,  1338,   114,   753,   480,   126,  1186,
      82,  1206,  1186,  1810,  1649,    93,   690,   739,  1543,   666,
    1472,   126,  1604,  1753,   483,    93,   484,  1207,  1712,  1130,
    1548,   650,  1339,   740,   651,  1713,   154,  1121,   650,   543,
     107,   651,   543,  1680,  1160,  1714,  1404,  1161,   154,   317,
     107,  1405,   488,   902,  1643,   431,   719,   468,  1337,  -261,
    1338,   154,  1055,   719,  1473,   321,   991,   128,  1804,  1337,
    1406,  1338,   613,  1337,  -262,  1338,  1783,  1457,  1784,  1840,
     317,   317,   496,  1230,  1843,  1465,   435,   435,  1339,  1046,
     689,   720,   489,   721,  1231,   430,   321,   321,   720,  1339,
     721,   789,  1265,  1339,  1268,   709,  1201,   690,  1458,  1404,
     992,  1407,   494,   497,  1405,   993,   498,  1372,  1808,  1814,
    1208,   741,   543,  -261,  1388,   543,  1232,  1459,  -261,   543,
    1767,   691,   543,   543,  1770,  1389,  1209,  1233,  -262,   317,
     543,  1825,   495,  -262,  1507,  1390,   543,   543,  1319,  1186,
    1320,   689,  1046,   650,   543,   321,   651,  1391,   737,   907,
    1808,   543,   543,   543,   543,   892,  1814,   317,   690,   543,
     544,  1304,   457,   738,  1304,  -261,   430,   543,  1667,  1213,
    1257,   560,  1527,   321,  1516,  1530,  1527,  1521,  1707,  1258,
    -262,  1213,  1781,  1710,  1711,  1528,   763,   581,  1531,  1677,
    1527,   764,  1186,   955,  1186,   582,   955,  1082,  1083,  1380,
    1737,   955,  1404,  1846,  1594,   992,  1348,  1405,  1349,  1816,
     993,  1595,   711,   712,   543,  1791,  1225,  1226,  1227,   906,
    1222,  1223,  1228,   908,  1186,   462,   547,   466,   463,   543,
     467,   548,   481,   486,  1568,   482,   487,  1520,   650,  1164,
     543,   651,   714,  1577,  1353,   717,  1354,   561,  1164,   755,
     756,   757,  1569,  1570,   562,   935,   936,  1186,   583,  1164,
     944,   945,  1477,  1478,   942,   943,  1505,   863,  1724,  1725,
     588,  1186,   863,  1186,   589,   543,   590,   595,    11,    12,
     592,   606,   543,   609,  -622,   607,   608,   610,   438,   439,
     611,   440,   441,  1779,  1780,   619,  1560,   623,   442,   668,
    1413,   643,  1737,   669,  1564,   687,   688,   700,   443,   444,
     701,   702,   707,   713,   703,   733,   723,   726,   658,   745,
     747,   727,   728,   729,   748,   758,   445,   762,   771,   789,
     317,   446,   792,   800,   801,   543,   435,   802,   820,   803,
     821,   814,   463,   827,   467,   482,   321,   487,   829,  1737,
     498,   831,   835,  1656,   834,   836,   837,   839,   843,   851,
     853,   871,   854,   447,   448,   449,  1823,   978,   979,   980,
     981,   982,   983,   984,   985,   986,   987,   893,   881,  1373,
     875,   911,   912,   876,   918,   919,   913,   914,   543,   317,
     317,   317,   921,   933,   947,  1374,   946,   948,   949,   457,
     966,   967,   973,   974,   998,   321,   321,   321,   976,   999,
    1002,  1003,  1024,   450,   977,  1025,  1026,   543,  1028,  1030,
    1034,  1865,  1033,  1866,  1035,  1036,  1037,  1043,  1052,  1059,
    1164,   543,  1058,  1874,  1062,   543,   543,   612,  1080,   462,
    1069,  1070,  1071,  1072,  1077,  1081,  1659,   466,  1660,  1120,
    1122,  1664,  1665,   481,   543,  1668,   486,  1315,  1127,   497,
    1128,  1675,   543,  1135,  1138,   543,  1045,  1145,  1214,   543,
     993,  1234,  1198,  1235,  1256,  1261,  1262,   451,  1272,  1264,
    1274,   785,  1286,  1292,  1289,  1278,  1293,  1294,  1300,  1288,
    1287,  1316,  1303,  1299,  1304,  1310,  1317,  1322,  1662,  1318,
    1323,  1330,  1325,  1346,  1326,  1347,   751,  1365,  1396,  1375,
    1398,  1417,   543,  1400,   317,  1437,  1403,  1440,   452,    13,
     431,  1448,  1449,  1452,  1453,  1436,  1454,  1486,  1455,  1461,
     321,  1456,  1469,  1470,  1475,  1481,  1480,  1485,   317,  1487,
    1484,  1489,   916,  1488,   453,  1490,  1491,  1497,   670,   317,
     543,  1499,   454,  1503,   321,   431,   671,   672,  1508,   673,
     455,  1511,  1512,  1535,  1536,   321,  1527,   674,   317,  1542,
    1533,   675,  1540,   676,   431,  1545,  1556,  1561,   677,  1552,
     543,  1534,  1557,  1551,   321,  1553,  1554,  1562,  1563,   317,
     543,  1378,  1389,  1580,   678,   435,   317,  1581,  1555,  1582,
    1757,  1586,   435,  1588,  1761,   321,  1607,  1612,  1614,  1620,
    1627,  1621,   321,  1608,  1633,   543,   543,   543,   543,   679,
     680,   681,   682,   683,   684,  1622,  1623,  1624,  1373,  1638,
    1625,  1747,  1640,  1591,   879,  1626,  1644,  1636,  1601,  1646,
    1651,   430,  1751,  1662,  1374,  1653,  1754,  1654,  1655,  1642,
    1689,  1700,  1658,  1762,  1676,  1681,  1684,  1706,  1720,  1729,
     543,  1718,  1721,  1236,  1734,  1742,  1752,  1745,  1778,  1785,
    1786,  1793,  1769,  1787,   543,  1719,   430,  1788,  1789,  1794,
    1799,  1801,  1815,  1817,  1822,  1741,  1818,  1832,  1800,  1839,
    1870,  1831,  1842,  1867,  1845,   430,  1851,  1856,  1857,   543,
    1871,  1693,  1694,  1695,  1868,   624,  1000,  1829,   543,  1861,
     543,   625,   543,  1863,   543,  1468,  1546,  1849,  1858,  1217,
    1873,   543,   628,  1550,   768,  1285,  1483,   732,  1833,  1796,
    1827,  1067,  1838,  1412,  1134,  1704,  1571,  1585,  1387,  1754,
    1578,  1513,   828,  1574,  1517,  1523,  1532,   923,  1197,   957,
     934,   969,   958,  1544,   543,  1101,   543,   706,  1844,  1841,
    1269,  1566,  1559,  1565,  1854,  1717,  1602,  1855,  1415,  1606,
     317,  1605,  1716,  1439,   776,   777,  1241,  1476,  1835,   559,
    1726,  1603,  1635,     0,     0,     0,   321,     0,     0,     0,
    1864,     0,     0,   863,   867,     0,  1505,     0,     0,     0,
     567,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,  1852,     0,     0,  1373,   584,     0,   587,   543,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1374,     0,     0,  1852,     0,     0,  1775,     0,     0,     0,
       0,     0,  1835,     0,     0,     0,   543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1782,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1373,  1373,     0,     0,   317,  1374,
       0,     0,     0,     0,     0,  1373,     0,     0,     0,     0,
    1374,  1374,     0,     0,   321,     0,     0,     0,     0,   543,
       0,  1374,     0,   543,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   543,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   543,
       0,  1373,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1374,     0,     0,
       0,     0,     0,     0,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   543,     0,     0,     0,   543,     0,
     317,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   321,     0,  1373,     0,
       0,     0,     0,     0,     0,     0,   543,     0,     0,     0,
       0,     0,     0,   317,  1374,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   321,
       0,     0,     0,     0,     0,  1373,     0,     0,     0,     0,
       0,     0,     0,     0,  1373,     0,     0,   543,     0,     0,
       0,  1374,     0,     0,     0,     0,     0,     0,     0,     0,
    1374,     0,   742,     0,     0,   746,     0,     0,     0,   754,
       0,     0,   760,   761,     0,     0,     0,     0,     0,   543,
     769,     0,     0,     0,     0,     0,   781,   784,     0,     0,
       0,     0,     0,     0,   799,     0,     0,     0,     0,     0,
       0,   807,   808,   809,   812,     0,     0,     0,     0,   818,
       0,     0,     0,     0,     0,     0,     0,   825,     0,     0,
       0,     0,     0,   543,     0,     0,   543,     0,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   543,     0,     0,     0,     0,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   826,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   812,
     543,   543,     0,     0,     0,     0,     0,   565,     0,     0,
     838,   567,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     567,     0,     0,     0,     0,   874,     0,     0,     0,     0,
       0,     0,   784,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   543,     0,   543,     0,
     543,     0,   543,     0,     0,     0,     0,     0,     0,   543,
       0,     0,     0,     0,     0,   784,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   543,
       0,   543,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   543,   960,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   543,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   543,     0,     0,     0,     0,   997,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1027,     0,     0,   543,  1031,  1032,     0,     0,     0,
       0,     0,   543,     0,     0,     0,     0,     0,   543,     0,
     543,     0,     0,     0,  1051,     0,     0,     0,     0,     0,
       0,     0,  1057,     0,     0,  1060,     0,     0,     0,  1065,
       0,   543,     0,     0,     0,     0,     0,     0,     0,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     543,  1095,     0,     0,     0,   543,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,     0,     0,   543,     0,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1153,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1192,  1192,  1196,  1196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,  1260,
       0,     0,     0,     0,     0,     0,     0,     0,  1267,     0,
    1267,     0,   784,     0,  1192,     0,     0,     0,     0,     0,
       0,  1192,   855,   856,     0,   864,   865,   866,   868,     0,
     870,     0,     0,     0,     0,   877,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   887,     0,     0,     0,     0,
       0,     0,     0,     0,   818,     0,   818,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   909,   910,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   915,     0,
       0,     0,   917,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1397,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1192,   964,     0,     0,
       0,   964,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1192,     0,     0,     0,     0,     0,
    1029,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1066,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   784,
       0,     0,     0,  1495,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1091,     0,  1192,     0,  1093,  1094,     0,
    1096,     0,     0,     0,     0,     0,     0,   917,     0,   812,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1192,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1547,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   910,   874,     0,     0,     0,     0,  1146,
    1150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1192,     0,  1218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1641,
       0,     0,     0,     0,  1259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1275,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1296,
       0,     0,     0,  1666,     0,     0,  1192,     0,     0,  1192,
    1301,  1302,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1679,     0,     0,  1321,     0,  1683,  1324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1350,  1351,  1352,
       0,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,
    1702,  1703,  1366,  1367,     0,     0,     0,     0,     0,     0,
       0,  1381,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1464,     0,
       0,     0,     0,     0,     0,     0,  1192,     0,  1756,     0,
    1758,     0,  1760,     0,     0,     0,     0,     0,     0,  1768,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1192,
       0,  1192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1496,     0,  1498,     0,  1500,  1792,     0,     0,
    1795,     0,     0,     0,  1506,     0,     0,     0,     0,     0,
       0,  1192,     0,  1510,     0,     0,     0,     0,     0,  1514,
    1515,     0,  1802,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1537,     0,
       0,  1538,  1539,     0,  1192,     0,     0,     0,     0,     0,
       0,     0,  1830,     0,     0,     0,     0,     0,  1192,     0,
    1192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1847,     0,     0,     0,     0,     0,     0,     0,     0,
    1850,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1859,     0,  1146,     0,     0,  1860,  1150,  1579,     0,     0,
       0,     0,  1583,     0,     0,     0,     0,  1869,     0,     0,
    1872,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1645,
       0,     0,     0,  1647,     0,     0,     0,  1650,     0,  1652,
       0,     0,     0,     0,     0,     0,     0,  1657,     0,     0,
       0,     0,     0,     0,     0,  1661,  1663,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1685,  1686,
    1687,  1688,     0,  1690,  1691,     0,  1692,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1699,     0,     0,     0,     0,  1701,     0,     0,     0,
       0,     0,  1705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1743,     0,  1744,     0,     0,  1746,     0,     0,
    1748,     0,     0,     0,     0,  1750,  1663,     0,     0,     0,
       0,     0,     0,     0,  1755,     0,     0,     0,  1759,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1771,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1777,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1797,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1836,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -165,
     897,     0,     0,     0,     0,  1848,     0,     0,     0,  1853,
       1,     2,     0,     0,  1836,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
    1853,     0,    14,   426,  1862,    16,    17,    18,    19,    20,
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
     255,   256,   257,   258,   259,   260,  -165,   897,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   901,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   427,    30,    31,    32,    33,
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
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   897,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   427,    30,    31,    32,    33,    34,     0,    35,    36,
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
       0,   133,   134,   135,   136,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   897,
     253,     0,   254,   255,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   568,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   569,   570,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   516,    85,    86,    87,    88,    89,   571,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   572,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
       0,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   534,   535,   536,   185,   186,   537,   574,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,  -882,   468,     0,  -261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -882,     0,     0,
       0,  -882,     0,     0,     0,  -882,  -882,     0,     0,     0,
       0,  -882,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -261,     0,     0,  -882,     0,  -261,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -882,     0,
    -882,  -882,  -882,     0,     0,  -882,  -882,  -882,  -882,     0,
       0,     0,  -882,  -882,     0,     0,     0,     0,     0,  -882,
       0,     0,  -882,  -882,  -261,     0,     0,     0,  -882,     0,
       0,     0,     0,  -882,  -882,     0,     0,     0,     0,  -882,
       0,     0,     0,  -882,     0,     0,     0,  -882,  -882,     0,
    -882,     0,  -882,  -882,     0,     0,     0,  -882,  -882,     0,
       0,  -882,  -882,  -882,  -882,  -882,  -882,     0,     0,  -882,
       0,     0,     0,  -882,  -882,     0,     0,  -882,     0,     0,
       0,     0,  -882,     0,     0,  -882,     0,     0,     0,     0,
    -882,  -882,  -882,  -882,  -882,  -882,     0,  -882,  -882,  -882,
    -882,  -882,     0,     0,     0,     0,  -882,  -882,  -882,     0,
    -882,  -882,  -882,  -882,  -882,  -882,     0,  -882,     0,  -882,
       0,     0,     0,     0,     0,  -882,     0,     0,     0,  -882,
    -882,     0,  -883,   613,     0,  -262,     0,     0,     0,     0,
       0,     0,     0,     0,  -882,     0,  -882,     0,  -882,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -882,     0,     0,     0,     0,  -882,     0,     0,  -882,     0,
       0,     0,     0,     0,  -883,     0,     0,     0,  -883,     0,
       0,     0,  -883,  -883,     0,     0,     0,     0,  -883,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -262,
       0,     0,  -883,     0,  -262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -882,     0,  -882,  -883,     0,  -883,  -883,  -883,
       0,     0,  -883,  -883,  -883,  -883,     0,     0,     0,  -883,
    -883,     0,     0,     0,     0,     0,  -883,     0,     0,  -883,
    -883,  -262,     0,     0,     0,  -883,     0,     0,     0,     0,
    -883,  -883,     0,     0,     0,     0,  -883,     0,     0,     0,
    -883,     0,     0,     0,  -883,  -883,     0,  -883,     0,  -883,
    -883,     0,     0,     0,  -883,  -883,     0,     0,  -883,  -883,
    -883,  -883,  -883,  -883,     0,     0,  -883,     0,     0,     0,
    -883,  -883,     0,     0,  -883,     0,     0,     0,     0,  -883,
       0,     0,  -883,     0,     0,     0,     0,  -883,  -883,  -883,
    -883,  -883,  -883,     0,  -883,  -883,  -883,  -883,  -883,     0,
       0,     0,     0,  -883,  -883,  -883,     0,  -883,  -883,  -883,
    -883,  -883,  -883,     0,  -883,     0,  -883,     0,     0,     0,
       0,     0,  -883,     0,     0,     0,  -883,  -883,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -883,     0,  -883,     0,  -883,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -883,     0,     0,
       0,     0,  -883,     0,     0,  -883,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,  -883,
      13,  -883,     0,    14,    15,     0,    16,    17,    18,    19,
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
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,   261,   262,     1,
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
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     0,   620,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   427,    30,    31,    32,    33,
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
       0,   830,     0,   132,     0,   133,   134,   135,   136,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   427,    30,    31,    32,    33,    34,     0,    35,    36,
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
       0,   133,   134,   135,   136,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   255,   256,   257,   258,   259,   260,     1,
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
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
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
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,    14,   426,     0,    16,    17,    18,    19,
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
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,   901,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   427,    30,    31,    32,    33,
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
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
    1368,   427,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,  1369,  1370,    53,    54,    55,
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
       0,   133,   134,   135,   136,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,  1371,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   255,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   568,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   569,   570,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   516,    85,    86,    87,    88,    89,   571,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,   962,     0,   104,   105,   106,   107,
     108,   109,   110,   572,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,   963,   133,   134,   135,
       0,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   534,   535,   536,   185,   186,   537,   574,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   568,   427,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   569,   570,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   516,    85,    86,
      87,    88,    89,   571,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     962,     0,   104,   105,   106,   107,   108,   109,   110,   572,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   968,   133,   134,   135,     0,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   534,   535,
     536,   185,   186,   537,   574,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   254,   255,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   568,   427,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   569,   570,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,    89,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   572,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,   573,   132,     0,   133,
     134,   135,     0,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   534,   535,   536,   185,   186,   537,
     574,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   568,   427,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   569,
     570,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   516,
      85,    86,    87,    88,    89,   571,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   572,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   578,   133,   134,   135,     0,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     534,   535,   536,   185,   186,   537,   574,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     568,   427,    30,    31,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     0,    48,    49,    50,   569,   570,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   516,    85,    86,    87,    88,
      89,   571,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   572,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,     0,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   534,   535,   536,   185,
     186,   537,   574,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,   203,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   615,
     253,     0,   254,   255,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   568,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   569,   570,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   516,    85,    86,    87,    88,    89,   571,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   572,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
       0,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   534,   535,   536,   185,   186,   537,   574,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,   617,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   568,   427,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   569,   570,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   516,    85,    86,
      87,    88,    89,   571,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   572,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
     961,   132,     0,   133,   134,   135,     0,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   534,   535,
     536,   185,   186,   537,   574,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   254,   255,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   568,   427,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   569,   570,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,    89,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   572,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,  1200,   133,
     134,   135,     0,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   534,   535,   536,   185,   186,   537,
     574,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   255,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   568,   427,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   569,
     570,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   516,
      85,    86,    87,    88,    89,   571,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,  1463,     0,   104,   105,   106,   107,   108,   109,
     110,   572,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,     0,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     534,   535,   536,   185,   186,   537,   574,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   502,    27,
     504,   427,    30,   505,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
     507,     0,    48,    49,    50,   509,   510,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   516,    85,    86,    87,    88,
      89,   571,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   519,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   572,   112,     0,
     113,   114,   704,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   705,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,     0,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   529,   169,   530,   171,   531,   532,   174,   175,
     176,   177,   178,   179,   533,   181,   534,   535,   536,   185,
     186,   537,   538,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   539,     0,   202,   540,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   541,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   568,   427,    30,    31,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,    48,    49,
      50,   569,   570,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   516,    85,    86,    87,    88,    89,   571,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   572,   112,     0,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,   127,   128,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
       0,   137,   138,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   534,   535,   536,   185,   186,   537,   574,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     0,   202,   203,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   255,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     502,    27,   504,   427,    30,   505,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   507,     0,    48,    49,    50,   509,   510,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   516,    85,    86,
      87,    88,    89,   571,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   572,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,     0,   137,   138,     0,
     139,     0,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
       0,   155,   428,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   529,   169,   530,   171,   531,   532,
     174,   175,   176,   177,   178,   179,   533,   181,   534,   535,
     536,   185,   186,   537,   538,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   539,     0,   202,
     203,   204,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,   253,     0,   254,   541,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   502,    27,   504,   427,
      30,   505,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   507,     0,
      48,    49,    50,   509,   510,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,    89,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   519,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   572,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,     0,   137,   138,     0,   139,     0,   140,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     529,   169,   530,   171,   531,   532,   174,   175,   176,   177,
     178,   179,   533,   181,   534,   535,   536,   185,   186,   537,
     538,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   539,     0,   202,   540,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   541,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   425,
     426,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   568,   427,    30,    31,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,    48,    49,    50,   569,
     570,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,    75,    76,     0,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,    82,    83,   516,
      85,    86,    87,    88,    89,  1149,    91,     0,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   572,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,   135,     0,   137,
     138,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,     0,   152,
     153,   154,     0,   155,   428,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     534,   535,   536,   185,   186,   537,   574,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
       0,   202,   203,   204,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,   253,     0,   254,   255,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   425,   426,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   502,    27,
     504,   427,    30,   505,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
     507,     0,    48,    49,    50,   509,   510,    53,   511,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,    82,    83,   516,    85,    86,    87,    88,
      89,   571,    91,     0,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   519,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   572,   112,     0,
     113,   114,     0,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,     0,
       0,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,     0,   137,   138,     0,   139,     0,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,     0,   152,   153,   154,     0,   155,
     428,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   529,   169,   530,   171,   531,   532,   174,   175,
     176,   177,   178,   179,   533,   181,   534,   535,   536,   185,
     186,   537,   538,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   539,     0,   202,   540,   204,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
     253,     0,   254,   541,   256,   257,   258,   259,   260,     1,
       2,     0,     0,     0,     3,     0,     0,     0,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   425,   426,     0,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   502,    27,   504,   427,    30,   505,
      32,    33,    34,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,   507,     0,    48,    49,
      50,   509,   510,    53,   511,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,    82,
      83,   516,    85,    86,    87,    88,    89,   571,    91,     0,
      92,     0,     0,     0,    93,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   519,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   572,   112,     0,   113,   114,     0,   116,
     117,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,   126,     0,     0,     0,     0,     0,   129,
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
       0,     0,     0,     0,   139,     0,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
       0,   152,   153,   154,     0,   155,   428,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   529,   169,
     530,   171,   531,   532,   174,   175,   176,   177,   178,   179,
     533,   181,   534,   535,   536,   185,   186,   537,   538,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   539,     0,   202,   540,   204,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,   253,     0,   254,   541,
     256,   257,   258,   259,   260,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     502,    27,   504,   427,    30,   505,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   507,     0,    48,    49,    50,   509,   510,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   516,    85,    86,
      87,    88,    89,   571,    91,     0,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,     0,   109,   110,   572,
     112,     0,   113,   114,     0,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,     0,     0,     0,     0,
     139,     0,   140,     0,   141,     0,   143,     0,   145,   146,
     147,   148,   149,   150,   151,     0,     0,   152,   153,   154,
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
     252,     0,   253,     0,   254,   541,   256,   257,   258,   259,
     260,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   425,   426,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   502,    27,   504,   427,
      30,   505,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   507,     0,
      48,    49,    50,   509,   510,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   516,    85,    86,    87,    88,     0,   571,
      91,     0,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   519,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,     0,   109,   110,   572,     0,     0,     0,   114,
       0,     0,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,     0,     0,     0,     0,     0,     0,   140,     0,
     141,     0,   143,     0,   145,   146,   147,   148,   149,   150,
     151,     0,     0,   152,   153,   154,     0,   155,   428,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     529,   169,   530,   171,   531,   532,   174,   175,   176,   177,
     178,   179,   533,   181,   534,   535,   536,   185,   186,   537,
     538,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   539,     0,   202,   203,   204,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,   253,     0,
     254,   541,   256,   257,   258,   259,   260,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     0,     0,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,   425,
     426,     0,    16,    17,    18,   499,    20,    21,    22,   500,
      24,   501,   502,   503,   504,   427,    30,   505,    32,    33,
      34,     0,    35,    36,    37,    38,   506,    40,    41,    42,
      43,    44,    45,    46,   507,     0,    48,   508,    50,   509,
     510,    53,   511,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   512,   513,    71,
       0,    72,    73,    74,   514,     0,     0,    77,    78,    79,
       0,     0,   515,    81,     0,     0,     0,     0,    83,   516,
      85,   517,   518,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   520,   521,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   522,     0,
       0,     0,   118,   119,   120,   121,   523,   123,   124,   524,
       0,     0,     0,     0,     0,     0,     0,   525,   526,   131,
       0,     0,     0,   132,     0,   133,   134,   527,     0,     0,
       0,     0,   139,     0,   140,     0,   141,   142,   143,   144,
     528,   146,   147,   148,   149,   150,   151,     0,     0,   152,
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
     250,   251,     0,     0,     0,     0,   254,   541,   256,   257,
     258,   259,   260,     1,     2,     0,     0,     0,     3,     0,
       0,     0,     4,     0,     0,     0,     0,     9,    10,     0,
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
       0,   133,   134,   527,     0,     0,     0,     0,   139,     0,
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
      10,     0,     0,     0,    13,     0,     0,   425,   426,     0,
      16,    17,    18,   549,    20,    21,    22,   500,   550,   551,
     502,   503,   504,   427,    30,   505,    32,   552,    34,     0,
      35,    36,    37,    38,   553,    40,   554,   555,    43,    44,
      45,    46,   507,     0,    48,   556,    50,   509,   510,    53,
     511,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   512,   513,    71,     0,    72,
      73,    74,   557,     0,     0,    77,    78,    79,     0,     0,
     515,    81,     0,     0,     0,     0,    83,   516,    85,   517,
     518,    88,    89,   571,    91,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   519,   100,   101,   520,   521,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,   110,     0,
       0,     0,   956,     0,     0,   116,   522,     0,     0,     0,
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
       0,     0,     3,     0,   254,   541,   256,   257,   258,   259,
     260,     9,    10,     0,     0,     0,     0,     0,     0,   425,
     426,     0,    16,    17,    18,   499,    20,    21,    22,   500,
      24,   501,   502,  1175,   504,   427,    30,   505,    32,    33,
      34,     0,    35,    36,    37,    38,   506,    40,    41,    42,
      43,    44,    45,    46,   507,     0,    48,   508,    50,   509,
     510,    53,   511,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   512,   513,    71,
       0,    72,    73,    74,   514,     0,     0,    77,    78,    79,
       0,     0,   515,    81,     0,     0,     0,     0,    83,   516,
      85,   517,   518,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   519,   100,   101,   520,   521,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
    1176,     0,     0,     0,  1177,     0,     0,   116,   522,     0,
       0,     0,   118,   119,   120,   121,   523,   123,   124,   524,
       0,     0,     0,     0,     0,     0,     0,   525,   526,   131,
       0,     0,     0,   132,  1616,   133,   134,   527,     0,     0,
       0,     0,  1617,     0,   140,     0,   141,   142,   143,   144,
     528,   146,   147,   148,   149,   150,   151,     0,     0,  1178,
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
     250,   251,     0,     0,     0,     0,   254,   541,   256,  1179,
    1180,  1181,  1182,     3,     0,   585,   586,     0,     0,     0,
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
       0,     0,     0,     0,     0,   140,     0,   141,   142,   143,
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
     257,   258,   259,   260,     9,    10,     0,     0,     0,     0,
       0,     0,   425,   426,     0,    16,    17,    18,   549,    20,
      21,    22,   500,   550,   551,   502,   503,   504,   427,    30,
     505,    32,   552,    34,     0,    35,    36,    37,    38,   553,
      40,   554,   555,    43,    44,    45,    46,   507,     0,    48,
     556,    50,   509,   510,    53,   511,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     512,   513,    71,     0,    72,    73,    74,   557,     0,     0,
      77,    78,    79,     0,     0,   515,    81,     0,     0,     0,
       0,    83,   516,    85,   517,   518,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   519,   100,   101,   520,
     521,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   522,     0,     0,     0,   118,   119,   120,   121,   523,
     123,   124,   524,     0,     0,     0,     0,     0,     0,     0,
     525,   526,   131,     0,     0,     0,   132,   779,   133,   134,
     527,     0,     0,     0,     0,   780,     0,   140,     0,   141,
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
       0,   805,     0,     0,   425,   426,     0,    16,    17,    18,
     549,    20,    21,    22,   500,   550,   551,   502,   503,   504,
     427,    30,   505,    32,   552,    34,     0,    35,    36,    37,
      38,   553,    40,   554,   555,    43,    44,    45,    46,   507,
       0,    48,   556,    50,   509,   510,    53,   511,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   512,   513,    71,     0,    72,    73,    74,   557,
       0,     0,    77,    78,    79,     0,     0,   515,    81,     0,
       0,     0,     0,    83,   516,    85,   517,   518,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   519,   100,
     101,   520,   521,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   522,     0,     0,     0,   118,   119,   120,
     121,   523,   123,   124,   524,     0,     0,     0,     0,     0,
       0,     0,   525,   526,   131,     0,     0,     0,   132,   806,
     133,   134,   527,     0,     0,     0,     0,     0,     0,   140,
       0,   141,   142,   143,   144,   528,   146,   147,   148,   149,
     150,   151,     0,     0,   152,   153,     0,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   529,   558,   530,   171,   531,   532,   174,   175,   176,
     177,   178,   179,   533,   181,   534,   535,   536,   185,   186,
     537,   538,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   539,     0,   202,   540,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,     0,     3,
       0,   254,   541,   256,   257,   258,   259,   260,     9,    10,
       0,     0,     0,     0,     0,     0,   425,   426,     0,    16,
      17,    18,   549,    20,    21,    22,   500,   550,   551,   502,
     503,   504,   427,    30,   505,    32,   552,    34,     0,    35,
      36,    37,    38,   553,    40,   554,   555,    43,    44,    45,
      46,   507,     0,    48,   556,    50,   509,   510,    53,   511,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   512,   513,    71,     0,    72,    73,
      74,   557,     0,     0,    77,    78,    79,     0,     0,   515,
      81,     0,     0,     0,     0,    83,   516,    85,   517,   518,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     519,   100,   101,   520,   521,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,   116,   522,     0,     0,     0,   118,
     119,   120,   121,   523,   123,   124,   524,     0,     0,     0,
       0,     0,     0,     0,   525,   526,   131,     0,     0,     0,
     132,   823,   133,   134,   527,     0,     0,     0,     0,   824,
       0,   140,     0,   141,   142,   143,   144,   528,   146,   147,
     148,   149,   150,   151,     0,     0,   152,   153,     0,     0,
     155,   428,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   529,   558,   530,   171,   531,   532,   174,
     175,   176,   177,   178,   179,   533,   181,   534,   535,   536,
     185,   186,   537,   538,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   539,     0,   202,   540,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
       0,     3,     0,   254,   541,   256,   257,   258,   259,   260,
       9,    10,     0,     0,     0,     0,     0,     0,   425,   426,
       0,    16,    17,    18,   499,    20,    21,    22,   500,    24,
     501,   502,  1175,   504,   427,    30,   505,    32,    33,    34,
       0,    35,    36,    37,    38,   506,    40,    41,    42,    43,
      44,    45,    46,   507,     0,    48,   508,    50,   509,   510,
      53,   511,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   512,   513,    71,     0,
      72,    73,    74,   514,     0,     0,    77,    78,    79,     0,
       0,   515,    81,     0,     0,     0,     0,    83,   516,    85,
     517,   518,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   519,   100,   101,   520,   521,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1176,
       0,     0,     0,  1215,     0,     0,   116,   522,     0,     0,
       0,   118,   119,   120,   121,   523,   123,   124,   524,     0,
       0,     0,     0,     0,     0,     0,   525,   526,   131,     0,
       0,     0,   132,  1450,   133,   134,   527,     0,     0,     0,
       0,     0,     0,   140,     0,   141,   142,   143,   144,   528,
     146,   147,   148,   149,   150,   151,     0,     0,   152,   153,
       0,     0,   155,   428,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   529,   169,   530,   171,   531,
     532,   174,   175,   176,   177,   178,   179,   533,   181,   534,
     535,   536,   185,   186,   537,   538,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   539,     0,
     202,   540,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,     0,     0,     3,     0,   254,   541,   256,  1179,  1180,
    1181,  1182,     9,    10,     0,     0,     0,     0,     0,     0,
     425,   426,     0,    16,    17,    18,   499,    20,    21,    22,
     500,    24,   501,   502,  1175,   504,   427,    30,   505,    32,
      33,    34,     0,    35,    36,    37,    38,   506,    40,    41,
      42,    43,    44,    45,    46,   507,     0,    48,   508,    50,
     509,   510,    53,   511,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   512,   513,
      71,     0,    72,    73,    74,   514,     0,     0,    77,    78,
      79,     0,     0,   515,    81,     0,     0,     0,     0,    83,
     516,    85,   517,   518,    88,    89,  1524,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   519,   100,   101,   520,   521,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1176,     0,     0,     0,  1177,     0,     0,   116,   522,
       0,     0,     0,   118,   119,   120,   121,   523,   123,   124,
     524,     0,     0,     0,     0,     0,     0,     0,   525,   526,
     131,     0,     0,     0,   132,     0,   133,   134,   527,     0,
       0,     0,     0,     0,     0,   140,     0,   141,   142,   143,
     144,   528,   146,   147,   148,   149,   150,   151,     0,     0,
    1178,   153,     0,     0,   155,   428,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   529,   169,   530,
     171,   531,   532,   174,   175,   176,   177,   178,   179,   533,
     181,   534,   535,   536,   185,   186,   537,   538,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     539,     0,   202,   540,   204,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,     0,     0,     3,     0,   254,   541,   256,
    1179,  1180,  1181,  1182,     9,    10,     0,     0,     0,     0,
       0,     0,   425,   426,     0,    16,    17,    18,   499,    20,
      21,    22,   500,    24,   501,   502,  1175,   504,   427,    30,
     505,    32,    33,    34,     0,    35,    36,    37,    38,   506,
      40,    41,    42,    43,    44,    45,    46,   507,     0,    48,
     508,    50,   509,   510,    53,   511,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     512,   513,    71,     0,    72,    73,    74,   514,     0,     0,
      77,    78,    79,     0,     0,   515,    81,     0,     0,     0,
       0,    83,   516,    85,   517,   518,    88,    89,  1669,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   519,   100,   101,   520,
     521,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,  1176,     0,     0,     0,  1177,     0,     0,
     116,   522,     0,     0,     0,   118,   119,   120,   121,   523,
     123,   124,   524,     0,     0,     0,     0,     0,     0,     0,
     525,   526,   131,     0,     0,     0,   132,     0,   133,   134,
     527,     0,     0,     0,     0,     0,     0,   140,     0,   141,
     142,   143,   144,   528,   146,   147,   148,   149,   150,   151,
       0,     0,  1178,   153,     0,     0,   155,   428,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   529,
     169,   530,   171,   531,   532,   174,   175,   176,   177,   178,
     179,   533,   181,   534,   535,   536,   185,   186,   537,   538,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   539,     0,   202,   540,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,     0,     0,     3,     0,   254,
     541,   256,  1179,  1180,  1181,  1182,     9,    10,     0,     0,
       0,     0,     0,     0,   425,   426,     0,    16,    17,    18,
     499,    20,    21,    22,   500,    24,   501,   502,  1175,   504,
     427,    30,   505,    32,    33,    34,     0,    35,    36,    37,
      38,   506,    40,    41,    42,    43,    44,    45,    46,   507,
       0,    48,   508,    50,   509,   510,    53,   511,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   512,   513,    71,     0,    72,    73,    74,   514,
       0,     0,    77,    78,    79,     0,     0,   515,    81,     0,
       0,     0,     0,    83,   516,    85,   517,   518,    88,    89,
    1673,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   519,   100,
     101,   520,   521,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1176,     0,     0,     0,  1177,
       0,     0,   116,   522,     0,     0,     0,   118,   119,   120,
     121,   523,   123,   124,   524,     0,     0,     0,     0,     0,
       0,     0,   525,   526,   131,     0,     0,     0,   132,     0,
     133,   134,   527,     0,     0,     0,     0,     0,     0,   140,
       0,   141,   142,   143,   144,   528,   146,   147,   148,   149,
     150,   151,     0,     0,  1178,   153,     0,     0,   155,   428,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   529,   169,   530,   171,   531,   532,   174,   175,   176,
     177,   178,   179,   533,   181,   534,   535,   536,   185,   186,
     537,   538,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   539,     0,   202,   540,   204,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,     0,     3,
       0,   254,   541,   256,  1179,  1180,  1181,  1182,     9,    10,
       0,     0,     0,     0,     0,     0,   425,   426,     0,    16,
      17,    18,   499,    20,    21,    22,   500,    24,   501,   502,
    1175,   504,   427,    30,   505,    32,    33,    34,     0,    35,
      36,    37,    38,   506,    40,    41,    42,    43,    44,    45,
      46,   507,     0,    48,   508,    50,   509,   510,    53,   511,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   512,   513,    71,     0,    72,    73,
      74,   514,     0,     0,    77,    78,    79,     0,     0,   515,
      81,     0,     0,     0,     0,    83,   516,    85,   517,   518,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     519,   100,   101,   520,   521,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1176,     0,     0,
       0,  1177,     0,     0,   116,   522,     0,     0,     0,   118,
     119,   120,   121,   523,   123,   124,   524,     0,     0,     0,
       0,     0,     0,     0,   525,   526,   131,     0,     0,     0,
     132,     0,   133,   134,   527,     0,     0,     0,     0,     0,
       0,   140,     0,   141,   142,   143,   144,   528,   146,   147,
     148,   149,   150,   151,     0,     0,  1178,   153,     0,     0,
     155,   428,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   529,   169,   530,   171,   531,   532,   174,
     175,   176,   177,   178,   179,   533,   181,   534,   535,   536,
     185,   186,   537,   538,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   539,     0,   202,   540,
     204,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
       0,     3,     0,   254,   541,   256,  1179,  1180,  1181,  1182,
       9,    10,     0,     0,     0,     0,     0,     0,   425,   426,
       0,    16,    17,    18,   499,    20,    21,    22,   500,    24,
     501,   502,  1175,   504,   427,    30,   505,    32,    33,    34,
       0,    35,    36,    37,    38,   506,    40,    41,    42,    43,
      44,    45,    46,   507,     0,    48,   508,    50,   509,   510,
      53,   511,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   512,   513,    71,     0,
      72,    73,    74,   514,     0,     0,    77,    78,    79,     0,
       0,   515,    81,     0,     0,     0,     0,    83,   516,    85,
     517,   518,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   519,   100,   101,   520,   521,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1176,
       0,     0,     0,  1215,     0,     0,   116,   522,     0,     0,
       0,   118,   119,   120,   121,   523,   123,   124,   524,     0,
       0,     0,     0,     0,     0,     0,   525,   526,   131,     0,
       0,     0,   132,     0,   133,   134,   527,     0,     0,     0,
       0,     0,     0,   140,     0,   141,   142,   143,   144,   528,
     146,   147,   148,   149,   150,   151,     0,     0,   152,   153,
       0,     0,   155,   428,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   529,   169,   530,   171,   531,
     532,   174,   175,   176,   177,   178,   179,   533,   181,   534,
     535,   536,   185,   186,   537,   538,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   539,     0,
     202,   540,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,     0,     0,     3,     0,   254,   541,   256,  1179,  1180,
    1181,  1182,     9,    10,     0,     0,     0,     0,     0,     0,
     425,   426,     0,    16,    17,    18,   549,    20,    21,    22,
     500,   550,   551,   502,   503,   504,   427,    30,   505,    32,
     552,    34,     0,    35,    36,    37,    38,   553,    40,   554,
     555,    43,    44,    45,    46,   507,     0,    48,   556,    50,
     509,   510,    53,   511,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   512,   513,
      71,     0,    72,    73,    74,   557,     0,     0,    77,    78,
      79,     0,     0,   515,    81,     0,     0,     0,     0,    83,
     516,    85,   517,   518,    88,    89,  1270,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   519,   100,   101,   520,   521,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   522,
       0,     0,     0,   118,   119,   120,   121,   523,   123,   124,
     524,     0,     0,     0,     0,     0,     0,     0,   525,   526,
     131,     0,     0,     0,   132,     0,   133,   134,   527,     0,
       0,     0,     0,     0,     0,   140,     0,   141,   142,   143,
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
     257,   258,   259,   260,     9,    10,     0,     0,     0,     0,
       0,     0,   425,   426,     0,    16,    17,    18,   549,    20,
      21,    22,   500,   550,   551,   502,   503,   504,   427,    30,
     505,    32,   552,    34,     0,    35,    36,    37,    38,   553,
      40,   554,   555,    43,    44,    45,    46,   507,     0,    48,
     556,    50,   509,   510,    53,   511,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     512,   513,    71,     0,    72,    73,    74,   557,     0,     0,
      77,    78,    79,     0,     0,   515,    81,     0,     0,     0,
       0,    83,   516,    85,   517,   518,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   519,   100,   101,   520,
     521,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
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
     247,   248,   249,   250,   251,     0,     0,     0,     0,   254,
     541,   256,   257,   258,   259,   260,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   425,   426,
       0,    16,    17,    18,   857,    20,    21,    22,    23,     0,
     858,   502,    27,     0,   427,    30,   505,    32,     0,    34,
       0,    35,    36,    37,    38,   859,    40,     0,     0,    43,
      44,    45,    46,   507,     0,    48,   860,    50,     0,     0,
      53,   511,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   512,   513,    71,     0,
      72,    73,    74,   861,     0,     0,    77,    78,    79,     0,
       0,   515,    81,     0,     0,     0,    82,    83,   516,    85,
     517,   518,    88,    89,   571,    91,     0,     0,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   519,   100,   101,   520,   521,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,     0,
     572,   112,     0,   113,   114,     0,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   524,     0,
     126,     0,     0,     0,     0,     0,   525,   526,   131,     0,
       0,     0,   132,     0,   133,   134,   527,     0,     0,     0,
       0,     0,     0,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,     0,     0,   153,
     154,     0,   155,   428,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   529,     0,   530,   171,   531,
     532,   174,   175,   176,   177,   178,   179,   533,   181,   534,
     535,   536,   185,   186,     0,   538,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   539,     0,
     202,   540,   204,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   253,     9,    10,   541,   256,     0,     0,
       0,     0,   425,   426,     0,    16,    17,    18,     0,    20,
      21,    22,   500,     0,     0,   502,   503,     0,   427,    30,
     505,    32,     0,    34,     0,    35,    36,    37,    38,     0,
      40,     0,     0,    43,    44,    45,    46,   507,     0,    48,
       0,    50,     0,     0,    53,   511,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     512,   513,    71,     0,    72,    73,    74,     0,     0,     0,
      77,    78,    79,     0,     0,   515,    81,     0,     0,     0,
       0,    83,   516,    85,   517,   518,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   519,   100,   101,   520,
     521,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,     0,     0,     0,     0,     0,     0,     0,
     116,   522,     0,     0,     0,   118,   119,   120,   121,   523,
     123,   124,   524,     0,     0,     0,     0,     0,     0,     0,
     525,   526,   131,     0,     0,     0,   132,     0,   133,   134,
     527,     0,     0,     0,     0,     0,     0,   140,     0,   141,
     142,   143,   144,   528,   146,   147,   148,   149,   150,   151,
       0,     0,     0,   153,     0,     0,   155,   428,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   529,
       0,   530,   171,   531,   532,   174,   175,   176,   177,   178,
     179,   533,   181,   534,   535,   536,   185,   186,     0,   538,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   539,     0,   202,   540,   204,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,     0,     0,     0,     0,     0,
     541,   256
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,   321,   112,   113,   188,     5,     6,     7,     8,   436,
     437,     5,     6,     7,     8,   321,     0,   707,     5,     6,
       7,     5,     6,     7,     8,    14,   691,   799,   300,   692,
     693,   694,   695,   438,   352,   844,  1078,  1062,   269,   784,
     812,   268,   946,   947,   633,   634,  1311,   598,   631,   632,
     633,   634,   603,   284,   826,   881,   933,   203,   784,  1329,
     261,   262,  1393,  1394,     1,   138,   719,     1,   473,   474,
    1104,    76,   631,   632,  1161,    27,    28,   975,    39,  1527,
       8,   741,  1530,    44,    45,    36,  1043,  1025,  1342,    36,
      56,   670,    53,   672,   673,    47,   675,     1,   677,    60,
    1440,    62,    63,   991,     1,    57,   685,   686,    30,   291,
      71,   111,   119,     1,     1,    97,    95,   111,    37,    38,
       1,    40,    41,    75,     1,     1,   123,   111,    80,    27,
      28,   108,     5,     6,     7,     8,   119,    98,   144,    58,
      45,  1045,   252,   253,    95,    94,    97,   133,  1052,    47,
      97,     1,     1,     1,    97,     1,  1699,   138,    63,   431,
     112,   113,   114,   435,   108,     1,   231,   170,   946,   947,
      52,   108,   132,    25,   108,     1,     1,    75,   220,    97,
      31,    95,    34,    95,   139,     1,     1,   155,    42,   111,
     300,   158,    46,   108,   147,   114,   114,    51,   149,   158,
     155,   204,   149,     1,   126,   158,   192,    33,    30,    61,
     178,   188,    55,   991,    57,   113,    70,    33,   260,  1638,
     108,   108,   203,    49,   231,   997,     0,     1,     1,   151,
     144,   108,   108,   155,  1777,   184,   158,   149,   111,   199,
    1571,   108,   239,   162,   188,   224,   225,  1025,   176,   131,
       9,    10,     1,   149,   220,   320,   178,   577,   101,   108,
     239,   261,   262,     1,    97,   265,  1308,  1045,     1,  1294,
     231,   577,   108,   279,  1052,   457,  1541,   261,   262,  1051,
     262,   265,   355,   188,  1161,  1162,     1,     1,   192,  1177,
    1544,  1100,   564,   108,   260,   192,   279,  1637,   186,  1333,
     300,   188,   891,   892,  1752,  1050,   313,   226,  1342,   186,
     108,   192,   188,  1270,  1212,   169,   300,   977,   172,   262,
     263,   431,  1048,  1261,  1050,   435,   241,  1215,   279,  1416,
     889,   890,   279,   187,   108,   108,   190,   170,  1064,   188,
     162,   293,   192,   265,   192,   104,   192,   752,   267,   301,
     929,  1799,   188,  1801,     1,   360,   466,   309,   363,   108,
     214,   471,   323,   324,   325,   216,   125,   192,   127,  1788,
     108,   481,   239,   188,     1,   108,   231,   101,   488,   489,
     317,  1153,  1286,   279,   656,   319,   149,   497,   155,   108,
     188,     1,   797,   108,   108,   293,   155,   628,   629,  1177,
     159,   108,   108,   301,   631,   632,  1737,   638,     1,   263,
      30,   185,     0,     1,   257,   188,   175,     1,     1,   620,
     155,     1,     1,   108,     1,   258,   259,   270,   261,   272,
       1,   431,    27,    28,    77,   435,   119,  1215,   197,   188,
     283,   284,   285,   231,   287,   278,   289,   431,   236,   108,
     188,   435,   121,   155,   564,   188,   215,   290,     1,   108,
    1791,   108,   462,   187,   464,   320,   190,    95,   462,   188,
     464,   581,   582,   188,   188,   162,   178,   212,   462,   185,
     464,   108,   592,  1261,   183,   192,   486,   156,  1260,   158,
      97,   491,   486,   613,   114,    76,   108,   491,   108,   198,
     610,   611,   486,   188,  1774,   188,   933,   491,  1286,    90,
    1544,   231,   155,   233,   132,   108,   279,    45,   113,    47,
     108,   149,   158,   669,   108,   108,   203,  1272,   108,   108,
     189,   108,  1310,   114,   231,   212,   233,   108,   185,  1416,
     189,   108,   162,   970,  1448,   126,   666,   128,  1425,  1375,
    1139,  1140,  1141,  1379,  1819,  1281,  1139,  1140,  1141,  1436,
     108,  1214,    95,   170,   564,   108,  1256,   253,   254,   158,
       9,    10,   572,  1124,   243,   185,   188,   119,   572,   107,
     564,   199,     9,    10,   227,   228,   108,   160,   572,   462,
     276,   464,   185,   998,   999,     9,    10,   185,  1003,   108,
     320,   185,   185,   713,   177,   185,   185,   879,   185,   158,
     720,   611,    97,   486,   185,   108,   108,   611,   491,    97,
     620,   188,    45,   320,    47,  1397,     9,   611,  1033,   114,
    1655,   631,   632,   633,   634,   907,   620,   626,   711,   712,
     188,   169,   185,     3,   118,    95,    29,   631,   632,   633,
     634,   258,   259,    97,   261,    95,   656,    80,   155,    30,
      33,   268,   889,    95,   895,   104,   188,   138,   899,    30,
    1448,   278,   656,   158,   148,   107,    49,   104,     5,   188,
     158,   152,     9,   290,   107,    97,   125,   161,   127,     5,
     104,   224,   225,     9,   144,   188,   188,     9,   125,   572,
     127,   107,   275,   119,   144,   149,   239,    67,   708,   282,
     119,   125,    72,   127,   708,   212,   155,    29,   119,   292,
     159,   708,   196,   129,   708,   835,   836,   837,   155,   839,
    1607,  1773,   159,  1542,  1161,  1162,   175,   149,  1547,   160,
     111,   155,   125,    97,   127,   159,   169,   158,   175,  1527,
     111,   150,  1530,   136,  1499,   126,   177,   167,   197,   119,
     114,   175,  1427,  1667,   158,   126,   158,   166,   275,   879,
     197,   187,   155,   183,   190,   282,   215,    95,   187,   360,
     151,   190,   363,   197,   155,   292,    54,   158,   215,   789,
     151,    59,   158,  1382,  1484,   789,   121,     1,   125,     3,
     127,   215,   789,   121,   158,   789,    95,   178,   135,   125,
      78,   127,     1,   125,     3,   127,  1720,   146,  1722,   135,
     820,   821,   124,   269,   136,   139,   820,   821,   155,    97,
     160,   156,   158,   158,   280,   708,   820,   821,   156,   155,
     158,   155,  1039,   155,  1041,  1163,   956,   177,   177,    54,
     139,   119,   124,   155,    59,   144,   158,  1129,  1764,  1765,
     150,   442,   443,    67,    96,   446,   269,   196,    72,   450,
    1679,   201,   453,   454,  1683,   107,   166,   280,    67,   879,
     461,  1785,   124,    72,  1289,   117,   467,   468,  1085,  1667,
    1087,   160,    97,   187,   475,   879,   190,   129,   183,  1130,
    1806,   482,   483,   484,   485,  1136,  1812,   907,   177,   490,
     124,   101,   901,   198,   101,   119,   789,   498,   212,   988,
     305,   119,   101,   907,   114,   101,   101,   114,  1591,   314,
     119,  1000,   201,  1598,  1599,   114,   139,   155,   114,   114,
     101,   144,  1720,   714,  1722,   155,   717,   820,   821,  1133,
    1640,   722,    54,   114,   274,   139,   238,    59,   240,  1768,
     144,   281,   193,   194,   545,  1737,   283,   284,   285,   635,
     130,   131,   289,   639,  1752,   155,   124,   155,   158,   560,
     158,   124,   155,   155,  1389,   158,   158,  1307,   187,  1416,
     571,   190,   359,  1398,   238,   362,   240,   124,  1425,   227,
     228,   229,   130,   131,   124,   689,   690,  1785,   124,  1436,
     698,   699,  1254,  1255,   696,   697,  1288,   598,  1628,  1629,
     124,  1799,   603,  1801,   124,   606,   124,   219,    27,    28,
     155,   119,   613,   248,   158,   247,   247,   158,    37,    38,
     155,    40,    41,  1708,  1709,   320,  1366,     0,    47,   168,
    1160,   192,  1742,    93,  1374,   255,   100,    50,    57,    58,
     202,   102,   195,   156,   103,    30,   158,   185,  1374,    47,
     154,   185,   185,   185,   119,   252,    75,   310,   188,   155,
    1080,    80,     1,   119,   144,   666,  1080,   108,   155,   188,
     155,   188,   158,   144,   158,   158,  1080,   158,   185,  1789,
     158,   123,   158,  1508,   123,   158,   158,   155,    35,    17,
     216,   237,    30,   112,   113,   114,  1781,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     3,   251,  1129,
     192,   119,   169,   192,   290,   290,   171,   171,   719,  1139,
    1140,  1141,   119,    71,    95,  1129,   237,    95,    95,  1138,
     188,   151,   108,   108,   162,  1139,  1140,  1141,    30,   162,
     129,   134,   252,   162,   745,    95,   305,   748,   144,   119,
     185,  1861,   134,  1863,   185,   188,   188,   108,    95,    45,
    1607,   762,    97,  1873,    97,   766,   767,  1371,   155,   155,
     188,   188,   188,   188,   185,   185,  1516,   155,  1518,    95,
     243,  1521,  1522,   155,   785,  1525,   155,  1080,   144,   155,
     192,  1531,   793,   239,    33,   796,    95,   171,   134,   800,
     144,    30,   185,   292,   233,    95,   305,   226,   129,   155,
     119,   119,    95,   162,   134,   149,   134,    97,   119,   200,
     185,   185,   149,   155,   101,   101,   185,   144,  1520,   155,
     192,    35,   123,   155,   123,    30,    80,   119,   108,   251,
     107,   291,   843,   108,  1264,   266,   260,   273,   267,    30,
    1264,   158,   158,   158,   158,   264,   158,  1264,   158,   146,
    1264,   158,   292,    30,    30,   312,   293,   192,  1288,   188,
     233,   146,  1564,   188,   293,   188,   188,   149,   134,  1299,
     881,   129,   301,   149,  1288,  1299,   142,   143,   108,   145,
     309,   144,  1299,   188,   188,  1299,   101,   153,  1318,   134,
     185,   157,   200,   159,  1318,     7,    97,   158,   164,   239,
     911,  1318,   243,   192,  1318,   239,   239,   158,   158,  1339,
     921,   155,   107,   149,   180,  1339,  1346,   119,   239,   119,
    1670,    78,  1346,   188,  1674,  1339,   149,   292,    79,   188,
      30,   188,  1346,   288,    30,   946,   947,   948,   949,   205,
     206,   207,   208,   209,   210,   188,   188,   188,  1378,   108,
     188,  1653,   171,   256,  1378,   188,   185,   277,   256,   149,
     149,  1264,  1664,  1665,  1378,   128,  1668,   128,    97,   263,
     322,   144,   185,  1675,   185,   185,   185,   185,    95,    30,
     991,   155,   188,    97,   188,   171,    95,   149,    54,    95,
      30,   119,   199,   271,  1005,   286,  1299,   108,   108,   231,
      95,    95,   199,   199,   119,   293,   200,   231,  1758,    94,
     231,   119,   184,   201,   199,  1318,   119,   119,   299,  1030,
     119,  1561,  1562,  1563,   293,   265,   751,   311,  1039,   312,
    1041,   265,  1043,   312,  1045,  1216,  1339,   311,   311,   992,
     312,  1052,   268,  1346,   457,  1053,  1261,   437,  1798,  1742,
    1789,   802,  1802,  1158,   882,  1584,  1393,  1408,  1145,  1761,
    1400,  1300,   560,  1396,  1305,  1308,  1313,   668,   949,   719,
     688,   725,   719,  1333,  1085,   844,  1087,   347,  1812,  1806,
    1041,  1376,  1365,  1375,  1834,  1607,  1425,  1837,  1162,  1436,
    1520,  1429,  1604,  1171,   465,   465,  1024,  1238,  1800,    90,
    1631,  1426,  1474,    -1,    -1,    -1,  1520,    -1,    -1,    -1,
    1860,    -1,    -1,  1124,   601,    -1,  1818,    -1,    -1,    -1,
     111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1833,    -1,    -1,  1564,   126,    -1,   128,  1149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1564,    -1,    -1,  1855,    -1,    -1,  1696,    -1,    -1,    -1,
      -1,    -1,  1864,    -1,    -1,    -1,  1177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1718,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1215,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1653,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1664,  1665,    -1,    -1,  1668,  1653,
      -1,    -1,    -1,    -1,    -1,  1675,    -1,    -1,    -1,    -1,
    1664,  1665,    -1,    -1,  1668,    -1,    -1,    -1,    -1,  1270,
      -1,  1675,    -1,  1274,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1286,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1310,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1340,
      -1,  1761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1761,    -1,    -1,
      -1,    -1,    -1,    -1,  1365,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1375,    -1,    -1,    -1,  1379,    -1,
    1800,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1800,    -1,  1818,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1407,    -1,    -1,    -1,
      -1,    -1,    -1,  1833,  1818,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1833,
      -1,    -1,    -1,    -1,    -1,  1855,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1864,    -1,    -1,  1448,    -1,    -1,
      -1,  1855,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1864,    -1,   443,    -1,    -1,   446,    -1,    -1,    -1,   450,
      -1,    -1,   453,   454,    -1,    -1,    -1,    -1,    -1,  1480,
     461,    -1,    -1,    -1,    -1,    -1,   467,   468,    -1,    -1,
      -1,    -1,    -1,    -1,   475,    -1,    -1,    -1,    -1,    -1,
      -1,   482,   483,   484,   485,    -1,    -1,    -1,    -1,   490,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,
      -1,    -1,    -1,  1524,    -1,    -1,  1527,    -1,    -1,  1530,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1543,    -1,    -1,    -1,    -1,  1548,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,
    1581,  1582,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
     571,   572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     601,    -1,    -1,    -1,    -1,   606,    -1,    -1,    -1,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1667,    -1,  1669,    -1,
    1671,    -1,  1673,    -1,    -1,    -1,    -1,    -1,    -1,  1680,
      -1,    -1,    -1,    -1,    -1,   666,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1720,
      -1,  1722,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1738,   719,    -1,
    1741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1763,    -1,    -1,    -1,    -1,   748,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   762,    -1,    -1,  1785,   766,   767,    -1,    -1,    -1,
      -1,    -1,  1793,    -1,    -1,    -1,    -1,    -1,  1799,    -1,
    1801,    -1,    -1,    -1,   785,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   793,    -1,    -1,   796,    -1,    -1,    -1,   800,
      -1,  1822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1851,   832,    -1,    -1,    -1,  1856,    -1,    -1,    -1,    -1,
      -1,    -1,   843,    -1,    -1,    -1,    -1,  1868,    -1,    -1,
    1871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     911,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     921,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   946,   947,   948,   949,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     991,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1005,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   572,  1030,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1039,    -1,
    1041,    -1,  1043,    -1,  1045,    -1,    -1,    -1,    -1,    -1,
      -1,  1052,   596,   597,    -1,   599,   600,   601,   602,    -1,
     604,    -1,    -1,    -1,    -1,   609,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1085,    -1,  1087,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,   642,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,    -1,
      -1,    -1,   656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1177,   721,    -1,    -1,
      -1,   725,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1215,    -1,    -1,    -1,    -1,    -1,
     764,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   801,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1270,
      -1,    -1,    -1,  1274,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   827,    -1,  1286,    -1,   831,   832,    -1,
     834,    -1,    -1,    -1,    -1,    -1,    -1,   841,    -1,  1300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1310,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1340,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   907,  1365,    -1,    -1,    -1,    -1,   913,
     914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1407,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1448,    -1,   993,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1480,
      -1,    -1,    -1,    -1,  1028,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1047,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1063,
      -1,    -1,    -1,  1524,    -1,    -1,  1527,    -1,    -1,  1530,
    1074,  1075,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1543,    -1,    -1,  1089,    -1,  1548,  1092,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1111,  1112,  1113,
      -1,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,
    1581,  1582,  1126,  1127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1667,    -1,  1669,    -1,
    1671,    -1,  1673,    -1,    -1,    -1,    -1,    -1,    -1,  1680,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1720,
      -1,  1722,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1276,    -1,  1278,    -1,  1280,  1738,    -1,    -1,
    1741,    -1,    -1,    -1,  1288,    -1,    -1,    -1,    -1,    -1,
      -1,  1752,    -1,  1297,    -1,    -1,    -1,    -1,    -1,  1303,
    1304,    -1,  1763,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1322,    -1,
      -1,  1325,  1326,    -1,  1785,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1793,    -1,    -1,    -1,    -1,    -1,  1799,    -1,
    1801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1851,    -1,  1396,    -1,    -1,  1856,  1400,  1401,    -1,    -1,
      -1,    -1,  1406,    -1,    -1,    -1,    -1,  1868,    -1,    -1,
    1871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1493,
      -1,    -1,    -1,  1497,    -1,    -1,    -1,  1501,    -1,  1503,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1511,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1519,  1520,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1540,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1552,  1553,
    1554,  1555,    -1,  1557,  1558,    -1,  1560,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1575,    -1,    -1,    -1,    -1,  1580,    -1,    -1,    -1,
      -1,    -1,  1586,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1646,    -1,  1648,    -1,    -1,  1651,    -1,    -1,
    1654,    -1,    -1,    -1,    -1,  1659,  1660,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1668,    -1,    -1,    -1,  1672,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1689,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1700,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1745,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1757,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1800,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,    -1,    -1,  1829,    -1,    -1,    -1,  1833,
      11,    12,    -1,    -1,  1838,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
    1854,    -1,    33,    34,  1858,    36,    37,    38,    39,    40,
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
     321,   322,   323,   324,   325,   326,     0,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
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
     314,   315,   316,     1,   318,    -1,   320,   321,   322,   323,
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
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
      -1,   189,   190,   191,   192,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
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
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
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
     322,   323,   324,   325,   326,     0,     1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      95,    96,    97,    -1,    -1,   100,   101,   102,   103,    -1,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,   117,   118,   119,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,   134,
      -1,    -1,    -1,   138,    -1,    -1,    -1,   142,   143,    -1,
     145,    -1,   147,   148,    -1,    -1,    -1,   152,   153,    -1,
      -1,   156,   157,   158,   159,   160,   161,    -1,    -1,   164,
      -1,    -1,    -1,   168,   169,    -1,    -1,   172,    -1,    -1,
      -1,    -1,   177,    -1,    -1,   180,    -1,    -1,    -1,    -1,
     185,   186,   187,   188,   189,   190,    -1,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,   206,   207,   208,   209,   210,    -1,   212,    -1,   214,
      -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,   224,
     225,    -1,     0,     1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,    -1,   241,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   317,    -1,   319,    93,    -1,    95,    96,    97,
      -1,    -1,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,
     118,   119,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,
     128,   129,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,
     138,    -1,    -1,    -1,   142,   143,    -1,   145,    -1,   147,
     148,    -1,    -1,    -1,   152,   153,    -1,    -1,   156,   157,
     158,   159,   160,   161,    -1,    -1,   164,    -1,    -1,    -1,
     168,   169,    -1,    -1,   172,    -1,    -1,    -1,    -1,   177,
      -1,    -1,   180,    -1,    -1,    -1,    -1,   185,   186,   187,
     188,   189,   190,    -1,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,   207,
     208,   209,   210,    -1,   212,    -1,   214,    -1,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,   224,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,    -1,   241,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   317,
      30,   319,    -1,    33,    34,    -1,    36,    37,    38,    39,
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
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,    -1,   196,    -1,   198,    -1,
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
     320,   321,   322,   323,   324,   325,   326,   327,   328,    11,
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
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
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
     322,   323,   324,   325,   326,    -1,   328,    11,    12,    -1,
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
      -1,   185,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
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
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
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
      -1,   189,   190,   191,   192,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
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
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
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
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
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
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,    -1,   196,    -1,   198,    -1,
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
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
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
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
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
      -1,   189,   190,   191,   192,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
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
     182,   183,    -1,    -1,    -1,   187,   188,   189,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
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
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
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
      -1,   187,   188,   189,   190,   191,    -1,   193,   194,    -1,
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
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
      -1,   181,   182,   183,    -1,    -1,   186,   187,    -1,   189,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
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
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
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
      -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
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
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
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
      -1,   189,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
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
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
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
     312,   313,   314,   315,   316,    -1,   318,   319,   320,   321,
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
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
     186,   187,    -1,   189,   190,   191,    -1,   193,   194,    -1,
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
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
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
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
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
      -1,    -1,   146,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
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
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
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
      -1,   189,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
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
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
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
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
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
      -1,   187,    -1,   189,   190,   191,    -1,   193,   194,    -1,
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
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
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
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
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
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
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
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,   323,   324,   325,   326,    11,
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
     152,   153,   154,   155,   156,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
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
     322,   323,   324,   325,   326,    11,    12,    -1,    -1,    -1,
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
      -1,   137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,   153,   154,   155,
     156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,    -1,   200,    -1,   202,    -1,   204,   205,
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
     326,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,    -1,   202,    -1,   204,   205,   206,   207,   208,   209,
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
     320,   321,   322,   323,   324,   325,   326,    11,    12,    -1,
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
      -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
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
     314,   315,    -1,    -1,    -1,    -1,   320,   321,   322,   323,
     324,   325,   326,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
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
      -1,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
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
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
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
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
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
     314,   315,    -1,    -1,    -1,    -1,   320,   321,   322,   323,
     324,   325,   326,    16,    -1,    18,    19,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
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
     323,   324,   325,   326,    25,    26,    -1,    -1,    -1,    -1,
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
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,
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
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
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
     189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
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
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    16,
      -1,   320,   321,   322,   323,   324,   325,   326,    25,    26,
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
      -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
      -1,    16,    -1,   320,   321,   322,   323,   324,   325,   326,
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
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,    -1,    16,    -1,   320,   321,   322,   323,   324,
     325,   326,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
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
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
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
     323,   324,   325,   326,    25,    26,    -1,    -1,    -1,    -1,
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
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
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
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    16,
      -1,   320,   321,   322,   323,   324,   325,   326,    25,    26,
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
     187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
      -1,    16,    -1,   320,   321,   322,   323,   324,   325,   326,
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
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,    -1,    16,    -1,   320,   321,   322,   323,   324,
     325,   326,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
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
     183,    -1,    -1,    -1,   187,    -1,   189,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
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
     323,   324,   325,   326,    25,    26,    -1,    -1,    -1,    -1,
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
     311,   312,   313,   314,   315,    -1,    -1,    -1,    -1,   320,
     321,   322,   323,   324,   325,   326,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    -1,    49,    50,    51,    52,    -1,    54,
      -1,    56,    57,    58,    59,    60,    61,    -1,    -1,    64,
      65,    66,    67,    68,    -1,    70,    71,    72,    -1,    -1,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    98,    -1,    -1,   101,   102,   103,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
     155,   156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,   214,
     215,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,   318,    25,    26,   321,   322,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    58,    59,    -1,
      61,    -1,    -1,    64,    65,    66,    67,    68,    -1,    70,
      -1,    72,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,   214,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,    -1,    -1,    -1,    -1,
     321,   322
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
     504,   397,   506,   506,   419,   519,   158,   523,   525,   581,
     664,   186,   146,   188,   420,   529,   188,   151,   188,   529,
     108,   188,   188,   108,   108,   386,    30,   665,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   368,   369,
     370,    95,   139,   144,   374,   375,   376,   664,   162,   162,
     368,   663,   129,   134,    55,    57,   101,   257,   270,   272,
     283,   284,   285,   287,   289,   626,   627,   628,   629,   630,
     631,   638,   644,   645,   252,    95,   305,   664,   144,   420,
     119,   664,   664,   134,   185,   185,   188,   188,   185,   108,
     188,   108,   188,   108,    36,    95,    97,   149,   437,   438,
     560,   664,    95,   108,   188,   397,   188,   664,    97,    45,
     664,   663,    97,   144,   560,   664,   420,   441,   185,   188,
     188,   188,   188,   108,   189,   149,   560,   185,   188,   188,
     155,   185,   398,   398,   185,   108,   188,   108,   188,   144,
     560,   420,   189,   420,   420,   664,   420,   419,   419,   419,
     664,   538,   539,   132,   199,   185,   185,   185,   133,   192,
      95,   224,   225,   239,    95,   224,   225,   239,   239,   239,
      95,    95,   243,   231,   320,   108,   241,   144,   192,   188,
     419,   185,   515,   598,   417,   239,   365,    33,    33,   192,
     342,   192,   114,   400,   664,   171,   420,   452,   453,   119,
     420,   448,   449,   664,    56,   220,   260,   426,   427,   481,
     155,   158,   265,   502,   521,   599,   602,   603,   604,   605,
     606,   610,   612,   614,   615,    47,   154,   158,   213,   323,
     324,   325,   326,   561,   563,   565,   567,   582,   583,   584,
     585,   662,   664,   561,   493,   566,   664,   493,   185,   186,
     188,   419,   108,   188,   188,   521,   150,   166,   150,   166,
     139,   403,   386,   369,   134,   158,   563,   376,   420,   560,
     663,   663,   130,   131,   663,   283,   284,   285,   289,   664,
     269,   280,   269,   280,    30,   292,    97,   114,   158,   632,
     635,   626,    39,    44,    53,    60,    62,    71,    98,   231,
     323,   324,   325,   390,   567,   662,   233,   305,   314,   420,
     664,    95,   305,   663,   155,   579,   580,   664,   579,   580,
     119,   436,   129,   561,   119,   420,   149,   438,   149,    36,
     149,   437,   438,   560,   561,   388,    95,   185,   200,   134,
     360,   663,   162,   134,    97,   360,   420,   144,   438,   155,
     119,   420,   420,   149,   101,   462,   463,   464,   466,   467,
     101,   470,   471,   472,   473,   398,   185,   185,   155,   579,
     579,   420,   144,   192,   420,   123,   123,   188,   188,   188,
      35,   539,   132,   199,     9,    10,   104,   125,   127,   155,
     197,   534,   536,   547,   548,   551,   155,    30,   238,   240,
     420,   420,   420,   238,   240,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   517,   119,   420,   420,    48,    73,
      74,   250,   400,   421,   432,   251,   595,   596,   155,   212,
     401,   420,   192,   114,   395,   395,   395,   452,    96,   107,
     117,   129,   454,   455,   456,   457,   108,   664,   107,   450,
     108,   149,   560,   260,    54,    59,    78,   119,   437,   443,
     444,   445,   427,   419,   599,   606,   155,   291,   483,   651,
      97,   170,   258,   259,   261,   268,   278,   290,   600,   601,
     620,   621,   622,   623,   646,   649,   264,   266,   607,   625,
     273,   611,   647,   253,   254,   276,   616,   617,   158,   158,
     188,   563,   158,   158,   158,   158,   158,   146,   177,   196,
     562,   146,   188,   146,   420,   139,   403,   581,   375,   292,
      30,    97,   114,   158,   639,    30,   632,   562,   562,   504,
     293,   312,   560,   390,   233,   192,   397,   188,   188,   146,
     188,   188,   436,   149,   437,   664,   420,   149,   420,   129,
     420,   149,   438,   149,   561,   400,   420,   663,   108,   360,
     420,   144,   397,   460,   420,   420,   114,   463,   464,   101,
     424,   114,   464,   467,   119,   474,   561,   101,   114,   471,
     101,   114,   473,   185,   397,   188,   188,   420,   420,   420,
     200,   470,   134,   197,   536,     7,   398,   664,   197,   547,
     398,   192,   239,   239,   239,   239,    97,   243,   243,   593,
     424,   158,   158,   158,   424,   598,   596,   515,   663,   130,
     131,   456,   457,   457,   453,   144,   560,   663,   449,   420,
     149,   119,   119,   420,   664,   445,    78,   185,   188,   599,
     613,   256,   220,   260,   274,   281,   650,    97,   262,   263,
     648,   256,   603,   650,   485,   620,   604,   149,   288,   608,
     609,   648,   292,   619,    79,   618,   188,   196,   561,   564,
     188,   188,   188,   188,   188,   188,   188,    30,   138,   203,
     641,   642,   643,    30,   640,   641,   277,   636,   108,   633,
     171,   664,   263,   504,   185,   420,   149,   420,   149,   437,
     420,   149,   420,   128,   128,    97,   663,   420,   185,   424,
     424,   420,   400,   420,   424,   424,   664,   212,   424,   119,
     474,   119,   424,   119,   474,   424,   185,   114,   539,   664,
     197,   185,   539,   664,   185,   420,   420,   420,   420,   322,
     420,   420,   420,   419,   419,   419,   155,   597,   457,   420,
     144,   420,   664,   664,   444,   420,   185,   487,    52,   131,
     485,   485,   275,   282,   292,   624,   624,   605,   155,   286,
      95,   188,   108,   188,   639,   639,   643,   108,   188,    30,
     637,   648,   634,   635,   188,   392,   393,   504,   119,   231,
     313,   293,   171,   420,   420,   149,   420,   400,   420,   360,
     420,   400,    95,   561,   400,   420,   664,   424,   664,   420,
     664,   424,   400,   119,    94,   184,   540,   539,   664,   199,
     539,   420,   188,   188,   188,   419,   450,   420,    54,   485,
     485,   201,   419,   561,   561,    95,    30,   271,   108,   108,
     457,   560,   664,   119,   231,   664,   392,   420,   474,    95,
     424,    95,   664,     5,   135,   543,   544,   546,   548,    29,
     136,   541,   542,   545,   548,   199,   539,   199,   200,   470,
     185,   450,   119,   485,   185,   561,   635,   393,   457,   311,
     664,   119,   231,   424,   474,   400,   420,   474,   424,    94,
     135,   546,   184,   136,   545,   199,   114,   664,   420,   311,
     664,   119,   400,   420,   424,   424,   119,   299,   311,   664,
     664,   312,   420,   312,   424,   504,   504,   201,   293,   664,
     231,   119,   664,   312,   504
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
     517,   517,   517,   517,   517,   517,   517,   518,   518,   519,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   521,   521,   522,   522,   522,   523,
     524,   524,   525,   526,   527,   528,   528,   529,   529,   529,
     529,   530,   530,   531,   532,   533,   533,   534,   534,   534,
     535,   535,   535,   535,   535,   535,   536,   536,   537,   537,
     538,   539,   539,   540,   540,   541,   541,   542,   542,   542,
     542,   543,   543,   544,   544,   544,   544,   545,   545,   546,
     546,   547,   547,   547,   547,   548,   548,   548,   548,   549,
     549,   550,   550,   551,   552,   552,   552,   552,   552,   552,
     552,   553,   554,   554,   555,   555,   556,   557,   558,   558,
     559,   559,   560,   561,   561,   561,   561,   562,   562,   562,
     563,   563,   563,   563,   563,   563,   563,   564,   564,   565,
     566,   567,   567,   567,   567,   567,   567,   567,   567,   567,
     567,   568,   569,   570,   570,   570,   571,   572,   573,   574,
     574,   574,   575,   575,   575,   575,   575,   576,   577,   577,
     577,   577,   577,   577,   577,   578,   579,   580,   581,   582,
     582,   583,   584,   584,   585,   586,   586,   586,   587,   587,
     587,   587,   587,   587,   587,   587,   587,   587,   588,   588,
     589,   589,   590,   591,   592,   592,   593,   594,   595,   595,
     596,   597,   598,   598,   599,   600,   600,   601,   601,   602,
     602,   603,   603,   604,   604,   605,   605,   606,   607,   607,
     608,   608,   609,   610,   610,   610,   611,   611,   612,   613,
     613,   614,   615,   615,   616,   616,   617,   617,   617,   618,
     618,   619,   619,   620,   620,   620,   620,   620,   621,   622,
     623,   624,   624,   624,   625,   625,   626,   626,   626,   626,
     626,   626,   626,   626,   627,   627,   627,   627,   628,   628,
     629,   630,   630,   631,   631,   631,   632,   632,   633,   633,
     634,   634,   635,   636,   636,   637,   637,   638,   638,   638,
     639,   639,   640,   640,   641,   641,   642,   642,   643,   643,
     644,   645,   645,   646,   646,   646,   647,   648,   648,   648,
     648,   649,   649,   650,   650,   651,   652,   652,   653,   653,
     654,   654,   655,   656,   656,   656,   656,   657,   657,   657,
     658,   659,   660,   661,   662,   662,   662,   663,   664,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   665,   665,   665,   665,   665,   665,   665,   665,   665,
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
     665,   665,   665,   665,   665,   665,   665,   666
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
       3,     3,     4,     5,     3,     3,     3,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     4,     4,     3,     4,     1,     3,     1,
       3,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       4,     8,     5,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     7,     3,     7,     4,     4,     3,     7,
       3,     7,     2,     1,     2,     3,     2,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     4,     4,     3,     3,     3,     3,
       4,     4,     3,     4,     6,     4,     6,     4,     3,     4,
       6,     6,     4,     6,     6,     4,     1,     2,     1,     1,
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
       2,     3,     3,     3,     3,     5,     5,     5,     5,     8,
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
       1,     1,     1,     1,     1,     1,     1,     1
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
  "JSONTest", "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

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
     188,    -1,   517,   121,   523,    -1,   517,   121,   525,    -1,
     517,   121,   581,    -1,   519,    -1,   518,   519,    -1,   156,
     419,   186,    -1,   521,    -1,   523,    -1,   524,    -1,   525,
      -1,   528,    -1,   533,    -1,   526,    -1,   527,    -1,   530,
      -1,   402,    -1,   655,    -1,   652,    -1,   653,    -1,   654,
      -1,   522,    -1,   581,    -1,   111,    -1,   151,    -1,   126,
      -1,   119,   664,    -1,   158,   188,    -1,   158,   419,   188,
      -1,   120,    -1,   170,   155,   419,   185,    -1,   204,   155,
     419,   185,    -1,   665,   158,   188,    -1,   665,   158,   529,
     188,    -1,   146,    -1,   529,   108,   146,    -1,   420,    -1,
     529,   108,   420,    -1,   531,    -1,   532,    -1,   665,   147,
     151,    -1,    47,   386,   403,    -1,   534,    -1,   552,    -1,
     535,    -1,   549,    -1,   550,    -1,   159,   664,   539,   132,
      -1,   159,   664,   539,   199,   197,   664,   539,   199,    -1,
     159,   664,   537,   539,   132,    -1,   159,   664,   537,   539,
     199,   197,   664,   539,   199,    -1,   159,   664,   539,   199,
     536,   197,   664,   539,   199,    -1,   159,   664,   537,   539,
     199,   536,   197,   664,   539,   199,    -1,   547,    -1,   536,
     547,    -1,   538,    -1,   537,   538,    -1,    35,   664,   539,
     134,   539,   540,    -1,    -1,    35,    -1,   184,   541,   184,
      -1,    94,   543,    94,    -1,    -1,   542,    -1,   136,    -1,
     545,    -1,   542,   136,    -1,   542,   545,    -1,    -1,   544,
      -1,   135,    -1,   546,    -1,   544,   135,    -1,   544,   546,
      -1,    29,    -1,   548,    -1,     5,    -1,   548,    -1,   534,
      -1,    10,    -1,   551,    -1,   548,    -1,     9,    -1,   125,
      -1,   127,    -1,   155,   398,   185,    -1,   215,    31,   216,
      -1,   215,   216,    -1,   175,   664,   176,    -1,   175,   664,
       8,    -1,   104,     7,    -1,   553,    -1,   554,    -1,   555,
      -1,   556,    -1,   557,    -1,   558,    -1,   559,    -1,    43,
     155,   398,   185,    -1,    21,   397,   185,    -1,    45,   155,
     419,   185,   155,   397,   185,    -1,    22,   397,   185,    -1,
      98,   155,   419,   185,   155,   397,   185,    -1,    71,   155,
     398,   185,    -1,    39,   155,   398,   185,    -1,    23,   397,
     185,    -1,    60,   155,   419,   185,   155,   397,   185,    -1,
      24,   398,   185,    -1,   162,   155,   419,   185,   155,   398,
     185,    -1,    95,   561,    -1,   563,    -1,   563,   562,    -1,
     213,   158,   188,    -1,   158,   188,    -1,   146,    -1,   196,
      -1,   177,    -1,   565,    -1,   567,    -1,   154,   158,   188,
      -1,   326,   158,   188,    -1,   582,    -1,   585,    -1,   662,
      -1,   561,    -1,   564,   108,   561,    -1,   664,    -1,   664,
      -1,   570,    -1,   577,    -1,   575,    -1,   578,    -1,   576,
      -1,   574,    -1,   573,    -1,   572,    -1,   571,    -1,   568,
      -1,   569,   158,   188,    -1,   231,    -1,    44,   158,   188,
      -1,    44,   158,   577,   188,    -1,    44,   158,   578,   188,
      -1,    53,   158,   188,    -1,    71,   158,   188,    -1,    39,
     158,   188,    -1,    60,   158,   188,    -1,    60,   158,   664,
     188,    -1,    60,   158,    30,   188,    -1,    98,   158,   188,
      -1,    98,   158,   664,   188,    -1,    98,   158,   664,   108,
     579,   188,    -1,    98,   158,   196,   188,    -1,    98,   158,
     196,   108,   579,   188,    -1,    62,   158,   664,   188,    -1,
      45,   158,   188,    -1,    45,   158,   664,   188,    -1,    45,
     158,   664,   108,   579,   188,    -1,    45,   158,   664,   108,
     580,   188,    -1,    45,   158,   196,   188,    -1,    45,   158,
     196,   108,   579,   188,    -1,    45,   158,   196,   108,   580,
     188,    -1,    63,   158,   664,   188,    -1,   664,    -1,   664,
     146,    -1,    30,    -1,   583,    -1,   584,    -1,    47,   158,
     196,   188,    -1,    47,   158,   188,    95,   561,    -1,    47,
     158,   564,   188,    95,   561,    -1,   158,   563,   188,    -1,
      33,   226,   227,    -1,    33,   226,   228,    -1,    33,   226,
     229,    -1,   232,   231,   420,   239,   420,    -1,   232,   231,
     420,    95,   238,   239,   420,    -1,   232,   231,   420,    95,
     240,   239,   420,    -1,   232,   231,   420,   224,   420,    -1,
     232,   231,   420,   225,   420,    -1,   232,   233,   420,   239,
     420,    -1,   232,   233,   420,    95,   238,   239,   420,    -1,
     232,   233,   420,    95,   240,   239,   420,    -1,   232,   233,
     420,   224,   420,    -1,   232,   233,   420,   225,   420,    -1,
     230,   231,   420,    -1,   230,   233,   420,    -1,   235,   231,
     420,   243,   420,    -1,   235,   236,   237,   231,   420,   243,
     420,    -1,   234,   231,   420,    95,   420,    -1,   242,   119,
     592,   241,   420,   424,   420,    -1,   593,    -1,   592,   108,
     119,   593,    -1,   664,   144,   420,    -1,   250,   155,   419,
     185,   595,    -1,   596,    -1,   595,   596,    -1,   251,   598,
     597,    -1,   155,   419,   185,    -1,   515,    -1,   598,   212,
     515,    -1,   602,   600,    -1,    -1,   601,    -1,   620,    -1,
     601,   620,    -1,   603,    -1,   602,   268,   603,    -1,   604,
      -1,   603,   264,   604,    -1,   605,    -1,   604,   266,   149,
     605,    -1,   606,    -1,   265,   606,    -1,   610,   607,   608,
      -1,    -1,   625,    -1,    -1,   609,    -1,   288,   155,   419,
     185,    -1,   614,   611,    -1,   158,   599,   188,    -1,   612,
      -1,    -1,   647,    -1,   502,   155,   613,   185,    -1,    -1,
     599,    -1,   615,   616,    -1,   521,    -1,   155,   419,   185,
      -1,    -1,   617,    -1,   254,   618,    -1,   253,   619,    -1,
     276,    -1,    -1,    79,    -1,    -1,   292,    -1,   621,    -1,
     622,    -1,   623,    -1,   649,    -1,   646,    -1,   170,    -1,
     290,   485,   624,    -1,   259,   648,   624,    -1,   292,    -1,
     282,    -1,   275,    -1,   252,   626,    -1,   625,   252,   626,
      -1,   627,    -1,   628,    -1,   629,    -1,   644,    -1,   630,
      -1,   638,    -1,   631,    -1,   645,    -1,   101,   280,    -1,
     101,   269,    -1,   272,    -1,   287,    -1,   257,   280,    -1,
     257,   269,    -1,    57,   664,    30,    -1,   283,    -1,    55,
     283,    -1,   285,   632,    -1,   285,   158,   632,   633,   188,
      -1,    55,   285,    -1,   635,    -1,   114,    -1,    -1,   108,
     634,    -1,   635,    -1,   634,   108,   635,    -1,    97,    30,
     636,   637,    -1,    -1,   277,    30,    -1,    -1,   648,   271,
      -1,   284,   292,   639,   641,    -1,   284,   292,   114,   641,
      -1,    55,   284,   292,    -1,    97,    30,    -1,   158,   640,
     188,    -1,    30,    -1,   640,   108,    30,    -1,    -1,   642,
      -1,   643,    -1,   642,   643,    -1,   203,   639,    -1,   138,
     639,    -1,   270,    30,    -1,   289,    -1,    55,   289,    -1,
      97,   220,    -1,    97,   260,    -1,   261,   256,    -1,   273,
     648,   286,    -1,   262,   485,    -1,    97,   131,   485,    -1,
      97,    52,   485,    -1,   263,   485,   201,   485,    -1,   278,
     650,    -1,   258,   650,    -1,   281,    -1,   274,    -1,   291,
     256,   487,    -1,   156,   186,    -1,   156,   419,   186,    -1,
     316,   317,    -1,   316,   419,   317,    -1,   318,   319,    -1,
     318,   419,   319,    -1,   155,   656,   185,    -1,   664,   123,
     420,    -1,   420,   123,   420,    -1,   656,   108,   420,   123,
     420,    -1,   656,   108,   664,   123,   420,    -1,   232,   320,
     420,   239,   420,    -1,   232,   320,   656,   239,   420,    -1,
     232,   320,   420,   239,   420,    97,   322,   420,    -1,   321,
     320,   420,   239,   420,    -1,   230,   320,   517,    -1,   234,
     320,   517,    95,   420,    -1,   235,   236,   237,   320,   517,
     243,   420,    -1,   325,   158,   188,    -1,   324,   158,   188,
      -1,   323,   158,   188,    -1,    30,    -1,   665,    -1,    16,
      -1,    98,    -1,    39,    -1,    44,    -1,    53,    -1,    45,
      -1,   154,    -1,    48,    -1,   231,    -1,    60,    -1,    62,
      -1,    63,    -1,    71,    -1,    74,    -1,    73,    -1,   213,
      -1,   249,    -1,   320,    -1,   324,    -1,   323,    -1,   325,
      -1,   326,    -1,   666,    -1,    25,    -1,   217,    -1,   129,
      -1,    38,    -1,   267,    -1,    37,    -1,   228,    -1,   227,
      -1,   148,    -1,    43,    -1,   265,    -1,   266,    -1,   280,
      -1,   269,    -1,   257,    -1,   291,    -1,   283,    -1,   285,
      -1,   284,    -1,   289,    -1,   261,    -1,   256,    -1,    79,
      -1,   220,    -1,   260,    -1,    52,    -1,   229,    -1,   242,
      -1,   308,    -1,   236,    -1,   205,    -1,   210,    -1,   209,
      -1,   208,    -1,   207,    -1,   206,    -1,    97,    -1,   112,
      -1,   113,    -1,   187,    -1,    46,    -1,   263,    -1,    36,
      -1,    67,    -1,    72,    -1,    59,    -1,    54,    -1,    56,
      -1,    78,    -1,    42,    -1,   149,    -1,    51,    -1,   214,
      -1,   171,    -1,   172,    -1,   169,    -1,    70,    -1,    96,
      -1,   117,    -1,   130,    -1,   131,    -1,   107,    -1,    68,
      -1,   137,    -1,   189,    -1,   101,    -1,    95,    -1,   200,
      -1,   128,    -1,   168,    -1,    93,    -1,    50,    -1,   237,
      -1,   102,    -1,   201,    -1,   118,    -1,   161,    -1,   203,
      -1,   152,    -1,   138,    -1,    76,    -1,    77,    -1,   103,
      -1,   202,    -1,   153,    -1,   183,    -1,   198,    -1,   162,
      -1,   139,    -1,   133,    -1,   167,    -1,   150,    -1,   166,
      -1,    33,    -1,    40,    -1,    58,    -1,   114,    -1,    41,
      -1,    57,    -1,   219,    -1,    49,    -1,    61,    -1,    34,
      -1,    47,    -1,   279,    -1,   255,    -1,   288,    -1,   290,
      -1,   259,    -1,   273,    -1,   286,    -1,   278,    -1,   258,
      -1,   272,    -1,   287,    -1,   277,    -1,   271,    -1,   270,
      -1,   254,    -1,   253,    -1,   262,    -1,   292,    -1,   282,
      -1,   281,    -1,   276,    -1,   274,    -1,   275,    -1,   241,
      -1,   238,    -1,   321,    -1,   232,    -1,   235,    -1,   234,
      -1,   230,    -1,   225,    -1,   224,    -1,   226,    -1,   243,
      -1,   233,    -1,   240,    -1,   239,    -1,    66,    -1,    64,
      -1,    75,    -1,   170,    -1,   204,    -1,   248,    -1,   246,
      -1,   247,    -1,   244,    -1,   245,    -1,   250,    -1,   251,
      -1,   252,    -1,    65,    -1,   301,    -1,   299,    -1,   300,
      -1,   305,    -1,   306,    -1,   307,    -1,   302,    -1,   303,
      -1,   304,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,    90,    -1,   293,    -1,   294,    -1,   295,
      -1,   296,    -1,   297,    -1,   298,    -1,   309,    -1,   310,
      -1,   311,    -1,   312,    -1,   313,    -1,   314,    -1,   315,
      -1,    91,    -1,   106,    -1,   115,    -1,   173,    -1,   181,
      -1,   191,    -1,   140,    -1,    92,    -1,   116,    -1,   141,
      -1,   182,    -1,   322,    -1,   221,    -1,   222,    -1,   223,
      -1,   190,    -1,   218,    -1,    26,    -1
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
    1723,  1727,  1731,  1736,  1742,  1746,  1750,  1754,  1756,  1759,
    1763,  1765,  1767,  1769,  1771,  1773,  1775,  1777,  1779,  1781,
    1783,  1785,  1787,  1789,  1791,  1793,  1795,  1797,  1799,  1801,
    1804,  1807,  1811,  1813,  1818,  1823,  1827,  1832,  1834,  1838,
    1840,  1844,  1846,  1848,  1852,  1856,  1858,  1860,  1862,  1864,
    1866,  1871,  1880,  1886,  1896,  1906,  1917,  1919,  1922,  1924,
    1927,  1934,  1935,  1937,  1941,  1945,  1946,  1948,  1950,  1952,
    1955,  1958,  1959,  1961,  1963,  1965,  1968,  1971,  1973,  1975,
    1977,  1979,  1981,  1983,  1985,  1987,  1989,  1991,  1993,  1997,
    2001,  2004,  2008,  2012,  2015,  2017,  2019,  2021,  2023,  2025,
    2027,  2029,  2034,  2038,  2046,  2050,  2058,  2063,  2068,  2072,
    2080,  2084,  2092,  2095,  2097,  2100,  2104,  2107,  2109,  2111,
    2113,  2115,  2117,  2121,  2125,  2127,  2129,  2131,  2133,  2137,
    2139,  2141,  2143,  2145,  2147,  2149,  2151,  2153,  2155,  2157,
    2159,  2161,  2165,  2167,  2171,  2176,  2181,  2185,  2189,  2193,
    2197,  2202,  2207,  2211,  2216,  2223,  2228,  2235,  2240,  2244,
    2249,  2256,  2263,  2268,  2275,  2282,  2287,  2289,  2292,  2294,
    2296,  2298,  2303,  2309,  2316,  2320,  2324,  2328,  2332,  2338,
    2346,  2354,  2360,  2366,  2372,  2380,  2388,  2394,  2400,  2404,
    2408,  2414,  2422,  2428,  2436,  2438,  2443,  2447,  2453,  2455,
    2458,  2462,  2466,  2468,  2472,  2475,  2476,  2478,  2480,  2483,
    2485,  2489,  2491,  2495,  2497,  2502,  2504,  2507,  2511,  2512,
    2514,  2515,  2517,  2522,  2525,  2529,  2531,  2532,  2534,  2539,
    2540,  2542,  2545,  2547,  2551,  2552,  2554,  2557,  2560,  2562,
    2563,  2565,  2566,  2568,  2570,  2572,  2574,  2576,  2578,  2580,
    2584,  2588,  2590,  2592,  2594,  2597,  2601,  2603,  2605,  2607,
    2609,  2611,  2613,  2615,  2617,  2620,  2623,  2625,  2627,  2630,
    2633,  2637,  2639,  2642,  2645,  2651,  2654,  2656,  2658,  2659,
    2662,  2664,  2668,  2673,  2674,  2677,  2678,  2681,  2686,  2691,
    2695,  2698,  2702,  2704,  2708,  2709,  2711,  2713,  2716,  2719,
    2722,  2725,  2727,  2730,  2733,  2736,  2739,  2743,  2746,  2750,
    2754,  2759,  2762,  2765,  2767,  2769,  2773,  2776,  2780,  2783,
    2787,  2790,  2794,  2798,  2802,  2806,  2812,  2818,  2824,  2830,
    2839,  2845,  2849,  2855,  2863,  2867,  2871,  2875,  2877,  2879,
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
    3221,  3223,  3225,  3227,  3229,  3231,  3233,  3235,  3237,  3239,
    3241,  3243,  3245,  3247,  3249,  3251,  3253,  3255,  3257,  3259,
    3261,  3263,  3265,  3267,  3269,  3271,  3273,  3275,  3277,  3279,
    3281,  3283,  3285,  3287,  3289,  3291,  3293,  3295,  3297,  3299,
    3301,  3303,  3305,  3307,  3309,  3311,  3313,  3315,  3317,  3319,
    3321,  3323,  3325,  3327,  3329,  3331,  3333,  3335
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,   936,   936,   937,   941,   945,   951,   955,   959,   965,
     971,   979,   985,   994,   999,  1005,  1011,  1017,  1025,  1030,
    1038,  1046,  1054,  1063,  1068,  1074,  1080,  1089,  1097,  1104,
    1110,  1119,  1120,  1121,  1122,  1123,  1126,  1127,  1128,  1129,
    1130,  1131,  1132,  1133,  1136,  1141,  1147,  1153,  1159,  1164,
    1170,  1175,  1181,  1186,  1192,  1197,  1202,  1207,  1213,  1215,
    1217,  1225,  1230,  1238,  1246,  1255,  1262,  1270,  1276,  1282,
    1288,  1295,  1303,  1314,  1321,  1328,  1336,  1343,  1349,  1358,
    1359,  1360,  1361,  1362,  1363,  1364,  1365,  1368,  1374,  1381,
    1388,  1396,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,
    1412,  1413,  1416,  1430,  1436,  1442,  1449,  1455,  1462,  1467,
    1473,  1479,  1491,  1503,  1516,  1521,  1529,  1537,  1546,  1551,
    1558,  1563,  1570,  1575,  1583,  1588,  1595,  1601,  1610,  1611,
    1614,  1628,  1641,  1656,  1669,  1674,  1679,  1684,  1690,  1697,
    1705,  1710,  1718,  1726,  1734,  1742,  1752,  1756,  1762,  1766,
    1773,  1782,  1793,  1799,  1806,  1811,  1818,  1825,  1834,  1844,
    1854,  1864,  1879,  1895,  1899,  1904,  1909,  1913,  1918,  1923,
    1928,  1936,  1943,  1950,  1963,  1964,  1965,  1966,  1967,  1968,
    1969,  1970,  1971,  1972,  1973,  1974,  1975,  1978,  1984,  2010,
    2016,  2022,  2029,  2036,  2045,  2054,  2063,  2072,  2083,  2089,
    2095,  2101,  2113,  2118,  2124,  2136,  2149,  2169,  2175,  2182,
    2191,  2198,  2204,  2209,  2221,  2233,  2234,  2235,  2236,  2237,
    2238,  2241,  2242,  2243,  2244,  2245,  2246,  2247,  2248,  2249,
    2250,  2251,  2252,  2255,  2267,  2273,  2274,  2279,  2284,  2290,
    2295,  2300,  2306,  2315,  2325,  2335,  2346,  2352,  2353,  2354,
    2357,  2358,  2359,  2360,  2361,  2364,  2371,  2379,  2383,  2391,
    2399,  2407,  2408,  2413,  2420,  2427,  2437,  2447,  2457,  2467,
    2477,  2487,  2497,  2507,  2517,  2526,  2536,  2546,  2558,  2564,
    2570,  2576,  2582,  2590,  2598,  2606,  2614,  2624,  2630,  2639,
    2640,  2644,  2651,  2655,  2660,  2663,  2667,  2671,  2677,  2683,
    2689,  2695,  2703,  2707,  2715,  2723,  2731,  2739,  2749,  2755,
    2761,  2769,  2775,  2783,  2787,  2795,  2801,  2807,  2813,  2822,
    2831,  2840,  2851,  2855,  2861,  2867,  2875,  2881,  2890,  2901,
    2907,  2915,  2919,  2928,  2934,  2940,  2948,  2954,  2960,  2968,
    2974,  2980,  2988,  2994,  3001,  3011,  3018,  3028,  3034,  3042,
    3048,  3057,  3063,  3071,  3077,  3086,  3092,  3100,  3106,  3110,
    3116,  3121,  3127,  3131,  3142,  3146,  3155,  3161,  3170,  3180,
    3179,  3192,  3201,  3210,  3221,  3225,  3236,  3240,  3246,  3249,
    3255,  3259,  3265,  3269,  3273,  3279,  3283,  3289,  3295,  3301,
    3309,  3313,  3317,  3323,  3327,  3333,  3341,  3345,  3353,  3357,
    3365,  3369,  3377,  3381,  3389,  3393,  3399,  3403,  3409,  3413,
    3417,  3421,  3429,  3430,  3431,  3434,  3439,  3445,  3449,  3453,
    3457,  3461,  3465,  3471,  3475,  3479,  3485,  3489,  3493,  3497,
    3506,  3514,  3520,  3528,  3532,  3536,  3542,  3546,  3554,  3562,
    3598,  3604,  3614,  3618,  3624,  3625,  3628,  3634,  3642,  3648,
    3658,  3664,  3672,  3676,  3680,  3684,  3688,  3694,  3700,  3706,
    3710,  3716,  3720,  3729,  3733,  3737,  3743,  3747,  3755,  3756,
    3759,  3763,  3769,  3773,  3777,  3781,  3787,  3791,  3795,  3799,
    3803,  3807,  3813,  3819,  3825,  3829,  3833,  3839,  3845,  3853,
    3859,  3860,  3861,  3862,  3863,  3864,  3865,  3866,  3867,  3868,
    3869,  3870,  3871,  3872,  3875,  3879,  3885,  3892,  3899,  3908,
    3914,  3918,  3924,  3931,  3937,  3943,  3947,  3965,  3971,  3977,
    3983,  3991,  3995,  4001,  4007,  4017,  4018,  4021,  4022,  4023,
    4026,  4034,  4050,  4058,  4074,  4092,  4112,  4118,  4127,  4133,
    4142,  4149,  4150,  4152,  4157,  4164,  4167,  4173,  4179,  4185,
    4192,  4201,  4204,  4210,  4216,  4222,  4229,  4238,  4242,  4248,
    4252,  4258,  4262,  4266,  4271,  4278,  4282,  4286,  4290,  4296,
    4301,  4307,  4313,  4320,  4326,  4331,  4336,  4341,  4346,  4351,
    4356,  4359,  4365,  4369,  4375,  4379,  4385,  4391,  4397,  4401,
    4407,  4411,  4417,  4423,  4427,  4431,  4435,  4442,  4448,  4454,
    4462,  4501,  4505,  4509,  4513,  4517,  4521,  4527,  4533,  4541,
    4547,  4553,  4557,  4561,  4565,  4569,  4573,  4577,  4581,  4585,
    4589,  4595,  4601,  4607,  4611,  4615,  4621,  4626,  4632,  4638,
    4642,  4647,  4653,  4657,  4663,  4669,  4673,  4681,  4687,  4691,
    4697,  4706,  4715,  4721,  4727,  4735,  4741,  4747,  4753,  4759,
    4763,  4769,  4775,  4779,  4787,  4793,  4799,  4805,  4813,  4817,
    4823,  4829,  4833,  4839,  4843,  4849,  4855,  4862,  4870,  4875,
    4881,  4887,  4895,  4901,  4908,  4914,  4923,  4929,  4935,  4941,
    4950,  4957,  4963,  4969,  4978,  4985,  4989,  4995,  5000,  5007,
    5011,  5017,  5021,  5027,  5031,  5037,  5041,  5049,  5060,  5063,
    5069,  5072,  5078,  5084,  5092,  5096,  5102,  5105,  5111,  5121,
    5124,  5130,  5140,  5146,  5154,  5157,  5163,  5167,  5171,  5177,
    5180,  5186,  5189,  5195,  5199,  5203,  5207,  5211,  5217,  5223,
    5233,  5243,  5247,  5251,  5257,  5263,  5271,  5275,  5279,  5283,
    5287,  5291,  5295,  5299,  5305,  5309,  5313,  5317,  5323,  5329,
    5337,  5345,  5349,  5355,  5365,  5376,  5382,  5386,  5392,  5395,
    5401,  5406,  5413,  5421,  5424,  5430,  5434,  5440,  5449,  5456,
    5464,  5468,  5474,  5480,  5488,  5491,  5497,  5502,  5512,  5520,
    5530,  5536,  5540,  5546,  5550,  5554,  5560,  5566,  5570,  5574,
    5578,  5584,  5592,  5602,  5606,  5612,  5618,  5622,  5628,  5632,
    5638,  5642,  5648,  5655,  5665,  5671,  5678,  5689,  5695,  5705,
    5711,  5717,  5734,  5758,  5777,  5781,  5785,  5791,  5794,  5795,
    5796,  5797,  5798,  5799,  5800,  5801,  5802,  5803,  5804,  5805,
    5806,  5807,  5808,  5809,  5810,  5811,  5812,  5813,  5814,  5815,
    5816,  5819,  5820,  5821,  5822,  5823,  5824,  5825,  5826,  5827,
    5828,  5829,  5830,  5831,  5832,  5833,  5834,  5835,  5836,  5837,
    5838,  5839,  5840,  5841,  5842,  5843,  5844,  5845,  5846,  5847,
    5848,  5849,  5850,  5851,  5852,  5853,  5854,  5855,  5856,  5857,
    5858,  5859,  5860,  5861,  5862,  5863,  5864,  5865,  5866,  5867,
    5868,  5869,  5870,  5871,  5872,  5873,  5874,  5875,  5876,  5877,
    5878,  5879,  5880,  5881,  5882,  5883,  5884,  5885,  5886,  5887,
    5888,  5889,  5890,  5891,  5892,  5893,  5894,  5895,  5896,  5897,
    5898,  5899,  5900,  5901,  5902,  5903,  5904,  5905,  5906,  5907,
    5908,  5909,  5910,  5911,  5912,  5913,  5914,  5915,  5916,  5917,
    5918,  5919,  5920,  5921,  5922,  5923,  5924,  5925,  5926,  5927,
    5928,  5929,  5930,  5931,  5932,  5933,  5934,  5935,  5936,  5937,
    5938,  5939,  5940,  5941,  5942,  5943,  5944,  5945,  5946,  5947,
    5948,  5949,  5950,  5951,  5952,  5953,  5954,  5955,  5956,  5957,
    5958,  5959,  5960,  5961,  5962,  5963,  5964,  5965,  5966,  5967,
    5968,  5969,  5970,  5971,  5972,  5973,  5974,  5975,  5976,  5977,
    5978,  5979,  5980,  5981,  5982,  5983,  5984,  5985,  5986,  5987,
    5988,  5989,  5990,  5991,  5992,  5993,  5994,  5995,  5996,  5997,
    5998,  5999,  6000,  6001,  6002,  6003,  6004,  6005,  6006,  6007,
    6008,  6009,  6010,  6011,  6012,  6013,  6014,  6015,  6016,  6017,
    6018,  6019,  6020,  6021,  6022,  6023,  6024,  6027
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
  const int jsoniq_parser::yylast_ = 19531;
  const int jsoniq_parser::yynnts_ = 327;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 623;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 340;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 594;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 18395 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6029 "/home/pjl/src/28msec/zorba/pjl-misc/zorba/build/src/compiler/parser/jsoniq_parser.y"

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

