/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef PARSER_HEADER_H
# define PARSER_HEADER_H

#include <string>
#include <iostream>
#include "stack.hh"

namespace yy
{
  class position;
  class location;
}

/* First part of user declarations.  */
#line 30 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#ifdef WIN32
#include "util/win32/compatib_defs.h"
#ifndef _WIN32_WCE
#include <io.h>
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

//#include "context/static_context.h"
#include "zorba_api.h"
#include "context/dynamic_context.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"


using namespace std;
using namespace xqp;

namespace xqp {
	class xquery_driver;
	class parsenode;
	class exprnode;
}


#ifndef NDEBUG

#ifdef PARSER_DEBUG
static bool debug = true;
#else
static bool debug = false;
#endif

#else
static bool debug = false;
#endif



/* Line 303 of lalr1.cc.  */
#line 102 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.hpp"

#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
do {							\
  if (N)						\
    {							\
      (Current).begin = (Rhs)[1].begin;			\
      (Current).end   = (Rhs)[N].end;			\
    }							\
  else							\
    {							\
      (Current).begin = (Current).end = (Rhs)[0].end;	\
    }							\
} while (false)
#endif

namespace yy
{

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
#line 125 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
{
  xqp::parsenode * node;
  xqp::exprnode * expr;
  off_t sval;
	int ival;
	double dval;
	long double decval;
}
/* Line 303 of lalr1.cc.  */
#line 163 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.hpp"
	;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;
    /// Tokens.
    struct token
    {
      /* Tokens.  */
   enum yytokentype {
     END = 0,
     APOS_ATTR_CONTENT = 258,
     ATTRIBUTE_QNAME_LBRACE = 259,
     AT_URI_LITERAL = 260,
     CHAR_LITERAL = 261,
     CHAR_REF_LITERAL = 262,
     ELEMENT_CONTENT = 263,
     ELEMENT_QNAME_LBRACE = 264,
     ELEM_WILDCARD = 265,
     ENTITY_REF = 266,
     EXPR_COMMENT_LITERAL = 267,
     NCNAME = 268,
     PI_NCNAME_LBRACE = 269,
     PI_TARGET_LITERAL = 270,
     PRAGMA_LITERAL = 271,
     PREFIX_WILDCARD = 272,
     QNAME = 273,
     QNAME_LPAR = 274,
     QUOTE_ATTR_CONTENT = 275,
     STRING_LITERAL = 276,
     URI_LITERAL = 277,
     VARNAME = 278,
     VALIDATE_MODE = 279,
     XML_COMMENT_LITERAL = 280,
     ANCESTOR_AXIS = 281,
     ANCESTOR_OR_SELF_AXIS = 282,
     AND = 283,
     APOS = 284,
     AS = 285,
     ASCENDING = 286,
     AT = 287,
     ATTRIBUTE = 288,
     ATTRIBUTE_AXIS = 289,
     ATTRIBUTE_LBRACE = 290,
     ATTRIBUTE_LPAR = 291,
     AT_SIGN = 292,
     CASE = 293,
     CASTABLE_AS = 294,
     CAST_AS = 295,
     CDATA_BEGIN = 296,
     CDATA_END = 297,
     CHILD_AXIS = 298,
     COLLATION = 299,
     COMMA = 300,
     COMMENT_BEGIN = 301,
     COMMENT_END = 302,
     COMMENT_LBRACE = 303,
     COMMENT_LPAR = 304,
     DECIMAL_LITERAL = 305,
     DECLARE_BASE_URI = 306,
     DECLARE_BOUNDARY_SPACE = 307,
     DECLARE_CONSTRUCTION = 308,
     DECLARE_COPY_NAMESPACES = 309,
     DECLARE_DEFAULT_COLLATION = 310,
     DECLARE_DEFAULT_ELEMENT = 311,
     DECLARE_DEFAULT_FUNCTION = 312,
     DECLARE_DEFAULT_ORDER = 313,
     DECLARE_FUNCTION = 314,
     DECLARE_NAMESPACE = 315,
     DECLARE_OPTION = 316,
     DECLARE_ORDERING = 317,
     DECLARE_UPDATING_FUNCTION = 318,
     DECLARE_VARIABLE_DOLLAR = 319,
     DEFAULT = 320,
     DEFAULT_ELEMENT = 321,
     DESCENDANT_AXIS = 322,
     DESCENDANT_OR_SELF_AXIS = 323,
     DESCENDING = 324,
     DIV = 325,
     DOCUMENT_LBRACE = 326,
     DOCUMENT_NODE_LPAR = 327,
     DOLLAR = 328,
     DOT = 329,
     DOT_DOT = 330,
     DOUBLE_LBRACE = 331,
     DOUBLE_LITERAL = 332,
     DOUBLE_RBRACE = 333,
     ELEMENT_LBRACE = 334,
     ELEMENT_LPAR = 335,
     ELSE = 336,
     EMPTY_GREATEST = 337,
     EMPTY_LEAST = 338,
     EMPTY_TAG_END = 339,
     ENCODING = 340,
     EQUALS = 341,
     ESCAPE_APOS = 342,
     ESCAPE_QUOTE = 343,
     EVERY_DOLLAR = 344,
     EXCEPT = 345,
     EXTERNAL = 346,
     FOLLOWING_AXIS = 347,
     FOLLOWING_SIBLING_AXIS = 348,
     FOLLOWS = 349,
     FOR_DOLLAR = 350,
     GENERALCOMP = 351,
     GE = 352,
     GETS = 353,
     GT = 354,
     HOOK = 355,
     IDIV = 356,
     IF_LPAR = 357,
     IMPORT_MODULE = 358,
     IMPORT_SCHEMA = 359,
     _IN_ = 360,
     INHERIT = 361,
     INSTANCE_OF = 362,
     INTEGER_LITERAL = 363,
     INTERSECT = 364,
     IS = 365,
     ITEM_TEST = 366,
     LBRACE = 367,
     LBRACK = 368,
     LE = 369,
     LEADING_LONE_SLASH = 370,
     LET_DOLLAR = 371,
     LET_SCORE_DOLLAR = 372,
     LPAR = 373,
     LT = 374,
     MINUS = 375,
     MOD = 376,
     MODULE_NAMESPACE = 377,
     NAMESPACE = 378,
     _NAN = 379,
     NE = 380,
     NODECOMP = 381,
     NODE_LPAR = 382,
     NOT_OPERATOR_KEYWORD = 383,
     NO_INHERIT = 384,
     NO_PRESERVE = 385,
     OCCURS_HOOK = 386,
     OCCURS_PLUS = 387,
     OCCURS_STAR = 388,
     OR = 389,
     ORDERED = 390,
     ORDERED_LBRACE = 391,
     ORDER_BY = 392,
     PARENT_AXIS = 393,
     PI_BEGIN = 394,
     PI_END = 395,
     PI_LBRACE = 396,
     PI_LPAR = 397,
     PI_TARGET = 398,
     PLUS = 399,
     PRAGMA_BEGIN = 400,
     PRAGMA_END = 401,
     PRECEDES = 402,
     PRECEDING_AXIS = 403,
     PRECEDING_SIBLING_AXIS = 404,
     PRESERVE = 405,
     PROCESSING_INSTRUCTION = 406,
     QUOTE = 407,
     RBRACE = 408,
     RBRACK = 409,
     RETURN = 410,
     RPAR = 411,
     RPAR_AS = 412,
     SATISFIES = 413,
     SCHEMA_ATTRIBUTE_LPAR = 414,
     SCHEMA_ELEMENT_LPAR = 415,
     SELF_AXIS = 416,
     SEMI = 417,
     SLASH = 418,
     SLASH_SLASH = 419,
     SOME_DOLLAR = 420,
     STABLE_ORDER_BY = 421,
     STAR = 422,
     START_TAG_END = 423,
     START_TAG = 424,
     STRIP = 425,
     TAG_END = 426,
     TEXT_LBRACE = 427,
     TEXT_LPAR = 428,
     THEN = 429,
     TO = 430,
     TREAT_AS = 431,
     TYPESWITCH_LPAR = 432,
     UNION = 433,
     UNORDERED = 434,
     UNORDERED_LBRACE = 435,
     UNRECOGNIZED = 436,
     VAL_EQ = 437,
     VAL_GE = 438,
     VAL_GT = 439,
     VAL_LE = 440,
     VAL_LT = 441,
     VAL_NE = 442,
     VALIDATE_LBRACE = 443,
     VALUECOMP = 444,
     VBAR = 445,
     VOID_TEST = 446,
     WHERE = 447,
     XML_COMMENT_BEGIN = 448,
     XML_COMMENT_END = 449,
     XQUERY_VERSION = 450,
     AFTER = 451,
     BEFORE = 452,
     COMMA_DOLLAR = 453,
     DECLARE_REVALIDATION_MODE = 454,
     DO_DELETE = 455,
     DO_INSERT = 456,
     DO_RENAME = 457,
     DO_REPLACE = 458,
     FIRST_INTO = 459,
     INTO = 460,
     LAST_INTO = 461,
     MODIFY = 462,
     TRANSFORM_COPY_DOLLAR = 463,
     VALUE_OF = 464,
     WITH = 465,
     ALL = 466,
     ALL_WORDS = 467,
     ANY = 468,
     ANY_WORD = 469,
     AT_END = 470,
     AT_LEAST = 471,
     AT_MOST = 472,
     AT_START = 473,
     CASE_INSENSITIVE = 474,
     CASE_SENSITIVE = 475,
     DECLARE_FTOPTION = 476,
     DIACRITICS_INSENSITIVE = 477,
     DIACRITICS_SENSITIVE = 478,
     DIFFERENT = 479,
     DISTANCE = 480,
     ENTIRE_CONTENT = 481,
     EXACTLY = 482,
     FROM = 483,
     FTAND = 484,
     FTCONTAINS = 485,
     FTNOT = 486,
     FTOR = 487,
     LANGUAGE = 488,
     LEVELS = 489,
     LOWERCASE = 490,
     FTNOT_IN = 491,
     OCCURS = 492,
     PARAGRAPH = 493,
     PHRASE = 494,
     RELATIONSHIP = 495,
     SAME = 496,
     SCORE = 497,
     SENTENCE = 498,
     SENTENCES = 499,
     TIMES = 500,
     UPPERCASE = 501,
     WEIGHT = 502,
     WINDOW = 503,
     WITHOUT_CONTENT = 504,
     WITHOUT_DIACRITICS = 505,
     WITHOUT_STEMMING = 506,
     WITHOUT_STOP_WORDS = 507,
     WITHOUT_THESAURUS = 508,
     WITHOUT_WILDCARDS = 509,
     WITH_DEFAULT_STOP_WORDS = 510,
     WITH_DIACRITICS = 511,
     WITH_STEMMING = 512,
     WITH_STOP_WORDS = 513,
     WITH_THESAURUS = 514,
     WITH_WILDCARDS = 515,
     WORDS = 516,
     FTCONTAINS_REDUCE = 517,
     RANGE_REDUCE = 518,
     ADDITIVE_REDUCE = 519,
     MULTIPLICATIVE_REDUCE = 520,
     UNION_REDUCE = 521,
     INTERSECT_EXCEPT_REDUCE = 522,
     QVARINDECLLIST_REDUCE = 523,
     UNARY_PREC = 524,
     SEQUENCE_TYPE_REDUCE = 525,
     STEP_REDUCE = 526
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    xquery_parser (xquery_driver& driver_yyarg, void* yyscanner_yyarg);
    virtual ~xquery_parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the look-ahead token.
    virtual std::string yysyntax_error_ (int yystate);

#if YYDEBUG
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
					 const semantic_type* yyvaluep,
					 const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
				   const semantic_type* yyvaluep,
				   const location_type* yylocationp);
#endif /* ! YYDEBUG */


    /// State numbers.
    typedef int state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Internal symbol numbers.
    typedef unsigned short int token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const short int yypact_ninf_;

    /// For a state, default rule to reduce.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned short int yydefact_[];

    static const short int yypgoto_[];
    static const short int yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const unsigned short int yytable_[];
    static const signed char yytable_ninf_;

    static const short int yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned short int yystos_[];

    /// For a rule, its LHS.
    static const unsigned short int yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[];

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif

#if YYERROR_VERBOSE
    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    virtual std::string yytnamerr_ (const char *n);
#endif

#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef short int rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned short int yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned short int yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
			     int yytype,
			     semantic_type* yyvaluep,
			     location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;


    /* User arguments.  */
    xquery_driver& driver;
    void* yyscanner;
  };
}


#endif /* ! defined PARSER_HEADER_H */
