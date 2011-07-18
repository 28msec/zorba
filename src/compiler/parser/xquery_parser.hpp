
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
#line 35 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"


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
#line 74 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace zorba {

/* Line 35 of lalr1.cc  */
#line 88 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 35 of lalr1.cc  */
#line 98 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.hpp"

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
#line 146 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 139 "/home/mbrantner/zorba/vanilla/core/src/compiler/parser/xquery_parser.y"

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
#line 182 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.hpp"
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
     QNAME_SVAL = 279,
     EQNAME_SVAL = 280,
     ANNOTATION_QNAME_SVAL = 281,
     ANNOTATION_EQNAME_SVAL = 282,
     QUOTE_ATTR_CONTENT = 283,
     STRING_LITERAL = 284,
     XML_COMMENT_LITERAL = 285,
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
     NEXT = 308,
     NO = 309,
     ONLY = 310,
     OPTION = 311,
     ORDERING = 312,
     PREVIOUS = 313,
     PROCESSING_INSTRUCTION = 314,
     SCHEMA = 315,
     SCHEMA_ATTRIBUTE = 316,
     SCHEMA_ELEMENT = 317,
     SEQUENTIAL = 318,
     SET = 319,
     SIMPLE = 320,
     SLIDING = 321,
     SOME = 322,
     SPACE = 323,
     STABLE = 324,
     TEXT = 325,
     TUMBLING = 326,
     SWITCH = 327,
     TYPESWITCH = 328,
     UPDATING = 329,
     VALIDATE = 330,
     WHEN = 331,
     WORD = 332,
     DECIMAL_FORMAT = 333,
     DECIMAL_SEPARATOR = 334,
     GROUPING_SEPARATOR = 335,
     INFINITY_VALUE = 336,
     MINUS_SIGN = 337,
     NaN = 338,
     PERCENT = 339,
     PER_MILLE = 340,
     ZERO_DIGIT = 341,
     DIGIT = 342,
     PATTERN_SEPARATOR = 343,
     ANCESTOR = 344,
     ANCESTOR_OR_SELF = 345,
     AND = 346,
     APOS = 347,
     AS = 348,
     ASCENDING = 349,
     AT = 350,
     ATTRIBUTE = 351,
     AT_SIGN = 352,
     CASE = 353,
     CASTABLE = 354,
     CAST = 355,
     CDATA_BEGIN = 356,
     CDATA_END = 357,
     CHILD = 358,
     COLLATION = 359,
     COMMA = 360,
     COMMENT_BEGIN = 361,
     COMMENT_END = 362,
     DECIMAL_LITERAL = 363,
     CONTEXT = 364,
     VARIABLE = 365,
     DEFAULT = 366,
     DESCENDANT = 367,
     DESCENDANT_OR_SELF = 368,
     DESCENDING = 369,
     DIV = 370,
     DOLLAR = 371,
     DOT = 372,
     DOT_DOT = 373,
     COLON = 374,
     DOUBLE_COLON = 375,
     DOUBLE_LBRACE = 376,
     DOUBLE_LITERAL = 377,
     DOUBLE_RBRACE = 378,
     ELSE = 379,
     _EMPTY = 380,
     GREATEST = 381,
     LEAST = 382,
     EMPTY_TAG_END = 383,
     ENCODING = 384,
     EQUALS = 385,
     ESCAPE_APOS = 386,
     ESCAPE_QUOTE = 387,
     EVERY = 388,
     EXCEPT = 389,
     EXTERNAL = 390,
     FOLLOWING = 391,
     FOLLOWING_SIBLING = 392,
     FOLLOWS = 393,
     GE = 394,
     GETS = 395,
     GT = 396,
     HOOK = 397,
     HASH = 398,
     IDIV = 399,
     _IN = 400,
     INHERIT = 401,
     INTEGER_LITERAL = 402,
     INTERSECT = 403,
     IS = 404,
     ITEM = 405,
     LBRACE = 406,
     LBRACK = 407,
     LE = 408,
     LPAR = 409,
     LT_OR_START_TAG = 410,
     MINUS = 411,
     MOD = 412,
     NAMESPACE = 413,
     _NAN = 414,
     NE = 415,
     NODECOMP = 416,
     NOT_OPERATOR_KEYWORD = 417,
     NO_INHERIT = 418,
     NO_PRESERVE = 419,
     OR = 420,
     ORDER = 421,
     ORDERED = 422,
     BY = 423,
     GROUP = 424,
     PARENT = 425,
     PERCENTAGE = 426,
     PI_BEGIN = 427,
     PI_END = 428,
     PLUS = 429,
     PRAGMA_BEGIN = 430,
     PRAGMA_END = 431,
     PRECEDES = 432,
     PRECEDING = 433,
     PRECEDING_SIBLING = 434,
     PRESERVE = 435,
     QUOTE = 436,
     RBRACE = 437,
     RBRACK = 438,
     RETURN = 439,
     RPAR = 440,
     SATISFIES = 441,
     SELF = 442,
     SEMI = 443,
     SLASH = 444,
     SLASH_SLASH = 445,
     STAR = 446,
     START_TAG_END = 447,
     STRIP = 448,
     TAG_END = 449,
     THEN = 450,
     TO = 451,
     TREAT = 452,
     UNION = 453,
     UNORDERED = 454,
     VAL_EQ = 455,
     VAL_GE = 456,
     VAL_GT = 457,
     VAL_LE = 458,
     VAL_LT = 459,
     VAL_NE = 460,
     VALUECOMP = 461,
     VBAR = 462,
     EMPTY_SEQUENCE = 463,
     WHERE = 464,
     XML_COMMENT_BEGIN = 465,
     XML_COMMENT_END = 466,
     XQUERY = 467,
     VERSION = 468,
     START = 469,
     AFTER = 470,
     BEFORE = 471,
     REVALIDATION = 472,
     _STRICT = 473,
     LAX = 474,
     SKIP = 475,
     _DELETE = 476,
     NODE = 477,
     INSERT = 478,
     NODES = 479,
     RENAME = 480,
     REPLACE = 481,
     VALUE = 482,
     OF = 483,
     FIRST = 484,
     INTO = 485,
     LAST = 486,
     MODIFY = 487,
     COPY = 488,
     WITH = 489,
     LOCAL = 490,
     BREAK = 491,
     CONTINUE = 492,
     EXIT = 493,
     LOOP = 494,
     RETURNING = 495,
     WHILE = 496,
     TRY = 497,
     CATCH = 498,
     USING = 499,
     ALL = 500,
     ANY = 501,
     CONTAINS = 502,
     CONTENT = 503,
     DIACRITICS = 504,
     DIFFERENT = 505,
     DISTANCE = 506,
     END = 507,
     ENTIRE = 508,
     EXACTLY = 509,
     FROM = 510,
     FTAND = 511,
     FTNOT = 512,
     NOT = 513,
     FT_OPTION = 514,
     FTOR = 515,
     INSENSITIVE = 516,
     LANGUAGE = 517,
     LEVELS = 518,
     LOWERCASE = 519,
     OCCURS = 520,
     PARAGRAPH = 521,
     PARAGRAPHS = 522,
     PHRASE = 523,
     RELATIONSHIP = 524,
     SAME = 525,
     SCORE = 526,
     SENSITIVE = 527,
     SENTENCE = 528,
     SENTENCES = 529,
     STEMMING = 530,
     STOP = 531,
     THESAURUS = 532,
     TIMES = 533,
     UPPERCASE = 534,
     WEIGHT = 535,
     WILDCARDS = 536,
     WINDOW = 537,
     WITHOUT = 538,
     WORDS = 539,
     COLLECTION = 540,
     CONSTOPT = 541,
     APPEND_ONLY = 542,
     QUEUE = 543,
     MUTABLE = 544,
     READ_ONLY = 545,
     UNIQUE = 546,
     NON = 547,
     INDEX = 548,
     MANUALLY = 549,
     AUTOMATICALLY = 550,
     MAINTAINED = 551,
     ON = 552,
     RANGE = 553,
     EQUALITY = 554,
     GENERAL = 555,
     INTEGRITY = 556,
     CONSTRAINT = 557,
     CHECK = 558,
     KEY = 559,
     FOREACH = 560,
     FOREIGN = 561,
     KEYS = 562,
     BYTE_ORDER_MARK_UTF8 = 563,
     RANGE_REDUCE = 564,
     ADDITIVE_REDUCE = 565,
     MULTIPLICATIVE_REDUCE = 566,
     UNION_REDUCE = 567,
     INTERSECT_EXCEPT_REDUCE = 568,
     QVARINDECLLIST_REDUCE = 569,
     COMMA_DOLLAR = 570,
     UNARY_PREC = 571,
     SEQUENCE_TYPE_REDUCE = 572,
     OCCURS_STAR = 573,
     OCCURS_PLUS = 574,
     OCCURS_HOOK = 575,
     STEP_REDUCE = 576
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

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 35 of lalr1.cc  */
#line 687 "/home/mbrantner/zorba/vanilla/build/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
