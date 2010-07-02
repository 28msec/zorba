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
#line 31 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"


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
#line 73 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


namespace zorba {

/* Line 34 of lalr1.cc  */
#line 84 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.hpp"
  class position;
  class location;

} // zorba

/* Line 34 of lalr1.cc  */
#line 91 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.hpp"

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
#line 136 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 34 of lalr1.cc  */
#line 152 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"

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
#line 172 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.hpp"
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
     APOS_ATTR_CONTENT = 259,
     CHAR_LITERAL = 260,
     CHAR_LITERAL_AND_CDATA_END = 261,
     CHAR_LITERAL_AND_PI_END = 262,
     CHAR_REF_LITERAL = 263,
     ELEMENT_CONTENT = 264,
     ELEM_WILDCARD = 265,
     ENTITY_REF = 266,
     EXPR_COMMENT_LITERAL = 267,
     PI_NCNAME_LBRACE = 268,
     NCNAME_SVAL = 269,
     PRAGMA_LITERAL_AND_END_PRAGMA = 270,
     QNAME_SVAL_AND_END_PRAGMA = 271,
     PREFIX_WILDCARD = 272,
     COMP_ELEMENT_QNAME_LBRACE = 273,
     COMP_ATTRIBUTE_QNAME_LBRACE = 274,
     COMP_PI_NCNAME_LBRACE = 275,
     QNAME_SVAL = 276,
     QUOTE_ATTR_CONTENT = 277,
     STRING_LITERAL = 278,
     XML_COMMENT_LITERAL = 279,
     DECLARE = 282,
     MODULE = 283,
     BLANK = 284,
     BASE_URI = 285,
     BOUNDARY_SPACE = 286,
     COMMENT = 287,
     CONSTRUCTION = 288,
     COPY_NAMESPACES = 289,
     COUNT = 290,
     DETERMINISTIC = 291,
     DOCUMENT = 292,
     DOCUMENT_NODE = 293,
     ELEMENT = 294,
     EVAL = 295,
     FOR = 296,
     FUNCTION = 297,
     IF = 298,
     IMPORT = 299,
     INSTANCE = 300,
     LET = 301,
     MOST = 302,
     NEXT = 303,
     NO = 304,
     NONDETERMINISTIC = 305,
     ONLY = 306,
     OPTION = 307,
     ORDERING = 308,
     OUTER = 309,
     PREVIOUS = 310,
     PROCESSING_INSTRUCTION = 311,
     SCHEMA = 312,
     SCHEMA_ATTRIBUTE = 313,
     SCHEMA_ELEMENT = 314,
     SEQUENTIAL = 315,
     SET = 316,
     SIMPLE = 317,
     SLIDING = 318,
     SOME = 319,
     SPACE = 320,
     STABLE = 321,
     TEXT = 322,
     TUMBLING = 323,
     SWITCH = 324,
     TYPESWITCH = 325,
     UPDATING = 326,
     VALIDATE = 327,
     WHEN = 328,
     WORD = 329,
     DECIMAL_FORMAT = 330,
     DECIMAL_SEPARATOR = 331,
     GROUPING_SEPARATOR = 332,
     INFINITY_VALUE = 333,
     MINUS_SIGN = 334,
     NaN = 335,
     PERCENT = 336,
     PER_MILLE = 337,
     ZERO_DIGIT = 338,
     DIGIT = 339,
     PATTERN_SEPARATOR = 340,
     ANCESTOR = 341,
     ANCESTOR_OR_SELF = 342,
     AND = 343,
     APOS = 344,
     AS = 345,
     ASCENDING = 346,
     AT = 347,
     ATTRIBUTE = 348,
     AT_SIGN = 349,
     CASE = 350,
     CASTABLE = 351,
     CAST = 352,
     CDATA_BEGIN = 353,
     CDATA_END = 354,
     CHILD = 355,
     COLLATION = 356,
     COMMA = 357,
     COMMENT_BEGIN = 358,
     COMMENT_END = 359,
     DECIMAL_LITERAL = 360,
     CONTEXT = 361,
     VARIABLE = 362,
     DEFAULT = 363,
     DESCENDANT = 364,
     DESCENDANT_OR_SELF = 365,
     DESCENDING = 366,
     DIV = 367,
     DOLLAR = 368,
     DOT = 369,
     DOT_DOT = 370,
     DOUBLE_COLON = 371,
     DOUBLE_LBRACE = 372,
     DOUBLE_LITERAL = 373,
     DOUBLE_RBRACE = 374,
     ELSE = 375,
     _EMPTY = 376,
     GREATEST = 377,
     LEAST = 378,
     EMPTY_TAG_END = 379,
     ENCODING = 380,
     EQUALS = 381,
     ESCAPE_APOS = 382,
     ESCAPE_QUOTE = 383,
     EVERY = 384,
     EXCEPT = 385,
     EXTERNAL = 386,
     FOLLOWING = 387,
     FOLLOWING_SIBLING = 388,
     FOLLOWS = 389,
     GE = 390,
     GETS = 391,
     GT = 392,
     HOOK = 393,
     HASH = 394,
     IDIV = 395,
     _IN = 396,
     INHERIT = 397,
     INTEGER_LITERAL = 398,
     INTERSECT = 399,
     IS = 400,
     ITEM = 401,
     LBRACE = 402,
     LBRACK = 403,
     LE = 404,
     LPAR = 405,
     LT_OR_START_TAG = 406,
     MINUS = 407,
     MOD = 408,
     NAMESPACE = 409,
     _NAN = 410,
     NE = 411,
     NODECOMP = 412,
     NOT_OPERATOR_KEYWORD = 413,
     NO_INHERIT = 414,
     NO_PRESERVE = 415,
     OR = 416,
     ORDER = 417,
     ORDERED = 418,
     BY = 419,
     GROUP = 420,
     PARENT = 421,
     PI_BEGIN = 422,
     PI_END = 423,
     PLUS = 424,
     PRAGMA_BEGIN = 425,
     PRAGMA_END = 426,
     PRECEDES = 427,
     PRECEDING = 428,
     PRECEDING_SIBLING = 429,
     PRESERVE = 430,
     QUOTE = 431,
     RBRACE = 432,
     RBRACK = 433,
     RETURN = 434,
     RPAR = 435,
     SATISFIES = 436,
     SELF = 437,
     SEMI = 438,
     SLASH = 439,
     SLASH_SLASH = 440,
     STAR = 441,
     START_TAG_END = 442,
     STRIP = 443,
     TAG_END = 444,
     THEN = 445,
     TO = 446,
     TREAT = 447,
     UNION = 448,
     UNORDERED = 449,
     VAL_EQ = 450,
     VAL_GE = 451,
     VAL_GT = 452,
     VAL_LE = 453,
     VAL_LT = 454,
     VAL_NE = 455,
     VALUECOMP = 456,
     VBAR = 457,
     EMPTY_SEQUENCE = 458,
     WHERE = 459,
     XML_COMMENT_BEGIN = 460,
     XML_COMMENT_END = 461,
     XQUERY = 462,
     VERSION = 463,
     START = 464,
     AFTER = 465,
     BEFORE = 466,
     REVALIDATION = 467,
     _STRICT = 468,
     LAX = 469,
     SKIP = 470,
     _DELETE = 471,
     NODE = 472,
     INSERT = 473,
     NODES = 474,
     RENAME = 475,
     REPLACE = 476,
     VALUE = 477,
     OF = 478,
     FIRST = 479,
     INTO = 480,
     LAST = 481,
     MODIFY = 482,
     COPY = 483,
     WITH = 484,
     BLOCK = 485,
     BREAK = 486,
     CONTINUE = 487,
     EXIT = 488,
     LOOP = 489,
     RETURNING = 490,
     WHILE = 491,
     TRY = 492,
     CATCH = 493,
     USING = 494,
     ALL = 495,
     ANY = 496,
     CONTAINS = 497,
     CONTENT = 498,
     DIACRITICS = 499,
     DIFFERENT = 500,
     DISTANCE = 501,
     END = 502,
     ENTIRE = 503,
     EXACTLY = 504,
     FROM = 505,
     FTAND = 506,
     FTNOT = 507,
     NOT = 508,
     FT_OPTION = 509,
     FTOR = 510,
     INSENSITIVE = 511,
     LANGUAGE = 512,
     LEVELS = 513,
     LOWERCASE = 514,
     OCCURS = 515,
     PARAGRAPH = 516,
     PARAGRAPHS = 517,
     PHRASE = 518,
     RELATIONSHIP = 519,
     SAME = 520,
     SCORE = 521,
     SENSITIVE = 522,
     SENTENCE = 523,
     SENTENCES = 524,
     STEMMING = 525,
     STOP = 526,
     THESAURUS = 527,
     TIMES = 528,
     UPPERCASE = 529,
     WEIGHT = 530,
     WILDCARDS = 531,
     WINDOW = 532,
     WITHOUT = 533,
     WORDS = 534,
     COLLECTION = 535,
     CONSTOPT = 536,
     APPEND_ONLY = 537,
     QUEUE = 538,
     MUTABLE = 539,
     READ_ONLY = 540,
     UNIQUE = 541,
     NON = 542,
     INDEX = 543,
     MANUALLY = 544,
     AUTOMATICALLY = 545,
     MAINTAINED = 546,
     ON = 547,
     RANGE = 548,
     EQUALITY = 549,
     GENERAL = 550,
     INTEGRITY = 551,
     CONSTRAINT = 552,
     CHECK = 553,
     KEY = 554,
     FOREACH = 555,
     FOREIGN = 556,
     KEYS = 557,
     BYTE_ORDER_MARK_UTF8 = 558,
     RANGE_REDUCE = 559,
     ADDITIVE_REDUCE = 560,
     MULTIPLICATIVE_REDUCE = 561,
     UNION_REDUCE = 562,
     INTERSECT_EXCEPT_REDUCE = 563,
     QVARINDECLLIST_REDUCE = 564,
     COMMA_DOLLAR = 565,
     UNARY_PREC = 566,
     SEQUENCE_TYPE_REDUCE = 567,
     OCCURS_STAR = 568,
     OCCURS_PLUS = 569,
     OCCURS_HOOK = 570,
     STEP_REDUCE = 571
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

/* Line 34 of lalr1.cc  */
#line 670 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
