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
#line 35 "/Users/pjl/src/flwor/zorba/trunk-3/zorba/src/compiler/parser/xquery_parser.y"


#include <list>
#include <string>
#include <vector>

#include "compiler/parsetree/parsenodes.h"
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
#line 74 "/Users/pjl/src/flwor/zorba/trunk-3/zorba/build/src/compiler/parser/xquery_parser.hpp"


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
#line 104 "/Users/pjl/src/flwor/zorba/trunk-3/zorba/build/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 150 "/Users/pjl/src/flwor/zorba/trunk-3/zorba/src/compiler/parser/xquery_parser.y"

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
#line 140 "/Users/pjl/src/flwor/zorba/trunk-3/zorba/build/src/compiler/parser/xquery_parser.hpp"
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
     ENTITY_REF = 267,
     EXPR_COMMENT_LITERAL = 268,
     PI_NCNAME_LBRACE = 269,
     NCNAME_SVAL = 270,
     PRAGMA_LITERAL_AND_END_PRAGMA = 271,
     QNAME_SVAL_AND_END_PRAGMA = 272,
     EQNAME_SVAL_AND_END_PRAGMA = 273,
     PREFIX_WILDCARD = 274,
     COMP_ELEMENT_QNAME_LBRACE = 275,
     COMP_ATTRIBUTE_QNAME_LBRACE = 276,
     COMP_PI_NCNAME_LBRACE = 277,
     QNAME_SVAL = 278,
     EQNAME_SVAL = 279,
     ANNOTATION_QNAME_SVAL = 280,
     QUOTE_ATTR_CONTENT = 281,
     STRING_LITERAL = 282,
     XML_COMMENT_LITERAL = 283,
     DECLARE = 286,
     MODULE = 287,
     BLANK = 288,
     ALLOWING = 289,
     BASE_URI = 290,
     BOUNDARY_SPACE = 291,
     COMMENT = 292,
     CONSTRUCTION = 293,
     COPY_NAMESPACES = 294,
     COUNT = 295,
     DOCUMENT = 296,
     DOCUMENT_NODE = 297,
     ELEMENT = 298,
     EVAL = 299,
     FOR = 300,
     FUNCTION = 301,
     IF = 302,
     IMPORT = 303,
     INSTANCE = 304,
     LET = 305,
     MOST = 306,
     NEXT = 307,
     NO = 308,
     ONLY = 309,
     OPTION = 310,
     ORDERING = 311,
     PREVIOUS = 312,
     PROCESSING_INSTRUCTION = 313,
     SCHEMA = 314,
     SCHEMA_ATTRIBUTE = 315,
     SCHEMA_ELEMENT = 316,
     SEQUENTIAL = 317,
     SET = 318,
     SIMPLE = 319,
     SLIDING = 320,
     SOME = 321,
     SPACE = 322,
     STABLE = 323,
     TEXT = 324,
     TUMBLING = 325,
     SWITCH = 326,
     TYPESWITCH = 327,
     UPDATING = 328,
     VALIDATE = 329,
     WHEN = 330,
     WORD = 331,
     DECIMAL_FORMAT = 332,
     DECIMAL_SEPARATOR = 333,
     GROUPING_SEPARATOR = 334,
     INFINITY_VALUE = 335,
     MINUS_SIGN = 336,
     NaN = 337,
     PERCENT = 338,
     PER_MILLE = 339,
     ZERO_DIGIT = 340,
     DIGIT = 341,
     PATTERN_SEPARATOR = 342,
     ANCESTOR = 343,
     ANCESTOR_OR_SELF = 344,
     AND = 345,
     APOS = 346,
     AS = 347,
     ASCENDING = 348,
     AT = 349,
     ATTRIBUTE = 350,
     AT_SIGN = 351,
     CASE = 352,
     CASTABLE = 353,
     CAST = 354,
     CDATA_BEGIN = 355,
     CDATA_END = 356,
     CHILD = 357,
     COLLATION = 358,
     COMMA = 359,
     COMMENT_BEGIN = 360,
     COMMENT_END = 361,
     DECIMAL_LITERAL = 362,
     CONTEXT = 363,
     VARIABLE = 364,
     DEFAULT = 365,
     DESCENDANT = 366,
     DESCENDANT_OR_SELF = 367,
     DESCENDING = 368,
     DIV = 369,
     DOLLAR = 370,
     DOT = 371,
     DOT_DOT = 372,
     COLON = 373,
     DOUBLE_COLON = 374,
     DOUBLE_LBRACE = 375,
     DOUBLE_LITERAL = 376,
     DOUBLE_RBRACE = 377,
     ELSE = 378,
     _EMPTY = 379,
     GREATEST = 380,
     LEAST = 381,
     EMPTY_TAG_END = 382,
     ENCODING = 383,
     EQUALS = 384,
     ESCAPE_APOS = 385,
     ESCAPE_QUOTE = 386,
     EVERY = 387,
     EXCEPT = 388,
     EXTERNAL = 389,
     FOLLOWING = 390,
     FOLLOWING_SIBLING = 391,
     FOLLOWS = 392,
     GE = 393,
     GETS = 394,
     GT = 395,
     HOOK = 396,
     HASH = 397,
     IDIV = 398,
     _IN = 399,
     INHERIT = 400,
     INTEGER_LITERAL = 401,
     INTERSECT = 402,
     IS = 403,
     ITEM = 404,
     LBRACE = 405,
     LBRACK = 406,
     LE = 407,
     LPAR = 408,
     LT_OR_START_TAG = 409,
     MINUS = 410,
     MOD = 411,
     NAMESPACE = 412,
     _NAN = 413,
     NE = 414,
     NODECOMP = 415,
     NOT_OPERATOR_KEYWORD = 416,
     NO_INHERIT = 417,
     NO_PRESERVE = 418,
     OR = 419,
     ORDER = 420,
     ORDERED = 421,
     BY = 422,
     GROUP = 423,
     PARENT = 424,
     PERCENTAGE = 425,
     PI_BEGIN = 426,
     PI_END = 427,
     PLUS = 428,
     PRAGMA_BEGIN = 429,
     PRAGMA_END = 430,
     PRECEDES = 431,
     PRECEDING = 432,
     PRECEDING_SIBLING = 433,
     PRESERVE = 434,
     QUOTE = 435,
     RBRACE = 436,
     RBRACK = 437,
     RETURN = 438,
     RPAR = 439,
     SATISFIES = 440,
     SELF = 441,
     SEMI = 442,
     SLASH = 443,
     SLASH_SLASH = 444,
     STAR = 445,
     START_TAG_END = 446,
     STRIP = 447,
     TAG_END = 448,
     THEN = 449,
     TO = 450,
     TREAT = 451,
     UNION = 452,
     UNORDERED = 453,
     VAL_EQ = 454,
     VAL_GE = 455,
     VAL_GT = 456,
     VAL_LE = 457,
     VAL_LT = 458,
     VAL_NE = 459,
     VALUECOMP = 460,
     VBAR = 461,
     EMPTY_SEQUENCE = 462,
     WHERE = 463,
     XML_COMMENT_BEGIN = 464,
     XML_COMMENT_END = 465,
     XQUERY = 466,
     VERSION = 467,
     START = 468,
     AFTER = 469,
     BEFORE = 470,
     REVALIDATION = 471,
     _STRICT = 472,
     LAX = 473,
     SKIP = 474,
     _DELETE = 475,
     NODE = 476,
     INSERT = 477,
     NODES = 478,
     RENAME = 479,
     REPLACE = 480,
     VALUE = 481,
     OF = 482,
     FIRST = 483,
     INTO = 484,
     LAST = 485,
     MODIFY = 486,
     COPY = 487,
     WITH = 488,
     LOCAL = 489,
     BREAK = 490,
     CONTINUE = 491,
     EXIT = 492,
     LOOP = 493,
     RETURNING = 494,
     WHILE = 495,
     TRY = 496,
     CATCH = 497,
     USING = 498,
     ALL = 499,
     ANY = 500,
     CONTAINS = 501,
     CONTENT = 502,
     DIACRITICS = 503,
     DIFFERENT = 504,
     DISTANCE = 505,
     END = 506,
     ENTIRE = 507,
     EXACTLY = 508,
     FROM = 509,
     FTAND = 510,
     FTNOT = 511,
     NOT = 512,
     FT_OPTION = 513,
     FTOR = 514,
     INSENSITIVE = 515,
     LANGUAGE = 516,
     LEVELS = 517,
     LOWERCASE = 518,
     OCCURS = 519,
     PARAGRAPH = 520,
     PARAGRAPHS = 521,
     PHRASE = 522,
     RELATIONSHIP = 523,
     SAME = 524,
     SCORE = 525,
     SENSITIVE = 526,
     SENTENCE = 527,
     SENTENCES = 528,
     STEMMING = 529,
     STOP = 530,
     THESAURUS = 531,
     TIMES = 532,
     UPPERCASE = 533,
     WEIGHT = 534,
     WILDCARDS = 535,
     WINDOW = 536,
     WITHOUT = 537,
     WORDS = 538,
     COLLECTION = 539,
     CONSTOPT = 540,
     APPEND_ONLY = 541,
     QUEUE = 542,
     MUTABLE = 543,
     READ_ONLY = 544,
     UNIQUE = 545,
     NON = 546,
     INDEX = 547,
     MANUALLY = 548,
     AUTOMATICALLY = 549,
     MAINTAINED = 550,
     ON = 551,
     RANGE = 552,
     EQUALITY = 553,
     GENERAL = 554,
     INTEGRITY = 555,
     CONSTRAINT = 556,
     CHECK = 557,
     KEY = 558,
     FOREACH = 559,
     FOREIGN = 560,
     KEYS = 561,
     BYTE_ORDER_MARK_UTF8 = 562,
     RANGE_REDUCE = 563,
     ADDITIVE_REDUCE = 564,
     MULTIPLICATIVE_REDUCE = 565,
     UNION_REDUCE = 566,
     INTERSECT_EXCEPT_REDUCE = 567,
     QVARINDECLLIST_REDUCE = 568,
     COMMA_DOLLAR = 569,
     UNARY_PREC = 570,
     SEQUENCE_TYPE_REDUCE = 571,
     OCCURS_STAR = 572,
     OCCURS_PLUS = 573,
     OCCURS_HOOK = 574,
     STEP_REDUCE = 575
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
#line 647 "/Users/pjl/src/flwor/zorba/trunk-3/zorba/build/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
