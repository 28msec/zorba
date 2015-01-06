// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   zorbalex

// First part of user declarations.
#line 1 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:399

#define JSONIQ_PARSER
#line 59 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:399


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

#line 102 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:399


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


#line 94 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "jsoniq_parser.hpp"

// User implementation prologue.
#line 791 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:407

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}
#line 848 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:407

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

#line 200 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
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


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace zorba {
#line 286 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:474

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
              // Fall through.
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
  {}

  jsoniq_parser::~jsoniq_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  jsoniq_parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  jsoniq_parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  jsoniq_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  jsoniq_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  jsoniq_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  jsoniq_parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  jsoniq_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  jsoniq_parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  jsoniq_parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  jsoniq_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  jsoniq_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  jsoniq_parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  jsoniq_parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  jsoniq_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  jsoniq_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  jsoniq_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  jsoniq_parser::symbol_number_type
  jsoniq_parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  jsoniq_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  jsoniq_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  jsoniq_parser::stack_symbol_type&
  jsoniq_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  jsoniq_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 111: // "'DECIMAL'"

#line 790 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { delete (yysym.value.decval); }
#line 505 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 126: // "'DOUBLE'"

#line 789 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { delete (yysym.value.dval); }
#line 512 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 151: // "'INTEGER'"

#line 788 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { delete (yysym.value.ival); }
#line 519 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 344: // VersionDecl

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 526 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 345: // MainModule

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 533 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 346: // LibraryModule

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 540 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 347: // ModuleDecl

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 547 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 348: // SIND_DeclList

#line 807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 554 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 349: // SIND_Decl

#line 807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 561 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 350: // Setter

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 568 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 351: // BoundarySpaceDecl

#line 801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 575 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 352: // DefaultCollationDecl

#line 802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 582 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 353: // BaseURIDecl

#line 801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 589 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 354: // ConstructionDecl

#line 801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 596 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 355: // OrderingModeDecl

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 603 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 356: // EmptyOrderDecl

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 610 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 357: // CopyNamespacesDecl

#line 802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 617 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 358: // Import

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 624 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 359: // SchemaImport

#line 807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 631 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 360: // URILiteralList

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 638 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 361: // SchemaPrefix

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 645 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 362: // ModuleImport

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 652 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 363: // NamespaceDecl

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 659 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 364: // DefaultNamespaceDecl

#line 802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 666 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 365: // VFO_DeclList

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 673 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 366: // VFO_Decl

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 680 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 367: // DecimalFormatDecl

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 687 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 368: // DecimalFormatParamList

#line 818 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { delete (yysym.value.vstrpair); }
#line 694 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 369: // DecimalFormatParam

#line 818 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { delete (yysym.value.strpair); }
#line 701 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 371: // OptionDecl

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 708 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 372: // FTOptionDecl

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 715 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 373: // CtxItemDecl

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 722 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 374: // CtxItemDecl2

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 729 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 375: // CtxItemDecl3

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 736 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 376: // CtxItemDecl4

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 743 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 377: // VarDecl

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 750 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 378: // VarNameAndType

#line 818 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { delete (yysym.value.varnametype); }
#line 757 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 379: // AnnotationList

#line 800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 764 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 380: // Annotation

#line 800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 771 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 381: // AnnotationLiteralList

#line 800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 778 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 382: // FunctionDecl

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 785 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 383: // FunctionDecl2

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 792 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 384: // FunctionDeclSimple

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 385: // FunctionDeclUpdating

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 386: // FunctionSig

#line 818 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { delete (yysym.value.fnsig); }
#line 813 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 387: // ParamList

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 820 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 388: // Param

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 827 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 389: // CollectionDecl

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 834 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 391: // IndexDecl

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 841 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 392: // IndexKeyList

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 848 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 393: // IndexKeySpec

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 855 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 394: // IntegrityConstraintDecl

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 862 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 395: // QueryBody

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 869 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 396: // StatementsAndOptionalExprTop

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 876 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 397: // StatementsAndOptionalExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 883 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 398: // StatementsAndExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 890 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 399: // Statements

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 897 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 400: // Statement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 904 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 401: // BlockStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 911 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 402: // BlockExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 918 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 403: // EnclosedStatementsAndOptionalExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 925 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 404: // VarDeclStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 932 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 407: // AssignStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 939 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 408: // ApplyStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 946 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 409: // ExitStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 953 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 410: // WhileStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 960 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 411: // FlowCtlStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 967 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 412: // FLWORStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 974 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 413: // ReturnStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 981 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 414: // IfStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 988 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 415: // TryStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 995 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 416: // CatchListStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1002 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 417: // CatchStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1009 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 418: // VoidStatement

#line 812 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1016 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 419: // Expr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1023 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 420: // ExprSingle

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1030 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 421: // ExprSimple

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1037 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 422: // FLWORExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1044 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 423: // ReturnExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1051 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 427: // FLWORWinCond

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1058 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 428: // WindowClause

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1065 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 429: // CountClause

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1072 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 430: // ForLetWinClause

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1079 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 432: // FLWORClauseList

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1086 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 433: // ForClause

#line 803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1093 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 435: // VarInDeclList

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1100 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 436: // VarInDecl

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1107 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 437: // PositionalVar

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1114 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 438: // FTScoreVar

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1121 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 439: // LetClause

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1128 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 440: // VarGetsDeclList

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1135 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 441: // VarGetsDecl

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1142 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 442: // WindowVarDecl

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1149 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 443: // WindowVars

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1156 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 444: // WindowVars3

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1163 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 445: // WindowVars2

#line 810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1170 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 446: // WhereClause

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1177 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 447: // GroupByClause

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1184 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 448: // GroupSpecList

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1191 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 449: // GroupSpec

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1198 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 450: // GroupCollationSpec

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1205 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 451: // OrderByClause

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1212 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 452: // OrderSpecList

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1219 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 453: // OrderSpec

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1226 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 454: // OrderModifier

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1233 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 455: // OrderDirSpec

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1240 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 456: // OrderEmptySpec

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1247 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 457: // OrderCollationSpec

#line 805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1254 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 458: // QuantifiedExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1261 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 459: // QVarInDeclList

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1268 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 460: // QVarInDecl

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1275 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 461: // SwitchExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1282 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 462: // SwitchCaseClauseList

#line 812 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1289 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 463: // SwitchCaseClause

#line 812 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1296 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 464: // SwitchCaseOperandList

#line 812 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1303 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 465: // SwitchStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1310 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 468: // TypeswitchExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1317 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 469: // TypeswitchStatement

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1324 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 470: // CaseClauseList

#line 801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1331 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 471: // CaseClause

#line 801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1338 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 474: // SequenceTypeList

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1345 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 475: // IfExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1352 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 476: // OrExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1359 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 477: // AndExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1366 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 478: // NotExpr

#line 813 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1373 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 479: // ComparisonExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1380 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 481: // FTContainsExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1387 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 482: // StringConcatExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1394 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 483: // opt_FTIgnoreOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1401 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 484: // RangeExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1408 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 485: // AdditiveExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1415 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 486: // MultiplicativeExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1422 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 487: // UnionExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1429 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 488: // IntersectExceptExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1436 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 489: // InstanceofExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1443 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 490: // TreatExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1450 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 491: // CastableExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1457 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 492: // CastExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1464 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 493: // SingleType

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1471 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 494: // UnaryExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1478 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 495: // SignList

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1485 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 496: // ValueExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1492 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 497: // SimpleMapExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1499 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 498: // ValueComp

#line 809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1506 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 499: // NodeComp

#line 812 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1513 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 500: // ValidateExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1520 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 501: // ExtensionExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1527 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 502: // Pragma_list

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1534 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 503: // Pragma

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1541 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 504: // PathExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1548 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 506: // RelativePathExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1555 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 507: // StepExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1562 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 508: // AxisStep

#line 816 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1569 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 509: // ForwardStep

#line 799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1576 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 510: // ForwardAxis

#line 799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1583 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 511: // AbbrevForwardStep

#line 799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1590 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 512: // ReverseStep

#line 799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1597 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 513: // ReverseAxis

#line 799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1604 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 514: // NodeTest

#line 799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1611 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 515: // NameTest

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1618 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 516: // Wildcard

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1625 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 517: // PostfixExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1632 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 518: // PredicateList

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1639 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 519: // Predicate

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1646 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 520: // PrimaryExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1653 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 521: // Literal

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1660 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 522: // NumericLiteral

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1667 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 523: // VarRef

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1674 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 524: // ParenthesizedExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1681 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 525: // ContextItemExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1688 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 526: // OrderedExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1695 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 527: // UnorderedExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1702 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 528: // FunctionCall

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1709 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 529: // ArgList

#line 800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1716 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 533: // Constructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1723 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 534: // DirectConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1730 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 535: // DirElemConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1737 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 536: // DirElemContentList

#line 802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1744 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 537: // DirAttributeList

#line 802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1751 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 538: // DirAttr

#line 802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1758 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 540: // DirAttributeValue

#line 802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1765 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 541: // opt_QuoteAttrContentList

#line 807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1772 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 542: // QuoteAttrContentList

#line 807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1779 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 543: // opt_AposAttrContentList

#line 800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1786 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 544: // AposAttrContentList

#line 800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1793 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 545: // QuoteAttrValueContent

#line 807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 546: // AposAttrValueContent

#line 800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 547: // DirElemContent

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 548: // CommonContent

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1821 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 549: // DirCommentConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1828 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 550: // DirPIConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1835 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 551: // CDataSection

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1842 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 552: // ComputedConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1849 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 553: // CompDocConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1856 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 554: // CompElemConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1863 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 555: // CompAttrConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1870 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 556: // CompTextConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1877 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 557: // CompCommentConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1884 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 558: // CompPIConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1891 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 559: // CompNamespaceConstructor

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1898 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 560: // TypeDeclaration

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1905 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 561: // SequenceType

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1912 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 562: // OccurrenceIndicator

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1919 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 563: // ItemType

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1926 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 564: // TypeList

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1933 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 565: // GeneralizedAtomicType

#line 801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1940 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 566: // SimpleType

#line 801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1947 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 567: // KindTest

#line 804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1954 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 568: // AnyKindTest

#line 800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1961 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 570: // DocumentTest

#line 802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1968 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 571: // NamespaceTest

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1975 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 572: // TextTest

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1982 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 573: // CommentTest

#line 801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1989 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 574: // PITest

#line 806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1996 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 575: // AttributeTest

#line 801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2003 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 576: // SchemaAttributeTest

#line 807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2010 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 577: // ElementTest

#line 802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2017 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 578: // SchemaElementTest

#line 807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2024 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 579: // TypeName

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2031 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 580: // TypeName_WITH_HOOK

#line 808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2038 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 581: // StringLiteral

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2045 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 583: // AnyFunctionTest

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2052 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 584: // TypedFunctionTest

#line 811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2059 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 587: // InsertExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2066 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 588: // DeleteExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2073 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 589: // ReplaceExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2080 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 590: // RenameExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2087 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 591: // TransformExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2094 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 592: // VarNameList

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2101 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 593: // VarNameDecl

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2108 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 594: // TryExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2115 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 595: // CatchListExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2122 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 596: // CatchExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2129 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 597: // BracedExpr

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2136 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 598: // NameTestList

#line 818 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { delete (yysym.value.name_test_list); }
#line 2143 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 599: // FTSelection

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2150 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 602: // FTOr

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2157 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 603: // FTAnd

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2164 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 604: // FTMildNot

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2171 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 605: // FTUnaryNot

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2178 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 606: // FTPrimaryWithOptions

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2185 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 607: // opt_FTMatchOptions

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2192 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 609: // FTWeight

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2199 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 610: // FTPrimary

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2206 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 611: // opt_FTTimes

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2213 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 612: // FTExtensionSelection

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2220 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 614: // FTWords

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2227 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 615: // FTWordsValue

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2234 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 617: // FTAnyallOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2241 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 620: // FTPosFilter

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2248 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 621: // FTOrder

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2255 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 622: // FTWindow

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2262 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 623: // FTDistance

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2269 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 624: // FTUnit

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2276 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 625: // FTMatchOptions

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2283 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 626: // FTMatchOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2290 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 627: // FTCaseOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2297 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 628: // FTDiacriticsOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2304 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 629: // FTExtensionOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2311 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 630: // FTStemOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2318 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 631: // FTThesaurusOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2325 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 635: // FTThesaurusID

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2332 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 638: // FTStopWordOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2339 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 639: // FTStopWords

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2346 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 643: // FTStopWordsInclExcl

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2353 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 644: // FTLanguageOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2360 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 645: // FTWildCardOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2367 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 646: // FTContent

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2374 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 647: // FTTimes

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2381 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 648: // FTRange

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2388 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 649: // FTScope

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2395 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 650: // FTBigUnit

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2402 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 651: // FTIgnoreOption

#line 814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2409 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 652: // JSONArrayConstructor

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2416 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 653: // JSONSimpleObjectUnion

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2423 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 654: // JSONAccumulatorObjectUnion

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2430 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 655: // JSONObjectConstructor

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2437 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 656: // JSONPairList

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2444 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 657: // JSONInsertExpr

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2451 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 658: // JSONAppendExpr

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2458 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 659: // JSONDeleteExpr

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2465 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 660: // JSONRenameExpr

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2472 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 661: // JSONReplaceExpr

#line 815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2479 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 664: // QNAME

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2486 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 665: // FUNCTION_NAME

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2493 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;

      case 666: // EQNAME

#line 817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2500 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:599
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  jsoniq_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  jsoniq_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  jsoniq_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  jsoniq_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
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
#endif // YYDEBUG

  inline jsoniq_parser::state_type
  jsoniq_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

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
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 128 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:725
{
    yyla.location.begin.filename = yyla.location.end.filename = &(driver.theFilename2);
}

#line 2636 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:725

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 3:
#line 937 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = (yystack_[0].value.node);
      }
#line 2752 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 4:
#line 941 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = (yystack_[0].value.node);
      }
#line 2760 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 945 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = (yystack_[0].value.node);
      }
#line 2768 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 6:
#line 951 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = NULL;
      }
#line 2776 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 7:
#line 955 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = NULL; YYABORT;
      }
#line 2784 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 8:
#line 959 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = NULL; YYABORT;
      }
#line 2792 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 9:
#line 965 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      driver.set_expr( (yylhs.value.node) );
    }
#line 2801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 971 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      MainModule* mm = dynamic_cast<MainModule*>((yystack_[0].value.node));
      mm->set_version_decl( static_cast<VersionDecl*>((yystack_[1].value.node)) );
      (yylhs.value.node) = (yystack_[0].value.node);
      driver.set_expr( (yylhs.value.node) );
    }
#line 2812 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 979 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      driver.set_expr( (yylhs.value.node) );
    }
#line 2821 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 985 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yystack_[0].value.node));
      lm->set_version_decl( static_cast<VersionDecl*>((yystack_[1].value.node)) );
      (yylhs.value.node) = (yystack_[0].value.node);
      driver.set_expr( (yylhs.value.node) );
    }
#line 2832 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 994 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VersionDecl( LOC(yylhs.location), SYMTAB((yystack_[1].value.sval)), "utf-8", VersionDecl::jsoniq );
    }
#line 2840 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 999 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VersionDecl( LOC(yylhs.location), SYMTAB((yystack_[3].value.sval)), SYMTAB((yystack_[1].value.sval)), VersionDecl::jsoniq );
    }
#line 2848 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 1005 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location), static_cast<SIND_DeclList*>((yystack_[2].value.node)), NULL);
      (yylhs.value.node) = new MainModule(LOC(yylhs.location), static_cast<QueryBody*>((yystack_[0].value.expr)), prolog);
    }
#line 2857 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 1011 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location), NULL, static_cast<VFO_DeclList*>((yystack_[2].value.node)));
      (yylhs.value.node) = new MainModule(LOC(yylhs.location), static_cast<QueryBody*>((yystack_[0].value.expr)), prolog);
    }
#line 2866 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 1017 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location),
                                  static_cast<SIND_DeclList*>((yystack_[4].value.node)),
                                  static_cast<VFO_DeclList*>((yystack_[2].value.node)));
      (yylhs.value.node) = new MainModule(LOC(yylhs.location), static_cast<QueryBody*>((yystack_[0].value.expr)), prolog);
    }
#line 2877 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 1025 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new MainModule( LOC(yylhs.location), static_cast<QueryBody*>((yystack_[0].value.expr)), NULL );
    }
#line 2885 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 1030 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.expr);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
#line 2896 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 1038 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.expr);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
#line 2907 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 1046 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[4].value.node); (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.expr);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
#line 2918 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 1054 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[4].value.node); (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.expr);
      yystack_[4].location.step();
      error(yystack_[4].location, "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
#line 2929 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 1063 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new LibraryModule(LOC(yylhs.location), static_cast<ModuleDecl*>((yystack_[0].value.node)), NULL);
    }
#line 2937 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 1068 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location), static_cast<SIND_DeclList*>((yystack_[1].value.node)), NULL);
      (yylhs.value.node) = new LibraryModule(LOC(yylhs.location), static_cast<ModuleDecl*>((yystack_[2].value.node)), prolog);
    }
#line 2946 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 1074 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location), NULL, static_cast<VFO_DeclList*>((yystack_[1].value.node)));
      (yylhs.value.node) = new LibraryModule(LOC(yylhs.location), static_cast<ModuleDecl*>((yystack_[2].value.node)), prolog);
    }
#line 2955 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 1080 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location),
                                  static_cast<SIND_DeclList*>((yystack_[3].value.node)),
                                  static_cast<VFO_DeclList*>((yystack_[1].value.node)));
      (yylhs.value.node) = new LibraryModule(LOC(yylhs.location), static_cast<ModuleDecl*>((yystack_[4].value.node)), prolog);
    }
#line 2966 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 1089 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[3].value.expr), yystack_[3].location);
      (yylhs.value.node) = new ModuleDecl( LOC(yylhs.location), static_cast<QName*>((yystack_[3].value.expr)), SYMTAB((yystack_[1].value.sval)) );
      dynamic_cast<ModuleDecl*>((yylhs.value.node))->setComment( SYMTAB((yystack_[5].value.sval)) );
    }
#line 2976 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 1097 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC(yylhs.location) );
      sdl->push_back( (yystack_[0].value.node) );
      (yylhs.value.node) = sdl;
    }
#line 2986 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 1104 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ((SIND_DeclList*)(yystack_[2].value.node))->push_back( (yystack_[0].value.node) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 2995 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 1110 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.node);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
#line 3006 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 1136 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new BoundarySpaceDecl(LOC(yylhs.location), StaticContextConsts::preserve_space);
    }
#line 3014 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 1141 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new BoundarySpaceDecl(LOC(yylhs.location), StaticContextConsts::strip_space);
    }
#line 3022 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 46:
#line 1147 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DefaultCollationDecl( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 3030 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 47:
#line 1153 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new BaseURIDecl( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 3038 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 1159 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ConstructionDecl(LOC(yylhs.location), StaticContextConsts::cons_preserve);
    }
#line 3046 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 1164 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ConstructionDecl(LOC(yylhs.location), StaticContextConsts::cons_strip);
    }
#line 3054 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 1170 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new OrderingModeDecl(LOC(yylhs.location), StaticContextConsts::ordered);
    }
#line 3062 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 1175 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new OrderingModeDecl(LOC(yylhs.location), StaticContextConsts::unordered);
    }
#line 3070 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 1181 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new EmptyOrderDecl(LOC(yylhs.location), StaticContextConsts::empty_greatest);
    }
#line 3078 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 1186 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new EmptyOrderDecl(LOC(yylhs.location), StaticContextConsts::empty_least);
    }
#line 3086 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 1192 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CopyNamespacesDecl(LOC(yylhs.location), true, true);
    }
#line 3094 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 1197 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CopyNamespacesDecl(LOC(yylhs.location), true, false);
    }
#line 3102 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 1202 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CopyNamespacesDecl(LOC(yylhs.location), false, true);
    }
#line 3110 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 1207 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CopyNamespacesDecl(LOC(yylhs.location), false, false);
    }
#line 3118 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 1217 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yylhs.value.node);
      error(yystack_[1].location, "syntax error, \"import\" should be followed by either \"schema\" or \"module\"");
      YYERROR;
    }
#line 3128 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 1225 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaImport( LOC(yylhs.location), NULL, SYMTAB((yystack_[0].value.sval)), NULL );
    }
#line 3136 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 1230 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaImport(LOC(yylhs.location),
                            dynamic_cast<SchemaPrefix*>((yystack_[1].value.node)),
                            SYMTAB((yystack_[0].value.sval)),
                            NULL);
    }
#line 3147 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 1238 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaImport(LOC(yylhs.location),
                            NULL,
                            SYMTAB((yystack_[2].value.sval)),
                            dynamic_cast<URILiteralList*>((yystack_[0].value.node)));
    }
#line 3158 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 1246 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaImport(LOC(yylhs.location),
                            dynamic_cast<SchemaPrefix*>((yystack_[3].value.node)),
                            SYMTAB((yystack_[2].value.sval)),
                            dynamic_cast<URILiteralList*>((yystack_[0].value.node)));
    }
#line 3169 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 1255 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      URILiteralList *ull = new URILiteralList( LOC(yylhs.location));
      ull->push_back( SYMTAB((yystack_[0].value.sval)) );
      (yylhs.value.node) = ull;
    }
#line 3179 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 1262 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yystack_[2].value.node)) )
        ull->push_back( SYMTAB((yystack_[0].value.sval)) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3189 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 1270 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[1].value.expr), yystack_[1].location);
      (yylhs.value.node) = new SchemaPrefix( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)));
    }
#line 3198 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 1276 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaPrefix( LOC(yylhs.location), true );
    }
#line 3206 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 1282 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ModuleImport(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), NULL);
      dynamic_cast<ModuleImport *>((yylhs.value.node))->setComment(SYMTAB((yystack_[1].value.sval)));
    }
#line 3215 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 1288 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[2].value.expr), yystack_[2].location);
      (yylhs.value.node) = new ModuleImport(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), SYMTAB((yystack_[0].value.sval)), NULL);
      dynamic_cast<ModuleImport *>((yylhs.value.node))->setComment(SYMTAB((yystack_[4].value.sval)));
    }
#line 3225 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 1295 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ModuleImport(LOC(yylhs.location),
                            SYMTAB((yystack_[2].value.sval)),
                            dynamic_cast<URILiteralList*>((yystack_[0].value.node)));
      dynamic_cast<ModuleImport *>((yylhs.value.node))->setComment(SYMTAB((yystack_[3].value.sval)));
    }
#line 3236 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 1303 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[4].value.expr), yystack_[4].location);
      (yylhs.value.node) = new ModuleImport(LOC(yylhs.location),
                            static_cast<QName*>((yystack_[4].value.expr)),
                            SYMTAB((yystack_[2].value.sval)),
                            dynamic_cast<URILiteralList*>((yystack_[0].value.node)));
      dynamic_cast<ModuleImport *>((yylhs.value.node))->setComment(SYMTAB((yystack_[6].value.sval)));
    }
#line 3249 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 1314 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[2].value.expr), yystack_[2].location);
      (yylhs.value.node) = new NamespaceDecl( LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), SYMTAB((yystack_[0].value.sval)) );
    }
#line 3258 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 1321 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DefaultNamespaceDecl(LOC(yylhs.location),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yystack_[0].value.sval)));
    }
#line 3268 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 1328 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DefaultNamespaceDecl(LOC(yylhs.location),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yystack_[0].value.sval)));
    }
#line 3278 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 1336 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC(yylhs.location));
      vdl->push_back( (yystack_[0].value.node) );
      (yylhs.value.node) = vdl;
    }
#line 3288 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 1343 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ((VFO_DeclList*)(yystack_[2].value.node))->push_back( (yystack_[0].value.node) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3297 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 1349 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.node);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
#line 3308 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 1368 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DecimalFormatNode(LOC(yylhs.location), (yystack_[0].value.vstrpair));
      delete (yystack_[0].value.vstrpair);
    }
#line 3317 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 1374 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DecimalFormatNode(LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), (yystack_[0].value.vstrpair));
      delete (yystack_[0].value.vstrpair);
    }
#line 3326 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 1381 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.vstrpair) = new vector<string_pair_t>();
      (yylhs.value.vstrpair)->push_back( *(yystack_[0].value.strpair) );
      delete (yystack_[0].value.strpair);
    }
#line 3336 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 1388 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yystack_[1].value.vstrpair)->push_back( *(yystack_[0].value.strpair) );
      delete (yystack_[0].value.strpair);
      (yylhs.value.vstrpair) = (yystack_[1].value.vstrpair);
    }
#line 3346 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 1396 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yystack_[0].value.expr));
      (yylhs.value.strpair) = new string_pair_t( (yystack_[2].value.strval), sl->get_strval().str() );
      delete sl;
    }
#line 3356 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 1403 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "decimal-separator"; }
#line 3362 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 1404 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "digit"; }
#line 3368 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 1405 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "grouping-separator"; }
#line 3374 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 1406 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "infinity"; }
#line 3380 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 1407 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "minus-sign"; }
#line 3386 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 1408 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "NaN"; }
#line 3392 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 1409 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "pattern-separator"; }
#line 3398 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 1410 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "percent"; }
#line 3404 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 1411 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "per-mille"; }
#line 3410 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 1412 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "zero-digit"; }
#line 3416 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 1416 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new OptionDecl(LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), SYMTAB((yystack_[0].value.sval)));
      if (static_cast<QName*>((yystack_[1].value.expr))->get_localname() == "enable")
      {
        zstring opt = SYMTAB((yystack_[0].value.sval));
        if (opt.find(":") != zstring::npos)
          opt = opt.substr(opt.find(":")+1);
        if (opt == "common-language")
          driver.enableCommonLanguage();
      }
    }
#line 3432 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 1430 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FTOptionDecl( LOC(yylhs.location), dynamic_cast<FTMatchOptions*>((yystack_[0].value.node)) );
    }
#line 3440 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 1436 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3448 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 1442 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yystack_[0].value.node));
      d->theType = (yystack_[1].value.node);
      (yylhs.value.node) = d;
    }
#line 3458 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 1449 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3466 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 1455 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yystack_[0].value.node));
      d->theIsExternal = false;
      (yylhs.value.node) = d;
    }
#line 3476 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 1462 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CtxItemDecl(LOC(yylhs.location), NULL);
    }
#line 3484 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 1467 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3492 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 1473 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CtxItemDecl(LOC(yylhs.location), (yystack_[0].value.expr));
    }
#line 3500 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 1479 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      std::unique_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yystack_[2].value.varnametype)));
      (yylhs.value.node) = new GlobalVarDecl(LOC(yylhs.location),
                             nt->theName,
                             nt->theType,
                             (yystack_[0].value.expr),
                             nt->get_annotations(),
                             false);
      static_cast<GlobalVarDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[3].value.sval)));
    }
#line 3515 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 1491 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      std::unique_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yystack_[1].value.varnametype)));
      (yylhs.value.node) = new GlobalVarDecl(LOC(yylhs.location),
                             nt->theName,
                             nt->theType,
                             NULL,
                             nt->get_annotations(),
                             true);
      static_cast<GlobalVarDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[2].value.sval)));
    }
#line 3530 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 1503 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      std::unique_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yystack_[3].value.varnametype)));
      (yylhs.value.node) = new GlobalVarDecl(LOC(yylhs.location),
                             nt->theName,
                             nt->theType,
                             (yystack_[0].value.expr),
                             nt->get_annotations(),
                             true);
      static_cast<GlobalVarDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[4].value.sval)));
    }
#line 3545 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 1516 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.varnametype) = new VarNameAndType(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)), NULL, NULL);
    }
#line 3553 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 1521 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.varnametype) = new VarNameAndType(LOC(yylhs.location),
                              static_cast<QName*>((yystack_[1].value.expr)),
                              dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)),
                              NULL);
    }
#line 3564 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 116:
#line 1529 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.varnametype) = new VarNameAndType(LOC(yylhs.location),
                              static_cast<QName*>((yystack_[0].value.expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yystack_[3].value.node)));
    }
#line 3575 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 117:
#line 1537 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.varnametype) = new VarNameAndType(LOC(yylhs.location),
                              static_cast<QName*>((yystack_[1].value.expr)),
                              dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)),
                              static_cast<AnnotationListParsenode*>((yystack_[4].value.node)));
    }
#line 3586 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 118:
#line 1546 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationListParsenode(LOC(yylhs.location), static_cast<AnnotationParsenode*>((yystack_[0].value.node)));
    }
#line 3594 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 119:
#line 1551 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      static_cast<AnnotationListParsenode*>((yystack_[1].value.node))->push_back(static_cast<AnnotationParsenode*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 3603 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 120:
#line 1558 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationParsenode(LOC(yylhs.location), new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval))), NULL);
    }
#line 3611 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 121:
#line 1563 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationParsenode(LOC(yylhs.location),
                                   new QName(LOC(yylhs.location), SYMTAB((yystack_[3].value.sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yystack_[1].value.node)));
    }
#line 3621 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 122:
#line 1570 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationParsenode(LOC(yylhs.location), new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), true), NULL);
    }
#line 3629 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 123:
#line 1575 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationParsenode(LOC(yylhs.location),
                                   new QName(LOC(yylhs.location), SYMTAB((yystack_[3].value.sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yystack_[1].value.node)));
    }
#line 3639 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 124:
#line 1583 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationLiteralListParsenode(LOC(yylhs.location), (yystack_[0].value.expr));
    }
#line 3647 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 125:
#line 1588 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      static_cast<AnnotationLiteralListParsenode*>((yystack_[2].value.node))->push_back((yystack_[0].value.expr));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3656 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 126:
#line 1595 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      static_cast<FunctionDecl*>((yystack_[0].value.node))->setComment( SYMTAB((yystack_[1].value.sval)) );
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3665 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 127:
#line 1601 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yystack_[0].value.node));
      fdecl->setComment( SYMTAB((yystack_[2].value.sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yystack_[1].value.node)));
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3676 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 130:
#line 1614 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      exprnode* body = (yystack_[0].value.expr);
      if (body == NULL)
        body = new BlockBody(LOC(yystack_[0].location));
      (yylhs.value.node) = new FunctionDecl(LOC(yylhs.location),
                            static_cast<QName*>((yystack_[2].value.expr)),
                            &* (yystack_[1].value.fnsig)->theParams,
                            &* (yystack_[1].value.fnsig)->theReturnType,
                            body,
                            false,
                            false);
      delete (yystack_[1].value.fnsig);
    }
#line 3694 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 131:
#line 1628 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FunctionDecl(LOC (yylhs.location),
                            static_cast<QName*>((yystack_[2].value.expr)),
                            (yystack_[1].value.fnsig)->theParams.getp(),
                            (yystack_[1].value.fnsig)->theReturnType.getp(),
                            NULL,
                            false,
                            true);
      delete (yystack_[1].value.fnsig);
    }
#line 3709 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 132:
#line 1641 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      exprnode* body = (yystack_[0].value.expr);
      if (body == NULL)
        body = new BlockBody(LOC(yystack_[0].location));
      (yylhs.value.node) = new FunctionDecl(LOC (yylhs.location),
                            static_cast<QName*>((yystack_[2].value.expr)),
                            (yystack_[1].value.fnsig)->theParams.getp(),
                            (yystack_[1].value.fnsig)->theReturnType.getp(),
                            (yystack_[0].value.expr),
                            true,
                            false);
      delete (yystack_[1].value.fnsig);
    }
#line 3727 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 133:
#line 1656 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FunctionDecl(LOC(yylhs.location),
                            static_cast<QName*>((yystack_[2].value.expr)),
                            (yystack_[1].value.fnsig)->theParams.getp(),
                            (yystack_[1].value.fnsig)->theReturnType.getp(),
                            NULL,
                            true,
                            true);
      delete (yystack_[1].value.fnsig);
    }
#line 3742 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 134:
#line 1669 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.fnsig) = new FunctionSig(NULL);
    }
#line 3750 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 135:
#line 1674 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yystack_[1].value.node)));
    }
#line 3758 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 136:
#line 1679 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node)));
    }
#line 3766 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 137:
#line 1684 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yystack_[3].value.node)), dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node)));
    }
#line 3774 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 138:
#line 1690 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ParamList *pl = new ParamList( LOC(yylhs.location) );
      pl->push_back( dynamic_cast<Param*>((yystack_[0].value.node)) );
      (yylhs.value.node) = pl;
    }
#line 3784 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 139:
#line 1697 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yystack_[2].value.node)) )
        pl->push_back( dynamic_cast<Param*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3794 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 140:
#line 1705 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Param(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)), NULL);
    }
#line 3802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 141:
#line 1710 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Param(LOC(yylhs.location),
                     static_cast<QName*>((yystack_[1].value.expr)),
                     dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
    }
#line 3812 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 142:
#line 1718 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CollectionDecl( LOC(yylhs.location),
                              static_cast<QName*>((yystack_[0].value.expr)),
                              NULL,
                              NULL);
      static_cast<CollectionDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[2].value.sval)));
    }
#line 3824 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 143:
#line 1726 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CollectionDecl( LOC(yylhs.location),
                              static_cast<QName*>((yystack_[2].value.expr)),
                              0,
                              static_cast<SequenceTypeAST*>((yystack_[0].value.node)));
      static_cast<CollectionDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[4].value.sval)));
    }
#line 3836 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 144:
#line 1734 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CollectionDecl( LOC(yylhs.location),
                               static_cast<QName*>((yystack_[0].value.expr)),
                               static_cast<AnnotationListParsenode*>((yystack_[2].value.node)),
                               0);
      static_cast<CollectionDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[3].value.sval)));
    }
#line 3848 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 145:
#line 1742 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CollectionDecl( LOC(yylhs.location),
                               static_cast<QName*>((yystack_[2].value.expr)),
                               static_cast<AnnotationListParsenode*>((yystack_[4].value.node)),
                               static_cast<SequenceTypeAST*>((yystack_[0].value.node)));
      static_cast<CollectionDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[5].value.sval)));
    }
#line 3860 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 146:
#line 1752 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC(yylhs.location), (yystack_[0].value.node), NULL));
    }
#line 3868 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 147:
#line 1756 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC(yylhs.location),
                                                    (yystack_[1].value.node),
                                                    dynamic_cast<OccurrenceIndicator*>((yystack_[0].value.node))));
    }
#line 3878 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 148:
#line 1762 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC(yylhs.location), (yystack_[0].value.node), NULL));
    }
#line 3886 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 149:
#line 1766 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC(yylhs.location),
                                                    (yystack_[1].value.node),
                                                    dynamic_cast<OccurrenceIndicator*>((yystack_[0].value.node))));
    }
#line 3896 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 150:
#line 1773 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AST_IndexDecl(LOC(yylhs.location),
                             static_cast<QName*>((yystack_[5].value.expr)),
                             (yystack_[2].value.expr),
                             dynamic_cast<IndexKeyList*>((yystack_[0].value.node)),
                             NULL);
      static_cast<AST_IndexDecl*>((yylhs.value.node))->setComment( SYMTAB((yystack_[7].value.sval)) );
    }
#line 3909 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 151:
#line 1782 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AST_IndexDecl(LOC(yylhs.location),
                             static_cast<QName*>((yystack_[5].value.expr)),
                             (yystack_[2].value.expr),
                             dynamic_cast<IndexKeyList*>((yystack_[0].value.node)),
                             static_cast<AnnotationListParsenode*>((yystack_[7].value.node)));
      static_cast<AST_IndexDecl*>((yylhs.value.node))->setComment( SYMTAB((yystack_[8].value.sval)) );
    }
#line 3922 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 152:
#line 1793 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      IndexKeyList* keyList = new IndexKeyList(LOC(yylhs.location));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yystack_[0].value.node)));
      (yylhs.value.node) = keyList;
    }
#line 3932 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 153:
#line 1799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      dynamic_cast<IndexKeyList*>((yystack_[2].value.node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3941 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 154:
#line 1806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new IndexKeySpec(LOC(yylhs.location), (yystack_[0].value.expr), NULL, NULL);
    }
#line 3949 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 155:
#line 1811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new IndexKeySpec(LOC(yylhs.location),
                            (yystack_[1].value.expr),
                            dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node)),
                            NULL);
    }
#line 3960 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 156:
#line 1818 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new IndexKeySpec(LOC(yylhs.location),
                            (yystack_[1].value.expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node)));
    }
#line 3971 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 157:
#line 1825 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new IndexKeySpec(LOC(yylhs.location),
                            (yystack_[2].value.expr),
                            dynamic_cast<SequenceTypeAST*>((yystack_[1].value.node)),
                            dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node)));
    }
#line 3982 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 158:
#line 1835 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ICCollSimpleCheck(LOC(yylhs.location),
                                 static_cast<QName*>((yystack_[7].value.expr)),
                                 static_cast<QName*>((yystack_[4].value.expr)),
                                 static_cast<QName*>((yystack_[2].value.expr)),
                                 (yystack_[0].value.expr));
    }
#line 3994 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 159:
#line 1845 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ICCollUniqueKeyCheck(LOC(yylhs.location),
                                    static_cast<QName*>((yystack_[10].value.expr)),
                                    static_cast<QName*>((yystack_[7].value.expr)),
                                    static_cast<QName*>((yystack_[4].value.expr)),
                                    (yystack_[0].value.expr));
    }
#line 4006 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 160:
#line 1855 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ICCollForeachNode(LOC(yylhs.location),
                                 static_cast<QName*>((yystack_[9].value.expr)),
                                 static_cast<QName*>((yystack_[6].value.expr)),
                                 static_cast<QName*>((yystack_[2].value.expr)),
                                 (yystack_[0].value.expr));
    }
#line 4018 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 161:
#line 1866 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ICForeignKey( LOC(yylhs.location),
                            static_cast<QName*>((yystack_[18].value.expr)),
                            static_cast<QName*>((yystack_[13].value.expr)),
                            static_cast<QName*>((yystack_[10].value.expr)),
                            (yystack_[8].value.expr),
                            static_cast<QName*>((yystack_[5].value.expr)),
                            static_cast<QName*>((yystack_[2].value.expr)),
                            (yystack_[0].value.expr));
    }
#line 4033 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 162:
#line 1879 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if ((yystack_[0].value.expr) == NULL)
      {
        error(yystack_[0].location, "syntax error, unexpected end of file, the query body should not be empty");
        YYERROR;
      }
      if (dynamic_cast<BlockBody*>((yystack_[0].value.expr)) != NULL)
      {
        BlockBody* blk = static_cast<BlockBody*>((yystack_[0].value.expr));
        blk->setTopLevel(true);
      }
      (yylhs.value.expr) = new QueryBody(LOC(yylhs.location), (yystack_[0].value.expr));
    }
#line 4051 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 163:
#line 1895 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4059 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 164:
#line 1899 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4067 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 165:
#line 1903 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = NULL;
    }
#line 4075 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 166:
#line 1909 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4083 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 167:
#line 1913 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4091 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 168:
#line 1917 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = NULL;
    }
#line 4099 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 169:
#line 1923 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4107 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 170:
#line 1928 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      BlockBody* blk = static_cast<BlockBody*>((yystack_[1].value.expr));
      blk->add((yystack_[0].value.expr));
      (yylhs.value.expr) = blk;
    }
#line 4117 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 171:
#line 1936 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      BlockBody* blk = new BlockBody(LOC(yylhs.location));
      blk->add((yystack_[0].value.expr));
      (yylhs.value.expr) = blk;
    }
#line 4127 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 172:
#line 1943 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      BlockBody* blk = static_cast<BlockBody*>((yystack_[1].value.expr));
      blk->add((yystack_[0].value.expr));
      (yylhs.value.expr) = blk;
    }
#line 4137 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 173:
#line 1950 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[3].value.expr);
      (yylhs.value.expr) = (yystack_[2].value.expr);
      (yylhs.value.expr) = (yystack_[0].value.expr);
      error(yystack_[1].location, "syntax error, unexpected statement (missing semicolon \";\" between statements?)");
      delete (yystack_[3].value.expr);
      delete (yystack_[2].value.expr);
      delete (yystack_[0].value.expr);
      YYERROR;
    }
#line 4152 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 187:
#line 1978 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 4160 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 188:
#line 1984 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yystack_[1].value.expr));
      if ((yystack_[1].value.expr) == NULL || (block != NULL && block->isEmpty()))
      {
        driver.addCommonLanguageWarning(yystack_[2].location, ZED(ZWST0009_EMPTY_OBJECT));
        (yylhs.value.expr) = new JSONDirectObjectConstructor(LOC(yylhs.location));
      }
      else
      if ((yystack_[1].value.expr) == NULL)
      {
        (yylhs.value.expr) = new BlockBody(LOC(yylhs.location));
      }
      else if (block == NULL)
      {
        BlockBody* blk = new BlockBody(LOC(yylhs.location));
        blk->add((yystack_[1].value.expr));
        (yylhs.value.expr) = blk;
      }
      else
      {
        (yylhs.value.expr) = (yystack_[1].value.expr);
      }
    }
#line 4188 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 189:
#line 2010 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 4196 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 190:
#line 2016 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 4204 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 191:
#line 2022 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yystack_[2].value.expr));
      vdecl->add((yystack_[0].value.node));
      (yylhs.value.expr) = vdecl;
    }
#line 4214 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 192:
#line 2029 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC(yylhs.location), NULL);
      vdecl->add((yystack_[0].value.node));
      (yylhs.value.expr) = vdecl;
    }
#line 4224 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 193:
#line 2036 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC(yylhs.location),
                                           static_cast<AnnotationListParsenode*>((yystack_[2].value.node)));
      vdecl->add((yystack_[0].value.node));
      (yylhs.value.expr) = vdecl;
    }
#line 4235 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 194:
#line 2045 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC(yylhs.location),
                                          static_cast<QName*>((yystack_[0].value.expr)),
                                          NULL,
                                          NULL,
                                          NULL);
      (yylhs.value.node) = vd;
    }
#line 4248 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 195:
#line 2054 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC(yylhs.location),
                                          static_cast<QName*>((yystack_[1].value.expr)),
                                          dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node)),
                                          NULL,
                                          NULL);
      (yylhs.value.node) = vd;
    }
#line 4261 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 196:
#line 2063 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC(yylhs.location),
                                          static_cast<QName*>((yystack_[2].value.expr)),
                                          NULL,
                                          (yystack_[0].value.expr),
                                          NULL);
      (yylhs.value.node) = vd;
    }
#line 4274 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 197:
#line 2072 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC(yylhs.location),
                                          static_cast<QName*>((yystack_[3].value.expr)),
                                          dynamic_cast<SequenceTypeAST*>((yystack_[2].value.node)),
                                          (yystack_[0].value.expr),
                                          NULL);
      (yylhs.value.node) = vd;
    }
#line 4287 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 198:
#line 2083 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new AssignExpr(LOC(yylhs.location), static_cast<QName*>((yystack_[3].value.expr)), (yystack_[1].value.expr));
    }
#line 4295 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 199:
#line 2089 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new ApplyExpr(LOC(yylhs.location), (yystack_[1].value.expr));
    }
#line 4303 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 200:
#line 2095 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new ExitExpr(LOC(yylhs.location), (yystack_[1].value.expr));
    }
#line 4311 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 201:
#line 2101 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      BlockBody* bb = dynamic_cast<BlockBody *>((yystack_[0].value.expr));
      if (bb == NULL)
      {
        bb = new BlockBody((yystack_[0].value.expr)->get_location());
        bb->add((yystack_[0].value.expr));
      }
      (yylhs.value.expr) = new WhileExpr(LOC(yylhs.location), (yystack_[2].value.expr), bb);
    }
#line 4325 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 202:
#line 2113 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new FlowCtlStatement(LOC(yylhs.location), FlowCtlStatement::BREAK);
    }
#line 4333 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 203:
#line 2118 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new FlowCtlStatement( LOC(yylhs.location), FlowCtlStatement::CONTINUE );
    }
#line 4341 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 204:
#line 2124 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ReturnExpr* re = dynamic_cast<ReturnExpr*>((yystack_[0].value.expr));
      (yylhs.value.expr) = new FLWORExpr(LOC(yylhs.location),
                         dynamic_cast<FLWORClauseList*>((yystack_[1].value.node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yystack_[0].value.expr);
    }
#line 4355 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 205:
#line 2136 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      exprnode* retExpr = (yystack_[0].value.expr);
      if (dynamic_cast<VarDeclStmt*>(retExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC(yylhs.location));
        blk->add(retExpr);
        retExpr = blk;
      }
      (yylhs.value.expr) = new ReturnExpr(LOC(yylhs.location), retExpr);
    }
#line 4370 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 206:
#line 2149 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      exprnode* thenExpr = (yystack_[2].value.expr);
      exprnode* elseExpr = (yystack_[0].value.expr);
      if (dynamic_cast<VarDeclStmt*>(thenExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC(yylhs.location));
        blk->add(thenExpr);
        thenExpr = blk;
      }
      if (dynamic_cast<VarDeclStmt*>(elseExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC(yylhs.location));
        blk->add(elseExpr);
        elseExpr = blk;
      }
      (yylhs.value.expr) = new IfExpr(LOC(yylhs.location), (yystack_[5].value.expr), thenExpr, elseExpr);
    }
#line 4392 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 207:
#line 2169 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TryExpr(LOC(yylhs.location), (yystack_[1].value.expr), (yystack_[0].value.expr));
    }
#line 4400 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 208:
#line 2175 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CatchListExpr* cle = new CatchListExpr( LOC(yylhs.location) );
      cle->push_back( static_cast<CatchExpr*>((yystack_[0].value.expr)) );
      (yylhs.value.expr) = cle;
    }
#line 4410 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 209:
#line 2182 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yystack_[1].value.expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yystack_[0].value.expr)) );
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 4421 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 210:
#line 2191 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new CatchExpr(LOC(yylhs.location), *(yystack_[1].value.name_test_list), (yystack_[0].value.expr));
       delete (yystack_[1].value.name_test_list);
    }
#line 4430 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 211:
#line 2198 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new BlockBody(LOC(yylhs.location));
    }
#line 4438 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 212:
#line 2204 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4446 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 213:
#line 2209 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      Expr* expr = dynamic_cast<Expr*>((yystack_[2].value.expr));
      if ( !expr )
      {
        expr = new Expr( LOC(yylhs.location) );
        expr->push_back( (yystack_[2].value.expr) );
      }
      expr->push_back( (yystack_[0].value.expr) );
      (yylhs.value.expr) = expr;
    }
#line 4461 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 214:
#line 2221 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[2].value.expr);
      (yylhs.value.expr) = (yystack_[0].value.expr);
      if (dynamic_cast<PathExpr*>((yystack_[2].value.expr)) == NULL)
        error(yystack_[1].location, "syntax error, unexpected expression (missing comma \",\" between expressions?)");
      delete (yystack_[2].value.expr);
      delete (yystack_[0].value.expr);
      YYERROR;
    }
#line 4475 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 233:
#line 2255 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ReturnExpr *re = dynamic_cast<ReturnExpr*>((yystack_[0].value.expr));
      (yylhs.value.expr) = new FLWORExpr(LOC(yylhs.location),
                         dynamic_cast<FLWORClauseList*>((yystack_[1].value.node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yystack_[0].value.expr);
    }
#line 4489 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 234:
#line 2267 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new ReturnExpr( LOC(yylhs.location), (yystack_[0].value.expr) );
    }
#line 4497 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 236:
#line 2274 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
    }
#line 4504 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 237:
#line 2279 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.strval) = parser::the_sliding;
    }
#line 4512 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 238:
#line 2284 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.strval) = parser::the_tumbling;
    }
#line 4520 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 239:
#line 2290 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.strval) = parser::the_start;
    }
#line 4528 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 240:
#line 2295 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.strval) = parser::the_end;
    }
#line 4536 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 241:
#line 2300 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
    (yylhs.value.strval) = parser::the_only_end;
  }
#line 4544 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 242:
#line 2306 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FLWORWinCond(LOC(yylhs.location),
                            dynamic_cast<WindowVars*>((yystack_[2].value.node)),
                            (yystack_[0].value.expr),
                            (yystack_[3].value.strval) == parser::the_start,
                            (yystack_[3].value.strval) == parser::the_only_end);
    }
#line 4556 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 243:
#line 2315 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FLWORWinCond(LOC(yylhs.location),
                            NULL,
                            (yystack_[0].value.expr),
                            (yystack_[2].value.strval) == parser::the_start,
                            (yystack_[2].value.strval) == parser::the_only_end);
    }
#line 4568 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 244:
#line 2325 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowClause (LOC (yylhs.location),
                             ((yystack_[3].value.strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yystack_[2].value.node)),
                             dynamic_cast<FLWORWinCond *> ((yystack_[1].value.node)),
                             dynamic_cast<FLWORWinCond *> ((yystack_[0].value.node)));
    }
#line 4582 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 245:
#line 2335 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowClause (LOC (yylhs.location),
                             ((yystack_[2].value.strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yystack_[1].value.node)),
                             dynamic_cast<FLWORWinCond *> ((yystack_[0].value.node)), NULL);
    }
#line 4595 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 246:
#line 2346 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CountClause(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 4603 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 255:
#line 2364 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC(yylhs.location) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yystack_[0].value.node)) );
      (yylhs.value.node) = fcl;
    }
#line 4613 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 256:
#line 2371 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yystack_[1].value.node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yystack_[0].value.node)) );
      (yylhs.value.node) = fcl;
    }
#line 4623 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 257:
#line 2379 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ForClause(LOC(yylhs.location), dynamic_cast<VarInDeclList*>((yystack_[0].value.node)));
    }
#line 4631 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 258:
#line 2383 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      error(yystack_[1].location, "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yystack_[0].value.node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yystack_[0].value.node);
      YYERROR;
    }
#line 4643 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 259:
#line 2391 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      error(yystack_[1].location, "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yystack_[0].value.node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yystack_[0].value.node);
      YYERROR;
    }
#line 4655 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 260:
#line 2399 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = NULL;
      error(yystack_[0].location, "");
      YYERROR;
    }
#line 4665 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 262:
#line 2408 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
    }
#line 4672 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 263:
#line 2413 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      VarInDeclList* vdl = new VarInDeclList( LOC(yylhs.location) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yystack_[0].value.node)) );
      (yylhs.value.node) = vdl;
    }
#line 4682 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 264:
#line 2420 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yystack_[3].value.node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[3].value.node);
    }
#line 4692 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 265:
#line 2427 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node);
      error(yystack_[0].location, "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yystack_[0].value.node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yystack_[2].value.node);
      YYERROR;
    }
#line 4704 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 266:
#line 2437 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[2].value.expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yystack_[0].value.expr),
                         false);
    }
#line 4718 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 267:
#line 2447 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yystack_[0].value.expr),
                         true);
    }
#line 4732 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 268:
#line 2457 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[2].value.node)),
                         NULL,
                         NULL,
                         (yystack_[0].value.expr),
                         false);
    }
#line 4746 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 269:
#line 2467 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[5].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[4].value.node)),
                         NULL,
                         NULL,
                         (yystack_[0].value.expr),
                         true);
    }
#line 4760 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 270:
#line 2477 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yystack_[2].value.node)),
                         NULL,
                         (yystack_[0].value.expr),
                         false);
    }
#line 4774 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 271:
#line 2487 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[5].value.expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yystack_[2].value.node)),
                         NULL,
                         (yystack_[0].value.expr),
                         true);
    }
#line 4788 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 272:
#line 2497 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[3].value.node)),
                         dynamic_cast<PositionalVar*>((yystack_[2].value.node)),
                         NULL,
                         (yystack_[0].value.expr),
                         false);
    }
#line 4802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 273:
#line 2507 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[6].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[5].value.node)),
                         dynamic_cast<PositionalVar*>((yystack_[2].value.node)),
                         NULL,
                         (yystack_[0].value.expr),
                         true);
    }
#line 4816 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 274:
#line 2517 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         false);
    }
#line 4829 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 275:
#line 2526 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[3].value.node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         false);
    }
#line 4843 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 276:
#line 2536 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC (yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yystack_[3].value.node)),
                         dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         false);
    }
#line 4857 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 277:
#line 2546 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC (yylhs.location),
                         static_cast<QName*>((yystack_[5].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[4].value.node)),
                         dynamic_cast<PositionalVar*>((yystack_[3].value.node)),
                         dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         false);
    }
#line 4871 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 278:
#line 2558 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new PositionalVar(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 4879 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 279:
#line 2564 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FTScoreVar(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 4887 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 280:
#line 2570 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new LetClause( LOC(yylhs.location), dynamic_cast<VarGetsDeclList*>((yystack_[0].value.node)) );
        }
#line 4895 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 281:
#line 2576 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC(yylhs.location) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yystack_[0].value.node)) );
            (yylhs.value.node) = vgdl;
        }
#line 4905 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 282:
#line 2582 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yystack_[2].value.node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yystack_[0].value.node)) );
            (yylhs.value.node) = (yystack_[2].value.node);
        }
#line 4915 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 283:
#line 2590 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarGetsDecl(LOC (yylhs.location),
                           static_cast<QName*>((yystack_[2].value.expr)),
                           NULL,
                           NULL,
                           (yystack_[0].value.expr));
    }
#line 4927 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 284:
#line 2598 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarGetsDecl(LOC (yylhs.location),
                           static_cast<QName*>((yystack_[3].value.expr)),
                           dynamic_cast<SequenceTypeAST *>((yystack_[2].value.node)),
                           NULL,
                           (yystack_[0].value.expr));
    }
#line 4939 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 285:
#line 2606 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarGetsDecl(LOC (yylhs.location),
                           dynamic_cast<FTScoreVar*>((yystack_[2].value.node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                           (yystack_[0].value.expr));
     }
#line 4951 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 286:
#line 2614 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarGetsDecl(LOC (yylhs.location),
                           static_cast<QName*>((yystack_[4].value.expr)),
                           dynamic_cast<SequenceTypeAST *>((yystack_[3].value.node)),
                           dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                           (yystack_[0].value.expr));
    }
#line 4963 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 287:
#line 2624 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVarDecl(LOC (yylhs.location),
                             static_cast<QName*>((yystack_[2].value.expr)),
                             NULL, (yystack_[0].value.expr));
    }
#line 4973 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 288:
#line 2630 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVarDecl(LOC (yylhs.location),
                             static_cast<QName*>((yystack_[3].value.expr)),
                             dynamic_cast<SequenceTypeAST *>((yystack_[2].value.node)),
                             (yystack_[0].value.expr));
    }
#line 4984 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 290:
#line 2640 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), NULL, static_cast<QName*>((yystack_[0].value.expr)), NULL, NULL);
    }
#line 4992 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 291:
#line 2644 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      dynamic_cast<WindowVars *>((yylhs.value.node))->set_curr(static_cast<QName*>((yystack_[1].value.expr)));
    }
#line 5001 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 292:
#line 2651 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), dynamic_cast<PositionalVar*>((yystack_[0].value.node)), NULL, NULL, NULL);
    }
#line 5009 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 293:
#line 2655 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      dynamic_cast<WindowVars *>((yylhs.value.node))->set_posvar(dynamic_cast<PositionalVar*>((yystack_[1].value.node)));
    }
#line 5018 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 295:
#line 2663 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), NULL, NULL, static_cast<QName*>((yystack_[3].value.expr)), static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 5026 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 296:
#line 2667 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), NULL, NULL, NULL, static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 5034 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 297:
#line 2671 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), NULL, NULL, static_cast<QName*>((yystack_[0].value.expr)), NULL);
    }
#line 5042 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 298:
#line 2677 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WhereClause(LOC (yylhs.location), (yystack_[0].value.expr));
    }
#line 5050 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 299:
#line 2683 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupByClause(LOC(yylhs.location), dynamic_cast<GroupSpecList*>((yystack_[0].value.node)));
    }
#line 5058 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 300:
#line 2689 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      GroupSpecList* gsl = new GroupSpecList(LOC(yylhs.location));
      gsl->push_back(static_cast<GroupSpec*>((yystack_[0].value.node)));
      (yylhs.value.node) = gsl;
    }
#line 5068 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 301:
#line 2695 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yystack_[2].value.node));
      gsl->push_back(static_cast<GroupSpec*>((yystack_[0].value.node)));
      (yylhs.value.node) = gsl;
    }
#line 5078 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 302:
#line 2703 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), NULL, (yystack_[0].value.expr), NULL);
    }
#line 5086 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 303:
#line 2707 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupSpec(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         static_cast<SequenceTypeAST*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         NULL);
    }
#line 5098 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 304:
#line 2715 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupSpec(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         static_cast<SequenceTypeAST*>((yystack_[3].value.node)),
                         (yystack_[1].value.expr),
                         static_cast<GroupCollationSpec*>((yystack_[0].value.node)));
    }
#line 5110 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 305:
#line 2723 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupSpec(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         NULL,
                         (yystack_[1].value.expr),
                         static_cast<GroupCollationSpec*>((yystack_[0].value.node)));
    }
#line 5122 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 306:
#line 2731 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yystack_[0].value.expr));
      if (varRef != NULL)
        (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), varRef, NULL, NULL, NULL);
      else
        (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), NULL, NULL, (yystack_[0].value.expr), NULL);
    }
#line 5134 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 307:
#line 2739 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yystack_[1].value.expr));
      if (varRef != NULL)
        (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yystack_[0].value.node)));
      else
        (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), NULL, NULL, (yystack_[1].value.expr), static_cast<GroupCollationSpec*>((yystack_[0].value.node)));
    }
#line 5146 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 308:
#line 2749 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupCollationSpec( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 5154 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 309:
#line 2755 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderByClause(
                LOC(yylhs.location), dynamic_cast<OrderSpecList*>((yystack_[0].value.node))
            );
        }
#line 5164 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 310:
#line 2761 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderByClause(
                LOC(yylhs.location), dynamic_cast<OrderSpecList*>((yystack_[0].value.node)), true
            );
        }
#line 5174 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 311:
#line 2769 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            OrderSpecList *osl = new OrderSpecList( LOC(yylhs.location) );
            osl->push_back( dynamic_cast<OrderSpec*>((yystack_[0].value.node)) );
            (yylhs.value.node) = osl;
        }
#line 5184 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 312:
#line 2775 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yystack_[2].value.node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yystack_[0].value.node)) );
            (yylhs.value.node) = (yystack_[2].value.node);
        }
#line 5194 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 313:
#line 2783 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderSpec( LOC(yylhs.location), (yystack_[0].value.expr), NULL );
        }
#line 5202 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 314:
#line 2787 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderSpec(
                LOC(yylhs.location), (yystack_[1].value.expr), dynamic_cast<OrderModifierPN*>((yystack_[0].value.node))
            );
        }
#line 5212 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 315:
#line 2795 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location), dynamic_cast<OrderDirSpec*>((yystack_[0].value.node)), NULL, NULL
            );
        }
#line 5222 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 316:
#line 2801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location), NULL, dynamic_cast<OrderEmptySpec*>((yystack_[0].value.node)), NULL
            );
        }
#line 5232 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 317:
#line 2807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node))
            );
        }
#line 5242 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 318:
#line 2813 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location),
                dynamic_cast<OrderDirSpec*>((yystack_[1].value.node)),
                dynamic_cast<OrderEmptySpec*>((yystack_[0].value.node)),
                NULL
            );
        }
#line 5255 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 319:
#line 2822 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location),
                dynamic_cast<OrderDirSpec*>((yystack_[1].value.node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node))
            );
        }
#line 5268 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 320:
#line 2831 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yystack_[1].value.node)),
                dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node))
            );
        }
#line 5281 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 321:
#line 2840 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location),
                dynamic_cast<OrderDirSpec*>((yystack_[2].value.node)),
                dynamic_cast<OrderEmptySpec*>((yystack_[1].value.node)),
                dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node))
            );
        }
#line 5294 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 322:
#line 2851 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderDirSpec( LOC(yylhs.location), ParseConstants::dir_ascending );
        }
#line 5302 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 323:
#line 2855 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderDirSpec( LOC(yylhs.location), ParseConstants::dir_descending );
        }
#line 5310 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 324:
#line 2861 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderEmptySpec(
                LOC(yylhs.location), StaticContextConsts::empty_greatest
            );
        }
#line 5320 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 325:
#line 2867 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderEmptySpec(
                LOC(yylhs.location), StaticContextConsts::empty_least
            );
        }
#line 5330 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 326:
#line 2875 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderCollationSpec( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
        }
#line 5338 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 327:
#line 2881 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new QuantifiedExpr(
                LOC(yylhs.location),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yystack_[2].value.node)),
                (yystack_[0].value.expr)
            );
        }
#line 5351 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 328:
#line 2890 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new QuantifiedExpr(
                LOC(yylhs.location),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yystack_[2].value.node)),
                (yystack_[0].value.expr)
            );
        }
#line 5364 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 329:
#line 2901 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC(yylhs.location) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yystack_[0].value.node)) );
      (yylhs.value.node) = qvidl;
    }
#line 5374 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 330:
#line 2907 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yystack_[3].value.node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[3].value.node);
    }
#line 5384 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 331:
#line 2915 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QVarInDecl(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), (yystack_[0].value.expr));
    }
#line 5392 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 332:
#line 2919 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QVarInDecl(LOC(yylhs.location),
                          static_cast<QName*>((yystack_[3].value.expr)),
                          dynamic_cast<SequenceTypeAST *>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
    }
#line 5403 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 333:
#line 2928 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new SwitchExpr(LOC(yylhs.location), (yystack_[5].value.expr), static_cast<SwitchCaseClauseList*>((yystack_[3].value.node)), (yystack_[0].value.expr));
    }
#line 5411 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 334:
#line 2934 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC(yylhs.location));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = scc_list_p;
    }
#line 5421 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 335:
#line 2940 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yystack_[1].value.node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 5431 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 336:
#line 2948 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SwitchCaseClause(LOC(yylhs.location), dynamic_cast<SwitchCaseOperandList*>((yystack_[2].value.node)), (yystack_[0].value.expr));
    }
#line 5439 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 337:
#line 2954 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC(yylhs.location));
      sco_list_p->push_back((yystack_[0].value.expr));
      (yylhs.value.node) = sco_list_p;
    }
#line 5449 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 338:
#line 2960 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yystack_[2].value.node));
      sco_list_p->push_back((yystack_[0].value.expr));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 5459 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 339:
#line 2968 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new SwitchExpr(LOC(yylhs.location), (yystack_[5].value.expr), static_cast<SwitchCaseClauseList*>((yystack_[3].value.node)), (yystack_[0].value.expr));
    }
#line 5467 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 340:
#line 2974 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC(yylhs.location));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = scc_list_p;
    }
#line 5477 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 341:
#line 2980 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yystack_[1].value.node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 5487 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 342:
#line 2988 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SwitchCaseClause(LOC(yylhs.location), dynamic_cast<SwitchCaseOperandList*>((yystack_[2].value.node)), (yystack_[0].value.expr));
    }
#line 5495 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 343:
#line 2994 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TypeswitchExpr(LOC(yylhs.location),
                              (yystack_[5].value.expr),
                              static_cast<CaseClauseList*>((yystack_[3].value.node)),
                              (yystack_[0].value.expr));
    }
#line 5506 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 344:
#line 3001 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TypeswitchExpr(LOC (yylhs.location),
                              (yystack_[7].value.expr),
                              static_cast<CaseClauseList*>((yystack_[5].value.node)),
                              static_cast<QName*>((yystack_[2].value.expr)),
                              (yystack_[0].value.expr));
    }
#line 5518 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 345:
#line 3011 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TypeswitchExpr(LOC(yylhs.location),
                              (yystack_[5].value.expr),
                              static_cast<CaseClauseList*>((yystack_[3].value.node)),
                              (yystack_[0].value.expr));
    }
#line 5529 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 346:
#line 3018 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TypeswitchExpr(LOC (yylhs.location),
                              (yystack_[7].value.expr),
                              static_cast<CaseClauseList*>((yystack_[5].value.node)),
                              static_cast<QName*>((yystack_[2].value.expr)),
                              (yystack_[0].value.expr));
    }
#line 5541 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 347:
#line 3028 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC (yylhs.location));
      cc_list_p->push_back(static_cast<CaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = cc_list_p;
    }
#line 5551 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 348:
#line 3034 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yystack_[1].value.node));
      cc_list_p->push_back(static_cast<CaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 5561 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 349:
#line 3042 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CaseClause(LOC (yylhs.location),
                          static_cast<SequenceTypeList*>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
    }
#line 5571 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 350:
#line 3048 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CaseClause(LOC (yylhs.location),
                          static_cast<QName*>((yystack_[4].value.expr)),
                          static_cast<SequenceTypeList*>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
     }
#line 5582 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 351:
#line 3057 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC (yylhs.location));
      cc_list_p->push_back(static_cast<CaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = cc_list_p;
    }
#line 5592 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 352:
#line 3063 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yystack_[1].value.node));
      cc_list_p->push_back(static_cast<CaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 5602 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 353:
#line 3071 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CaseClause(LOC (yylhs.location),
                          static_cast<SequenceTypeList*>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
    }
#line 5612 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 354:
#line 3077 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CaseClause(LOC (yylhs.location),
                          static_cast<QName*>((yystack_[4].value.expr)),
                          static_cast<SequenceTypeList*>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
     }
#line 5623 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 355:
#line 3086 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC(yylhs.location));
      seqList->push_back(static_cast<SequenceTypeAST*>((yystack_[0].value.node)));
      (yylhs.value.node) = seqList;
    }
#line 5633 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 356:
#line 3092 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yystack_[2].value.node));
      seqList->push_back(static_cast<SequenceTypeAST*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 5643 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 357:
#line 3100 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new IfExpr(LOC (yylhs.location), (yystack_[5].value.expr), (yystack_[2].value.expr), (yystack_[0].value.expr));
    }
#line 5651 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 358:
#line 3106 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 5659 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 359:
#line 3110 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new OrExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
    }
#line 5667 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 360:
#line 3116 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5675 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 361:
#line 3121 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AndExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5683 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 362:
#line 3127 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5691 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 363:
#line 3131 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new ComparisonExpr(
              LOC(yylhs.location),
              new ValueComp( LOC(yylhs.location), ParseConstants::op_val_not ),
              (yystack_[0].value.expr),
              NULL
          );
        }
#line 5704 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 364:
#line 3142 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5712 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 365:
#line 3146 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                dynamic_cast<ValueComp*>((yystack_[1].value.node)),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5725 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 366:
#line 3155 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location), dynamic_cast<NodeComp*>((yystack_[1].value.node)), (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5735 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 367:
#line 3161 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_eq ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5748 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 368:
#line 3170 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_ne ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5761 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 369:
#line 3179 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            driver.getJsoniqLexer()->interpretAsLessThan();
        }
#line 5769 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 370:
#line 3183 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_lt ),
                (yystack_[3].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5782 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 371:
#line 3192 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_le ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5795 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 372:
#line 3201 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_gt ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 373:
#line 3210 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_ge ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5821 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 374:
#line 3221 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5829 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 375:
#line 3225 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new FTContainsExpr(
                LOC(yylhs.location),
                (yystack_[4].value.expr),
                dynamic_cast<FTSelection*>((yystack_[1].value.node)),
                dynamic_cast<FTIgnoreOption*>((yystack_[0].value.node))
            );
        }
#line 5842 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 376:
#line 3236 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5850 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 377:
#line 3240 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new StringConcatExpr(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr));
        }
#line 5858 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 378:
#line 3245 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 5866 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 379:
#line 3249 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 5874 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 380:
#line 3255 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5882 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 381:
#line 3259 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new RangeExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5890 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 382:
#line 3265 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5898 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 383:
#line 3269 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AdditiveExpr( LOC(yylhs.location), ParseConstants::op_plus, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5906 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 384:
#line 3273 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AdditiveExpr( LOC(yylhs.location), ParseConstants::op_minus, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5914 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 385:
#line 3279 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5922 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 386:
#line 3283 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new MultiplicativeExpr(
                LOC(yylhs.location), ParseConstants::op_mul, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5932 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 387:
#line 3289 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new MultiplicativeExpr(
                LOC(yylhs.location), ParseConstants::op_div, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5942 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 388:
#line 3295 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new MultiplicativeExpr(
                LOC(yylhs.location), ParseConstants::op_idiv, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5952 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 389:
#line 3301 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new MultiplicativeExpr(
                LOC(yylhs.location), ParseConstants::op_mod, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5962 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 390:
#line 3309 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5970 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 391:
#line 3313 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new UnionExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5978 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 392:
#line 3317 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new UnionExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5986 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 393:
#line 3323 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5994 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 394:
#line 3327 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new IntersectExceptExpr(
                LOC(yylhs.location), ParseConstants::op_intersect, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 6004 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 395:
#line 3333 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new IntersectExceptExpr(
                LOC(yylhs.location), ParseConstants::op_except, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 6014 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 396:
#line 3341 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6022 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 397:
#line 3345 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InstanceofExpr(
                LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node))
            );
        }
#line 6032 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 398:
#line 3353 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6040 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 399:
#line 3357 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new TreatExpr(
                LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node))
            );
        }
#line 6050 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 400:
#line 3365 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6058 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 401:
#line 3369 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new CastableExpr(
                LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<SingleType*>((yystack_[0].value.node))
            );
        }
#line 6068 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 402:
#line 3377 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6076 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 403:
#line 3381 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new CastExpr(
                LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<SingleType*>((yystack_[0].value.node))
            );
        }
#line 6086 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 404:
#line 3389 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SingleType(LOC(yylhs.location), dynamic_cast<SimpleType*>((yystack_[0].value.node)), false);
    }
#line 6094 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 405:
#line 3393 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SingleType(LOC(yylhs.location), dynamic_cast<SimpleType*>((yystack_[1].value.node)), true);
    }
#line 6102 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 406:
#line 3399 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6110 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 407:
#line 3403 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new UnaryExpr( LOC(yylhs.location), dynamic_cast<SignList*>((yystack_[1].value.node)), (yystack_[0].value.expr) );
        }
#line 6118 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 408:
#line 3409 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SignList( LOC(yylhs.location), true );
        }
#line 6126 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 409:
#line 3413 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SignList( LOC(yylhs.location), false );
        }
#line 6134 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 410:
#line 3417 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 6142 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 411:
#line 3421 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yystack_[1].value.node)) )
                sl->negate();
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 6152 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 415:
#line 3434 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.expr) = (yystack_[0].value.expr);
      }
#line 6160 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 416:
#line 3439 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.expr) = new SimpleMapExpr(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr));
      }
#line 6168 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 417:
#line 3445 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_eq );
        }
#line 6176 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 418:
#line 3449 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_ne );
        }
#line 6184 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 419:
#line 3453 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_lt );
        }
#line 6192 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 420:
#line 3457 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_le );
        }
#line 6200 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 421:
#line 3461 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_gt );
        }
#line 6208 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 422:
#line 3465 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_ge );
        }
#line 6216 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 423:
#line 3471 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NodeComp( LOC(yylhs.location), ParseConstants::op_is );
        }
#line 6224 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 424:
#line 3475 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NodeComp( LOC(yylhs.location), ParseConstants::op_precedes );
        }
#line 6232 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 425:
#line 3479 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NodeComp( LOC(yylhs.location), ParseConstants::op_follows );
        }
#line 6240 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 426:
#line 3485 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ValidateExpr( LOC(yylhs.location), "strict", (yystack_[1].value.expr) );
        }
#line 6248 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 427:
#line 3489 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ValidateExpr( LOC(yylhs.location), "lax", (yystack_[1].value.expr) );
        }
#line 6256 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 428:
#line 3493 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ValidateExpr( LOC(yylhs.location), "strict", (yystack_[1].value.expr) );
        }
#line 6264 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 429:
#line 3497 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ValidateExpr(
                LOC(yylhs.location), dynamic_cast<TypeName*>((yystack_[3].value.node))->get_name(), (yystack_[1].value.expr)
            );
            delete (yystack_[3].value.node);
        }
#line 6275 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 430:
#line 3506 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ExtensionExpr(
                LOC(yylhs.location), dynamic_cast<PragmaList*>((yystack_[3].value.node)), (yystack_[1].value.expr)
            );
        }
#line 6285 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 431:
#line 3514 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            PragmaList *pl = new PragmaList( LOC(yylhs.location) );
            pl->push_back( dynamic_cast<Pragma*>((yystack_[0].value.node)) );
            (yylhs.value.node) = pl;
        }
#line 6295 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 432:
#line 3520 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yystack_[1].value.node)) )
                pl->push_back( dynamic_cast<Pragma*>((yystack_[0].value.node)) );
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 6305 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 433:
#line 3528 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new Pragma( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), SYMTAB((yystack_[0].value.sval)) );
        }
#line 6313 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 434:
#line 3532 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new Pragma( LOC(yylhs.location), new QName( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) ), "" );
        }
#line 6321 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 435:
#line 3536 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new Pragma( LOC(yylhs.location), new QName( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), true ), "" );
        }
#line 6329 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 436:
#line 3542 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new PathExpr(LOC(yylhs.location), ParseConstants::path_leading_lone_slash, NULL);
    }
#line 6337 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 437:
#line 3546 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC(yylhs.location), ParseConstants::st_slash, NULL, (yystack_[0].value.expr), false);
      (yylhs.value.expr) = new PathExpr(LOC(yylhs.location),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
#line 6349 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 438:
#line 3554 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC(yylhs.location), ParseConstants::st_slashslash, NULL, (yystack_[0].value.expr), false);
      (yylhs.value.expr) = new PathExpr(LOC(yylhs.location),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
#line 6361 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 439:
#line 3562 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = NULL;
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yystack_[0].value.expr));
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
          driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
          (yylhs.value.expr) = new NullLiteral(LOC(yylhs.location));
          break;
        case 2:
          driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
          (yylhs.value.expr) = new BooleanLiteral(LOC(yylhs.location), false);
          break;
        case 3:
          driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_TRUE_FALSE_NULL_KEYWORDS));
          (yylhs.value.expr) = new BooleanLiteral(LOC(yylhs.location), true);
          break;
        }
      }
      if ((yylhs.value.expr) == NULL)
        (yylhs.value.expr) = (rpe ?
              new PathExpr( LOC(yylhs.location), ParseConstants::path_relative, (yystack_[0].value.expr)) :
              (yystack_[0].value.expr));
    }
#line 6399 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 440:
#line 3598 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = NULL;
    }
#line 6407 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 441:
#line 3604 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yystack_[0].value.expr));
      (yylhs.value.expr) = (as ?
            new RelativePathExpr(LOC(yylhs.location),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC(yylhs.location), true ), (yystack_[0].value.expr), true)
            :
            (yystack_[0].value.expr));
    }
#line 6421 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 442:
#line 3614 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new RelativePathExpr(LOC(yylhs.location), ParseConstants::st_slash, (yystack_[2].value.expr), (yystack_[0].value.expr), false);
    }
#line 6429 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 443:
#line 3618 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new RelativePathExpr(LOC(yylhs.location), ParseConstants::st_slashslash, (yystack_[2].value.expr), (yystack_[0].value.expr), false);
    }
#line 6437 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 446:
#line 3628 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AxisStep(
                LOC(yylhs.location), dynamic_cast<ForwardStep*>((yystack_[0].value.node)), NULL
            );
        }
#line 6447 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 447:
#line 3634 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AxisStep(
                LOC(yylhs.location),
                dynamic_cast<ForwardStep*>((yystack_[1].value.node)),
                dynamic_cast<PredicateList*>((yystack_[0].value.node))
            );
        }
#line 6459 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 448:
#line 3642 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AxisStep(
                LOC(yylhs.location), dynamic_cast<ReverseStep*>((yystack_[0].value.node)), NULL
            );
        }
#line 6469 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 449:
#line 3648 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AxisStep(
                LOC(yylhs.location),
                dynamic_cast<ReverseStep*>((yystack_[1].value.node)),
                dynamic_cast<PredicateList*>((yystack_[0].value.node))
            );
        }
#line 6481 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 450:
#line 3658 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardStep(
                LOC(yylhs.location), dynamic_cast<ForwardAxis*>((yystack_[1].value.node)), (yystack_[0].value.node)
            );
        }
#line 6491 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 451:
#line 3664 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardStep(
                LOC(yylhs.location), dynamic_cast<AbbrevForwardStep*>((yystack_[0].value.node))
            );
        }
#line 6501 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 452:
#line 3672 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_child );
        }
#line 6509 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 453:
#line 3676 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_descendant);
        }
#line 6517 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 454:
#line 3680 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_attribute );
        }
#line 6525 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 455:
#line 3684 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_self );
        }
#line 6533 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 456:
#line 3688 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis(
                LOC(yylhs.location), ParseConstants::axis_descendant_or_self
            );
        }
#line 6543 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 457:
#line 3694 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis(
                LOC(yylhs.location), ParseConstants::axis_following_sibling
            );
        }
#line 6553 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 458:
#line 3700 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_following );
        }
#line 6561 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 459:
#line 3706 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AbbrevForwardStep( LOC(yylhs.location), (yystack_[0].value.node), false );
        }
#line 6569 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 460:
#line 3710 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AbbrevForwardStep( LOC(yylhs.location), (yystack_[0].value.node), true );
        }
#line 6577 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 461:
#line 3716 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseStep( LOC(yylhs.location), dynamic_cast<ReverseAxis*>((yystack_[1].value.node)), (yystack_[0].value.node) );
        }
#line 6585 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 462:
#line 3720 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC(yylhs.location), ParseConstants::axis_parent
            );
            (yylhs.value.node) = new ReverseStep( LOC(yylhs.location), ra, NULL );
        }
#line 6596 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 463:
#line 3729 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis( LOC(yylhs.location), ParseConstants::axis_parent );
        }
#line 6604 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 464:
#line 3733 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis( LOC(yylhs.location), ParseConstants::axis_ancestor );
        }
#line 6612 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 465:
#line 3737 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis(
                LOC(yylhs.location), ParseConstants::axis_preceding_sibling
            );
        }
#line 6622 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 466:
#line 3743 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis( LOC(yylhs.location), ParseConstants::axis_preceding );
        }
#line 6630 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 467:
#line 3747 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis(
                LOC(yylhs.location), ParseConstants::axis_ancestor_or_self
            );
        }
#line 6640 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 470:
#line 3759 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NameTest( LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)) );
        }
#line 6648 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 471:
#line 3763 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NameTest( LOC(yylhs.location), dynamic_cast<Wildcard*>((yystack_[0].value.node)) );
        }
#line 6656 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 472:
#line 3769 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Wildcard(LOC(yylhs.location), "", "", ParseConstants::wild_all, false);
    }
#line 6664 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 473:
#line 3773 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Wildcard(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), "", ParseConstants::wild_elem, false);
    }
#line 6672 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 474:
#line 3777 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Wildcard(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), "", ParseConstants::wild_elem, true);
    }
#line 6680 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 475:
#line 3781 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Wildcard(LOC(yylhs.location), "", SYMTAB((yystack_[0].value.sval)), ParseConstants::wild_prefix, false);
    }
#line 6688 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 476:
#line 3787 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = (yystack_[0].value.expr);
     }
#line 6696 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 477:
#line 3791 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new FilterExpr(LOC(yylhs.location), (yystack_[1].value.expr), dynamic_cast<PredicateList*>((yystack_[0].value.node)));
     }
#line 6704 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 478:
#line 3795 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new DynamicFunctionInvocation(LOC(yylhs.location), (yystack_[2].value.expr), false);
     }
#line 6712 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 479:
#line 3799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new DynamicFunctionInvocation(LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<ArgList*>((yystack_[1].value.node)), false);
     }
#line 6720 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 480:
#line 3803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new JSONArrayUnboxing(LOC(yylhs.location), (yystack_[2].value.expr));
    }
#line 6728 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 481:
#line 3807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       ERROR_IF_QNAME_NOT_NCNAME((yystack_[0].value.expr), yystack_[0].location);
       StringLiteral* sl = new StringLiteral( LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)));
       (yylhs.value.expr) = new JSONObjectLookup(LOC(yylhs.location), LOC(yystack_[1].location), (yystack_[2].value.expr), sl);
     }
#line 6738 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 482:
#line 3813 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new JSONObjectLookup(LOC(yylhs.location), LOC(yystack_[2].location),
                                 (yystack_[3].value.expr),
                                 new ParenthesizedExpr(LOC(yylhs.location), NULL));
     }
#line 6748 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 483:
#line 3819 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new JSONObjectLookup(LOC(yylhs.location), LOC(yystack_[3].location),
                                 (yystack_[4].value.expr),
                                 new ParenthesizedExpr(LOC(yylhs.location), (yystack_[1].value.expr)));
     }
#line 6758 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 484:
#line 3825 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.expr) = new JSONObjectLookup(LOC(yylhs.location), LOC(yystack_[1].location), (yystack_[2].value.expr), (yystack_[0].value.expr));
     }
#line 6766 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 485:
#line 3829 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
        (yylhs.value.expr) = new JSONObjectLookup(LOC(yylhs.location), LOC(yystack_[1].location), (yystack_[2].value.expr), (yystack_[0].value.expr));
     }
#line 6774 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 486:
#line 3833 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new JSONObjectLookup(LOC(yylhs.location), LOC(yystack_[1].location), (yystack_[2].value.expr), (yystack_[0].value.expr));
     }
#line 6782 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 487:
#line 3839 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      PredicateList* pl = new PredicateList( LOC(yylhs.location) );
      pl->push_back(dynamic_cast<exprnode*>((yystack_[0].value.expr)));
      (yylhs.value.node) = pl;
    }
#line 6792 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 488:
#line 3845 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yystack_[1].value.node)))
        pl->push_back(dynamic_cast<exprnode*>((yystack_[0].value.expr)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 6802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 489:
#line 3853 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 6810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 504:
#line 3875 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6818 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 505:
#line 3879 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6826 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 506:
#line 3885 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = NumericLiteral::new_literal(
                LOC(yylhs.location), ParseConstants::num_decimal, *(yystack_[0].value.decval)
            );
            delete yyla.value.decval;
        }
#line 6837 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 507:
#line 3892 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = NumericLiteral::new_literal(
                LOC(yylhs.location), ParseConstants::num_integer, *(yystack_[0].value.ival)
            );
            delete yyla.value.ival;
        }
#line 6848 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 508:
#line 3899 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = NumericLiteral::new_literal(
                LOC(yylhs.location), ParseConstants::num_double, *(yystack_[0].value.dval)
            );
            delete yyla.value.dval;
        }
#line 6859 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 509:
#line 3908 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new VarRef(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)));
        }
#line 6867 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 510:
#line 3914 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ParenthesizedExpr( LOC(yylhs.location), NULL);
        }
#line 6875 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 511:
#line 3918 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ParenthesizedExpr( LOC(yylhs.location), (yystack_[1].value.expr) );
        }
#line 6883 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 512:
#line 3924 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yylhs.value.expr) = new ContextItemExpr( LOC(yylhs.location) );
        }
#line 6892 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 513:
#line 3931 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new OrderedExpr( LOC(yylhs.location), (yystack_[1].value.expr) );
        }
#line 6900 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 514:
#line 3937 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new UnorderedExpr( LOC(yylhs.location), (yystack_[1].value.expr) );
        }
#line 6908 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 515:
#line 3943 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new FunctionCall(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), NULL);
    }
#line 6916 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 516:
#line 3947 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ArgList* argList = dynamic_cast<ArgList*>((yystack_[1].value.node));
      if (argList->has_placeholder())
      {
        LiteralFunctionItem* lfi =
        new LiteralFunctionItem(LOC(yylhs.location),
                                dynamic_cast<QName*>((yystack_[3].value.expr)),
                                new Integer(argList->size()));
        (yylhs.value.expr) = new DynamicFunctionInvocation(LOC(yylhs.location), lfi, argList, true);
      }
      else
      {
        (yylhs.value.expr) = new FunctionCall(LOC(yylhs.location), static_cast<QName*>((yystack_[3].value.expr)), argList);
      }
    }
#line 6936 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 517:
#line 3965 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ArgList* al = new ArgList(LOC(yylhs.location));
      al->push_back(new ArgumentPlaceholder(LOC(yylhs.location)));
      (yylhs.value.node) = al;
    }
#line 6946 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 518:
#line 3971 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yystack_[2].value.node)))
        al->push_back(new ArgumentPlaceholder(LOC(yylhs.location)));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 6956 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 519:
#line 3977 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ArgList *al = new ArgList( LOC(yylhs.location) );
      al->push_back( (yystack_[0].value.expr) );
      (yylhs.value.node) = al;
    }
#line 6966 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 520:
#line 3983 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yystack_[2].value.node)) )
        al->push_back( (yystack_[0].value.expr) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 6976 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 521:
#line 3991 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 6984 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 522:
#line 3995 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 6992 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 523:
#line 4001 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new LiteralFunctionItem(LOC (yylhs.location), dynamic_cast<QName*>((yystack_[2].value.expr)), (yystack_[0].value.ival));
    }
#line 7000 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 524:
#line 4007 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new InlineFunction(LOC(yylhs.location),
                              &*(yystack_[1].value.fnsig)->theParams,
                              &*(yystack_[1].value.fnsig)->theReturnType,
                              (yystack_[0].value.expr));
      delete (yystack_[1].value.fnsig);
    }
#line 7012 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 530:
#line 4026 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirElemConstructor(LOC(yylhs.location),
                                  static_cast<QName*>((yystack_[2].value.expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
#line 7024 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 531:
#line 4034 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if (static_cast<QName*>((yystack_[6].value.expr))->get_qname() != static_cast<QName*>((yystack_[2].value.expr))->get_qname())
      {
        error(yystack_[3].location, "syntax error, end tag </" +
                  static_cast<QName*>((yystack_[2].value.expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yystack_[6].value.expr))->get_qname().str() + ">");
        YYERROR;
      }
      (yylhs.value.expr) = new DirElemConstructor(LOC(yylhs.location),
                                  static_cast<QName*>((yystack_[6].value.expr)),
                                  static_cast<QName*>((yystack_[2].value.expr)),
                                  NULL,
                                  NULL);
    }
#line 7044 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 532:
#line 4050 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirElemConstructor(LOC(yylhs.location),
                                  static_cast<QName*>((yystack_[3].value.expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yystack_[2].value.node)),
                                  NULL);
    }
#line 7056 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 533:
#line 4058 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if (static_cast<QName*>((yystack_[7].value.expr))->get_qname() != static_cast<QName*>((yystack_[2].value.expr))->get_qname())
      {
        error(yystack_[4].location, "syntax error, end tag </" +
                  static_cast<QName*>((yystack_[2].value.expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yystack_[7].value.expr))->get_qname().str() + ">");
        YYERROR;
      }
      (yylhs.value.expr) = new DirElemConstructor(LOC(yylhs.location),
                                  static_cast<QName*>((yystack_[7].value.expr)),
                                  static_cast<QName*>((yystack_[2].value.expr)),
                                  dynamic_cast<DirAttributeList*>((yystack_[6].value.node)),
                                  NULL);
    }
#line 7076 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 534:
#line 4076 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if (static_cast<QName*>((yystack_[7].value.expr))->get_qname() != static_cast<QName*>((yystack_[2].value.expr))->get_qname())
      {
        error(yystack_[4].location, "syntax error, end tag </" +
                  static_cast<QName*>((yystack_[2].value.expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yystack_[7].value.expr))->get_qname().str() + ">");
        YYERROR;
      }
      (yylhs.value.expr) = new DirElemConstructor(LOC(yylhs.location),
                                  static_cast<QName*>((yystack_[7].value.expr)),
                                  static_cast<QName*>((yystack_[2].value.expr)),
                                  NULL,
                                  dynamic_cast<DirElemContentList*>((yystack_[4].value.node)));
    }
#line 7096 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 535:
#line 4094 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      if (static_cast<QName*>((yystack_[8].value.expr))->get_qname() != static_cast<QName*>((yystack_[2].value.expr))->get_qname())
      {
        error(yystack_[5].location, "syntax error, end tag </" +
                  static_cast<QName*>((yystack_[2].value.expr))->get_qname().str() +
                  "> does not match start tag <" +
                  static_cast<QName*>((yystack_[8].value.expr))->get_qname().str() + ">");
        YYERROR;
      }
      (yylhs.value.expr) = new DirElemConstructor(LOC(yylhs.location),
                                  static_cast<QName*>((yystack_[8].value.expr)),
                                  static_cast<QName*>((yystack_[2].value.expr)),
                                  dynamic_cast<DirAttributeList*>((yystack_[7].value.node)),
                                  dynamic_cast<DirElemContentList*>((yystack_[4].value.node)));
    }
#line 7116 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 536:
#line 4112 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      DirElemContentList *decl = new DirElemContentList( LOC(yylhs.location) );
      decl->push_back( dynamic_cast<DirElemContent*>((yystack_[0].value.expr)) );
      (yylhs.value.node) = decl;
    }
#line 7126 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 537:
#line 4118 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yystack_[1].value.node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yystack_[0].value.expr)) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7137 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 538:
#line 4127 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      DirAttributeList *dal = new DirAttributeList( LOC(yylhs.location) );
      dal->push_back( dynamic_cast<DirAttr*>((yystack_[0].value.node)) );
      (yylhs.value.node) = dal;
    }
#line 7147 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 539:
#line 4133 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yystack_[1].value.node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7158 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 540:
#line 4142 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DirAttr(LOC(yylhs.location),
                       static_cast<QName*>((yystack_[4].value.expr)),
                       dynamic_cast<DirAttributeValue*>((yystack_[0].value.node)));
    }
#line 7168 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 543:
#line 4152 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DirAttributeValue(LOC(yylhs.location),
                                 dynamic_cast<QuoteAttrContentList*>((yystack_[1].value.node)));
    }
#line 7177 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 544:
#line 4157 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DirAttributeValue( LOC(yylhs.location),
                                  dynamic_cast<AposAttrContentList*>((yystack_[1].value.node)));
    }
#line 7186 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 545:
#line 4163 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QuoteAttrContentList( LOC(yylhs.location) );
    }
#line 7194 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 546:
#line 4167 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7202 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 547:
#line 4173 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC(yylhs.location) );
      qacl->push_back( new QuoteAttrValueContent( LOC(yylhs.location), "\"" ) );
      (yylhs.value.node) = qacl;
    }
#line 7212 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 548:
#line 4179 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC(yylhs.location) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yystack_[0].value.node)) );
      (yylhs.value.node) = qacl;
    }
#line 7222 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 549:
#line 4185 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yystack_[1].value.node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC(yylhs.location), "\"" ) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7233 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 550:
#line 4192 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yystack_[1].value.node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7244 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 551:
#line 4200 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AposAttrContentList( LOC(yylhs.location) );
    }
#line 7252 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 552:
#line 4204 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7260 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 553:
#line 4210 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC(yylhs.location) );
      aacl->push_back( new AposAttrValueContent( LOC(yylhs.location),"'") );
      (yylhs.value.node) = aacl;
    }
#line 7270 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 554:
#line 4216 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC(yylhs.location) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yystack_[0].value.node)) );
      (yylhs.value.node) = aacl;
    }
#line 7280 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 555:
#line 4222 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yystack_[1].value.node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC(yylhs.location),"'") );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7291 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 556:
#line 4229 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yystack_[1].value.node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7302 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 557:
#line 4238 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QuoteAttrValueContent( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 7310 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 558:
#line 4242 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QuoteAttrValueContent(LOC(yylhs.location), dynamic_cast<CommonContent*>((yystack_[0].value.expr)));
    }
#line 7318 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 559:
#line 4248 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AposAttrValueContent( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 7326 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 560:
#line 4252 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AposAttrValueContent(LOC(yylhs.location), dynamic_cast<CommonContent*>((yystack_[0].value.expr)));
    }
#line 7334 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 561:
#line 4258 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirElemContent( LOC(yylhs.location), (yystack_[0].value.expr) );
    }
#line 7342 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 562:
#line 4262 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirElemContent( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 7350 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 563:
#line 4266 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yystack_[0].value.expr));
      (yylhs.value.expr) = new DirElemContent( LOC(yylhs.location), cdata_h );
    }
#line 7359 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 564:
#line 4271 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yystack_[0].value.expr));
      (yylhs.value.expr) = new DirElemContent( LOC(yylhs.location), cont_h );
    }
#line 7368 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 565:
#line 4278 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CommonContent(LOC(yylhs.location), ParseConstants::cont_charref, SYMTAB((yystack_[0].value.sval)));
    }
#line 7376 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 566:
#line 4282 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CommonContent(LOC(yylhs.location), ParseConstants::cont_escape_lbrace);
    }
#line 7384 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 567:
#line 4286 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CommonContent(LOC(yylhs.location), ParseConstants::cont_escape_rbrace);
    }
#line 7392 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 568:
#line 4290 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CommonContent(LOC(yylhs.location), new EnclosedExpr(LOC(yylhs.location), (yystack_[1].value.expr)));
    }
#line 7400 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 569:
#line 4296 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirCommentConstructor( LOC(yylhs.location), SYMTAB((yystack_[1].value.sval)) );
    }
#line 7408 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 570:
#line 4301 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirCommentConstructor( LOC(yylhs.location), "" );
    }
#line 7416 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 571:
#line 4307 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[1].value.expr), yystack_[1].location);
      (yylhs.value.expr) = new DirPIConstructor( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)) );
    }
#line 7425 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 572:
#line 4313 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[1].value.expr), yystack_[1].location);
      (yylhs.value.expr) = new DirPIConstructor( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), SYMTAB((yystack_[0].value.sval)) );
    }
#line 7434 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 573:
#line 4320 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CDataSection( LOC(yylhs.location),SYMTAB((yystack_[0].value.sval)) );
    }
#line 7442 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 574:
#line 4326 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7450 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 575:
#line 4331 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7458 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 576:
#line 4336 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7466 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 577:
#line 4341 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7474 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 578:
#line 4346 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7482 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 579:
#line 4351 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7490 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 581:
#line 4359 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompDocConstructor( LOC(yylhs.location), (yystack_[1].value.expr) );
    }
#line 7498 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 582:
#line 4365 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompElemConstructor(LOC(yylhs.location), new QName(LOC(yylhs.location), SYMTAB((yystack_[2].value.sval))), (yystack_[1].value.expr));
    }
#line 7506 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 583:
#line 4369 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompElemConstructor( LOC(yylhs.location), (yystack_[4].value.expr), (yystack_[1].value.expr) );
    }
#line 7514 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 584:
#line 4375 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompAttrConstructor( LOC(yylhs.location), new QName(LOC(yylhs.location), SYMTAB((yystack_[2].value.sval))), (yystack_[1].value.expr) );
    }
#line 7522 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 585:
#line 4379 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompAttrConstructor( LOC(yylhs.location), (yystack_[4].value.expr), (yystack_[1].value.expr) );
    }
#line 7530 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 586:
#line 4385 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompTextConstructor( LOC(yylhs.location), (yystack_[1].value.expr) );
    }
#line 7538 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 587:
#line 4391 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompCommentConstructor( LOC(yylhs.location), (yystack_[1].value.expr) );
    }
#line 7546 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 588:
#line 4397 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompPIConstructor(LOC(yylhs.location), SYMTAB((yystack_[2].value.sval)), (yystack_[1].value.expr));
    }
#line 7554 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 589:
#line 4401 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompPIConstructor(LOC(yylhs.location), (yystack_[4].value.expr), (yystack_[1].value.expr));
    }
#line 7562 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 590:
#line 4407 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompNamespaceConstructor(LOC(yylhs.location), SYMTAB((yystack_[2].value.sval)), (yystack_[1].value.expr));
    }
#line 7570 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 591:
#line 4411 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompNamespaceConstructor(LOC(yylhs.location), (yystack_[4].value.expr), (yystack_[1].value.expr));
    }
#line 7578 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 592:
#line 4417 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7586 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 593:
#line 4423 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SequenceTypeAST( LOC(yylhs.location), (yystack_[0].value.node), NULL );
        }
#line 7594 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 594:
#line 4427 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SequenceTypeAST(LOC(yylhs.location), (yystack_[1].value.node), dynamic_cast<OccurrenceIndicator*>((yystack_[0].value.node)));
        }
#line 7602 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 595:
#line 4431 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SequenceTypeAST( LOC(yylhs.location), NULL, NULL );
        }
#line 7610 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 596:
#line 4435 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            driver.addCommonLanguageWarning(yystack_[1].location, ZED(ZWST0009_JSONIQ_EMPTY_SEQUENCE));
            (yylhs.value.node) = new SequenceTypeAST( LOC(yylhs.location), NULL, NULL );
        }
#line 7619 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 597:
#line 4442 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OccurrenceIndicator(
                LOC(yylhs.location), ParseConstants::occurs_optionally
            );
        }
#line 7629 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 598:
#line 4448 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OccurrenceIndicator(
                LOC(yylhs.location), ParseConstants::occurs_zero_or_more
            );
        }
#line 7639 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 599:
#line 4454 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OccurrenceIndicator(
                LOC(yylhs.location), ParseConstants::occurs_one_or_more
            );
        }
#line 7649 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 600:
#line 4462 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            GeneralizedAtomicType* gat = static_cast<GeneralizedAtomicType*>((yystack_[0].value.node));
            QName* q = gat->get_qname();
            if (q->get_qname() == "item")
            {
              driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yylhs.value.node) = new ItemType( LOC(yylhs.location), true );
              delete gat;
            }
            else if (q->get_qname() == "array")
            {
              driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yylhs.value.node) = new JSON_Test(LOC(yylhs.location), store::StoreConsts::jsonArray);
              delete gat;
            }
            else if (q->get_qname() == "object")
            {
              driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yylhs.value.node) = new JSON_Test(LOC(yylhs.location), store::StoreConsts::jsonObject);
              delete gat;
            }
            else if (q->get_qname() == "json-item")
            {
              driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yylhs.value.node) = new JSON_Test(LOC(yylhs.location), store::StoreConsts::jsonItem);
              delete gat;
            }
            else if (q->get_qname() == "structured-item")
            {
              driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yylhs.value.node) = new StructuredItemType(LOC(yylhs.location));
              delete gat;
            }
            else
            {
              (yylhs.value.node) = (yystack_[0].value.node);
            }
        }
#line 7692 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 601:
#line 4501 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 7700 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 602:
#line 4505 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ItemType( LOC(yylhs.location), true );
        }
#line 7708 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 603:
#line 4509 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new StructuredItemType(LOC(yylhs.location));
        }
#line 7716 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 604:
#line 4513 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 7724 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 605:
#line 4517 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 7732 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 606:
#line 4521 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 7740 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 607:
#line 4527 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          TypeList* aTypeList = new TypeList(LOC (yylhs.location));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
          (yylhs.value.node) = aTypeList;
        }
#line 7750 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 608:
#line 4533 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yystack_[2].value.node));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
          (yylhs.value.node) = (yystack_[2].value.node);
        }
#line 7760 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 609:
#line 4541 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GeneralizedAtomicType( LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)) );
    }
#line 7768 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 610:
#line 4547 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SimpleType( LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)) );
    }
#line 7776 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 611:
#line 4553 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7784 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 612:
#line 4557 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7792 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 613:
#line 4561 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 614:
#line 4565 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 615:
#line 4569 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7816 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 616:
#line 4573 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7824 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 617:
#line 4577 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7832 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 618:
#line 4581 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7840 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 619:
#line 4585 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7848 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 620:
#line 4589 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7856 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 621:
#line 4595 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnyKindTest( LOC(yylhs.location) );
    }
#line 7864 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 622:
#line 4601 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = NULL;
    }
#line 7872 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 623:
#line 4607 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DocumentTest(LOC(yylhs.location));
    }
#line 7880 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 624:
#line 4611 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DocumentTest(LOC(yylhs.location), dynamic_cast<ElementTest*>((yystack_[1].value.node)));
    }
#line 7888 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 625:
#line 4615 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DocumentTest(LOC(yylhs.location), dynamic_cast<SchemaElementTest*>((yystack_[1].value.node)));
    }
#line 7896 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 626:
#line 4621 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new NamespaceTest(LOC(yylhs.location));
    }
#line 7904 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 627:
#line 4626 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new TextTest(LOC(yylhs.location));
    }
#line 7912 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 628:
#line 4632 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CommentTest(LOC(yylhs.location));
    }
#line 7920 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 629:
#line 4638 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new PITest( LOC(yylhs.location), "" );
        }
#line 7928 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 630:
#line 4642 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            ERROR_IF_QNAME_NOT_NCNAME((yystack_[1].value.expr), yystack_[1].location);
            (yylhs.value.node) = new PITest( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)) );
        }
#line 7937 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 631:
#line 4647 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new PITest( LOC(yylhs.location), SYMTAB((yystack_[1].value.sval)) );
        }
#line 7945 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 632:
#line 4653 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest( LOC(yylhs.location), NULL, NULL );
        }
#line 7953 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 633:
#line 4657 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest(
                LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), NULL
            );
        }
#line 7963 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 634:
#line 4663 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest(
                LOC(yylhs.location), static_cast<QName*>((yystack_[3].value.expr)), dynamic_cast<TypeName*>((yystack_[1].value.node))
            );
        }
#line 7973 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 635:
#line 4669 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest( LOC(yylhs.location), NULL, NULL );
        }
#line 7981 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 636:
#line 4673 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest(
                LOC(yylhs.location), NULL, dynamic_cast<TypeName*>((yystack_[1].value.node))
            );
        }
#line 7991 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 637:
#line 4681 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SchemaAttributeTest( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)) );
        }
#line 7999 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 638:
#line 4687 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest( LOC(yylhs.location), NULL, NULL, true );
        }
#line 8007 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 639:
#line 4691 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), NULL, true
            );
        }
#line 8017 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 640:
#line 4697 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location),
                static_cast<QName*>((yystack_[3].value.expr)),
                dynamic_cast<TypeName*>((yystack_[1].value.node)),
                false
            );
        }
#line 8030 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 641:
#line 4706 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location),
                static_cast<QName*>((yystack_[3].value.expr)),
                dynamic_cast<TypeName*>((yystack_[1].value.node)),
                true
            );
        }
#line 8043 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 642:
#line 4715 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location), NULL, NULL, true
            );
        }
#line 8053 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 643:
#line 4721 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location), NULL, dynamic_cast<TypeName*>((yystack_[1].value.node)), false
            );
        }
#line 8063 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 644:
#line 4727 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location), NULL, dynamic_cast<TypeName*>((yystack_[1].value.node)), true
            );
        }
#line 8073 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 645:
#line 4735 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SchemaElementTest( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)) );
        }
#line 8081 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 646:
#line 4741 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new TypeName( LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)) );
        }
#line 8089 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 647:
#line 4747 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new TypeName( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), true );
        }
#line 8097 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 648:
#line 4753 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new StringLiteral( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
        }
#line 8105 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 649:
#line 4759 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 8113 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 650:
#line 4763 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 8121 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 651:
#line 4769 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnyFunctionTest(LOC(yylhs.location));
    }
#line 8129 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 652:
#line 4775 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new TypedFunctionTest(LOC (yylhs.location), dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
        }
#line 8137 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 653:
#line 4779 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new TypedFunctionTest(LOC (yylhs.location),
              dynamic_cast<TypeList *>((yystack_[3].value.node)),
              dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
        }
#line 8147 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 654:
#line 4787 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
           (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 8155 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 655:
#line 4793 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new RevalidationDecl(
                LOC(yylhs.location), StaticContextConsts::strict_validation
            );
        }
#line 8165 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 656:
#line 4799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new RevalidationDecl(
                LOC(yylhs.location), StaticContextConsts::lax_validation
            );
        }
#line 8175 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 657:
#line 4805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new RevalidationDecl(
                LOC(yylhs.location), StaticContextConsts::skip_validation
            );
        }
#line 8185 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 658:
#line 4813 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr( LOC(yylhs.location), store::UpdateConsts::INTO, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 8193 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 659:
#line 4817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC(yylhs.location), store::UpdateConsts::AS_FIRST_INTO, (yystack_[4].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8203 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 660:
#line 4823 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC(yylhs.location), store::UpdateConsts::AS_LAST_INTO, (yystack_[4].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8213 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 661:
#line 4829 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr( LOC(yylhs.location), store::UpdateConsts::AFTER, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 8221 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 662:
#line 4833 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC (yylhs.location), store::UpdateConsts::BEFORE, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8231 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 663:
#line 4839 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr( LOC(yylhs.location), store::UpdateConsts::INTO, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 8239 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 664:
#line 4843 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC(yylhs.location), store::UpdateConsts::AS_FIRST_INTO, (yystack_[4].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8249 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 665:
#line 4849 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                  LOC(yylhs.location), store::UpdateConsts::AS_LAST_INTO, (yystack_[4].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8259 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 666:
#line 4855 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC (yylhs.location),
                store::UpdateConsts::AFTER, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8270 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 667:
#line 4862 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC (yylhs.location), store::UpdateConsts::BEFORE, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8280 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 668:
#line 4870 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new DeleteExpr( LOC (yylhs.location), (yystack_[0].value.expr) );
        }
#line 8288 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 669:
#line 4875 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new DeleteExpr( LOC (yylhs.location), (yystack_[0].value.expr) );
        }
#line 8296 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 670:
#line 4881 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ReplaceExpr(
                LOC(yylhs.location), store::UpdateConsts::NODE, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8306 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 671:
#line 4887 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ReplaceExpr(
                LOC(yylhs.location), store::UpdateConsts::VALUE_OF_NODE, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8316 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 672:
#line 4895 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new RenameExpr( LOC (yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 8324 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 673:
#line 4901 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yystack_[4].value.expr));
      (yylhs.value.expr) = new TransformExpr( LOC(yylhs.location), cvl, (yystack_[2].value.expr), (yystack_[0].value.expr) );
    }
#line 8333 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 674:
#line 4908 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CopyVarList* lList = new CopyVarList(LOC(yylhs.location));
      lList->push_back (dynamic_cast<VarBinding*> ((yystack_[0].value.expr)));
      (yylhs.value.expr) = lList;
    }
#line 8343 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 675:
#line 4914 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yystack_[3].value.expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yystack_[0].value.expr));
      lList->push_back(lBinding);
      (yylhs.value.expr) = lList;
    }
#line 8354 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 676:
#line 4923 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new VarBinding(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), (yystack_[0].value.expr));
    }
#line 8362 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 677:
#line 4929 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new TryExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 8370 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 678:
#line 4935 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            CatchListExpr *cle = new CatchListExpr( LOC(yylhs.location) );
            cle->push_back( static_cast<CatchExpr*>((yystack_[0].value.expr)) );
            (yylhs.value.expr) = cle;
        }
#line 8380 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 679:
#line 4941 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yystack_[1].value.expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yystack_[0].value.expr)) );
            (yylhs.value.expr) = (yystack_[1].value.expr);
        }
#line 8391 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 680:
#line 4950 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new CatchExpr(LOC(yylhs.location), *(yystack_[1].value.name_test_list), (yystack_[0].value.expr));
       delete (yystack_[1].value.name_test_list);
    }
#line 8400 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 681:
#line 4957 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 8408 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 682:
#line 4963 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yystack_[0].value.node)) );
            (yylhs.value.name_test_list) = ntl;
        }
#line 8418 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 683:
#line 4969 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yystack_[2].value.name_test_list));
            ntl->push_back( static_cast<NameTest*>((yystack_[0].value.node)) );
            (yylhs.value.name_test_list) = ntl;
        }
#line 8429 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 684:
#line 4978 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTSelection( LOC(yylhs.location), (yystack_[1].value.node), (yystack_[0].value.pos_filter_list) );
            delete (yystack_[0].value.pos_filter_list);
        }
#line 8438 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 685:
#line 4985 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.pos_filter_list) = NULL;
        }
#line 8446 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 686:
#line 4989 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.pos_filter_list) = (yystack_[0].value.pos_filter_list);
        }
#line 8454 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 687:
#line 4995 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yylhs.value.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yystack_[0].value.node)) );
        }
#line 8463 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 688:
#line 5000 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yystack_[1].value.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yystack_[0].value.node)) );
            (yylhs.value.pos_filter_list) = (yystack_[1].value.pos_filter_list);
        }
#line 8472 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 689:
#line 5007 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8480 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 690:
#line 5011 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTOr( LOC(yylhs.location), (yystack_[2].value.node), (yystack_[0].value.node) );
        }
#line 8488 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 691:
#line 5017 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8496 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 692:
#line 5021 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnd( LOC(yylhs.location), (yystack_[2].value.node), (yystack_[0].value.node) );
        }
#line 8504 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 693:
#line 5027 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8512 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 694:
#line 5031 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTMildNot( LOC(yylhs.location), (yystack_[3].value.node), (yystack_[0].value.node) );
        }
#line 8520 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 695:
#line 5037 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8528 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 696:
#line 5041 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTUnaryNot(
                LOC(yylhs.location), dynamic_cast<FTPrimaryWithOptions*>((yystack_[0].value.node))
            );
        }
#line 8538 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 697:
#line 5049 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTPrimaryWithOptions(
                LOC(yylhs.location),
                dynamic_cast<FTPrimary*>((yystack_[2].value.node)),
                dynamic_cast<FTMatchOptions*>((yystack_[1].value.node)),
                dynamic_cast<FTWeight*>((yystack_[0].value.node))
            );
        }
#line 8551 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 698:
#line 5059 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8559 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 699:
#line 5063 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8567 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 700:
#line 5068 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8575 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 701:
#line 5072 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8583 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 702:
#line 5078 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWeight( LOC(yylhs.location), dynamic_cast<exprnode*>((yystack_[1].value.expr)) );
        }
#line 8591 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 703:
#line 5084 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWordsTimes(
                LOC(yylhs.location),
                dynamic_cast<FTWords*>((yystack_[1].value.node)),
                dynamic_cast<FTTimes*>((yystack_[0].value.node))
            );
        }
#line 8603 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 704:
#line 5092 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 8611 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 705:
#line 5096 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8619 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 706:
#line 5101 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8627 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 707:
#line 5105 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8635 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 708:
#line 5111 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTExtensionSelection(
                LOC(yylhs.location),
                dynamic_cast<PragmaList*>((yystack_[3].value.node)),
                dynamic_cast<FTSelection*>((yystack_[1].value.node))
            );
        }
#line 8647 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 709:
#line 5120 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8655 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 710:
#line 5124 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8663 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 711:
#line 5130 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWords(
                LOC(yylhs.location),
                dynamic_cast<FTWordsValue*>((yystack_[1].value.node)),
                dynamic_cast<FTAnyallOption*>((yystack_[0].value.node))
            );
        }
#line 8675 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 712:
#line 5140 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWordsValue(
                LOC(yylhs.location), static_cast<StringLiteral*>((yystack_[0].value.expr)), NULL
            );
        }
#line 8685 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 713:
#line 5146 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWordsValue(
                LOC(yylhs.location), NULL, dynamic_cast<exprnode*>((yystack_[1].value.expr))
            );
        }
#line 8695 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 714:
#line 5153 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnyallOption( LOC(yylhs.location), ft_anyall_mode::any );
        }
#line 8703 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 715:
#line 5157 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8711 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 716:
#line 5163 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnyallOption( LOC(yylhs.location), (yystack_[0].value.ft_anyall_value) );
        }
#line 8719 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 717:
#line 5167 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnyallOption( LOC(yylhs.location), (yystack_[0].value.ft_anyall_value) );
        }
#line 8727 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 718:
#line 5171 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnyallOption( LOC(yylhs.location), ft_anyall_mode::phrase );
        }
#line 8735 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 719:
#line 5176 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.ft_anyall_value) = ft_anyall_mode::any;
        }
#line 8743 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 720:
#line 5180 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.ft_anyall_value) = ft_anyall_mode::any_word;
        }
#line 8751 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 721:
#line 5185 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.ft_anyall_value) = ft_anyall_mode::all;
        }
#line 8759 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 722:
#line 5189 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.ft_anyall_value) = ft_anyall_mode::all_words;
        }
#line 8767 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 723:
#line 5195 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8775 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 724:
#line 5199 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8783 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 725:
#line 5203 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8791 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 726:
#line 5207 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 727:
#line 5211 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 728:
#line 5217 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTOrder( LOC(yylhs.location) );
        }
#line 8815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 729:
#line 5223 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWindow(
                LOC(yylhs.location),
                static_cast<AdditiveExpr*>((yystack_[1].value.expr)),
                static_cast<FTUnit*>((yystack_[0].value.node))
            );
        }
#line 8827 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 730:
#line 5233 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTDistance(
                LOC(yylhs.location),
                dynamic_cast<FTRange*>((yystack_[1].value.node)),
                dynamic_cast<FTUnit*>((yystack_[0].value.node))
            );
        }
#line 8839 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 731:
#line 5243 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTUnit( LOC(yylhs.location), ft_unit::words );
        }
#line 8847 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 732:
#line 5247 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTUnit( LOC(yylhs.location), ft_unit::sentences );
        }
#line 8855 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 733:
#line 5251 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTUnit( LOC(yylhs.location), ft_unit::paragraphs );
        }
#line 8863 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 734:
#line 5257 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC(yylhs.location) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yystack_[0].value.node)) );
            (yylhs.value.node) = mo;
        }
#line 8873 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 735:
#line 5263 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yystack_[2].value.node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yystack_[0].value.node)) );
            (yylhs.value.node) = (yystack_[2].value.node);
        }
#line 8883 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 736:
#line 5271 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8891 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 737:
#line 5275 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8899 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 738:
#line 5279 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8907 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 739:
#line 5283 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8915 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 740:
#line 5287 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8923 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 741:
#line 5291 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8931 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 742:
#line 5295 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8939 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 743:
#line 5299 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8947 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 744:
#line 5305 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTCaseOption( LOC(yylhs.location), ft_case_mode::sensitive );
        }
#line 8955 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 745:
#line 5309 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTCaseOption( LOC(yylhs.location), ft_case_mode::insensitive );
        }
#line 8963 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 746:
#line 5313 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTCaseOption( LOC(yylhs.location), ft_case_mode::lower );
        }
#line 8971 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 747:
#line 5317 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTCaseOption( LOC(yylhs.location), ft_case_mode::upper );
        }
#line 8979 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 748:
#line 5323 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTDiacriticsOption(
                LOC(yylhs.location), ft_diacritics_mode::sensitive
            );
        }
#line 8989 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 749:
#line 5329 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTDiacriticsOption(
                LOC(yylhs.location), ft_diacritics_mode::insensitive
            );
        }
#line 8999 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 750:
#line 5337 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTExtensionOption(
                LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), SYMTAB((yystack_[0].value.sval))
            );
        }
#line 9009 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 751:
#line 5345 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStemOption( LOC(yylhs.location), ft_stem_mode::stemming );
        }
#line 9017 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 752:
#line 5349 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStemOption( LOC(yylhs.location), ft_stem_mode::no_stemming );
        }
#line 9025 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 753:
#line 5355 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( (yystack_[0].value.node) ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yystack_[0].value.node)) );
            }
            (yylhs.value.node) = new FTThesaurusOption( LOC(yylhs.location), til, !til );
            delete til;
        }
#line 9039 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 754:
#line 5365 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            FTThesaurusOption::thesaurus_id_list_t *til = (yystack_[1].value.thesaurus_id_list);
            if ( (yystack_[2].value.node) ) {
                if ( !til )
                    til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yystack_[2].value.node)) );
            }
            (yylhs.value.node) = new FTThesaurusOption( LOC(yylhs.location), til, !(yystack_[2].value.node) );
            delete til;
        }
#line 9054 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 755:
#line 5376 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTThesaurusOption( LOC(yylhs.location), NULL, false, true );
        }
#line 9062 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 756:
#line 5382 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 9070 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 757:
#line 5386 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 9078 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 758:
#line 5391 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.thesaurus_id_list) = NULL;
        }
#line 9086 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 759:
#line 5395 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.thesaurus_id_list) = (yystack_[0].value.thesaurus_id_list);
        }
#line 9094 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 760:
#line 5401 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yylhs.value.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yystack_[0].value.node)) );
        }
#line 9103 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 761:
#line 5406 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yystack_[2].value.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yystack_[0].value.node)) );
            (yylhs.value.thesaurus_id_list) = (yystack_[2].value.thesaurus_id_list);
        }
#line 9112 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 762:
#line 5413 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTThesaurusID(
                LOC(yylhs.location), SYMTAB((yystack_[2].value.sval)), SYMTAB((yystack_[1].value.sval)), dynamic_cast<FTRange*>((yystack_[0].value.node))
            );
        }
#line 9122 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 763:
#line 5420 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.sval) = 0;
        }
#line 9130 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 764:
#line 5424 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.sval) = (yystack_[0].value.sval);
        }
#line 9138 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 765:
#line 5430 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 9146 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 766:
#line 5434 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 9154 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 767:
#line 5440 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordOption(
                LOC(yylhs.location),
                dynamic_cast<FTStopWords*>((yystack_[1].value.node)), (yystack_[0].value.incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yystack_[0].value.incl_excl_list);
        }
#line 9167 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 768:
#line 5449 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordOption(
                LOC(yylhs.location), NULL, (yystack_[0].value.incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yystack_[0].value.incl_excl_list);
        }
#line 9178 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 769:
#line 5456 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordOption(
                LOC(yylhs.location), NULL, NULL, ft_stop_words_mode::without
            );
        }
#line 9188 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 770:
#line 5464 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWords( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), NULL );
        }
#line 9196 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 771:
#line 5468 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWords( LOC(yylhs.location), "", (yystack_[1].value.strlist) );
        }
#line 9204 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 772:
#line 5474 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yystack_[0].value.sval)) );
            (yylhs.value.strlist) = sl;
        }
#line 9214 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 773:
#line 5480 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            if ( (yystack_[2].value.strlist) )
                (yystack_[2].value.strlist)->push_back( SYMTAB((yystack_[0].value.sval)) );
            (yylhs.value.strlist) = (yystack_[2].value.strlist);
        }
#line 9224 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 774:
#line 5487 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.incl_excl_list) = NULL;
        }
#line 9232 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 775:
#line 5491 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.incl_excl_list) = (yystack_[0].value.incl_excl_list);
        }
#line 9240 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 776:
#line 5497 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yylhs.value.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yystack_[0].value.node)) );
        }
#line 9249 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 777:
#line 5502 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            FTStopWordOption::incl_excl_list_t *iel = (yystack_[1].value.incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yystack_[0].value.node)) );
            (yylhs.value.incl_excl_list) = iel;
        }
#line 9261 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 778:
#line 5512 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordsInclExcl(
                LOC(yylhs.location),
                dynamic_cast<FTStopWords*>((yystack_[0].value.node)),
                ft_stop_words_unex::union_
            );
        }
#line 9273 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 779:
#line 5520 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordsInclExcl(
                LOC(yylhs.location),
                dynamic_cast<FTStopWords*>((yystack_[0].value.node)),
                ft_stop_words_unex::except
            );
        }
#line 9285 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 780:
#line 5530 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTLanguageOption( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
        }
#line 9293 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 781:
#line 5536 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWildCardOption( LOC(yylhs.location), ft_wild_card_mode::with );
        }
#line 9301 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 782:
#line 5540 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWildCardOption( LOC(yylhs.location), ft_wild_card_mode::without );
        }
#line 9309 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 783:
#line 5546 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTContent( LOC(yylhs.location), ft_content_mode::at_start );
        }
#line 9317 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 784:
#line 5550 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTContent( LOC(yylhs.location), ft_content_mode::at_end );
        }
#line 9325 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 785:
#line 5554 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTContent( LOC(yylhs.location), ft_content_mode::entire );
        }
#line 9333 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 786:
#line 5560 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTTimes( LOC(yylhs.location), dynamic_cast<FTRange*>((yystack_[1].value.node)) );
        }
#line 9341 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 787:
#line 5566 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTRange( LOC(yylhs.location), ft_range_mode::exactly, (yystack_[0].value.expr) );
        }
#line 9349 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 788:
#line 5570 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTRange( LOC(yylhs.location), ft_range_mode::at_least, (yystack_[0].value.expr) );
        }
#line 9357 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 789:
#line 5574 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTRange( LOC(yylhs.location), ft_range_mode::at_most, (yystack_[0].value.expr) );
        }
#line 9365 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 790:
#line 5578 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTRange( LOC(yylhs.location), ft_range_mode::from_to, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 9373 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 791:
#line 5584 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTScope(
                LOC(yylhs.location),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yystack_[0].value.node))
            );
        }
#line 9385 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 792:
#line 5592 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTScope(
                LOC(yylhs.location),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yystack_[0].value.node))
            );
        }
#line 9397 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 793:
#line 5602 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTBigUnit( LOC(yylhs.location), ft_big_unit::sentence );
        }
#line 9405 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 794:
#line 5606 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTBigUnit( LOC(yylhs.location), ft_big_unit::paragraph );
        }
#line 9413 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 795:
#line 5612 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTIgnoreOption( LOC(yylhs.location), static_cast<UnionExpr*>((yystack_[0].value.expr)) );
        }
#line 9421 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 796:
#line 5618 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONArrayConstructor( LOC(yylhs.location), NULL );
        }
#line 9429 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 797:
#line 5622 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONArrayConstructor( LOC(yylhs.location), (yystack_[1].value.expr) );
        }
#line 9437 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 798:
#line 5628 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectConstructor(LOC(yylhs.location), NULL, false);
        }
#line 9445 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 799:
#line 5632 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectConstructor(LOC(yylhs.location), (yystack_[1].value.expr), false);
        }
#line 9453 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 800:
#line 5638 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectConstructor(LOC(yylhs.location), NULL, true);
        }
#line 9461 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 801:
#line 5642 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectConstructor(LOC(yylhs.location), (yystack_[1].value.expr), true);
        }
#line 9469 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 802:
#line 5648 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONDirectObjectConstructor(LOC(yylhs.location),
                                               dynamic_cast<JSONPairList*>((yystack_[1].value.node)));
        }
#line 9478 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 803:
#line 5655 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          ERROR_IF_QNAME_NOT_NCNAME((yystack_[2].value.expr), yystack_[2].location);
          driver.addCommonLanguageWarning(yystack_[2].location, ZED(ZWST0009_OBJECT_KEY_NOT_QUOTED));
          StringLiteral* sl = new StringLiteral( LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)) );
          JSONPairList* jpl = new JSONPairList(LOC(yylhs.location));
          jpl->push_back(new JSONPairConstructor(LOC(yylhs.location), sl, (yystack_[0].value.expr)));
          (yylhs.value.node) = jpl;
        }
#line 9491 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 804:
#line 5665 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          JSONPairList* jpl = new JSONPairList(LOC(yylhs.location));
          jpl->push_back(new JSONPairConstructor(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr)));
          (yylhs.value.node) = jpl;
        }
#line 9501 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 805:
#line 5671 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yystack_[4].value.node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr)));
          (yylhs.value.node) = jpl;
        }
#line 9512 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 806:
#line 5678 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          ERROR_IF_QNAME_NOT_NCNAME((yystack_[2].value.expr), yystack_[2].location);
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yystack_[4].value.node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)) );
          jpl->push_back(new JSONPairConstructor(LOC(yylhs.location), sl, (yystack_[0].value.expr)));
          (yylhs.value.node) = jpl;
        }
#line 9525 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 807:
#line 5689 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectInsertExpr(LOC(yylhs.location),
                                        (yystack_[2].value.expr),
                                        (yystack_[0].value.expr));
        }
#line 9535 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 808:
#line 5695 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yystack_[2].value.node));
          (yylhs.value.expr) = new JSONObjectInsertExpr(
              LOC(yylhs.location),
              new JSONDirectObjectConstructor(
                  LOC(yylhs.location),
                  jpl),
              (yystack_[0].value.expr));
        }
#line 9549 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 809:
#line 5705 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONArrayInsertExpr(LOC(yylhs.location), (yystack_[5].value.expr), (yystack_[3].value.expr), (yystack_[0].value.expr));
        }
#line 9557 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 810:
#line 5711 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONArrayAppendExpr(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr));
        }
#line 9565 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 811:
#line 5717 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          rchandle<exprnode> lTargetExpr;
          rchandle<exprnode> lSelectorExpr;
          string lError;
          if (!convert_postfix_to_target_and_selector((yystack_[0].value.expr), &lTargetExpr, &lSelectorExpr, &lError))
          {
            error(yystack_[1].location, lError);
            YYERROR;
          }
          (yylhs.value.expr) = new JSONDeleteExpr(
              LOC(yylhs.location),
              lTargetExpr,
              lSelectorExpr);
        }
#line 9584 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 812:
#line 5734 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          rchandle<exprnode> lTargetExpr;
          rchandle<exprnode> lSelectorExpr;
          string lError;
          if (!convert_postfix_to_target_and_selector(
              (yystack_[2].value.expr),
              &lTargetExpr,
              &lSelectorExpr,
              &lError,
              false))
          {
            error(yystack_[2].location, lError);
            delete (yystack_[0].value.expr);
            YYERROR;
          }
          (yylhs.value.expr) = new JSONRenameExpr(
                LOC(yylhs.location),
                lTargetExpr,
                lSelectorExpr,
                (yystack_[0].value.expr));
        }
#line 9610 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 813:
#line 5758 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          rchandle<exprnode> lTargetExpr;
          rchandle<exprnode> lSelectorExpr;
          string lError;
          if (!convert_postfix_to_target_and_selector((yystack_[2].value.expr), &lTargetExpr, &lSelectorExpr, &lError))
          {
            error(yystack_[2].location, lError);
            delete (yystack_[0].value.expr);
            YYERROR;
          }
          (yylhs.value.expr) = new JSONReplaceExpr(
                LOC(yylhs.location),
                lTargetExpr,
                lSelectorExpr,
                (yystack_[0].value.expr));
        }
#line 9631 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 814:
#line 5777 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new JSON_Test(LOC(yylhs.location), store::StoreConsts::jsonItem);
        }
#line 9639 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 815:
#line 5781 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new JSON_Test(LOC(yylhs.location), store::StoreConsts::jsonArray);
        }
#line 9647 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 816:
#line 5785 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new JSON_Test(LOC(yylhs.location), store::StoreConsts::jsonObject);
        }
#line 9655 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 819:
#line 5794 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval))); }
#line 9661 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 820:
#line 5795 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("attribute"))); }
#line 9667 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 821:
#line 5796 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("comment"))); }
#line 9673 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 822:
#line 5797 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("document-node"))); }
#line 9679 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 823:
#line 5798 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("namespace-node"))); }
#line 9685 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 824:
#line 5799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("element"))); }
#line 9691 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 825:
#line 5800 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("item"))); }
#line 9697 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 826:
#line 5801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("if"))); }
#line 9703 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 827:
#line 5802 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("node"))); }
#line 9709 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 828:
#line 5803 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
#line 9715 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 829:
#line 5804 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
#line 9721 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 830:
#line 5805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("schema-element"))); }
#line 9727 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 831:
#line 5806 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("text"))); }
#line 9733 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 832:
#line 5807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("typeswitch"))); }
#line 9739 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 833:
#line 5808 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("switch"))); }
#line 9745 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 834:
#line 5809 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
#line 9751 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 835:
#line 5810 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("while"))); }
#line 9757 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 836:
#line 5811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("json"))); }
#line 9763 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 837:
#line 5812 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("array"))); }
#line 9769 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 838:
#line 5813 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("object"))); }
#line 9775 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 839:
#line 5814 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("json-item"))); }
#line 9781 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 840:
#line 5815 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("structured-item"))); }
#line 9787 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 842:
#line 5819 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval))); }
#line 9793 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 843:
#line 5820 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("xquery"))); }
#line 9799 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 844:
#line 5821 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("empty"))); }
#line 9805 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 845:
#line 5822 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("boundary-space"))); }
#line 9811 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 846:
#line 5823 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ft-option"))); }
#line 9817 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 847:
#line 5824 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("base-uri"))); }
#line 9823 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 848:
#line 5825 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("lax"))); }
#line 9829 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 849:
#line 5826 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("strict"))); }
#line 9835 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 850:
#line 5827 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("idiv"))); }
#line 9841 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 851:
#line 5828 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("document"))); }
#line 9847 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 852:
#line 5829 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ftnot"))); }
#line 9853 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 853:
#line 5830 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("not"))); }
#line 9859 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 854:
#line 5831 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sensitive"))); }
#line 9865 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 855:
#line 5832 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("insensitive"))); }
#line 9871 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 856:
#line 5833 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("diacritics"))); }
#line 9877 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 857:
#line 5834 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("without"))); }
#line 9883 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 858:
#line 5835 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("stemming"))); }
#line 9889 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 859:
#line 5836 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("thesaurus"))); }
#line 9895 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 860:
#line 5837 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("stop"))); }
#line 9901 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 861:
#line 5838 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("wildcards"))); }
#line 9907 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 862:
#line 5839 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("entire"))); }
#line 9913 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 863:
#line 5840 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("content"))); }
#line 9919 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 864:
#line 5841 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("word"))); }
#line 9925 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 865:
#line 5842 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("start"))); }
#line 9931 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 866:
#line 5843 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("end"))); }
#line 9937 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 867:
#line 5844 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("most"))); }
#line 9943 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 868:
#line 5845 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("skip"))); }
#line 9949 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 869:
#line 5846 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("copy"))); }
#line 9955 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 870:
#line 5847 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("general"))); }
#line 9961 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 871:
#line 5848 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("value"))); }
#line 9967 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 872:
#line 5849 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("eq"))); }
#line 9973 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 873:
#line 5850 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ne"))); }
#line 9979 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 874:
#line 5851 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("lt"))); }
#line 9985 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 875:
#line 5852 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("le"))); }
#line 9991 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 876:
#line 5853 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("gt"))); }
#line 9997 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 877:
#line 5854 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ge"))); }
#line 10003 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 878:
#line 5855 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("at"))); }
#line 10009 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 879:
#line 5856 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("context"))); }
#line 10015 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 880:
#line 5857 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("variable"))); }
#line 10021 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 881:
#line 5858 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("return"))); }
#line 10027 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 882:
#line 5859 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("for"))); }
#line 10033 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 883:
#line 5860 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("from"))); }
#line 10039 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 884:
#line 5861 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("allowing"))); }
#line 10045 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 885:
#line 5862 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sliding"))); }
#line 10051 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 886:
#line 5863 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("tumbling"))); }
#line 10057 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 887:
#line 5864 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("previous"))); }
#line 10063 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 888:
#line 5865 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("next"))); }
#line 10069 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 889:
#line 5866 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("only"))); }
#line 10075 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 890:
#line 5867 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("when"))); }
#line 10081 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 891:
#line 5868 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("count"))); }
#line 10087 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 892:
#line 5869 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("in"))); }
#line 10093 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 893:
#line 5870 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("let"))); }
#line 10099 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 894:
#line 5871 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("where"))); }
#line 10105 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 895:
#line 5872 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("by"))); }
#line 10111 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 896:
#line 5873 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("group"))); }
#line 10117 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 897:
#line 5874 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("order"))); }
#line 10123 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 898:
#line 5875 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("stable"))); }
#line 10129 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 899:
#line 5876 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ascending"))); }
#line 10135 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 900:
#line 5877 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("descending"))); }
#line 10141 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 901:
#line 5878 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("greatest"))); }
#line 10147 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 902:
#line 5879 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("least"))); }
#line 10153 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 903:
#line 5880 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("collation"))); }
#line 10159 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 904:
#line 5881 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("some"))); }
#line 10165 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 905:
#line 5882 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("every"))); }
#line 10171 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 906:
#line 5883 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("satisfies"))); }
#line 10177 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 907:
#line 5884 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("case"))); }
#line 10183 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 908:
#line 5885 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("as"))); }
#line 10189 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 909:
#line 5886 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("then"))); }
#line 10195 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 910:
#line 5887 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("else"))); }
#line 10201 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 911:
#line 5888 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("or"))); }
#line 10207 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 912:
#line 5889 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("and"))); }
#line 10213 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 913:
#line 5890 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("instance"))); }
#line 10219 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 914:
#line 5891 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("of"))); }
#line 10225 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 915:
#line 5892 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("castable"))); }
#line 10231 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 916:
#line 5893 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("to"))); }
#line 10237 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 917:
#line 5894 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("div"))); }
#line 10243 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 918:
#line 5895 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("mod"))); }
#line 10249 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 919:
#line 5896 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("union"))); }
#line 10255 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 920:
#line 5897 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("intersect"))); }
#line 10261 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 921:
#line 5898 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("except"))); }
#line 10267 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 922:
#line 5899 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("validate"))); }
#line 10273 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 923:
#line 5900 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("type"))); }
#line 10279 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 924:
#line 5901 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("cast"))); }
#line 10285 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 925:
#line 5902 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("treat"))); }
#line 10291 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 926:
#line 5903 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("is"))); }
#line 10297 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 927:
#line 5904 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("preserve"))); }
#line 10303 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 928:
#line 5905 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("strip"))); }
#line 10309 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 929:
#line 5906 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("namespace"))); }
#line 10315 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 930:
#line 5907 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("external"))); }
#line 10321 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 931:
#line 5908 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("encoding"))); }
#line 10327 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 932:
#line 5909 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("no-preserve"))); }
#line 10333 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 933:
#line 5910 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("inherit"))); }
#line 10339 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 934:
#line 5911 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("no-inherit"))); }
#line 10345 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 935:
#line 5912 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("declare"))); }
#line 10351 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 936:
#line 5913 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("construction"))); }
#line 10357 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 937:
#line 5914 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ordering"))); }
#line 10363 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 938:
#line 5915 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("default"))); }
#line 10369 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 939:
#line 5916 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
#line 10375 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 940:
#line 5917 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("option"))); }
#line 10381 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 941:
#line 5918 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("version"))); }
#line 10387 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 942:
#line 5919 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("import"))); }
#line 10393 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 943:
#line 5920 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("schema"))); }
#line 10399 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 944:
#line 5921 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("module"))); }
#line 10405 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 945:
#line 5922 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("function"))); }
#line 10411 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 946:
#line 5923 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("score"))); }
#line 10417 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 947:
#line 5924 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("contains"))); }
#line 10423 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 948:
#line 5925 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("weight"))); }
#line 10429 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 949:
#line 5926 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("window"))); }
#line 10435 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 950:
#line 5927 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("distance"))); }
#line 10441 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 951:
#line 5928 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("occurs"))); }
#line 10447 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 952:
#line 5929 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("times"))); }
#line 10453 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 953:
#line 5930 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("same"))); }
#line 10459 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 954:
#line 5931 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("different"))); }
#line 10465 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 955:
#line 5932 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("lowercase"))); }
#line 10471 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 956:
#line 5933 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("uppercase"))); }
#line 10477 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 957:
#line 5934 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("relationship"))); }
#line 10483 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 958:
#line 5935 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("levels"))); }
#line 10489 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 959:
#line 5936 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("language"))); }
#line 10495 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 960:
#line 5937 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("any"))); }
#line 10501 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 961:
#line 5938 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("all"))); }
#line 10507 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 962:
#line 5939 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("exactly"))); }
#line 10513 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 963:
#line 5940 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("words"))); }
#line 10519 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 964:
#line 5941 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sentences"))); }
#line 10525 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 965:
#line 5942 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sentence"))); }
#line 10531 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 966:
#line 5943 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("phrase"))); }
#line 10537 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 967:
#line 5944 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("paragraph"))); }
#line 10543 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 968:
#line 5945 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("paragraphs"))); }
#line 10549 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 969:
#line 5946 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("modify"))); }
#line 10555 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 970:
#line 5947 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("first"))); }
#line 10561 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 971:
#line 5948 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("append"))); }
#line 10567 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 972:
#line 5949 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("insert"))); }
#line 10573 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 973:
#line 5950 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("replace"))); }
#line 10579 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 974:
#line 5951 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("rename"))); }
#line 10585 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 975:
#line 5952 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("delete"))); }
#line 10591 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 976:
#line 5953 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("before"))); }
#line 10597 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 977:
#line 5954 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("after"))); }
#line 10603 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 978:
#line 5955 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("revalidation"))); }
#line 10609 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 979:
#line 5956 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("with"))); }
#line 10615 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 980:
#line 5957 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("nodes"))); }
#line 10621 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 981:
#line 5958 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("last"))); }
#line 10627 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 982:
#line 5959 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("into"))); }
#line 10633 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 983:
#line 5960 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("simple"))); }
#line 10639 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 984:
#line 5961 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sequential"))); }
#line 10645 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 985:
#line 5962 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("updating"))); }
#line 10651 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 986:
#line 5963 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ordered"))); }
#line 10657 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 987:
#line 5964 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("unordered"))); }
#line 10663 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 988:
#line 5965 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("returning"))); }
#line 10669 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 989:
#line 5966 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("exit"))); }
#line 10675 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 990:
#line 5967 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("loop"))); }
#line 10681 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 991:
#line 5968 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("break"))); }
#line 10687 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 992:
#line 5969 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("continue"))); }
#line 10693 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 993:
#line 5970 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("try"))); }
#line 10699 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 994:
#line 5971 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("catch"))); }
#line 10705 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 995:
#line 5972 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("using"))); }
#line 10711 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 996:
#line 5973 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("set"))); }
#line 10717 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 997:
#line 5974 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("index"))); }
#line 10723 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 998:
#line 5975 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("unique"))); }
#line 10729 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 999:
#line 5976 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("non"))); }
#line 10735 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1000:
#line 5977 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("on"))); }
#line 10741 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1001:
#line 5978 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("range"))); }
#line 10747 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1002:
#line 5979 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("equality"))); }
#line 10753 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1003:
#line 5980 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("manually"))); }
#line 10759 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1004:
#line 5981 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("automatically"))); }
#line 10765 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1005:
#line 5982 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("maintained"))); }
#line 10771 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1006:
#line 5983 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("decimal-format"))); }
#line 10777 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1007:
#line 5984 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
#line 10783 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1008:
#line 5985 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
#line 10789 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1009:
#line 5986 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("infinity"))); }
#line 10795 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1010:
#line 5987 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("minus-sign"))); }
#line 10801 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1011:
#line 5988 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("NaN"))); }
#line 10807 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1012:
#line 5989 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("percent"))); }
#line 10813 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1013:
#line 5990 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("per-mille"))); }
#line 10819 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1014:
#line 5991 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("zero-digit"))); }
#line 10825 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1015:
#line 5992 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("digit"))); }
#line 10831 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1016:
#line 5993 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
#line 10837 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1017:
#line 5994 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("collection"))); }
#line 10843 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1018:
#line 5995 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("const"))); }
#line 10849 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1019:
#line 5996 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("append-only"))); }
#line 10855 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1020:
#line 5997 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("queue"))); }
#line 10861 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1021:
#line 5998 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("mutable"))); }
#line 10867 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1022:
#line 5999 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("read-only"))); }
#line 10873 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1023:
#line 6000 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("integrity"))); }
#line 10879 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1024:
#line 6001 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("constraint"))); }
#line 10885 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1025:
#line 6002 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("check"))); }
#line 10891 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1026:
#line 6003 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("key"))); }
#line 10897 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1027:
#line 6004 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("foreach"))); }
#line 10903 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1028:
#line 6005 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("foreign"))); }
#line 10909 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1029:
#line 6006 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("keys"))); }
#line 10915 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1030:
#line 6007 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ancestor"))); }
#line 10921 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1031:
#line 6008 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("child"))); }
#line 10927 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1032:
#line 6009 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("descendant"))); }
#line 10933 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1033:
#line 6010 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("parent"))); }
#line 10939 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1034:
#line 6011 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("preceding"))); }
#line 10945 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1035:
#line 6012 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("self"))); }
#line 10951 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1036:
#line 6013 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("following"))); }
#line 10957 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1037:
#line 6014 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
#line 10963 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1038:
#line 6015 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
#line 10969 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1039:
#line 6016 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("following-sibling"))); }
#line 10975 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1040:
#line 6017 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
#line 10981 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1041:
#line 6018 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("position"))); }
#line 10987 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1042:
#line 6019 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("null"))); }
#line 10993 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1043:
#line 6020 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("true"))); }
#line 10999 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1044:
#line 6021 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("false"))); }
#line 11005 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1045:
#line 6022 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("select"))); }
#line 11011 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1046:
#line 6023 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("jsoniq"))); }
#line 11017 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;

  case 1047:
#line 6026 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), true); }
#line 11023 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
    break;


#line 11027 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
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
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
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

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
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
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  jsoniq_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  jsoniq_parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
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
         yyla.  (However, yyla is currently not documented for users.)
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
            // Stay within bounds of both yycheck and yytname.
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

    char const* yyformat = YY_NULLPTR;
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


  const short int jsoniq_parser::yypact_ninf_ = -1544;

  const short int jsoniq_parser::yytable_ninf_ = -884;

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



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
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
  "JSONTest", "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
       0,   935,   935,   936,   940,   944,   950,   954,   958,   964,
     970,   978,   984,   993,   998,  1004,  1010,  1016,  1024,  1029,
    1037,  1045,  1053,  1062,  1067,  1073,  1079,  1088,  1096,  1103,
    1109,  1118,  1119,  1120,  1121,  1122,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1135,  1140,  1146,  1152,  1158,  1163,
    1169,  1174,  1180,  1185,  1191,  1196,  1201,  1206,  1212,  1214,
    1216,  1224,  1229,  1237,  1245,  1254,  1261,  1269,  1275,  1281,
    1287,  1294,  1302,  1313,  1320,  1327,  1335,  1342,  1348,  1357,
    1358,  1359,  1360,  1361,  1362,  1363,  1364,  1367,  1373,  1380,
    1387,  1395,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,
    1411,  1412,  1415,  1429,  1435,  1441,  1448,  1454,  1461,  1466,
    1472,  1478,  1490,  1502,  1515,  1520,  1528,  1536,  1545,  1550,
    1557,  1562,  1569,  1574,  1582,  1587,  1594,  1600,  1609,  1610,
    1613,  1627,  1640,  1655,  1668,  1673,  1678,  1683,  1689,  1696,
    1704,  1709,  1717,  1725,  1733,  1741,  1751,  1755,  1761,  1765,
    1772,  1781,  1792,  1798,  1805,  1810,  1817,  1824,  1833,  1843,
    1853,  1863,  1878,  1894,  1898,  1903,  1908,  1912,  1917,  1922,
    1927,  1935,  1942,  1949,  1962,  1963,  1964,  1965,  1966,  1967,
    1968,  1969,  1970,  1971,  1972,  1973,  1974,  1977,  1983,  2009,
    2015,  2021,  2028,  2035,  2044,  2053,  2062,  2071,  2082,  2088,
    2094,  2100,  2112,  2117,  2123,  2135,  2148,  2168,  2174,  2181,
    2190,  2197,  2203,  2208,  2220,  2232,  2233,  2234,  2235,  2236,
    2237,  2240,  2241,  2242,  2243,  2244,  2245,  2246,  2247,  2248,
    2249,  2250,  2251,  2254,  2266,  2272,  2273,  2278,  2283,  2289,
    2294,  2299,  2305,  2314,  2324,  2334,  2345,  2351,  2352,  2353,
    2356,  2357,  2358,  2359,  2360,  2363,  2370,  2378,  2382,  2390,
    2398,  2406,  2407,  2412,  2419,  2426,  2436,  2446,  2456,  2466,
    2476,  2486,  2496,  2506,  2516,  2525,  2535,  2545,  2557,  2563,
    2569,  2575,  2581,  2589,  2597,  2605,  2613,  2623,  2629,  2638,
    2639,  2643,  2650,  2654,  2659,  2662,  2666,  2670,  2676,  2682,
    2688,  2694,  2702,  2706,  2714,  2722,  2730,  2738,  2748,  2754,
    2760,  2768,  2774,  2782,  2786,  2794,  2800,  2806,  2812,  2821,
    2830,  2839,  2850,  2854,  2860,  2866,  2874,  2880,  2889,  2900,
    2906,  2914,  2918,  2927,  2933,  2939,  2947,  2953,  2959,  2967,
    2973,  2979,  2987,  2993,  3000,  3010,  3017,  3027,  3033,  3041,
    3047,  3056,  3062,  3070,  3076,  3085,  3091,  3099,  3105,  3109,
    3115,  3120,  3126,  3130,  3141,  3145,  3154,  3160,  3169,  3179,
    3178,  3191,  3200,  3209,  3220,  3224,  3235,  3239,  3245,  3248,
    3254,  3258,  3264,  3268,  3272,  3278,  3282,  3288,  3294,  3300,
    3308,  3312,  3316,  3322,  3326,  3332,  3340,  3344,  3352,  3356,
    3364,  3368,  3376,  3380,  3388,  3392,  3398,  3402,  3408,  3412,
    3416,  3420,  3428,  3429,  3430,  3433,  3438,  3444,  3448,  3452,
    3456,  3460,  3464,  3470,  3474,  3478,  3484,  3488,  3492,  3496,
    3505,  3513,  3519,  3527,  3531,  3535,  3541,  3545,  3553,  3561,
    3597,  3603,  3613,  3617,  3623,  3624,  3627,  3633,  3641,  3647,
    3657,  3663,  3671,  3675,  3679,  3683,  3687,  3693,  3699,  3705,
    3709,  3715,  3719,  3728,  3732,  3736,  3742,  3746,  3754,  3755,
    3758,  3762,  3768,  3772,  3776,  3780,  3786,  3790,  3794,  3798,
    3802,  3806,  3812,  3818,  3824,  3828,  3832,  3838,  3844,  3852,
    3858,  3859,  3860,  3861,  3862,  3863,  3864,  3865,  3866,  3867,
    3868,  3869,  3870,  3871,  3874,  3878,  3884,  3891,  3898,  3907,
    3913,  3917,  3923,  3930,  3936,  3942,  3946,  3964,  3970,  3976,
    3982,  3990,  3994,  4000,  4006,  4016,  4017,  4020,  4021,  4022,
    4025,  4033,  4049,  4057,  4073,  4091,  4111,  4117,  4126,  4132,
    4141,  4148,  4149,  4151,  4156,  4163,  4166,  4172,  4178,  4184,
    4191,  4200,  4203,  4209,  4215,  4221,  4228,  4237,  4241,  4247,
    4251,  4257,  4261,  4265,  4270,  4277,  4281,  4285,  4289,  4295,
    4300,  4306,  4312,  4319,  4325,  4330,  4335,  4340,  4345,  4350,
    4355,  4358,  4364,  4368,  4374,  4378,  4384,  4390,  4396,  4400,
    4406,  4410,  4416,  4422,  4426,  4430,  4434,  4441,  4447,  4453,
    4461,  4500,  4504,  4508,  4512,  4516,  4520,  4526,  4532,  4540,
    4546,  4552,  4556,  4560,  4564,  4568,  4572,  4576,  4580,  4584,
    4588,  4594,  4600,  4606,  4610,  4614,  4620,  4625,  4631,  4637,
    4641,  4646,  4652,  4656,  4662,  4668,  4672,  4680,  4686,  4690,
    4696,  4705,  4714,  4720,  4726,  4734,  4740,  4746,  4752,  4758,
    4762,  4768,  4774,  4778,  4786,  4792,  4798,  4804,  4812,  4816,
    4822,  4828,  4832,  4838,  4842,  4848,  4854,  4861,  4869,  4874,
    4880,  4886,  4894,  4900,  4907,  4913,  4922,  4928,  4934,  4940,
    4949,  4956,  4962,  4968,  4977,  4984,  4988,  4994,  4999,  5006,
    5010,  5016,  5020,  5026,  5030,  5036,  5040,  5048,  5059,  5062,
    5068,  5071,  5077,  5083,  5091,  5095,  5101,  5104,  5110,  5120,
    5123,  5129,  5139,  5145,  5153,  5156,  5162,  5166,  5170,  5176,
    5179,  5185,  5188,  5194,  5198,  5202,  5206,  5210,  5216,  5222,
    5232,  5242,  5246,  5250,  5256,  5262,  5270,  5274,  5278,  5282,
    5286,  5290,  5294,  5298,  5304,  5308,  5312,  5316,  5322,  5328,
    5336,  5344,  5348,  5354,  5364,  5375,  5381,  5385,  5391,  5394,
    5400,  5405,  5412,  5420,  5423,  5429,  5433,  5439,  5448,  5455,
    5463,  5467,  5473,  5479,  5487,  5490,  5496,  5501,  5511,  5519,
    5529,  5535,  5539,  5545,  5549,  5553,  5559,  5565,  5569,  5573,
    5577,  5583,  5591,  5601,  5605,  5611,  5617,  5621,  5627,  5631,
    5637,  5641,  5647,  5654,  5664,  5670,  5677,  5688,  5694,  5704,
    5710,  5716,  5733,  5757,  5776,  5780,  5784,  5790,  5793,  5794,
    5795,  5796,  5797,  5798,  5799,  5800,  5801,  5802,  5803,  5804,
    5805,  5806,  5807,  5808,  5809,  5810,  5811,  5812,  5813,  5814,
    5815,  5818,  5819,  5820,  5821,  5822,  5823,  5824,  5825,  5826,
    5827,  5828,  5829,  5830,  5831,  5832,  5833,  5834,  5835,  5836,
    5837,  5838,  5839,  5840,  5841,  5842,  5843,  5844,  5845,  5846,
    5847,  5848,  5849,  5850,  5851,  5852,  5853,  5854,  5855,  5856,
    5857,  5858,  5859,  5860,  5861,  5862,  5863,  5864,  5865,  5866,
    5867,  5868,  5869,  5870,  5871,  5872,  5873,  5874,  5875,  5876,
    5877,  5878,  5879,  5880,  5881,  5882,  5883,  5884,  5885,  5886,
    5887,  5888,  5889,  5890,  5891,  5892,  5893,  5894,  5895,  5896,
    5897,  5898,  5899,  5900,  5901,  5902,  5903,  5904,  5905,  5906,
    5907,  5908,  5909,  5910,  5911,  5912,  5913,  5914,  5915,  5916,
    5917,  5918,  5919,  5920,  5921,  5922,  5923,  5924,  5925,  5926,
    5927,  5928,  5929,  5930,  5931,  5932,  5933,  5934,  5935,  5936,
    5937,  5938,  5939,  5940,  5941,  5942,  5943,  5944,  5945,  5946,
    5947,  5948,  5949,  5950,  5951,  5952,  5953,  5954,  5955,  5956,
    5957,  5958,  5959,  5960,  5961,  5962,  5963,  5964,  5965,  5966,
    5967,  5968,  5969,  5970,  5971,  5972,  5973,  5974,  5975,  5976,
    5977,  5978,  5979,  5980,  5981,  5982,  5983,  5984,  5985,  5986,
    5987,  5988,  5989,  5990,  5991,  5992,  5993,  5994,  5995,  5996,
    5997,  5998,  5999,  6000,  6001,  6002,  6003,  6004,  6005,  6006,
    6007,  6008,  6009,  6010,  6011,  6012,  6013,  6014,  6015,  6016,
    6017,  6018,  6019,  6020,  6021,  6022,  6023,  6026
  };

  // Print the state stack on the debug stream.
  void
  jsoniq_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  jsoniq_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
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
    const unsigned int user_token_number_max_ = 594;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // zorba
#line 16485 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.cpp" // lalr1.cc:1155
#line 6028 "/home/vagrant/zorba/build/src/compiler/parser/jsoniq_parser.y" // lalr1.cc:1156

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
