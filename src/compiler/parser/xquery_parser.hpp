/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2010 Free Software Foundation, Inc.
   
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

/* Line 34 of lalr1.cc  */
#line 31 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


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







/* Line 34 of lalr1.cc  */
#line 73 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


namespace zorba {

/* Line 34 of lalr1.cc  */
#line 84 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.hpp"
  class position;
  class location;

} // zorba

/* Line 34 of lalr1.cc  */
#line 91 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.hpp"

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

/* Line 34 of lalr1.cc  */
#line 136 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 34 of lalr1.cc  */
#line 152 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

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



/* Line 34 of lalr1.cc  */
#line 172 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.hpp"
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
     BASE_URI = 286,
     BOUNDARY_SPACE = 287,
     COMMENT = 288,
     CONSTRUCTION = 289,
     COPY_NAMESPACES = 290,
     COUNT = 291,
     DETERMINISTIC = 292,
     DOCUMENT = 293,
     DOCUMENT_NODE = 294,
     ELEMENT = 295,
     EVAL = 296,
     FOR = 297,
     FUNCTION = 298,
     IF = 299,
     IMPORT = 300,
     INSTANCE = 301,
     LET = 302,
     MOST = 303,
     NEXT = 304,
     NO = 305,
     NONDETERMINISTIC = 306,
     ONLY = 307,
     OPTION = 308,
     ORDERING = 309,
     OUTER = 310,
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
     PI_BEGIN = 423,
     PI_END = 424,
     PLUS = 425,
     PRAGMA_BEGIN = 426,
     PRAGMA_END = 427,
     PRECEDES = 428,
     PRECEDING = 429,
     PRECEDING_SIBLING = 430,
     PRESERVE = 431,
     QUOTE = 432,
     RBRACE = 433,
     RBRACK = 434,
     RETURN = 435,
     RPAR = 436,
     SATISFIES = 437,
     SELF = 438,
     SEMI = 439,
     SLASH = 440,
     SLASH_SLASH = 441,
     STAR = 442,
     START_TAG_END = 443,
     STRIP = 444,
     TAG_END = 445,
     THEN = 446,
     TO = 447,
     TREAT = 448,
     UNION = 449,
     UNORDERED = 450,
     VAL_EQ = 451,
     VAL_GE = 452,
     VAL_GT = 453,
     VAL_LE = 454,
     VAL_LT = 455,
     VAL_NE = 456,
     VALUECOMP = 457,
     VBAR = 458,
     EMPTY_SEQUENCE = 459,
     WHERE = 460,
     XML_COMMENT_BEGIN = 461,
     XML_COMMENT_END = 462,
     XQUERY = 463,
     VERSION = 464,
     START = 465,
     AFTER = 466,
     BEFORE = 467,
     REVALIDATION = 468,
     _STRICT = 469,
     LAX = 470,
     SKIP = 471,
     _DELETE = 472,
     NODE = 473,
     INSERT = 474,
     NODES = 475,
     RENAME = 476,
     REPLACE = 477,
     VALUE = 478,
     OF = 479,
     FIRST = 480,
     INTO = 481,
     LAST = 482,
     MODIFY = 483,
     COPY = 484,
     WITH = 485,
     BLOCK = 486,
     BREAK = 487,
     CONTINUE = 488,
     EXIT = 489,
     LOOP = 490,
     RETURNING = 491,
     WHILE = 492,
     TRY = 493,
     CATCH = 494,
     USING = 495,
     ALL = 496,
     ANY = 497,
     CONTAINS = 498,
     CONTENT = 499,
     DIACRITICS = 500,
     DIFFERENT = 501,
     DISTANCE = 502,
     END = 503,
     ENTIRE = 504,
     EXACTLY = 505,
     FROM = 506,
     FTAND = 507,
     FTNOT = 508,
     NOT = 509,
     FT_OPTION = 510,
     FTOR = 511,
     INSENSITIVE = 512,
     LANGUAGE = 513,
     LEVELS = 514,
     LOWERCASE = 515,
     OCCURS = 516,
     PARAGRAPH = 517,
     PARAGRAPHS = 518,
     PHRASE = 519,
     RELATIONSHIP = 520,
     SAME = 521,
     SCORE = 522,
     SENSITIVE = 523,
     SENTENCE = 524,
     SENTENCES = 525,
     STEMMING = 526,
     STOP = 527,
     THESAURUS = 528,
     TIMES = 529,
     UPPERCASE = 530,
     WEIGHT = 531,
     WILDCARDS = 532,
     WINDOW = 533,
     WITHOUT = 534,
     WORDS = 535,
     COLLECTION = 536,
     CONSTOPT = 537,
     APPEND_ONLY = 538,
     QUEUE = 539,
     MUTABLE = 540,
     READ_ONLY = 541,
     UNIQUE = 542,
     NON = 543,
     INDEX = 544,
     MANUALLY = 545,
     AUTOMATICALLY = 546,
     MAINTAINED = 547,
     ON = 548,
     RANGE = 549,
     EQUALITY = 550,
     GENERAL = 551,
     INTEGRITY = 552,
     CONSTRAINT = 553,
     CHECK = 554,
     KEY = 555,
     FOREACH = 556,
     FOREIGN = 557,
     KEYS = 558,
     BYTE_ORDER_MARK_UTF8 = 559,
     RANGE_REDUCE = 560,
     ADDITIVE_REDUCE = 561,
     MULTIPLICATIVE_REDUCE = 562,
     UNION_REDUCE = 563,
     INTERSECT_EXCEPT_REDUCE = 564,
     QVARINDECLLIST_REDUCE = 565,
     COMMA_DOLLAR = 566,
     UNARY_PREC = 567,
     SEQUENCE_TYPE_REDUCE = 568,
     OCCURS_STAR = 569,
     OCCURS_PLUS = 570,
     OCCURS_HOOK = 571,
     STEP_REDUCE = 572
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

/* Line 34 of lalr1.cc  */
#line 670 "/home/colea/work/xquery/build_fast/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
