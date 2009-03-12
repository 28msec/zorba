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
     BLOCK = 281,
     EXIT = 282,
     BREAK = 283,
     LOOP = 284,
     CONTINUE = 285,
     WHILE = 286,
     VALIDATE = 287,
     TYPESWITCH = 288,
     ELEMENT = 289,
     DOCUMENT = 290,
     TEXT = 291,
     COMMENT = 292,
     DECLARE = 293,
     FUNCTION = 294,
     UPDATING = 295,
     SEQUENTIAL = 296,
     IF = 297,
     PROCESSING_INSTRUCTION = 298,
     MOST = 299,
     IMPORT = 300,
     SOME = 301,
     STABLE = 302,
     MODULE = 303,
     OPTION = 304,
     WORD = 305,
     SCHEMA = 306,
     SPACE = 307,
     SET = 308,
     LET = 309,
     CONSTRUCTION = 310,
     EVAL = 311,
     FOR = 312,
     OUTER = 313,
     SLIDING = 314,
     TUMBLING = 315,
     PREVIOUS = 316,
     NEXT = 317,
     ONLY = 318,
     WHEN = 319,
     COUNT = 320,
     ORDERING = 321,
     CONT = 322,
     BASE_URI = 323,
     SCHEMA_ELEMENT = 324,
     DOCUMENT_NODE = 325,
     COPY_NAMESPACES = 326,
     INSTANCE = 327,
     SCHEMA_ATTRIBUTE = 328,
     BOUNDARY_SPACE = 329,
     ANCESTOR_AXIS = 330,
     ANCESTOR_OR_SELF_AXIS = 331,
     AND = 332,
     APOS = 333,
     AS = 334,
     ASCENDING = 335,
     AT = 336,
     ATTRIBUTE = 337,
     ATTRIBUTE_AXIS = 338,
     AT_SIGN = 339,
     CASE = 340,
     CASTABLE = 341,
     CAST = 342,
     CDATA_BEGIN = 343,
     CDATA_END = 344,
     CHILD_AXIS = 345,
     COLLATION = 346,
     COMMA = 347,
     COMMENT_BEGIN = 348,
     COMMENT_END = 349,
     DECIMAL_LITERAL = 350,
     VARIABLE = 351,
     DEFAULT = 352,
     DESCENDANT_AXIS = 353,
     DESCENDANT_OR_SELF_AXIS = 354,
     DESCENDING = 355,
     DIV = 356,
     DOLLAR = 357,
     DOT = 358,
     DOT_DOT = 359,
     DOUBLE_LBRACE = 360,
     DOUBLE_LITERAL = 361,
     DOUBLE_RBRACE = 362,
     ELSE = 363,
     _EMPTY = 364,
     GREATEST = 365,
     LEAST = 366,
     EMPTY_TAG_END = 367,
     ENCODING = 368,
     EQUALS = 369,
     ESCAPE_APOS = 370,
     ESCAPE_QUOTE = 371,
     EVERY = 372,
     EXCEPT = 373,
     EXTERNAL = 374,
     FOLLOWING_AXIS = 375,
     FOLLOWING_SIBLING_AXIS = 376,
     FOLLOWS = 377,
     GE = 378,
     GETS = 379,
     GT = 380,
     HOOK = 381,
     IDIV = 382,
     _IN = 383,
     INHERIT = 384,
     INTEGER_LITERAL = 385,
     INTERSECT = 386,
     IS = 387,
     ITEM = 388,
     LBRACE = 389,
     LBRACK = 390,
     LE = 391,
     LPAR = 392,
     LT_OR_START_TAG = 393,
     MINUS = 394,
     MOD = 395,
     NAMESPACE = 396,
     _NAN = 397,
     NE = 398,
     NODECOMP = 399,
     NOT_OPERATOR_KEYWORD = 400,
     NO_INHERIT = 401,
     NO_PRESERVE = 402,
     OR = 403,
     ORDERED = 404,
     ORDER = 405,
     BY = 406,
     GROUP = 407,
     PARENT_AXIS = 408,
     PI_BEGIN = 409,
     PI_END = 410,
     PLUS = 411,
     PRAGMA_BEGIN = 412,
     PRAGMA_END = 413,
     PRECEDES = 414,
     PRECEDING_AXIS = 415,
     PRECEDING_SIBLING_AXIS = 416,
     PRESERVE = 417,
     QUOTE = 418,
     RBRACE = 419,
     RBRACK = 420,
     RETURN = 421,
     RPAR = 422,
     SATISFIES = 423,
     SCHEMA_ATTRIBUTE_LPAR = 424,
     SELF_AXIS = 425,
     SEMI = 426,
     SLASH = 427,
     SLASH_SLASH = 428,
     STAR = 429,
     START_TAG_END = 430,
     STRIP = 431,
     TAG_END = 432,
     THEN = 433,
     TO = 434,
     TREAT = 435,
     UNION = 436,
     UNORDERED = 437,
     VAL_EQ = 438,
     VAL_GE = 439,
     VAL_GT = 440,
     VAL_LE = 441,
     VAL_LT = 442,
     VAL_NE = 443,
     VALUECOMP = 444,
     VBAR = 445,
     EMPTY_SEQUENCE = 446,
     WHERE = 447,
     XML_COMMENT_BEGIN = 448,
     XML_COMMENT_END = 449,
     XQUERY = 450,
     VERSION = 451,
     END_PRAGMA = 452,
     START = 453,
     AFTER = 454,
     BEFORE = 455,
     REVALIDATION = 456,
     _STRICT = 457,
     LAX = 458,
     SKIP = 459,
     _DELETE = 460,
     NODE = 461,
     INSERT = 462,
     NODES = 463,
     RENAME = 464,
     REPLACE = 465,
     VALUE = 466,
     OF = 467,
     FIRST = 468,
     INTO = 469,
     LAST = 470,
     MODIFY = 471,
     COPY = 472,
     WITH = 473,
     TRY = 474,
     CATCH = 475,
     USING = 476,
     ALL = 477,
     ANY = 478,
     SENSITIVE = 479,
     FT_OPTION = 480,
     DIACRITICS = 481,
     INSENSITIVE = 482,
     DIFFERENT = 483,
     DISTANCE = 484,
     ENTIRE = 485,
     END = 486,
     CONTENT = 487,
     EXACTLY = 488,
     FROM = 489,
     FTAND = 490,
     FTCONTAINS = 491,
     FTNOT = 492,
     FTOR = 493,
     LANGUAGE = 494,
     LEVELS = 495,
     LOWERCASE = 496,
     OCCURS = 497,
     PARAGRAPH = 498,
     PHRASE = 499,
     RELATIONSHIP = 500,
     SAME = 501,
     SCORE = 502,
     SENTENCE = 503,
     SENTENCES = 504,
     TIMES = 505,
     UPPERCASE = 506,
     WEIGHT = 507,
     WINDOW = 508,
     WITHOUT = 509,
     STEMMING = 510,
     STOP = 511,
     WORDS = 512,
     THESAURUS = 513,
     WILDCARDS = 514,
     CREATE = 515,
     DROP = 516,
     UNIQUE = 517,
     INDEX = 518,
     HASH = 519,
     BTREE = 520,
     ON = 521,
     BYTE_ORDER_MARK_UTF8 = 522,
     FTCONTAINS_REDUCE = 523,
     RANGE_REDUCE = 524,
     ADDITIVE_REDUCE = 525,
     MULTIPLICATIVE_REDUCE = 526,
     UNION_REDUCE = 527,
     INTERSECT_EXCEPT_REDUCE = 528,
     QVARINDECLLIST_REDUCE = 529,
     COMMA_DOLLAR = 530,
     UNARY_PREC = 531,
     SEQUENCE_TYPE_REDUCE = 532,
     OCCURS_STAR = 533,
     OCCURS_PLUS = 534,
     OCCURS_HOOK = 535,
     STEP_REDUCE = 536
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
