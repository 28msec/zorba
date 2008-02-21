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


#include "zorba/common/common.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include "zorba/common/common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

//#include "context/static_context.h"
#include "zorba_api.h"
#include "context/dynamic_context.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "types/typemanager.h"


using namespace std;
using namespace xqp;

namespace xqp {
	class xquery_driver;
	class parsenode;
	class exprnode;
}




/* Line 303 of lalr1.cc.  */
#line 89 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.hpp"

#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 112 "/Users/mbrantner/misc/code/vanilla/xquery/src/compiler/parser/xquery_parser.y"
{
  xqp::parsenode * node;
  xqp::exprnode * expr;
  off_t sval;
	xqp_integer* ival;
	xqp_double* dval;
	xqp_decimal* decval;
}
/* Line 303 of lalr1.cc.  */
#line 150 "/Users/mbrantner/misc/code/vanilla/xquery/build/src/compiler/parser/xquery_parser.hpp"
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
     CHAR_LITERAL_AND_CDATA_END = 262,
     CHAR_LITERAL_AND_PI_END = 263,
     CHAR_REF_LITERAL = 264,
     ELEMENT_CONTENT = 265,
     ELEMENT_QNAME_LBRACE = 266,
     ELEM_WILDCARD = 267,
     ENTITY_REF = 268,
     EXPR_COMMENT_LITERAL = 269,
     NCNAME = 270,
     PI_NCNAME_LBRACE = 271,
     PI_TARGET_LITERAL = 272,
     PRAGMA_LITERAL_AND_END = 273,
     PREFIX_WILDCARD = 274,
     QNAME = 275,
     QNAME_AND_END_PRAGMA = 276,
     QNAME_LPAR = 277,
     QUOTE_ATTR_CONTENT = 278,
     STRING_LITERAL = 279,
     URI_LITERAL = 280,
     VARNAME = 281,
     VALIDATE_MODE = 282,
     XML_COMMENT_LITERAL = 283,
     ANCESTOR_AXIS = 284,
     ANCESTOR_OR_SELF_AXIS = 285,
     AND = 286,
     APOS = 287,
     AS = 288,
     ASCENDING = 289,
     AT = 290,
     ATTRIBUTE = 291,
     ATTRIBUTE_AXIS = 292,
     ATTRIBUTE_LBRACE = 293,
     ATTRIBUTE_LPAR = 294,
     AT_SIGN = 295,
     CASE = 296,
     CASTABLE_AS = 297,
     CAST_AS = 298,
     CDATA_BEGIN = 299,
     CDATA_END = 300,
     CHILD_AXIS = 301,
     COLLATION = 302,
     COMMA = 303,
     COMMENT_BEGIN = 304,
     COMMENT_END = 305,
     COMMENT_LBRACE = 306,
     COMMENT_LPAR = 307,
     DECIMAL_LITERAL = 308,
     DECLARE_BASE_URI = 309,
     DECLARE_BOUNDARY_SPACE = 310,
     DECLARE_CONSTRUCTION = 311,
     DECLARE_COPY_NAMESPACES = 312,
     DECLARE_DEFAULT_COLLATION = 313,
     DECLARE_DEFAULT_ELEMENT = 314,
     DECLARE_DEFAULT_FUNCTION = 315,
     DECLARE_DEFAULT_ORDER = 316,
     DECLARE_FUNCTION = 317,
     DECLARE_NAMESPACE = 318,
     DECLARE_OPTION = 319,
     DECLARE_ORDERING = 320,
     DECLARE_UPDATING_FUNCTION = 321,
     DECLARE_VARIABLE_DOLLAR = 322,
     DEFAULT = 323,
     DEFAULT_ELEMENT = 324,
     DESCENDANT_AXIS = 325,
     DESCENDANT_OR_SELF_AXIS = 326,
     DESCENDING = 327,
     DIV = 328,
     DOCUMENT_LBRACE = 329,
     DOCUMENT_NODE_LPAR = 330,
     DOLLAR = 331,
     DOT = 332,
     DOT_DOT = 333,
     DOUBLE_LBRACE = 334,
     DOUBLE_LITERAL = 335,
     DOUBLE_RBRACE = 336,
     ELEMENT_LBRACE = 337,
     ELEMENT_LPAR = 338,
     ELSE = 339,
     EMPTY_GREATEST = 340,
     EMPTY_LEAST = 341,
     EMPTY_TAG_END = 342,
     ENCODING = 343,
     EQUALS = 344,
     ESCAPE_APOS = 345,
     ESCAPE_QUOTE = 346,
     EVERY_DOLLAR = 347,
     EXCEPT = 348,
     EXTERNAL = 349,
     FOLLOWING_AXIS = 350,
     FOLLOWING_SIBLING_AXIS = 351,
     FOLLOWS = 352,
     FOR_DOLLAR = 353,
     GENERALCOMP = 354,
     GE = 355,
     GETS = 356,
     GT = 357,
     HOOK = 358,
     IDIV = 359,
     IF_LPAR = 360,
     IMPORT_MODULE = 361,
     IMPORT_SCHEMA = 362,
     _IN_ = 363,
     INHERIT = 364,
     INSTANCE_OF = 365,
     INTEGER_LITERAL = 366,
     INTERSECT = 367,
     IS = 368,
     ITEM_TEST = 369,
     LBRACE = 370,
     LBRACK = 371,
     LE = 372,
     LEADING_LONE_SLASH = 373,
     LET_DOLLAR = 374,
     LET_SCORE_DOLLAR = 375,
     LPAR = 376,
     LT = 377,
     MINUS = 378,
     MOD = 379,
     MODULE_NAMESPACE = 380,
     NAMESPACE = 381,
     _NAN = 382,
     NE = 383,
     NODECOMP = 384,
     NODE_LPAR = 385,
     NOT_OPERATOR_KEYWORD = 386,
     NO_INHERIT = 387,
     NO_PRESERVE = 388,
     OCCURS_HOOK = 389,
     OCCURS_PLUS = 390,
     OCCURS_STAR = 391,
     OR = 392,
     ORDERED = 393,
     ORDERED_LBRACE = 394,
     ORDER_BY = 395,
     PARENT_AXIS = 396,
     PI_BEGIN = 397,
     PI_END = 398,
     PI_LBRACE = 399,
     PI_LPAR = 400,
     PI_TARGET = 401,
     PLUS = 402,
     PRAGMA_BEGIN = 403,
     PRAGMA_END = 404,
     PRECEDES = 405,
     PRECEDING_AXIS = 406,
     PRECEDING_SIBLING_AXIS = 407,
     PRESERVE = 408,
     PROCESSING_INSTRUCTION = 409,
     QUOTE = 410,
     RBRACE = 411,
     RBRACK = 412,
     RETURN = 413,
     RPAR = 414,
     RPAR_AS = 415,
     SATISFIES = 416,
     SCHEMA_ATTRIBUTE_LPAR = 417,
     SCHEMA_ELEMENT_LPAR = 418,
     SELF_AXIS = 419,
     SEMI = 420,
     SLASH = 421,
     SLASH_SLASH = 422,
     SOME_DOLLAR = 423,
     STABLE_ORDER_BY = 424,
     STAR = 425,
     START_TAG_END = 426,
     START_TAG = 427,
     STRIP = 428,
     TAG_END = 429,
     TEXT_LBRACE = 430,
     TEXT_LPAR = 431,
     THEN = 432,
     TO = 433,
     TREAT_AS = 434,
     TYPESWITCH_LPAR = 435,
     UNION = 436,
     UNORDERED = 437,
     UNORDERED_LBRACE = 438,
     UNRECOGNIZED = 439,
     VAL_EQ = 440,
     VAL_GE = 441,
     VAL_GT = 442,
     VAL_LE = 443,
     VAL_LT = 444,
     VAL_NE = 445,
     VALIDATE_LBRACE = 446,
     VALUECOMP = 447,
     VBAR = 448,
     VOID_TEST = 449,
     WHERE = 450,
     XML_COMMENT_BEGIN = 451,
     XML_COMMENT_END = 452,
     XQUERY_VERSION = 453,
     AFTER = 454,
     BEFORE = 455,
     COMMA_DOLLAR = 456,
     DECLARE_REVALIDATION_MODE = 457,
     DO_DELETE = 458,
     DO_INSERT = 459,
     DO_RENAME = 460,
     DO_REPLACE = 461,
     FIRST_INTO = 462,
     INTO = 463,
     LAST_INTO = 464,
     MODIFY = 465,
     TRANSFORM_COPY_DOLLAR = 466,
     VALUE_OF = 467,
     WITH = 468,
     ALL = 469,
     ALL_WORDS = 470,
     ANY = 471,
     ANY_WORD = 472,
     AT_END = 473,
     AT_LEAST = 474,
     AT_MOST = 475,
     AT_START = 476,
     CASE_INSENSITIVE = 477,
     CASE_SENSITIVE = 478,
     DECLARE_FTOPTION = 479,
     DIACRITICS_INSENSITIVE = 480,
     DIACRITICS_SENSITIVE = 481,
     DIFFERENT = 482,
     DISTANCE = 483,
     ENTIRE_CONTENT = 484,
     EXACTLY = 485,
     FROM = 486,
     FTAND = 487,
     FTCONTAINS = 488,
     FTNOT = 489,
     FTOR = 490,
     LANGUAGE = 491,
     LEVELS = 492,
     LOWERCASE = 493,
     FTNOT_IN = 494,
     OCCURS = 495,
     PARAGRAPH = 496,
     PHRASE = 497,
     RELATIONSHIP = 498,
     SAME = 499,
     SCORE = 500,
     SENTENCE = 501,
     SENTENCES = 502,
     TIMES = 503,
     UPPERCASE = 504,
     WEIGHT = 505,
     WINDOW = 506,
     WITHOUT_CONTENT = 507,
     WITHOUT_DIACRITICS = 508,
     WITHOUT_STEMMING = 509,
     WITHOUT_STOP_WORDS = 510,
     WITHOUT_THESAURUS = 511,
     WITHOUT_WILDCARDS = 512,
     WITH_DEFAULT_STOP_WORDS = 513,
     WITH_DIACRITICS = 514,
     WITH_STEMMING = 515,
     WITH_STOP_WORDS = 516,
     WITH_THESAURUS = 517,
     WITH_WILDCARDS = 518,
     WORDS = 519,
     FTCONTAINS_REDUCE = 520,
     RANGE_REDUCE = 521,
     ADDITIVE_REDUCE = 522,
     MULTIPLICATIVE_REDUCE = 523,
     UNION_REDUCE = 524,
     INTERSECT_EXCEPT_REDUCE = 525,
     QVARINDECLLIST_REDUCE = 526,
     UNARY_PREC = 527,
     SEQUENCE_TYPE_REDUCE = 528,
     STEP_REDUCE = 529
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
