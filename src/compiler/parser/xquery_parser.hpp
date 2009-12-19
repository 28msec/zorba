
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
#line 30 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parsetree/parsenodes.h"

#ifdef __GNUC__
  // disable a warning in location.hh which comes with bison
  // position.hh:141: warning: suggest parentheses around && within ||
#  pragma GCC diagnostic ignored "-Wparentheses"
#endif

#include "location.hh"

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wparentheses"
#endif

namespace zorba {
class xquery_driver;
}




/* Line 35 of lalr1.cc  */
#line 68 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace zorba {

/* Line 35 of lalr1.cc  */
#line 82 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 35 of lalr1.cc  */
#line 92 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.hpp"

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
#line 140 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 134 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"

  zorba::parsenode * node;
  zorba::exprnode * expr;
  zorba::FunctionSig *fnsig;
  zorba::VarNameAndType *varnametype;
  off_t sval;
  const char *strval;
	xqp_integer* ival;
	xqp_double* dval;
	xqp_decimal* decval;
  XQUERY_ERROR err;
  std::vector<std::pair<std::string, std::string> >* pair_vector;
  std::pair<std::string, std::string>* pair;
  CatchExpr::NameTestList *name_test_list;
  int intval;



/* Line 35 of lalr1.cc  */
#line 172 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.hpp"
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
     VALIDATE = 283,
     TYPESWITCH = 284,
     ELEMENT = 285,
     DOCUMENT = 286,
     TEXT = 287,
     COMMENT = 288,
     FUNCTION = 289,
     UPDATING = 290,
     SEQUENTIAL = 291,
     DETERMINISTIC = 292,
     NONDETERMINISTIC = 293,
     SIMPLE = 294,
     IF = 295,
     IMPORT = 296,
     PROCESSING_INSTRUCTION = 297,
     MOST = 298,
     SOME = 299,
     STABLE = 300,
     OPTION = 301,
     WORD = 302,
     SCHEMA = 303,
     SPACE = 304,
     SET = 305,
     LET = 306,
     CONSTRUCTION = 307,
     EVAL = 308,
     FOR = 309,
     OUTER = 310,
     SLIDING = 311,
     TUMBLING = 312,
     PREVIOUS = 313,
     NEXT = 314,
     ONLY = 315,
     WHEN = 316,
     COUNT = 317,
     ORDERING = 318,
     BASE_URI = 319,
     SCHEMA_ELEMENT = 320,
     DOCUMENT_NODE = 321,
     COPY_NAMESPACES = 322,
     INSTANCE = 323,
     SCHEMA_ATTRIBUTE = 324,
     BOUNDARY_SPACE = 325,
     DECIMAL_FORMAT = 326,
     DECIMAL_SEPARATOR = 327,
     GROUPING_SEPARATOR = 328,
     INFINITY_VALUE = 329,
     MINUS_SIGN = 330,
     NaN = 331,
     PERCENT = 332,
     PER_MILLE = 333,
     ZERO_DIGIT = 334,
     DIGIT = 335,
     PATTERN_SEPARATOR = 336,
     ANCESTOR_AXIS = 337,
     ANCESTOR_OR_SELF_AXIS = 338,
     AND = 339,
     APOS = 340,
     AS = 341,
     ASCENDING = 342,
     AT = 343,
     ATTRIBUTE = 344,
     ATTRIBUTE_AXIS = 345,
     AT_SIGN = 346,
     CASE = 347,
     CASTABLE = 348,
     CAST = 349,
     CDATA_BEGIN = 350,
     CDATA_END = 351,
     CHILD_AXIS = 352,
     COLLATION = 353,
     COMMA = 354,
     COMMENT_BEGIN = 355,
     COMMENT_END = 356,
     DECIMAL_LITERAL = 357,
     CONTEXT = 358,
     VARIABLE = 359,
     DEFAULT = 360,
     DESCENDANT_AXIS = 361,
     DESCENDANT_OR_SELF_AXIS = 362,
     DESCENDING = 363,
     DIV = 364,
     DOLLAR = 365,
     DOT = 366,
     DOT_DOT = 367,
     DOUBLE_LBRACE = 368,
     DOUBLE_LITERAL = 369,
     DOUBLE_RBRACE = 370,
     ELSE = 371,
     _EMPTY = 372,
     GREATEST = 373,
     LEAST = 374,
     EMPTY_TAG_END = 375,
     ENCODING = 376,
     EQUALS = 377,
     ESCAPE_APOS = 378,
     ESCAPE_QUOTE = 379,
     EVERY = 380,
     EXCEPT = 381,
     EXTERNAL = 382,
     FOLLOWING_AXIS = 383,
     FOLLOWING_SIBLING_AXIS = 384,
     FOLLOWS = 385,
     GE = 386,
     GETS = 387,
     GT = 388,
     HOOK = 389,
     IDIV = 390,
     _IN = 391,
     INHERIT = 392,
     INTEGER_LITERAL = 393,
     INTERSECT = 394,
     IS = 395,
     ITEM = 396,
     LBRACE = 397,
     LBRACK = 398,
     LE = 399,
     LPAR = 400,
     LT_OR_START_TAG = 401,
     MINUS = 402,
     MOD = 403,
     NAMESPACE = 404,
     _NAN = 405,
     NE = 406,
     NODECOMP = 407,
     NOT_OPERATOR_KEYWORD = 408,
     NO_INHERIT = 409,
     NO_PRESERVE = 410,
     OR = 411,
     ORDERED = 412,
     ORDER = 413,
     BY = 414,
     GROUP = 415,
     PARENT_AXIS = 416,
     PI_BEGIN = 417,
     PI_END = 418,
     PLUS = 419,
     PRAGMA_BEGIN = 420,
     PRAGMA_END = 421,
     PRECEDES = 422,
     PRECEDING_AXIS = 423,
     PRECEDING_SIBLING_AXIS = 424,
     PRESERVE = 425,
     QUOTE = 426,
     RBRACE = 427,
     RBRACK = 428,
     RETURN = 429,
     RPAR = 430,
     SATISFIES = 431,
     SCHEMA_ATTRIBUTE_LPAR = 432,
     SELF_AXIS = 433,
     SEMI = 434,
     SLASH = 435,
     SLASH_SLASH = 436,
     STAR = 437,
     START_TAG_END = 438,
     STRIP = 439,
     TAG_END = 440,
     THEN = 441,
     TO = 442,
     TREAT = 443,
     UNION = 444,
     UNORDERED = 445,
     VAL_EQ = 446,
     VAL_GE = 447,
     VAL_GT = 448,
     VAL_LE = 449,
     VAL_LT = 450,
     VAL_NE = 451,
     VALUECOMP = 452,
     VBAR = 453,
     EMPTY_SEQUENCE = 454,
     WHERE = 455,
     XML_COMMENT_BEGIN = 456,
     XML_COMMENT_END = 457,
     XQUERY = 458,
     VERSION = 459,
     END_PRAGMA = 460,
     START = 461,
     AFTER = 462,
     BEFORE = 463,
     REVALIDATION = 464,
     _STRICT = 465,
     LAX = 466,
     SKIP = 467,
     _DELETE = 468,
     NODE = 469,
     INSERT = 470,
     NODES = 471,
     RENAME = 472,
     REPLACE = 473,
     VALUE = 474,
     OF = 475,
     FIRST = 476,
     INTO = 477,
     LAST = 478,
     MODIFY = 479,
     COPY = 480,
     WITH = 481,
     RETURNING = 482,
     BLOCK = 483,
     EXIT = 484,
     BREAK = 485,
     LOOP = 486,
     CONTINUE = 487,
     WHILE = 488,
     TRY = 489,
     CATCH = 490,
     USING = 491,
     ALL = 492,
     ANY = 493,
     SENSITIVE = 494,
     FT_OPTION = 495,
     DIACRITICS = 496,
     INSENSITIVE = 497,
     DIFFERENT = 498,
     DISTANCE = 499,
     ENTIRE = 500,
     END = 501,
     CONTENT = 502,
     EXACTLY = 503,
     FROM = 504,
     FTAND = 505,
     FTCONTAINS = 506,
     FTNOT = 507,
     FTOR = 508,
     LANGUAGE = 509,
     LEVELS = 510,
     LOWERCASE = 511,
     OCCURS = 512,
     PARAGRAPH = 513,
     PHRASE = 514,
     RELATIONSHIP = 515,
     SAME = 516,
     SCORE = 517,
     SENTENCE = 518,
     SENTENCES = 519,
     TIMES = 520,
     UPPERCASE = 521,
     WEIGHT = 522,
     WINDOW = 523,
     WITHOUT = 524,
     STEMMING = 525,
     STOP = 526,
     WORDS = 527,
     THESAURUS = 528,
     WILDCARDS = 529,
     COLLECTION = 530,
     CONST_ = 531,
     APPEND_ONLY = 532,
     QUEUE = 533,
     MUTABLE = 534,
     READ_ONLY = 535,
     UNIQUE = 536,
     NON = 537,
     INDEX = 538,
     MANUAL = 539,
     AUTOMATIC = 540,
     ON = 541,
     INTEGRITY = 542,
     CONSTRAINT = 543,
     CHECK = 544,
     KEY = 545,
     FOREACH = 546,
     FOREIGN = 547,
     KEYS = 548,
     BYTE_ORDER_MARK_UTF8 = 549,
     FTCONTAINS_REDUCE = 550,
     RANGE_REDUCE = 551,
     ADDITIVE_REDUCE = 552,
     MULTIPLICATIVE_REDUCE = 553,
     UNION_REDUCE = 554,
     INTERSECT_EXCEPT_REDUCE = 555,
     QVARINDECLLIST_REDUCE = 556,
     COMMA_DOLLAR = 557,
     UNARY_PREC = 558,
     SEQUENCE_TYPE_REDUCE = 559,
     OCCURS_STAR = 560,
     OCCURS_PLUS = 561,
     OCCURS_HOOK = 562,
     STEP_REDUCE = 563
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
#line 664 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
