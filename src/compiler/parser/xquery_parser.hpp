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
  rchandle<TypeDeclaration> type;


  VarNameAndType (std::string name_, rchandle<TypeDeclaration> type_)
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
}
/* Line 35 of lalr1.cc.  */
#line 176 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.hpp"
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
     DETERMINISTIC = 297,
     NONDETERMINISTIC = 298,
     SIMPLE = 299,
     IF = 300,
     PROCESSING_INSTRUCTION = 301,
     MOST = 302,
     IMPORT = 303,
     SOME = 304,
     STABLE = 305,
     MODULE = 306,
     OPTION = 307,
     WORD = 308,
     SCHEMA = 309,
     SPACE = 310,
     SET = 311,
     LET = 312,
     CONSTRUCTION = 313,
     EVAL = 314,
     FOR = 315,
     OUTER = 316,
     SLIDING = 317,
     TUMBLING = 318,
     PREVIOUS = 319,
     NEXT = 320,
     ONLY = 321,
     WHEN = 322,
     COUNT = 323,
     ORDERING = 324,
     BASE_URI = 325,
     SCHEMA_ELEMENT = 326,
     DOCUMENT_NODE = 327,
     COPY_NAMESPACES = 328,
     INSTANCE = 329,
     SCHEMA_ATTRIBUTE = 330,
     BOUNDARY_SPACE = 331,
     ANCESTOR_AXIS = 332,
     ANCESTOR_OR_SELF_AXIS = 333,
     AND = 334,
     APOS = 335,
     AS = 336,
     ASCENDING = 337,
     AT = 338,
     ATTRIBUTE = 339,
     ATTRIBUTE_AXIS = 340,
     AT_SIGN = 341,
     CASE = 342,
     CASTABLE = 343,
     CAST = 344,
     CDATA_BEGIN = 345,
     CDATA_END = 346,
     CHILD_AXIS = 347,
     COLLATION = 348,
     COMMA = 349,
     COMMENT_BEGIN = 350,
     COMMENT_END = 351,
     DECIMAL_LITERAL = 352,
     CONTEXT = 353,
     VARIABLE = 354,
     DEFAULT = 355,
     DESCENDANT_AXIS = 356,
     DESCENDANT_OR_SELF_AXIS = 357,
     DESCENDING = 358,
     DIV = 359,
     DOLLAR = 360,
     DOT = 361,
     DOT_DOT = 362,
     DOUBLE_LBRACE = 363,
     DOUBLE_LITERAL = 364,
     DOUBLE_RBRACE = 365,
     ELSE = 366,
     _EMPTY = 367,
     GREATEST = 368,
     LEAST = 369,
     EMPTY_TAG_END = 370,
     ENCODING = 371,
     EQUALS = 372,
     ESCAPE_APOS = 373,
     ESCAPE_QUOTE = 374,
     EVERY = 375,
     EXCEPT = 376,
     EXTERNAL = 377,
     FOLLOWING_AXIS = 378,
     FOLLOWING_SIBLING_AXIS = 379,
     FOLLOWS = 380,
     GE = 381,
     GETS = 382,
     GT = 383,
     HOOK = 384,
     IDIV = 385,
     _IN = 386,
     INHERIT = 387,
     INTEGER_LITERAL = 388,
     INTERSECT = 389,
     IS = 390,
     ITEM = 391,
     LBRACE = 392,
     LBRACK = 393,
     LE = 394,
     LPAR = 395,
     LT_OR_START_TAG = 396,
     MINUS = 397,
     MOD = 398,
     NAMESPACE = 399,
     _NAN = 400,
     NE = 401,
     NODECOMP = 402,
     NOT_OPERATOR_KEYWORD = 403,
     NO_INHERIT = 404,
     NO_PRESERVE = 405,
     OR = 406,
     ORDERED = 407,
     ORDER = 408,
     BY = 409,
     GROUP = 410,
     PARENT_AXIS = 411,
     PI_BEGIN = 412,
     PI_END = 413,
     PLUS = 414,
     PRAGMA_BEGIN = 415,
     PRAGMA_END = 416,
     PRECEDES = 417,
     PRECEDING_AXIS = 418,
     PRECEDING_SIBLING_AXIS = 419,
     PRESERVE = 420,
     QUOTE = 421,
     RBRACE = 422,
     RBRACK = 423,
     RETURN = 424,
     RPAR = 425,
     SATISFIES = 426,
     SCHEMA_ATTRIBUTE_LPAR = 427,
     SELF_AXIS = 428,
     SEMI = 429,
     SLASH = 430,
     SLASH_SLASH = 431,
     STAR = 432,
     START_TAG_END = 433,
     STRIP = 434,
     TAG_END = 435,
     THEN = 436,
     TO = 437,
     TREAT = 438,
     UNION = 439,
     UNORDERED = 440,
     VAL_EQ = 441,
     VAL_GE = 442,
     VAL_GT = 443,
     VAL_LE = 444,
     VAL_LT = 445,
     VAL_NE = 446,
     VALUECOMP = 447,
     VBAR = 448,
     EMPTY_SEQUENCE = 449,
     WHERE = 450,
     XML_COMMENT_BEGIN = 451,
     XML_COMMENT_END = 452,
     XQUERY = 453,
     VERSION = 454,
     END_PRAGMA = 455,
     START = 456,
     AFTER = 457,
     BEFORE = 458,
     REVALIDATION = 459,
     _STRICT = 460,
     LAX = 461,
     SKIP = 462,
     _DELETE = 463,
     NODE = 464,
     INSERT = 465,
     NODES = 466,
     RENAME = 467,
     REPLACE = 468,
     VALUE = 469,
     OF = 470,
     FIRST = 471,
     INTO = 472,
     LAST = 473,
     MODIFY = 474,
     COPY = 475,
     WITH = 476,
     TRY = 477,
     CATCH = 478,
     USING = 479,
     ALL = 480,
     ANY = 481,
     SENSITIVE = 482,
     FT_OPTION = 483,
     DIACRITICS = 484,
     INSENSITIVE = 485,
     DIFFERENT = 486,
     DISTANCE = 487,
     ENTIRE = 488,
     END = 489,
     CONTENT = 490,
     EXACTLY = 491,
     FROM = 492,
     FTAND = 493,
     FTCONTAINS = 494,
     FTNOT = 495,
     FTOR = 496,
     LANGUAGE = 497,
     LEVELS = 498,
     LOWERCASE = 499,
     OCCURS = 500,
     PARAGRAPH = 501,
     PHRASE = 502,
     RELATIONSHIP = 503,
     SAME = 504,
     SCORE = 505,
     SENTENCE = 506,
     SENTENCES = 507,
     TIMES = 508,
     UPPERCASE = 509,
     WEIGHT = 510,
     WINDOW = 511,
     WITHOUT = 512,
     STEMMING = 513,
     STOP = 514,
     WORDS = 515,
     THESAURUS = 516,
     WILDCARDS = 517,
     CREATE = 518,
     DROP = 519,
     UNIQUE = 520,
     INDEX = 521,
     HASH = 522,
     BTREE = 523,
     ON = 524,
     BYTE_ORDER_MARK_UTF8 = 525,
     FTCONTAINS_REDUCE = 526,
     RANGE_REDUCE = 527,
     ADDITIVE_REDUCE = 528,
     MULTIPLICATIVE_REDUCE = 529,
     UNION_REDUCE = 530,
     INTERSECT_EXCEPT_REDUCE = 531,
     QVARINDECLLIST_REDUCE = 532,
     COMMA_DOLLAR = 533,
     UNARY_PREC = 534,
     SEQUENCE_TYPE_REDUCE = 535,
     OCCURS_STAR = 536,
     OCCURS_PLUS = 537,
     OCCURS_HOOK = 538,
     STEP_REDUCE = 539
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
