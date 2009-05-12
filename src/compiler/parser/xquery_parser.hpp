/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

#include <string>
#include <iostream>
#include "stack.hh"

namespace zorba
{
  class position;
  class location;
}

/* First part of user declarations.  */
#line 38 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <string>

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"

#define SYMTAB( n ) driver.symtab.get ((off_t) n)
#define SYMTAB_PUT( s ) driver.symtab.put (s)
#define LOC( p ) driver.createQueryLoc(p)

namespace zorba 
{

namespace parser 
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_ofor, *the_declare, *the_create;
}

class xquery_driver;


class FunctionSig {
public:
  rchandle<ParamList> param;
  rchandle<SequenceType> ret;

  FunctionSig (ParamList *param_, SequenceType *ret_ = NULL)
    : param (param_), ret (ret_)
  {}
};

class VarNameAndType {
public:
  std::string name;
  rchandle<SequenceType> type;


  VarNameAndType (std::string name_, rchandle<SequenceType> type_)
    : name (name_), type (type_)
  {}
};

}

#define YYDEBUG 1



/* Line 35 of lalr1.cc.  */
#line 111 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.hpp"

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

namespace zorba
{

  /// A Bison parser.
  class xquery_parser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
#line 139 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
{
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
}
/* Line 35 of lalr1.cc.  */
#line 179 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.hpp"
	;
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
     PI_TARGET_LITERAL = 269,
     PRAGMA_LITERAL_AND_END_PRAGMA = 270,
     QNAME_SVAL_AND_END_PRAGMA = 271,
     PREFIX_WILDCARD = 272,
     QNAME_SVAL = 273,
     QUOTE_ATTR_CONTENT = 274,
     STRING_LITERAL = 275,
     XML_COMMENT_LITERAL = 276,
     BLANK = 282,
     BLOCK = 283,
     EXIT = 284,
     BREAK = 285,
     LOOP = 286,
     CONTINUE = 287,
     WHILE = 288,
     VALIDATE = 289,
     TYPESWITCH = 290,
     ELEMENT = 291,
     DOCUMENT = 292,
     TEXT = 293,
     COMMENT = 294,
     DECLARE = 295,
     FUNCTION = 296,
     UPDATING = 297,
     SEQUENTIAL = 298,
     DETERMINISTIC = 299,
     NONDETERMINISTIC = 300,
     SIMPLE = 301,
     IF = 302,
     PROCESSING_INSTRUCTION = 303,
     MOST = 304,
     IMPORT = 305,
     SOME = 306,
     STABLE = 307,
     MODULE = 308,
     OPTION = 309,
     WORD = 310,
     SCHEMA = 311,
     SPACE = 312,
     SET = 313,
     LET = 314,
     CONSTRUCTION = 315,
     EVAL = 316,
     FOR = 317,
     OUTER = 318,
     SLIDING = 319,
     TUMBLING = 320,
     PREVIOUS = 321,
     NEXT = 322,
     ONLY = 323,
     WHEN = 324,
     COUNT = 325,
     ORDERING = 326,
     BASE_URI = 327,
     SCHEMA_ELEMENT = 328,
     DOCUMENT_NODE = 329,
     COPY_NAMESPACES = 330,
     INSTANCE = 331,
     SCHEMA_ATTRIBUTE = 332,
     BOUNDARY_SPACE = 333,
     DECIMAL_FORMAT = 334,
     DECIMAL_SEPARATOR = 335,
     GROUPING_SEPARATOR = 336,
     INFINITY = 337,
     MINUS_SIGN = 338,
     NaN = 339,
     PERCENT = 340,
     PER_MILLE = 341,
     ZERO_DIGIT = 342,
     DIGIT = 343,
     PATTERN_SEPARATOR = 344,
     ANCESTOR_AXIS = 345,
     ANCESTOR_OR_SELF_AXIS = 346,
     AND = 347,
     APOS = 348,
     AS = 349,
     ASCENDING = 350,
     AT = 351,
     ATTRIBUTE = 352,
     ATTRIBUTE_AXIS = 353,
     AT_SIGN = 354,
     CASE = 355,
     CASTABLE = 356,
     CAST = 357,
     CDATA_BEGIN = 358,
     CDATA_END = 359,
     CHILD_AXIS = 360,
     COLLATION = 361,
     COMMA = 362,
     COMMENT_BEGIN = 363,
     COMMENT_END = 364,
     DECIMAL_LITERAL = 365,
     CONTEXT = 366,
     VARIABLE = 367,
     DEFAULT = 368,
     DESCENDANT_AXIS = 369,
     DESCENDANT_OR_SELF_AXIS = 370,
     DESCENDING = 371,
     DIV = 372,
     DOLLAR = 373,
     DOT = 374,
     DOT_DOT = 375,
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
     FOLLOWING_AXIS = 391,
     FOLLOWING_SIBLING_AXIS = 392,
     FOLLOWS = 393,
     GE = 394,
     GETS = 395,
     GT = 396,
     HOOK = 397,
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
     ORDERED = 420,
     ORDER = 421,
     BY = 422,
     GROUP = 423,
     PARENT_AXIS = 424,
     PI_BEGIN = 425,
     PI_END = 426,
     PLUS = 427,
     PRAGMA_BEGIN = 428,
     PRAGMA_END = 429,
     PRECEDES = 430,
     PRECEDING_AXIS = 431,
     PRECEDING_SIBLING_AXIS = 432,
     PRESERVE = 433,
     QUOTE = 434,
     RBRACE = 435,
     RBRACK = 436,
     RETURN = 437,
     RPAR = 438,
     SATISFIES = 439,
     SCHEMA_ATTRIBUTE_LPAR = 440,
     SELF_AXIS = 441,
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
     END_PRAGMA = 468,
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
     TRY = 490,
     CATCH = 491,
     USING = 492,
     ALL = 493,
     ANY = 494,
     SENSITIVE = 495,
     FT_OPTION = 496,
     DIACRITICS = 497,
     INSENSITIVE = 498,
     DIFFERENT = 499,
     DISTANCE = 500,
     ENTIRE = 501,
     END = 502,
     CONTENT = 503,
     EXACTLY = 504,
     FROM = 505,
     FTAND = 506,
     FTCONTAINS = 507,
     FTNOT = 508,
     FTOR = 509,
     LANGUAGE = 510,
     LEVELS = 511,
     LOWERCASE = 512,
     OCCURS = 513,
     PARAGRAPH = 514,
     PHRASE = 515,
     RELATIONSHIP = 516,
     SAME = 517,
     SCORE = 518,
     SENTENCE = 519,
     SENTENCES = 520,
     TIMES = 521,
     UPPERCASE = 522,
     WEIGHT = 523,
     WINDOW = 524,
     WITHOUT = 525,
     STEMMING = 526,
     STOP = 527,
     WORDS = 528,
     THESAURUS = 529,
     WILDCARDS = 530,
     CREATE = 531,
     BUILD = 532,
     DROP = 533,
     UNIQUE = 534,
     INDEX = 535,
     HASH = 536,
     BTREE = 537,
     ON = 538,
     BYTE_ORDER_MARK_UTF8 = 539,
     FTCONTAINS_REDUCE = 540,
     RANGE_REDUCE = 541,
     ADDITIVE_REDUCE = 542,
     MULTIPLICATIVE_REDUCE = 543,
     UNION_REDUCE = 544,
     INTERSECT_EXCEPT_REDUCE = 545,
     QVARINDECLLIST_REDUCE = 546,
     COMMA_DOLLAR = 547,
     UNARY_PREC = 548,
     SEQUENCE_TYPE_REDUCE = 549,
     OCCURS_STAR = 550,
     OCCURS_PLUS = 551,
     OCCURS_HOOK = 552,
     STEP_REDUCE = 553
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

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the look-ahead token.
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
#endif /* ! YYDEBUG */


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

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;


    /* User arguments.  */
    xquery_driver& driver;
  };
}


#endif /* ! defined PARSER_HEADER_H */
