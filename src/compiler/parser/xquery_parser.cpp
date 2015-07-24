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
#line 1 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:399

#define XQUERY_PARSER
#line 59 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:399


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

#line 102 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:399


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


#line 94 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "xquery_parser.hpp"

// User implementation prologue.
#line 784 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:407

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}
#line 838 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:407

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

#line 147 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:407


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
#line 233 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:474

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
  xquery_parser::xquery_parser (xquery_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  xquery_parser::~xquery_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  xquery_parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  xquery_parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  xquery_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  xquery_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  xquery_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  xquery_parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  xquery_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  xquery_parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  xquery_parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  xquery_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  xquery_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  xquery_parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  xquery_parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  xquery_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  xquery_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  xquery_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  xquery_parser::symbol_number_type
  xquery_parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  xquery_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  xquery_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  xquery_parser::stack_symbol_type&
  xquery_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  xquery_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 111: // "'DECIMAL'"

#line 783 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { delete (yysym.value.decval); }
#line 452 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 125: // "'DOUBLE'"

#line 782 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { delete (yysym.value.dval); }
#line 459 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 150: // "'INTEGER'"

#line 781 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { delete (yysym.value.ival); }
#line 466 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 338: // VersionDecl

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 473 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 339: // MainModule

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 480 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 340: // LibraryModule

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 487 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 341: // ModuleDecl

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 494 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 342: // SIND_DeclList

#line 800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 501 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 343: // SIND_Decl

#line 800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 508 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 344: // Setter

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 515 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 345: // BoundarySpaceDecl

#line 794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 522 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 346: // DefaultCollationDecl

#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 529 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 347: // BaseURIDecl

#line 794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 536 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 348: // ConstructionDecl

#line 794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 543 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 349: // OrderingModeDecl

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 550 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 350: // EmptyOrderDecl

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 557 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 351: // CopyNamespacesDecl

#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 564 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 352: // Import

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 571 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 353: // SchemaImport

#line 800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 578 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 354: // URILiteralList

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 585 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 355: // SchemaPrefix

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 592 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 356: // ModuleImport

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 599 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 357: // NamespaceDecl

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 606 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 358: // DefaultNamespaceDecl

#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 613 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 359: // VFO_DeclList

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 620 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 360: // VFO_Decl

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 627 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 361: // DecimalFormatDecl

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 634 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 362: // DecimalFormatParamList

#line 810 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { delete (yysym.value.vstrpair); }
#line 641 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 363: // DecimalFormatParam

#line 810 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { delete (yysym.value.strpair); }
#line 648 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 365: // OptionDecl

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 655 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 366: // FTOptionDecl

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 662 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 367: // CtxItemDecl

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 669 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 368: // CtxItemDecl2

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 676 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 369: // CtxItemDecl3

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 683 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 370: // CtxItemDecl4

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 690 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 371: // VarDecl

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 697 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 372: // VarNameAndType

#line 810 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { delete (yysym.value.varnametype); }
#line 704 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 373: // AnnotationList

#line 793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 711 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 374: // Annotation

#line 793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 718 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 375: // AnnotationLiteralList

#line 793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 725 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 376: // FunctionDecl

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 732 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 377: // FunctionDecl2

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 739 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 378: // FunctionDeclSimple

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 746 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 379: // FunctionDeclUpdating

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 753 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 380: // FunctionSig

#line 810 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { delete (yysym.value.fnsig); }
#line 760 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 381: // ParamList

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 767 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 382: // Param

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 774 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 383: // CollectionDecl

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 781 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 385: // IndexDecl

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 788 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 386: // IndexKeyList

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 387: // IndexKeySpec

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 388: // IntegrityConstraintDecl

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 389: // QueryBody

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 816 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 390: // StatementsAndOptionalExprTop

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 823 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 391: // StatementsAndOptionalExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 830 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 392: // StatementsAndExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 837 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 393: // Statements

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 844 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 394: // Statement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 851 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 395: // BlockStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 858 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 396: // BlockExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 865 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 397: // EnclosedStatementsAndOptionalExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 872 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 398: // VarDeclStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 879 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 401: // AssignStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 886 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 402: // ApplyStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 893 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 403: // ExitStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 900 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 404: // WhileStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 907 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 405: // FlowCtlStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 914 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 406: // FLWORStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 921 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 407: // ReturnStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 928 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 408: // IfStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 935 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 409: // TryStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 942 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 410: // CatchListStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 949 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 411: // CatchStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 956 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 412: // VoidStatement

#line 805 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 963 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 413: // Expr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 970 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 414: // ExprSingle

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 977 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 415: // ExprSimple

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 984 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 416: // FLWORExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 991 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 417: // ReturnExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 998 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 421: // FLWORWinCond

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1005 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 422: // WindowClause

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1012 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 423: // CountClause

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1019 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 424: // ForLetWinClause

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1026 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 426: // FLWORClauseList

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1033 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 427: // ForClause

#line 796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1040 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 429: // VarInDeclList

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1047 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 430: // VarInDecl

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1054 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 431: // PositionalVar

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1061 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 432: // FTScoreVar

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1068 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 433: // LetClause

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1075 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 434: // VarGetsDeclList

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1082 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 435: // VarGetsDecl

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1089 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 436: // WindowVarDecl

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1096 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 437: // WindowVars

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1103 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 438: // WindowVars3

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1110 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 439: // WindowVars2

#line 803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1117 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 440: // WhereClause

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1124 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 441: // GroupByClause

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1131 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 442: // GroupSpecList

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1138 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 443: // GroupSpec

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1145 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 444: // GroupCollationSpec

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1152 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 445: // OrderByClause

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1159 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 446: // OrderSpecList

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1166 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 447: // OrderSpec

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1173 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 448: // OrderModifier

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1180 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 449: // OrderDirSpec

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1187 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 450: // OrderEmptySpec

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1194 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 451: // OrderCollationSpec

#line 798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1201 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 452: // QuantifiedExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1208 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 453: // QVarInDeclList

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1215 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 454: // QVarInDecl

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1222 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 455: // SwitchExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1229 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 456: // SwitchCaseClauseList

#line 805 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1236 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 457: // SwitchCaseClause

#line 805 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1243 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 458: // SwitchCaseOperandList

#line 805 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1250 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 459: // SwitchStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1257 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 462: // TypeswitchExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1264 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 463: // TypeswitchStatement

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1271 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 464: // CaseClauseList

#line 794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1278 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 465: // CaseClause

#line 794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1285 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 468: // SequenceTypeList

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1292 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 469: // IfExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1299 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 470: // OrExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1306 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 471: // AndExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1313 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 472: // ComparisonExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1320 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 474: // FTContainsExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1327 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 475: // StringConcatExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1334 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 476: // opt_FTIgnoreOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1341 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 477: // RangeExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1348 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 478: // AdditiveExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1355 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 479: // MultiplicativeExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1362 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 480: // UnionExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1369 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 481: // IntersectExceptExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1376 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 482: // InstanceofExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1383 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 483: // TreatExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1390 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 484: // CastableExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1397 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 485: // CastExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1404 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 486: // SingleType

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1411 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 487: // UnaryExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1418 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 488: // SignList

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1425 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 489: // ValueExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1432 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 490: // SimpleMapExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1439 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 491: // ValueComp

#line 802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1446 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 492: // NodeComp

#line 805 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1453 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 493: // ValidateExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1460 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 494: // ExtensionExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1467 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 495: // Pragma_list

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1474 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 496: // Pragma

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1481 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 497: // PathExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1488 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 499: // RelativePathExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1495 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 500: // StepExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1502 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 501: // AxisStep

#line 808 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1509 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 502: // ForwardStep

#line 792 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1516 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 503: // ForwardAxis

#line 792 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1523 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 504: // AbbrevForwardStep

#line 792 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1530 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 505: // ReverseStep

#line 792 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1537 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 506: // ReverseAxis

#line 792 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1544 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 507: // NodeTest

#line 792 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1551 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 508: // NameTest

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1558 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 509: // Wildcard

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1565 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 510: // PostfixExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1572 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 511: // PredicateList

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1579 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 512: // Predicate

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1586 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 513: // PrimaryExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1593 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 514: // Literal

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1600 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 515: // NumericLiteral

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1607 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 516: // VarRef

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1614 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 517: // ParenthesizedExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1621 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 518: // ContextItemExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1628 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 519: // OrderedExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1635 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 520: // UnorderedExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1642 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 521: // FunctionCall

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1649 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 522: // ArgList

#line 793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1656 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 526: // Constructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1663 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 527: // DirectConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1670 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 528: // DirElemConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1677 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 529: // DirElemContentList

#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1684 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 530: // DirAttributeList

#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1691 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 531: // DirAttr

#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1698 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 533: // DirAttributeValue

#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1705 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 534: // opt_QuoteAttrContentList

#line 800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1712 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 535: // QuoteAttrContentList

#line 800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1719 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 536: // opt_AposAttrContentList

#line 793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1726 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 537: // AposAttrContentList

#line 793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1733 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 538: // QuoteAttrValueContent

#line 800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1740 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 539: // AposAttrValueContent

#line 793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1747 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 540: // DirElemContent

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1754 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 541: // CommonContent

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1761 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 542: // DirCommentConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1768 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 543: // DirPIConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1775 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 544: // CDataSection

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1782 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 545: // ComputedConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1789 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 546: // CompDocConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 547: // CompElemConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 548: // CompAttrConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1810 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 549: // CompTextConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1817 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 550: // CompCommentConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1824 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 551: // CompPIConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1831 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 552: // CompNamespaceConstructor

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1838 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 553: // TypeDeclaration

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1845 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 554: // SequenceType

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1852 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 555: // OccurrenceIndicator

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1859 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 556: // ItemType

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1866 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 557: // TypeList

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1873 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 558: // GeneralizedAtomicType

#line 794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1880 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 559: // SimpleType

#line 794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1887 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 560: // KindTest

#line 797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1894 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 561: // AnyKindTest

#line 793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1901 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 563: // DocumentTest

#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1908 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 564: // NamespaceTest

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1915 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 565: // TextTest

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1922 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 566: // CommentTest

#line 794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1929 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 567: // PITest

#line 799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1936 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 568: // AttributeTest

#line 794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1943 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 569: // SchemaAttributeTest

#line 800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1950 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 570: // ElementTest

#line 795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1957 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 571: // SchemaElementTest

#line 800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1964 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 572: // TypeName

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1971 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 573: // TypeName_WITH_HOOK

#line 801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1978 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 574: // StringLiteral

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 1985 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 576: // AnyFunctionTest

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1992 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 577: // TypedFunctionTest

#line 804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 1999 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 580: // InsertExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2006 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 581: // DeleteExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2013 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 582: // ReplaceExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2020 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 583: // RenameExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2027 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 584: // TransformExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2034 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 585: // VarNameList

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2041 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 586: // VarNameDecl

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2048 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 587: // TryExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2055 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 588: // CatchListExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2062 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 589: // CatchExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2069 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 590: // BracedExpr

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2076 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 591: // NameTestList

#line 810 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { delete (yysym.value.name_test_list); }
#line 2083 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 592: // FTSelection

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2090 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 595: // FTOr

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2097 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 596: // FTAnd

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2104 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 597: // FTMildNot

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2111 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 598: // FTUnaryNot

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2118 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 599: // FTPrimaryWithOptions

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2125 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 600: // opt_FTMatchOptions

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2132 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 602: // FTWeight

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2139 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 603: // FTPrimary

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2146 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 604: // opt_FTTimes

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2153 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 605: // FTExtensionSelection

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2160 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 607: // FTWords

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2167 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 608: // FTWordsValue

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2174 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 610: // FTAnyallOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2181 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 613: // FTPosFilter

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2188 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 614: // FTOrder

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2195 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 615: // FTWindow

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2202 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 616: // FTDistance

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2209 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 617: // FTUnit

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2216 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 618: // FTMatchOptions

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2223 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 619: // FTMatchOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2230 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 620: // FTCaseOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2237 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 621: // FTDiacriticsOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2244 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 622: // FTExtensionOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2251 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 623: // FTStemOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2258 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 624: // FTThesaurusOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2265 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 628: // FTThesaurusID

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2272 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 631: // FTStopWordOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2279 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 632: // FTStopWords

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2286 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 636: // FTStopWordsInclExcl

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2293 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 637: // FTLanguageOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2300 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 638: // FTWildCardOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2307 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 639: // FTContent

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2314 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 640: // FTTimes

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2321 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 641: // FTRange

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2328 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 642: // FTScope

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2335 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 643: // FTBigUnit

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2342 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 644: // FTIgnoreOption

#line 806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2349 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 645: // JSONArrayConstructor

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2356 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 646: // JSONSimpleObjectUnion

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2363 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 647: // JSONAccumulatorObjectUnion

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2370 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 648: // JSONObjectConstructor

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2377 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 649: // JSONPairList

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.node) ); }
#line 2384 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 650: // JSONInsertExpr

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2391 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 651: // JSONAppendExpr

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2398 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 652: // JSONDeleteExpr

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2405 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 653: // JSONRenameExpr

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2412 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 654: // JSONReplaceExpr

#line 807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2419 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 657: // QNAME

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2426 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 658: // FUNCTION_NAME

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2433 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;

      case 659: // EQNAME

#line 809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:599
        { release_hack( (yysym.value.expr) ); }
#line 2440 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:599
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  xquery_parser::yy_print_ (std::ostream& yyo,
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
  xquery_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  xquery_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  xquery_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
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
#endif // YYDEBUG

  inline xquery_parser::state_type
  xquery_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

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
    #line 128 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:725
{
    yyla.location.begin.filename = yyla.location.end.filename = &(driver.theFilename2);
}

#line 2576 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:725

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
#line 874 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = (yystack_[0].value.node);
      }
#line 2692 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 4:
#line 878 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = (yystack_[0].value.node);
      }
#line 2700 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 882 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = (yystack_[0].value.node);
      }
#line 2708 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 6:
#line 888 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = NULL;
      }
#line 2716 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 7:
#line 892 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = NULL; YYABORT;
      }
#line 2724 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 8:
#line 896 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
        (yylhs.value.node) = NULL; YYABORT;
      }
#line 2732 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 9:
#line 902 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      driver.set_expr( (yylhs.value.node) );
    }
#line 2741 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 908 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      MainModule* mm = dynamic_cast<MainModule*>((yystack_[0].value.node));
      mm->set_version_decl( static_cast<VersionDecl*>((yystack_[1].value.node)) );
      (yylhs.value.node) = (yystack_[0].value.node);
      driver.set_expr( (yylhs.value.node) );
    }
#line 2752 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 916 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      driver.set_expr( (yylhs.value.node) );
    }
#line 2761 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 922 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yystack_[0].value.node));
      lm->set_version_decl( static_cast<VersionDecl*>((yystack_[1].value.node)) );
      (yylhs.value.node) = (yystack_[0].value.node);
      driver.set_expr( (yylhs.value.node) );
    }
#line 2772 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 931 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VersionDecl( LOC(yylhs.location), SYMTAB((yystack_[1].value.sval)), "utf-8" );
    }
#line 2780 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 936 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VersionDecl( LOC(yylhs.location), SYMTAB((yystack_[3].value.sval)), SYMTAB((yystack_[1].value.sval)) );
    }
#line 2788 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 942 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location), static_cast<SIND_DeclList*>((yystack_[2].value.node)), NULL);
      (yylhs.value.node) = new MainModule(LOC(yylhs.location), static_cast<QueryBody*>((yystack_[0].value.expr)), prolog);
    }
#line 2797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 948 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location), NULL, static_cast<VFO_DeclList*>((yystack_[2].value.node)));
      (yylhs.value.node) = new MainModule(LOC(yylhs.location), static_cast<QueryBody*>((yystack_[0].value.expr)), prolog);
    }
#line 2806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 954 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location),
                                  static_cast<SIND_DeclList*>((yystack_[4].value.node)),
                                  static_cast<VFO_DeclList*>((yystack_[2].value.node)));
      (yylhs.value.node) = new MainModule(LOC(yylhs.location), static_cast<QueryBody*>((yystack_[0].value.expr)), prolog);
    }
#line 2817 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 962 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new MainModule( LOC(yylhs.location), static_cast<QueryBody*>((yystack_[0].value.expr)), NULL );
    }
#line 2825 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 967 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.expr);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
#line 2836 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 975 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.expr);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
#line 2847 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 983 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[4].value.node); (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.expr);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
#line 2858 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 991 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[4].value.node); (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.expr);
      yystack_[4].location.step();
      error(yystack_[4].location, "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
#line 2869 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 1000 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new LibraryModule(LOC(yylhs.location), static_cast<ModuleDecl*>((yystack_[0].value.node)), NULL);
    }
#line 2877 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 1005 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location), static_cast<SIND_DeclList*>((yystack_[1].value.node)), NULL);
      (yylhs.value.node) = new LibraryModule(LOC(yylhs.location), static_cast<ModuleDecl*>((yystack_[2].value.node)), prolog);
    }
#line 2886 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 1011 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location), NULL, static_cast<VFO_DeclList*>((yystack_[1].value.node)));
      (yylhs.value.node) = new LibraryModule(LOC(yylhs.location), static_cast<ModuleDecl*>((yystack_[2].value.node)), prolog);
    }
#line 2895 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 1017 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      Prolog* prolog = new Prolog(LOC(yylhs.location),
                                  static_cast<SIND_DeclList*>((yystack_[3].value.node)),
                                  static_cast<VFO_DeclList*>((yystack_[1].value.node)));
      (yylhs.value.node) = new LibraryModule(LOC(yylhs.location), static_cast<ModuleDecl*>((yystack_[4].value.node)), prolog);
    }
#line 2906 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 1026 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[3].value.expr), yystack_[3].location);
      (yylhs.value.node) = new ModuleDecl( LOC(yylhs.location), static_cast<QName*>((yystack_[3].value.expr)), SYMTAB((yystack_[1].value.sval)) );
      dynamic_cast<ModuleDecl*>((yylhs.value.node))->setComment( SYMTAB((yystack_[5].value.sval)) );
    }
#line 2916 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 1034 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC(yylhs.location) );
      sdl->push_back( (yystack_[0].value.node) );
      (yylhs.value.node) = sdl;
    }
#line 2926 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 1041 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ((SIND_DeclList*)(yystack_[2].value.node))->push_back( (yystack_[0].value.node) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 2935 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 1047 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.node);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
#line 2946 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 1073 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new BoundarySpaceDecl(LOC(yylhs.location), StaticContextConsts::preserve_space);
    }
#line 2954 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 1078 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new BoundarySpaceDecl(LOC(yylhs.location), StaticContextConsts::strip_space);
    }
#line 2962 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 46:
#line 1084 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DefaultCollationDecl( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 2970 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 47:
#line 1090 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new BaseURIDecl( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 2978 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 1096 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ConstructionDecl(LOC(yylhs.location), StaticContextConsts::cons_preserve);
    }
#line 2986 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 49:
#line 1101 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ConstructionDecl(LOC(yylhs.location), StaticContextConsts::cons_strip);
    }
#line 2994 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 1107 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new OrderingModeDecl(LOC(yylhs.location), StaticContextConsts::ordered);
    }
#line 3002 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 1112 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new OrderingModeDecl(LOC(yylhs.location), StaticContextConsts::unordered);
    }
#line 3010 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 1118 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new EmptyOrderDecl(LOC(yylhs.location), StaticContextConsts::empty_greatest);
    }
#line 3018 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 1123 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new EmptyOrderDecl(LOC(yylhs.location), StaticContextConsts::empty_least);
    }
#line 3026 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 1129 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CopyNamespacesDecl(LOC(yylhs.location), true, true);
    }
#line 3034 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 1134 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CopyNamespacesDecl(LOC(yylhs.location), true, false);
    }
#line 3042 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 1139 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CopyNamespacesDecl(LOC(yylhs.location), false, true);
    }
#line 3050 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 1144 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CopyNamespacesDecl(LOC(yylhs.location), false, false);
    }
#line 3058 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 1154 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yylhs.value.node);
      error(yystack_[1].location, "syntax error, \"import\" should be followed by either \"schema\" or \"module\"");
      YYERROR;
    }
#line 3068 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 1162 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaImport( LOC(yylhs.location), NULL, SYMTAB((yystack_[0].value.sval)), NULL );
    }
#line 3076 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 1167 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaImport(LOC(yylhs.location),
                            dynamic_cast<SchemaPrefix*>((yystack_[1].value.node)),
                            SYMTAB((yystack_[0].value.sval)),
                            NULL);
    }
#line 3087 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 1175 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaImport(LOC(yylhs.location),
                            NULL,
                            SYMTAB((yystack_[2].value.sval)),
                            dynamic_cast<URILiteralList*>((yystack_[0].value.node)));
    }
#line 3098 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 1183 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaImport(LOC(yylhs.location),
                            dynamic_cast<SchemaPrefix*>((yystack_[3].value.node)),
                            SYMTAB((yystack_[2].value.sval)),
                            dynamic_cast<URILiteralList*>((yystack_[0].value.node)));
    }
#line 3109 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 1192 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      URILiteralList *ull = new URILiteralList( LOC(yylhs.location));
      ull->push_back( SYMTAB((yystack_[0].value.sval)) );
      (yylhs.value.node) = ull;
    }
#line 3119 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 1199 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yystack_[2].value.node)) )
        ull->push_back( SYMTAB((yystack_[0].value.sval)) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3129 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 1207 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[1].value.expr), yystack_[1].location);
      (yylhs.value.node) = new SchemaPrefix( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)));
    }
#line 3138 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 1213 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SchemaPrefix( LOC(yylhs.location), true );
    }
#line 3146 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 1219 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ModuleImport(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), NULL);
      dynamic_cast<ModuleImport *>((yylhs.value.node))->setComment(SYMTAB((yystack_[1].value.sval)));
    }
#line 3155 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 1225 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[2].value.expr), yystack_[2].location);
      (yylhs.value.node) = new ModuleImport(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), SYMTAB((yystack_[0].value.sval)), NULL);
      dynamic_cast<ModuleImport *>((yylhs.value.node))->setComment(SYMTAB((yystack_[4].value.sval)));
    }
#line 3165 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 1232 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ModuleImport(LOC(yylhs.location),
                            SYMTAB((yystack_[2].value.sval)),
                            dynamic_cast<URILiteralList*>((yystack_[0].value.node)));
      dynamic_cast<ModuleImport *>((yylhs.value.node))->setComment(SYMTAB((yystack_[3].value.sval)));
    }
#line 3176 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 1240 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[4].value.expr), yystack_[4].location);
      (yylhs.value.node) = new ModuleImport(LOC(yylhs.location),
                            static_cast<QName*>((yystack_[4].value.expr)),
                            SYMTAB((yystack_[2].value.sval)),
                            dynamic_cast<URILiteralList*>((yystack_[0].value.node)));
      dynamic_cast<ModuleImport *>((yylhs.value.node))->setComment(SYMTAB((yystack_[6].value.sval)));
    }
#line 3189 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 1251 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[2].value.expr), yystack_[2].location);
      (yylhs.value.node) = new NamespaceDecl( LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), SYMTAB((yystack_[0].value.sval)) );
    }
#line 3198 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 1258 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DefaultNamespaceDecl(LOC(yylhs.location),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yystack_[0].value.sval)));
    }
#line 3208 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 1265 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DefaultNamespaceDecl(LOC(yylhs.location),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yystack_[0].value.sval)));
    }
#line 3218 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 1273 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC(yylhs.location));
      vdl->push_back( (yystack_[0].value.node) );
      (yylhs.value.node) = vdl;
    }
#line 3228 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 1280 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ((VFO_DeclList*)(yystack_[2].value.node))->push_back( (yystack_[0].value.node) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3237 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 1286 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node); (yylhs.value.node) = (yystack_[0].value.node);
      yystack_[2].location.step();
      error(yystack_[2].location, "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
#line 3248 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 1305 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DecimalFormatNode(LOC(yylhs.location), (yystack_[0].value.vstrpair));
      delete (yystack_[0].value.vstrpair);
    }
#line 3257 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 1311 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DecimalFormatNode(LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), (yystack_[0].value.vstrpair));
      delete (yystack_[0].value.vstrpair);
    }
#line 3266 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 1318 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.vstrpair) = new vector<string_pair_t>();
      (yylhs.value.vstrpair)->push_back( *(yystack_[0].value.strpair) );
      delete (yystack_[0].value.strpair);
    }
#line 3276 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 1325 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yystack_[1].value.vstrpair)->push_back( *(yystack_[0].value.strpair) );
      delete (yystack_[0].value.strpair);
      (yylhs.value.vstrpair) = (yystack_[1].value.vstrpair);
    }
#line 3286 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 1333 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yystack_[0].value.expr));
      (yylhs.value.strpair) = new string_pair_t( (yystack_[2].value.strval), sl->get_strval().str() );
      delete sl;
    }
#line 3296 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 1340 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "decimal-separator"; }
#line 3302 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 1341 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "digit"; }
#line 3308 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 1342 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "grouping-separator"; }
#line 3314 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 1343 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "infinity"; }
#line 3320 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 1344 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "minus-sign"; }
#line 3326 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 1345 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "NaN"; }
#line 3332 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 1346 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "pattern-separator"; }
#line 3338 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 1347 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "percent"; }
#line 3344 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 1348 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "per-mille"; }
#line 3350 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 1349 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.strval) = "zero-digit"; }
#line 3356 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 1353 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3372 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 1367 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FTOptionDecl( LOC(yylhs.location), dynamic_cast<FTMatchOptions*>((yystack_[0].value.node)) );
    }
#line 3380 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 1373 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3388 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 1379 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yystack_[0].value.node));
      d->theType = (yystack_[1].value.node);
      (yylhs.value.node) = d;
    }
#line 3398 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 1386 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3406 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 107:
#line 1392 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yystack_[0].value.node));
      d->theIsExternal = false;
      (yylhs.value.node) = d;
    }
#line 3416 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 108:
#line 1399 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CtxItemDecl(LOC(yylhs.location), NULL);
    }
#line 3424 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 109:
#line 1404 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3432 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 110:
#line 1410 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CtxItemDecl(LOC(yylhs.location), (yystack_[0].value.expr));
    }
#line 3440 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 111:
#line 1416 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3455 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 112:
#line 1428 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3470 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 113:
#line 1440 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3485 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 114:
#line 1453 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.varnametype) = new VarNameAndType(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)), NULL, NULL);
    }
#line 3493 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 115:
#line 1458 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.varnametype) = new VarNameAndType(LOC(yylhs.location),
                              static_cast<QName*>((yystack_[1].value.expr)),
                              dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)),
                              NULL);
    }
#line 3504 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 116:
#line 1466 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.varnametype) = new VarNameAndType(LOC(yylhs.location),
                              static_cast<QName*>((yystack_[0].value.expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yystack_[3].value.node)));
    }
#line 3515 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 117:
#line 1474 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.varnametype) = new VarNameAndType(LOC(yylhs.location),
                              static_cast<QName*>((yystack_[1].value.expr)),
                              dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)),
                              static_cast<AnnotationListParsenode*>((yystack_[4].value.node)));
    }
#line 3526 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 118:
#line 1483 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationListParsenode(LOC(yylhs.location), static_cast<AnnotationParsenode*>((yystack_[0].value.node)));
    }
#line 3534 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 119:
#line 1488 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      static_cast<AnnotationListParsenode*>((yystack_[1].value.node))->push_back(static_cast<AnnotationParsenode*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 3543 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 120:
#line 1495 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationParsenode(LOC(yylhs.location), new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval))), NULL);
    }
#line 3551 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 121:
#line 1500 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationParsenode(LOC(yylhs.location),
                                   new QName(LOC(yylhs.location), SYMTAB((yystack_[3].value.sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yystack_[1].value.node)));
    }
#line 3561 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 122:
#line 1507 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationParsenode(LOC(yylhs.location), new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), true), NULL);
    }
#line 3569 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 123:
#line 1512 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationParsenode(LOC(yylhs.location),
                                   new QName(LOC(yylhs.location), SYMTAB((yystack_[3].value.sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yystack_[1].value.node)));
    }
#line 3579 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 124:
#line 1520 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnnotationLiteralListParsenode(LOC(yylhs.location), (yystack_[0].value.expr));
    }
#line 3587 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 125:
#line 1525 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      static_cast<AnnotationLiteralListParsenode*>((yystack_[2].value.node))->push_back((yystack_[0].value.expr));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3596 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 126:
#line 1532 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      static_cast<FunctionDecl*>((yystack_[0].value.node))->setComment( SYMTAB((yystack_[1].value.sval)) );
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3605 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 127:
#line 1538 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yystack_[0].value.node));
      fdecl->setComment( SYMTAB((yystack_[2].value.sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yystack_[1].value.node)));
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 3616 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 130:
#line 1551 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3634 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 131:
#line 1565 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3649 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 132:
#line 1578 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3667 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 133:
#line 1593 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3682 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 134:
#line 1606 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.fnsig) = new FunctionSig(NULL);
    }
#line 3690 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 135:
#line 1611 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yystack_[1].value.node)));
    }
#line 3698 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 136:
#line 1616 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node)));
    }
#line 3706 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 137:
#line 1621 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yystack_[3].value.node)), dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node)));
    }
#line 3714 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 138:
#line 1627 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ParamList *pl = new ParamList( LOC(yylhs.location) );
      pl->push_back( dynamic_cast<Param*>((yystack_[0].value.node)) );
      (yylhs.value.node) = pl;
    }
#line 3724 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 139:
#line 1634 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yystack_[2].value.node)) )
        pl->push_back( dynamic_cast<Param*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3734 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 140:
#line 1642 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Param(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)), NULL);
    }
#line 3742 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 141:
#line 1647 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Param(LOC(yylhs.location),
                     static_cast<QName*>((yystack_[1].value.expr)),
                     dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
    }
#line 3752 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 142:
#line 1655 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CollectionDecl( LOC(yylhs.location),
                              static_cast<QName*>((yystack_[0].value.expr)),
                              NULL,
                              NULL);
      static_cast<CollectionDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[2].value.sval)));
    }
#line 3764 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 143:
#line 1663 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CollectionDecl( LOC(yylhs.location),
                              static_cast<QName*>((yystack_[2].value.expr)),
                              0,
                              static_cast<SequenceTypeAST*>((yystack_[0].value.node)));
      static_cast<CollectionDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[4].value.sval)));
    }
#line 3776 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 144:
#line 1671 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CollectionDecl( LOC(yylhs.location),
                               static_cast<QName*>((yystack_[0].value.expr)),
                               static_cast<AnnotationListParsenode*>((yystack_[2].value.node)),
                               0);
      static_cast<CollectionDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[3].value.sval)));
    }
#line 3788 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 145:
#line 1679 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CollectionDecl( LOC(yylhs.location),
                               static_cast<QName*>((yystack_[2].value.expr)),
                               static_cast<AnnotationListParsenode*>((yystack_[4].value.node)),
                               static_cast<SequenceTypeAST*>((yystack_[0].value.node)));
      static_cast<CollectionDecl*>((yylhs.value.node))->setComment(SYMTAB((yystack_[5].value.sval)));
    }
#line 3800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 146:
#line 1689 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC(yylhs.location), (yystack_[0].value.node), NULL));
    }
#line 3808 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 147:
#line 1693 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC(yylhs.location),
                                                    (yystack_[1].value.node),
                                                    dynamic_cast<OccurrenceIndicator*>((yystack_[0].value.node))));
    }
#line 3818 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 148:
#line 1699 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC(yylhs.location), (yystack_[0].value.node), NULL));
    }
#line 3826 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 149:
#line 1703 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = static_cast<parsenode*>(new SequenceTypeAST(LOC(yylhs.location),
                                                    (yystack_[1].value.node),
                                                    dynamic_cast<OccurrenceIndicator*>((yystack_[0].value.node))));
    }
#line 3836 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 150:
#line 1710 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AST_IndexDecl(LOC(yylhs.location),
                             static_cast<QName*>((yystack_[5].value.expr)),
                             (yystack_[2].value.expr),
                             dynamic_cast<IndexKeyList*>((yystack_[0].value.node)),
                             NULL);
      static_cast<AST_IndexDecl*>((yylhs.value.node))->setComment( SYMTAB((yystack_[7].value.sval)) );
    }
#line 3849 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 151:
#line 1719 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AST_IndexDecl(LOC(yylhs.location),
                             static_cast<QName*>((yystack_[5].value.expr)),
                             (yystack_[2].value.expr),
                             dynamic_cast<IndexKeyList*>((yystack_[0].value.node)),
                             static_cast<AnnotationListParsenode*>((yystack_[7].value.node)));
      static_cast<AST_IndexDecl*>((yylhs.value.node))->setComment( SYMTAB((yystack_[8].value.sval)) );
    }
#line 3862 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 152:
#line 1730 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      IndexKeyList* keyList = new IndexKeyList(LOC(yylhs.location));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yystack_[0].value.node)));
      (yylhs.value.node) = keyList;
    }
#line 3872 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 153:
#line 1736 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      dynamic_cast<IndexKeyList*>((yystack_[2].value.node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 3881 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 154:
#line 1743 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new IndexKeySpec(LOC(yylhs.location), (yystack_[0].value.expr), NULL, NULL);
    }
#line 3889 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 155:
#line 1748 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new IndexKeySpec(LOC(yylhs.location),
                            (yystack_[1].value.expr),
                            dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node)),
                            NULL);
    }
#line 3900 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 156:
#line 1755 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new IndexKeySpec(LOC(yylhs.location),
                            (yystack_[1].value.expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node)));
    }
#line 3911 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 157:
#line 1762 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new IndexKeySpec(LOC(yylhs.location),
                            (yystack_[2].value.expr),
                            dynamic_cast<SequenceTypeAST*>((yystack_[1].value.node)),
                            dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node)));
    }
#line 3922 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 158:
#line 1772 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ICCollSimpleCheck(LOC(yylhs.location),
                                 static_cast<QName*>((yystack_[7].value.expr)),
                                 static_cast<QName*>((yystack_[4].value.expr)),
                                 static_cast<QName*>((yystack_[2].value.expr)),
                                 (yystack_[0].value.expr));
    }
#line 3934 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 159:
#line 1782 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ICCollUniqueKeyCheck(LOC(yylhs.location),
                                    static_cast<QName*>((yystack_[10].value.expr)),
                                    static_cast<QName*>((yystack_[7].value.expr)),
                                    static_cast<QName*>((yystack_[4].value.expr)),
                                    (yystack_[0].value.expr));
    }
#line 3946 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 160:
#line 1792 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ICCollForeachNode(LOC(yylhs.location),
                                 static_cast<QName*>((yystack_[9].value.expr)),
                                 static_cast<QName*>((yystack_[6].value.expr)),
                                 static_cast<QName*>((yystack_[2].value.expr)),
                                 (yystack_[0].value.expr));
    }
#line 3958 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 161:
#line 1803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3973 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 162:
#line 1816 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 3991 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 163:
#line 1832 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 3999 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 164:
#line 1836 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4007 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 165:
#line 1840 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = NULL;
    }
#line 4015 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 166:
#line 1846 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4023 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 167:
#line 1850 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4031 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 168:
#line 1854 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = NULL;
    }
#line 4039 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 169:
#line 1860 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4047 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 170:
#line 1865 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      BlockBody* blk = static_cast<BlockBody*>((yystack_[1].value.expr));
      blk->add((yystack_[0].value.expr));
      (yylhs.value.expr) = blk;
    }
#line 4057 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 171:
#line 1873 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      BlockBody* blk = new BlockBody(LOC(yylhs.location));
      blk->add((yystack_[0].value.expr));
      (yylhs.value.expr) = blk;
    }
#line 4067 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 172:
#line 1880 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      BlockBody* blk = static_cast<BlockBody*>((yystack_[1].value.expr));
      blk->add((yystack_[0].value.expr));
      (yylhs.value.expr) = blk;
    }
#line 4077 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 173:
#line 1887 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 4092 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 187:
#line 1915 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 4100 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 188:
#line 1920 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      driver.addCommonLanguageWarning(yystack_[1].location, ZED(ZWST0009_EMPTY_BLOCK));
      (yylhs.value.expr) = new BlockBody(LOC(yylhs.location));
    }
#line 4109 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 189:
#line 1927 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yystack_[1].value.expr));
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
#line 4131 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 190:
#line 1947 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 4139 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 191:
#line 1953 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 4147 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 192:
#line 1959 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yystack_[2].value.expr));
      vdecl->add((yystack_[0].value.node));
      (yylhs.value.expr) = vdecl;
    }
#line 4157 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 193:
#line 1966 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC(yylhs.location), NULL);
      vdecl->add((yystack_[0].value.node));
      (yylhs.value.expr) = vdecl;
    }
#line 4167 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 194:
#line 1973 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC(yylhs.location),
                                           static_cast<AnnotationListParsenode*>((yystack_[2].value.node)));
      vdecl->add((yystack_[0].value.node));
      (yylhs.value.expr) = vdecl;
    }
#line 4178 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 195:
#line 1982 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC(yylhs.location),
                                          static_cast<QName*>((yystack_[0].value.expr)),
                                          NULL,
                                          NULL,
                                          NULL);
      (yylhs.value.node) = vd;
    }
#line 4191 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 196:
#line 1991 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC(yylhs.location),
                                          static_cast<QName*>((yystack_[1].value.expr)),
                                          dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node)),
                                          NULL,
                                          NULL);
      (yylhs.value.node) = vd;
    }
#line 4204 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 197:
#line 2000 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC(yylhs.location),
                                          static_cast<QName*>((yystack_[2].value.expr)),
                                          NULL,
                                          (yystack_[0].value.expr),
                                          NULL);
      (yylhs.value.node) = vd;
    }
#line 4217 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 198:
#line 2009 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC(yylhs.location),
                                          static_cast<QName*>((yystack_[3].value.expr)),
                                          dynamic_cast<SequenceTypeAST*>((yystack_[2].value.node)),
                                          (yystack_[0].value.expr),
                                          NULL);
      (yylhs.value.node) = vd;
    }
#line 4230 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 199:
#line 2020 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new AssignExpr(LOC(yylhs.location), static_cast<QName*>((yystack_[3].value.expr)), (yystack_[1].value.expr));
    }
#line 4238 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 200:
#line 2026 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new ApplyExpr(LOC(yylhs.location), (yystack_[1].value.expr));
    }
#line 4246 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 201:
#line 2032 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new ExitExpr(LOC(yylhs.location), (yystack_[1].value.expr));
    }
#line 4254 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 202:
#line 2038 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      BlockBody* bb = dynamic_cast<BlockBody *>((yystack_[0].value.expr));
      if (bb == NULL)
      {
        bb = new BlockBody((yystack_[0].value.expr)->get_location());
        bb->add((yystack_[0].value.expr));
      }
      (yylhs.value.expr) = new WhileExpr(LOC(yylhs.location), (yystack_[2].value.expr), bb);
    }
#line 4268 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 203:
#line 2050 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new FlowCtlStatement(LOC(yylhs.location), FlowCtlStatement::BREAK);
    }
#line 4276 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 204:
#line 2055 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new FlowCtlStatement( LOC(yylhs.location), FlowCtlStatement::CONTINUE );
    }
#line 4284 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 205:
#line 2061 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ReturnExpr* re = dynamic_cast<ReturnExpr*>((yystack_[0].value.expr));
      (yylhs.value.expr) = new FLWORExpr(LOC(yylhs.location),
                         dynamic_cast<FLWORClauseList*>((yystack_[1].value.node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yystack_[0].value.expr);
    }
#line 4298 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 206:
#line 2073 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 4313 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 207:
#line 2086 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 4335 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 208:
#line 2106 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TryExpr(LOC(yylhs.location), (yystack_[1].value.expr), (yystack_[0].value.expr));
    }
#line 4343 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 209:
#line 2112 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CatchListExpr* cle = new CatchListExpr( LOC(yylhs.location) );
      cle->push_back( static_cast<CatchExpr*>((yystack_[0].value.expr)) );
      (yylhs.value.expr) = cle;
    }
#line 4353 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 210:
#line 2119 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yystack_[1].value.expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yystack_[0].value.expr)) );
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 4364 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 211:
#line 2128 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new CatchExpr(LOC(yylhs.location), *(yystack_[1].value.name_test_list), (yystack_[0].value.expr));
       delete (yystack_[1].value.name_test_list);
    }
#line 4373 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 212:
#line 2135 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new BlockBody(LOC(yylhs.location));
    }
#line 4381 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 213:
#line 2141 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 4389 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 214:
#line 2146 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 4404 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 215:
#line 2158 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[2].value.expr);
      (yylhs.value.expr) = (yystack_[0].value.expr);
      if (dynamic_cast<PathExpr*>((yystack_[2].value.expr)) == NULL)
        error(yystack_[1].location, "syntax error, unexpected expression (missing comma \",\" between expressions?)");
      delete (yystack_[2].value.expr);
      delete (yystack_[0].value.expr);
      YYERROR;
    }
#line 4418 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 234:
#line 2192 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ReturnExpr *re = dynamic_cast<ReturnExpr*>((yystack_[0].value.expr));
      (yylhs.value.expr) = new FLWORExpr(LOC(yylhs.location),
                         dynamic_cast<FLWORClauseList*>((yystack_[1].value.node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yystack_[0].value.expr);
    }
#line 4432 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 235:
#line 2204 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new ReturnExpr( LOC(yylhs.location), (yystack_[0].value.expr) );
    }
#line 4440 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 236:
#line 2210 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
    }
#line 4447 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 237:
#line 2215 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.strval) = parser::the_sliding;
    }
#line 4455 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 238:
#line 2220 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.strval) = parser::the_tumbling;
    }
#line 4463 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 239:
#line 2226 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.strval) = parser::the_start;
    }
#line 4471 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 240:
#line 2231 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.strval) = parser::the_end;
    }
#line 4479 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 241:
#line 2236 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
    (yylhs.value.strval) = parser::the_only_end;
  }
#line 4487 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 242:
#line 2242 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FLWORWinCond(LOC(yylhs.location),
                            dynamic_cast<WindowVars*>((yystack_[2].value.node)),
                            (yystack_[0].value.expr),
                            (yystack_[3].value.strval) == parser::the_start,
                            (yystack_[3].value.strval) == parser::the_only_end);
    }
#line 4499 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 243:
#line 2251 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FLWORWinCond(LOC(yylhs.location),
                            NULL,
                            (yystack_[0].value.expr),
                            (yystack_[2].value.strval) == parser::the_start,
                            (yystack_[2].value.strval) == parser::the_only_end);
    }
#line 4511 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 244:
#line 2261 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowClause (LOC (yylhs.location),
                             ((yystack_[3].value.strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yystack_[2].value.node)),
                             dynamic_cast<FLWORWinCond *> ((yystack_[1].value.node)),
                             dynamic_cast<FLWORWinCond *> ((yystack_[0].value.node)));
    }
#line 4525 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 245:
#line 2271 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowClause (LOC (yylhs.location),
                             ((yystack_[2].value.strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yystack_[1].value.node)),
                             dynamic_cast<FLWORWinCond *> ((yystack_[0].value.node)), NULL);
    }
#line 4538 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 246:
#line 2282 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CountClause(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 4546 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 255:
#line 2300 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC(yylhs.location) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yystack_[0].value.node)) );
      (yylhs.value.node) = fcl;
    }
#line 4556 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 256:
#line 2307 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yystack_[1].value.node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yystack_[0].value.node)) );
      (yylhs.value.node) = fcl;
    }
#line 4566 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 257:
#line 2315 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new ForClause(LOC(yylhs.location), dynamic_cast<VarInDeclList*>((yystack_[0].value.node)));
    }
#line 4574 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 258:
#line 2319 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      error(yystack_[1].location, "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yystack_[0].value.node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yystack_[0].value.node);
      YYERROR;
    }
#line 4586 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 259:
#line 2327 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = NULL;
      error(yystack_[0].location, "");
      YYERROR;
    }
#line 4596 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 260:
#line 2335 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
    }
#line 4603 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 261:
#line 2340 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      VarInDeclList* vdl = new VarInDeclList( LOC(yylhs.location) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yystack_[0].value.node)) );
      (yylhs.value.node) = vdl;
    }
#line 4613 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 262:
#line 2347 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yystack_[3].value.node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[3].value.node);
    }
#line 4623 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 263:
#line 2354 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[2].value.node);
      error(yystack_[0].location, "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yystack_[0].value.node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yystack_[2].value.node);
      YYERROR;
    }
#line 4635 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 264:
#line 2364 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[2].value.expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yystack_[0].value.expr),
                         false);
    }
#line 4649 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 265:
#line 2374 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yystack_[0].value.expr),
                         true);
    }
#line 4663 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 266:
#line 2384 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[2].value.node)),
                         NULL,
                         NULL,
                         (yystack_[0].value.expr),
                         false);
    }
#line 4677 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 267:
#line 2394 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[5].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[4].value.node)),
                         NULL,
                         NULL,
                         (yystack_[0].value.expr),
                         true);
    }
#line 4691 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 268:
#line 2404 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yystack_[2].value.node)),
                         NULL,
                         (yystack_[0].value.expr),
                         false);
    }
#line 4705 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 269:
#line 2414 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[5].value.expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yystack_[2].value.node)),
                         NULL,
                         (yystack_[0].value.expr),
                         true);
    }
#line 4719 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 270:
#line 2424 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[3].value.node)),
                         dynamic_cast<PositionalVar*>((yystack_[2].value.node)),
                         NULL,
                         (yystack_[0].value.expr),
                         false);
    }
#line 4733 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 271:
#line 2434 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[6].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[5].value.node)),
                         dynamic_cast<PositionalVar*>((yystack_[2].value.node)),
                         NULL,
                         (yystack_[0].value.expr),
                         true);
    }
#line 4747 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 272:
#line 2444 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         false);
    }
#line 4760 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 273:
#line 2453 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[3].value.node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         false);
    }
#line 4774 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 274:
#line 2463 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC (yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yystack_[3].value.node)),
                         dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         false);
    }
#line 4788 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 275:
#line 2473 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarInDecl(LOC (yylhs.location),
                         static_cast<QName*>((yystack_[5].value.expr)),
                         dynamic_cast<SequenceTypeAST *>((yystack_[4].value.node)),
                         dynamic_cast<PositionalVar*>((yystack_[3].value.node)),
                         dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         false);
    }
#line 4802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 276:
#line 2485 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new PositionalVar(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 4810 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 277:
#line 2491 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new FTScoreVar(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 4818 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 278:
#line 2497 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new LetClause( LOC(yylhs.location), dynamic_cast<VarGetsDeclList*>((yystack_[0].value.node)) );
        }
#line 4826 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 279:
#line 2503 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC(yylhs.location) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yystack_[0].value.node)) );
            (yylhs.value.node) = vgdl;
        }
#line 4836 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 280:
#line 2509 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yystack_[2].value.node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yystack_[0].value.node)) );
            (yylhs.value.node) = (yystack_[2].value.node);
        }
#line 4846 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 281:
#line 2517 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarGetsDecl(LOC (yylhs.location),
                           static_cast<QName*>((yystack_[2].value.expr)),
                           NULL,
                           NULL,
                           (yystack_[0].value.expr));
    }
#line 4858 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 282:
#line 2525 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarGetsDecl(LOC (yylhs.location),
                           static_cast<QName*>((yystack_[3].value.expr)),
                           dynamic_cast<SequenceTypeAST *>((yystack_[2].value.node)),
                           NULL,
                           (yystack_[0].value.expr));
    }
#line 4870 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 283:
#line 2533 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarGetsDecl(LOC (yylhs.location),
                           dynamic_cast<FTScoreVar*>((yystack_[2].value.node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                           (yystack_[0].value.expr));
     }
#line 4882 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 284:
#line 2541 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new VarGetsDecl(LOC (yylhs.location),
                           static_cast<QName*>((yystack_[4].value.expr)),
                           dynamic_cast<SequenceTypeAST *>((yystack_[3].value.node)),
                           dynamic_cast<FTScoreVar*>((yystack_[2].value.node)),
                           (yystack_[0].value.expr));
    }
#line 4894 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 285:
#line 2551 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVarDecl(LOC (yylhs.location),
                             static_cast<QName*>((yystack_[2].value.expr)),
                             NULL, (yystack_[0].value.expr));
    }
#line 4904 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 286:
#line 2557 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVarDecl(LOC (yylhs.location),
                             static_cast<QName*>((yystack_[3].value.expr)),
                             dynamic_cast<SequenceTypeAST *>((yystack_[2].value.node)),
                             (yystack_[0].value.expr));
    }
#line 4915 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 288:
#line 2567 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), NULL, static_cast<QName*>((yystack_[0].value.expr)), NULL, NULL);
    }
#line 4923 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 289:
#line 2571 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      dynamic_cast<WindowVars *>((yylhs.value.node))->set_curr(static_cast<QName*>((yystack_[1].value.expr)));
    }
#line 4932 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 290:
#line 2578 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), dynamic_cast<PositionalVar*>((yystack_[0].value.node)), NULL, NULL, NULL);
    }
#line 4940 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 291:
#line 2582 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
      dynamic_cast<WindowVars *>((yylhs.value.node))->set_posvar(dynamic_cast<PositionalVar*>((yystack_[1].value.node)));
    }
#line 4949 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 293:
#line 2590 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), NULL, NULL, static_cast<QName*>((yystack_[3].value.expr)), static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 4957 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 294:
#line 2594 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), NULL, NULL, NULL, static_cast<QName*>((yystack_[0].value.expr)));
    }
#line 4965 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 295:
#line 2598 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WindowVars(LOC(yylhs.location), NULL, NULL, static_cast<QName*>((yystack_[0].value.expr)), NULL);
    }
#line 4973 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 296:
#line 2604 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new WhereClause(LOC (yylhs.location), (yystack_[0].value.expr));
    }
#line 4981 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 297:
#line 2610 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupByClause(LOC(yylhs.location), dynamic_cast<GroupSpecList*>((yystack_[0].value.node)));
    }
#line 4989 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 298:
#line 2616 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      GroupSpecList* gsl = new GroupSpecList(LOC(yylhs.location));
      gsl->push_back(static_cast<GroupSpec*>((yystack_[0].value.node)));
      (yylhs.value.node) = gsl;
    }
#line 4999 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 299:
#line 2622 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yystack_[2].value.node));
      gsl->push_back(static_cast<GroupSpec*>((yystack_[0].value.node)));
      (yylhs.value.node) = gsl;
    }
#line 5009 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 300:
#line 2630 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), NULL, (yystack_[0].value.expr), NULL);
    }
#line 5017 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 301:
#line 2634 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupSpec(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         static_cast<SequenceTypeAST*>((yystack_[2].value.node)),
                         (yystack_[0].value.expr),
                         NULL);
    }
#line 5029 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 302:
#line 2642 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupSpec(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[4].value.expr)),
                         static_cast<SequenceTypeAST*>((yystack_[3].value.node)),
                         (yystack_[1].value.expr),
                         static_cast<GroupCollationSpec*>((yystack_[0].value.node)));
    }
#line 5041 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 303:
#line 2650 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupSpec(LOC(yylhs.location),
                         static_cast<QName*>((yystack_[3].value.expr)),
                         NULL,
                         (yystack_[1].value.expr),
                         static_cast<GroupCollationSpec*>((yystack_[0].value.node)));
    }
#line 5053 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 304:
#line 2658 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yystack_[0].value.expr));
      if (varRef != NULL)
        (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), varRef, NULL, NULL, NULL);
      else
        (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), NULL, NULL, (yystack_[0].value.expr), NULL);
    }
#line 5065 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 305:
#line 2666 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yystack_[1].value.expr));
      if (varRef != NULL)
        (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yystack_[0].value.node)));
      else
        (yylhs.value.node) = new GroupSpec(LOC(yylhs.location), NULL, NULL, (yystack_[1].value.expr), static_cast<GroupCollationSpec*>((yystack_[0].value.node)));
    }
#line 5077 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 306:
#line 2676 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GroupCollationSpec( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 5085 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 307:
#line 2682 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderByClause(
                LOC(yylhs.location), dynamic_cast<OrderSpecList*>((yystack_[0].value.node))
            );
        }
#line 5095 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 308:
#line 2688 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderByClause(
                LOC(yylhs.location), dynamic_cast<OrderSpecList*>((yystack_[0].value.node)), true
            );
        }
#line 5105 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 309:
#line 2696 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            OrderSpecList *osl = new OrderSpecList( LOC(yylhs.location) );
            osl->push_back( dynamic_cast<OrderSpec*>((yystack_[0].value.node)) );
            (yylhs.value.node) = osl;
        }
#line 5115 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 310:
#line 2702 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yystack_[2].value.node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yystack_[0].value.node)) );
            (yylhs.value.node) = (yystack_[2].value.node);
        }
#line 5125 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 311:
#line 2710 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderSpec( LOC(yylhs.location), (yystack_[0].value.expr), NULL );
        }
#line 5133 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 312:
#line 2714 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderSpec(
                LOC(yylhs.location), (yystack_[1].value.expr), dynamic_cast<OrderModifierPN*>((yystack_[0].value.node))
            );
        }
#line 5143 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 313:
#line 2722 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location), dynamic_cast<OrderDirSpec*>((yystack_[0].value.node)), NULL, NULL
            );
        }
#line 5153 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 314:
#line 2728 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location), NULL, dynamic_cast<OrderEmptySpec*>((yystack_[0].value.node)), NULL
            );
        }
#line 5163 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 315:
#line 2734 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node))
            );
        }
#line 5173 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 316:
#line 2740 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location),
                dynamic_cast<OrderDirSpec*>((yystack_[1].value.node)),
                dynamic_cast<OrderEmptySpec*>((yystack_[0].value.node)),
                NULL
            );
        }
#line 5186 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 317:
#line 2749 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location),
                dynamic_cast<OrderDirSpec*>((yystack_[1].value.node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node))
            );
        }
#line 5199 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 318:
#line 2758 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yystack_[1].value.node)),
                dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node))
            );
        }
#line 5212 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 319:
#line 2767 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderModifierPN(
                LOC(yylhs.location),
                dynamic_cast<OrderDirSpec*>((yystack_[2].value.node)),
                dynamic_cast<OrderEmptySpec*>((yystack_[1].value.node)),
                dynamic_cast<OrderCollationSpec*>((yystack_[0].value.node))
            );
        }
#line 5225 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 320:
#line 2778 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderDirSpec( LOC(yylhs.location), ParseConstants::dir_ascending );
        }
#line 5233 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 321:
#line 2782 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderDirSpec( LOC(yylhs.location), ParseConstants::dir_descending );
        }
#line 5241 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 322:
#line 2788 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderEmptySpec(
                LOC(yylhs.location), StaticContextConsts::empty_greatest
            );
        }
#line 5251 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 323:
#line 2794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderEmptySpec(
                LOC(yylhs.location), StaticContextConsts::empty_least
            );
        }
#line 5261 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 324:
#line 2802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OrderCollationSpec( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
        }
#line 5269 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 325:
#line 2808 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new QuantifiedExpr(
                LOC(yylhs.location),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yystack_[2].value.node)),
                (yystack_[0].value.expr)
            );
        }
#line 5282 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 326:
#line 2817 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new QuantifiedExpr(
                LOC(yylhs.location),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yystack_[2].value.node)),
                (yystack_[0].value.expr)
            );
        }
#line 5295 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 327:
#line 2828 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC(yylhs.location) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yystack_[0].value.node)) );
      (yylhs.value.node) = qvidl;
    }
#line 5305 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 328:
#line 2834 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yystack_[3].value.node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[3].value.node);
    }
#line 5315 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 329:
#line 2842 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QVarInDecl(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), (yystack_[0].value.expr));
    }
#line 5323 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 330:
#line 2846 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QVarInDecl(LOC(yylhs.location),
                          static_cast<QName*>((yystack_[3].value.expr)),
                          dynamic_cast<SequenceTypeAST *>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
    }
#line 5334 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 331:
#line 2855 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new SwitchExpr(LOC(yylhs.location), (yystack_[5].value.expr), static_cast<SwitchCaseClauseList*>((yystack_[3].value.node)), (yystack_[0].value.expr));
    }
#line 5342 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 332:
#line 2861 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC(yylhs.location));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = scc_list_p;
    }
#line 5352 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 333:
#line 2867 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yystack_[1].value.node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 5362 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 334:
#line 2875 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SwitchCaseClause(LOC(yylhs.location), dynamic_cast<SwitchCaseOperandList*>((yystack_[2].value.node)), (yystack_[0].value.expr));
    }
#line 5370 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 335:
#line 2881 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC(yylhs.location));
      sco_list_p->push_back((yystack_[0].value.expr));
      (yylhs.value.node) = sco_list_p;
    }
#line 5380 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 336:
#line 2887 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yystack_[2].value.node));
      sco_list_p->push_back((yystack_[0].value.expr));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 5390 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 337:
#line 2895 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new SwitchExpr(LOC(yylhs.location), (yystack_[5].value.expr), static_cast<SwitchCaseClauseList*>((yystack_[3].value.node)), (yystack_[0].value.expr));
    }
#line 5398 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 338:
#line 2901 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC(yylhs.location));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = scc_list_p;
    }
#line 5408 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 339:
#line 2907 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yystack_[1].value.node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 5418 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 340:
#line 2915 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SwitchCaseClause(LOC(yylhs.location), dynamic_cast<SwitchCaseOperandList*>((yystack_[2].value.node)), (yystack_[0].value.expr));
    }
#line 5426 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 341:
#line 2921 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TypeswitchExpr(LOC(yylhs.location),
                              (yystack_[5].value.expr),
                              static_cast<CaseClauseList*>((yystack_[3].value.node)),
                              (yystack_[0].value.expr));
    }
#line 5437 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 342:
#line 2928 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TypeswitchExpr(LOC (yylhs.location),
                              (yystack_[7].value.expr),
                              static_cast<CaseClauseList*>((yystack_[5].value.node)),
                              static_cast<QName*>((yystack_[2].value.expr)),
                              (yystack_[0].value.expr));
    }
#line 5449 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 343:
#line 2938 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TypeswitchExpr(LOC(yylhs.location),
                              (yystack_[5].value.expr),
                              static_cast<CaseClauseList*>((yystack_[3].value.node)),
                              (yystack_[0].value.expr));
    }
#line 5460 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 344:
#line 2945 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new TypeswitchExpr(LOC (yylhs.location),
                              (yystack_[7].value.expr),
                              static_cast<CaseClauseList*>((yystack_[5].value.node)),
                              static_cast<QName*>((yystack_[2].value.expr)),
                              (yystack_[0].value.expr));
    }
#line 5472 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 345:
#line 2955 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC (yylhs.location));
      cc_list_p->push_back(static_cast<CaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = cc_list_p;
    }
#line 5482 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 346:
#line 2961 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yystack_[1].value.node));
      cc_list_p->push_back(static_cast<CaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 5492 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 347:
#line 2969 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CaseClause(LOC (yylhs.location),
                          static_cast<SequenceTypeList*>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
    }
#line 5502 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 348:
#line 2975 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CaseClause(LOC (yylhs.location),
                          static_cast<QName*>((yystack_[4].value.expr)),
                          static_cast<SequenceTypeList*>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
     }
#line 5513 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 349:
#line 2984 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC (yylhs.location));
      cc_list_p->push_back(static_cast<CaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = cc_list_p;
    }
#line 5523 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 350:
#line 2990 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yystack_[1].value.node));
      cc_list_p->push_back(static_cast<CaseClause*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 5533 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 351:
#line 2998 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CaseClause(LOC (yylhs.location),
                          static_cast<SequenceTypeList*>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
    }
#line 5543 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 352:
#line 3004 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CaseClause(LOC (yylhs.location),
                          static_cast<QName*>((yystack_[4].value.expr)),
                          static_cast<SequenceTypeList*>((yystack_[2].value.node)),
                          (yystack_[0].value.expr));
     }
#line 5554 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 353:
#line 3013 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC(yylhs.location));
      seqList->push_back(static_cast<SequenceTypeAST*>((yystack_[0].value.node)));
      (yylhs.value.node) = seqList;
    }
#line 5564 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 354:
#line 3019 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yystack_[2].value.node));
      seqList->push_back(static_cast<SequenceTypeAST*>((yystack_[0].value.node)));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 5574 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 355:
#line 3027 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new IfExpr(LOC (yylhs.location), (yystack_[5].value.expr), (yystack_[2].value.expr), (yystack_[0].value.expr));
    }
#line 5582 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 356:
#line 3033 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 5590 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 357:
#line 3037 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new OrExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
    }
#line 5598 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 358:
#line 3043 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5606 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 359:
#line 3048 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AndExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5614 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 360:
#line 3054 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5622 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 361:
#line 3058 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                dynamic_cast<ValueComp*>((yystack_[1].value.node)),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5635 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 362:
#line 3067 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location), dynamic_cast<NodeComp*>((yystack_[1].value.node)), (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5645 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 363:
#line 3073 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_eq ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5658 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 364:
#line 3082 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_ne ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5671 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 365:
#line 3091 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            driver.getXqueryLexer()->interpretAsLessThan();
        }
#line 5679 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 366:
#line 3095 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_lt ),
                (yystack_[3].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5692 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 367:
#line 3104 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_le ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5705 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 368:
#line 3113 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_gt ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5718 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 369:
#line 3122 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ComparisonExpr(
                LOC(yylhs.location),
                new GeneralComp( LOC(yylhs.location), ParseConstants::op_ge ),
                (yystack_[2].value.expr),
                (yystack_[0].value.expr)
            );
        }
#line 5731 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 370:
#line 3133 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5739 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 371:
#line 3137 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new FTContainsExpr(
                LOC(yylhs.location),
                (yystack_[4].value.expr),
                dynamic_cast<FTSelection*>((yystack_[1].value.node)),
                dynamic_cast<FTIgnoreOption*>((yystack_[0].value.node))
            );
        }
#line 5752 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 372:
#line 3148 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5760 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 373:
#line 3152 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new StringConcatExpr(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr));
        }
#line 5768 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 374:
#line 3157 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 5776 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 375:
#line 3161 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 5784 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 376:
#line 3167 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5792 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 377:
#line 3171 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new RangeExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 378:
#line 3177 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5808 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 379:
#line 3181 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AdditiveExpr( LOC(yylhs.location), ParseConstants::op_plus, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5816 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 380:
#line 3185 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AdditiveExpr( LOC(yylhs.location), ParseConstants::op_minus, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5824 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 381:
#line 3191 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5832 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 382:
#line 3195 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new MultiplicativeExpr(
                LOC(yylhs.location), ParseConstants::op_mul, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5842 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 383:
#line 3201 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new MultiplicativeExpr(
                LOC(yylhs.location), ParseConstants::op_div, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5852 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 384:
#line 3207 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new MultiplicativeExpr(
                LOC(yylhs.location), ParseConstants::op_idiv, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5862 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 385:
#line 3213 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new MultiplicativeExpr(
                LOC(yylhs.location), ParseConstants::op_mod, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5872 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 386:
#line 3221 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5880 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 387:
#line 3225 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new UnionExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5888 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 388:
#line 3229 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new UnionExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 5896 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 389:
#line 3235 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5904 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 390:
#line 3239 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new IntersectExceptExpr(
                LOC(yylhs.location), ParseConstants::op_intersect, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5914 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 391:
#line 3245 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new IntersectExceptExpr(
                LOC(yylhs.location), ParseConstants::op_except, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 5924 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 392:
#line 3253 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5932 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 393:
#line 3257 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InstanceofExpr(
                LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node))
            );
        }
#line 5942 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 394:
#line 3265 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5950 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 395:
#line 3269 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new TreatExpr(
                LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<SequenceTypeAST*>((yystack_[0].value.node))
            );
        }
#line 5960 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 396:
#line 3277 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5968 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 397:
#line 3281 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new CastableExpr(
                LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<SingleType*>((yystack_[0].value.node))
            );
        }
#line 5978 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 398:
#line 3289 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 5986 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 399:
#line 3293 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new CastExpr(
                LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<SingleType*>((yystack_[0].value.node))
            );
        }
#line 5996 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 400:
#line 3301 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SingleType(LOC(yylhs.location), dynamic_cast<SimpleType*>((yystack_[0].value.node)), false);
    }
#line 6004 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 401:
#line 3305 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SingleType(LOC(yylhs.location), dynamic_cast<SimpleType*>((yystack_[1].value.node)), true);
    }
#line 6012 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 402:
#line 3311 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6020 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 403:
#line 3315 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new UnaryExpr( LOC(yylhs.location), dynamic_cast<SignList*>((yystack_[1].value.node)), (yystack_[0].value.expr) );
        }
#line 6028 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 404:
#line 3321 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SignList( LOC(yylhs.location), true );
        }
#line 6036 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 405:
#line 3325 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SignList( LOC(yylhs.location), false );
        }
#line 6044 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 406:
#line 3329 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 6052 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 407:
#line 3333 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yystack_[1].value.node)) )
                sl->negate();
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 6062 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 411:
#line 3346 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
        (yylhs.value.expr) = (yystack_[0].value.expr);
      }
#line 6070 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 412:
#line 3351 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
        (yylhs.value.expr) = new SimpleMapExpr(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr));
      }
#line 6078 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 413:
#line 3357 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_eq );
        }
#line 6086 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 414:
#line 3361 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_ne );
        }
#line 6094 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 415:
#line 3365 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_lt );
        }
#line 6102 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 416:
#line 3369 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_le );
        }
#line 6110 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 417:
#line 3373 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_gt );
        }
#line 6118 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 418:
#line 3377 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ValueComp( LOC(yylhs.location), ParseConstants::op_val_ge );
        }
#line 6126 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 419:
#line 3383 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NodeComp( LOC(yylhs.location), ParseConstants::op_is );
        }
#line 6134 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 420:
#line 3387 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NodeComp( LOC(yylhs.location), ParseConstants::op_precedes );
        }
#line 6142 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 421:
#line 3391 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NodeComp( LOC(yylhs.location), ParseConstants::op_follows );
        }
#line 6150 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 422:
#line 3397 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ValidateExpr( LOC(yylhs.location), "strict", (yystack_[1].value.expr) );
        }
#line 6158 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 423:
#line 3401 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ValidateExpr( LOC(yylhs.location), "lax", (yystack_[1].value.expr) );
        }
#line 6166 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 424:
#line 3405 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ValidateExpr( LOC(yylhs.location), "strict", (yystack_[1].value.expr) );
        }
#line 6174 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 425:
#line 3409 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ValidateExpr(
                LOC(yylhs.location), dynamic_cast<TypeName*>((yystack_[3].value.node))->get_name(), (yystack_[1].value.expr)
            );
            delete (yystack_[3].value.node);
        }
#line 6185 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 426:
#line 3418 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ExtensionExpr(
                LOC(yylhs.location), dynamic_cast<PragmaList*>((yystack_[3].value.node)), (yystack_[1].value.expr)
            );
        }
#line 6195 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 427:
#line 3426 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            PragmaList *pl = new PragmaList( LOC(yylhs.location) );
            pl->push_back( dynamic_cast<Pragma*>((yystack_[0].value.node)) );
            (yylhs.value.node) = pl;
        }
#line 6205 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 428:
#line 3432 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yystack_[1].value.node)) )
                pl->push_back( dynamic_cast<Pragma*>((yystack_[0].value.node)) );
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 6215 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 429:
#line 3440 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new Pragma( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), SYMTAB((yystack_[0].value.sval)) );
        }
#line 6223 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 430:
#line 3444 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new Pragma( LOC(yylhs.location), new QName( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) ), "" );
        }
#line 6231 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 431:
#line 3448 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new Pragma( LOC(yylhs.location), new QName( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), true ), "" );
        }
#line 6239 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 432:
#line 3454 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new PathExpr(LOC(yylhs.location), ParseConstants::path_leading_lone_slash, NULL);
    }
#line 6247 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 433:
#line 3458 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC(yylhs.location), ParseConstants::st_slash, NULL, (yystack_[0].value.expr), false);
      (yylhs.value.expr) = new PathExpr(LOC(yylhs.location),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
#line 6259 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 434:
#line 3466 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC(yylhs.location), ParseConstants::st_slashslash, NULL, (yystack_[0].value.expr), false);
      (yylhs.value.expr) = new PathExpr(LOC(yylhs.location),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
#line 6271 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 435:
#line 3474 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
        driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_AXIS_STEP));
      }
      if ((yylhs.value.expr) == NULL)
        (yylhs.value.expr) = (rpe ?
              new PathExpr( LOC(yylhs.location), ParseConstants::path_relative, (yystack_[0].value.expr)) :
              (yystack_[0].value.expr));
    }
#line 6293 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 436:
#line 3494 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = NULL;
    }
#line 6301 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 437:
#line 3500 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yystack_[0].value.expr));
      (yylhs.value.expr) = (as ?
            new RelativePathExpr(LOC(yylhs.location),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC(yylhs.location), true ), (yystack_[0].value.expr), true)
            :
            (yystack_[0].value.expr));
    }
#line 6315 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 438:
#line 3510 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new RelativePathExpr(LOC(yylhs.location), ParseConstants::st_slash, (yystack_[2].value.expr), (yystack_[0].value.expr), false);
    }
#line 6323 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 439:
#line 3514 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new RelativePathExpr(LOC(yylhs.location), ParseConstants::st_slashslash, (yystack_[2].value.expr), (yystack_[0].value.expr), false);
    }
#line 6331 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 442:
#line 3524 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AxisStep(
                LOC(yylhs.location), dynamic_cast<ForwardStep*>((yystack_[0].value.node)), NULL
            );
        }
#line 6341 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 443:
#line 3530 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AxisStep(
                LOC(yylhs.location),
                dynamic_cast<ForwardStep*>((yystack_[1].value.node)),
                dynamic_cast<PredicateList*>((yystack_[0].value.node))
            );
        }
#line 6353 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 444:
#line 3538 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AxisStep(
                LOC(yylhs.location), dynamic_cast<ReverseStep*>((yystack_[0].value.node)), NULL
            );
        }
#line 6363 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 445:
#line 3544 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new AxisStep(
                LOC(yylhs.location),
                dynamic_cast<ReverseStep*>((yystack_[1].value.node)),
                dynamic_cast<PredicateList*>((yystack_[0].value.node))
            );
        }
#line 6375 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 446:
#line 3554 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardStep(
                LOC(yylhs.location), dynamic_cast<ForwardAxis*>((yystack_[1].value.node)), (yystack_[0].value.node)
            );
        }
#line 6385 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 447:
#line 3560 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardStep(
                LOC(yylhs.location), dynamic_cast<AbbrevForwardStep*>((yystack_[0].value.node))
            );
        }
#line 6395 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 448:
#line 3568 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_child );
        }
#line 6403 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 449:
#line 3572 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_descendant);
        }
#line 6411 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 450:
#line 3576 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_attribute );
        }
#line 6419 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 451:
#line 3580 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_self );
        }
#line 6427 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 452:
#line 3584 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis(
                LOC(yylhs.location), ParseConstants::axis_descendant_or_self
            );
        }
#line 6437 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 453:
#line 3590 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis(
                LOC(yylhs.location), ParseConstants::axis_following_sibling
            );
        }
#line 6447 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 454:
#line 3596 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ForwardAxis( LOC(yylhs.location), ParseConstants::axis_following );
        }
#line 6455 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 455:
#line 3602 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AbbrevForwardStep( LOC(yylhs.location), (yystack_[0].value.node), false );
        }
#line 6463 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 456:
#line 3606 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AbbrevForwardStep( LOC(yylhs.location), (yystack_[0].value.node), true );
        }
#line 6471 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 457:
#line 3612 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseStep( LOC(yylhs.location), dynamic_cast<ReverseAxis*>((yystack_[1].value.node)), (yystack_[0].value.node) );
        }
#line 6479 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 458:
#line 3616 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC(yylhs.location), ParseConstants::axis_parent
            );
            (yylhs.value.node) = new ReverseStep( LOC(yylhs.location), ra, NULL );
        }
#line 6490 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 459:
#line 3625 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis( LOC(yylhs.location), ParseConstants::axis_parent );
        }
#line 6498 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 460:
#line 3629 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis( LOC(yylhs.location), ParseConstants::axis_ancestor );
        }
#line 6506 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 461:
#line 3633 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis(
                LOC(yylhs.location), ParseConstants::axis_preceding_sibling
            );
        }
#line 6516 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 462:
#line 3639 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis( LOC(yylhs.location), ParseConstants::axis_preceding );
        }
#line 6524 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 463:
#line 3643 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ReverseAxis(
                LOC(yylhs.location), ParseConstants::axis_ancestor_or_self
            );
        }
#line 6534 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 466:
#line 3655 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NameTest( LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)) );
        }
#line 6542 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 467:
#line 3659 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new NameTest( LOC(yylhs.location), dynamic_cast<Wildcard*>((yystack_[0].value.node)) );
        }
#line 6550 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 468:
#line 3665 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Wildcard(LOC(yylhs.location), "", "", ParseConstants::wild_all, false);
    }
#line 6558 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 469:
#line 3669 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Wildcard(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), "", ParseConstants::wild_elem, false);
    }
#line 6566 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 470:
#line 3673 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Wildcard(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), "", ParseConstants::wild_elem, true);
    }
#line 6574 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 471:
#line 3677 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new Wildcard(LOC(yylhs.location), "", SYMTAB((yystack_[0].value.sval)), ParseConstants::wild_prefix, false);
    }
#line 6582 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 472:
#line 3683 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = (yystack_[0].value.expr);
     }
#line 6590 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 473:
#line 3687 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new FilterExpr(LOC(yylhs.location), (yystack_[1].value.expr), dynamic_cast<PredicateList*>((yystack_[0].value.node)));
     }
#line 6598 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 474:
#line 3691 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new DynamicFunctionInvocation(LOC(yylhs.location), (yystack_[2].value.expr), false);
     }
#line 6606 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 475:
#line 3695 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new DynamicFunctionInvocation(LOC(yylhs.location), (yystack_[3].value.expr), dynamic_cast<ArgList*>((yystack_[1].value.node)), false);
     }
#line 6614 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 476:
#line 3701 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      PredicateList* pl = new PredicateList( LOC(yylhs.location) );
      pl->push_back(dynamic_cast<exprnode*>((yystack_[0].value.expr)));
      (yylhs.value.node) = pl;
    }
#line 6624 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 477:
#line 3707 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yystack_[1].value.node)))
        pl->push_back(dynamic_cast<exprnode*>((yystack_[0].value.expr)));
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 6634 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 478:
#line 3715 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 6642 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 493:
#line 3737 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6650 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 494:
#line 3741 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = (yystack_[0].value.expr);
        }
#line 6658 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 495:
#line 3747 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = NumericLiteral::new_literal(
                LOC(yylhs.location), ParseConstants::num_decimal, *(yystack_[0].value.decval)
            );
            delete yyla.value.decval;
        }
#line 6669 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 496:
#line 3754 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = NumericLiteral::new_literal(
                LOC(yylhs.location), ParseConstants::num_integer, *(yystack_[0].value.ival)
            );
            delete yyla.value.ival;
        }
#line 6680 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 497:
#line 3761 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = NumericLiteral::new_literal(
                LOC(yylhs.location), ParseConstants::num_double, *(yystack_[0].value.dval)
            );
            delete yyla.value.dval;
        }
#line 6691 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 498:
#line 3770 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new VarRef(LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)));
        }
#line 6699 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 499:
#line 3776 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ParenthesizedExpr( LOC(yylhs.location), NULL);
        }
#line 6707 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 500:
#line 3780 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ParenthesizedExpr( LOC(yylhs.location), (yystack_[1].value.expr) );
        }
#line 6715 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 501:
#line 3786 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            driver.addCommonLanguageWarning(yystack_[0].location, ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yylhs.value.expr) = new ContextItemExpr( LOC(yylhs.location) );
        }
#line 6724 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 502:
#line 3793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new OrderedExpr( LOC(yylhs.location), (yystack_[1].value.expr) );
        }
#line 6732 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 503:
#line 3799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new UnorderedExpr( LOC(yylhs.location), (yystack_[1].value.expr) );
        }
#line 6740 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 504:
#line 3805 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new FunctionCall(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), NULL);
    }
#line 6748 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 505:
#line 3809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 6768 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 506:
#line 3827 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ArgList* al = new ArgList(LOC(yylhs.location));
      al->push_back(new ArgumentPlaceholder(LOC(yylhs.location)));
      (yylhs.value.node) = al;
    }
#line 6778 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 507:
#line 3833 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yystack_[2].value.node)))
        al->push_back(new ArgumentPlaceholder(LOC(yylhs.location)));
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 6788 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 508:
#line 3839 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ArgList *al = new ArgList( LOC(yylhs.location) );
      al->push_back( (yystack_[0].value.expr) );
      (yylhs.value.node) = al;
    }
#line 6798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 509:
#line 3845 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yystack_[2].value.node)) )
        al->push_back( (yystack_[0].value.expr) );
      (yylhs.value.node) = (yystack_[2].value.node);
    }
#line 6808 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 510:
#line 3853 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 6816 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 511:
#line 3857 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 6824 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 512:
#line 3863 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new LiteralFunctionItem(LOC (yylhs.location), dynamic_cast<QName*>((yystack_[2].value.expr)), (yystack_[0].value.ival));
    }
#line 6832 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 513:
#line 3869 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new InlineFunction(LOC(yylhs.location),
                              &*(yystack_[1].value.fnsig)->theParams,
                              &*(yystack_[1].value.fnsig)->theReturnType,
                              (yystack_[0].value.expr));
      delete (yystack_[1].value.fnsig);
    }
#line 6844 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 519:
#line 3888 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirElemConstructor(LOC(yylhs.location),
                                  static_cast<QName*>((yystack_[2].value.expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
#line 6856 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 520:
#line 3896 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 6876 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 521:
#line 3912 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirElemConstructor(LOC(yylhs.location),
                                  static_cast<QName*>((yystack_[3].value.expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yystack_[2].value.node)),
                                  NULL);
    }
#line 6888 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 522:
#line 3920 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 6908 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 523:
#line 3938 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 6928 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 524:
#line 3956 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 6948 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 525:
#line 3974 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      DirElemContentList *decl = new DirElemContentList( LOC(yylhs.location) );
      decl->push_back( dynamic_cast<DirElemContent*>((yystack_[0].value.expr)) );
      (yylhs.value.node) = decl;
    }
#line 6958 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 526:
#line 3980 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yystack_[1].value.node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yystack_[0].value.expr)) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 6969 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 527:
#line 3989 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      DirAttributeList *dal = new DirAttributeList( LOC(yylhs.location) );
      dal->push_back( dynamic_cast<DirAttr*>((yystack_[0].value.node)) );
      (yylhs.value.node) = dal;
    }
#line 6979 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 528:
#line 3995 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yystack_[1].value.node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 6990 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 529:
#line 4004 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DirAttr(LOC(yylhs.location),
                       static_cast<QName*>((yystack_[4].value.expr)),
                       dynamic_cast<DirAttributeValue*>((yystack_[0].value.node)));
    }
#line 7000 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 532:
#line 4014 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DirAttributeValue(LOC(yylhs.location),
                                 dynamic_cast<QuoteAttrContentList*>((yystack_[1].value.node)));
    }
#line 7009 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 533:
#line 4019 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DirAttributeValue( LOC(yylhs.location),
                                  dynamic_cast<AposAttrContentList*>((yystack_[1].value.node)));
    }
#line 7018 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 534:
#line 4025 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QuoteAttrContentList( LOC(yylhs.location) );
    }
#line 7026 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 535:
#line 4029 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7034 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 536:
#line 4035 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC(yylhs.location) );
      qacl->push_back( new QuoteAttrValueContent( LOC(yylhs.location), "\"" ) );
      (yylhs.value.node) = qacl;
    }
#line 7044 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 537:
#line 4041 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC(yylhs.location) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yystack_[0].value.node)) );
      (yylhs.value.node) = qacl;
    }
#line 7054 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 538:
#line 4047 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yystack_[1].value.node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC(yylhs.location), "\"" ) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7065 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 539:
#line 4054 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yystack_[1].value.node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7076 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 540:
#line 4062 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AposAttrContentList( LOC(yylhs.location) );
    }
#line 7084 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 541:
#line 4066 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7092 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 542:
#line 4072 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC(yylhs.location) );
      aacl->push_back( new AposAttrValueContent( LOC(yylhs.location),"'") );
      (yylhs.value.node) = aacl;
    }
#line 7102 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 543:
#line 4078 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC(yylhs.location) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yystack_[0].value.node)) );
      (yylhs.value.node) = aacl;
    }
#line 7112 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 544:
#line 4084 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yystack_[1].value.node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC(yylhs.location),"'") );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7123 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 545:
#line 4091 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yystack_[1].value.node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yystack_[0].value.node)) );
      (yylhs.value.node) = (yystack_[1].value.node);
    }
#line 7134 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 546:
#line 4100 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QuoteAttrValueContent( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 7142 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 547:
#line 4104 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new QuoteAttrValueContent(LOC(yylhs.location), dynamic_cast<CommonContent*>((yystack_[0].value.expr)));
    }
#line 7150 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 548:
#line 4110 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AposAttrValueContent( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 7158 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 549:
#line 4114 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AposAttrValueContent(LOC(yylhs.location), dynamic_cast<CommonContent*>((yystack_[0].value.expr)));
    }
#line 7166 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 550:
#line 4120 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirElemContent( LOC(yylhs.location), (yystack_[0].value.expr) );
    }
#line 7174 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 551:
#line 4124 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirElemContent( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
    }
#line 7182 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 552:
#line 4128 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yystack_[0].value.expr));
      (yylhs.value.expr) = new DirElemContent( LOC(yylhs.location), cdata_h );
    }
#line 7191 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 553:
#line 4133 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yystack_[0].value.expr));
      (yylhs.value.expr) = new DirElemContent( LOC(yylhs.location), cont_h );
    }
#line 7200 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 554:
#line 4140 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CommonContent(LOC(yylhs.location), ParseConstants::cont_charref, SYMTAB((yystack_[0].value.sval)));
    }
#line 7208 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 555:
#line 4144 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CommonContent(LOC(yylhs.location), ParseConstants::cont_escape_lbrace);
    }
#line 7216 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 556:
#line 4148 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CommonContent(LOC(yylhs.location), ParseConstants::cont_escape_rbrace);
    }
#line 7224 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 557:
#line 4152 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CommonContent(LOC(yylhs.location), new EnclosedExpr(LOC(yylhs.location), (yystack_[1].value.expr)));
    }
#line 7232 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 558:
#line 4158 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirCommentConstructor( LOC(yylhs.location), SYMTAB((yystack_[1].value.sval)) );
    }
#line 7240 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 559:
#line 4163 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new DirCommentConstructor( LOC(yylhs.location), "" );
    }
#line 7248 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 560:
#line 4169 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[1].value.expr), yystack_[1].location);
      (yylhs.value.expr) = new DirPIConstructor( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)) );
    }
#line 7257 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 561:
#line 4175 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      ERROR_IF_QNAME_NOT_NCNAME((yystack_[1].value.expr), yystack_[1].location);
      (yylhs.value.expr) = new DirPIConstructor( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), SYMTAB((yystack_[0].value.sval)) );
    }
#line 7266 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 562:
#line 4182 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CDataSection( LOC(yylhs.location),SYMTAB((yystack_[0].value.sval)) );
    }
#line 7274 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 563:
#line 4188 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7282 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 564:
#line 4193 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7290 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 565:
#line 4198 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7298 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 566:
#line 4203 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7306 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 567:
#line 4208 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7314 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 568:
#line 4213 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[0].value.expr);
    }
#line 7322 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 570:
#line 4221 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompDocConstructor( LOC(yylhs.location), (yystack_[1].value.expr) );
    }
#line 7330 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 571:
#line 4227 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompElemConstructor(LOC(yylhs.location), new QName(LOC(yylhs.location), SYMTAB((yystack_[2].value.sval))), (yystack_[1].value.expr));
    }
#line 7338 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 572:
#line 4231 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompElemConstructor( LOC(yylhs.location), (yystack_[4].value.expr), (yystack_[1].value.expr) );
    }
#line 7346 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 573:
#line 4237 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompAttrConstructor( LOC(yylhs.location), new QName(LOC(yylhs.location), SYMTAB((yystack_[2].value.sval))), (yystack_[1].value.expr) );
    }
#line 7354 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 574:
#line 4241 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompAttrConstructor( LOC(yylhs.location), (yystack_[4].value.expr), (yystack_[1].value.expr) );
    }
#line 7362 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 575:
#line 4247 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompTextConstructor( LOC(yylhs.location), (yystack_[1].value.expr) );
    }
#line 7370 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 576:
#line 4253 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompCommentConstructor( LOC(yylhs.location), (yystack_[1].value.expr) );
    }
#line 7378 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 577:
#line 4259 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompPIConstructor(LOC(yylhs.location), SYMTAB((yystack_[2].value.sval)), (yystack_[1].value.expr));
    }
#line 7386 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 578:
#line 4263 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompPIConstructor(LOC(yylhs.location), (yystack_[4].value.expr), (yystack_[1].value.expr));
    }
#line 7394 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 579:
#line 4269 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompNamespaceConstructor(LOC(yylhs.location), SYMTAB((yystack_[2].value.sval)), (yystack_[1].value.expr));
    }
#line 7402 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 580:
#line 4273 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = new CompNamespaceConstructor(LOC(yylhs.location), (yystack_[4].value.expr), (yystack_[1].value.expr));
    }
#line 7410 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 581:
#line 4279 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7418 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 582:
#line 4285 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SequenceTypeAST( LOC(yylhs.location), (yystack_[0].value.node), NULL );
        }
#line 7426 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 583:
#line 4289 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SequenceTypeAST(LOC(yylhs.location), (yystack_[1].value.node), dynamic_cast<OccurrenceIndicator*>((yystack_[0].value.node)));
        }
#line 7434 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 584:
#line 4293 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SequenceTypeAST( LOC(yylhs.location), NULL, NULL );
        }
#line 7442 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 585:
#line 4299 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OccurrenceIndicator(
                LOC(yylhs.location), ParseConstants::occurs_optionally
            );
        }
#line 7452 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 586:
#line 4305 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OccurrenceIndicator(
                LOC(yylhs.location), ParseConstants::occurs_zero_or_more
            );
        }
#line 7462 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 587:
#line 4311 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new OccurrenceIndicator(
                LOC(yylhs.location), ParseConstants::occurs_one_or_more
            );
        }
#line 7472 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 588:
#line 4319 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 7480 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 589:
#line 4323 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 7488 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 590:
#line 4327 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ItemType( LOC(yylhs.location), true );
        }
#line 7496 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 591:
#line 4331 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new StructuredItemType(LOC(yylhs.location));
        }
#line 7504 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 592:
#line 4335 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 7512 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 593:
#line 4339 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 7520 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 594:
#line 4343 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 7528 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 595:
#line 4349 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          TypeList* aTypeList = new TypeList(LOC (yylhs.location));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
          (yylhs.value.node) = aTypeList;
        }
#line 7538 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 596:
#line 4355 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yystack_[2].value.node));
          aTypeList->push_back(dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
          (yylhs.value.node) = (yystack_[2].value.node);
        }
#line 7548 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 597:
#line 4363 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new GeneralizedAtomicType( LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)) );
    }
#line 7556 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 598:
#line 4369 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new SimpleType( LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)) );
    }
#line 7564 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 599:
#line 4375 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7572 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 600:
#line 4379 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7580 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 601:
#line 4383 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7588 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 602:
#line 4387 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7596 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 603:
#line 4391 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7604 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 604:
#line 4395 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7612 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 605:
#line 4399 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7620 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 606:
#line 4403 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7628 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 607:
#line 4407 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7636 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 608:
#line 4411 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7644 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 609:
#line 4417 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnyKindTest( LOC(yylhs.location) );
    }
#line 7652 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 610:
#line 4423 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = NULL;
    }
#line 7660 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 611:
#line 4429 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DocumentTest(LOC(yylhs.location));
    }
#line 7668 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 612:
#line 4433 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DocumentTest(LOC(yylhs.location), dynamic_cast<ElementTest*>((yystack_[1].value.node)));
    }
#line 7676 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 613:
#line 4437 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new DocumentTest(LOC(yylhs.location), dynamic_cast<SchemaElementTest*>((yystack_[1].value.node)));
    }
#line 7684 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 614:
#line 4443 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new NamespaceTest(LOC(yylhs.location));
    }
#line 7692 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 615:
#line 4448 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new TextTest(LOC(yylhs.location));
    }
#line 7700 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 616:
#line 4454 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new CommentTest(LOC(yylhs.location));
    }
#line 7708 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 617:
#line 4460 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new PITest( LOC(yylhs.location), "" );
        }
#line 7716 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 618:
#line 4464 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            ERROR_IF_QNAME_NOT_NCNAME((yystack_[1].value.expr), yystack_[1].location);
            (yylhs.value.node) = new PITest( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)) );
        }
#line 7725 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 619:
#line 4469 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new PITest( LOC(yylhs.location), SYMTAB((yystack_[1].value.sval)) );
        }
#line 7733 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 620:
#line 4475 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest( LOC(yylhs.location), NULL, NULL );
        }
#line 7741 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 621:
#line 4479 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest(
                LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), NULL
            );
        }
#line 7751 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 622:
#line 4485 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest(
                LOC(yylhs.location), static_cast<QName*>((yystack_[3].value.expr)), dynamic_cast<TypeName*>((yystack_[1].value.node))
            );
        }
#line 7761 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 623:
#line 4491 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest( LOC(yylhs.location), NULL, NULL );
        }
#line 7769 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 624:
#line 4495 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new AttributeTest(
                LOC(yylhs.location), NULL, dynamic_cast<TypeName*>((yystack_[1].value.node))
            );
        }
#line 7779 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 625:
#line 4503 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SchemaAttributeTest( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)) );
        }
#line 7787 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 626:
#line 4509 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest( LOC(yylhs.location), NULL, NULL, true );
        }
#line 7795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 627:
#line 4513 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), NULL, true
            );
        }
#line 7805 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 628:
#line 4519 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location),
                static_cast<QName*>((yystack_[3].value.expr)),
                dynamic_cast<TypeName*>((yystack_[1].value.node)),
                false
            );
        }
#line 7818 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 629:
#line 4528 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location),
                static_cast<QName*>((yystack_[3].value.expr)),
                dynamic_cast<TypeName*>((yystack_[1].value.node)),
                true
            );
        }
#line 7831 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 630:
#line 4537 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location), NULL, NULL, true
            );
        }
#line 7841 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 631:
#line 4543 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location), NULL, dynamic_cast<TypeName*>((yystack_[1].value.node)), false
            );
        }
#line 7851 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 632:
#line 4549 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new ElementTest(
                LOC(yylhs.location), NULL, dynamic_cast<TypeName*>((yystack_[1].value.node)), true
            );
        }
#line 7861 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 633:
#line 4557 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new SchemaElementTest( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)) );
        }
#line 7869 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 634:
#line 4563 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new TypeName( LOC(yylhs.location), static_cast<QName*>((yystack_[0].value.expr)) );
        }
#line 7877 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 635:
#line 4569 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new TypeName( LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), true );
        }
#line 7885 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 636:
#line 4575 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new StringLiteral( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
        }
#line 7893 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 637:
#line 4581 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7901 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 638:
#line 4585 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = (yystack_[0].value.node);
    }
#line 7909 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 639:
#line 4591 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.node) = new AnyFunctionTest(LOC(yylhs.location));
    }
#line 7917 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 640:
#line 4597 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new TypedFunctionTest(LOC (yylhs.location), dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
        }
#line 7925 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 641:
#line 4601 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new TypedFunctionTest(LOC (yylhs.location),
              dynamic_cast<TypeList *>((yystack_[3].value.node)),
              dynamic_cast<SequenceTypeAST *>((yystack_[0].value.node)));
        }
#line 7935 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 642:
#line 4609 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
           (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 7943 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 643:
#line 4615 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new RevalidationDecl(
                LOC(yylhs.location), StaticContextConsts::strict_validation
            );
        }
#line 7953 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 644:
#line 4621 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new RevalidationDecl(
                LOC(yylhs.location), StaticContextConsts::lax_validation
            );
        }
#line 7963 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 645:
#line 4627 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new RevalidationDecl(
                LOC(yylhs.location), StaticContextConsts::skip_validation
            );
        }
#line 7973 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 646:
#line 4635 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr( LOC(yylhs.location), store::UpdateConsts::INTO, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 7981 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 647:
#line 4639 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC(yylhs.location), store::UpdateConsts::AS_FIRST_INTO, (yystack_[4].value.expr), (yystack_[0].value.expr)
            );
        }
#line 7991 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 648:
#line 4645 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC(yylhs.location), store::UpdateConsts::AS_LAST_INTO, (yystack_[4].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8001 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 649:
#line 4651 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr( LOC(yylhs.location), store::UpdateConsts::AFTER, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 8009 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 650:
#line 4655 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC (yylhs.location), store::UpdateConsts::BEFORE, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8019 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 651:
#line 4661 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr( LOC(yylhs.location), store::UpdateConsts::INTO, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 8027 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 652:
#line 4665 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC(yylhs.location), store::UpdateConsts::AS_FIRST_INTO, (yystack_[4].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8037 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 653:
#line 4671 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                  LOC(yylhs.location), store::UpdateConsts::AS_LAST_INTO, (yystack_[4].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8047 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 654:
#line 4677 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC (yylhs.location),
                store::UpdateConsts::AFTER, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8058 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 655:
#line 4684 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new InsertExpr(
                LOC (yylhs.location), store::UpdateConsts::BEFORE, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8068 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 656:
#line 4692 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new DeleteExpr( LOC (yylhs.location), (yystack_[0].value.expr) );
        }
#line 8076 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 657:
#line 4697 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new DeleteExpr( LOC (yylhs.location), (yystack_[0].value.expr) );
        }
#line 8084 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 658:
#line 4703 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ReplaceExpr(
                LOC(yylhs.location), store::UpdateConsts::NODE, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8094 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 659:
#line 4709 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new ReplaceExpr(
                LOC(yylhs.location), store::UpdateConsts::VALUE_OF_NODE, (yystack_[2].value.expr), (yystack_[0].value.expr)
            );
        }
#line 8104 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 660:
#line 4717 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new RenameExpr( LOC (yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 8112 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 661:
#line 4723 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yystack_[4].value.expr));
      (yylhs.value.expr) = new TransformExpr( LOC(yylhs.location), cvl, (yystack_[2].value.expr), (yystack_[0].value.expr) );
    }
#line 8121 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 662:
#line 4730 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CopyVarList* lList = new CopyVarList(LOC(yylhs.location));
      lList->push_back (dynamic_cast<VarBinding*> ((yystack_[0].value.expr)));
      (yylhs.value.expr) = lList;
    }
#line 8131 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 663:
#line 4736 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yystack_[3].value.expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yystack_[0].value.expr));
      lList->push_back(lBinding);
      (yylhs.value.expr) = lList;
    }
#line 8142 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 664:
#line 4745 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new VarBinding(LOC(yylhs.location), static_cast<QName*>((yystack_[2].value.expr)), (yystack_[0].value.expr));
    }
#line 8150 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 665:
#line 4751 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.expr) = new TryExpr( LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 8158 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 666:
#line 4757 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            CatchListExpr *cle = new CatchListExpr( LOC(yylhs.location) );
            cle->push_back( static_cast<CatchExpr*>((yystack_[0].value.expr)) );
            (yylhs.value.expr) = cle;
        }
#line 8168 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 667:
#line 4763 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yystack_[1].value.expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yystack_[0].value.expr)) );
            (yylhs.value.expr) = (yystack_[1].value.expr);
        }
#line 8179 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 668:
#line 4772 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
       (yylhs.value.expr) = new CatchExpr(LOC(yylhs.location), *(yystack_[1].value.name_test_list), (yystack_[0].value.expr));
       delete (yystack_[1].value.name_test_list);
    }
#line 8188 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 669:
#line 4779 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
      (yylhs.value.expr) = (yystack_[1].value.expr);
    }
#line 8196 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 670:
#line 4785 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yystack_[0].value.node)) );
            (yylhs.value.name_test_list) = ntl;
        }
#line 8206 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 671:
#line 4791 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yystack_[2].value.name_test_list));
            ntl->push_back( static_cast<NameTest*>((yystack_[0].value.node)) );
            (yylhs.value.name_test_list) = ntl;
        }
#line 8217 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 672:
#line 4800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTSelection( LOC(yylhs.location), (yystack_[1].value.node), (yystack_[0].value.pos_filter_list) );
            delete (yystack_[0].value.pos_filter_list);
        }
#line 8226 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 673:
#line 4807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.pos_filter_list) = NULL;
        }
#line 8234 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 674:
#line 4811 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.pos_filter_list) = (yystack_[0].value.pos_filter_list);
        }
#line 8242 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 675:
#line 4817 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yylhs.value.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yystack_[0].value.node)) );
        }
#line 8251 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 676:
#line 4822 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yystack_[1].value.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yystack_[0].value.node)) );
            (yylhs.value.pos_filter_list) = (yystack_[1].value.pos_filter_list);
        }
#line 8260 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 677:
#line 4829 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8268 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 678:
#line 4833 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTOr( LOC(yylhs.location), (yystack_[2].value.node), (yystack_[0].value.node) );
        }
#line 8276 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 679:
#line 4839 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8284 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 680:
#line 4843 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnd( LOC(yylhs.location), (yystack_[2].value.node), (yystack_[0].value.node) );
        }
#line 8292 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 681:
#line 4849 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8300 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 682:
#line 4853 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTMildNot( LOC(yylhs.location), (yystack_[3].value.node), (yystack_[0].value.node) );
        }
#line 8308 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 683:
#line 4859 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8316 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 684:
#line 4863 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTUnaryNot(
                LOC(yylhs.location), dynamic_cast<FTPrimaryWithOptions*>((yystack_[0].value.node))
            );
        }
#line 8326 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 685:
#line 4871 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTPrimaryWithOptions(
                LOC(yylhs.location),
                dynamic_cast<FTPrimary*>((yystack_[2].value.node)),
                dynamic_cast<FTMatchOptions*>((yystack_[1].value.node)),
                dynamic_cast<FTWeight*>((yystack_[0].value.node))
            );
        }
#line 8339 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 686:
#line 4881 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8347 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 687:
#line 4885 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8355 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 688:
#line 4890 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8363 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 689:
#line 4894 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8371 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 690:
#line 4900 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWeight( LOC(yylhs.location), dynamic_cast<exprnode*>((yystack_[1].value.expr)) );
        }
#line 8379 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 691:
#line 4906 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWordsTimes(
                LOC(yylhs.location),
                dynamic_cast<FTWords*>((yystack_[1].value.node)),
                dynamic_cast<FTTimes*>((yystack_[0].value.node))
            );
        }
#line 8391 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 692:
#line 4914 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 8399 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 693:
#line 4918 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8407 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 694:
#line 4923 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8415 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 695:
#line 4927 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8423 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 696:
#line 4933 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTExtensionSelection(
                LOC(yylhs.location),
                dynamic_cast<PragmaList*>((yystack_[3].value.node)),
                dynamic_cast<FTSelection*>((yystack_[1].value.node))
            );
        }
#line 8435 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 697:
#line 4942 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8443 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 698:
#line 4946 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8451 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 699:
#line 4952 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWords(
                LOC(yylhs.location),
                dynamic_cast<FTWordsValue*>((yystack_[1].value.node)),
                dynamic_cast<FTAnyallOption*>((yystack_[0].value.node))
            );
        }
#line 8463 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 700:
#line 4962 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWordsValue(
                LOC(yylhs.location), static_cast<StringLiteral*>((yystack_[0].value.expr)), NULL
            );
        }
#line 8473 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 701:
#line 4968 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWordsValue(
                LOC(yylhs.location), NULL, dynamic_cast<exprnode*>((yystack_[1].value.expr))
            );
        }
#line 8483 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 702:
#line 4975 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnyallOption( LOC(yylhs.location), ft_anyall_mode::any );
        }
#line 8491 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 703:
#line 4979 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8499 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 704:
#line 4985 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnyallOption( LOC(yylhs.location), (yystack_[0].value.ft_anyall_value) );
        }
#line 8507 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 705:
#line 4989 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnyallOption( LOC(yylhs.location), (yystack_[0].value.ft_anyall_value) );
        }
#line 8515 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 706:
#line 4993 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTAnyallOption( LOC(yylhs.location), ft_anyall_mode::phrase );
        }
#line 8523 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 707:
#line 4998 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.ft_anyall_value) = ft_anyall_mode::any;
        }
#line 8531 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 708:
#line 5002 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.ft_anyall_value) = ft_anyall_mode::any_word;
        }
#line 8539 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 709:
#line 5007 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.ft_anyall_value) = ft_anyall_mode::all;
        }
#line 8547 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 710:
#line 5011 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.ft_anyall_value) = ft_anyall_mode::all_words;
        }
#line 8555 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 711:
#line 5017 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8563 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 712:
#line 5021 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8571 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 713:
#line 5025 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8579 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 714:
#line 5029 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8587 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 715:
#line 5033 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8595 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 716:
#line 5039 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTOrder( LOC(yylhs.location) );
        }
#line 8603 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 717:
#line 5045 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWindow(
                LOC(yylhs.location),
                static_cast<AdditiveExpr*>((yystack_[1].value.expr)),
                static_cast<FTUnit*>((yystack_[0].value.node))
            );
        }
#line 8615 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 718:
#line 5055 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTDistance(
                LOC(yylhs.location),
                dynamic_cast<FTRange*>((yystack_[1].value.node)),
                dynamic_cast<FTUnit*>((yystack_[0].value.node))
            );
        }
#line 8627 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 719:
#line 5065 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTUnit( LOC(yylhs.location), ft_unit::words );
        }
#line 8635 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 720:
#line 5069 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTUnit( LOC(yylhs.location), ft_unit::sentences );
        }
#line 8643 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 721:
#line 5073 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTUnit( LOC(yylhs.location), ft_unit::paragraphs );
        }
#line 8651 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 722:
#line 5079 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC(yylhs.location) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yystack_[0].value.node)) );
            (yylhs.value.node) = mo;
        }
#line 8661 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 723:
#line 5085 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yystack_[2].value.node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yystack_[0].value.node)) );
            (yylhs.value.node) = (yystack_[2].value.node);
        }
#line 8671 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 724:
#line 5093 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8679 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 725:
#line 5097 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8687 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 726:
#line 5101 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8695 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 727:
#line 5105 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8703 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 728:
#line 5109 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8711 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 729:
#line 5113 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8719 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 730:
#line 5117 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8727 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 731:
#line 5121 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8735 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 732:
#line 5127 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTCaseOption( LOC(yylhs.location), ft_case_mode::sensitive );
        }
#line 8743 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 733:
#line 5131 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTCaseOption( LOC(yylhs.location), ft_case_mode::insensitive );
        }
#line 8751 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 734:
#line 5135 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTCaseOption( LOC(yylhs.location), ft_case_mode::lower );
        }
#line 8759 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 735:
#line 5139 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTCaseOption( LOC(yylhs.location), ft_case_mode::upper );
        }
#line 8767 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 736:
#line 5145 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTDiacriticsOption(
                LOC(yylhs.location), ft_diacritics_mode::sensitive
            );
        }
#line 8777 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 737:
#line 5151 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTDiacriticsOption(
                LOC(yylhs.location), ft_diacritics_mode::insensitive
            );
        }
#line 8787 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 738:
#line 5159 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTExtensionOption(
                LOC(yylhs.location), static_cast<QName*>((yystack_[1].value.expr)), SYMTAB((yystack_[0].value.sval))
            );
        }
#line 8797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 739:
#line 5167 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStemOption( LOC(yylhs.location), ft_stem_mode::stemming );
        }
#line 8805 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 740:
#line 5171 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStemOption( LOC(yylhs.location), ft_stem_mode::no_stemming );
        }
#line 8813 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 741:
#line 5177 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( (yystack_[0].value.node) ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yystack_[0].value.node)) );
            }
            (yylhs.value.node) = new FTThesaurusOption( LOC(yylhs.location), til, !til );
            delete til;
        }
#line 8827 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 742:
#line 5187 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 8842 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 743:
#line 5198 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTThesaurusOption( LOC(yylhs.location), NULL, false, true );
        }
#line 8850 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 744:
#line 5204 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[0].value.node);
        }
#line 8858 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 745:
#line 5208 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8866 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 746:
#line 5213 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.thesaurus_id_list) = NULL;
        }
#line 8874 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 747:
#line 5217 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.thesaurus_id_list) = (yystack_[0].value.thesaurus_id_list);
        }
#line 8882 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 748:
#line 5223 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yylhs.value.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yystack_[0].value.node)) );
        }
#line 8891 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 749:
#line 5228 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yystack_[2].value.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yystack_[0].value.node)) );
            (yylhs.value.thesaurus_id_list) = (yystack_[2].value.thesaurus_id_list);
        }
#line 8900 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 750:
#line 5235 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTThesaurusID(
                LOC(yylhs.location), SYMTAB((yystack_[2].value.sval)), SYMTAB((yystack_[1].value.sval)), dynamic_cast<FTRange*>((yystack_[0].value.node))
            );
        }
#line 8910 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 751:
#line 5242 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.sval) = 0;
        }
#line 8918 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 752:
#line 5246 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.sval) = (yystack_[0].value.sval);
        }
#line 8926 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 753:
#line 5252 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = NULL;
        }
#line 8934 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 754:
#line 5256 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = (yystack_[1].value.node);
        }
#line 8942 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 755:
#line 5262 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordOption(
                LOC(yylhs.location),
                dynamic_cast<FTStopWords*>((yystack_[1].value.node)), (yystack_[0].value.incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yystack_[0].value.incl_excl_list);
        }
#line 8955 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 756:
#line 5271 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordOption(
                LOC(yylhs.location), NULL, (yystack_[0].value.incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yystack_[0].value.incl_excl_list);
        }
#line 8966 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 757:
#line 5278 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordOption(
                LOC(yylhs.location), NULL, NULL, ft_stop_words_mode::without
            );
        }
#line 8976 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 758:
#line 5286 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWords( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), NULL );
        }
#line 8984 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 759:
#line 5290 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWords( LOC(yylhs.location), "", (yystack_[1].value.strlist) );
        }
#line 8992 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 760:
#line 5296 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yystack_[0].value.sval)) );
            (yylhs.value.strlist) = sl;
        }
#line 9002 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 761:
#line 5302 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            if ( (yystack_[2].value.strlist) )
                (yystack_[2].value.strlist)->push_back( SYMTAB((yystack_[0].value.sval)) );
            (yylhs.value.strlist) = (yystack_[2].value.strlist);
        }
#line 9012 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 762:
#line 5309 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.incl_excl_list) = NULL;
        }
#line 9020 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 763:
#line 5313 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.incl_excl_list) = (yystack_[0].value.incl_excl_list);
        }
#line 9028 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 764:
#line 5319 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yylhs.value.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yystack_[0].value.node)) );
        }
#line 9037 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 765:
#line 5324 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            FTStopWordOption::incl_excl_list_t *iel = (yystack_[1].value.incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yystack_[0].value.node)) );
            (yylhs.value.incl_excl_list) = iel;
        }
#line 9049 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 766:
#line 5334 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordsInclExcl(
                LOC(yylhs.location),
                dynamic_cast<FTStopWords*>((yystack_[0].value.node)),
                ft_stop_words_unex::union_
            );
        }
#line 9061 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 767:
#line 5342 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTStopWordsInclExcl(
                LOC(yylhs.location),
                dynamic_cast<FTStopWords*>((yystack_[0].value.node)),
                ft_stop_words_unex::except
            );
        }
#line 9073 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 768:
#line 5352 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTLanguageOption( LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)) );
        }
#line 9081 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 769:
#line 5358 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWildCardOption( LOC(yylhs.location), ft_wild_card_mode::with );
        }
#line 9089 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 770:
#line 5362 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTWildCardOption( LOC(yylhs.location), ft_wild_card_mode::without );
        }
#line 9097 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 771:
#line 5368 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTContent( LOC(yylhs.location), ft_content_mode::at_start );
        }
#line 9105 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 772:
#line 5372 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTContent( LOC(yylhs.location), ft_content_mode::at_end );
        }
#line 9113 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 773:
#line 5376 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTContent( LOC(yylhs.location), ft_content_mode::entire );
        }
#line 9121 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 774:
#line 5382 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTTimes( LOC(yylhs.location), dynamic_cast<FTRange*>((yystack_[1].value.node)) );
        }
#line 9129 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 775:
#line 5388 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTRange( LOC(yylhs.location), ft_range_mode::exactly, (yystack_[0].value.expr) );
        }
#line 9137 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 776:
#line 5392 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTRange( LOC(yylhs.location), ft_range_mode::at_least, (yystack_[0].value.expr) );
        }
#line 9145 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 777:
#line 5396 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTRange( LOC(yylhs.location), ft_range_mode::at_most, (yystack_[0].value.expr) );
        }
#line 9153 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 778:
#line 5400 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTRange( LOC(yylhs.location), ft_range_mode::from_to, (yystack_[2].value.expr), (yystack_[0].value.expr) );
        }
#line 9161 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 779:
#line 5406 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTScope(
                LOC(yylhs.location),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yystack_[0].value.node))
            );
        }
#line 9173 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 780:
#line 5414 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTScope(
                LOC(yylhs.location),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yystack_[0].value.node))
            );
        }
#line 9185 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 781:
#line 5424 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTBigUnit( LOC(yylhs.location), ft_big_unit::sentence );
        }
#line 9193 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 782:
#line 5428 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTBigUnit( LOC(yylhs.location), ft_big_unit::paragraph );
        }
#line 9201 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 783:
#line 5434 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
            (yylhs.value.node) = new FTIgnoreOption( LOC(yylhs.location), static_cast<UnionExpr*>((yystack_[0].value.expr)) );
        }
#line 9209 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 784:
#line 5440 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONArrayConstructor( LOC(yylhs.location), NULL );
        }
#line 9217 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 785:
#line 5444 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONArrayConstructor( LOC(yylhs.location), (yystack_[1].value.expr) );
        }
#line 9225 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 786:
#line 5450 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectConstructor(LOC(yylhs.location), NULL, false);
        }
#line 9233 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 787:
#line 5454 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectConstructor(LOC(yylhs.location), (yystack_[1].value.expr), false);
        }
#line 9241 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 788:
#line 5460 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectConstructor(LOC(yylhs.location), NULL, true);
        }
#line 9249 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 789:
#line 5464 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectConstructor(LOC(yylhs.location), (yystack_[1].value.expr), true);
        }
#line 9257 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 790:
#line 5470 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONDirectObjectConstructor(LOC(yylhs.location),
                                               dynamic_cast<JSONPairList*>((yystack_[1].value.node)));
        }
#line 9266 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 791:
#line 5477 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          JSONPairList* jpl = new JSONPairList(LOC(yylhs.location));
          jpl->push_back(new JSONPairConstructor(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr)));
          (yylhs.value.node) = jpl;
        }
#line 9276 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 792:
#line 5483 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yystack_[4].value.node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr)));
          (yylhs.value.node) = jpl;
        }
#line 9287 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 793:
#line 5492 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONObjectInsertExpr(LOC(yylhs.location),
                                        (yystack_[2].value.expr),
                                        (yystack_[0].value.expr));
        }
#line 9297 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 794:
#line 5498 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yystack_[2].value.node));
          (yylhs.value.expr) = new JSONObjectInsertExpr(
              LOC(yylhs.location),
              new JSONDirectObjectConstructor(
                  LOC(yylhs.location),
                  jpl),
              (yystack_[0].value.expr));
        }
#line 9311 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 795:
#line 5508 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONArrayInsertExpr(LOC(yylhs.location), (yystack_[5].value.expr), (yystack_[3].value.expr), (yystack_[0].value.expr));
        }
#line 9319 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 796:
#line 5514 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.expr) = new JSONArrayAppendExpr(LOC(yylhs.location), (yystack_[2].value.expr), (yystack_[0].value.expr));
        }
#line 9327 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 797:
#line 5520 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 9346 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 798:
#line 5537 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 9372 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 799:
#line 5561 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
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
#line 9393 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 800:
#line 5580 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new JSON_Test(LOC(yylhs.location), store::StoreConsts::jsonItem);
        }
#line 9401 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 801:
#line 5584 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new JSON_Test(LOC(yylhs.location), store::StoreConsts::jsonArray);
        }
#line 9409 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 802:
#line 5588 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    {
          (yylhs.value.node) = new JSON_Test(LOC(yylhs.location), store::StoreConsts::jsonObject);
        }
#line 9417 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 805:
#line 5597 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval))); }
#line 9423 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 806:
#line 5598 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("attribute"))); }
#line 9429 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 807:
#line 5599 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("comment"))); }
#line 9435 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 808:
#line 5600 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("document-node"))); }
#line 9441 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 809:
#line 5601 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("namespace-node"))); }
#line 9447 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 810:
#line 5602 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("element"))); }
#line 9453 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 811:
#line 5603 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("item"))); }
#line 9459 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 812:
#line 5604 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("if"))); }
#line 9465 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 813:
#line 5605 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("node"))); }
#line 9471 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 814:
#line 5606 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
#line 9477 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 815:
#line 5607 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
#line 9483 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 816:
#line 5608 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("schema-element"))); }
#line 9489 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 817:
#line 5609 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("text"))); }
#line 9495 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 818:
#line 5610 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("typeswitch"))); }
#line 9501 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 819:
#line 5611 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("switch"))); }
#line 9507 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 820:
#line 5612 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
#line 9513 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 821:
#line 5613 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("while"))); }
#line 9519 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 822:
#line 5614 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("json"))); }
#line 9525 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 823:
#line 5615 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("array"))); }
#line 9531 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 824:
#line 5616 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("object"))); }
#line 9537 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 825:
#line 5617 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("json-item"))); }
#line 9543 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 826:
#line 5618 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("structured-item"))); }
#line 9549 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 828:
#line 5622 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval))); }
#line 9555 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 829:
#line 5623 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("xquery"))); }
#line 9561 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 830:
#line 5624 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("empty"))); }
#line 9567 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 831:
#line 5625 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("boundary-space"))); }
#line 9573 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 832:
#line 5626 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ft-option"))); }
#line 9579 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 833:
#line 5627 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("base-uri"))); }
#line 9585 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 834:
#line 5628 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("lax"))); }
#line 9591 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 835:
#line 5629 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("strict"))); }
#line 9597 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 836:
#line 5630 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("idiv"))); }
#line 9603 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 837:
#line 5631 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("document"))); }
#line 9609 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 838:
#line 5632 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ftnot"))); }
#line 9615 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 839:
#line 5633 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("not"))); }
#line 9621 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 840:
#line 5634 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sensitive"))); }
#line 9627 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 841:
#line 5635 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("insensitive"))); }
#line 9633 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 842:
#line 5636 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("diacritics"))); }
#line 9639 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 843:
#line 5637 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("without"))); }
#line 9645 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 844:
#line 5638 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("stemming"))); }
#line 9651 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 845:
#line 5639 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("thesaurus"))); }
#line 9657 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 846:
#line 5640 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("stop"))); }
#line 9663 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 847:
#line 5641 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("wildcards"))); }
#line 9669 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 848:
#line 5642 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("entire"))); }
#line 9675 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 849:
#line 5643 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("content"))); }
#line 9681 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 850:
#line 5644 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("word"))); }
#line 9687 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 851:
#line 5645 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("start"))); }
#line 9693 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 852:
#line 5646 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("end"))); }
#line 9699 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 853:
#line 5647 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("most"))); }
#line 9705 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 854:
#line 5648 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("skip"))); }
#line 9711 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 855:
#line 5649 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("copy"))); }
#line 9717 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 856:
#line 5650 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("general"))); }
#line 9723 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 857:
#line 5651 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("value"))); }
#line 9729 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 858:
#line 5652 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("eq"))); }
#line 9735 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 859:
#line 5653 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ne"))); }
#line 9741 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 860:
#line 5654 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("lt"))); }
#line 9747 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 861:
#line 5655 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("le"))); }
#line 9753 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 862:
#line 5656 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("gt"))); }
#line 9759 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 863:
#line 5657 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ge"))); }
#line 9765 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 864:
#line 5658 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("at"))); }
#line 9771 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 865:
#line 5659 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("context"))); }
#line 9777 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 866:
#line 5660 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("variable"))); }
#line 9783 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 867:
#line 5661 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("return"))); }
#line 9789 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 868:
#line 5662 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("for"))); }
#line 9795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 869:
#line 5663 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("from"))); }
#line 9801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 870:
#line 5664 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("allowing"))); }
#line 9807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 871:
#line 5665 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sliding"))); }
#line 9813 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 872:
#line 5666 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("tumbling"))); }
#line 9819 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 873:
#line 5667 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("previous"))); }
#line 9825 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 874:
#line 5668 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("next"))); }
#line 9831 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 875:
#line 5669 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("only"))); }
#line 9837 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 876:
#line 5670 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("when"))); }
#line 9843 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 877:
#line 5671 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("count"))); }
#line 9849 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 878:
#line 5672 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("in"))); }
#line 9855 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 879:
#line 5673 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("let"))); }
#line 9861 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 880:
#line 5674 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("where"))); }
#line 9867 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 881:
#line 5675 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("by"))); }
#line 9873 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 882:
#line 5676 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("group"))); }
#line 9879 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 883:
#line 5677 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("order"))); }
#line 9885 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 884:
#line 5678 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("stable"))); }
#line 9891 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 885:
#line 5679 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ascending"))); }
#line 9897 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 886:
#line 5680 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("descending"))); }
#line 9903 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 887:
#line 5681 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("greatest"))); }
#line 9909 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 888:
#line 5682 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("least"))); }
#line 9915 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 889:
#line 5683 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("collation"))); }
#line 9921 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 890:
#line 5684 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("some"))); }
#line 9927 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 891:
#line 5685 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("every"))); }
#line 9933 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 892:
#line 5686 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("satisfies"))); }
#line 9939 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 893:
#line 5687 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("case"))); }
#line 9945 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 894:
#line 5688 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("as"))); }
#line 9951 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 895:
#line 5689 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("then"))); }
#line 9957 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 896:
#line 5690 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("else"))); }
#line 9963 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 897:
#line 5691 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("or"))); }
#line 9969 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 898:
#line 5692 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("and"))); }
#line 9975 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 899:
#line 5693 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("instance"))); }
#line 9981 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 900:
#line 5694 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("of"))); }
#line 9987 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 901:
#line 5695 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("castable"))); }
#line 9993 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 902:
#line 5696 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("to"))); }
#line 9999 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 903:
#line 5697 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("div"))); }
#line 10005 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 904:
#line 5698 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("mod"))); }
#line 10011 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 905:
#line 5699 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("union"))); }
#line 10017 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 906:
#line 5700 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("intersect"))); }
#line 10023 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 907:
#line 5701 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("except"))); }
#line 10029 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 908:
#line 5702 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("validate"))); }
#line 10035 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 909:
#line 5703 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("type"))); }
#line 10041 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 910:
#line 5704 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("cast"))); }
#line 10047 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 911:
#line 5705 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("treat"))); }
#line 10053 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 912:
#line 5706 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("is"))); }
#line 10059 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 913:
#line 5707 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("preserve"))); }
#line 10065 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 914:
#line 5708 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("strip"))); }
#line 10071 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 915:
#line 5709 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("namespace"))); }
#line 10077 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 916:
#line 5710 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("external"))); }
#line 10083 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 917:
#line 5711 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("encoding"))); }
#line 10089 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 918:
#line 5712 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("no-preserve"))); }
#line 10095 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 919:
#line 5713 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("inherit"))); }
#line 10101 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 920:
#line 5714 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("no-inherit"))); }
#line 10107 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 921:
#line 5715 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("declare"))); }
#line 10113 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 922:
#line 5716 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("construction"))); }
#line 10119 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 923:
#line 5717 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ordering"))); }
#line 10125 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 924:
#line 5718 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("default"))); }
#line 10131 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 925:
#line 5719 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
#line 10137 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 926:
#line 5720 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("option"))); }
#line 10143 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 927:
#line 5721 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("version"))); }
#line 10149 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 928:
#line 5722 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("import"))); }
#line 10155 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 929:
#line 5723 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("schema"))); }
#line 10161 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 930:
#line 5724 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("module"))); }
#line 10167 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 931:
#line 5725 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("function"))); }
#line 10173 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 932:
#line 5726 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("score"))); }
#line 10179 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 933:
#line 5727 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("contains"))); }
#line 10185 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 934:
#line 5728 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("weight"))); }
#line 10191 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 935:
#line 5729 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("window"))); }
#line 10197 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 936:
#line 5730 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("distance"))); }
#line 10203 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 937:
#line 5731 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("occurs"))); }
#line 10209 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 938:
#line 5732 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("times"))); }
#line 10215 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 939:
#line 5733 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("same"))); }
#line 10221 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 940:
#line 5734 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("different"))); }
#line 10227 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 941:
#line 5735 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("lowercase"))); }
#line 10233 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 942:
#line 5736 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("uppercase"))); }
#line 10239 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 943:
#line 5737 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("relationship"))); }
#line 10245 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 944:
#line 5738 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("levels"))); }
#line 10251 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 945:
#line 5739 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("language"))); }
#line 10257 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 946:
#line 5740 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("any"))); }
#line 10263 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 947:
#line 5741 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("all"))); }
#line 10269 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 948:
#line 5742 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("exactly"))); }
#line 10275 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 949:
#line 5743 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("words"))); }
#line 10281 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 950:
#line 5744 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sentences"))); }
#line 10287 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 951:
#line 5745 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sentence"))); }
#line 10293 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 952:
#line 5746 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("phrase"))); }
#line 10299 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 953:
#line 5747 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("paragraph"))); }
#line 10305 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 954:
#line 5748 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("paragraphs"))); }
#line 10311 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 955:
#line 5749 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("modify"))); }
#line 10317 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 956:
#line 5750 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("first"))); }
#line 10323 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 957:
#line 5751 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("append"))); }
#line 10329 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 958:
#line 5752 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("insert"))); }
#line 10335 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 959:
#line 5753 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("replace"))); }
#line 10341 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 960:
#line 5754 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("rename"))); }
#line 10347 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 961:
#line 5755 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("delete"))); }
#line 10353 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 962:
#line 5756 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("before"))); }
#line 10359 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 963:
#line 5757 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("after"))); }
#line 10365 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 964:
#line 5758 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("revalidation"))); }
#line 10371 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 965:
#line 5759 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("with"))); }
#line 10377 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 966:
#line 5760 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("nodes"))); }
#line 10383 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 967:
#line 5761 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("last"))); }
#line 10389 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 968:
#line 5762 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("into"))); }
#line 10395 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 969:
#line 5763 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("simple"))); }
#line 10401 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 970:
#line 5764 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("sequential"))); }
#line 10407 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 971:
#line 5765 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("updating"))); }
#line 10413 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 972:
#line 5766 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ordered"))); }
#line 10419 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 973:
#line 5767 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("unordered"))); }
#line 10425 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 974:
#line 5768 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("returning"))); }
#line 10431 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 975:
#line 5769 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("exit"))); }
#line 10437 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 976:
#line 5770 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("loop"))); }
#line 10443 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 977:
#line 5771 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("break"))); }
#line 10449 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 978:
#line 5772 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("continue"))); }
#line 10455 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 979:
#line 5773 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("try"))); }
#line 10461 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 980:
#line 5774 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("catch"))); }
#line 10467 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 981:
#line 5775 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("using"))); }
#line 10473 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 982:
#line 5776 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("set"))); }
#line 10479 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 983:
#line 5777 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("index"))); }
#line 10485 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 984:
#line 5778 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("unique"))); }
#line 10491 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 985:
#line 5779 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("non"))); }
#line 10497 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 986:
#line 5780 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("on"))); }
#line 10503 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 987:
#line 5781 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("range"))); }
#line 10509 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 988:
#line 5782 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("equality"))); }
#line 10515 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 989:
#line 5783 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("manually"))); }
#line 10521 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 990:
#line 5784 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("automatically"))); }
#line 10527 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 991:
#line 5785 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("maintained"))); }
#line 10533 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 992:
#line 5786 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("decimal-format"))); }
#line 10539 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 993:
#line 5787 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
#line 10545 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 994:
#line 5788 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
#line 10551 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 995:
#line 5789 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("infinity"))); }
#line 10557 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 996:
#line 5790 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("minus-sign"))); }
#line 10563 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 997:
#line 5791 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("NaN"))); }
#line 10569 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 998:
#line 5792 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("percent"))); }
#line 10575 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 999:
#line 5793 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("per-mille"))); }
#line 10581 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1000:
#line 5794 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("zero-digit"))); }
#line 10587 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1001:
#line 5795 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("digit"))); }
#line 10593 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1002:
#line 5796 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
#line 10599 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1003:
#line 5797 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("collection"))); }
#line 10605 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1004:
#line 5798 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("const"))); }
#line 10611 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1005:
#line 5799 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("append-only"))); }
#line 10617 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1006:
#line 5800 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("queue"))); }
#line 10623 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1007:
#line 5801 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("mutable"))); }
#line 10629 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1008:
#line 5802 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("read-only"))); }
#line 10635 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1009:
#line 5803 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("integrity"))); }
#line 10641 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1010:
#line 5804 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("constraint"))); }
#line 10647 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1011:
#line 5805 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("check"))); }
#line 10653 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1012:
#line 5806 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("key"))); }
#line 10659 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1013:
#line 5807 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("foreach"))); }
#line 10665 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1014:
#line 5808 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("foreign"))); }
#line 10671 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1015:
#line 5809 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("keys"))); }
#line 10677 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1016:
#line 5810 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ancestor"))); }
#line 10683 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1017:
#line 5811 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("child"))); }
#line 10689 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1018:
#line 5812 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("descendant"))); }
#line 10695 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1019:
#line 5813 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("parent"))); }
#line 10701 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1020:
#line 5814 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("preceding"))); }
#line 10707 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1021:
#line 5815 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("self"))); }
#line 10713 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1022:
#line 5816 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("following"))); }
#line 10719 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1023:
#line 5817 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
#line 10725 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1024:
#line 5818 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
#line 10731 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1025:
#line 5819 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("following-sibling"))); }
#line 10737 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1026:
#line 5820 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
#line 10743 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1027:
#line 5821 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB(SYMTAB_PUT("position"))); }
#line 10749 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;

  case 1028:
#line 5824 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:847
    { (yylhs.value.expr) = new QName(LOC(yylhs.location), SYMTAB((yystack_[0].value.sval)), true); }
#line 10755 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
    break;


#line 10759 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:847
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
  xquery_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  xquery_parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
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


  const short int xquery_parser::yypact_ninf_ = -1425;

  const short int xquery_parser::yytable_ninf_ = -869;

  const short int
  xquery_parser::yypact_[] =
  {
    4693, -1425, -1425, -1425, -1425,  6247,  6247,  6247,  6247, -1425,
   -1425,   197,   260, -1425,  1422,    58, -1425, -1425, -1425,   806,
   -1425, -1425, -1425,   292,   360,   810,  4411,   529,   644,   850,
   -1425,    78, -1425,   691, -1425, -1425, -1425, -1425, -1425,   814,
   -1425,   695,   737, -1425, -1425, -1425, -1425,   372, -1425,   815,
   -1425,   780,   832, -1425,   427, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   533,
     660, -1425, -1425, -1425, -1425,   690, 12447, -1425, -1425, -1425,
     853, -1425, -1425, -1425,   863, -1425,   869,   871, -1425, -1425,
   16318, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   879,
   -1425, -1425,   877,   887, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,  5317,  8727,  9037, 16318, -1425, -1425,   860, -1425, -1425,
   -1425, -1425,   865, -1425, -1425,   899, 16318, -1425, 13358,   901,
     902, -1425, -1425, -1425,   903, -1425, -1425, 11827, -1425, -1425,
   -1425, -1425, -1425, -1425,   876, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,    77,   811, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,   -72,   875,   -51, -1425,  -101,   390, -1425,
   -1425, -1425, -1425, -1425, -1425,   915, -1425,   792,   794,   795,
   -1425, -1425,   882,   889, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,  9347,  9657, -1425,
     727, -1425, -1425, -1425, -1425, -1425,  5005,  6557,  1044, -1425,
    6867, -1425, -1425,   332,    76, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,    95,
   -1425, -1425, -1425, -1425, -1425, -1425,   482, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425,  6247, -1425, -1425, -1425, -1425,
     351, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
     180, -1425,   866, -1425, -1425, -1425,   675, -1425,   532, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   890,   966, -1425,   950,
     813,   960,   713,   588,   632,    36, -1425,  1013,   864,   963,
     964, 10277, -1425,   878, -1425, -1425,   528, -1425, -1425, 12137,
   -1425,   755, -1425,   911, 12447, -1425,   911, 12447, -1425, -1425,
   -1425,   801, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   912,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   785, -1425, -1425,
   -1425, -1425, -1425,   884, -1425,  6247,   888,   891,   894,  6247,
     548,   548,  1043,   717,   747,   480, 16906, 16318,   609,  1032,
   16318,   927,   962,   640, 16318,   763,   836, 16318, 16318,   786,
     507,    82, -1425, -1425, -1425, 16318,  6247,   897,  6247,   140,
   10587, 13654, 16318,   -19,   933, 10587,  1087,   182,   135, 16318,
     974,   953,   989, -1425,   913, 10587, 13950, 16318, 16318, 16318,
    6247,   916, 10587, 10587, 16318,  6247,   944,   945, -1425, -1425,
   -1425, 10587, 14246,   947, -1425,   952, -1425, -1425, -1425, -1425,
     954, -1425,   955, -1425, -1425, -1425, -1425, -1425,   957, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, 16318, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,   958, 16318, -1425, -1425, -1425,   923,  5627,   988,   303,
     961,   967,   969, 16318,  6247, -1425,   968,   234, -1425,   675,
   -1425,   131,  1084, 10587, 10587, -1425,   112, -1425, -1425,  1103,
   -1425, -1425, -1425, -1425, 10587,   909, -1425,  1097, 10587, 10587,
   16618, 10587, 10587, 10587, 10587, 16618, 10587,   904, 16318,   938,
     940, 10587, 10587,  5317,   892, -1425,    67, -1425,    54, 10587,
    6557, -1425, -1425, -1425, -1425, -1425,  1422,   850,   102,   104,
    1131,  7177,  3149,  7487,  3470,   863, -1425, -1425,   204,   863,
   -1425, 10587,  4090, -1425,  1017,   757,    78,   970,   971,   972,
   -1425, 10587, -1425, -1425,  6247, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,   855,   856, 16318,  1024, 10897, 10897, 10897, -1425,
   10897, 10897, -1425, 10897, -1425, 10897, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, 10897, 10897,  1073, 10897, 10897, 10897, 10897,
   10897, 10897, 10897, 10897, 10897, 10897, 10897, 10897,   920,  1050,
    1051,  1052, -1425, -1425, -1425, 11517,  6247, -1425, -1425, 11827,
   11827, 10587,   911, -1425, -1425,   911, -1425,  8107,   911,   976,
    1002,  8417, -1425, -1425, -1425, -1425,   369, -1425,   381, -1425,
   -1425, -1425, -1425, -1425, -1425,  1053,  1056,   529,  1129, -1425,
   -1425, 16906,   965,   694, 16318,  1004,  1005,   965,  1043,  1039,
    1035, -1425, -1425, -1425,   188,   924,  1074,   883, 16318,  1029,
   10587,  1055, 16318, 16318, -1425,  1042,   994, -1425,   997,   952,
     737, -1425,   998,  1000,   215, -1425,   419,   443,  1076, -1425,
      46, 16318,  1093,   478, -1425,  6247, -1425,   150, -1425, 16318,
    1092,  1145, 16318,  1043,  1094,   697, 16318, 10587,    78, -1425,
     334,  1006, -1425,  1007,  1009,  1010,   250, -1425,   621,  1008,
   -1425,   151,   162,  1045, -1425,  1014,  6247,  6247,   335, -1425,
     493,   505,   702, 10587,   263, -1425, -1425, 10587, 10587, -1425,
   10587, 10587, 10587, -1425, 10587, -1425, 10587, -1425, 16318,  1084,
   -1425,   458,   339,   374, -1425, -1425, -1425,   386, -1425,   479,
   -1425, -1425,  1046,  1047,  1048,  1049,  1054,   801,   785,   230,
     287,   274,    13,  1109,   517,   973,  -100,    27, -1425,  1062,
   -1425, -1425,  1016,   169,  5627,   432, 12757,   892, -1425, -1425,
   -1425,   978, -1425,   332,   825,  1174,   166, -1425, -1425,   117,
   -1425, -1425, -1425,   125, -1425,    65, -1425, -1425, -1425, -1425,
   -1425,  3780, -1425, -1425, -1425, 16318,  1057, 10587, 11207, -1425,
   -1425, -1425, -1425, -1425,  1076, 16318,    63,   966, -1425, -1425,
   -1425, -1425, -1425, 10897, -1425, -1425, -1425,    71, -1425,   588,
     588,    10,   632,   632,   632,   632,    36,    36, -1425, -1425,
   15430, 15430, 16318, 16318, -1425,  1028, -1425, -1425,   237, -1425,
   -1425, -1425, -1425,   544, -1425, -1425, -1425,   549,   548, -1425,
   -1425,   602,   606,   543, -1425,   529, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   965, -1425,  1080, 15726,
    1071, 10587, -1425, -1425, -1425,  1120,  1043,  1043,   965, -1425,
     867,  1043,   696, 16318,   676,   678,  1186, -1425, -1425,   931,
      52, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,   188,    44,   991,   646, 10587, -1425, 16318,  1125,
     922,  1043, -1425, -1425, -1425, -1425,  1068, 16318, -1425, 16318,
   -1425, 16022,  1095, 15430,  1105, 10587,   -20,  1077,    59,  1120,
   15430,  1107,  1133,  1058,  1031,  1098,  1043,  1069,  1099,  1136,
    1043, 10587,    80, -1425, -1425, -1425,  1081, -1425, -1425, -1425,
   -1425,  1115, 10587, 10587,  1088, -1425,  1137,  1138,  6247, -1425,
    1059,  1060,  1086, 16318, -1425, 16318, -1425, 10587,  1102,  1061,
   10587, -1425,  1124,   192,   221,   223,  1212, -1425,   474, -1425,
     107,  1096, -1425, -1425,  1222, -1425,   756, 10587, 10587, 10587,
     759, 10587, 10587, 10587, 10587, 10587, 10587, 10587, 10587, 10587,
   16618,  1135, 10587, 10587, -1425,  7797,   129,  1011, -1425,   499,
   -1425, 10587,   136,   189,    65,  7487,  3470,  7487,  1175, -1425,
   -1425, 10587,   797,  1149, -1425, 16318,  1151,  1152, -1425,   682,
    1012, -1425, -1425,   731,    63, -1425, 10587,    71,   738,   589,
   -1425,   977,   293,  1001,  1003, -1425, -1425,   836, -1425,  1015,
     638,  1111,  1112, 15726,  1113,  1114,  1117,  1118,  1121, -1425,
      14, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,  1119, -1425, -1425, -1425, -1425,  9967, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,   700, -1425,  1249,   643,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   995,
   -1425, -1425,  1250, -1425, -1425, -1425, -1425, -1425,   642,  1255,
   -1425,   784, -1425, -1425, -1425,   947,   360,   691,   954,   695,
     955,   957, -1425,  1114,  1117,  1118, -1425,    14,    14, 11517,
     999,   983, -1425,  1120,    44,  1063,  1104,  6247,  1106,  1110,
    1147,  1122,  1126, 16318, -1425,   382, -1425, 16318, -1425, 10587,
    1148, 10587,  1170, 10587,    86,  1153, -1425, -1425, -1425, 15430,
   -1425,  6247,  1043,  1191, -1425, -1425, -1425,  1043,  1191, -1425,
   10587,  1159,  6247, 16318, -1425, -1425, 10587, 10587,   449, -1425,
     343,   796, -1425, 14542,   819, -1425,   820, -1425,  1128, -1425,
   -1425,  6247,  1127,  1130, -1425, 10587, -1425, -1425, 10587,  1108,
    1137,  1203, -1425,  1172, -1425,   575, -1425, -1425,  1301, -1425,
   -1425,  6247, 16318, -1425,   599, -1425, -1425, -1425,  6247,  1132,
    1083,  1100, -1425, -1425, -1425,  1116,  1134, -1425, -1425, -1425,
    1223, -1425, -1425, -1425, -1425,  1089,   338, 16318,  1139, -1425,
    1164,  1178,  1179,  1177, -1425,   866,   675, 12757,  1011, -1425,
    5937, 12757, -1425, -1425,  1174,   348, -1425, -1425, -1425,  1149,
   -1425,  1043, -1425,   873, -1425,   688,  1225, -1425, 10587,   722,
    1043, -1425, 11207, 10587,  1181, -1425,  1218,  1219, 10587, 16318,
     847,  1262, -1425, -1425, -1425,   434,  1154, -1425,    71,  1123,
   -1425, -1425,   -53, -1425,   641,   340,  1144,    71,   641, 10897,
   -1425,   307, -1425, -1425, -1425, -1425, -1425, -1425,    71,  1194,
    1065,   924,   340, -1425, -1425,  1066,  1264, -1425, -1425, -1425,
   13053,  1157,  1158,  1161,  1166,  1168,  1173,  1176, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425,  1327,    17,  1329,    17,  1101,  1256, -1425, -1425,  1195,
   16318,  1140, -1425, -1425, 11517, -1425,  1184, -1425, -1425, -1425,
   -1425, -1425, -1425, 10587,  1226, -1425, -1425, 10587, -1425,   662,
   -1425, 10587,  1229, 10587, -1425,  1243,  1244,  1282,  1043,  1191,
   -1425, 10587,  1196, -1425, -1425, -1425,  1139, -1425,   343, 10587,
    6247,  1139,   343, -1425, 16318,   -26, -1425, 14838,    29, -1425,
   15134,  1139, -1425, -1425,  1197, -1425, -1425, -1425, -1425, 10587,
     834,  1212, 16318,   626, -1425,  1198,  1212, 16318, -1425,  1200,
   -1425, 10587, 10587, 10587, 10587,  1072, 10587, 10587, -1425, 10587,
   10587, 10587, 10587,  7797,   586, -1425, -1425, -1425, -1425, -1425,
    1225, -1425, -1425, -1425, 10587,  1242, -1425, -1425, -1425, 10587,
   16318, 16318, -1425,   739, -1425, 10587, -1425, -1425, -1425,  1205,
   10897, -1425, -1425, -1425, -1425, -1425,    62, 10897, 10897,   584,
   -1425,  1001, -1425,   407, -1425,  1003,    71,  1233, -1425, -1425,
    1142, -1425, -1425, -1425, -1425,  1300,  1209, -1425,   550, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   520,   520, -1425,
      17, -1425, -1425,   555, -1425,  1370,   340,  1304,  1215, 11517,
     -25,  1141,  1234, -1425, -1425, 10587, -1425, 10587,  1257, -1425,
   10587, -1425,  7797, 10587,  1043, -1425, -1425, -1425, 10587, 10587,
   -1425, -1425, -1425,  7797,  7797,  1308, 15430,  6247, 16318,   -26,
   16318, 10587, 16318,   -26,  7797, -1425,    31,   298,  1212, 16318,
   -1425,  1210,  1212, -1425, -1425, -1425, -1425, -1425, 10587, -1425,
   -1425, -1425,   231,   239,   249, 10587, -1425, -1425,  1151, 10587,
   -1425, -1425,  1354, -1425, -1425, -1425,   632, 10897, 10897,    10,
     724, -1425, -1425, -1425, -1425, -1425, -1425, 10587, -1425, 15430,
   -1425, 15430,  1314, -1425, -1425, -1425,  1383, -1425, -1425, -1425,
    1150,  1309, -1425, -1425,  1310, -1425,   783, 16318,  1297,  1199,
   16318, 11517, -1425, -1425, 10587, -1425, -1425, -1425,  1191, -1425,
   -1425, 15430, -1425, -1425, -1425,  1324, 10587,  1139, -1425,  1325,
    7797, -1425, 16318,   448,   540, -1425,  1228,  1212, -1425,  1230,
   -1425,  1231,  1137,  1138,   459, -1425,  1151,  1307,    10,    10,
   10897,   463, -1425, -1425, 15430, -1425, -1425,  1304, 11517, -1425,
    1225,  1156, 16318,  1312,  1207,  1310, -1425,   -26, 15430,  6247,
   15430,  1139, -1425, -1425,  1340,   620, -1425, -1425, -1425, -1425,
    1240,   578, -1425, -1425, -1425,  1238, -1425,  7797,   835, -1425,
   -1425, 16318,    10, -1425, -1425, -1425, -1425, -1425, 10587,  1160,
   16318,  1318,  6247,   -26, -1425, -1425,   -26, 10587, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425,  1319, -1425, -1425,  1146,  1162,
   16318, -1425, -1425, 10587,  7797, 16318,  1169, 10587,  1183,  1139,
   11517, -1425, 11517,  7797, -1425,  1241,  1155, 16318,  1216,  1326,
   16318,  1187, 11517, -1425
  };

  const unsigned short int
  xquery_parser::yydefact_[] =
  {
     165,   469,   470,   805,   471,   168,   168,   168,     0,   828,
    1028,   120,   122,   636,   921,   930,   870,   833,   831,   807,
     922,   925,   877,   837,   808,   810,     0,   931,   812,   928,
     899,   879,   853,   809,   874,   875,   926,   923,   873,   814,
     929,   815,   816,   970,   982,   969,   871,   890,   884,   817,
     872,   819,   818,   971,   908,   909,   876,   850,   992,   993,
     994,   995,   996,   997,   998,   999,  1000,  1001,  1002,  1016,
    1023,   898,   894,   885,   864,   806,     0,   893,   901,   910,
    1017,   889,   495,   865,   866,   924,  1018,  1024,   886,   903,
       0,   501,   458,   497,   896,   830,   887,   888,   917,   891,
     907,   916,  1022,  1025,   836,   878,   919,   496,   906,   912,
     811,     0,     0,     0,     0,   405,   904,   915,   920,   918,
     897,   883,   972,   881,   882,  1019,     0,   404,     0,  1020,
    1026,   913,   867,   892,  1021,   212,   436,     0,   468,   914,
     895,   902,   911,   905,   973,   858,   863,   862,   861,   860,
     859,   820,   880,     0,   829,   927,   851,   963,   962,   964,
     835,   834,   854,   961,   813,   958,   966,   960,   959,   857,
     900,   956,   968,   967,   955,   855,   965,   977,   978,   975,
     976,   974,   821,   979,   980,   981,   947,   946,   933,   849,
     842,   940,   936,   852,   848,   948,   869,   838,   839,   832,
     841,   945,   944,   941,   937,   953,   954,   952,   943,   939,
     932,   840,   951,   950,   844,   846,   845,   938,   942,   934,
     847,   935,   843,   949,  1003,  1004,  1005,  1006,  1007,  1008,
     984,   985,   983,   989,   990,   991,   986,   987,   988,   856,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,     0,     0,   822,
     957,  1027,   824,   823,   825,   826,   165,   165,     0,     2,
     165,     9,    11,    23,     0,    28,    31,    36,    37,    38,
      39,    40,    41,    42,    32,    58,    59,    33,    34,     0,
      76,    79,    80,    35,    81,    82,     0,   118,    83,    84,
      85,    86,    18,   162,   163,   164,   171,   174,   488,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   185,   186,
       0,   213,   221,   216,   249,   255,     0,   247,     0,   248,
     223,   217,   184,   218,   183,   219,   222,   356,   358,   360,
     370,   372,   376,   378,   381,   386,   389,   392,   394,   396,
     398,     0,   402,   409,   408,   410,     0,   427,   411,   432,
     435,   437,   440,   442,     0,   447,   444,     0,   455,   465,
     467,   441,   472,   479,   493,   480,   481,   482,   485,   486,
     483,   487,   510,   511,   484,   514,   516,   517,   518,   515,
     563,   564,   565,   566,   567,   568,   569,   464,   608,     0,
     599,   607,   606,   605,   604,   601,   603,   600,   602,   494,
      43,   224,   225,   227,   226,   228,   220,   490,   491,   492,
     489,   230,   233,   229,   231,   232,   466,   804,   827,   921,
     930,   928,   829,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   460,   463,
     450,     0,     0,   807,   837,   810,   868,   931,   812,   879,
     814,   890,   817,   819,   818,   908,  1016,  1023,   806,  1017,
     866,  1018,  1024,   891,  1022,  1025,   915,   972,  1019,  1020,
    1026,  1021,   973,   961,   958,   960,   959,   855,   977,   978,
     975,   821,   979,   957,   456,   804,   448,     0,   193,   449,
     452,   807,   808,   810,   809,   814,   815,   816,   817,   806,
     813,   498,     0,   454,   453,   188,     0,     0,   213,     0,
     812,   819,   818,     0,   168,   784,   979,     0,   221,     0,
     499,     0,   530,     0,     0,   459,     0,   430,   431,     0,
     462,   461,   451,   434,     0,     0,   559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   786,     0,   788,     0,     0,
     165,     3,     4,     1,    10,    12,     0,     0,     0,     0,
       6,   165,     0,   165,     0,     0,   119,   172,     0,     0,
     191,     0,     0,   200,     0,     0,     0,     0,     0,     0,
     236,     0,   205,   234,     0,   254,   250,   256,   251,   253,
     252,   259,     0,     0,     0,     0,     0,     0,     0,   421,
       0,     0,   419,     0,   365,     0,   420,   413,   418,   417,
     416,   415,   414,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   407,   406,   403,     0,   168,   428,   433,     0,
       0,     0,   443,   476,   446,   445,   457,     0,   473,     0,
       0,     0,   571,   573,   577,   579,     0,   124,     0,   803,
      47,    44,    45,    48,    49,     0,     0,     0,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   643,   644,   645,     0,   103,   142,     0,     0,   112,
       0,     0,     0,     0,   127,     0,     0,   616,     0,     0,
       0,   611,     0,     0,     0,   626,     0,     0,   258,   261,
       0,     0,   134,     0,   138,   168,   513,     0,    60,     0,
      69,     0,     0,     0,    61,     0,     0,     0,     0,   614,
       0,     0,   617,     0,     0,     0,     0,   327,     0,     0,
     615,     0,     0,     0,   634,     0,     0,     0,     0,   620,
       0,     0,   195,     0,     0,   189,   187,     0,     0,   790,
       0,     0,     0,   498,     0,   785,     0,   500,   531,   530,
     527,     0,     0,     0,   561,   560,   429,     0,   558,     0,
     656,   657,     0,     0,     0,     0,     0,   797,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   662,     0,
     203,   204,     0,     0,     0,     0,     0,   208,   209,   787,
     789,     0,     5,    24,     0,    25,     0,     7,    29,     0,
      15,     8,    30,     0,    19,   921,    77,    16,    78,    20,
     194,     0,   192,   214,   215,     0,     0,     0,     0,   296,
     206,   235,   237,   238,   257,     0,     0,   357,   359,   363,
     369,   368,   367,     0,   364,   361,   362,     0,   373,   380,
     379,   377,   383,   384,   385,   382,   387,   388,   391,   390,
       0,     0,     0,     0,   412,     0,   438,   439,     0,   477,
     506,   474,   508,     0,   609,   512,   504,     0,     0,   121,
     123,     0,     0,     0,   102,     0,    92,    94,    95,    96,
      97,    99,   100,   101,    93,    98,    88,    89,     0,     0,
     108,     0,   104,   106,   107,   114,     0,     0,    87,    46,
       0,     0,     0,     0,     0,     0,     0,   734,   739,     0,
       0,   735,   769,   722,   724,   725,   726,   728,   730,   729,
     727,   731,     0,     0,     0,     0,     0,   111,     0,   144,
       0,     0,   576,   570,   612,   613,     0,     0,   630,     0,
     627,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,     0,   135,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,   277,   283,   280,     0,   619,   618,   625,
     633,     0,     0,     0,     0,   575,     0,     0,     0,   422,
       0,     0,     0,     0,   623,     0,   621,     0,   196,     0,
       0,   791,     0,     0,     0,     0,   530,   528,     0,   519,
       0,     0,   502,   503,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,     0,     0,     0,   670,     0,
     210,     0,     0,     0,     0,   165,     0,   165,     0,   173,
     246,     0,   311,   307,   309,     0,   304,   297,   298,     0,
       0,   239,   240,     0,   245,   366,     0,     0,     0,     0,
     700,   374,   673,   677,   679,   681,   683,   686,   693,   694,
     702,   931,   811,     0,   820,   824,   823,   825,   826,   393,
     582,   588,   589,   592,   637,   638,   593,   594,   597,   395,
     397,   400,   598,   399,   426,   478,     0,   475,   505,   125,
      56,    57,    54,    55,   131,   130,     0,    90,     0,     0,
     109,   110,   115,    74,    75,    52,    53,    73,   740,     0,
     743,   770,     0,   733,   732,   737,   736,   768,     0,     0,
     745,     0,   741,   744,   723,     0,     0,     0,     0,     0,
       0,     0,   610,     0,     0,     0,   143,   146,   148,     0,
       0,     0,   113,   116,     0,     0,     0,   168,     0,     0,
     634,     0,     0,     0,   263,     0,   581,     0,   264,     0,
       0,     0,     0,     0,     0,     0,   141,   136,   139,     0,
     190,     0,     0,    71,    65,    68,    67,     0,    63,   281,
       0,     0,   168,     0,   325,   329,     0,     0,     0,   332,
       0,     0,   338,     0,     0,   345,     0,   349,     0,   424,
     423,   168,     0,     0,   197,     0,   199,   326,     0,     0,
       0,     0,   531,     0,   521,     0,   554,   551,     0,   555,
     556,     0,     0,   550,     0,   525,   553,   552,     0,     0,
       0,     0,   649,   650,   646,     0,     0,   654,   655,   651,
     793,   794,   660,   798,   658,     0,     0,     0,     0,   664,
     812,   819,   818,   979,   202,     0,     0,     0,   665,   666,
       0,     0,   211,   796,    26,     0,    17,    21,    22,   308,
     320,     0,   321,     0,   312,   313,   314,   315,     0,   498,
       0,   305,     0,     0,     0,   241,     0,     0,     0,     0,
     290,     0,   287,   292,   244,     0,     0,   684,   697,     0,
     371,   375,     0,   716,     0,     0,     0,     0,     0,     0,
     672,   674,   675,   711,   712,   713,   715,   714,     0,     0,
     688,   687,     0,   691,   695,   709,   707,   706,   699,   703,
       0,     0,     0,     0,     0,     0,     0,     0,   585,   587,
     586,   583,   401,   507,   509,   133,   132,    91,   105,   757,
     738,     0,   762,     0,   762,   751,   746,   147,   149,     0,
       0,     0,   117,   145,     0,    27,     0,   631,   632,   635,
     628,   629,   262,     0,     0,   276,   268,     0,   272,     0,
     266,     0,     0,     0,   137,     0,     0,    70,     0,    64,
     282,     0,     0,   328,   330,   335,     0,   333,     0,     0,
       0,     0,     0,   339,     0,     0,   353,     0,     0,   346,
       0,     0,   350,   425,     0,   624,   622,   198,   792,     0,
       0,   530,     0,     0,   562,     0,   530,     0,   526,     0,
      14,     0,     0,     0,     0,     0,     0,     0,   663,     0,
       0,     0,     0,     0,     0,   667,   671,   324,   322,   323,
     316,   317,   318,   310,     0,     0,   306,   299,   285,     0,
       0,     0,   243,   288,   291,     0,   701,   692,   698,     0,
       0,   771,   772,   782,   781,   780,     0,     0,     0,     0,
     773,   678,   779,     0,   676,   680,     0,     0,   685,   689,
       0,   710,   705,   708,   704,     0,     0,   595,     0,   590,
     642,   584,   802,   801,   800,   591,   758,     0,     0,   756,
     763,   764,   760,     0,   755,     0,   753,     0,     0,     0,
       0,     0,     0,   572,   265,     0,   274,     0,     0,   270,
       0,   273,     0,     0,     0,    66,   284,   578,     0,     0,
     336,   340,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,     0,     0,   530,     0,
     557,     0,   530,   580,   647,   648,   652,   653,     0,   659,
     799,   661,     0,     0,     0,     0,   668,   319,   300,     0,
     286,   294,   295,   289,   242,   696,   783,     0,     0,   775,
       0,   721,   720,   719,   718,   717,   682,     0,   774,     0,
     639,     0,     0,   767,   766,   765,     0,   759,   752,   750,
       0,   747,   748,   742,   150,   152,   154,     0,     0,     0,
       0,     0,   269,   267,     0,   275,   207,   355,    72,   331,
     337,     0,   354,   351,   347,     0,     0,     0,   341,     0,
       0,   343,     0,   540,   534,   529,     0,   530,   520,     0,
     795,     0,     0,     0,     0,   303,   301,     0,   777,   776,
       0,     0,   640,   596,     0,   761,   754,     0,     0,   156,
     155,     0,     0,     0,     0,   151,   271,     0,     0,     0,
       0,     0,   548,   542,     0,   541,   543,   549,   546,   536,
       0,   535,   537,   547,   522,     0,   523,     0,     0,   669,
     302,     0,   778,   690,   641,   749,   153,   157,     0,     0,
       0,     0,     0,     0,   344,   342,     0,     0,   533,   544,
     545,   532,   538,   539,   524,     0,   293,   158,     0,     0,
       0,   352,   348,     0,     0,     0,     0,     0,     0,     0,
       0,   160,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,   161
  };

  const short int
  xquery_parser::yypgoto_[] =
  {
   -1425, -1425,  -188,  -176, -1425,  1204,  1214, -1425,  1180,  -552,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
    -992, -1425, -1425, -1425, -1425,  -219,  -578, -1425,   707,   -40,
   -1425, -1425, -1425, -1425, -1425,   257,   477, -1425, -1425,    11,
    -173,  1023, -1425,  1019, -1425, -1425,  -641, -1425,   424, -1425,
     224, -1425,  -254,  -282, -1425,  -563, -1425,     4,    12,    28,
    -223,  -181, -1425,  -880, -1425, -1425,  -240, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425,   611, -1425,   -59,
    1357,     0, -1425, -1425,  -315, -1425, -1425,   347, -1425, -1425,
    -301, -1425,    16, -1425, -1425,   828,  -934,  -742,  -718, -1425,
   -1425,   704, -1425, -1425,   -70,   105, -1425, -1425, -1425,   122,
   -1068, -1425,   363,   127, -1425, -1425,   133, -1299, -1425,   948,
     226, -1425, -1425,   218, -1014, -1425, -1425,   220, -1425, -1425,
   -1260, -1255, -1425,   217, -1422, -1425, -1425,   848,   851, -1425,
    -527,   829, -1425, -1425,  -665,   328,  -643,   323,   329, -1425,
   -1425, -1425,   576, -1425, -1425,  1182, -1425, -1425, -1425, -1425,
   -1425,  -886,  -319,  -682, -1425,   -66, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425,   -13,  -819, -1425,  -539,  -195,   275, -1425,
    -427, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   799, -1425,
   -1425, -1425, -1425, -1001, -1425,   206, -1425,   684,  -797, -1425,
   -1425, -1425, -1425, -1425,  -266,  -259, -1212,  -919, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,  -755,
    -832,  -210,  -825, -1425, -1425, -1425,  -759, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425,  1067,  1070,  -192,   498,
     330, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,
   -1425, -1425,   183, -1425, -1425,   171, -1425,   174, -1072, -1425,
   -1425, -1425,   128,   114,   -52,   389, -1425, -1425, -1425, -1425,
   -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425, -1425,   130,
   -1425, -1425, -1425,   -45,   383,   530, -1425, -1425, -1425, -1425,
   -1425,   326, -1425, -1425, -1424, -1425, -1425, -1425,  -577, -1425,
      94, -1425,   -61, -1425, -1425, -1425, -1425, -1322, -1425,   142,
   -1425, -1425, -1425, -1425, -1425,   949, -1425, -1425, -1425, -1425,
   -1425,  -929,  -383,   914,   -64, -1425
  };

  const short int
  xquery_parser::yydefgoto_[] =
  {
      -1,   258,   632,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
    1263,   783,   276,   277,   278,   279,   280,   281,   966,   967,
     968,   282,   283,   284,   972,   973,   974,   285,   450,   286,
     287,   716,   288,   452,   453,   454,   464,   773,   774,   289,
    1226,   290,  1704,  1705,   291,   292,   293,   556,   294,   295,
     296,   297,   298,   776,   299,   300,   538,   301,   302,   303,
     304,   305,   306,   642,   307,   308,   867,   868,   309,   310,
     311,   568,   313,   643,  1641,   655,  1133,  1134,   314,   645,
     315,   647,   569,   317,   318,   768,   769,  1380,   471,   319,
     472,   473,   906,  1381,  1382,  1383,   648,   649,  1127,  1128,
    1371,   650,  1123,  1124,  1364,  1365,  1366,  1367,   320,   796,
     797,   321,  1278,  1279,  1488,   322,  1281,  1282,   323,   324,
    1284,  1285,  1286,  1287,  1495,   325,   326,   327,   328,   913,
     329,   330,  1390,   331,   332,   333,   334,   335,   336,   337,
     338,   339,  1170,   340,   341,   342,   343,   673,   674,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   708,   703,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   943,   371,
     372,   373,   374,   375,   376,  1314,   829,   830,   831,  1735,
    1780,  1781,  1774,  1775,  1782,  1776,  1315,  1316,   377,   378,
    1317,   379,   380,   381,   382,   383,   384,   385,   386,  1028,
    1496,  1431,  1160,  1588,  1161,  1171,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   803,  1239,
     399,  1163,  1164,  1165,  1166,   400,   401,   402,   403,   404,
     405,   857,   858,   406,  1348,  1349,  1666,  1109,  1141,  1400,
    1401,  1142,  1143,  1144,  1145,  1146,  1410,  1578,  1579,  1147,
    1413,  1148,  1559,  1149,  1150,  1418,  1419,  1584,  1582,  1402,
    1403,  1404,  1405,  1684,   745,   993,   994,   995,   996,   997,
     998,  1212,  1608,  1701,  1213,  1606,  1699,   999,  1444,  1603,
    1599,  1600,  1601,  1000,  1001,  1406,  1414,  1569,  1407,  1565,
    1391,   407,   408,   409,   410,   559,   411,   412,   413,   414,
     415,  1167,  1264,   416,   417,   418
  };

  const short int
  xquery_parser::yytable_[] =
  {
     312,   644,   604,   717,   717,   312,   312,   312,   312,   423,
     426,   427,   535,   934,   921,   646,   316,   424,   424,   424,
     428,   316,   316,   316,   316,   451,   535,   697,  1026,  1499,
    1042,  1139,  1078,   425,   425,   425,   429,   922,   923,   924,
     925,  1510,  1280,  1054,   619,   886,   888,  1108,  1268,   720,
     535,   847,  1027,   567,   571,   620,   854,  1068,   880,   884,
     887,   889,   535,   534,   535,  1386,  1541,  1542,   620,   878,
     882,   583,   627,  1185,  1228,  1639,   622,   620,  1643,  1313,
     611,   612,  1022,  1215,   780,   784,   953,  1244,  1216,   759,
    1580,   624,    11,    12,  1707,  1252,   620,  1217,  1159,  1169,
     771,    13,  1518,   620,  1218,   620,  1219,   760,   585,    11,
      12,   312,   436,   626,  1677,  1220,  1306,  1307,   620,  1130,
     834,   818,   437,   424,   594,  1099,   620,   316,  1249,   436,
     620,   909,   620,   910,   911,  1101,   912,   620,   914,   557,
     439,  1023,  1221,  1024,  1189,   440,   915,   916,  1640,  1209,
    1732,   620,   620,   588,  1597,   589,  1024,   439,   702,  1428,
     640,   705,   631,   620,  1561,   719,  1210,   881,   772,   677,
     620,  1162,  1162,   686,   591,   631,   592,   441,   442,  1118,
    -169,   620,    82,  1702,  1636,   759,   678,   687,   606,   608,
    1429,  1246,  1678,   620,  1025,   751,    93,   469,  1257,  1114,
    1708,  1562,   627,   760,  -170,   620,   627,  1253,  1430,  1211,
    1162,  1308,   719,   595,  1100,   640,   620,   640,  1598,   455,
    1192,   107,   620,  1270,   620,  1136,   432,   433,  1137,   434,
     435,  1309,   620,  1310,  1471,   620,   628,   631,   620,   631,
     620,  1667,   590,   982,  1227,   983,  1095,   438,   128,   781,
     620,  1139,  1139,   470,   826,  1499,   312,   312,   631,   631,
     312,  1311,  1102,   593,  1162,   114,   621,  1492,   646,  1222,
     631,  1162,   316,   316,  1256,  1479,   316,   631,   626,  1303,
    1131,   126,  1709,   698,  1700,   623,  1254,   835,   631,   984,
     535,   586,   873,   535,   875,   312,   782,   886,   888,  1767,
     631,  1518,  1312,  1355,  1313,  1228,  1436,  1115,  1250,  1462,
    1255,   316,   631,  1313,  1186,  1117,  1558,  1132,   827,   470,
     153,   878,   882,   631,  1271,  1086,  1354,   761,  1422,   631,
    1138,   631,   470,  1795,   627,   620,   620,  1034,  1056,   631,
     620,   704,   631,   779,   706,   631,  1803,   631,  1806,  1057,
     444,   470,   447,   470,   430,   979,  1105,   631,  1051,   470,
     448,  1223,  1224,  1225,  -169,   616,   628,   870,   449,   752,
     628,  1051,   727,   535,  1374,   620,   535,   753,   869,  1299,
     535,   617,  1090,   535,   535,   890,  1135,   620,  -170,   892,
    1392,   535,  1733,   735,  1162,   736,   817,   535,   535,  1016,
    1039,   764,   879,   883,  1392,   535,   777,  1759,  1300,   445,
    1301,   818,   535,   535,   535,   535,   790,   431,  1741,   825,
     535,   900,  1175,   801,   802,   312,  1742,  1474,   535,   312,
     874,   876,   808,   620,   872,   620,  1743,  1566,  1052,   985,
     891,   316,   631,   631,  1489,   316,   458,   631,  1087,  1088,
     446,  1070,   986,  1772,   987,   738,   312,  1306,   312,   629,
     620,  1797,  1393,  1089,   620,   988,   989,   990,   756,   991,
     758,   992,   316,   535,   316,  1227,  1393,   948,  1452,  1024,
     312,  1734,   631,  1788,   429,   312,   429,   819,   535,   948,
    1140,   479,   799,   701,   631,   707,   316,   805,   628,   535,
    1162,   316,  1139,  1464,   484,  1091,  1092,  1094,   429,    11,
      12,  1139,  1313,   429,   832,   833,   739,   459,  1046,  1062,
    1093,  1179,  1139,  1081,  1162,   837,   848,  1017,  1108,   640,
    1463,   848,  1536,  1499,   535,   651,  1472,   886,   888,   886,
     631,   630,   631,   863,   865,  1394,  1395,  1449,  1396,  1306,
    1277,  1019,  1356,  1357,  1358,  1397,   949,   312,  1082,  1394,
    1395,  1336,  1396,  1486,   312,  1398,   677,   631,   950,  1778,
    1083,   631,  1309,   316,  1310,  1527,   424,  1399,    13,  1398,
     316,   485,  1773,   678,  1306,  1307,  1031,  1306,  1587,  1079,
     535,  1399,   425,  1193,  1194,   625,  1567,  1568,  1197,   652,
    1745,  1063,  1311,   312,   653,  1304,  1018,  1778,  1306,  1307,
     312,  1084,  1097,  1065,  1545,   596,  1107,  1441,  1556,   316,
     597,   312,   312,   312,   312,  1772,   316,   451,  1236,  1306,
    1020,   864,  1718,   936,   937,  1306,  1307,   316,   316,   316,
     316,   627,   938,  1789,   312,   749,   725,  1793,   486,   487,
     750,   654,  1176,  1350,  1112,  1080,   488,  1176,  1691,    82,
     316,  1162,   726,  1696,  1309,  1032,  1310,   955,  1119,  1085,
     535,  1305,   701,    93,   707,  1779,  1681,  1443,  1790,  1308,
    1064,  1184,   696,  1682,   535,   735,   463,   736,   535,   535,
    1139,  1116,  1066,  1683,  1311,   876,   312,   775,   107,  1309,
     935,  1310,  1309,  1308,  1310,   128,   680,   535,   424,  1351,
    1140,  1140,   316,  1812,  1647,   535,  1023,   634,   535,  1651,
     737,   635,   535,  1309,   425,  1310,   636,  1618,  1492,  1311,
    1308,  1177,  1311,   114,  1573,   681,  1178,  1692,  1162,  1441,
    1665,  1162,  1697,  1388,  1309,   637,  1310,   738,   682,   126,
    1309,  1180,  1310,  1311,  1809,  1182,  1442,   114,   462,  1024,
    -260,  1073,  1074,  1075,   535,   865,   128,  1181,    13,  1053,
    1512,  1183,  1612,   126,  1311,   312,   886,  1023,   729,  1033,
    1311,   970,   683,   489,   114,  1376,   971,   424,   153,   969,
    1377,   316,  1023,  1376,  1517,  1361,  1351,  1023,  1377,  1443,
     126,   465,   535,   425,  1722,  1106,   312,   312,   739,  1378,
    1617,   730,   153,   490,  1777,  1783,  1363,  1023,  1060,  1061,
     697,  1649,   316,   316,  -260,  1238,   881,  1241,  1024,  -260,
    1373,   535,   970,   684,   429,   429,  1024,   971,  1435,   153,
    1041,   535,   685,   638,   491,  1067,   639,   492,   474,    82,
    1379,  1736,   477,  1681,   775,  1739,  1777,  1752,  1113,  1753,
    1682,   640,  1783,    93,   312,  1544,   535,   535,   535,   535,
    1683,  1292,   677,  1293,   617,   466,  -260,  1162,  1023,  1477,
     316,  1209,  1344,   677,   467,  1415,  1416,   641,   107,   678,
    1361,   312,  1136,  1360,   478,  1137,   451,  1277,  1210,   721,
     678,  1376,  1679,  1680,  1361,   535,  1377,   316,  1417,  1563,
    1491,   468,   679,   722,  1362,   128,  1564,  1676,   891,   535,
    1497,  1500,  1794,  1750,   876,  1363,  1187,  1706,  1352,   723,
    1162,   710,  1162,  1498,  1501,  1497,  1497,   482,  1187,  1203,
    1785,  1205,   711,   724,   535,  1230,   699,   700,  1646,  1815,
    1204,  1760,  1206,   535,  1231,   535,   701,   535,   707,   535,
     456,  1140,  1162,   457,   460,  1490,   535,   461,   475,   480,
    1140,   476,   481,  1198,  1199,  1200,   536,   939,  1537,  1201,
     939,  1140,   537,   939,   741,   742,   743,  1546,  1320,   483,
    1321,  1325,   539,  1326,   540,  1162,  1195,  1196,   552,   535,
     553,   535,  1538,  1539,   551,   919,   920,   926,   927,  1162,
     554,  1162,  1748,  1749,   573,   928,   929,  1447,  1448,   574,
    1693,  1694,   575,  1529,   580,   581,   582,   587,   572,  1706,
     584,  1533,  -610,   599,   598,   600,   848,   601,  1475,   602,
     576,   609,   579,   603,   613,   646,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   633,   656,   312,   657,
     676,   535,   675,   688,   689,   690,   701,   691,   712,   709,
    1288,   695,   713,   719,   316,   714,  1706,  1385,   715,   731,
     733,   734,   744,   658,   757,  1792,   429,   775,   778,   535,
     748,   659,   660,   786,   661,  1625,   787,   788,   806,   807,
     789,   813,   662,   800,   457,  1345,   663,   815,   664,   461,
     817,   476,   481,   665,   492,   312,   312,   312,   820,   828,
     836,  1346,   824,   838,   821,   451,   822,   839,   860,   666,
     861,   316,   316,   316,   877,   856,   895,   866,   896,   902,
     903,   897,   898,   905,   917,   931,   932,   933,  1834,  1140,
    1835,   930,   945,   667,   668,   669,   670,   671,   672,   954,
    1843,   951,   604,   944,   952,   976,   977,   980,   981,  1003,
    1002,  1628,  1006,  1629,  1008,  1011,  1633,  1634,  1012,   535,
    1637,  1013,  1004,   535,  1021,  1014,  1644,  1015,  1030,  1036,
    1037,  1040,  1055,  1047,  1048,   535,  1049,  1050,  1059,  1058,
     456,   460,   475,   480,  1096,  1103,  1104,  1114,   491,   535,
    1098,  1111,  1174,  1188,   971,  1023,  1207,  1208,  1229,   535,
    1234,  1235,  1237,  1245,  1247,  1251,   771,  1121,  1259,  1261,
    1265,  1262,  1266,  1267,  1273,  1272,  1276,   312,  1277,  1283,
    1291,  1456,  1260,  1289,  1290,  1295,  1298,  1302,   535,   424,
    1318,  1296,  1319,   316,  1337,   737,  1347,  1368,  1370,  1408,
    1372,   312,  1389,  1409,  1432,   425,  1375,  1631,  1420,  1421,
    1423,  1424,   312,   535,  1425,  1426,  1482,   316,  1427,    13,
    1440,  1439,  1412,   535,   424,  1445,  1450,   535,   316,  1451,
    1454,   312,  1459,  1457,  1455,  1504,  1467,  1458,  1469,  1478,
     425,  1473,  1481,   424,  1497,  1511,  1509,   316,  1514,  1460,
     900,   312,  1503,  1461,  1505,   535,  1521,  1506,   312,   425,
    1525,  1530,  1520,  1515,  1726,   640,  1526,   316,  1730,  1549,
    1519,  1350,  1361,  1522,   316,  1531,  1532,  1550,  1551,   429,
    1555,  1557,  1576,  1583,  1589,  1590,   429,  1577,  1591,  1523,
    1345,   728,  1581,  1592,   732,  1593,   535,  1596,   740,  1602,
    1594,   746,   747,  1595,  1607,  1609,  1346,  1524,  1613,   755,
    1622,  1623,  1605,  1560,  1615,   767,   770,  1620,   864,  1624,
    1627,  1645,  1650,   785,  1653,  1669,   535,  1687,  1658,  1675,
     793,   794,   795,   798,  1570,  1689,  1690,  1611,   804,  1716,
    1698,  1209,  1703,  1721,  1711,  1714,   811,  1738,  1747,  1754,
    1720,  1631,  1769,  1755,  1723,  1756,  1762,  1757,  1758,  1768,
    1770,  1731,  1688,  1811,  1763,  1784,  1791,  1786,  1710,  1787,
     535,  1800,  1801,   535,  1808,  1814,   535,  1820,  1825,  1826,
    1836,  1839,  1837,   618,   978,  1840,  1438,  1190,   535,    11,
      12,   812,  1802,   535,   718,  1258,  1807,  1765,  1453,   432,
     433,  1798,   434,   435,   614,  1818,   798,  1827,   558,   436,
     754,  1662,  1663,  1664,   615,  1830,  1796,   823,  1110,   437,
     438,  1384,   904,  1673,  1359,  1554,   535,   535,  1823,  1832,
     312,  1824,  1045,  1842,  1547,  1543,  1487,   439,  1540,  1483,
     814,  1493,   440,  1502,   907,   918,   316,  1723,   908,  1173,
     947,  1513,   859,  1077,  1833,  1813,  1810,  1242,  1437,  1535,
    1528,  1534,  1575,   694,  1686,  1571,   762,  1387,  1685,   763,
    1411,  1574,  1214,  1345,   441,   442,   443,  1446,  1604,  1695,
    1572,     0,   852,     0,     0,     0,  1804,     0,     0,  1346,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1475,     0,     0,     0,   770,     0,
       0,     0,   535,     0,   535,     0,   535,     0,   535,  1821,
       0,     0,     0,   444,     0,   535,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1821,     0,     0,     0,     0,  1744,     0,     0,     0,
    1804,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1345,     0,     0,   535,     0,   535,  1751,     0,
       0,     0,     0,  1345,  1345,     0,     0,   312,  1346,     0,
       0,     0,   445,   535,  1345,     0,   535,     0,   975,  1346,
    1346,     0,     0,   316,     0,     0,     0,   535,     0,     0,
    1346,     0,  1005,     0,     0,     0,  1009,  1010,   535,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   446,     0,  1029,     0,     0,     0,     0,
     535,     0,     0,  1035,     0,     0,  1038,     0,   535,     0,
    1043,     0,     0,     0,   535,     0,   535,     0,     0,   447,
       0,     0,     0,     0,     0,     0,     0,   448,     0,     0,
       0,     0,     0,     0,     0,   449,     0,   535,     0,     0,
    1345,     0,     0,     0,     0,     0,   535,     0,     0,     0,
       0,     0,  1076,     0,     0,     0,  1346,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   535,     0,     0,     0,
       0,   535,     0,     0,     0,     0,     0,     0,     0,   312,
       0,     0,     0,   535,     0,     0,   535,     0,     0,     0,
       0,     0,     0,     0,     0,   316,     0,  1345,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   312,  1346,     0,     0,     0,     0,     0,  1120,
       0,     0,     0,     0,     0,     0,     0,     0,   316,  1129,
       0,     0,     0,     0,  1345,     0,     0,     0,     0,     0,
       0,     0,     0,  1345,     0,     0,     0,     0,     0,     0,
    1346,     0,     0,     0,  1168,  1168,  1172,  1172,     0,  1346,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   558,  1233,     0,     0,     0,     0,     0,     0,     0,
       0,  1240,     0,  1240,     0,   770,     0,  1168,     0,     0,
       0,     0,     0,     0,  1168,   840,   841,     0,   849,   850,
     851,   853,     0,   855,     0,     0,     0,     0,   862,     0,
       0,     0,     0,     0,     0,     0,   871,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   804,     0,   804,
       0,     0,     0,     0,     0,     0,     0,     0,   893,   894,
       0,     0,     0,     0,     0,     0,     0,     0,   899,     0,
       0,   901,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   942,     0,     0,  1168,   942,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1007,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1044,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   770,     0,     0,
       0,  1465,     0,     0,     0,     0,     0,     0,     0,     0,
    1069,     0,     0,  1168,  1071,  1072,     0,     0,     0,     0,
       0,     0,     0,   901,     0,     0,     0,   798,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   894,     0,
       0,   859,     0,     0,  1122,  1126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1553,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1191,     0,
       0,     0,     0,     0,  1168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1232,  1610,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1269,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1635,  1274,
    1275,  1168,     0,     0,  1168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1294,     0,  1648,  1297,     0,     0,
       0,  1652,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1322,  1323,  1324,     0,  1327,  1328,
    1329,  1330,  1331,  1332,  1333,  1334,  1335,     0,     0,  1338,
    1339,     0,     0,     0,  1671,  1672,     0,     0,  1353,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1434,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1168,     0,  1725,     0,  1727,     0,  1729,     0,     0,     0,
       0,     0,     0,  1737,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1168,     0,  1168,  1466,     0,  1468,     0,
    1470,     0,     0,     0,     0,     0,     0,     0,  1476,     0,
       0,  1761,     0,     0,  1764,     0,     0,  1480,     0,     0,
       0,     0,     0,  1484,  1485,  1168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1771,     0,     0,     0,
       0,     0,  1507,     0,     0,  1508,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1168,     0,
       0,     0,     0,     0,     0,     0,  1799,     0,     0,     0,
       0,     0,  1168,     0,  1168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1816,     0,     0,     0,     0,
       0,     0,     0,     0,  1819,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1122,     0,     0,     0,  1126,
    1548,     0,     0,     0,  1828,  1552,     0,     0,     0,  1829,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1838,     0,     0,  1841,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1614,     0,     0,     0,  1616,     0,     0,     0,  1619,     0,
    1621,     0,     0,     0,     0,     0,     0,     0,  1626,     0,
       0,     0,     0,     0,     0,     0,  1630,  1632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1476,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1654,  1655,
    1656,  1657,     0,  1659,  1660,     0,  1661,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1668,     0,     0,     0,     0,  1670,     0,     0,     0,
       0,     0,  1674,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1712,     0,  1713,     0,     0,  1715,     0,     0,
    1717,     0,     0,     0,     0,  1719,  1632,     0,     0,     0,
       0,     0,     0,     0,  1724,     0,     0,     0,  1728,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1740,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1746,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1766,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1724,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1805,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -165,
     881,     0,     0,     0,     0,  1817,     0,     0,     0,  1822,
       1,     2,     0,     0,  1805,     3,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
    1822,     0,    14,   420,  1831,    16,    17,    18,    19,    20,
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
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   137,     0,   138,     0,   139,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
     151,   152,   153,     0,   422,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
       0,   248,     0,   249,   250,   251,   252,   253,   254,   255,
    -165,   881,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   885,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   421,
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
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   881,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   421,
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
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   881,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   419,   420,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   560,   421,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   561,   562,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   510,    85,    86,    87,    88,    89,   563,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   564,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   528,   529,
     530,   180,   181,   531,   566,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,  -868,   462,     0,  -260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -868,     0,     0,     0,  -868,     0,     0,
       0,  -868,  -868,     0,     0,     0,     0,  -868,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -260,     0,
       0,  -868,     0,  -260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -868,     0,  -868,  -868,  -868,     0,
       0,  -868,  -868,  -868,  -868,     0,     0,     0,  -868,  -868,
       0,     0,     0,     0,     0,  -868,     0,     0,  -868,  -868,
    -260,     0,     0,  -868,     0,     0,     0,     0,  -868,  -868,
       0,     0,     0,     0,  -868,     0,     0,     0,  -868,     0,
       0,     0,  -868,  -868,     0,  -868,     0,  -868,  -868,     0,
       0,     0,  -868,  -868,     0,     0,  -868,  -868,  -868,  -868,
    -868,  -868,     0,     0,  -868,     0,     0,     0,  -868,  -868,
       0,     0,  -868,     0,     0,     0,     0,  -868,     0,     0,
    -868,     0,     0,     0,     0,  -868,  -868,  -868,  -868,  -868,
       0,  -868,  -868,  -868,  -868,  -868,     0,     0,     0,     0,
    -868,  -868,  -868,     0,  -868,  -868,  -868,  -868,  -868,  -868,
       0,  -868,     0,  -868,     0,     0,     0,     0,  -868,  -868,
    -868,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -868,     0,  -868,     0,  -868,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -868,     0,     0,     0,     0,  -868,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,  -868,    13,  -868,     0,    14,    15,     0,    16,
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
       0,   133,   134,   135,   136,   137,     0,   138,     0,   139,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,     0,   248,     0,   249,   250,   251,
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
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     0,   610,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   421,    30,    31,    32,
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
       0,   555,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   421,    30,    31,    32,
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
       0,   816,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,  1340,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
    1341,  1342,    53,    54,    55,    56,    57,    58,    59,    60,
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
       0,   555,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,  1343,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   421,    30,    31,    32,
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
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
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
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
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
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
      14,   420,     0,    16,    17,    18,    19,    20,    21,    22,
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
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     885,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   421,    30,    31,    32,
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
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,  1340,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
    1341,  1342,    53,    54,    55,    56,    57,    58,    59,    60,
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
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,  1343,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   940,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   941,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   940,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   946,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,   565,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,   570,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   605,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
     607,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,  1433,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   692,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   693,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   560,   421,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     561,   562,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,  1125,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   528,   529,   530,   180,   181,
     531,   566,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   564,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,     0,     0,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     419,   420,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   496,    27,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,    49,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     510,    85,    86,    87,    88,    89,   563,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,     0,   109,
     110,   564,   112,     0,   113,   114,     0,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,     0,     0,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,     0,     0,
       0,   138,     0,   139,     0,   140,     0,   142,     0,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     0,     0,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
     419,   420,     0,    16,    17,    18,   493,    20,    21,    22,
     494,    24,   495,   496,   497,   498,   421,    30,   499,    32,
      33,    34,     0,    35,    36,    37,    38,   500,    40,    41,
      42,    43,    44,    45,    46,   501,     0,    48,   502,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   506,   507,
      71,     0,    72,    73,    74,   508,     0,     0,    77,    78,
      79,     0,     0,   509,    81,     0,     0,     0,     0,    83,
     510,    85,   511,   512,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   514,   515,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   516,     0,
       0,     0,   118,   119,   120,   121,   517,   123,   124,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   131,
       0,     0,     0,   132,     0,   133,   521,     0,     0,     0,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   522,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
       0,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   164,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,     0,     0,
       0,   249,   533,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     0,     0,
       0,     0,     9,    10,     0,     0,     0,     0,     0,     0,
     419,   420,     0,    16,    17,    18,   541,    20,    21,    22,
     494,   542,   543,   496,   497,   498,   421,    30,   499,    32,
     544,    34,     0,    35,    36,    37,    38,   545,    40,   546,
     547,    43,    44,    45,    46,   501,     0,    48,   548,    50,
     503,   504,    53,   505,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   506,   507,
      71,     0,    72,    73,    74,   549,     0,     0,    77,    78,
      79,     0,     0,   509,    81,     0,     0,     0,     0,    83,
     510,    85,   511,   512,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   513,   100,   101,   514,   515,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   516,     0,
       0,     0,   118,   119,   120,   121,   517,   123,   124,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   131,
       0,     0,     0,   132,     0,   133,   521,     0,     0,     0,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   522,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
       0,     0,   422,   155,   156,   157,   158,   159,   160,   161,
     162,   523,   550,   524,   166,   525,   526,   169,   170,   171,
     172,   173,   174,   527,   176,   528,   529,   530,   180,   181,
     531,   532,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,     0,     3,
       0,   249,   533,   251,   252,   253,   254,   255,     9,    10,
       0,     0,     0,     0,     0,     0,   419,   420,     0,    16,
      17,    18,   493,    20,    21,    22,   494,    24,   495,   496,
    1151,   498,   421,    30,   499,    32,    33,    34,     0,    35,
      36,    37,    38,   500,    40,    41,    42,    43,    44,    45,
      46,   501,     0,    48,   502,    50,   503,   504,    53,   505,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   506,   507,    71,     0,    72,    73,
      74,   508,     0,     0,    77,    78,    79,     0,     0,   509,
      81,     0,     0,     0,     0,    83,   510,    85,   511,   512,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   513,
     100,   101,   514,   515,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1152,     0,     0,     0,
    1153,     0,     0,   116,   516,     0,     0,     0,   118,   119,
     120,   121,   517,   123,   124,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   131,     0,     0,     0,   132,
    1585,   133,   521,     0,     0,     0,     0,  1586,     0,   139,
       0,   140,   141,   142,   143,   522,   145,   146,   147,   148,
     149,   150,     0,     0,  1154,   152,     0,     0,   422,   155,
     156,   157,   158,   159,   160,   161,   162,   523,   164,   524,
     166,   525,   526,   169,   170,   171,   172,   173,   174,   527,
     176,   528,   529,   530,   180,   181,   531,   532,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,     0,   249,   533,   251,
    1155,  1156,  1157,  1158,     3,     0,   577,   578,     0,     0,
       0,     0,     0,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   541,    20,    21,
      22,   494,   542,   543,   496,   497,   498,   421,    30,   499,
      32,   544,    34,     0,    35,    36,    37,    38,   545,    40,
     546,   547,    43,    44,    45,    46,   501,     0,    48,   548,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   549,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   516,
       0,     0,     0,   118,   119,   120,   121,   517,   123,   124,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,     0,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     522,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,     0,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,   550,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,   531,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       3,     0,   249,   533,   251,   252,   253,   254,   255,     9,
      10,     0,     0,     0,     0,     0,     0,   419,   420,     0,
      16,    17,    18,   541,    20,    21,    22,   494,   542,   543,
     496,   497,   498,   421,    30,   499,    32,   544,    34,     0,
      35,    36,    37,    38,   545,    40,   546,   547,    43,    44,
      45,    46,   501,     0,    48,   548,    50,   503,   504,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,   549,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,     0,    83,   510,    85,   511,
     512,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,   116,   516,     0,     0,     0,   118,
     119,   120,   121,   517,   123,   124,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   131,     0,     0,     0,
     132,   765,   133,   521,     0,     0,     0,     0,   766,     0,
     139,     0,   140,   141,   142,   143,   522,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,     0,     0,   422,
     155,   156,   157,   158,   159,   160,   161,   162,   523,   550,
     524,   166,   525,   526,   169,   170,   171,   172,   173,   174,
     527,   176,   528,   529,   530,   180,   181,   531,   532,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     3,     0,   249,   533,
     251,   252,   253,   254,   255,     9,    10,     0,     0,     0,
     791,     0,     0,   419,   420,     0,    16,    17,    18,   541,
      20,    21,    22,   494,   542,   543,   496,   497,   498,   421,
      30,   499,    32,   544,    34,     0,    35,    36,    37,    38,
     545,    40,   546,   547,    43,    44,    45,    46,   501,     0,
      48,   548,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   549,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,     0,    83,   510,    85,   511,   512,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   516,     0,     0,     0,   118,   119,   120,   121,   517,
     123,   124,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   131,     0,     0,     0,   132,   792,   133,   521,
       0,     0,     0,     0,     0,     0,   139,     0,   140,   141,
     142,   143,   522,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,     0,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   523,   550,   524,   166,   525,   526,
     169,   170,   171,   172,   173,   174,   527,   176,   528,   529,
     530,   180,   181,   531,   532,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     3,     0,   249,   533,   251,   252,   253,   254,
     255,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   541,    20,    21,    22,   494,
     542,   543,   496,   497,   498,   421,    30,   499,    32,   544,
      34,     0,    35,    36,    37,    38,   545,    40,   546,   547,
      43,    44,    45,    46,   501,     0,    48,   548,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   549,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   516,     0,     0,
       0,   118,   119,   120,   121,   517,   123,   124,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,   809,   133,   521,     0,     0,     0,     0,
     810,     0,   139,     0,   140,   141,   142,   143,   522,   145,
     146,   147,   148,   149,   150,     0,     0,   151,   152,     0,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,   550,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,   531,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     3,     0,
     249,   533,   251,   252,   253,   254,   255,     9,    10,     0,
       0,     0,     0,     0,     0,   419,   420,     0,    16,    17,
      18,   493,    20,    21,    22,   494,    24,   495,   496,  1151,
     498,   421,    30,   499,    32,    33,    34,     0,    35,    36,
      37,    38,   500,    40,    41,    42,    43,    44,    45,    46,
     501,     0,    48,   502,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     508,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,     0,    83,   510,    85,   511,   512,    88,
      89,  1494,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1152,     0,     0,     0,  1153,
       0,     0,   116,   516,     0,     0,     0,   118,   119,   120,
     121,   517,   123,   124,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   131,     0,     0,     0,   132,     0,
     133,   521,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   522,   145,   146,   147,   148,   149,
     150,     0,     0,  1154,   152,     0,     0,   422,   155,   156,
     157,   158,   159,   160,   161,   162,   523,   164,   524,   166,
     525,   526,   169,   170,   171,   172,   173,   174,   527,   176,
     528,   529,   530,   180,   181,   531,   532,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     3,     0,   249,   533,   251,  1155,
    1156,  1157,  1158,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   493,    20,    21,
      22,   494,    24,   495,   496,  1151,   498,   421,    30,   499,
      32,    33,    34,     0,    35,    36,    37,    38,   500,    40,
      41,    42,    43,    44,    45,    46,   501,     0,    48,   502,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   508,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,  1638,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1152,     0,     0,     0,  1153,     0,     0,   116,   516,
       0,     0,     0,   118,   119,   120,   121,   517,   123,   124,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,     0,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     522,   145,   146,   147,   148,   149,   150,     0,     0,  1154,
     152,     0,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,   164,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,   531,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       3,     0,   249,   533,   251,  1155,  1156,  1157,  1158,     9,
      10,     0,     0,     0,     0,     0,     0,   419,   420,     0,
      16,    17,    18,   493,    20,    21,    22,   494,    24,   495,
     496,  1151,   498,   421,    30,   499,    32,    33,    34,     0,
      35,    36,    37,    38,   500,    40,    41,    42,    43,    44,
      45,    46,   501,     0,    48,   502,    50,   503,   504,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,   508,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,     0,    83,   510,    85,   511,
     512,    88,    89,  1642,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1152,     0,     0,
       0,  1153,     0,     0,   116,   516,     0,     0,     0,   118,
     119,   120,   121,   517,   123,   124,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   131,     0,     0,     0,
     132,     0,   133,   521,     0,     0,     0,     0,     0,     0,
     139,     0,   140,   141,   142,   143,   522,   145,   146,   147,
     148,   149,   150,     0,     0,  1154,   152,     0,     0,   422,
     155,   156,   157,   158,   159,   160,   161,   162,   523,   164,
     524,   166,   525,   526,   169,   170,   171,   172,   173,   174,
     527,   176,   528,   529,   530,   180,   181,   531,   532,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     3,     0,   249,   533,
     251,  1155,  1156,  1157,  1158,     9,    10,     0,     0,     0,
       0,     0,     0,   419,   420,     0,    16,    17,    18,   493,
      20,    21,    22,   494,    24,   495,   496,  1151,   498,   421,
      30,   499,    32,    33,    34,     0,    35,    36,    37,    38,
     500,    40,    41,    42,    43,    44,    45,    46,   501,     0,
      48,   502,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   508,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,     0,    83,   510,    85,   511,   512,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,  1152,     0,     0,     0,  1153,     0,     0,
     116,   516,     0,     0,     0,   118,   119,   120,   121,   517,
     123,   124,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   131,     0,     0,     0,   132,     0,   133,   521,
       0,     0,     0,     0,     0,     0,   139,     0,   140,   141,
     142,   143,   522,   145,   146,   147,   148,   149,   150,     0,
       0,  1154,   152,     0,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   523,   164,   524,   166,   525,   526,
     169,   170,   171,   172,   173,   174,   527,   176,   528,   529,
     530,   180,   181,   531,   532,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     3,     0,   249,   533,   251,  1155,  1156,  1157,
    1158,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   493,    20,    21,    22,   494,
      24,   495,   496,  1151,   498,   421,    30,   499,    32,    33,
      34,     0,    35,    36,    37,    38,   500,    40,    41,    42,
      43,    44,    45,    46,   501,     0,    48,   502,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   508,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1152,
       0,     0,     0,  1153,     0,     0,   116,   516,     0,     0,
       0,   118,   119,   120,   121,   517,   123,   124,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,     0,   133,   521,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   522,   145,
     146,   147,   148,   149,   150,     0,     0,   151,   152,     0,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,   164,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,   531,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     3,     0,
     249,   533,   251,  1155,  1156,  1157,  1158,     9,    10,     0,
       0,     0,     0,     0,     0,   419,   420,     0,    16,    17,
      18,   541,    20,    21,    22,   494,   542,   543,   496,   497,
     498,   421,    30,   499,    32,   544,    34,     0,    35,    36,
      37,    38,   545,    40,   546,   547,    43,    44,    45,    46,
     501,     0,    48,   548,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     549,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,     0,    83,   510,    85,   511,   512,    88,
      89,  1243,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   516,     0,     0,     0,   118,   119,   120,
     121,   517,   123,   124,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   131,     0,     0,     0,   132,     0,
     133,   521,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   522,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,     0,     0,   422,   155,   156,
     157,   158,   159,   160,   161,   162,   523,   550,   524,   166,
     525,   526,   169,   170,   171,   172,   173,   174,   527,   176,
     528,   529,   530,   180,   181,   531,   532,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     3,     0,   249,   533,   251,   252,
     253,   254,   255,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   541,    20,    21,
      22,   494,   542,   543,   496,   497,   498,   421,    30,   499,
      32,   544,    34,     0,    35,    36,    37,    38,   545,    40,
     546,   547,    43,    44,    45,    46,   501,     0,    48,   548,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   549,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   516,
       0,     0,     0,   118,   119,   120,   121,   517,   123,   124,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,     0,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     522,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,     0,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,   550,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,   531,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       0,     0,   249,   533,   251,   252,   253,   254,   255,     5,
       6,     7,     8,     9,    10,     0,     0,     0,    13,     0,
       0,   419,   420,     0,    16,    17,    18,   842,    20,    21,
      22,    23,     0,   843,   496,    27,     0,   421,    30,   499,
      32,     0,    34,     0,    35,    36,    37,    38,   844,    40,
       0,     0,    43,    44,    45,    46,   501,     0,    48,   845,
      50,     0,     0,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   846,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,    82,
      83,   510,    85,   511,   512,    88,    89,   563,    91,     0,
       0,     0,     0,    93,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,     0,   564,   112,     0,   113,   114,     0,   116,   117,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     518,     0,   126,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,     0,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,     0,     0,
     152,   153,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,     0,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,     0,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     0,
     248,     9,    10,   533,   251,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,     0,    20,    21,    22,   494,
       0,     0,   496,   497,     0,   421,    30,   499,    32,     0,
      34,     0,    35,    36,    37,    38,     0,    40,     0,     0,
      43,    44,    45,    46,   501,     0,    48,     0,    50,     0,
       0,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,     0,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,     0,
       0,     0,     0,     0,     0,     0,   116,   516,     0,     0,
       0,   118,   119,   120,   121,   517,   123,   124,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,     0,   133,   521,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   522,   145,
     146,   147,   148,   149,   150,     0,     0,     0,   152,     0,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,     0,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,     0,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,     0,
       0,   533,   251
  };

  const short int
  xquery_parser::yycheck_[] =
  {
       0,   316,   183,   430,   431,     5,     6,     7,     8,     5,
       6,     7,    76,   695,   679,   316,     0,     5,     6,     7,
       8,     5,     6,     7,     8,    14,    90,   346,   770,  1284,
     785,   917,   829,     5,     6,     7,     8,   680,   681,   682,
     683,  1301,  1056,   798,   263,   623,   624,   866,  1040,   432,
     114,   590,   770,   112,   113,     1,   595,   812,   621,   622,
     623,   624,   126,    76,   128,  1137,  1365,  1366,     1,   621,
     622,   137,   295,   953,  1003,  1497,   264,     1,  1500,  1080,
     256,   257,    36,    39,   467,   468,   727,  1021,    44,    45,
    1412,   279,    27,    28,   119,    36,     1,    53,   930,   931,
     119,    30,  1314,     1,    60,     1,    62,    63,    31,    27,
      28,   111,    47,   286,    52,    71,     9,    10,     1,    56,
       8,   108,    57,   111,   225,   225,     1,   111,   148,    47,
       1,   658,     1,   660,   661,   108,   663,     1,   665,   111,
      75,    95,    98,    97,   969,    80,   673,   674,   119,    97,
     119,     1,     1,   225,   137,   227,    97,    75,   353,   145,
     186,   356,   108,     1,   217,    30,   114,     1,   187,   159,
       1,   930,   931,   137,   225,   108,   227,   112,   113,   114,
       0,     1,   111,  1607,   210,    45,   176,   151,   247,   248,
     176,  1023,   130,     1,   148,   113,   125,   119,  1030,    33,
     225,   254,   425,    63,     0,     1,   429,   148,   194,   157,
     969,   104,    30,   314,   314,   186,     1,   186,   201,   161,
     975,   150,     1,   143,     1,   154,    37,    38,   157,    40,
      41,   124,     1,   126,   148,     1,   295,   108,     1,   108,
       1,  1540,   314,    55,  1003,    57,   233,    58,   177,   114,
       1,  1137,  1138,   273,   569,  1510,   256,   257,   108,   108,
     260,   154,   235,   314,  1023,   158,   190,  1281,   569,   225,
     108,  1030,   256,   257,  1029,  1267,   260,   108,   451,  1076,
     217,   174,   307,   349,  1606,   190,  1028,   175,   108,   101,
     354,   214,   190,   357,   190,   295,   161,   875,   876,  1721,
     108,  1513,   195,   114,  1305,  1234,  1186,   190,  1026,  1243,
    1028,   295,   108,  1314,   955,   190,  1388,   254,   187,   273,
     213,   873,   874,   108,  1042,    95,   190,   187,  1153,   108,
     259,   108,   273,  1757,   557,     1,     1,   187,   187,   108,
       1,   354,   108,   161,   357,   108,  1768,   108,  1770,   187,
     161,   273,   287,   273,   157,   738,   187,   108,   108,   273,
     295,   317,   318,   319,   184,    33,   425,   313,   303,   287,
     429,   108,   436,   437,  1129,     1,   440,   295,   311,   187,
     444,    49,    95,   447,   448,   625,   913,     1,   184,   629,
      97,   455,    94,    45,  1153,    47,   122,   461,   462,   184,
     783,   460,   621,   622,    97,   469,   465,  1706,   187,   220,
     187,   108,   476,   477,   478,   479,   475,   157,   187,   185,
     484,   644,   185,   482,   483,   425,   187,  1259,   492,   429,
     618,   619,   491,     1,   610,     1,   187,    97,   188,   251,
     628,   425,   108,   108,   101,   429,   154,   108,   218,   219,
     261,   188,   264,     5,   266,   107,   456,     9,   458,   108,
       1,  1760,   169,   233,     1,   277,   278,   279,   456,   281,
     458,   283,   456,   537,   458,  1234,   169,   108,  1233,    97,
     480,   183,   108,  1743,   456,   485,   458,   184,   552,   108,
     917,   119,   480,   155,   108,   157,   480,   485,   557,   563,
    1259,   485,  1388,  1245,    77,   218,   219,   233,   480,    27,
      28,  1397,  1513,   485,   573,   574,   168,   157,   184,   184,
     233,   948,  1408,   184,  1283,   584,   590,   108,  1347,   186,
     148,   595,  1351,  1788,   598,     3,  1254,  1115,  1116,  1117,
     108,   190,   108,   602,   603,   252,   253,  1229,   255,     9,
     101,   108,  1115,  1116,  1117,   262,   187,   557,   184,   252,
     253,  1100,   255,   114,   564,   272,   159,   108,   187,    29,
     184,   108,   124,   557,   126,   237,   564,   284,    30,   272,
     564,   154,   134,   176,     9,    10,   108,     9,  1420,   131,
     654,   284,   564,   976,   977,   113,   256,   257,   981,    67,
    1668,   108,   154,   603,    72,   131,   187,    29,     9,    10,
     610,   132,    95,   108,  1369,   225,   184,    97,   184,   603,
     230,   621,   622,   623,   624,     5,   610,   616,  1011,     9,
     187,   603,  1624,   699,   700,     9,    10,   621,   622,   623,
     624,   864,   701,   184,   644,   138,   166,   184,   221,   222,
     143,   119,   108,   154,   873,   197,   123,   108,   108,   111,
     644,  1420,   182,   108,   124,   187,   126,   731,   891,   190,
     734,   197,   155,   125,   157,   135,   269,   157,  1746,   104,
     187,   138,   154,   276,   748,    45,   157,    47,   752,   753,
    1576,   879,   187,   286,   154,   883,   696,   154,   150,   124,
     696,   126,   124,   104,   126,   177,   118,   771,   696,   210,
    1137,  1138,   696,   135,  1511,   779,    95,    42,   782,  1516,
      80,    46,   786,   124,   696,   126,    51,  1469,  1742,   154,
     104,   187,   154,   158,  1399,   147,   187,   187,  1497,    97,
     154,  1500,   187,   154,   124,    70,   126,   107,   160,   174,
     124,   149,   126,   154,   134,   149,   114,   158,     1,    97,
       3,   820,   821,   822,   828,   824,   177,   165,    30,   148,
     195,   165,  1454,   174,   154,   775,  1354,    95,   169,   775,
     154,   138,   194,   123,   158,    54,   143,   775,   213,    95,
      59,   775,    95,    54,   195,   107,   210,    95,    59,   157,
     174,   157,   866,   775,  1636,   864,   806,   807,   168,    78,
     148,   202,   213,   123,  1733,  1734,   128,    95,   806,   807,
    1139,   195,   806,   807,    67,  1017,     1,  1019,    97,    72,
     148,   895,   138,   201,   806,   807,    97,   143,   138,   213,
     143,   905,   210,   168,   154,   143,   171,   157,   157,   111,
     119,  1648,   157,   269,   154,  1652,  1775,  1689,    33,  1691,
     276,   186,  1781,   125,   864,   143,   930,   931,   932,   933,
     286,  1063,   159,  1065,    49,    25,   119,  1636,    95,  1262,
     864,    97,  1105,   159,    34,   247,   248,   212,   150,   176,
     107,   891,   154,    96,   157,   157,   885,   101,   114,   182,
     176,    54,  1567,  1568,   107,   969,    59,   891,   270,   268,
     114,    61,   199,   196,   117,   177,   275,  1560,  1106,   983,
     101,   101,  1754,   199,  1112,   128,   966,  1609,  1109,   182,
    1689,   146,  1691,   114,   114,   101,   101,   157,   978,   263,
    1737,   263,   157,   196,  1008,   299,   191,   192,   114,   114,
     274,  1706,   274,  1017,   308,  1019,   155,  1021,   157,  1023,
     154,  1388,  1721,   157,   154,  1280,  1030,   157,   154,   154,
    1397,   157,   157,   277,   278,   279,   123,   702,  1361,   283,
     705,  1408,   119,   708,   221,   222,   223,  1370,   232,   157,
     234,   232,   123,   234,   123,  1754,   129,   130,   119,  1063,
     123,  1065,   129,   130,    90,   677,   678,   684,   685,  1768,
     123,  1770,  1677,  1678,   154,   686,   687,  1227,  1228,   154,
    1597,  1598,   123,  1338,   123,   123,   123,   216,   114,  1711,
     154,  1346,   157,   241,   119,   241,  1100,   242,  1261,   157,
     126,   314,   128,   154,     0,  1346,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   190,   167,  1058,    93,
     100,  1125,   249,    50,   200,   102,   155,   103,   184,   157,
    1058,   193,   184,    30,  1058,   184,  1758,  1136,   184,    47,
     153,   119,   246,   133,   187,  1750,  1058,   154,     1,  1153,
     304,   141,   142,   119,   144,  1478,   143,   108,   154,   154,
     187,   143,   152,   187,   157,  1105,   156,   184,   158,   157,
     122,   157,   157,   163,   157,  1115,  1116,  1117,   157,    35,
      17,  1105,   154,   214,   157,  1114,   157,    30,   190,   179,
     190,  1115,  1116,  1117,     3,   231,   119,   245,   168,   284,
     284,   170,   170,   119,    71,    95,    95,    95,  1830,  1576,
    1832,   231,   150,   203,   204,   205,   206,   207,   208,    30,
    1842,   108,  1343,   187,   108,   161,   161,   128,   133,    95,
     246,  1486,   143,  1488,   119,   133,  1491,  1492,   184,  1243,
    1495,   184,   299,  1247,   108,   187,  1501,   187,    95,    97,
      45,    97,   184,   187,   187,  1259,   187,   187,   184,   154,
     154,   154,   154,   154,    95,   143,   190,    33,   154,  1273,
     237,   233,   184,   133,   143,    95,    30,   286,   227,  1283,
      95,   299,   154,   128,   119,   148,   119,   170,    95,   198,
     161,   133,   133,    97,   119,   154,   148,  1237,   101,   101,
     154,  1237,   184,   184,   184,   143,   122,    35,  1312,  1237,
     154,   190,    30,  1237,   119,    80,   245,   108,   107,   258,
     108,  1261,   285,   260,   145,  1237,   254,  1490,   157,   157,
     157,   157,  1272,  1337,   157,   157,  1272,  1261,   157,    30,
      30,   286,   267,  1347,  1272,    30,   287,  1351,  1272,   306,
     227,  1291,   145,   187,   190,  1291,   148,   187,   128,   108,
    1272,   148,   143,  1291,   101,   133,   198,  1291,     7,   187,
    1533,  1311,   184,   187,   187,  1379,   233,   187,  1318,  1291,
      97,   157,   190,  1311,  1639,   186,   237,  1311,  1643,   148,
    1318,   154,   107,   233,  1318,   157,   157,   119,   119,  1311,
      78,   187,   148,    79,   187,   187,  1318,   282,   187,   233,
    1350,   437,   286,   187,   440,   187,  1420,    30,   444,    30,
     187,   447,   448,   187,   108,   170,  1350,   233,   184,   455,
     127,   127,   271,   250,   148,   461,   462,   148,  1350,    97,
     184,   184,   184,   469,   184,   143,  1450,   154,   316,   184,
     476,   477,   478,   479,   250,    95,   187,   257,   484,  1622,
      30,    97,   187,    95,   170,   148,   492,   197,    54,    95,
    1633,  1634,  1727,    30,  1637,   265,   119,   108,   108,    95,
      95,  1644,   280,   183,   225,   197,   119,   197,   287,   198,
    1494,   119,   225,  1497,    94,   197,  1500,   119,   119,   293,
     199,   225,   287,   263,   737,   119,  1189,   970,  1512,    27,
      28,   537,  1767,  1517,   431,  1031,  1771,  1711,  1234,    37,
      38,   305,    40,    41,   260,   305,   552,   305,   111,    47,
     451,  1530,  1531,  1532,   260,   306,  1758,   563,   867,    57,
      58,  1134,   654,  1553,  1121,  1380,  1550,  1551,  1803,   306,
    1490,  1806,   788,   306,  1372,  1368,  1278,    75,  1365,  1273,
     552,  1281,    80,  1286,   656,   676,  1490,  1730,   657,   933,
     711,  1305,   598,   829,  1829,  1781,  1775,  1019,  1188,  1348,
    1337,  1347,  1408,   341,  1576,  1397,   459,  1138,  1573,   459,
    1147,  1401,  1002,  1533,   112,   113,   114,  1211,  1444,  1600,
    1398,    -1,   593,    -1,    -1,    -1,  1769,    -1,    -1,  1533,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1787,    -1,    -1,    -1,   654,    -1,
      -1,    -1,  1636,    -1,  1638,    -1,  1640,    -1,  1642,  1802,
      -1,    -1,    -1,   161,    -1,  1649,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1824,    -1,    -1,    -1,    -1,  1665,    -1,    -1,    -1,
    1833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1622,    -1,    -1,  1689,    -1,  1691,  1687,    -1,
      -1,    -1,    -1,  1633,  1634,    -1,    -1,  1637,  1622,    -1,
      -1,    -1,   220,  1707,  1644,    -1,  1710,    -1,   734,  1633,
    1634,    -1,    -1,  1637,    -1,    -1,    -1,  1721,    -1,    -1,
    1644,    -1,   748,    -1,    -1,    -1,   752,   753,  1732,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   261,    -1,   771,    -1,    -1,    -1,    -1,
    1754,    -1,    -1,   779,    -1,    -1,   782,    -1,  1762,    -1,
     786,    -1,    -1,    -1,  1768,    -1,  1770,    -1,    -1,   287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,  1791,    -1,    -1,
    1730,    -1,    -1,    -1,    -1,    -1,  1800,    -1,    -1,    -1,
      -1,    -1,   828,    -1,    -1,    -1,  1730,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,    -1,
      -1,  1825,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1769,
      -1,    -1,    -1,  1837,    -1,    -1,  1840,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1769,    -1,  1787,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1802,  1787,    -1,    -1,    -1,    -1,    -1,   895,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1802,   905,
      -1,    -1,    -1,    -1,  1824,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1833,    -1,    -1,    -1,    -1,    -1,    -1,
    1824,    -1,    -1,    -1,   930,   931,   932,   933,    -1,  1833,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   969,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   983,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   564,  1008,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1017,    -1,  1019,    -1,  1021,    -1,  1023,    -1,    -1,
      -1,    -1,    -1,    -1,  1030,   588,   589,    -1,   591,   592,
     593,   594,    -1,   596,    -1,    -1,    -1,    -1,   601,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1063,    -1,  1065,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   631,   632,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,    -1,
      -1,   644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   707,    -1,    -1,  1153,   711,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   750,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   787,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,
      -1,  1247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     813,    -1,    -1,  1259,   817,   818,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   826,    -1,    -1,    -1,  1273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1283,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1312,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   891,    -1,
      -1,  1337,    -1,    -1,   897,   898,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1379,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   971,    -1,
      -1,    -1,    -1,    -1,  1420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1006,  1450,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1041,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1494,  1052,
    1053,  1497,    -1,    -1,  1500,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1067,    -1,  1512,  1070,    -1,    -1,
      -1,  1517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1087,  1088,  1089,    -1,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,    -1,    -1,  1102,
    1103,    -1,    -1,    -1,  1550,  1551,    -1,    -1,  1111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1636,    -1,  1638,    -1,  1640,    -1,  1642,    -1,    -1,    -1,
      -1,    -1,    -1,  1649,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1689,    -1,  1691,  1249,    -1,  1251,    -1,
    1253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1261,    -1,
      -1,  1707,    -1,    -1,  1710,    -1,    -1,  1270,    -1,    -1,
      -1,    -1,    -1,  1276,  1277,  1721,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1732,    -1,    -1,    -1,
      -1,    -1,  1295,    -1,    -1,  1298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1754,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1762,    -1,    -1,    -1,
      -1,    -1,  1768,    -1,  1770,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1791,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1800,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1368,    -1,    -1,    -1,  1372,
    1373,    -1,    -1,    -1,  1820,  1378,    -1,    -1,    -1,  1825,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1837,    -1,    -1,  1840,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1463,    -1,    -1,    -1,  1467,    -1,    -1,    -1,  1471,    -1,
    1473,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1481,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1489,  1490,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1509,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1521,  1522,
    1523,  1524,    -1,  1526,  1527,    -1,  1529,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1544,    -1,    -1,    -1,    -1,  1549,    -1,    -1,    -1,
      -1,    -1,  1555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1615,    -1,  1617,    -1,    -1,  1620,    -1,    -1,
    1623,    -1,    -1,    -1,    -1,  1628,  1629,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1637,    -1,    -1,    -1,  1641,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1658,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1669,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1726,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1769,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,    -1,    -1,  1798,    -1,    -1,    -1,  1802,
      11,    12,    -1,    -1,  1807,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
    1823,    -1,    33,    34,  1827,    36,    37,    38,    39,    40,
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
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
     191,   192,    -1,   194,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
      -1,   312,    -1,   314,   315,   316,   317,   318,   319,   320,
       0,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     310,     1,   312,    -1,   314,   315,   316,   317,   318,   319,
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     310,     1,   312,    -1,   314,   315,   316,   317,   318,   319,
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
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
     320,     0,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,    -1,
      -1,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,
     119,    -1,    -1,   122,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,   137,    -1,
      -1,    -1,   141,   142,    -1,   144,    -1,   146,   147,    -1,
      -1,    -1,   151,   152,    -1,    -1,   155,   156,   157,   158,
     159,   160,    -1,    -1,   163,    -1,    -1,    -1,   167,   168,
      -1,    -1,   171,    -1,    -1,    -1,    -1,   176,    -1,    -1,
     179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,   188,
      -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,   200,   201,    -1,   203,   204,   205,   206,   207,   208,
      -1,   210,    -1,   212,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   233,    -1,   235,    -1,   237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   311,    30,   313,    -1,    33,    34,    -1,    36,
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
      -1,   188,   189,   190,   191,   192,    -1,   194,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,   213,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,    -1,   312,    -1,   314,   315,   316,
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
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
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
     315,   316,   317,   318,   319,   320,    -1,   322,    11,    12,
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
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,   184,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,   185,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
     313,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,   136,    -1,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,    -1,   152,
     153,   154,   155,    -1,   157,   158,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   198,    -1,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,    -1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    -1,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
      -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    16,
      -1,   314,   315,   316,   317,   318,   319,   320,    25,    26,
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
     307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320,    16,    -1,    18,    19,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,   151,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
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
      16,    -1,   314,   315,   316,   317,   318,   319,   320,    25,
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
     186,   187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,    -1,    16,    -1,   314,   315,
     316,   317,   318,   319,   320,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
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
      -1,    -1,    16,    -1,   314,   315,   316,   317,   318,   319,
     320,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
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
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
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
     304,   305,   306,   307,   308,   309,    -1,    -1,    16,    -1,
     314,   315,   316,   317,   318,   319,   320,    25,    26,    -1,
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
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
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
     308,   309,    -1,    -1,    16,    -1,   314,   315,   316,   317,
     318,   319,   320,    25,    26,    -1,    -1,    -1,    -1,    -1,
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
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
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
      16,    -1,   314,   315,   316,   317,   318,   319,   320,    25,
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
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,   157,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,    -1,    16,    -1,   314,   315,
     316,   317,   318,   319,   320,    25,    26,    -1,    -1,    -1,
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
      -1,   151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
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
      -1,    -1,    16,    -1,   314,   315,   316,   317,   318,   319,
     320,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
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
     304,   305,   306,   307,   308,   309,    -1,    -1,    16,    -1,
     314,   315,   316,   317,   318,   319,   320,    25,    26,    -1,
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
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
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
     308,   309,    -1,    -1,    16,    -1,   314,   315,   316,   317,
     318,   319,   320,    25,    26,    -1,    -1,    -1,    -1,    -1,
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
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
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
      -1,    -1,   314,   315,   316,   317,   318,   319,   320,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    -1,    54,    -1,    56,    57,    58,    59,    60,    61,
      -1,    -1,    64,    65,    66,    67,    68,    -1,    70,    71,
      72,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,    -1,   101,
     102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,   125,    -1,   127,   128,   129,   130,    -1,
     132,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,    -1,   154,   155,    -1,   157,   158,    -1,   160,   161,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,    -1,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    25,    26,   315,   316,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    -1,    40,    41,    42,    43,
      -1,    -1,    46,    47,    -1,    49,    50,    51,    52,    -1,
      54,    -1,    56,    57,    58,    59,    -1,    61,    -1,    -1,
      64,    65,    66,    67,    68,    -1,    70,    -1,    72,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    -1,    -1,    -1,   101,   102,   103,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,    -1,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,
      -1,   315,   316
  };

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
     181,   182,   186,   188,   189,   190,   191,   192,   194,   196,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   211,   212,   213,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   259,   260,   261,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   312,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   335,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   356,   357,   358,   359,
     360,   361,   365,   366,   367,   371,   373,   374,   376,   383,
     385,   388,   389,   390,   392,   393,   394,   395,   396,   398,
     399,   401,   402,   403,   404,   405,   406,   408,   409,   412,
     413,   414,   415,   416,   422,   424,   426,   427,   428,   433,
     452,   455,   459,   462,   463,   469,   470,   471,   472,   474,
     475,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     487,   488,   489,   490,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   523,   524,   525,   526,   527,   528,   542,   543,   545,
     546,   547,   548,   549,   550,   551,   552,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   574,
     579,   580,   581,   582,   583,   584,   587,   645,   646,   647,
     648,   650,   651,   652,   653,   654,   657,   658,   659,    33,
      34,    49,   215,   391,   392,   393,   391,   391,   392,   393,
     157,   157,    37,    38,    40,    41,    47,    57,    58,    75,
      80,   112,   113,   114,   161,   220,   261,   287,   295,   303,
     372,   373,   377,   378,   379,   161,   154,   157,   154,   157,
     154,   157,     1,   157,   380,   157,    25,    34,    61,   119,
     273,   432,   434,   435,   157,   154,   157,   157,   157,   119,
     154,   157,   157,   157,    77,   154,   221,   222,   123,   123,
     123,   154,   157,    39,    43,    45,    46,    47,    48,    51,
      60,    68,    71,    73,    74,    76,    91,    92,    98,   106,
     113,   115,   116,   136,   139,   140,   161,   169,   172,   180,
     181,   189,   202,   224,   226,   228,   229,   236,   238,   239,
     240,   243,   244,   315,   507,   658,   123,   119,   400,   123,
     123,    39,    44,    45,    53,    60,    62,    63,    71,    98,
     225,   657,   119,   123,   123,   184,   391,   393,   414,   649,
      48,    73,    74,   119,   154,   185,   244,   413,   415,   426,
     187,   413,   657,   154,   154,   123,   657,    18,    19,   657,
     123,   123,   123,   499,   154,    31,   214,   216,   225,   227,
     314,   225,   227,   314,   225,   314,   225,   230,   119,   241,
     241,   242,   157,   154,   395,   311,   413,   313,   413,   314,
     322,   337,   337,     0,   339,   340,    33,    49,   342,   359,
       1,   190,   336,   190,   336,   113,   374,   394,   413,   108,
     190,   108,   336,   190,    42,    46,    51,    70,   168,   171,
     186,   212,   407,   417,   418,   423,   424,   425,   440,   441,
     445,     3,    67,    72,   119,   419,   167,    93,   133,   141,
     142,   144,   152,   156,   158,   163,   179,   203,   204,   205,
     206,   207,   208,   491,   492,   249,   100,   159,   176,   199,
     118,   147,   160,   194,   201,   210,   137,   151,    50,   200,
     102,   103,   159,   176,   489,   193,   154,   496,   499,   191,
     192,   155,   511,   512,   507,   511,   507,   157,   511,   157,
     146,   157,   184,   184,   184,   184,   375,   514,   375,    30,
     656,   182,   196,   182,   196,   166,   182,   658,   657,   169,
     202,    47,   657,   153,   119,    45,    47,    80,   107,   168,
     657,   221,   222,   223,   246,   618,   657,   657,   304,   138,
     143,   113,   287,   295,   377,   657,   392,   187,   392,    45,
      63,   187,   570,   571,   413,   187,   194,   657,   429,   430,
     657,   119,   187,   381,   382,   154,   397,   413,     1,   161,
     656,   114,   161,   355,   656,   657,   119,   143,   108,   187,
     413,    30,   187,   657,   657,   657,   453,   454,   657,   392,
     187,   413,   413,   572,   657,   392,   154,   154,   413,   187,
     194,   657,   657,   143,   453,   184,   184,   122,   108,   184,
     157,   157,   157,   657,   154,   185,   418,   187,    35,   530,
     531,   532,   413,   413,     8,   175,    17,   413,   214,    30,
     414,   414,    39,    45,    60,    71,    98,   510,   658,   414,
     414,   414,   649,   414,   510,   414,   231,   585,   586,   657,
     190,   190,   414,   413,   393,   413,   245,   410,   411,   311,
     313,   414,   337,   190,   336,   190,   336,     3,   343,   359,
     389,     1,   343,   359,   389,    33,   360,   389,   360,   389,
     400,   336,   400,   414,   414,   119,   168,   170,   170,   414,
     394,   414,   284,   284,   429,   119,   436,   471,   472,   474,
     474,   474,   474,   473,   474,   474,   474,    71,   475,   479,
     479,   478,   480,   480,   480,   480,   481,   481,   482,   482,
     231,    95,    95,    95,   497,   391,   499,   499,   413,   512,
     145,   187,   414,   522,   187,   150,   187,   522,   108,   187,
     187,   108,   108,   380,    30,   658,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   362,   363,   364,    95,
     138,   143,   368,   369,   370,   657,   161,   161,   362,   656,
     128,   133,    55,    57,   101,   251,   264,   266,   277,   278,
     279,   281,   283,   619,   620,   621,   622,   623,   624,   631,
     637,   638,   246,    95,   299,   657,   143,   414,   119,   657,
     657,   133,   184,   184,   187,   187,   184,   108,   187,   108,
     187,   108,    36,    95,    97,   148,   431,   432,   553,   657,
      95,   108,   187,   391,   187,   657,    97,    45,   657,   656,
      97,   143,   553,   657,   414,   435,   184,   187,   187,   187,
     187,   108,   188,   148,   553,   184,   187,   187,   154,   184,
     392,   392,   184,   108,   187,   108,   187,   143,   553,   414,
     188,   414,   414,   413,   413,   413,   657,   531,   532,   131,
     197,   184,   184,   184,   132,   190,    95,   218,   219,   233,
      95,   218,   219,   233,   233,   233,    95,    95,   237,   225,
     314,   108,   235,   143,   190,   187,   413,   184,   508,   591,
     411,   233,   359,    33,    33,   190,   336,   190,   114,   394,
     657,   170,   414,   446,   447,   119,   414,   442,   443,   657,
      56,   217,   254,   420,   421,   474,   154,   157,   259,   495,
     514,   592,   595,   596,   597,   598,   599,   603,   605,   607,
     608,    47,   153,   157,   211,   317,   318,   319,   320,   554,
     556,   558,   560,   575,   576,   577,   578,   655,   657,   554,
     486,   559,   657,   486,   184,   185,   108,   187,   187,   514,
     149,   165,   149,   165,   138,   397,   380,   363,   133,   556,
     370,   414,   553,   656,   656,   129,   130,   656,   277,   278,
     279,   283,   657,   263,   274,   263,   274,    30,   286,    97,
     114,   157,   625,   628,   619,    39,    44,    53,    60,    62,
      71,    98,   225,   317,   318,   319,   384,   560,   655,   227,
     299,   308,   414,   657,    95,   299,   656,   154,   572,   573,
     657,   572,   573,   119,   430,   128,   554,   119,   414,   148,
     432,   148,    36,   148,   431,   432,   553,   554,   382,    95,
     184,   198,   133,   354,   656,   161,   133,    97,   354,   414,
     143,   432,   154,   119,   414,   414,   148,   101,   456,   457,
     458,   460,   461,   101,   464,   465,   466,   467,   392,   184,
     184,   154,   572,   572,   414,   143,   190,   414,   122,   187,
     187,   187,    35,   532,   131,   197,     9,    10,   104,   124,
     126,   154,   195,   527,   529,   540,   541,   544,   154,    30,
     232,   234,   414,   414,   414,   232,   234,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   510,   119,   414,   414,
      48,    73,    74,   244,   394,   415,   426,   245,   588,   589,
     154,   210,   395,   414,   190,   114,   389,   389,   389,   446,
      96,   107,   117,   128,   448,   449,   450,   451,   108,   657,
     107,   444,   108,   148,   553,   254,    54,    59,    78,   119,
     431,   437,   438,   439,   421,   413,   592,   599,   154,   285,
     476,   644,    97,   169,   252,   253,   255,   262,   272,   284,
     593,   594,   613,   614,   615,   616,   639,   642,   258,   260,
     600,   618,   267,   604,   640,   247,   248,   270,   609,   610,
     157,   157,   556,   157,   157,   157,   157,   157,   145,   176,
     194,   555,   145,   145,   414,   138,   397,   574,   369,   286,
      30,    97,   114,   157,   632,    30,   625,   555,   555,   497,
     287,   306,   553,   384,   227,   190,   391,   187,   187,   145,
     187,   187,   430,   148,   431,   657,   414,   148,   414,   128,
     414,   148,   432,   148,   554,   394,   414,   656,   108,   354,
     414,   143,   391,   454,   414,   414,   114,   457,   458,   101,
     418,   114,   458,   461,   119,   468,   554,   101,   114,   465,
     101,   114,   467,   184,   391,   187,   187,   414,   414,   198,
     464,   133,   195,   529,     7,   392,   657,   195,   540,   392,
     190,   233,   233,   233,   233,    97,   237,   237,   586,   418,
     157,   157,   157,   418,   591,   589,   508,   656,   129,   130,
     450,   451,   451,   447,   143,   553,   656,   443,   414,   148,
     119,   119,   414,   657,   439,    78,   184,   187,   592,   606,
     250,   217,   254,   268,   275,   643,    97,   256,   257,   641,
     250,   596,   643,   478,   613,   597,   148,   282,   601,   602,
     641,   286,   612,    79,   611,   187,   194,   554,   557,   187,
     187,   187,   187,   187,   187,   187,    30,   137,   201,   634,
     635,   636,    30,   633,   634,   271,   629,   108,   626,   170,
     657,   257,   497,   184,   414,   148,   414,   148,   431,   414,
     148,   414,   127,   127,    97,   656,   414,   184,   418,   418,
     414,   394,   414,   418,   418,   657,   210,   418,   119,   468,
     119,   418,   119,   468,   418,   184,   114,   532,   657,   195,
     184,   532,   657,   184,   414,   414,   414,   414,   316,   414,
     414,   414,   413,   413,   413,   154,   590,   451,   414,   143,
     414,   657,   657,   438,   414,   184,   480,    52,   130,   478,
     478,   269,   276,   286,   617,   617,   598,   154,   280,    95,
     187,   108,   187,   632,   632,   636,   108,   187,    30,   630,
     641,   627,   628,   187,   386,   387,   497,   119,   225,   307,
     287,   170,   414,   414,   148,   414,   394,   414,   354,   414,
     394,    95,   554,   394,   414,   657,   418,   657,   414,   657,
     418,   394,   119,    94,   183,   533,   532,   657,   197,   532,
     414,   187,   187,   187,   413,   444,   414,    54,   478,   478,
     199,   413,   554,   554,    95,    30,   265,   108,   108,   451,
     553,   657,   119,   225,   657,   386,   414,   468,    95,   418,
      95,   657,     5,   134,   536,   537,   539,   541,    29,   135,
     534,   535,   538,   541,   197,   532,   197,   198,   464,   184,
     444,   119,   478,   184,   554,   628,   387,   451,   305,   657,
     119,   225,   418,   468,   394,   414,   468,   418,    94,   134,
     539,   183,   135,   538,   197,   114,   657,   414,   305,   657,
     119,   394,   414,   418,   418,   119,   293,   305,   657,   657,
     306,   414,   306,   418,   497,   497,   199,   287,   657,   225,
     119,   657,   306,   497
  };

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
     394,   394,   394,   394,   394,   394,   394,   395,   395,   396,
     397,   398,   399,   399,   399,   400,   400,   400,   400,   401,
     402,   403,   404,   405,   405,   406,   407,   408,   409,   410,
     410,   411,   412,   413,   413,   413,   414,   414,   414,   414,
     414,   414,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   416,   417,   418,   419,   419,   420,
     420,   420,   421,   421,   422,   422,   423,   424,   424,   424,
     425,   425,   425,   425,   425,   426,   426,   427,   427,   427,
     428,   429,   429,   429,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   431,   432,   433,   434,
     434,   435,   435,   435,   435,   436,   436,   437,   437,   437,
     438,   438,   438,   439,   439,   439,   440,   441,   442,   442,
     443,   443,   443,   443,   443,   443,   444,   445,   445,   446,
     446,   447,   447,   448,   448,   448,   448,   448,   448,   448,
     449,   449,   450,   450,   451,   452,   452,   453,   453,   454,
     454,   455,   456,   456,   457,   458,   458,   459,   460,   460,
     461,   462,   462,   463,   463,   464,   464,   465,   465,   466,
     466,   467,   467,   468,   468,   469,   470,   470,   471,   471,
     472,   472,   472,   472,   472,   473,   472,   472,   472,   472,
     474,   474,   475,   475,   476,   476,   477,   477,   478,   478,
     478,   479,   479,   479,   479,   479,   480,   480,   480,   481,
     481,   481,   482,   482,   483,   483,   484,   484,   485,   485,
     486,   486,   487,   487,   488,   488,   488,   488,   489,   489,
     489,   490,   490,   491,   491,   491,   491,   491,   491,   492,
     492,   492,   493,   493,   493,   493,   494,   495,   495,   496,
     496,   496,   497,   497,   497,   497,   498,   499,   499,   499,
     500,   500,   501,   501,   501,   501,   502,   502,   503,   503,
     503,   503,   503,   503,   503,   504,   504,   505,   505,   506,
     506,   506,   506,   506,   507,   507,   508,   508,   509,   509,
     509,   509,   510,   510,   510,   510,   511,   511,   512,   513,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   513,   513,   514,   514,   515,   515,   515,   516,   517,
     517,   518,   519,   520,   521,   521,   522,   522,   522,   522,
     523,   523,   524,   525,   526,   526,   527,   527,   527,   528,
     528,   528,   528,   528,   528,   529,   529,   530,   530,   531,
     532,   532,   533,   533,   534,   534,   535,   535,   535,   535,
     536,   536,   537,   537,   537,   537,   538,   538,   539,   539,
     540,   540,   540,   540,   541,   541,   541,   541,   542,   542,
     543,   543,   544,   545,   545,   545,   545,   545,   545,   545,
     546,   547,   547,   548,   548,   549,   550,   551,   551,   552,
     552,   553,   554,   554,   554,   555,   555,   555,   556,   556,
     556,   556,   556,   556,   556,   557,   557,   558,   559,   560,
     560,   560,   560,   560,   560,   560,   560,   560,   560,   561,
     562,   563,   563,   563,   564,   565,   566,   567,   567,   567,
     568,   568,   568,   568,   568,   569,   570,   570,   570,   570,
     570,   570,   570,   571,   572,   573,   574,   575,   575,   576,
     577,   577,   578,   579,   579,   579,   580,   580,   580,   580,
     580,   580,   580,   580,   580,   580,   581,   581,   582,   582,
     583,   584,   585,   585,   586,   587,   588,   588,   589,   590,
     591,   591,   592,   593,   593,   594,   594,   595,   595,   596,
     596,   597,   597,   598,   598,   599,   600,   600,   601,   601,
     602,   603,   603,   603,   604,   604,   605,   606,   606,   607,
     608,   608,   609,   609,   610,   610,   610,   611,   611,   612,
     612,   613,   613,   613,   613,   613,   614,   615,   616,   617,
     617,   617,   618,   618,   619,   619,   619,   619,   619,   619,
     619,   619,   620,   620,   620,   620,   621,   621,   622,   623,
     623,   624,   624,   624,   625,   625,   626,   626,   627,   627,
     628,   629,   629,   630,   630,   631,   631,   631,   632,   632,
     633,   633,   634,   634,   635,   635,   636,   636,   637,   638,
     638,   639,   639,   639,   640,   641,   641,   641,   641,   642,
     642,   643,   643,   644,   645,   645,   646,   646,   647,   647,
     648,   649,   649,   650,   650,   650,   651,   652,   653,   654,
     655,   655,   655,   656,   657,   657,   657,   657,   657,   657,
     657,   657,   657,   657,   657,   657,   657,   657,   657,   657,
     657,   657,   657,   657,   657,   657,   657,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   659
  };

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
       1,     1,     1,     1,     1,     1,     2,     3,     3,     2,
       1,     1,     4,     3,     3,     5,     4,     6,     4,     6,
       5,     7,     4,     5,     5,     6,     3,     3,     2,     1,
       3,     4,     5,     3,     6,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     2,     3,     1,     3,
       4,     5,     6,     5,     1,     2,     2,     3,     4,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     2,     2,     2,     5,     5,     1,     4,     3,
       4,     8,     1,     2,     3,     2,     3,     8,     1,     2,
       3,     8,    10,     8,    10,     1,     2,     4,     7,     1,
       2,     4,     7,     1,     3,     8,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     0,     4,     3,     3,     3,
       1,     5,     1,     3,     0,     1,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     4,     1,     4,     1,     4,     1,     4,
       1,     2,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     4,     1,     2,     3,
       2,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     1,     2,     3,     1,
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
       7,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     4,     4,     3,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     4,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     1,     1,     4,
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
       3,     3,     5,     5,     5,     8,     5,     3,     5,     7,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
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
  "JSONTest", "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
       0,   872,   872,   873,   877,   881,   887,   891,   895,   901,
     907,   915,   921,   930,   935,   941,   947,   953,   961,   966,
     974,   982,   990,   999,  1004,  1010,  1016,  1025,  1033,  1040,
    1046,  1055,  1056,  1057,  1058,  1059,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1072,  1077,  1083,  1089,  1095,  1100,
    1106,  1111,  1117,  1122,  1128,  1133,  1138,  1143,  1149,  1151,
    1153,  1161,  1166,  1174,  1182,  1191,  1198,  1206,  1212,  1218,
    1224,  1231,  1239,  1250,  1257,  1264,  1272,  1279,  1285,  1294,
    1295,  1296,  1297,  1298,  1299,  1300,  1301,  1304,  1310,  1317,
    1324,  1332,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,
    1348,  1349,  1352,  1366,  1372,  1378,  1385,  1391,  1398,  1403,
    1409,  1415,  1427,  1439,  1452,  1457,  1465,  1473,  1482,  1487,
    1494,  1499,  1506,  1511,  1519,  1524,  1531,  1537,  1546,  1547,
    1550,  1564,  1577,  1592,  1605,  1610,  1615,  1620,  1626,  1633,
    1641,  1646,  1654,  1662,  1670,  1678,  1688,  1692,  1698,  1702,
    1709,  1718,  1729,  1735,  1742,  1747,  1754,  1761,  1770,  1780,
    1790,  1800,  1815,  1831,  1835,  1840,  1845,  1849,  1854,  1859,
    1864,  1872,  1879,  1886,  1899,  1900,  1901,  1902,  1903,  1904,
    1905,  1906,  1907,  1908,  1909,  1910,  1911,  1914,  1919,  1926,
    1946,  1952,  1958,  1965,  1972,  1981,  1990,  1999,  2008,  2019,
    2025,  2031,  2037,  2049,  2054,  2060,  2072,  2085,  2105,  2111,
    2118,  2127,  2134,  2140,  2145,  2157,  2169,  2170,  2171,  2172,
    2173,  2174,  2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,
    2185,  2186,  2187,  2188,  2191,  2203,  2209,  2214,  2219,  2225,
    2230,  2235,  2241,  2250,  2260,  2270,  2281,  2287,  2288,  2289,
    2292,  2293,  2294,  2295,  2296,  2299,  2306,  2314,  2318,  2326,
    2334,  2339,  2346,  2353,  2363,  2373,  2383,  2393,  2403,  2413,
    2423,  2433,  2443,  2452,  2462,  2472,  2484,  2490,  2496,  2502,
    2508,  2516,  2524,  2532,  2540,  2550,  2556,  2565,  2566,  2570,
    2577,  2581,  2586,  2589,  2593,  2597,  2603,  2609,  2615,  2621,
    2629,  2633,  2641,  2649,  2657,  2665,  2675,  2681,  2687,  2695,
    2701,  2709,  2713,  2721,  2727,  2733,  2739,  2748,  2757,  2766,
    2777,  2781,  2787,  2793,  2801,  2807,  2816,  2827,  2833,  2841,
    2845,  2854,  2860,  2866,  2874,  2880,  2886,  2894,  2900,  2906,
    2914,  2920,  2927,  2937,  2944,  2954,  2960,  2968,  2974,  2983,
    2989,  2997,  3003,  3012,  3018,  3026,  3032,  3036,  3042,  3047,
    3053,  3057,  3066,  3072,  3081,  3091,  3090,  3103,  3112,  3121,
    3132,  3136,  3147,  3151,  3157,  3160,  3166,  3170,  3176,  3180,
    3184,  3190,  3194,  3200,  3206,  3212,  3220,  3224,  3228,  3234,
    3238,  3244,  3252,  3256,  3264,  3268,  3276,  3280,  3288,  3292,
    3300,  3304,  3310,  3314,  3320,  3324,  3328,  3332,  3340,  3341,
    3342,  3345,  3350,  3356,  3360,  3364,  3368,  3372,  3376,  3382,
    3386,  3390,  3396,  3400,  3404,  3408,  3417,  3425,  3431,  3439,
    3443,  3447,  3453,  3457,  3465,  3473,  3493,  3499,  3509,  3513,
    3519,  3520,  3523,  3529,  3537,  3543,  3553,  3559,  3567,  3571,
    3575,  3579,  3583,  3589,  3595,  3601,  3605,  3611,  3615,  3624,
    3628,  3632,  3638,  3642,  3650,  3651,  3654,  3658,  3664,  3668,
    3672,  3676,  3682,  3686,  3690,  3694,  3700,  3706,  3714,  3720,
    3721,  3722,  3723,  3724,  3725,  3726,  3727,  3728,  3729,  3730,
    3731,  3732,  3733,  3736,  3740,  3746,  3753,  3760,  3769,  3775,
    3779,  3785,  3792,  3798,  3804,  3808,  3826,  3832,  3838,  3844,
    3852,  3856,  3862,  3868,  3878,  3879,  3882,  3883,  3884,  3887,
    3895,  3911,  3919,  3935,  3953,  3973,  3979,  3988,  3994,  4003,
    4010,  4011,  4013,  4018,  4025,  4028,  4034,  4040,  4046,  4053,
    4062,  4065,  4071,  4077,  4083,  4090,  4099,  4103,  4109,  4113,
    4119,  4123,  4127,  4132,  4139,  4143,  4147,  4151,  4157,  4162,
    4168,  4174,  4181,  4187,  4192,  4197,  4202,  4207,  4212,  4217,
    4220,  4226,  4230,  4236,  4240,  4246,  4252,  4258,  4262,  4268,
    4272,  4278,  4284,  4288,  4292,  4298,  4304,  4310,  4318,  4322,
    4326,  4330,  4334,  4338,  4342,  4348,  4354,  4362,  4368,  4374,
    4378,  4382,  4386,  4390,  4394,  4398,  4402,  4406,  4410,  4416,
    4422,  4428,  4432,  4436,  4442,  4447,  4453,  4459,  4463,  4468,
    4474,  4478,  4484,  4490,  4494,  4502,  4508,  4512,  4518,  4527,
    4536,  4542,  4548,  4556,  4562,  4568,  4574,  4580,  4584,  4590,
    4596,  4600,  4608,  4614,  4620,  4626,  4634,  4638,  4644,  4650,
    4654,  4660,  4664,  4670,  4676,  4683,  4691,  4696,  4702,  4708,
    4716,  4722,  4729,  4735,  4744,  4750,  4756,  4762,  4771,  4778,
    4784,  4790,  4799,  4806,  4810,  4816,  4821,  4828,  4832,  4838,
    4842,  4848,  4852,  4858,  4862,  4870,  4881,  4884,  4890,  4893,
    4899,  4905,  4913,  4917,  4923,  4926,  4932,  4942,  4945,  4951,
    4961,  4967,  4975,  4978,  4984,  4988,  4992,  4998,  5001,  5007,
    5010,  5016,  5020,  5024,  5028,  5032,  5038,  5044,  5054,  5064,
    5068,  5072,  5078,  5084,  5092,  5096,  5100,  5104,  5108,  5112,
    5116,  5120,  5126,  5130,  5134,  5138,  5144,  5150,  5158,  5166,
    5170,  5176,  5186,  5197,  5203,  5207,  5213,  5216,  5222,  5227,
    5234,  5242,  5245,  5251,  5255,  5261,  5270,  5277,  5285,  5289,
    5295,  5301,  5309,  5312,  5318,  5323,  5333,  5341,  5351,  5357,
    5361,  5367,  5371,  5375,  5381,  5387,  5391,  5395,  5399,  5405,
    5413,  5423,  5427,  5433,  5439,  5443,  5449,  5453,  5459,  5463,
    5469,  5476,  5482,  5491,  5497,  5507,  5513,  5519,  5536,  5560,
    5579,  5583,  5587,  5593,  5596,  5597,  5598,  5599,  5600,  5601,
    5602,  5603,  5604,  5605,  5606,  5607,  5608,  5609,  5610,  5611,
    5612,  5613,  5614,  5615,  5616,  5617,  5618,  5621,  5622,  5623,
    5624,  5625,  5626,  5627,  5628,  5629,  5630,  5631,  5632,  5633,
    5634,  5635,  5636,  5637,  5638,  5639,  5640,  5641,  5642,  5643,
    5644,  5645,  5646,  5647,  5648,  5649,  5650,  5651,  5652,  5653,
    5654,  5655,  5656,  5657,  5658,  5659,  5660,  5661,  5662,  5663,
    5664,  5665,  5666,  5667,  5668,  5669,  5670,  5671,  5672,  5673,
    5674,  5675,  5676,  5677,  5678,  5679,  5680,  5681,  5682,  5683,
    5684,  5685,  5686,  5687,  5688,  5689,  5690,  5691,  5692,  5693,
    5694,  5695,  5696,  5697,  5698,  5699,  5700,  5701,  5702,  5703,
    5704,  5705,  5706,  5707,  5708,  5709,  5710,  5711,  5712,  5713,
    5714,  5715,  5716,  5717,  5718,  5719,  5720,  5721,  5722,  5723,
    5724,  5725,  5726,  5727,  5728,  5729,  5730,  5731,  5732,  5733,
    5734,  5735,  5736,  5737,  5738,  5739,  5740,  5741,  5742,  5743,
    5744,  5745,  5746,  5747,  5748,  5749,  5750,  5751,  5752,  5753,
    5754,  5755,  5756,  5757,  5758,  5759,  5760,  5761,  5762,  5763,
    5764,  5765,  5766,  5767,  5768,  5769,  5770,  5771,  5772,  5773,
    5774,  5775,  5776,  5777,  5778,  5779,  5780,  5781,  5782,  5783,
    5784,  5785,  5786,  5787,  5788,  5789,  5790,  5791,  5792,  5793,
    5794,  5795,  5796,  5797,  5798,  5799,  5800,  5801,  5802,  5803,
    5804,  5805,  5806,  5807,  5808,  5809,  5810,  5811,  5812,  5813,
    5814,  5815,  5816,  5817,  5818,  5819,  5820,  5821,  5824
  };

  // Print the state stack on the debug stream.
  void
  xquery_parser::yystack_print_ ()
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
  xquery_parser::yy_reduce_print_ (int yyrule)
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
    const unsigned int user_token_number_max_ = 588;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // zorba
#line 15737 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.cpp" // lalr1.cc:1155
#line 5826 "/home/federico/zorba/build/src/compiler/parser/xquery_parser.y" // lalr1.cc:1156

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
