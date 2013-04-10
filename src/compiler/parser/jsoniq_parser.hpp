/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
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

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef PARSER_HEADER_H
# define PARSER_HEADER_H

/* "%code requires" blocks.  */

/* Line 35 of lalr1.cc  */
#line 35 "/home/colea/xquery/new-jsoniq/src/compiler/parser/jsoniq_parser.y"


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





/* Line 35 of lalr1.cc  */
#line 89 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"
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
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


namespace zorba {

/* Line 35 of lalr1.cc  */
#line 119 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.hpp"

  /// A Bison parser.
  class jsoniq_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 148 "/home/colea/xquery/new-jsoniq/src/compiler/parser/jsoniq_parser.y"

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



/* Line 35 of lalr1.cc  */
#line 155 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.hpp"
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
     DECLARE = 289,
     MODULE = 290,
     BLANK = 291,
     ALLOWING = 292,
     BASE_URI = 293,
     BOUNDARY_SPACE = 294,
     COMMENT = 295,
     CONSTRUCTION = 296,
     COPY_NAMESPACES = 297,
     COUNT = 298,
     DOCUMENT = 299,
     DOCUMENT_NODE = 300,
     ELEMENT = 301,
     FOR = 302,
     FUNCTION = 303,
     IF = 304,
     IMPORT = 305,
     INSTANCE = 306,
     LET = 307,
     MOST = 308,
     NS_NODE = 309,
     NEXT = 310,
     NO = 311,
     ONLY = 312,
     OPTION = 313,
     ORDERING = 314,
     PREVIOUS = 315,
     PROCESSING_INSTRUCTION = 316,
     SCHEMA = 317,
     SCHEMA_ATTRIBUTE = 318,
     SCHEMA_ELEMENT = 319,
     SEQUENTIAL = 320,
     SET = 321,
     SIMPLE = 322,
     SLIDING = 323,
     SOME = 324,
     SPACE = 325,
     STABLE = 326,
     TEXT = 327,
     TUMBLING = 328,
     SWITCH = 329,
     TYPESWITCH = 330,
     UPDATING = 331,
     VALIDATE = 332,
     TYPE = 333,
     WHEN = 334,
     WORD = 335,
     DECIMAL_FORMAT = 336,
     DECIMAL_SEPARATOR = 337,
     GROUPING_SEPARATOR = 338,
     INFINITY_VALUE = 339,
     MINUS_SIGN = 340,
     NaN = 341,
     PERCENT = 342,
     PER_MILLE = 343,
     ZERO_DIGIT = 344,
     DIGIT = 345,
     PATTERN_SEPARATOR = 346,
     ANCESTOR = 347,
     ANCESTOR_OR_SELF = 348,
     AND = 349,
     APOS = 350,
     AS = 351,
     ASCENDING = 352,
     AT = 353,
     ATTRIBUTE = 354,
     AT_SIGN = 355,
     CONCAT = 356,
     CASE = 357,
     CASTABLE = 358,
     CAST = 359,
     CDATA_BEGIN = 360,
     CDATA_END = 361,
     CHILD = 362,
     COLLATION = 363,
     COMMA = 364,
     COMMENT_BEGIN = 365,
     COMMENT_END = 366,
     DECIMAL_LITERAL = 367,
     CONTEXT = 368,
     VARIABLE = 369,
     DEFAULT = 370,
     DESCENDANT = 371,
     DESCENDANT_OR_SELF = 372,
     DESCENDING = 373,
     DIV = 374,
     DOLLAR = 375,
     DOLLAR_DOLLAR = 376,
     DOT = 377,
     DOT_DOT = 378,
     COLON = 379,
     DOUBLE_COLON = 380,
     DOUBLE_LBRACE = 381,
     DOUBLE_LITERAL = 382,
     DOUBLE_RBRACE = 383,
     ELSE = 384,
     _EMPTY = 385,
     GREATEST = 386,
     LEAST = 387,
     EMPTY_TAG_END = 388,
     ENCODING = 389,
     EQUALS = 390,
     ESCAPE_APOS = 391,
     ESCAPE_QUOTE = 392,
     EVERY = 393,
     EXCEPT = 394,
     EXTERNAL = 395,
     FOLLOWING = 396,
     FOLLOWING_SIBLING = 397,
     FOLLOWS = 398,
     GE = 399,
     GETS = 400,
     GT = 401,
     HOOK = 402,
     HASH = 403,
     IDIV = 404,
     _IN = 405,
     INHERIT = 406,
     INTEGER_LITERAL = 407,
     INTERSECT = 408,
     IS = 409,
     ITEM = 410,
     LBRACE = 411,
     LBRACK = 412,
     LE = 413,
     LPAR = 414,
     LT_OR_START_TAG = 415,
     MINUS = 416,
     MOD = 417,
     NAMESPACE = 418,
     _NAN = 419,
     NE = 420,
     NODECOMP = 421,
     NOT_OPERATOR_KEYWORD = 422,
     NO_INHERIT = 423,
     NO_PRESERVE = 424,
     OR = 425,
     ORDER = 426,
     ORDERED = 427,
     BY = 428,
     GROUP = 429,
     PARENT = 430,
     PERCENTAGE = 431,
     PI_BEGIN = 432,
     PI_END = 433,
     PLUS = 434,
     PRAGMA_BEGIN = 435,
     PRAGMA_END = 436,
     PRECEDES = 437,
     PRECEDING = 438,
     PRECEDING_SIBLING = 439,
     PRESERVE = 440,
     QUOTE = 441,
     RBRACE = 442,
     RBRACK = 443,
     RETURN = 444,
     RPAR = 445,
     SATISFIES = 446,
     SELF = 447,
     SEMI = 448,
     SLASH = 449,
     SLASH_SLASH = 450,
     BANG = 451,
     STAR = 452,
     START_TAG_END = 453,
     STRIP = 454,
     TAG_END = 455,
     THEN = 456,
     TO = 457,
     TREAT = 458,
     UNION = 459,
     UNORDERED = 460,
     VAL_EQ = 461,
     VAL_GE = 462,
     VAL_GT = 463,
     VAL_LE = 464,
     VAL_LT = 465,
     VAL_NE = 466,
     VALUECOMP = 467,
     VBAR = 468,
     EMPTY_SEQUENCE = 469,
     WHERE = 470,
     XML_COMMENT_BEGIN = 471,
     XML_COMMENT_END = 472,
     XQUERY = 473,
     JSONIQ = 474,
     VERSION = 475,
     START = 476,
     NULL_TOKEN = 477,
     TRUE_TOKEN = 478,
     FALSE_TOKEN = 479,
     AFTER = 480,
     BEFORE = 481,
     REVALIDATION = 482,
     _STRICT = 483,
     LAX = 484,
     SKIP = 485,
     _DELETE = 486,
     NODE = 487,
     INSERT = 488,
     NODES = 489,
     RENAME = 490,
     REPLACE = 491,
     VALUE = 492,
     OF = 493,
     FIRST = 494,
     INTO = 495,
     LAST = 496,
     MODIFY = 497,
     COPY = 498,
     WITH = 499,
     BREAK = 500,
     CONTINUE = 501,
     EXIT = 502,
     LOOP = 503,
     RETURNING = 504,
     WHILE = 505,
     TRY = 506,
     CATCH = 507,
     USING = 508,
     ALL = 509,
     ANY = 510,
     CONTAINS = 511,
     CONTENT = 512,
     DIACRITICS = 513,
     DIFFERENT = 514,
     DISTANCE = 515,
     END = 516,
     ENTIRE = 517,
     EXACTLY = 518,
     FROM = 519,
     FTAND = 520,
     FTNOT = 521,
     NOT = 522,
     FT_OPTION = 523,
     FTOR = 524,
     INSENSITIVE = 525,
     LANGUAGE = 526,
     LEVELS = 527,
     LOWERCASE = 528,
     OCCURS = 529,
     PARAGRAPH = 530,
     PARAGRAPHS = 531,
     PHRASE = 532,
     RELATIONSHIP = 533,
     SAME = 534,
     SCORE = 535,
     SENSITIVE = 536,
     SENTENCE = 537,
     SENTENCES = 538,
     STEMMING = 539,
     STOP = 540,
     THESAURUS = 541,
     TIMES = 542,
     UPPERCASE = 543,
     WEIGHT = 544,
     WILDCARDS = 545,
     WINDOW = 546,
     WITHOUT = 547,
     WORDS = 548,
     COLLECTION = 549,
     CONSTOPT = 550,
     APPEND_ONLY = 551,
     QUEUE = 552,
     MUTABLE = 553,
     READ_ONLY = 554,
     UNIQUE = 555,
     NON = 556,
     INDEX = 557,
     MANUALLY = 558,
     AUTOMATICALLY = 559,
     MAINTAINED = 560,
     ON = 561,
     RANGE = 562,
     EQUALITY = 563,
     GENERAL = 564,
     INTEGRITY = 565,
     CONSTRAINT = 566,
     CHECK = 567,
     KEY = 568,
     FOREACH = 569,
     FOREIGN = 570,
     KEYS = 571,
     L_SIMPLE_OBJ_UNION = 572,
     R_SIMPLE_OBJ_UNION = 573,
     L_ACCUMULATOR_OBJ_UNION = 574,
     R_ACCUMULATOR_OBJ_UNION = 575,
     JSON = 576,
     APPEND = 577,
     POSITION = 578,
     OBJECT = 579,
     ARRAY = 580,
     JSON_ITEM = 581,
     STRUCTURED_ITEM = 582,
     BYTE_ORDER_MARK_UTF8 = 583,
     SHEBANG = 584,
     RANGE_REDUCE = 585,
     SEQUENCE_TYPE_REDUCE = 586,
     ADDITIVE_REDUCE = 587,
     UNION_REDUCE = 588,
     INTERSECT_EXCEPT_REDUCE = 589,
     QVARINDECLLIST_REDUCE = 590,
     COMMA_DOLLAR = 591,
     UNARY_PREC = 592,
     STEP_REDUCE = 593,
     SIMPLEMAPEXPR_REDUCE = 594,
     MULTIPLICATIVE_REDUCE = 595,
     JSONLOOKUPEXPR_REDUCE = 596
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    jsoniq_parser (jsoniq_driver& driver_yyarg);
    virtual ~jsoniq_parser ();

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

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);

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
    jsoniq_driver& driver;
  };

} // zorba

/* Line 35 of lalr1.cc  */
#line 683 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/jsoniq_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
