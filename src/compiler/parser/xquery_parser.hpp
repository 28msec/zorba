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
     WHILE_LPAR = 278,
     QUOTE_ATTR_CONTENT = 279,
     STRING_LITERAL = 280,
     URI_LITERAL = 281,
     VARNAME = 282,
     VALIDATE_MODE = 283,
     XML_COMMENT_LITERAL = 284,
     ANCESTOR_AXIS = 285,
     ANCESTOR_OR_SELF_AXIS = 286,
     AND = 287,
     APOS = 288,
     AS = 289,
     ASCENDING = 290,
     AT = 291,
     ATTRIBUTE = 292,
     ATTRIBUTE_AXIS = 293,
     ATTRIBUTE_LBRACE = 294,
     ATTRIBUTE_LPAR = 295,
     AT_SIGN = 296,
     CASE = 297,
     CASTABLE_AS = 298,
     CAST_AS = 299,
     CDATA_BEGIN = 300,
     CDATA_END = 301,
     CHILD_AXIS = 302,
     COLLATION = 303,
     COMMA = 304,
     COMMENT_BEGIN = 305,
     COMMENT_END = 306,
     COMMENT_LBRACE = 307,
     COMMENT_LPAR = 308,
     DECIMAL_LITERAL = 309,
     DECLARE_BASE_URI = 310,
     DECLARE_BOUNDARY_SPACE = 311,
     DECLARE_CONSTRUCTION = 312,
     DECLARE_COPY_NAMESPACES = 313,
     DECLARE_DEFAULT_COLLATION = 314,
     DECLARE_DEFAULT_ELEMENT = 315,
     DECLARE_DEFAULT_FUNCTION = 316,
     DECLARE_DEFAULT_ORDER = 317,
     DECLARE_FUNCTION = 318,
     DECLARE_NAMESPACE = 319,
     DECLARE_OPTION = 320,
     DECLARE_ORDERING = 321,
     DECLARE_UPDATING_FUNCTION = 322,
     DECLARE_SEQ_FUNCTION = 323,
     EXIT_WITH = 324,
     BREAK_LOOP = 325,
     CONT_LOOP = 326,
     DECLARE_VARIABLE_DOLLAR = 327,
     DEFAULT = 328,
     DEFAULT_ELEMENT = 329,
     DESCENDANT_AXIS = 330,
     DESCENDANT_OR_SELF_AXIS = 331,
     DESCENDING = 332,
     DIV = 333,
     DOCUMENT_LBRACE = 334,
     DOCUMENT_NODE_LPAR = 335,
     DOLLAR = 336,
     DOT = 337,
     DOT_DOT = 338,
     DOUBLE_LBRACE = 339,
     DOUBLE_LITERAL = 340,
     DOUBLE_RBRACE = 341,
     ELEMENT_LBRACE = 342,
     ELEMENT_LPAR = 343,
     ELSE = 344,
     EMPTY_GREATEST = 345,
     EMPTY_LEAST = 346,
     EMPTY_TAG_END = 347,
     ENCODING = 348,
     EQUALS = 349,
     ESCAPE_APOS = 350,
     ESCAPE_QUOTE = 351,
     EVERY_DOLLAR = 352,
     EXCEPT = 353,
     EXTERNAL = 354,
     FOLLOWING_AXIS = 355,
     FOLLOWING_SIBLING_AXIS = 356,
     FOLLOWS = 357,
     FOR_DOLLAR = 358,
     GENERALCOMP = 359,
     GE = 360,
     GETS = 361,
     GT = 362,
     HOOK = 363,
     IDIV = 364,
     IF_LPAR = 365,
     IMPORT_MODULE = 366,
     IMPORT_SCHEMA = 367,
     _IN_ = 368,
     INHERIT = 369,
     INSTANCE_OF = 370,
     INTEGER_LITERAL = 371,
     INTERSECT = 372,
     IS = 373,
     ITEM_TEST = 374,
     LBRACE = 375,
     LBRACK = 376,
     LE = 377,
     LEADING_LONE_SLASH = 378,
     LET_DOLLAR = 379,
     LET_SCORE_DOLLAR = 380,
     LPAR = 381,
     LT = 382,
     MINUS = 383,
     MOD = 384,
     MODULE_NAMESPACE = 385,
     NAMESPACE = 386,
     _NAN = 387,
     NE = 388,
     NODECOMP = 389,
     NODE_LPAR = 390,
     NOT_OPERATOR_KEYWORD = 391,
     NO_INHERIT = 392,
     NO_PRESERVE = 393,
     OCCURS_HOOK = 394,
     OCCURS_PLUS = 395,
     OCCURS_STAR = 396,
     OR = 397,
     ORDERED = 398,
     ORDERED_LBRACE = 399,
     ORDER_BY = 400,
     GROUP_BY = 401,
     PARENT_AXIS = 402,
     PI_BEGIN = 403,
     PI_END = 404,
     PI_LBRACE = 405,
     PI_LPAR = 406,
     PI_TARGET = 407,
     PLUS = 408,
     PRAGMA_BEGIN = 409,
     PRAGMA_END = 410,
     PRECEDES = 411,
     PRECEDING_AXIS = 412,
     PRECEDING_SIBLING_AXIS = 413,
     PRESERVE = 414,
     PROCESSING_INSTRUCTION = 415,
     QUOTE = 416,
     RBRACE = 417,
     RBRACK = 418,
     RETURN = 419,
     RPAR = 420,
     SATISFIES = 421,
     SCHEMA_ATTRIBUTE_LPAR = 422,
     SCHEMA_ELEMENT_LPAR = 423,
     SELF_AXIS = 424,
     SEMI = 425,
     SLASH = 426,
     SLASH_SLASH = 427,
     SOME_DOLLAR = 428,
     STABLE_ORDER_BY = 429,
     STAR = 430,
     START_TAG_END = 431,
     START_TAG = 432,
     STRIP = 433,
     TAG_END = 434,
     TEXT_LBRACE = 435,
     TEXT_LPAR = 436,
     THEN = 437,
     TO = 438,
     TREAT_AS = 439,
     TYPESWITCH_LPAR = 440,
     UNION = 441,
     UNORDERED = 442,
     UNORDERED_LBRACE = 443,
     UNRECOGNIZED = 444,
     VAL_EQ = 445,
     VAL_GE = 446,
     VAL_GT = 447,
     VAL_LE = 448,
     VAL_LT = 449,
     VAL_NE = 450,
     VALIDATE_LBRACE = 451,
     VALUECOMP = 452,
     VBAR = 453,
     VOID_TEST = 454,
     WHERE = 455,
     XML_COMMENT_BEGIN = 456,
     XML_COMMENT_END = 457,
     XQUERY_VERSION = 458,
     AFTER = 459,
     BEFORE = 460,
     DECLARE_REVALIDATION = 461,
     REVAL_STRICT = 462,
     REVAL_LAX = 463,
     REVAL_SKIP = 464,
     DELETE_NODE = 465,
     DELETE_NODES = 466,
     INSERT_NODE = 467,
     INSERT_NODES = 468,
     RENAME = 469,
     REPLACE = 470,
     REPLACE_VALUE_OF = 471,
     FIRST_INTO = 472,
     INTO = 473,
     LAST_INTO = 474,
     MODIFY = 475,
     COPY_DOLLAR = 476,
     WITH = 477,
     TRY = 478,
     CATCH_LPAR = 479,
     USING_DOLLAR = 480,
     EVAL_LBRACE = 481,
     ALL = 482,
     ALL_WORDS = 483,
     ANY = 484,
     ANY_WORD = 485,
     AT_END = 486,
     AT_LEAST = 487,
     AT_MOST = 488,
     AT_START = 489,
     CASE_INSENSITIVE = 490,
     CASE_SENSITIVE = 491,
     DECLARE_FTOPTION = 492,
     DIACRITICS_INSENSITIVE = 493,
     DIACRITICS_SENSITIVE = 494,
     DIFFERENT = 495,
     DISTANCE = 496,
     ENTIRE_CONTENT = 497,
     EXACTLY = 498,
     FROM = 499,
     FTAND = 500,
     FTCONTAINS = 501,
     FTNOT = 502,
     FTOR = 503,
     LANGUAGE = 504,
     LEVELS = 505,
     LOWERCASE = 506,
     FTNOT_IN = 507,
     OCCURS = 508,
     PARAGRAPH = 509,
     PHRASE = 510,
     RELATIONSHIP = 511,
     SAME = 512,
     SCORE = 513,
     SENTENCE = 514,
     SENTENCES = 515,
     TIMES = 516,
     UPPERCASE = 517,
     WEIGHT = 518,
     WINDOW = 519,
     WITHOUT_CONTENT = 520,
     WITHOUT_DIACRITICS = 521,
     WITHOUT_STEMMING = 522,
     WITHOUT_STOP_WORDS = 523,
     WITHOUT_THESAURUS = 524,
     WITHOUT_WILDCARDS = 525,
     WITH_DEFAULT_STOP_WORDS = 526,
     WITH_DIACRITICS = 527,
     WITH_STEMMING = 528,
     WITH_STOP_WORDS = 529,
     WITH_THESAURUS = 530,
     WITH_WILDCARDS = 531,
     WORDS = 532,
     FTCONTAINS_REDUCE = 533,
     RANGE_REDUCE = 534,
     ADDITIVE_REDUCE = 535,
     MULTIPLICATIVE_REDUCE = 536,
     UNION_REDUCE = 537,
     INTERSECT_EXCEPT_REDUCE = 538,
     QVARINDECLLIST_REDUCE = 539,
     COMMA_DOLLAR = 540,
     UNARY_PREC = 541,
     SEQUENCE_TYPE_REDUCE = 542,
     STEP_REDUCE = 543
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
