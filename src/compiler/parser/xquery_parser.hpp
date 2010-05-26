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

namespace zorba {
class xquery_driver;
}

typedef std::list<std::string> string_list_t;
typedef std::pair<std::string,std::string> string_pair_t;

class scanner_error {
public:
  std::string msg;

public:
  scanner_error(std::string _msg) : msg(_msg) { };

  static scanner_error* unrecognizedCharErr(const char* _error_token)
  {
    std::string token;
    // translate some common non-printable characters for better readability.
    if (*_error_token == '\t')
      token = "\\t";
    else if (*_error_token == '\n')
      token = "\\n";
    else if (*_error_token == '\r')
      token = "\\r";
    else if (*_error_token == ' ')
      token = "<blank>";
    else
      token = _error_token;

    return new scanner_error("syntax error, unexpected character '" + token + "'");
  };

  static scanner_error* unterminatedCommentErr()
  {
    return new scanner_error("syntax error, unexpected end of file, unterminated comment");
  }

  static scanner_error* unrecognizedIntegerErr(const char* _error_token)
  {
    return new scanner_error(std::string("syntax error, unexpected '") + _error_token + "', separator needed after numeric literal");
  }
};






/* Line 34 of lalr1.cc  */
#line 112 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


namespace zorba {

/* Line 34 of lalr1.cc  */
#line 123 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.hpp"
  class position;
  class location;

} // zorba

/* Line 34 of lalr1.cc  */
#line 130 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.hpp"

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
#line 175 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 34 of lalr1.cc  */
#line 190 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"

    zorba::parsenode *node;
    zorba::exprnode *expr;
    zorba::FunctionSig *fnsig;
    zorba::VarNameAndType *varnametype;
    off_t sval;
    const char *strval;
    xqp_integer *ival;
    xqp_double *dval;
    xqp_decimal *decval;
    scanner_error *err;
    string_list_t *strlist;
    string_pair_t *strpair;
    std::vector<string_pair_t> *vstrpair;
    CatchExpr::NameTestList *name_test_list;
    FTStopWordOption::incl_excl_list_t *incl_excl_list;
    FTSelection::pos_filter_list_t *pos_filter_list;
    FTThesaurusOption::thesaurus_id_list_t *thesaurus_id_list;
    ft_anyall_mode::type ft_anyall_value;



/* Line 34 of lalr1.cc  */
#line 211 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.hpp"
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
     QNAME_SVAL = 273,
     QUOTE_ATTR_CONTENT = 274,
     STRING_LITERAL = 275,
     XML_COMMENT_LITERAL = 276,
     DECLARE = 280,
     MODULE = 281,
     BLANK = 282,
     BASE_URI = 283,
     BOUNDARY_SPACE = 284,
     COMMENT = 285,
     CONSTRUCTION = 286,
     COPY_NAMESPACES = 287,
     COUNT = 288,
     DETERMINISTIC = 289,
     DOCUMENT = 290,
     DOCUMENT_NODE = 291,
     ELEMENT = 292,
     EVAL = 293,
     FOR = 294,
     FUNCTION = 295,
     IF = 296,
     IMPORT = 297,
     INSTANCE = 298,
     LET = 299,
     MOST = 300,
     NEXT = 301,
     NO = 302,
     NONDETERMINISTIC = 303,
     ONLY = 304,
     OPTION = 305,
     ORDERING = 306,
     OUTER = 307,
     PREVIOUS = 308,
     PROCESSING_INSTRUCTION = 309,
     SCHEMA = 310,
     SCHEMA_ATTRIBUTE = 311,
     SCHEMA_ELEMENT = 312,
     SEQUENTIAL = 313,
     SET = 314,
     SIMPLE = 315,
     SLIDING = 316,
     SOME = 317,
     SPACE = 318,
     STABLE = 319,
     TEXT = 320,
     TUMBLING = 321,
     SWITCH = 322,
     TYPESWITCH = 323,
     UPDATING = 324,
     VALIDATE = 325,
     WHEN = 326,
     WORD = 327,
     DECIMAL_FORMAT = 328,
     DECIMAL_SEPARATOR = 329,
     GROUPING_SEPARATOR = 330,
     INFINITY_VALUE = 331,
     MINUS_SIGN = 332,
     NaN = 333,
     PERCENT = 334,
     PER_MILLE = 335,
     ZERO_DIGIT = 336,
     DIGIT = 337,
     PATTERN_SEPARATOR = 338,
     ANCESTOR = 339,
     ANCESTOR_OR_SELF = 340,
     AND = 341,
     APOS = 342,
     AS = 343,
     ASCENDING = 344,
     AT = 345,
     ATTRIBUTE = 346,
     AT_SIGN = 347,
     CASE = 348,
     CASTABLE = 349,
     CAST = 350,
     CDATA_BEGIN = 351,
     CDATA_END = 352,
     CHILD = 353,
     COLLATION = 354,
     COMMA = 355,
     COMMENT_BEGIN = 356,
     COMMENT_END = 357,
     DECIMAL_LITERAL = 358,
     CONTEXT = 359,
     VARIABLE = 360,
     DEFAULT = 361,
     DESCENDANT = 362,
     DESCENDANT_OR_SELF = 363,
     DESCENDING = 364,
     DIV = 365,
     DOLLAR = 366,
     DOT = 367,
     DOT_DOT = 368,
     DOUBLE_COLON = 369,
     DOUBLE_LBRACE = 370,
     DOUBLE_LITERAL = 371,
     DOUBLE_RBRACE = 372,
     ELSE = 373,
     _EMPTY = 374,
     GREATEST = 375,
     LEAST = 376,
     EMPTY_TAG_END = 377,
     ENCODING = 378,
     EQUALS = 379,
     ESCAPE_APOS = 380,
     ESCAPE_QUOTE = 381,
     EVERY = 382,
     EXCEPT = 383,
     EXTERNAL = 384,
     FOLLOWING = 385,
     FOLLOWING_SIBLING = 386,
     FOLLOWS = 387,
     GE = 388,
     GETS = 389,
     GT = 390,
     HOOK = 391,
     HASH = 392,
     IDIV = 393,
     _IN = 394,
     INHERIT = 395,
     INTEGER_LITERAL = 396,
     INTERSECT = 397,
     IS = 398,
     ITEM = 399,
     LBRACE = 400,
     LBRACK = 401,
     LE = 402,
     LPAR = 403,
     LT_OR_START_TAG = 404,
     MINUS = 405,
     MOD = 406,
     NAMESPACE = 407,
     _NAN = 408,
     NE = 409,
     NODECOMP = 410,
     NOT_OPERATOR_KEYWORD = 411,
     NO_INHERIT = 412,
     NO_PRESERVE = 413,
     OR = 414,
     ORDER = 415,
     ORDERED = 416,
     BY = 417,
     GROUP = 418,
     PARENT = 419,
     PI_BEGIN = 420,
     PI_END = 421,
     PLUS = 422,
     PRAGMA_BEGIN = 423,
     PRAGMA_END = 424,
     PRECEDES = 425,
     PRECEDING = 426,
     PRECEDING_SIBLING = 427,
     PRESERVE = 428,
     QUOTE = 429,
     RBRACE = 430,
     RBRACK = 431,
     RETURN = 432,
     RPAR = 433,
     SATISFIES = 434,
     SCHEMA_ATTRIBUTE_LPAR = 435,
     SELF = 436,
     SEMI = 437,
     SLASH = 438,
     SLASH_SLASH = 439,
     STAR = 440,
     START_TAG_END = 441,
     STRIP = 442,
     TAG_END = 443,
     THEN = 444,
     TO = 445,
     TREAT = 446,
     UNION = 447,
     UNORDERED = 448,
     VAL_EQ = 449,
     VAL_GE = 450,
     VAL_GT = 451,
     VAL_LE = 452,
     VAL_LT = 453,
     VAL_NE = 454,
     VALUECOMP = 455,
     VBAR = 456,
     EMPTY_SEQUENCE = 457,
     WHERE = 458,
     XML_COMMENT_BEGIN = 459,
     XML_COMMENT_END = 460,
     XQUERY = 461,
     VERSION = 462,
     END_PRAGMA = 463,
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
#line 708 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
