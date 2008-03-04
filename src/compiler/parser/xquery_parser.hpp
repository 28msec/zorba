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
#line 30 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"


#include <zorba/common/common.h>

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

//#include "context/static_context.h"
#include "zorba/zorba_api.h"
#include "context/dynamic_context.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include <zorba/static_context_consts.h>
#include "types/typemanager.h"


using namespace std;
using namespace xqp;

namespace xqp {
	class xquery_driver;
	class parsenode;
	class exprnode;
}

#define YYDEBUG 1



/* Line 35 of lalr1.cc.  */
#line 89 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.hpp"

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
#line 112 "/home/dagraf/Work/28msec/zorba3/xquery/src/compiler/parser/xquery_parser.y"
{
  xqp::parsenode * node;
  xqp::exprnode * expr;
  off_t sval;
	xqp_integer* ival;
	xqp_double* dval;
	xqp_decimal* decval;
}
/* Line 35 of lalr1.cc.  */
#line 150 "/home/dagraf/Work/28msec/zorba3/xquery/build/src/compiler/parser/xquery_parser.hpp"
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
     ELEMENT_CONTENT = 264,
     ELEMENT_QNAME_LBRACE = 265,
     ELEM_WILDCARD = 266,
     ENTITY_REF = 267,
     EXPR_COMMENT_LITERAL = 268,
     NCNAME = 269,
     PI_NCNAME_LBRACE = 270,
     PI_TARGET_LITERAL = 271,
     PRAGMA_LITERAL_AND_END = 272,
     PREFIX_WILDCARD = 273,
     QNAME = 274,
     QNAME_AND_END_PRAGMA = 275,
     QNAME_LPAR = 276,
     QUOTE_ATTR_CONTENT = 277,
     STRING_LITERAL = 278,
     URI_LITERAL = 279,
     VARNAME = 280,
     VALIDATE_MODE = 281,
     XML_COMMENT_LITERAL = 282,
     ANCESTOR_AXIS = 283,
     ANCESTOR_OR_SELF_AXIS = 284,
     AND = 285,
     APOS = 286,
     AS = 287,
     ASCENDING = 288,
     AT = 289,
     ATTRIBUTE = 290,
     ATTRIBUTE_AXIS = 291,
     ATTRIBUTE_LBRACE = 292,
     ATTRIBUTE_LPAR = 293,
     AT_SIGN = 294,
     CASE = 295,
     CASTABLE_AS = 296,
     CAST_AS = 297,
     CDATA_BEGIN = 298,
     CDATA_END = 299,
     CHILD_AXIS = 300,
     COLLATION = 301,
     COMMA = 302,
     COMMENT_BEGIN = 303,
     COMMENT_END = 304,
     COMMENT_LBRACE = 305,
     COMMENT_LPAR = 306,
     DECIMAL_LITERAL = 307,
     DECLARE_BASE_URI = 308,
     DECLARE_BOUNDARY_SPACE = 309,
     DECLARE_CONSTRUCTION = 310,
     DECLARE_COPY_NAMESPACES = 311,
     DECLARE_DEFAULT_COLLATION = 312,
     DECLARE_DEFAULT_ELEMENT = 313,
     DECLARE_DEFAULT_FUNCTION = 314,
     DECLARE_DEFAULT_ORDER = 315,
     DECLARE_FUNCTION = 316,
     DECLARE_NAMESPACE = 317,
     DECLARE_OPTION = 318,
     DECLARE_ORDERING = 319,
     DECLARE_UPDATING_FUNCTION = 320,
     DECLARE_VARIABLE_DOLLAR = 321,
     DEFAULT = 322,
     DEFAULT_ELEMENT = 323,
     DESCENDANT_AXIS = 324,
     DESCENDANT_OR_SELF_AXIS = 325,
     DESCENDING = 326,
     DIV = 327,
     DOCUMENT_LBRACE = 328,
     DOCUMENT_NODE_LPAR = 329,
     DOLLAR = 330,
     DOT = 331,
     DOT_DOT = 332,
     DOUBLE_LBRACE = 333,
     DOUBLE_LITERAL = 334,
     DOUBLE_RBRACE = 335,
     ELEMENT_LBRACE = 336,
     ELEMENT_LPAR = 337,
     ELSE = 338,
     EMPTY_GREATEST = 339,
     EMPTY_LEAST = 340,
     EMPTY_TAG_END = 341,
     ENCODING = 342,
     EQUALS = 343,
     ESCAPE_APOS = 344,
     ESCAPE_QUOTE = 345,
     EVERY_DOLLAR = 346,
     EXCEPT = 347,
     EXTERNAL = 348,
     FOLLOWING_AXIS = 349,
     FOLLOWING_SIBLING_AXIS = 350,
     FOLLOWS = 351,
     FOR_DOLLAR = 352,
     GENERALCOMP = 353,
     GE = 354,
     GETS = 355,
     GT = 356,
     HOOK = 357,
     IDIV = 358,
     IF_LPAR = 359,
     IMPORT_MODULE = 360,
     IMPORT_SCHEMA = 361,
     _IN_ = 362,
     INHERIT = 363,
     INSTANCE_OF = 364,
     INTEGER_LITERAL = 365,
     INTERSECT = 366,
     IS = 367,
     ITEM_TEST = 368,
     LBRACE = 369,
     LBRACK = 370,
     LE = 371,
     LEADING_LONE_SLASH = 372,
     LET_DOLLAR = 373,
     LET_SCORE_DOLLAR = 374,
     LPAR = 375,
     LT = 376,
     MINUS = 377,
     MOD = 378,
     MODULE_NAMESPACE = 379,
     NAMESPACE = 380,
     _NAN = 381,
     NE = 382,
     NODECOMP = 383,
     NODE_LPAR = 384,
     NOT_OPERATOR_KEYWORD = 385,
     NO_INHERIT = 386,
     NO_PRESERVE = 387,
     OCCURS_HOOK = 388,
     OCCURS_PLUS = 389,
     OCCURS_STAR = 390,
     OR = 391,
     ORDERED = 392,
     ORDERED_LBRACE = 393,
     ORDER_BY = 394,
     PARENT_AXIS = 395,
     PI_BEGIN = 396,
     PI_END = 397,
     PI_LBRACE = 398,
     PI_LPAR = 399,
     PI_TARGET = 400,
     PLUS = 401,
     PRAGMA_BEGIN = 402,
     PRAGMA_END = 403,
     PRECEDES = 404,
     PRECEDING_AXIS = 405,
     PRECEDING_SIBLING_AXIS = 406,
     PRESERVE = 407,
     PROCESSING_INSTRUCTION = 408,
     QUOTE = 409,
     RBRACE = 410,
     RBRACK = 411,
     RETURN = 412,
     RPAR = 413,
     RPAR_AS = 414,
     SATISFIES = 415,
     SCHEMA_ATTRIBUTE_LPAR = 416,
     SCHEMA_ELEMENT_LPAR = 417,
     SELF_AXIS = 418,
     SEMI = 419,
     SLASH = 420,
     SLASH_SLASH = 421,
     SOME_DOLLAR = 422,
     STABLE_ORDER_BY = 423,
     STAR = 424,
     START_TAG_END = 425,
     START_TAG = 426,
     STRIP = 427,
     TAG_END = 428,
     TEXT_LBRACE = 429,
     TEXT_LPAR = 430,
     THEN = 431,
     TO = 432,
     TREAT_AS = 433,
     TYPESWITCH_LPAR = 434,
     UNION = 435,
     UNORDERED = 436,
     UNORDERED_LBRACE = 437,
     UNRECOGNIZED = 438,
     VAL_EQ = 439,
     VAL_GE = 440,
     VAL_GT = 441,
     VAL_LE = 442,
     VAL_LT = 443,
     VAL_NE = 444,
     VALIDATE_LBRACE = 445,
     VALUECOMP = 446,
     VBAR = 447,
     VOID_TEST = 448,
     WHERE = 449,
     XML_COMMENT_BEGIN = 450,
     XML_COMMENT_END = 451,
     XQUERY_VERSION = 452,
     AFTER = 453,
     BEFORE = 454,
     DECLARE_REVALIDATION = 455,
     REVAL_STRICT = 456,
     REVAL_LAX = 457,
     REVAL_SKIP = 458,
     DELETE_NODE = 459,
     DELETE_NODES = 460,
     INSERT_NODE = 461,
     INSERT_NODES = 462,
     RENAME = 463,
     REPLACE = 464,
     REPLACE_VALUE_OF = 465,
     FIRST_INTO = 466,
     INTO = 467,
     LAST_INTO = 468,
     MODIFY = 469,
     COPY_DOLLAR = 470,
     WITH = 471,
     TRY = 472,
     CATCH_LPAR = 473,
     ALL = 474,
     ALL_WORDS = 475,
     ANY = 476,
     ANY_WORD = 477,
     AT_END = 478,
     AT_LEAST = 479,
     AT_MOST = 480,
     AT_START = 481,
     CASE_INSENSITIVE = 482,
     CASE_SENSITIVE = 483,
     DECLARE_FTOPTION = 484,
     DIACRITICS_INSENSITIVE = 485,
     DIACRITICS_SENSITIVE = 486,
     DIFFERENT = 487,
     DISTANCE = 488,
     ENTIRE_CONTENT = 489,
     EXACTLY = 490,
     FROM = 491,
     FTAND = 492,
     FTCONTAINS = 493,
     FTNOT = 494,
     FTOR = 495,
     LANGUAGE = 496,
     LEVELS = 497,
     LOWERCASE = 498,
     FTNOT_IN = 499,
     OCCURS = 500,
     PARAGRAPH = 501,
     PHRASE = 502,
     RELATIONSHIP = 503,
     SAME = 504,
     SCORE = 505,
     SENTENCE = 506,
     SENTENCES = 507,
     TIMES = 508,
     UPPERCASE = 509,
     WEIGHT = 510,
     WINDOW = 511,
     WITHOUT_CONTENT = 512,
     WITHOUT_DIACRITICS = 513,
     WITHOUT_STEMMING = 514,
     WITHOUT_STOP_WORDS = 515,
     WITHOUT_THESAURUS = 516,
     WITHOUT_WILDCARDS = 517,
     WITH_DEFAULT_STOP_WORDS = 518,
     WITH_DIACRITICS = 519,
     WITH_STEMMING = 520,
     WITH_STOP_WORDS = 521,
     WITH_THESAURUS = 522,
     WITH_WILDCARDS = 523,
     WORDS = 524,
     FTCONTAINS_REDUCE = 525,
     RANGE_REDUCE = 526,
     ADDITIVE_REDUCE = 527,
     MULTIPLICATIVE_REDUCE = 528,
     UNION_REDUCE = 529,
     INTERSECT_EXCEPT_REDUCE = 530,
     QVARINDECLLIST_REDUCE = 531,
     COMMA_DOLLAR = 532,
     UNARY_PREC = 533,
     SEQUENCE_TYPE_REDUCE = 534,
     STEP_REDUCE = 535
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
