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
#line 89 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.hpp"

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
#line 117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
#line 151 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.hpp"
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
     END = 0,
     APOS_ATTR_CONTENT = 258,
     ATTRIBUTE_QNAME_LBRACE = 259,
     AT_URI_LITERAL = 260,
     CHAR_LITERAL = 261,
     CHAR_LITERAL_AND_CDATA_END = 262,
     CHAR_LITERAL_AND_PI_END = 263,
     CHAR_REF_LITERAL = 264,
     ELEMENT_CONTENT = 265,
     ELEMENT_QNAME_LBRACE = 266,
     ELEM_WILDCARD = 267,
     ENTITY_REF = 268,
     EXPR_COMMENT_LITERAL = 269,
     NCNAME = 270,
     PI_NCNAME_LBRACE = 271,
     PI_TARGET_LITERAL = 272,
     PRAGMA_LITERAL_AND_END = 273,
     PREFIX_WILDCARD = 274,
     QNAME = 275,
     QNAME_AND_END_PRAGMA = 276,
     QNAME_LPAR = 277,
     QUOTE_ATTR_CONTENT = 278,
     STRING_LITERAL = 279,
     URI_LITERAL = 280,
     VARNAME = 281,
     VALIDATE_MODE = 282,
     XML_COMMENT_LITERAL = 283,
     ANCESTOR_AXIS = 284,
     ANCESTOR_OR_SELF_AXIS = 285,
     AND = 286,
     APOS = 287,
     AS = 288,
     ASCENDING = 289,
     AT = 290,
     ATTRIBUTE = 291,
     ATTRIBUTE_AXIS = 292,
     ATTRIBUTE_LBRACE = 293,
     ATTRIBUTE_LPAR = 294,
     AT_SIGN = 295,
     CASE = 296,
     CASTABLE_AS = 297,
     CAST_AS = 298,
     CDATA_BEGIN = 299,
     CDATA_END = 300,
     CHILD_AXIS = 301,
     COLLATION = 302,
     COMMA = 303,
     COMMENT_BEGIN = 304,
     COMMENT_END = 305,
     COMMENT_LBRACE = 306,
     COMMENT_LPAR = 307,
     DECIMAL_LITERAL = 308,
     DECLARE_BASE_URI = 309,
     DECLARE_BOUNDARY_SPACE = 310,
     DECLARE_CONSTRUCTION = 311,
     DECLARE_COPY_NAMESPACES = 312,
     DECLARE_DEFAULT_COLLATION = 313,
     DECLARE_DEFAULT_ELEMENT = 314,
     DECLARE_DEFAULT_FUNCTION = 315,
     DECLARE_DEFAULT_ORDER = 316,
     DECLARE_FUNCTION = 317,
     DECLARE_NAMESPACE = 318,
     DECLARE_OPTION = 319,
     DECLARE_ORDERING = 320,
     DECLARE_UPDATING_FUNCTION = 321,
     DECLARE_SEQ_FUNCTION = 322,
     EXIT_WITH = 323,
     DECLARE_VARIABLE_DOLLAR = 324,
     DEFAULT = 325,
     DEFAULT_ELEMENT = 326,
     DESCENDANT_AXIS = 327,
     DESCENDANT_OR_SELF_AXIS = 328,
     DESCENDING = 329,
     DIV = 330,
     DOCUMENT_LBRACE = 331,
     DOCUMENT_NODE_LPAR = 332,
     DOLLAR = 333,
     DOT = 334,
     DOT_DOT = 335,
     DOUBLE_LBRACE = 336,
     DOUBLE_LITERAL = 337,
     DOUBLE_RBRACE = 338,
     ELEMENT_LBRACE = 339,
     ELEMENT_LPAR = 340,
     ELSE = 341,
     EMPTY_GREATEST = 342,
     EMPTY_LEAST = 343,
     EMPTY_TAG_END = 344,
     ENCODING = 345,
     EQUALS = 346,
     ESCAPE_APOS = 347,
     ESCAPE_QUOTE = 348,
     EVERY_DOLLAR = 349,
     EXCEPT = 350,
     EXTERNAL = 351,
     FOLLOWING_AXIS = 352,
     FOLLOWING_SIBLING_AXIS = 353,
     FOLLOWS = 354,
     FOR_DOLLAR = 355,
     GENERALCOMP = 356,
     GE = 357,
     GETS = 358,
     GT = 359,
     HOOK = 360,
     IDIV = 361,
     IF_LPAR = 362,
     IMPORT_MODULE = 363,
     IMPORT_SCHEMA = 364,
     _IN_ = 365,
     INHERIT = 366,
     INSTANCE_OF = 367,
     INTEGER_LITERAL = 368,
     INTERSECT = 369,
     IS = 370,
     ITEM_TEST = 371,
     LBRACE = 372,
     LBRACK = 373,
     LE = 374,
     LEADING_LONE_SLASH = 375,
     LET_DOLLAR = 376,
     LET_SCORE_DOLLAR = 377,
     LPAR = 378,
     LT = 379,
     MINUS = 380,
     MOD = 381,
     MODULE_NAMESPACE = 382,
     NAMESPACE = 383,
     _NAN = 384,
     NE = 385,
     NODECOMP = 386,
     NODE_LPAR = 387,
     NOT_OPERATOR_KEYWORD = 388,
     NO_INHERIT = 389,
     NO_PRESERVE = 390,
     OCCURS_HOOK = 391,
     OCCURS_PLUS = 392,
     OCCURS_STAR = 393,
     OR = 394,
     ORDERED = 395,
     ORDERED_LBRACE = 396,
     ORDER_BY = 397,
     GROUP_BY = 398,
     PARENT_AXIS = 399,
     PI_BEGIN = 400,
     PI_END = 401,
     PI_LBRACE = 402,
     PI_LPAR = 403,
     PI_TARGET = 404,
     PLUS = 405,
     PRAGMA_BEGIN = 406,
     PRAGMA_END = 407,
     PRECEDES = 408,
     PRECEDING_AXIS = 409,
     PRECEDING_SIBLING_AXIS = 410,
     PRESERVE = 411,
     PROCESSING_INSTRUCTION = 412,
     QUOTE = 413,
     RBRACE = 414,
     RBRACK = 415,
     RETURN = 416,
     RPAR = 417,
     SATISFIES = 418,
     SCHEMA_ATTRIBUTE_LPAR = 419,
     SCHEMA_ELEMENT_LPAR = 420,
     SELF_AXIS = 421,
     SEMI = 422,
     SLASH = 423,
     SLASH_SLASH = 424,
     SOME_DOLLAR = 425,
     STABLE_ORDER_BY = 426,
     STAR = 427,
     START_TAG_END = 428,
     START_TAG = 429,
     STRIP = 430,
     TAG_END = 431,
     TEXT_LBRACE = 432,
     TEXT_LPAR = 433,
     THEN = 434,
     TO = 435,
     TREAT_AS = 436,
     TYPESWITCH_LPAR = 437,
     UNION = 438,
     UNORDERED = 439,
     UNORDERED_LBRACE = 440,
     UNRECOGNIZED = 441,
     VAL_EQ = 442,
     VAL_GE = 443,
     VAL_GT = 444,
     VAL_LE = 445,
     VAL_LT = 446,
     VAL_NE = 447,
     VALIDATE_LBRACE = 448,
     VALUECOMP = 449,
     VBAR = 450,
     VOID_TEST = 451,
     WHERE = 452,
     XML_COMMENT_BEGIN = 453,
     XML_COMMENT_END = 454,
     XQUERY_VERSION = 455,
     AFTER = 456,
     BEFORE = 457,
     DECLARE_REVALIDATION = 458,
     REVAL_STRICT = 459,
     REVAL_LAX = 460,
     REVAL_SKIP = 461,
     DELETE_NODE = 462,
     DELETE_NODES = 463,
     INSERT_NODE = 464,
     INSERT_NODES = 465,
     RENAME = 466,
     REPLACE = 467,
     REPLACE_VALUE_OF = 468,
     FIRST_INTO = 469,
     INTO = 470,
     LAST_INTO = 471,
     MODIFY = 472,
     COPY_DOLLAR = 473,
     WITH = 474,
     TRY = 475,
     CATCH_LPAR = 476,
     USING_DOLLAR = 477,
     EVAL_LBRACE = 478,
     ALL = 479,
     ALL_WORDS = 480,
     ANY = 481,
     ANY_WORD = 482,
     AT_END = 483,
     AT_LEAST = 484,
     AT_MOST = 485,
     AT_START = 486,
     CASE_INSENSITIVE = 487,
     CASE_SENSITIVE = 488,
     DECLARE_FTOPTION = 489,
     DIACRITICS_INSENSITIVE = 490,
     DIACRITICS_SENSITIVE = 491,
     DIFFERENT = 492,
     DISTANCE = 493,
     ENTIRE_CONTENT = 494,
     EXACTLY = 495,
     FROM = 496,
     FTAND = 497,
     FTCONTAINS = 498,
     FTNOT = 499,
     FTOR = 500,
     LANGUAGE = 501,
     LEVELS = 502,
     LOWERCASE = 503,
     FTNOT_IN = 504,
     OCCURS = 505,
     PARAGRAPH = 506,
     PHRASE = 507,
     RELATIONSHIP = 508,
     SAME = 509,
     SCORE = 510,
     SENTENCE = 511,
     SENTENCES = 512,
     TIMES = 513,
     UPPERCASE = 514,
     WEIGHT = 515,
     WINDOW = 516,
     WITHOUT_CONTENT = 517,
     WITHOUT_DIACRITICS = 518,
     WITHOUT_STEMMING = 519,
     WITHOUT_STOP_WORDS = 520,
     WITHOUT_THESAURUS = 521,
     WITHOUT_WILDCARDS = 522,
     WITH_DEFAULT_STOP_WORDS = 523,
     WITH_DIACRITICS = 524,
     WITH_STEMMING = 525,
     WITH_STOP_WORDS = 526,
     WITH_THESAURUS = 527,
     WITH_WILDCARDS = 528,
     WORDS = 529,
     FTCONTAINS_REDUCE = 530,
     RANGE_REDUCE = 531,
     ADDITIVE_REDUCE = 532,
     MULTIPLICATIVE_REDUCE = 533,
     UNION_REDUCE = 534,
     INTERSECT_EXCEPT_REDUCE = 535,
     QVARINDECLLIST_REDUCE = 536,
     COMMA_DOLLAR = 537,
     UNARY_PREC = 538,
     SEQUENCE_TYPE_REDUCE = 539,
     STEP_REDUCE = 540
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
