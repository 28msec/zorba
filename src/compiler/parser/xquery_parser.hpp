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
#line 30 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"


#include "zorba/common.h"

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




/* Line 35 of lalr1.cc.  */
#line 93 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.hpp"

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
#line 116 "/usr/local/src/zorba/src/compiler/parser/xquery_parser.y"
{
  xqp::parsenode * node;
  xqp::exprnode * expr;
  off_t sval;
	int ival;
	double dval;
	long double decval;
}
/* Line 35 of lalr1.cc.  */
#line 154 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.hpp"
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
     CHAR_LITERAL_AND_PI_END = 262,
     CHAR_REF_LITERAL = 263,
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
     QNAME_LPAR = 275,
     QUOTE_ATTR_CONTENT = 276,
     STRING_LITERAL = 277,
     URI_LITERAL = 278,
     VARNAME = 279,
     VALIDATE_MODE = 280,
     XML_COMMENT_LITERAL = 281,
     ANCESTOR_AXIS = 282,
     ANCESTOR_OR_SELF_AXIS = 283,
     AND = 284,
     APOS = 285,
     AS = 286,
     ASCENDING = 287,
     AT = 288,
     ATTRIBUTE = 289,
     ATTRIBUTE_AXIS = 290,
     ATTRIBUTE_LBRACE = 291,
     ATTRIBUTE_LPAR = 292,
     AT_SIGN = 293,
     CASE = 294,
     CASTABLE_AS = 295,
     CAST_AS = 296,
     CDATA_BEGIN = 297,
     CDATA_END = 298,
     CHILD_AXIS = 299,
     COLLATION = 300,
     COMMA = 301,
     COMMENT_BEGIN = 302,
     COMMENT_END = 303,
     COMMENT_LBRACE = 304,
     COMMENT_LPAR = 305,
     DECIMAL_LITERAL = 306,
     DECLARE_BASE_URI = 307,
     DECLARE_BOUNDARY_SPACE = 308,
     DECLARE_CONSTRUCTION = 309,
     DECLARE_COPY_NAMESPACES = 310,
     DECLARE_DEFAULT_COLLATION = 311,
     DECLARE_DEFAULT_ELEMENT = 312,
     DECLARE_DEFAULT_FUNCTION = 313,
     DECLARE_DEFAULT_ORDER = 314,
     DECLARE_FUNCTION = 315,
     DECLARE_NAMESPACE = 316,
     DECLARE_OPTION = 317,
     DECLARE_ORDERING = 318,
     DECLARE_UPDATING_FUNCTION = 319,
     DECLARE_VARIABLE_DOLLAR = 320,
     DEFAULT = 321,
     DEFAULT_ELEMENT = 322,
     DESCENDANT_AXIS = 323,
     DESCENDANT_OR_SELF_AXIS = 324,
     DESCENDING = 325,
     DIV = 326,
     DOCUMENT_LBRACE = 327,
     DOCUMENT_NODE_LPAR = 328,
     DOLLAR = 329,
     DOT = 330,
     DOT_DOT = 331,
     DOUBLE_LBRACE = 332,
     DOUBLE_LITERAL = 333,
     DOUBLE_RBRACE = 334,
     ELEMENT_LBRACE = 335,
     ELEMENT_LPAR = 336,
     ELSE = 337,
     EMPTY_GREATEST = 338,
     EMPTY_LEAST = 339,
     EMPTY_TAG_END = 340,
     ENCODING = 341,
     EQUALS = 342,
     ESCAPE_APOS = 343,
     ESCAPE_QUOTE = 344,
     EVERY_DOLLAR = 345,
     EXCEPT = 346,
     EXTERNAL = 347,
     FOLLOWING_AXIS = 348,
     FOLLOWING_SIBLING_AXIS = 349,
     FOLLOWS = 350,
     FOR_DOLLAR = 351,
     GENERALCOMP = 352,
     GE = 353,
     GETS = 354,
     GT = 355,
     HOOK = 356,
     IDIV = 357,
     IF_LPAR = 358,
     IMPORT_MODULE = 359,
     IMPORT_SCHEMA = 360,
     _IN_ = 361,
     INHERIT = 362,
     INSTANCE_OF = 363,
     INTEGER_LITERAL = 364,
     INTERSECT = 365,
     IS = 366,
     ITEM_TEST = 367,
     LBRACE = 368,
     LBRACK = 369,
     LE = 370,
     LEADING_LONE_SLASH = 371,
     LET_DOLLAR = 372,
     LET_SCORE_DOLLAR = 373,
     LPAR = 374,
     LT = 375,
     MINUS = 376,
     MOD = 377,
     MODULE_NAMESPACE = 378,
     NAMESPACE = 379,
     _NAN = 380,
     NE = 381,
     NODECOMP = 382,
     NODE_LPAR = 383,
     NOT_OPERATOR_KEYWORD = 384,
     NO_INHERIT = 385,
     NO_PRESERVE = 386,
     OCCURS_HOOK = 387,
     OCCURS_PLUS = 388,
     OCCURS_STAR = 389,
     OR = 390,
     ORDERED = 391,
     ORDERED_LBRACE = 392,
     ORDER_BY = 393,
     PARENT_AXIS = 394,
     PI_BEGIN = 395,
     PI_END = 396,
     PI_LBRACE = 397,
     PI_LPAR = 398,
     PI_TARGET = 399,
     PLUS = 400,
     PRAGMA_BEGIN = 401,
     PRAGMA_END = 402,
     PRECEDES = 403,
     PRECEDING_AXIS = 404,
     PRECEDING_SIBLING_AXIS = 405,
     PRESERVE = 406,
     PROCESSING_INSTRUCTION = 407,
     QUOTE = 408,
     RBRACE = 409,
     RBRACK = 410,
     RETURN = 411,
     RPAR = 412,
     RPAR_AS = 413,
     SATISFIES = 414,
     SCHEMA_ATTRIBUTE_LPAR = 415,
     SCHEMA_ELEMENT_LPAR = 416,
     SELF_AXIS = 417,
     SEMI = 418,
     SLASH = 419,
     SLASH_SLASH = 420,
     SOME_DOLLAR = 421,
     STABLE_ORDER_BY = 422,
     STAR = 423,
     START_TAG_END = 424,
     START_TAG = 425,
     STRIP = 426,
     TAG_END = 427,
     TEXT_LBRACE = 428,
     TEXT_LPAR = 429,
     THEN = 430,
     TO = 431,
     TREAT_AS = 432,
     TYPESWITCH_LPAR = 433,
     UNION = 434,
     UNORDERED = 435,
     UNORDERED_LBRACE = 436,
     UNRECOGNIZED = 437,
     VAL_EQ = 438,
     VAL_GE = 439,
     VAL_GT = 440,
     VAL_LE = 441,
     VAL_LT = 442,
     VAL_NE = 443,
     VALIDATE_LBRACE = 444,
     VALUECOMP = 445,
     VBAR = 446,
     VOID_TEST = 447,
     WHERE = 448,
     XML_COMMENT_BEGIN = 449,
     XML_COMMENT_END = 450,
     XQUERY_VERSION = 451,
     AFTER = 452,
     BEFORE = 453,
     COMMA_DOLLAR = 454,
     DECLARE_REVALIDATION_MODE = 455,
     DO_DELETE = 456,
     DO_INSERT = 457,
     DO_RENAME = 458,
     DO_REPLACE = 459,
     FIRST_INTO = 460,
     INTO = 461,
     LAST_INTO = 462,
     MODIFY = 463,
     TRANSFORM_COPY_DOLLAR = 464,
     VALUE_OF = 465,
     WITH = 466,
     ALL = 467,
     ALL_WORDS = 468,
     ANY = 469,
     ANY_WORD = 470,
     AT_END = 471,
     AT_LEAST = 472,
     AT_MOST = 473,
     AT_START = 474,
     CASE_INSENSITIVE = 475,
     CASE_SENSITIVE = 476,
     DECLARE_FTOPTION = 477,
     DIACRITICS_INSENSITIVE = 478,
     DIACRITICS_SENSITIVE = 479,
     DIFFERENT = 480,
     DISTANCE = 481,
     ENTIRE_CONTENT = 482,
     EXACTLY = 483,
     FROM = 484,
     FTAND = 485,
     FTCONTAINS = 486,
     FTNOT = 487,
     FTOR = 488,
     LANGUAGE = 489,
     LEVELS = 490,
     LOWERCASE = 491,
     FTNOT_IN = 492,
     OCCURS = 493,
     PARAGRAPH = 494,
     PHRASE = 495,
     RELATIONSHIP = 496,
     SAME = 497,
     SCORE = 498,
     SENTENCE = 499,
     SENTENCES = 500,
     TIMES = 501,
     UPPERCASE = 502,
     WEIGHT = 503,
     WINDOW = 504,
     WITHOUT_CONTENT = 505,
     WITHOUT_DIACRITICS = 506,
     WITHOUT_STEMMING = 507,
     WITHOUT_STOP_WORDS = 508,
     WITHOUT_THESAURUS = 509,
     WITHOUT_WILDCARDS = 510,
     WITH_DEFAULT_STOP_WORDS = 511,
     WITH_DIACRITICS = 512,
     WITH_STEMMING = 513,
     WITH_STOP_WORDS = 514,
     WITH_THESAURUS = 515,
     WITH_WILDCARDS = 516,
     WORDS = 517,
     FTCONTAINS_REDUCE = 518,
     RANGE_REDUCE = 519,
     ADDITIVE_REDUCE = 520,
     MULTIPLICATIVE_REDUCE = 521,
     UNION_REDUCE = 522,
     INTERSECT_EXCEPT_REDUCE = 523,
     QVARINDECLLIST_REDUCE = 524,
     UNARY_PREC = 525,
     SEQUENCE_TYPE_REDUCE = 526,
     STEP_REDUCE = 527
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
