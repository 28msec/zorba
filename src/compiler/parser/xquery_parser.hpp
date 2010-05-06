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
#line 31 "/home/colea/work/xquery_temp4/src/compiler/parser/xquery_parser.y"

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





/* Line 34 of lalr1.cc  */
#line 74 "/home/colea/work/xquery_temp4/build_fast/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


namespace zorba {

/* Line 34 of lalr1.cc  */
#line 85 "/home/colea/work/xquery_temp4/build_fast/src/compiler/parser/xquery_parser.hpp"
  class position;
  class location;

} // zorba

/* Line 34 of lalr1.cc  */
#line 92 "/home/colea/work/xquery_temp4/build_fast/src/compiler/parser/xquery_parser.hpp"

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
#line 137 "/home/colea/work/xquery_temp4/build_fast/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 34 of lalr1.cc  */
#line 145 "/home/colea/work/xquery_temp4/src/compiler/parser/xquery_parser.y"

    zorba::parsenode *node;
    zorba::exprnode *expr;
    zorba::FunctionSig *fnsig;
    zorba::VarNameAndType *varnametype;
    off_t sval;
    const char *strval;
    xqp_integer *ival;
    xqp_double *dval;
    xqp_decimal *decval;
    XQUERY_ERROR err;
    string_list_t *strlist;
    string_pair_t *strpair;
    std::vector<string_pair_t> *vstrpair;
    CatchExpr::NameTestList *name_test_list;
    FTStopWordOption::incl_excl_list_t *incl_excl_list;
    FTSelection::pos_filter_list_t *pos_filter_list;
    FTThesaurusOption::thesaurus_id_list_t *thesaurus_id_list;
    ft_anyall_mode::type ft_anyall_value;



/* Line 34 of lalr1.cc  */
#line 173 "/home/colea/work/xquery_temp4/build_fast/src/compiler/parser/xquery_parser.hpp"
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
     TYPESWITCH = 322,
     UPDATING = 323,
     VALIDATE = 324,
     WHEN = 325,
     WORD = 326,
     DECIMAL_FORMAT = 327,
     DECIMAL_SEPARATOR = 328,
     GROUPING_SEPARATOR = 329,
     INFINITY_VALUE = 330,
     MINUS_SIGN = 331,
     NaN = 332,
     PERCENT = 333,
     PER_MILLE = 334,
     ZERO_DIGIT = 335,
     DIGIT = 336,
     PATTERN_SEPARATOR = 337,
     ANCESTOR_AXIS = 338,
     ANCESTOR_OR_SELF_AXIS = 339,
     AND = 340,
     APOS = 341,
     AS = 342,
     ASCENDING = 343,
     AT = 344,
     ATTRIBUTE = 345,
     ATTRIBUTE_AXIS = 346,
     AT_SIGN = 347,
     CASE = 348,
     CASTABLE = 349,
     CAST = 350,
     CDATA_BEGIN = 351,
     CDATA_END = 352,
     CHILD_AXIS = 353,
     COLLATION = 354,
     COMMA = 355,
     COMMENT_BEGIN = 356,
     COMMENT_END = 357,
     DECIMAL_LITERAL = 358,
     CONTEXT = 359,
     VARIABLE = 360,
     DEFAULT = 361,
     DESCENDANT_AXIS = 362,
     DESCENDANT_OR_SELF_AXIS = 363,
     DESCENDING = 364,
     DIV = 365,
     DOLLAR = 366,
     DOT = 367,
     DOT_DOT = 368,
     DOUBLE_LBRACE = 369,
     DOUBLE_LITERAL = 370,
     DOUBLE_RBRACE = 371,
     ELSE = 372,
     _EMPTY = 373,
     GREATEST = 374,
     LEAST = 375,
     EMPTY_TAG_END = 376,
     ENCODING = 377,
     EQUALS = 378,
     ESCAPE_APOS = 379,
     ESCAPE_QUOTE = 380,
     EVERY = 381,
     EXCEPT = 382,
     EXTERNAL = 383,
     FOLLOWING_AXIS = 384,
     FOLLOWING_SIBLING_AXIS = 385,
     FOLLOWS = 386,
     GE = 387,
     GETS = 388,
     GT = 389,
     HOOK = 390,
     HASH = 391,
     IDIV = 392,
     _IN = 393,
     INHERIT = 394,
     INTEGER_LITERAL = 395,
     INTERSECT = 396,
     IS = 397,
     ITEM = 398,
     LBRACE = 399,
     LBRACK = 400,
     LE = 401,
     LPAR = 402,
     LT_OR_START_TAG = 403,
     MINUS = 404,
     MOD = 405,
     NAMESPACE = 406,
     _NAN = 407,
     NE = 408,
     NODECOMP = 409,
     NOT_OPERATOR_KEYWORD = 410,
     NO_INHERIT = 411,
     NO_PRESERVE = 412,
     OR = 413,
     ORDER = 414,
     ORDERED = 415,
     BY = 416,
     GROUP = 417,
     PARENT_AXIS = 418,
     PI_BEGIN = 419,
     PI_END = 420,
     PLUS = 421,
     PRAGMA_BEGIN = 422,
     PRAGMA_END = 423,
     PRECEDES = 424,
     PRECEDING_AXIS = 425,
     PRECEDING_SIBLING_AXIS = 426,
     PRESERVE = 427,
     QUOTE = 428,
     RBRACE = 429,
     RBRACK = 430,
     RETURN = 431,
     RPAR = 432,
     SATISFIES = 433,
     SCHEMA_ATTRIBUTE_LPAR = 434,
     SELF_AXIS = 435,
     SEMI = 436,
     SLASH = 437,
     SLASH_SLASH = 438,
     STAR = 439,
     START_TAG_END = 440,
     STRIP = 441,
     TAG_END = 442,
     THEN = 443,
     TO = 444,
     TREAT = 445,
     UNION = 446,
     UNORDERED = 447,
     VAL_EQ = 448,
     VAL_GE = 449,
     VAL_GT = 450,
     VAL_LE = 451,
     VAL_LT = 452,
     VAL_NE = 453,
     VALUECOMP = 454,
     VBAR = 455,
     EMPTY_SEQUENCE = 456,
     WHERE = 457,
     XML_COMMENT_BEGIN = 458,
     XML_COMMENT_END = 459,
     XQUERY = 460,
     VERSION = 461,
     END_PRAGMA = 462,
     START = 463,
     AFTER = 464,
     BEFORE = 465,
     REVALIDATION = 466,
     _STRICT = 467,
     LAX = 468,
     SKIP = 469,
     _DELETE = 470,
     NODE = 471,
     INSERT = 472,
     NODES = 473,
     RENAME = 474,
     REPLACE = 475,
     VALUE = 476,
     OF = 477,
     FIRST = 478,
     INTO = 479,
     LAST = 480,
     MODIFY = 481,
     COPY = 482,
     WITH = 483,
     BLOCK = 484,
     BREAK = 485,
     CONTINUE = 486,
     EXIT = 487,
     LOOP = 488,
     RETURNING = 489,
     WHILE = 490,
     TRY = 491,
     CATCH = 492,
     USING = 493,
     ALL = 494,
     ANY = 495,
     CONTAINS = 496,
     CONTENT = 497,
     DIACRITICS = 498,
     DIFFERENT = 499,
     DISTANCE = 500,
     END = 501,
     ENTIRE = 502,
     EXACTLY = 503,
     FROM = 504,
     FTAND = 505,
     FTNOT = 506,
     NOT = 507,
     FT_OPTION = 508,
     FTOR = 509,
     INSENSITIVE = 510,
     LANGUAGE = 511,
     LEVELS = 512,
     LOWERCASE = 513,
     OCCURS = 514,
     PARAGRAPH = 515,
     PARAGRAPHS = 516,
     PHRASE = 517,
     RELATIONSHIP = 518,
     SAME = 519,
     SCORE = 520,
     SENSITIVE = 521,
     SENTENCE = 522,
     SENTENCES = 523,
     STEMMING = 524,
     STOP = 525,
     THESAURUS = 526,
     TIMES = 527,
     UPPERCASE = 528,
     WEIGHT = 529,
     WILDCARDS = 530,
     WINDOW = 531,
     WITHOUT = 532,
     WORDS = 533,
     COLLECTION = 534,
     CONSTOPT = 535,
     APPEND_ONLY = 536,
     QUEUE = 537,
     MUTABLE = 538,
     READ_ONLY = 539,
     UNIQUE = 540,
     NON = 541,
     INDEX = 542,
     MANUALLY = 543,
     AUTOMATICALLY = 544,
     MAINTAINED = 545,
     ON = 546,
     RANGE = 547,
     EQUALITY = 548,
     INTEGRITY = 549,
     CONSTRAINT = 550,
     CHECK = 551,
     KEY = 552,
     FOREACH = 553,
     FOREIGN = 554,
     KEYS = 555,
     BYTE_ORDER_MARK_UTF8 = 556,
     RANGE_REDUCE = 557,
     ADDITIVE_REDUCE = 558,
     MULTIPLICATIVE_REDUCE = 559,
     UNION_REDUCE = 560,
     INTERSECT_EXCEPT_REDUCE = 561,
     QVARINDECLLIST_REDUCE = 562,
     COMMA_DOLLAR = 563,
     UNARY_PREC = 564,
     SEQUENCE_TYPE_REDUCE = 565,
     OCCURS_STAR = 566,
     OCCURS_PLUS = 567,
     OCCURS_HOOK = 568,
     STEP_REDUCE = 569
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
#line 668 "/home/colea/work/xquery_temp4/build_fast/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
