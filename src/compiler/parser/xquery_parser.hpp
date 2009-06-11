
/* A Bison parser, made by GNU Bison 2.4.  */

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
#line 30 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parsetree/parsenodes.h"
namespace zorba {
class xquery_driver;
}



/* Line 35 of lalr1.cc  */
#line 54 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.hpp"


#include <string>
#include <iostream>
#include "stack.hh"


/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace zorba {

/* Line 35 of lalr1.cc  */
#line 68 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.hpp"
  class position;
  class location;

/* Line 35 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 35 of lalr1.cc  */
#line 78 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.hpp"

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
#line 126 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.hpp"

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 120 "/home/soso/work/zorba/trunk/zorba/src/compiler/parser/xquery_parser.y"

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



/* Line 35 of lalr1.cc  */
#line 157 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.hpp"
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
     BLANK = 281,
     BLOCK = 282,
     EXIT = 283,
     BREAK = 284,
     LOOP = 285,
     CONTINUE = 286,
     WHILE = 287,
     VALIDATE = 288,
     TYPESWITCH = 289,
     ELEMENT = 290,
     DOCUMENT = 291,
     TEXT = 292,
     COMMENT = 293,
     DECLARE = 294,
     FUNCTION = 295,
     UPDATING = 296,
     SEQUENTIAL = 297,
     DETERMINISTIC = 298,
     NONDETERMINISTIC = 299,
     SIMPLE = 300,
     IF = 301,
     PROCESSING_INSTRUCTION = 302,
     MOST = 303,
     IMPORT = 304,
     SOME = 305,
     STABLE = 306,
     MODULE = 307,
     OPTION = 308,
     WORD = 309,
     SCHEMA = 310,
     SPACE = 311,
     SET = 312,
     LET = 313,
     CONSTRUCTION = 314,
     EVAL = 315,
     FOR = 316,
     OUTER = 317,
     SLIDING = 318,
     TUMBLING = 319,
     PREVIOUS = 320,
     NEXT = 321,
     ONLY = 322,
     WHEN = 323,
     COUNT = 324,
     ORDERING = 325,
     BASE_URI = 326,
     SCHEMA_ELEMENT = 327,
     DOCUMENT_NODE = 328,
     COPY_NAMESPACES = 329,
     INSTANCE = 330,
     SCHEMA_ATTRIBUTE = 331,
     BOUNDARY_SPACE = 332,
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
     ANCESTOR_AXIS = 344,
     ANCESTOR_OR_SELF_AXIS = 345,
     AND = 346,
     APOS = 347,
     AS = 348,
     ASCENDING = 349,
     AT = 350,
     ATTRIBUTE = 351,
     ATTRIBUTE_AXIS = 352,
     AT_SIGN = 353,
     CASE = 354,
     CASTABLE = 355,
     CAST = 356,
     CDATA_BEGIN = 357,
     CDATA_END = 358,
     CHILD_AXIS = 359,
     COLLATION = 360,
     COMMA = 361,
     COMMENT_BEGIN = 362,
     COMMENT_END = 363,
     DECIMAL_LITERAL = 364,
     CONTEXT = 365,
     VARIABLE = 366,
     DEFAULT = 367,
     DESCENDANT_AXIS = 368,
     DESCENDANT_OR_SELF_AXIS = 369,
     DESCENDING = 370,
     DIV = 371,
     DOLLAR = 372,
     DOT = 373,
     DOT_DOT = 374,
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
     FOLLOWING_AXIS = 390,
     FOLLOWING_SIBLING_AXIS = 391,
     FOLLOWS = 392,
     GE = 393,
     GETS = 394,
     GT = 395,
     HOOK = 396,
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
     ORDERED = 419,
     ORDER = 420,
     BY = 421,
     GROUP = 422,
     PARENT_AXIS = 423,
     PI_BEGIN = 424,
     PI_END = 425,
     PLUS = 426,
     PRAGMA_BEGIN = 427,
     PRAGMA_END = 428,
     PRECEDES = 429,
     PRECEDING_AXIS = 430,
     PRECEDING_SIBLING_AXIS = 431,
     PRESERVE = 432,
     QUOTE = 433,
     RBRACE = 434,
     RBRACK = 435,
     RETURN = 436,
     RPAR = 437,
     SATISFIES = 438,
     SCHEMA_ATTRIBUTE_LPAR = 439,
     SELF_AXIS = 440,
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
     END_PRAGMA = 467,
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
     CREATE = 530,
     BUILD = 531,
     DROP = 532,
     UNIQUE = 533,
     INDEX = 534,
     HASH = 535,
     BTREE = 536,
     ON = 537,
     BYTE_ORDER_MARK_UTF8 = 538,
     FTCONTAINS_REDUCE = 539,
     RANGE_REDUCE = 540,
     ADDITIVE_REDUCE = 541,
     MULTIPLICATIVE_REDUCE = 542,
     UNION_REDUCE = 543,
     INTERSECT_EXCEPT_REDUCE = 544,
     QVARINDECLLIST_REDUCE = 545,
     COMMA_DOLLAR = 546,
     UNARY_PREC = 547,
     SEQUENCE_TYPE_REDUCE = 548,
     OCCURS_STAR = 549,
     OCCURS_PLUS = 550,
     OCCURS_HOOK = 551,
     STEP_REDUCE = 552
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
#line 637 "/home/soso/work/zorba/trunk/zorba/build/src/compiler/parser/xquery_parser.hpp"



#endif /* ! defined PARSER_HEADER_H */
