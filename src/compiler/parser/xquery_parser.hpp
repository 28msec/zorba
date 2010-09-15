/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 Free
   Software Foundation, Inc.
   
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
#line 35 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"


#include <list>
#include <string>
#include <vector>

#include "compiler/parsetree/parsenodes.h"

#ifdef __GNUC__
    // disable a warning in location.hh which comes with bison
    // position.hh:141: warning: suggest parentheses around && within ||
#   pragma GCC diagnostic ignored "-Wparentheses"
#endif

#include "location.hh"

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wparentheses"
#endif

typedef std::list<std::string> string_list_t;
typedef std::pair<std::string,std::string> string_pair_t;







/* Line 35 of lalr1.cc  */
#line 74 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


namespace zorba {

/* Line 35 of lalr1.cc  */
#line 85 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.hpp"
  class position;
  class location;

} // zorba

/* Line 35 of lalr1.cc  */
#line 92 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.hpp"

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


namespace zorba {

/* Line 35 of lalr1.cc  */
#line 137 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 156 "/home/colea/work/xquery_temp1/src/compiler/parser/xquery_parser.y"

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
#line 173 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.hpp"
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
     QUOTE_ATTR_CONTENT = 278,
     STRING_LITERAL = 279,
     XML_COMMENT_LITERAL = 280,
     DECLARE = 283,
     MODULE = 284,
     BLANK = 285,
     ALLOWING = 286,
     BASE_URI = 287,
     BOUNDARY_SPACE = 288,
     COMMENT = 289,
     CONSTRUCTION = 290,
     COPY_NAMESPACES = 291,
     COUNT = 292,
     DETERMINISTIC = 293,
     DOCUMENT = 294,
     DOCUMENT_NODE = 295,
     ELEMENT = 296,
     EVAL = 297,
     FOR = 298,
     FUNCTION = 299,
     IF = 300,
     IMPORT = 301,
     INSTANCE = 302,
     LET = 303,
     MOST = 304,
     NEXT = 305,
     NO = 306,
     NONDETERMINISTIC = 307,
     ONLY = 308,
     OPTION = 309,
     ORDERING = 310,
     PREVIOUS = 311,
     PROCESSING_INSTRUCTION = 312,
     SCHEMA = 313,
     SCHEMA_ATTRIBUTE = 314,
     SCHEMA_ELEMENT = 315,
     SEQUENTIAL = 316,
     SET = 317,
     SIMPLE = 318,
     SLIDING = 319,
     SOME = 320,
     SPACE = 321,
     STABLE = 322,
     TEXT = 323,
     TUMBLING = 324,
     SWITCH = 325,
     TYPESWITCH = 326,
     UPDATING = 327,
     VALIDATE = 328,
     WHEN = 329,
     WORD = 330,
     DECIMAL_FORMAT = 331,
     DECIMAL_SEPARATOR = 332,
     GROUPING_SEPARATOR = 333,
     INFINITY_VALUE = 334,
     MINUS_SIGN = 335,
     NaN = 336,
     PERCENT = 337,
     PER_MILLE = 338,
     ZERO_DIGIT = 339,
     DIGIT = 340,
     PATTERN_SEPARATOR = 341,
     ANCESTOR = 342,
     ANCESTOR_OR_SELF = 343,
     AND = 344,
     APOS = 345,
     AS = 346,
     ASCENDING = 347,
     AT = 348,
     ATTRIBUTE = 349,
     AT_SIGN = 350,
     CASE = 351,
     CASTABLE = 352,
     CAST = 353,
     CDATA_BEGIN = 354,
     CDATA_END = 355,
     CHILD = 356,
     COLLATION = 357,
     COMMA = 358,
     COMMENT_BEGIN = 359,
     COMMENT_END = 360,
     DECIMAL_LITERAL = 361,
     CONTEXT = 362,
     VARIABLE = 363,
     DEFAULT = 364,
     DESCENDANT = 365,
     DESCENDANT_OR_SELF = 366,
     DESCENDING = 367,
     DIV = 368,
     DOLLAR = 369,
     DOT = 370,
     DOT_DOT = 371,
     DOUBLE_COLON = 372,
     DOUBLE_LBRACE = 373,
     DOUBLE_LITERAL = 374,
     DOUBLE_RBRACE = 375,
     ELSE = 376,
     _EMPTY = 377,
     GREATEST = 378,
     LEAST = 379,
     EMPTY_TAG_END = 380,
     ENCODING = 381,
     EQUALS = 382,
     ESCAPE_APOS = 383,
     ESCAPE_QUOTE = 384,
     EVERY = 385,
     EXCEPT = 386,
     EXTERNAL = 387,
     FOLLOWING = 388,
     FOLLOWING_SIBLING = 389,
     FOLLOWS = 390,
     GE = 391,
     GETS = 392,
     GT = 393,
     HOOK = 394,
     HASH = 395,
     IDIV = 396,
     _IN = 397,
     INHERIT = 398,
     INTEGER_LITERAL = 399,
     INTERSECT = 400,
     IS = 401,
     ITEM = 402,
     LBRACE = 403,
     LBRACK = 404,
     LE = 405,
     LPAR = 406,
     LT_OR_START_TAG = 407,
     MINUS = 408,
     MOD = 409,
     NAMESPACE = 410,
     _NAN = 411,
     NE = 412,
     NODECOMP = 413,
     NOT_OPERATOR_KEYWORD = 414,
     NO_INHERIT = 415,
     NO_PRESERVE = 416,
     OR = 417,
     ORDER = 418,
     ORDERED = 419,
     BY = 420,
     GROUP = 421,
     PARENT = 422,
     PERCENTAGE = 423,
     PI_BEGIN = 424,
     PI_END = 425,
     PLUS = 426,
     PRAGMA_BEGIN = 427,
     PRAGMA_END = 428,
     PRECEDES = 429,
     PRECEDING = 430,
     PRECEDING_SIBLING = 431,
     PRESERVE = 432,
     QUOTE = 433,
     RBRACE = 434,
     RBRACK = 435,
     RETURN = 436,
     RPAR = 437,
     SATISFIES = 438,
     SELF = 439,
     SEMI = 440,
     SLASH = 441,
     SLASH_SLASH = 442,
     STAR = 443,
     START_TAG_END = 444,
     STRIP = 445,
     TAG_END = 446,
     THEN = 447,
     TO = 448,
     TREAT = 449,
     UNION = 450,
     UNORDERED = 451,
     VAL_EQ = 452,
     VAL_GE = 453,
     VAL_GT = 454,
     VAL_LE = 455,
     VAL_LT = 456,
     VAL_NE = 457,
     VALUECOMP = 458,
     VBAR = 459,
     EMPTY_SEQUENCE = 460,
     WHERE = 461,
     XML_COMMENT_BEGIN = 462,
     XML_COMMENT_END = 463,
     XQUERY = 464,
     VERSION = 465,
     START = 466,
     AFTER = 467,
     BEFORE = 468,
     REVALIDATION = 469,
     _STRICT = 470,
     LAX = 471,
     SKIP = 472,
     _DELETE = 473,
     NODE = 474,
     INSERT = 475,
     NODES = 476,
     RENAME = 477,
     REPLACE = 478,
     VALUE = 479,
     OF = 480,
     FIRST = 481,
     INTO = 482,
     LAST = 483,
     MODIFY = 484,
     COPY = 485,
     WITH = 486,
     BLOCK = 487,
     BREAK = 488,
     CONTINUE = 489,
     EXIT = 490,
     LOOP = 491,
     RETURNING = 492,
     WHILE = 493,
     TRY = 494,
     CATCH = 495,
     USING = 496,
     ALL = 497,
     ANY = 498,
     CONTAINS = 499,
     CONTENT = 500,
     DIACRITICS = 501,
     DIFFERENT = 502,
     DISTANCE = 503,
     END = 504,
     ENTIRE = 505,
     EXACTLY = 506,
     FROM = 507,
     FTAND = 508,
     FTNOT = 509,
     NOT = 510,
     FT_OPTION = 511,
     FTOR = 512,
     INSENSITIVE = 513,
     LANGUAGE = 514,
     LEVELS = 515,
     LOWERCASE = 516,
     OCCURS = 517,
     PARAGRAPH = 518,
     PARAGRAPHS = 519,
     PHRASE = 520,
     RELATIONSHIP = 521,
     SAME = 522,
     SCORE = 523,
     SENSITIVE = 524,
     SENTENCE = 525,
     SENTENCES = 526,
     STEMMING = 527,
     STOP = 528,
     THESAURUS = 529,
     TIMES = 530,
     UPPERCASE = 531,
     WEIGHT = 532,
     WILDCARDS = 533,
     WINDOW = 534,
     WITHOUT = 535,
     WORDS = 536,
     COLLECTION = 537,
     CONSTOPT = 538,
     APPEND_ONLY = 539,
     QUEUE = 540,
     MUTABLE = 541,
     READ_ONLY = 542,
     UNIQUE = 543,
     NON = 544,
     INDEX = 545,
     MANUALLY = 546,
     AUTOMATICALLY = 547,
     MAINTAINED = 548,
     ON = 549,
     RANGE = 550,
     EQUALITY = 551,
     GENERAL = 552,
     INTEGRITY = 553,
     CONSTRAINT = 554,
     CHECK = 555,
     KEY = 556,
     FOREACH = 557,
     FOREIGN = 558,
     KEYS = 559,
     BYTE_ORDER_MARK_UTF8 = 560,
     RANGE_REDUCE = 561,
     ADDITIVE_REDUCE = 562,
     MULTIPLICATIVE_REDUCE = 563,
     UNION_REDUCE = 564,
     INTERSECT_EXCEPT_REDUCE = 565,
     QVARINDECLLIST_REDUCE = 566,
     COMMA_DOLLAR = 567,
     UNARY_PREC = 568,
     SEQUENCE_TYPE_REDUCE = 569,
     OCCURS_STAR = 570,
     OCCURS_PLUS = 571,
     OCCURS_HOOK = 572,
     STEP_REDUCE = 573
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

} // zorba

/* Line 35 of lalr1.cc  */
#line 672 "/home/colea/work/xquery_temp1/build/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
