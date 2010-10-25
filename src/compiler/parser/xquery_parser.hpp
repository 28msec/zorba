
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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
#line 35 "/home/markos/zorba/merge/src/compiler/parser/xquery_parser.y"


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
#line 76 "/home/markos/zorba/merge/build-gdb/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace zorba {

/* Line 35 of lalr1.cc  */
#line 90 "/home/markos/zorba/merge/build-gdb/src/compiler/parser/xquery_parser.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 35 of lalr1.cc  */
#line 100 "/home/markos/zorba/merge/build-gdb/src/compiler/parser/xquery_parser.hpp"

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


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace zorba {

/* Line 35 of lalr1.cc  */
#line 148 "/home/markos/zorba/merge/build-gdb/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 150 "/home/markos/zorba/merge/src/compiler/parser/xquery_parser.y"

    zorba::parsenode *node;
    zorba::exprnode *expr;
    zorba::FunctionSig *fnsig;
    zorba::VarNameAndType *varnametype;
    off_t sval;
    const char *strval;
    xqp_integer *ival;
    xqp_double *dval;
    xqp_decimal *decval;
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
#line 184 "/home/markos/zorba/merge/build-gdb/src/compiler/parser/xquery_parser.hpp"
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
     PREFIX_WILDCARD = 273,
     COMP_ELEMENT_QNAME_LBRACE = 274,
     COMP_ATTRIBUTE_QNAME_LBRACE = 275,
     COMP_PI_NCNAME_LBRACE = 276,
     QNAME_SVAL = 277,
     ANNOTATION_QNAME_SVAL = 278,
     QUOTE_ATTR_CONTENT = 279,
     STRING_LITERAL = 280,
     XML_COMMENT_LITERAL = 281,
     DECLARE = 284,
     MODULE = 285,
     BLANK = 286,
     ALLOWING = 287,
     BASE_URI = 288,
     BOUNDARY_SPACE = 289,
     COMMENT = 290,
     CONSTRUCTION = 291,
     COPY_NAMESPACES = 292,
     COUNT = 293,
     DETERMINISTIC = 294,
     DOCUMENT = 295,
     DOCUMENT_NODE = 296,
     ELEMENT = 297,
     EVAL = 298,
     FOR = 299,
     FUNCTION = 300,
     IF = 301,
     IMPORT = 302,
     INSTANCE = 303,
     LET = 304,
     MOST = 305,
     NEXT = 306,
     NO = 307,
     NONDETERMINISTIC = 308,
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
     DOUBLE_COLON = 373,
     DOUBLE_LBRACE = 374,
     DOUBLE_LITERAL = 375,
     DOUBLE_RBRACE = 376,
     ELSE = 377,
     _EMPTY = 378,
     GREATEST = 379,
     LEAST = 380,
     EMPTY_TAG_END = 381,
     ENCODING = 382,
     EQUALS = 383,
     ESCAPE_APOS = 384,
     ESCAPE_QUOTE = 385,
     EVERY = 386,
     EXCEPT = 387,
     EXTERNAL = 388,
     FOLLOWING = 389,
     FOLLOWING_SIBLING = 390,
     FOLLOWS = 391,
     GE = 392,
     GETS = 393,
     GT = 394,
     HOOK = 395,
     HASH = 396,
     IDIV = 397,
     _IN = 398,
     INHERIT = 399,
     INTEGER_LITERAL = 400,
     INTERSECT = 401,
     IS = 402,
     ITEM = 403,
     LBRACE = 404,
     LBRACK = 405,
     LE = 406,
     LPAR = 407,
     LT_OR_START_TAG = 408,
     MINUS = 409,
     MOD = 410,
     NAMESPACE = 411,
     _NAN = 412,
     NE = 413,
     NODECOMP = 414,
     NOT_OPERATOR_KEYWORD = 415,
     NO_INHERIT = 416,
     NO_PRESERVE = 417,
     OR = 418,
     ORDER = 419,
     ORDERED = 420,
     BY = 421,
     GROUP = 422,
     PARENT = 423,
     PERCENTAGE = 424,
     PI_BEGIN = 425,
     PI_END = 426,
     PLUS = 427,
     PRAGMA_BEGIN = 428,
     PRAGMA_END = 429,
     PRECEDES = 430,
     PRECEDING = 431,
     PRECEDING_SIBLING = 432,
     PRESERVE = 433,
     QUOTE = 434,
     RBRACE = 435,
     RBRACK = 436,
     RETURN = 437,
     RPAR = 438,
     SATISFIES = 439,
     SELF = 440,
     SEMI = 441,
     SLASH = 442,
     SLASH_SLASH = 443,
     STAR = 444,
     START_TAG_END = 445,
     STRIP = 446,
     TAG_END = 447,
     THEN = 448,
     TO = 449,
     TREAT = 450,
     UNION = 451,
     UNORDERED = 452,
     VAL_EQ = 453,
     VAL_GE = 454,
     VAL_GT = 455,
     VAL_LE = 456,
     VAL_LT = 457,
     VAL_NE = 458,
     VALUECOMP = 459,
     VBAR = 460,
     EMPTY_SEQUENCE = 461,
     WHERE = 462,
     XML_COMMENT_BEGIN = 463,
     XML_COMMENT_END = 464,
     XQUERY = 465,
     VERSION = 466,
     START = 467,
     AFTER = 468,
     BEFORE = 469,
     REVALIDATION = 470,
     _STRICT = 471,
     LAX = 472,
     SKIP = 473,
     _DELETE = 474,
     NODE = 475,
     INSERT = 476,
     NODES = 477,
     RENAME = 478,
     REPLACE = 479,
     VALUE = 480,
     OF = 481,
     FIRST = 482,
     INTO = 483,
     LAST = 484,
     MODIFY = 485,
     COPY = 486,
     WITH = 487,
     BLOCK = 488,
     BREAK = 489,
     CONTINUE = 490,
     EXIT = 491,
     LOOP = 492,
     RETURNING = 493,
     WHILE = 494,
     TRY = 495,
     CATCH = 496,
     USING = 497,
     ALL = 498,
     ANY = 499,
     CONTAINS = 500,
     CONTENT = 501,
     DIACRITICS = 502,
     DIFFERENT = 503,
     DISTANCE = 504,
     END = 505,
     ENTIRE = 506,
     EXACTLY = 507,
     FROM = 508,
     FTAND = 509,
     FTNOT = 510,
     NOT = 511,
     FT_OPTION = 512,
     FTOR = 513,
     INSENSITIVE = 514,
     LANGUAGE = 515,
     LEVELS = 516,
     LOWERCASE = 517,
     OCCURS = 518,
     PARAGRAPH = 519,
     PARAGRAPHS = 520,
     PHRASE = 521,
     RELATIONSHIP = 522,
     SAME = 523,
     SCORE = 524,
     SENSITIVE = 525,
     SENTENCE = 526,
     SENTENCES = 527,
     STEMMING = 528,
     STOP = 529,
     THESAURUS = 530,
     TIMES = 531,
     UPPERCASE = 532,
     WEIGHT = 533,
     WILDCARDS = 534,
     WINDOW = 535,
     WITHOUT = 536,
     WORDS = 537,
     COLLECTION = 538,
     CONSTOPT = 539,
     APPEND_ONLY = 540,
     QUEUE = 541,
     MUTABLE = 542,
     READ_ONLY = 543,
     UNIQUE = 544,
     NON = 545,
     INDEX = 546,
     MANUALLY = 547,
     AUTOMATICALLY = 548,
     MAINTAINED = 549,
     ON = 550,
     RANGE = 551,
     EQUALITY = 552,
     GENERAL = 553,
     INTEGRITY = 554,
     CONSTRAINT = 555,
     CHECK = 556,
     KEY = 557,
     FOREACH = 558,
     FOREIGN = 559,
     KEYS = 560,
     BYTE_ORDER_MARK_UTF8 = 561,
     RANGE_REDUCE = 562,
     ADDITIVE_REDUCE = 563,
     MULTIPLICATIVE_REDUCE = 564,
     UNION_REDUCE = 565,
     INTERSECT_EXCEPT_REDUCE = 566,
     QVARINDECLLIST_REDUCE = 567,
     COMMA_DOLLAR = 568,
     UNARY_PREC = 569,
     SEQUENCE_TYPE_REDUCE = 570,
     OCCURS_STAR = 571,
     OCCURS_PLUS = 572,
     OCCURS_HOOK = 573,
     STEP_REDUCE = 574
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

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 35 of lalr1.cc  */
#line 687 "/home/markos/zorba/merge/build-gdb/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
