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
     CONTEXT = 351,
     VARIABLE = 352,
     DEFAULT = 353,
     DESCENDANT_AXIS = 354,
     DESCENDANT_OR_SELF_AXIS = 355,
     DESCENDING = 356,
     DIV = 357,
     DOLLAR = 358,
     DOT = 359,
     DOT_DOT = 360,
     DOUBLE_LBRACE = 361,
     DOUBLE_LITERAL = 362,
     DOUBLE_RBRACE = 363,
     ELSE = 364,
     _EMPTY = 365,
     GREATEST = 366,
     LEAST = 367,
     EMPTY_TAG_END = 368,
     ENCODING = 369,
     EQUALS = 370,
     ESCAPE_APOS = 371,
     ESCAPE_QUOTE = 372,
     EVERY = 373,
     EXCEPT = 374,
     EXTERNAL = 375,
     FOLLOWING_AXIS = 376,
     FOLLOWING_SIBLING_AXIS = 377,
     FOLLOWS = 378,
     GE = 379,
     GETS = 380,
     GT = 381,
     HOOK = 382,
     IDIV = 383,
     _IN = 384,
     INHERIT = 385,
     INTEGER_LITERAL = 386,
     INTERSECT = 387,
     IS = 388,
     ITEM = 389,
     LBRACE = 390,
     LBRACK = 391,
     LE = 392,
     LPAR = 393,
     LT_OR_START_TAG = 394,
     MINUS = 395,
     MOD = 396,
     NAMESPACE = 397,
     _NAN = 398,
     NE = 399,
     NODECOMP = 400,
     NOT_OPERATOR_KEYWORD = 401,
     NO_INHERIT = 402,
     NO_PRESERVE = 403,
     OR = 404,
     ORDERED = 405,
     ORDER = 406,
     BY = 407,
     GROUP = 408,
     PARENT_AXIS = 409,
     PI_BEGIN = 410,
     PI_END = 411,
     PLUS = 412,
     PRAGMA_BEGIN = 413,
     PRAGMA_END = 414,
     PRECEDES = 415,
     PRECEDING_AXIS = 416,
     PRECEDING_SIBLING_AXIS = 417,
     PRESERVE = 418,
     QUOTE = 419,
     RBRACE = 420,
     RBRACK = 421,
     RETURN = 422,
     RPAR = 423,
     SATISFIES = 424,
     SCHEMA_ATTRIBUTE_LPAR = 425,
     SELF_AXIS = 426,
     SEMI = 427,
     SLASH = 428,
     SLASH_SLASH = 429,
     STAR = 430,
     START_TAG_END = 431,
     STRIP = 432,
     TAG_END = 433,
     THEN = 434,
     TO = 435,
     TREAT = 436,
     UNION = 437,
     UNORDERED = 438,
     VAL_EQ = 439,
     VAL_GE = 440,
     VAL_GT = 441,
     VAL_LE = 442,
     VAL_LT = 443,
     VAL_NE = 444,
     VALUECOMP = 445,
     VBAR = 446,
     EMPTY_SEQUENCE = 447,
     WHERE = 448,
     XML_COMMENT_BEGIN = 449,
     XML_COMMENT_END = 450,
     XQUERY = 451,
     VERSION = 452,
     END_PRAGMA = 453,
     START = 454,
     AFTER = 455,
     BEFORE = 456,
     REVALIDATION = 457,
     _STRICT = 458,
     LAX = 459,
     SKIP = 460,
     _DELETE = 461,
     NODE = 462,
     INSERT = 463,
     NODES = 464,
     RENAME = 465,
     REPLACE = 466,
     VALUE = 467,
     OF = 468,
     FIRST = 469,
     INTO = 470,
     LAST = 471,
     MODIFY = 472,
     COPY = 473,
     WITH = 474,
     TRY = 475,
     CATCH = 476,
     USING = 477,
     ALL = 478,
     ANY = 479,
     SENSITIVE = 480,
     FT_OPTION = 481,
     DIACRITICS = 482,
     INSENSITIVE = 483,
     DIFFERENT = 484,
     DISTANCE = 485,
     ENTIRE = 486,
     END = 487,
     CONTENT = 488,
     EXACTLY = 489,
     FROM = 490,
     FTAND = 491,
     FTCONTAINS = 492,
     FTNOT = 493,
     FTOR = 494,
     LANGUAGE = 495,
     LEVELS = 496,
     LOWERCASE = 497,
     OCCURS = 498,
     PARAGRAPH = 499,
     PHRASE = 500,
     RELATIONSHIP = 501,
     SAME = 502,
     SCORE = 503,
     SENTENCE = 504,
     SENTENCES = 505,
     TIMES = 506,
     UPPERCASE = 507,
     WEIGHT = 508,
     WINDOW = 509,
     WITHOUT = 510,
     STEMMING = 511,
     STOP = 512,
     WORDS = 513,
     THESAURUS = 514,
     WILDCARDS = 515,
     CREATE = 516,
     DROP = 517,
     UNIQUE = 518,
     INDEX = 519,
     HASH = 520,
     BTREE = 521,
     ON = 522,
     BYTE_ORDER_MARK_UTF8 = 523,
     FTCONTAINS_REDUCE = 524,
     RANGE_REDUCE = 525,
     ADDITIVE_REDUCE = 526,
     MULTIPLICATIVE_REDUCE = 527,
     UNION_REDUCE = 528,
     INTERSECT_EXCEPT_REDUCE = 529,
     QVARINDECLLIST_REDUCE = 530,
     COMMA_DOLLAR = 531,
     UNARY_PREC = 532,
     SEQUENCE_TYPE_REDUCE = 533,
     OCCURS_STAR = 534,
     OCCURS_PLUS = 535,
     OCCURS_HOOK = 536,
     STEP_REDUCE = 537
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
