/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2013 Free Software Foundation, Inc.
   
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

/**
 ** \file /Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.hpp
 ** Define the zorba::parser class.
 */

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef YY_ZORBA_USERS_PJL_SRC_FLWOR_ZORBA_REPO_SKIPLIMIT_ZORBA_BUILD_SRC_COMPILER_PARSER_XQUERY_PARSER_HPP_INCLUDED
# define YY_ZORBA_USERS_PJL_SRC_FLWOR_ZORBA_REPO_SKIPLIMIT_ZORBA_BUILD_SRC_COMPILER_PARSER_XQUERY_PARSER_HPP_INCLUDED

/* "%code requires" blocks.  */
/* Line 33 of lalr1.cc  */
#line 5 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"


/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <list>
#include <string>
#include <vector>
#include <zorba/internal/unique_ptr.h>

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/zorba_parser_error.h"
#include "zorbatypes/zstring.h"

#ifdef __GNUC__
    // disable a warning in location.hh which comes with bison
    // position.hh:141: warning: suggest parentheses around && within ||
#   pragma GCC diagnostic ignored "-Wparentheses"
#endif

#include "location.hh"

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wparentheses"
#endif

typedef std::list<zorba::zstring> string_list_t;
typedef std::pair<zorba::zstring,zorba::zstring> string_pair_t;




/* Line 33 of lalr1.cc  */
#line 93 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"
#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace zorba {
/* Line 33 of lalr1.cc  */
#line 109 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {
/* Line 33 of lalr1.cc  */
#line 148 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.y"

    zorba::parsenode *node;
    zorba::exprnode *expr;
    zorba::FunctionSig *fnsig;
    zorba::VarNameAndType *varnametype;
    off_t sval;
    const char *strval;
    xs_integer *ival;
    xs_double *dval;
    xs_decimal *decval;
    ZorbaParserError *err;
    string_list_t *strlist;
    string_pair_t *strpair;
    std::vector<string_pair_t> *vstrpair;
    CatchExpr::NameTestList *name_test_list;
    FTStopWordOption::incl_excl_list_t *incl_excl_list;
    FTSelection::pos_filter_list_t *pos_filter_list;
    FTThesaurusOption::thesaurus_id_list_t *thesaurus_id_list;
    ft_anyall_mode::type ft_anyall_value;


/* Line 33 of lalr1.cc  */
#line 143 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.hpp"
    };
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
     _EOF = 0,
     UNRECOGNIZED = 258,
     APOS_ATTR_CONTENT = 260,
     CHAR_LITERAL = 261,
     CHAR_LITERAL_AND_CDATA_END = 262,
     CHAR_LITERAL_AND_PI_END = 263,
     CHAR_REF_LITERAL = 264,
     ELEMENT_CONTENT = 265,
     ELEM_WILDCARD = 266,
     ELEM_EQNAME_WILDCARD = 267,
     ENTITY_REF = 268,
     EXPR_COMMENT_LITERAL = 269,
     PI_NCNAME_LBRACE = 270,
     NCNAME_SVAL = 271,
     PRAGMA_LITERAL_AND_END_PRAGMA = 272,
     QNAME_SVAL_AND_END_PRAGMA = 273,
     EQNAME_SVAL_AND_END_PRAGMA = 274,
     PREFIX_WILDCARD = 275,
     COMP_ELEMENT_QNAME_LBRACE = 276,
     COMP_ATTRIBUTE_QNAME_LBRACE = 277,
     COMP_PI_NCNAME_LBRACE = 278,
     COMP_NS_NCNAME_LBRACE = 279,
     QNAME_SVAL = 280,
     EQNAME_SVAL = 281,
     ANNOTATION_QNAME_SVAL = 282,
     ANNOTATION_EQNAME_SVAL = 283,
     QUOTE_ATTR_CONTENT = 284,
     STRING_LITERAL = 285,
     XML_COMMENT_LITERAL = 286,
     DECLARE = 288,
     MODULE = 289,
     BLANK = 290,
     ALLOWING = 291,
     BASE_URI = 292,
     BOUNDARY_SPACE = 293,
     COMMENT = 294,
     CONSTRUCTION = 295,
     COPY_NAMESPACES = 296,
     COUNT = 297,
     DOCUMENT = 298,
     DOCUMENT_NODE = 299,
     ELEMENT = 300,
     FOR = 301,
     FUNCTION = 302,
     IF = 303,
     IMPORT = 304,
     INSTANCE = 305,
     LET = 306,
     MOST = 307,
     NS_NODE = 308,
     NEXT = 309,
     NO = 310,
     ONLY = 311,
     OPTION = 312,
     ORDERING = 313,
     PREVIOUS = 314,
     PROCESSING_INSTRUCTION = 315,
     SCHEMA = 316,
     SCHEMA_ATTRIBUTE = 317,
     SCHEMA_ELEMENT = 318,
     SEQUENTIAL = 319,
     SET = 320,
     SIMPLE = 321,
     SLIDING = 322,
     SOME = 323,
     SPACE = 324,
     STABLE = 325,
     TEXT = 326,
     TUMBLING = 327,
     SWITCH = 328,
     TYPESWITCH = 329,
     UPDATING = 330,
     VALIDATE = 331,
     TYPE = 332,
     WHEN = 333,
     WORD = 334,
     DECIMAL_FORMAT = 335,
     DECIMAL_SEPARATOR = 336,
     GROUPING_SEPARATOR = 337,
     INFINITY_VALUE = 338,
     MINUS_SIGN = 339,
     NaN = 340,
     PERCENT = 341,
     PER_MILLE = 342,
     ZERO_DIGIT = 343,
     DIGIT = 344,
     PATTERN_SEPARATOR = 345,
     ANCESTOR = 346,
     ANCESTOR_OR_SELF = 347,
     AND = 348,
     APOS = 349,
     AS = 350,
     ASCENDING = 351,
     AT = 352,
     ATTRIBUTE = 353,
     AT_SIGN = 354,
     CONCAT = 355,
     CASE = 356,
     CASTABLE = 357,
     CAST = 358,
     CDATA_BEGIN = 359,
     CDATA_END = 360,
     CHILD = 361,
     COLLATION = 362,
     COMMA = 363,
     COMMENT_BEGIN = 364,
     COMMENT_END = 365,
     DECIMAL_LITERAL = 366,
     CONTEXT = 367,
     VARIABLE = 368,
     DEFAULT = 369,
     DESCENDANT = 370,
     DESCENDANT_OR_SELF = 371,
     DESCENDING = 372,
     DIV = 373,
     DOLLAR = 374,
     DOT = 375,
     DOT_DOT = 376,
     COLON = 377,
     DOUBLE_COLON = 378,
     DOUBLE_LBRACE = 379,
     DOUBLE_LITERAL = 380,
     DOUBLE_RBRACE = 381,
     ELSE = 382,
     _EMPTY = 383,
     GREATEST = 384,
     LEAST = 385,
     EMPTY_TAG_END = 386,
     ENCODING = 387,
     EQUALS = 388,
     ESCAPE_APOS = 389,
     ESCAPE_QUOTE = 390,
     EVERY = 391,
     EXCEPT = 392,
     EXTERNAL = 393,
     FOLLOWING = 394,
     FOLLOWING_SIBLING = 395,
     FOLLOWS = 396,
     GE = 397,
     GETS = 398,
     GT = 399,
     HOOK = 400,
     HASH = 401,
     IDIV = 402,
     _IN = 403,
     INHERIT = 404,
     INTEGER_LITERAL = 405,
     INTERSECT = 406,
     IS = 407,
     ITEM = 408,
     LBRACE = 409,
     LBRACK = 410,
     LE = 411,
     LPAR = 412,
     LT_OR_START_TAG = 413,
     MINUS = 414,
     MOD = 415,
     NAMESPACE = 416,
     _NAN = 417,
     NE = 418,
     NODECOMP = 419,
     NO_INHERIT = 420,
     NO_PRESERVE = 421,
     OR = 422,
     ORDER = 423,
     ORDERED = 424,
     BY = 425,
     GROUP = 426,
     PARENT = 427,
     PERCENTAGE = 428,
     PI_BEGIN = 429,
     PI_END = 430,
     PLUS = 431,
     PRAGMA_BEGIN = 432,
     PRAGMA_END = 433,
     PRECEDES = 434,
     PRECEDING = 435,
     PRECEDING_SIBLING = 436,
     PRESERVE = 437,
     QUOTE = 438,
     RBRACE = 439,
     RBRACK = 440,
     OFFSET = 441,
     LIMIT = 442,
     RETURN = 443,
     RPAR = 444,
     SATISFIES = 445,
     SELF = 446,
     SEMI = 447,
     SLASH = 448,
     SLASH_SLASH = 449,
     BANG = 450,
     STAR = 451,
     START_TAG_END = 452,
     STRIP = 453,
     TAG_END = 454,
     THEN = 455,
     TO = 456,
     TREAT = 457,
     UNION = 458,
     UNORDERED = 459,
     VAL_EQ = 460,
     VAL_GE = 461,
     VAL_GT = 462,
     VAL_LE = 463,
     VAL_LT = 464,
     VAL_NE = 465,
     VALUECOMP = 466,
     VBAR = 467,
     EMPTY_SEQUENCE = 468,
     WHERE = 469,
     XML_COMMENT_BEGIN = 470,
     XML_COMMENT_END = 471,
     XQUERY = 472,
     VERSION = 473,
     START = 474,
     AFTER = 475,
     BEFORE = 476,
     REVALIDATION = 477,
     _STRICT = 478,
     LAX = 479,
     SKIP = 480,
     _DELETE = 481,
     NODE = 482,
     INSERT = 483,
     NODES = 484,
     RENAME = 485,
     REPLACE = 486,
     VALUE = 487,
     OF = 488,
     FIRST = 489,
     INTO = 490,
     LAST = 491,
     MODIFY = 492,
     COPY = 493,
     WITH = 494,
     BREAK = 495,
     CONTINUE = 496,
     EXIT = 497,
     LOOP = 498,
     RETURNING = 499,
     WHILE = 500,
     TRY = 501,
     CATCH = 502,
     USING = 503,
     ALL = 504,
     ANY = 505,
     CONTAINS = 506,
     CONTENT = 507,
     DIACRITICS = 508,
     DIFFERENT = 509,
     DISTANCE = 510,
     END = 511,
     ENTIRE = 512,
     EXACTLY = 513,
     FROM = 514,
     FTAND = 515,
     FTNOT = 516,
     NOT = 517,
     FT_OPTION = 518,
     FTOR = 519,
     INSENSITIVE = 520,
     LANGUAGE = 521,
     LEVELS = 522,
     LOWERCASE = 523,
     OCCURS = 524,
     PARAGRAPH = 525,
     PARAGRAPHS = 526,
     PHRASE = 527,
     RELATIONSHIP = 528,
     SAME = 529,
     SCORE = 530,
     SENSITIVE = 531,
     SENTENCE = 532,
     SENTENCES = 533,
     STEMMING = 534,
     STOP = 535,
     THESAURUS = 536,
     TIMES = 537,
     UPPERCASE = 538,
     WEIGHT = 539,
     WILDCARDS = 540,
     WINDOW = 541,
     WITHOUT = 542,
     WORDS = 543,
     COLLECTION = 544,
     CONSTOPT = 545,
     APPEND_ONLY = 546,
     QUEUE = 547,
     MUTABLE = 548,
     READ_ONLY = 549,
     UNIQUE = 550,
     NON = 551,
     INDEX = 552,
     MANUALLY = 553,
     AUTOMATICALLY = 554,
     MAINTAINED = 555,
     ON = 556,
     RANGE = 557,
     EQUALITY = 558,
     GENERAL = 559,
     INTEGRITY = 560,
     CONSTRAINT = 561,
     CHECK = 562,
     KEY = 563,
     FOREACH = 564,
     FOREIGN = 565,
     KEYS = 566,
     L_SIMPLE_OBJ_UNION = 567,
     R_SIMPLE_OBJ_UNION = 568,
     L_ACCUMULATOR_OBJ_UNION = 569,
     R_ACCUMULATOR_OBJ_UNION = 570,
     JSON = 571,
     APPEND = 572,
     POSITION = 573,
     OBJECT = 574,
     ARRAY = 575,
     JSON_ITEM = 576,
     STRUCTURED_ITEM = 577,
     BYTE_ORDER_MARK_UTF8 = 578,
     SHEBANG = 579,
     RANGE_REDUCE = 580,
     SEQUENCE_TYPE_REDUCE = 581,
     ADDITIVE_REDUCE = 582,
     UNION_REDUCE = 583,
     INTERSECT_EXCEPT_REDUCE = 584,
     QVARINDECLLIST_REDUCE = 585,
     UNARY_PREC = 586,
     STEP_REDUCE = 587,
     SIMPLEMAPEXPR_REDUCE = 588,
     MULTIPLICATIVE_REDUCE = 589,
     SELECT = 590
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    xquery_parser (xquery_driver& driver_yyarg);
    virtual ~xquery_parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
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
#endif

  private:
    /// This class is not copyable.
    xquery_parser (const xquery_parser&);
    xquery_parser& operator= (const xquery_parser&);

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the lookahead token.
    virtual std::string yysyntax_error_ (int yystate, int tok);

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
#endif


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

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    /// Internal symbol numbers.
    typedef unsigned short int token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const short int yypact_ninf_;

    /// For a state, default reduction number.
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
    static const short int yytable_[];
    static const short int yytable_ninf_;

    static const short int yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned short int yystos_[];

    /// For a rule, its LHS.
    static const unsigned short int yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[]; 

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
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

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    ///                     If null, do not display the symbol, just free it.
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

    /* User arguments.  */
    xquery_driver& driver;
  };

} // zorba
/* Line 33 of lalr1.cc  */
#line 668 "/Users/pjl/src/flwor/zorba/repo/skiplimit/zorba/build/src/compiler/parser/xquery_parser.hpp"



#endif /* !YY_ZORBA_USERS_PJL_SRC_FLWOR_ZORBA_REPO_SKIPLIMIT_ZORBA_BUILD_SRC_COMPILER_PARSER_XQUERY_PARSER_HPP_INCLUDED  */
