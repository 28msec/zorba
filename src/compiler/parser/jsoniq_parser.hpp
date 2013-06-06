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
#line 5 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"


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
#line 89 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.hpp"


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
#line 119 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.hpp"

  /// A Bison parser.
  class jsoniq_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 131 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.y"

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
#line 155 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.hpp"
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
     DOLLAR_DOLLAR = 375,
     DOT = 376,
     DOT_DOT = 377,
     COLON = 378,
     DOUBLE_COLON = 379,
     DOUBLE_LBRACE = 380,
     DOUBLE_LITERAL = 381,
     DOUBLE_RBRACE = 382,
     ELSE = 383,
     _EMPTY = 384,
     GREATEST = 385,
     LEAST = 386,
     EMPTY_TAG_END = 387,
     ENCODING = 388,
     EQUALS = 389,
     ESCAPE_APOS = 390,
     ESCAPE_QUOTE = 391,
     EVERY = 392,
     EXCEPT = 393,
     EXTERNAL = 394,
     FOLLOWING = 395,
     FOLLOWING_SIBLING = 396,
     FOLLOWS = 397,
     GE = 398,
     GETS = 399,
     GT = 400,
     HOOK = 401,
     HASH = 402,
     IDIV = 403,
     _IN = 404,
     INHERIT = 405,
     INTEGER_LITERAL = 406,
     INTERSECT = 407,
     IS = 408,
     ITEM = 409,
     LBRACE = 410,
     LBRACK = 411,
     LE = 412,
     LPAR = 413,
     LT_OR_START_TAG = 414,
     MINUS = 415,
     MOD = 416,
     NAMESPACE = 417,
     _NAN = 418,
     NE = 419,
     NODECOMP = 420,
     NO_INHERIT = 421,
     NO_PRESERVE = 422,
     OR = 423,
     ORDER = 424,
     ORDERED = 425,
     BY = 426,
     GROUP = 427,
     PARENT = 428,
     PERCENTAGE = 429,
     PI_BEGIN = 430,
     PI_END = 431,
     PLUS = 432,
     PRAGMA_BEGIN = 433,
     PRAGMA_END = 434,
     PRECEDES = 435,
     PRECEDING = 436,
     PRECEDING_SIBLING = 437,
     PRESERVE = 438,
     QUOTE = 439,
     RBRACE = 440,
     RBRACK = 441,
     RETURN = 442,
     RPAR = 443,
     SATISFIES = 444,
     SELF = 445,
     SEMI = 446,
     SLASH = 447,
     SLASH_SLASH = 448,
     BANG = 449,
     STAR = 450,
     START_TAG_END = 451,
     STRIP = 452,
     TAG_END = 453,
     THEN = 454,
     TO = 455,
     TREAT = 456,
     UNION = 457,
     UNORDERED = 458,
     VAL_EQ = 459,
     VAL_GE = 460,
     VAL_GT = 461,
     VAL_LE = 462,
     VAL_LT = 463,
     VAL_NE = 464,
     VALUECOMP = 465,
     VBAR = 466,
     EMPTY_SEQUENCE = 467,
     WHERE = 468,
     XML_COMMENT_BEGIN = 469,
     XML_COMMENT_END = 470,
     XQUERY = 471,
     JSONIQ = 472,
     VERSION = 473,
     START = 474,
     NULL_TOKEN = 475,
     TRUE_TOKEN = 476,
     FALSE_TOKEN = 477,
     AFTER = 478,
     BEFORE = 479,
     REVALIDATION = 480,
     _STRICT = 481,
     LAX = 482,
     SKIP = 483,
     _DELETE = 484,
     NODE = 485,
     INSERT = 486,
     NODES = 487,
     RENAME = 488,
     REPLACE = 489,
     VALUE = 490,
     OF = 491,
     FIRST = 492,
     INTO = 493,
     LAST = 494,
     MODIFY = 495,
     COPY = 496,
     WITH = 497,
     BREAK = 498,
     CONTINUE = 499,
     EXIT = 500,
     LOOP = 501,
     RETURNING = 502,
     WHILE = 503,
     TRY = 504,
     CATCH = 505,
     USING = 506,
     ALL = 507,
     ANY = 508,
     CONTAINS = 509,
     CONTENT = 510,
     DIACRITICS = 511,
     DIFFERENT = 512,
     DISTANCE = 513,
     END = 514,
     ENTIRE = 515,
     EXACTLY = 516,
     FROM = 517,
     FTAND = 518,
     FTNOT = 519,
     NOT = 520,
     FT_OPTION = 521,
     FTOR = 522,
     INSENSITIVE = 523,
     LANGUAGE = 524,
     LEVELS = 525,
     LOWERCASE = 526,
     OCCURS = 527,
     PARAGRAPH = 528,
     PARAGRAPHS = 529,
     PHRASE = 530,
     RELATIONSHIP = 531,
     SAME = 532,
     SCORE = 533,
     SENSITIVE = 534,
     SENTENCE = 535,
     SENTENCES = 536,
     STEMMING = 537,
     STOP = 538,
     THESAURUS = 539,
     TIMES = 540,
     UPPERCASE = 541,
     WEIGHT = 542,
     WILDCARDS = 543,
     WINDOW = 544,
     WITHOUT = 545,
     WORDS = 546,
     COLLECTION = 547,
     CONSTOPT = 548,
     APPEND_ONLY = 549,
     QUEUE = 550,
     MUTABLE = 551,
     READ_ONLY = 552,
     UNIQUE = 553,
     NON = 554,
     INDEX = 555,
     MANUALLY = 556,
     AUTOMATICALLY = 557,
     MAINTAINED = 558,
     ON = 559,
     RANGE = 560,
     EQUALITY = 561,
     GENERAL = 562,
     INTEGRITY = 563,
     CONSTRAINT = 564,
     CHECK = 565,
     KEY = 566,
     FOREACH = 567,
     FOREIGN = 568,
     KEYS = 569,
     L_SIMPLE_OBJ_UNION = 570,
     R_SIMPLE_OBJ_UNION = 571,
     L_ACCUMULATOR_OBJ_UNION = 572,
     R_ACCUMULATOR_OBJ_UNION = 573,
     JSON = 574,
     APPEND = 575,
     POSITION = 576,
     OBJECT = 577,
     ARRAY = 578,
     JSON_ITEM = 579,
     STRUCTURED_ITEM = 580,
     BYTE_ORDER_MARK_UTF8 = 581,
     SHEBANG = 582,
     RANGE_REDUCE = 583,
     SEQUENCE_TYPE_REDUCE = 584,
     ADDITIVE_REDUCE = 585,
     UNION_REDUCE = 586,
     INTERSECT_EXCEPT_REDUCE = 587,
     QVARINDECLLIST_REDUCE = 588,
     COMMA_DOLLAR = 589,
     UNARY_PREC = 590,
     STEP_REDUCE = 591,
     SIMPLEMAPEXPR_REDUCE = 592,
     MULTIPLICATIVE_REDUCE = 593,
     JSONLOOKUPEXPR_REDUCE = 594,
     ANYKINDTEST_REDUCE = 595,
     GROUPBY_VAR_REDUCE = 596,
     GROUPBY_VAR_REDUCE2 = 597
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    jsoniq_parser (xquery_driver& driver_yyarg);
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
    xquery_driver& driver;
  };

} // zorba

/* Line 35 of lalr1.cc  */
#line 685 "/home/colea/work/new-jsoniq/build/src/compiler/parser/jsoniq_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
