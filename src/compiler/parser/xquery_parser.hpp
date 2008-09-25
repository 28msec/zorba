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
#line 38 "/Users/wcandillon/zorba/src/compiler/parser/xquery_parser.y"


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
#define LOC( p ) driver.createQueryLoc(p)

namespace zorba {
  namespace parser {
    extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_ofor;
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
}

#define YYDEBUG 1



/* Line 303 of lalr1.cc.  */
#line 93 "/Users/wcandillon/zorba/build/src/compiler/parser/xquery_parser.hpp"

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
#line 121 "/Users/wcandillon/zorba/src/compiler/parser/xquery_parser.y"
{
  zorba::parsenode * node;
  zorba::exprnode * expr;
  zorba::FunctionSig *fnsig;
  off_t sval;
  const char *strval;
	xqp_integer* ival;
	xqp_double* dval;
	xqp_decimal* decval;
}
/* Line 303 of lalr1.cc.  */
#line 156 "/Users/wcandillon/zorba/build/src/compiler/parser/xquery_parser.hpp"
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
     APOS_ATTR_CONTENT = 258,
     CHAR_LITERAL = 259,
     CHAR_LITERAL_AND_CDATA_END = 260,
     CHAR_LITERAL_AND_PI_END = 261,
     CHAR_REF_LITERAL = 262,
     ELEMENT_CONTENT = 263,
     ELEM_WILDCARD = 264,
     ENTITY_REF = 265,
     EXPR_COMMENT_LITERAL = 266,
     PI_NCNAME_LBRACE = 267,
     PI_TARGET_LITERAL = 268,
     PRAGMA_LITERAL_AND_END_PRAGMA = 269,
     QNAME_SVAL_AND_END_PRAGMA = 270,
     PREFIX_WILDCARD = 271,
     QNAME_SVAL = 272,
     QUOTE_ATTR_CONTENT = 273,
     STRING_LITERAL = 274,
     XML_COMMENT_LITERAL = 275,
     BLANK = 279,
     EXIT = 280,
     BREAK = 281,
     LOOP = 282,
     CONTINUE = 283,
     WHILE = 284,
     VALIDATE = 285,
     TYPESWITCH = 286,
     ELEMENT = 287,
     DOCUMENT = 288,
     TEXT = 289,
     COMMENT = 290,
     DECLARE = 291,
     FUNCTION = 292,
     UPDATING = 293,
     SEQUENTIAL = 294,
     IF = 295,
     PROCESSING_INSTRUCTION = 296,
     MOST = 297,
     IMPORT = 298,
     SOME = 299,
     STABLE = 300,
     MODULE = 301,
     OPTION = 302,
     WORD = 303,
     SCHEMA = 304,
     SPACE = 305,
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
     CONT = 319,
     BASE_URI = 320,
     SCHEMA_ELEMENT = 321,
     DOCUMENT_NODE = 322,
     COPY_NAMESPACES = 323,
     INSTANCE = 324,
     SCHEMA_ATTRIBUTE = 325,
     BOUNDARY_SPACE = 326,
     ANCESTOR_AXIS = 327,
     ANCESTOR_OR_SELF_AXIS = 328,
     AND = 329,
     APOS = 330,
     AS = 331,
     ASCENDING = 332,
     AT = 333,
     ATTRIBUTE = 334,
     ATTRIBUTE_AXIS = 335,
     AT_SIGN = 336,
     CASE = 337,
     CASTABLE = 338,
     CAST = 339,
     CDATA_BEGIN = 340,
     CDATA_END = 341,
     CHILD_AXIS = 342,
     COLLATION = 343,
     COMMA = 344,
     COMMENT_BEGIN = 345,
     COMMENT_END = 346,
     DECIMAL_LITERAL = 347,
     VARIABLE = 348,
     DEFAULT = 349,
     DESCENDANT_AXIS = 350,
     DESCENDANT_OR_SELF_AXIS = 351,
     DESCENDING = 352,
     DIV = 353,
     DOLLAR = 354,
     DOT = 355,
     DOT_DOT = 356,
     DOUBLE_LBRACE = 357,
     DOUBLE_LITERAL = 358,
     DOUBLE_RBRACE = 359,
     ELSE = 360,
     _EMPTY = 361,
     GREATEST = 362,
     LEAST = 363,
     EMPTY_TAG_END = 364,
     ENCODING = 365,
     EQUALS = 366,
     ESCAPE_APOS = 367,
     ESCAPE_QUOTE = 368,
     EVERY = 369,
     EXCEPT = 370,
     EXTERNAL = 371,
     FOLLOWING_AXIS = 372,
     FOLLOWING_SIBLING_AXIS = 373,
     FOLLOWS = 374,
     GE = 375,
     GETS = 376,
     GT = 377,
     HOOK = 378,
     IDIV = 379,
     _IN = 380,
     INHERIT = 381,
     INTEGER_LITERAL = 382,
     INTERSECT = 383,
     IS = 384,
     ITEM = 385,
     LBRACE = 386,
     LBRACK = 387,
     LE = 388,
     LPAR = 389,
     LT_OR_START_TAG = 390,
     MINUS = 391,
     MOD = 392,
     NAMESPACE = 393,
     _NAN = 394,
     NE = 395,
     NODECOMP = 396,
     NOT_OPERATOR_KEYWORD = 397,
     NO_INHERIT = 398,
     NO_PRESERVE = 399,
     OR = 400,
     ORDERED = 401,
     ORDER = 402,
     BY = 403,
     GROUP = 404,
     PARENT_AXIS = 405,
     PI_BEGIN = 406,
     PI_END = 407,
     PLUS = 408,
     PRAGMA_BEGIN = 409,
     PRAGMA_END = 410,
     PRECEDES = 411,
     PRECEDING_AXIS = 412,
     PRECEDING_SIBLING_AXIS = 413,
     PRESERVE = 414,
     QUOTE = 415,
     RBRACE = 416,
     RBRACK = 417,
     RETURN = 418,
     RPAR = 419,
     SATISFIES = 420,
     SCHEMA_ATTRIBUTE_LPAR = 421,
     SELF_AXIS = 422,
     SEMI = 423,
     SLASH = 424,
     SLASH_SLASH = 425,
     STAR = 426,
     START_TAG_END = 427,
     STRIP = 428,
     TAG_END = 429,
     THEN = 430,
     TO = 431,
     TREAT = 432,
     UNION = 433,
     UNORDERED = 434,
     UNRECOGNIZED = 435,
     VAL_EQ = 436,
     VAL_GE = 437,
     VAL_GT = 438,
     VAL_LE = 439,
     VAL_LT = 440,
     VAL_NE = 441,
     VALUECOMP = 442,
     VBAR = 443,
     EMPTY_SEQUENCE = 444,
     WHERE = 445,
     XML_COMMENT_BEGIN = 446,
     XML_COMMENT_END = 447,
     XQUERY = 448,
     VERSION = 449,
     END_PRAGMA = 450,
     START = 451,
     AFTER = 452,
     BEFORE = 453,
     REVALIDATION = 454,
     _STRICT = 455,
     LAX = 456,
     SKIP = 457,
     _DELETE = 458,
     NODE = 459,
     INSERT = 460,
     NODES = 461,
     RENAME = 462,
     REPLACE = 463,
     VALUE = 464,
     OF = 465,
     FIRST = 466,
     INTO = 467,
     LAST = 468,
     MODIFY = 469,
     COPY = 470,
     WITH = 471,
     TRY = 472,
     CATCH = 473,
     USING = 474,
     ALL = 475,
     ANY = 476,
     SENSITIVE = 477,
     FT_OPTION = 478,
     DIACRITICS = 479,
     INSENSITIVE = 480,
     DIFFERENT = 481,
     DISTANCE = 482,
     ENTIRE = 483,
     END = 484,
     CONTENT = 485,
     EXACTLY = 486,
     FROM = 487,
     FTAND = 488,
     FTCONTAINS = 489,
     FTNOT = 490,
     FTOR = 491,
     LANGUAGE = 492,
     LEVELS = 493,
     LOWERCASE = 494,
     OCCURS = 495,
     PARAGRAPH = 496,
     PHRASE = 497,
     RELATIONSHIP = 498,
     SAME = 499,
     SCORE = 500,
     SENTENCE = 501,
     SENTENCES = 502,
     TIMES = 503,
     UPPERCASE = 504,
     WEIGHT = 505,
     WINDOW = 506,
     WITHOUT = 507,
     STEMMING = 508,
     STOP = 509,
     WORDS = 510,
     THESAURUS = 511,
     WILDCARDS = 512,
     FTCONTAINS_REDUCE = 513,
     RANGE_REDUCE = 514,
     ADDITIVE_REDUCE = 515,
     MULTIPLICATIVE_REDUCE = 516,
     UNION_REDUCE = 517,
     INTERSECT_EXCEPT_REDUCE = 518,
     QVARINDECLLIST_REDUCE = 519,
     COMMA_DOLLAR = 520,
     UNARY_PREC = 521,
     SEQUENCE_TYPE_REDUCE = 522,
     OCCURS_STAR = 523,
     OCCURS_PLUS = 524,
     OCCURS_HOOK = 525,
     STEP_REDUCE = 526
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
