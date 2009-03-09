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
#define LOC( p ) driver.createQueryLoc(p)

namespace zorba 
{

namespace parser 
{
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

class VarNameAndType {
public:
  std::string name;
  rchandle<TypeDeclaration> type;


  VarNameAndType (std::string name_, rchandle<TypeDeclaration> type_)
    : name (name_), type (type_)
  {}
};

}

#define YYDEBUG 1



/* Line 35 of lalr1.cc.  */
#line 110 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.hpp"

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
#line 138 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
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
}
/* Line 35 of lalr1.cc.  */
#line 175 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.hpp"
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
     BLANK = 280,
     EXIT = 281,
     BREAK = 282,
     LOOP = 283,
     CONTINUE = 284,
     WHILE = 285,
     VALIDATE = 286,
     TYPESWITCH = 287,
     ELEMENT = 288,
     DOCUMENT = 289,
     TEXT = 290,
     COMMENT = 291,
     DECLARE = 292,
     FUNCTION = 293,
     UPDATING = 294,
     SEQUENTIAL = 295,
     IF = 296,
     PROCESSING_INSTRUCTION = 297,
     MOST = 298,
     IMPORT = 299,
     SOME = 300,
     STABLE = 301,
     MODULE = 302,
     OPTION = 303,
     WORD = 304,
     SCHEMA = 305,
     SPACE = 306,
     SET = 307,
     LET = 308,
     CONSTRUCTION = 309,
     EVAL = 310,
     FOR = 311,
     OUTER = 312,
     SLIDING = 313,
     TUMBLING = 314,
     PREVIOUS = 315,
     NEXT = 316,
     ONLY = 317,
     WHEN = 318,
     COUNT = 319,
     ORDERING = 320,
     CONT = 321,
     BASE_URI = 322,
     SCHEMA_ELEMENT = 323,
     DOCUMENT_NODE = 324,
     COPY_NAMESPACES = 325,
     INSTANCE = 326,
     SCHEMA_ATTRIBUTE = 327,
     BOUNDARY_SPACE = 328,
     ANCESTOR_AXIS = 329,
     ANCESTOR_OR_SELF_AXIS = 330,
     AND = 331,
     APOS = 332,
     AS = 333,
     ASCENDING = 334,
     AT = 335,
     ATTRIBUTE = 336,
     ATTRIBUTE_AXIS = 337,
     AT_SIGN = 338,
     CASE = 339,
     CASTABLE = 340,
     CAST = 341,
     CDATA_BEGIN = 342,
     CDATA_END = 343,
     CHILD_AXIS = 344,
     COLLATION = 345,
     COMMA = 346,
     COMMENT_BEGIN = 347,
     COMMENT_END = 348,
     DECIMAL_LITERAL = 349,
     VARIABLE = 350,
     DEFAULT = 351,
     DESCENDANT_AXIS = 352,
     DESCENDANT_OR_SELF_AXIS = 353,
     DESCENDING = 354,
     DIV = 355,
     DOLLAR = 356,
     DOT = 357,
     DOT_DOT = 358,
     DOUBLE_LBRACE = 359,
     DOUBLE_LITERAL = 360,
     DOUBLE_RBRACE = 361,
     ELSE = 362,
     _EMPTY = 363,
     GREATEST = 364,
     LEAST = 365,
     EMPTY_TAG_END = 366,
     ENCODING = 367,
     EQUALS = 368,
     ESCAPE_APOS = 369,
     ESCAPE_QUOTE = 370,
     EVERY = 371,
     EXCEPT = 372,
     EXTERNAL = 373,
     FOLLOWING_AXIS = 374,
     FOLLOWING_SIBLING_AXIS = 375,
     FOLLOWS = 376,
     GE = 377,
     GETS = 378,
     GT = 379,
     HOOK = 380,
     IDIV = 381,
     _IN = 382,
     INHERIT = 383,
     INTEGER_LITERAL = 384,
     INTERSECT = 385,
     IS = 386,
     ITEM = 387,
     LBRACE = 388,
     LBRACK = 389,
     LE = 390,
     LPAR = 391,
     LT_OR_START_TAG = 392,
     MINUS = 393,
     MOD = 394,
     NAMESPACE = 395,
     _NAN = 396,
     NE = 397,
     NODECOMP = 398,
     NOT_OPERATOR_KEYWORD = 399,
     NO_INHERIT = 400,
     NO_PRESERVE = 401,
     OR = 402,
     ORDERED = 403,
     ORDER = 404,
     BY = 405,
     GROUP = 406,
     PARENT_AXIS = 407,
     PI_BEGIN = 408,
     PI_END = 409,
     PLUS = 410,
     PRAGMA_BEGIN = 411,
     PRAGMA_END = 412,
     PRECEDES = 413,
     PRECEDING_AXIS = 414,
     PRECEDING_SIBLING_AXIS = 415,
     PRESERVE = 416,
     QUOTE = 417,
     RBRACE = 418,
     RBRACK = 419,
     RETURN = 420,
     RPAR = 421,
     SATISFIES = 422,
     SCHEMA_ATTRIBUTE_LPAR = 423,
     SELF_AXIS = 424,
     SEMI = 425,
     SLASH = 426,
     SLASH_SLASH = 427,
     STAR = 428,
     START_TAG_END = 429,
     STRIP = 430,
     TAG_END = 431,
     THEN = 432,
     TO = 433,
     TREAT = 434,
     UNION = 435,
     UNORDERED = 436,
     VAL_EQ = 437,
     VAL_GE = 438,
     VAL_GT = 439,
     VAL_LE = 440,
     VAL_LT = 441,
     VAL_NE = 442,
     VALUECOMP = 443,
     VBAR = 444,
     EMPTY_SEQUENCE = 445,
     WHERE = 446,
     XML_COMMENT_BEGIN = 447,
     XML_COMMENT_END = 448,
     XQUERY = 449,
     VERSION = 450,
     END_PRAGMA = 451,
     START = 452,
     AFTER = 453,
     BEFORE = 454,
     REVALIDATION = 455,
     _STRICT = 456,
     LAX = 457,
     SKIP = 458,
     _DELETE = 459,
     NODE = 460,
     INSERT = 461,
     NODES = 462,
     RENAME = 463,
     REPLACE = 464,
     VALUE = 465,
     OF = 466,
     FIRST = 467,
     INTO = 468,
     LAST = 469,
     MODIFY = 470,
     COPY = 471,
     WITH = 472,
     TRY = 473,
     CATCH = 474,
     USING = 475,
     ALL = 476,
     ANY = 477,
     SENSITIVE = 478,
     FT_OPTION = 479,
     DIACRITICS = 480,
     INSENSITIVE = 481,
     DIFFERENT = 482,
     DISTANCE = 483,
     ENTIRE = 484,
     END = 485,
     CONTENT = 486,
     EXACTLY = 487,
     FROM = 488,
     FTAND = 489,
     FTCONTAINS = 490,
     FTNOT = 491,
     FTOR = 492,
     LANGUAGE = 493,
     LEVELS = 494,
     LOWERCASE = 495,
     OCCURS = 496,
     PARAGRAPH = 497,
     PHRASE = 498,
     RELATIONSHIP = 499,
     SAME = 500,
     SCORE = 501,
     SENTENCE = 502,
     SENTENCES = 503,
     TIMES = 504,
     UPPERCASE = 505,
     WEIGHT = 506,
     WINDOW = 507,
     WITHOUT = 508,
     STEMMING = 509,
     STOP = 510,
     WORDS = 511,
     THESAURUS = 512,
     WILDCARDS = 513,
     BYTE_ORDER_MARK_UTF8 = 514,
     FTCONTAINS_REDUCE = 515,
     RANGE_REDUCE = 516,
     ADDITIVE_REDUCE = 517,
     MULTIPLICATIVE_REDUCE = 518,
     UNION_REDUCE = 519,
     INTERSECT_EXCEPT_REDUCE = 520,
     QVARINDECLLIST_REDUCE = 521,
     COMMA_DOLLAR = 522,
     UNARY_PREC = 523,
     SEQUENCE_TYPE_REDUCE = 524,
     OCCURS_STAR = 525,
     OCCURS_PLUS = 526,
     OCCURS_HOOK = 527,
     STEP_REDUCE = 528
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
