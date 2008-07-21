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
#line 38 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <string>

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "store/api/update_consts.h"


#define SYMTAB( n ) driver.symtab.get ((off_t) n)
#define LOC( p ) driver.createQueryLoc(p)

namespace zorba {
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



/* Line 35 of lalr1.cc.  */
#line 89 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.hpp"

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
#line 117 "/home/colea/work/xquery/src/compiler/parser/xquery_parser.y"
{
  zorba::parsenode * node;
  zorba::exprnode * expr;
  zorba::FunctionSig *fnsig;
  off_t sval;
	xqp_integer* ival;
	xqp_double* dval;
	xqp_decimal* decval;
}
/* Line 35 of lalr1.cc.  */
#line 151 "/home/colea/work/xquery/build/src/compiler/parser/xquery_parser.hpp"
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
     ORDERING = 310,
     CONT = 311,
     BASE_URI = 312,
     SCHEMA_ELEMENT = 313,
     DOCUMENT_NODE = 314,
     COPY_NAMESPACES = 315,
     INSTANCE = 316,
     SCHEMA_ATTRIBUTE = 317,
     BOUNDARY_SPACE = 318,
     ANCESTOR_AXIS = 319,
     ANCESTOR_OR_SELF_AXIS = 320,
     AND = 321,
     APOS = 322,
     AS = 323,
     ASCENDING = 324,
     AT = 325,
     ATTRIBUTE = 326,
     ATTRIBUTE_AXIS = 327,
     AT_SIGN = 328,
     CASE = 329,
     CASTABLE = 330,
     CAST = 331,
     CDATA_BEGIN = 332,
     CDATA_END = 333,
     CHILD_AXIS = 334,
     COLLATION = 335,
     COMMA = 336,
     COMMENT_BEGIN = 337,
     COMMENT_END = 338,
     DECIMAL_LITERAL = 339,
     VARIABLE = 340,
     DEFAULT = 341,
     DESCENDANT_AXIS = 342,
     DESCENDANT_OR_SELF_AXIS = 343,
     DESCENDING = 344,
     DIV = 345,
     DOLLAR = 346,
     DOT = 347,
     DOT_DOT = 348,
     DOUBLE_LBRACE = 349,
     DOUBLE_LITERAL = 350,
     DOUBLE_RBRACE = 351,
     ELSE = 352,
     _EMPTY = 353,
     GREATEST = 354,
     LEAST = 355,
     EMPTY_TAG_END = 356,
     ENCODING = 357,
     EQUALS = 358,
     ESCAPE_APOS = 359,
     ESCAPE_QUOTE = 360,
     EVERY = 361,
     EXCEPT = 362,
     EXTERNAL = 363,
     FOLLOWING_AXIS = 364,
     FOLLOWING_SIBLING_AXIS = 365,
     FOLLOWS = 366,
     GE = 367,
     GETS = 368,
     GT = 369,
     HOOK = 370,
     IDIV = 371,
     IN = 372,
     INHERIT = 373,
     INTEGER_LITERAL = 374,
     INTERSECT = 375,
     IS = 376,
     ITEM = 377,
     LBRACE = 378,
     LBRACK = 379,
     LE = 380,
     LEADING_LONE_SLASH = 381,
     LPAR = 382,
     LT_OR_START_TAG = 383,
     MINUS = 384,
     MOD = 385,
     NAMESPACE = 386,
     _NAN = 387,
     NE = 388,
     NODECOMP = 389,
     NOT_OPERATOR_KEYWORD = 390,
     NO_INHERIT = 391,
     NO_PRESERVE = 392,
     OR = 393,
     ORDERED = 394,
     ORDER = 395,
     BY = 396,
     GROUP = 397,
     PARENT_AXIS = 398,
     PI_BEGIN = 399,
     PI_END = 400,
     PLUS = 401,
     PRAGMA_BEGIN = 402,
     PRAGMA_END = 403,
     PRECEDES = 404,
     PRECEDING_AXIS = 405,
     PRECEDING_SIBLING_AXIS = 406,
     PRESERVE = 407,
     QUOTE = 408,
     RBRACE = 409,
     RBRACK = 410,
     RETURN = 411,
     RPAR = 412,
     SATISFIES = 413,
     SCHEMA_ATTRIBUTE_LPAR = 414,
     SELF_AXIS = 415,
     SEMI = 416,
     SLASH = 417,
     SLASH_SLASH = 418,
     STAR = 419,
     START_TAG_END = 420,
     STRIP = 421,
     TAG_END = 422,
     THEN = 423,
     TO = 424,
     TREAT = 425,
     UNION = 426,
     UNORDERED = 427,
     UNRECOGNIZED = 428,
     VAL_EQ = 429,
     VAL_GE = 430,
     VAL_GT = 431,
     VAL_LE = 432,
     VAL_LT = 433,
     VAL_NE = 434,
     VALUECOMP = 435,
     VBAR = 436,
     EMPTY_SEQUENCE = 437,
     WHERE = 438,
     XML_COMMENT_BEGIN = 439,
     XML_COMMENT_END = 440,
     XQUERY = 441,
     VERSION = 442,
     END_PRAGMA = 443,
     START = 444,
     AFTER = 445,
     BEFORE = 446,
     REVALIDATION = 447,
     STRICT = 448,
     LAX = 449,
     SKIP = 450,
     DELETE = 451,
     NODE = 452,
     INSERT = 453,
     NODES = 454,
     RENAME = 455,
     REPLACE = 456,
     VALUE = 457,
     OF = 458,
     FIRST = 459,
     INTO = 460,
     LAST = 461,
     MODIFY = 462,
     COPY = 463,
     WITH = 464,
     TRY = 465,
     CATCH = 466,
     USING = 467,
     ALL = 468,
     ANY = 469,
     SENSITIVE = 470,
     FT_OPTION = 471,
     DIACRITICS = 472,
     INSENSITIVE = 473,
     DIFFERENT = 474,
     DISTANCE = 475,
     ENTIRE = 476,
     END = 477,
     CONTENT = 478,
     EXACTLY = 479,
     FROM = 480,
     FTAND = 481,
     FTCONTAINS = 482,
     FTNOT = 483,
     FTOR = 484,
     LANGUAGE = 485,
     LEVELS = 486,
     LOWERCASE = 487,
     OCCURS = 488,
     PARAGRAPH = 489,
     PHRASE = 490,
     RELATIONSHIP = 491,
     SAME = 492,
     SCORE = 493,
     SENTENCE = 494,
     SENTENCES = 495,
     TIMES = 496,
     UPPERCASE = 497,
     WEIGHT = 498,
     WINDOW = 499,
     WITHOUT = 500,
     STEMMING = 501,
     STOP = 502,
     WORDS = 503,
     THESAURUS = 504,
     WILDCARDS = 505,
     FTCONTAINS_REDUCE = 506,
     RANGE_REDUCE = 507,
     ADDITIVE_REDUCE = 508,
     MULTIPLICATIVE_REDUCE = 509,
     UNION_REDUCE = 510,
     INTERSECT_EXCEPT_REDUCE = 511,
     QVARINDECLLIST_REDUCE = 512,
     COMMA_DOLLAR = 513,
     UNARY_PREC = 514,
     SEQUENCE_TYPE_REDUCE = 515,
     OCCURS_STAR = 516,
     OCCURS_PLUS = 517,
     OCCURS_HOOK = 518,
     STEP_REDUCE = 519
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
