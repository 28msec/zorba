/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

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

// Take the name prefix into account.
#define yylex   zorbalex

#include "xquery_parser.hpp"

/* User implementation prologue.  */
#line 753 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace zorba
{
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  xquery_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  xquery_parser::xquery_parser (xquery_driver& driver_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      driver (driver_yyarg)
  {
  }

  xquery_parser::~xquery_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  xquery_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  xquery_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif /* ! YYDEBUG */

  void
  xquery_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 53: /* "\"'DECIMAL'\"" */
#line 653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).decval; };
#line 211 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 80: /* "\"'DOUBLE'\"" */
#line 652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).dval; };
#line 216 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 111: /* "\"'INTEGER'\"" */
#line 651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).ival; };
#line 221 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "VersionDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "MainModule" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "LibraryModule" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "ModuleDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "Prolog" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "SIND_DeclList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "VFO_DeclList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "SIND_Decl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "VFO_Decl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "Setter" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "Import" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "NamespaceDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "BoundarySpaceDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "DefaultNamespaceDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "OptionDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "OrderingModeDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "EmptyOrderDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "CopyNamespacesDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "DefaultCollationDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "BaseURIDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "SchemaImport" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "URILiteralList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "SchemaPrefix" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "ModuleImport" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "VarDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "ConstructionDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "FunctionDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 356 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "ParamList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 361 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Param" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 366 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "EnclosedExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "NonNodeEnclosedExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "QueryBody" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "Expr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 386 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ExprSingle" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 391 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "FLWORExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 396 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "ForLetClauseList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 401 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "ForLetClause" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 406 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ForClause" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 411 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VarInDeclList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 416 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VarInDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 421 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "PositionalVar" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 426 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LetClause" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 431 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "VarGetsDeclList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "EvalVarDeclList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VarGetsDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "EvalVarDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "WhereClause" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "GroupByClause" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "GroupSpecList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "GroupSpec" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "GroupCollationSpec" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "LetClauseList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderByClause" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderSpecList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "OrderSpec" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "OrderModifier" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OrderDirSpec" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "OrderEmptySpec" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderCollationSpec" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "QuantifiedExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 521 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "QVarInDeclList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "QVarInDecl" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "TypeswitchExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 536 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CaseClauseList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CaseClause" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "IfExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 551 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OrExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 556 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "AndExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 561 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ComparisonExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 566 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "RangeExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 571 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "AdditiveExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 576 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "MultiplicativeExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 581 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "UnionExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 586 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IntersectExceptExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 591 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "InstanceofExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 596 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "TreatExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 601 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CastableExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 606 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CastExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 611 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "UnaryExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 616 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "SignList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 621 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ValueExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "GeneralComp" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 631 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ValueComp" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 636 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "NodeComp" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 641 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ValidateExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ExtensionExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "PragmaList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 656 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "Pragma" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 661 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "PathExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "RelativePathExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StepExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "AxisStep" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ForwardStep" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 686 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ForwardAxis" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 691 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "AbbrevForwardStep" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ReverseStep" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ReverseAxis" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 706 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "NodeTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 711 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "NameTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 716 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "Wildcard" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 721 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FilterExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "PredicateList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 731 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Predicate" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "PrimaryExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Literal" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "NumericLiteral" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 751 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "VarRef" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 756 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ParenthesizedExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 761 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ContextItemExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 766 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "OrderedExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 771 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "UnorderedExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 776 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "FunctionCall" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 781 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ArgList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 786 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "Constructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 791 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "DirectConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 796 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "DirElemConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "DirElemContentList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 806 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "DirAttributeList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 811 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "DirAttr" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 816 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "DirAttributeValue" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 821 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "Opt_QuoteAttrContentList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 826 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "QuoteAttrContentList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 831 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "Opt_AposAttrContentList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 836 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "AposAttrContentList" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 841 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "QuoteAttrValueContent" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "AposAttrValueContent" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "DirElemContent" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 856 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "CommonContent" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 861 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "DirCommentConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 866 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "DirPIConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 871 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "CDataSection" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 876 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "ComputedConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 881 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CompDocConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 886 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CompElemConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 891 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CompAttrConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 896 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "CompTextConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 901 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CompCommentConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 906 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CompPIConstructor" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 911 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "SingleType" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 916 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "TypeDeclaration" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 921 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SequenceType" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 926 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OccurrenceIndicator" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 931 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ItemType" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 936 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "AtomicType" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 941 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "KindTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 946 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "AnyKindTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 951 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "DocumentTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 956 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "TextTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 961 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "CommentTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 966 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "PITest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 971 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AttributeTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SchemaAttributeTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ElementTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SchemaElementTest" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "TypeName" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "TypeName_WITH_HOOK" */
#line 657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "StringLiteral" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1006 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "InsertExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1011 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "DeleteExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1016 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "ReplaceExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1021 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "RenameExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1026 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "TransformExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1031 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "VarNameList" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1036 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "VarNameDecl" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1041 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "TryExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1046 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CatchListExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1051 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "CatchExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1056 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "EvalExpr" */
#line 658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1061 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;

	default:
	  break;
      }
  }

  void
  xquery_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

  std::ostream&
  xquery_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  xquery_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  xquery_parser::debug_level_type
  xquery_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  xquery_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }


  int
  xquery_parser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    #line 84 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}
  /* Line 547 of yacc.c.  */
#line 1142 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
      yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:
#line 774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 779 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 4:
#line 785 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 5:
#line 790 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		;}
    break;

  case 6:
#line 802 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), encoding);
		;}
    break;

  case 7:
#line 807 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (2)].sval)), SYMTAB ((yysemantic_stack_[(5) - (4)].sval)));
    ;}
    break;

  case 8:
#line 817 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;

  case 9:
#line 824 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								NULL,
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 10:
#line 836 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 848 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)));
		;}
    break;

  case 12:
#line 860 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 866 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 872 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 884 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 890 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 910 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 924 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 932 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 936 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 949 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 953 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 959 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 989 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 993 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1009 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1013 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1028 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 38:
#line 1040 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1045 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1056 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 41:
#line 1062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 42:
#line 1074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 43:
#line 1087 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1098 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1103 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1115 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1120 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1131 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 49:
#line 1137 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 50:
#line 1143 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1149 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1168 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1179 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1190 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1197 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(3) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1204 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 57:
#line 1211 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(5) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 58:
#line 1224 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1230 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1249 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1259 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1272 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 65:
#line 1278 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(7) - (7)].node)));
		;}
    break;

  case 66:
#line 1292 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 67:
#line 1299 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1306 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 69:
#line 1313 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (3)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1326 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1331 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1342 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 73:
#line 1349 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 74:
#line 1357 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 75:
#line 1365 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 76:
#line 1374 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 77:
#line 1383 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								(yysemantic_stack_[(7) - (7)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 78:
#line 1392 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 79:
#line 1401 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								(yysemantic_stack_[(8) - (8)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 80:
#line 1410 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 81:
#line 1417 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 82:
#line 1425 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 83:
#line 1433 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 84:
#line 1442 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 85:
#line 1451 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								(yysemantic_stack_[(7) - (7)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 86:
#line 1460 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 87:
#line 1469 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								(yysemantic_stack_[(8) - (8)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 88:
#line 1484 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1492 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1506 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1524 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1532 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1543 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1554 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 96:
#line 1560 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 97:
#line 1572 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1576 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1580 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1584 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1588 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1598 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1602 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1610 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 107:
#line 1614 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 108:
#line 1618 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 109:
#line 1628 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 110:
#line 1635 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 111:
#line 1643 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 112:
#line 1651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (2)].node)),
                NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 113:
#line 1660 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupByClause* lGroupBy = dynamic_cast<GroupByClause*>((yysemantic_stack_[(4) - (2)].node));
			FLWORExpr* lFLWOR = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,
                lGroupBy,
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      lGroupBy->set_flwor(lFLWOR);
      (yyval.expr) = lFLWOR;
    ;}
    break;

  case 114:
#line 1672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupByClause* lGroupBy = dynamic_cast<GroupByClause*>((yysemantic_stack_[(5) - (3)].node));
			FLWORExpr* lFLWOR = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (2)].node)),
                lGroupBy,
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
      lGroupBy->set_flwor(lFLWOR);
      (yyval.expr) = lFLWOR;
    ;}
    break;

  case 115:
#line 1684 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupByClause* lGroupBy = dynamic_cast<GroupByClause*>((yysemantic_stack_[(5) - (2)].node));
			FLWORExpr* lFLWOR = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								NULL,
                lGroupBy,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      lGroupBy->set_flwor(lFLWOR);
      (yyval.expr) = lFLWOR;
    ;}
    break;

  case 116:
#line 1696 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupByClause* lGroupBy = dynamic_cast<GroupByClause*>((yysemantic_stack_[(6) - (3)].node));
			FLWORExpr* lFLWOR = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(6) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(6) - (2)].node)),
                lGroupBy,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
      lGroupBy->set_flwor(lFLWOR);
      (yyval.expr) = lFLWOR;
    ;}
    break;

  case 117:
#line 1714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ForLetClauseList* flc_list_p = new ForLetClauseList(LOC ((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 118:
#line 1720 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 119:
#line 1732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 120:
#line 1736 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 121:
#line 1746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 122:
#line 1757 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 123:
#line 1763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 124:
#line 1777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 125:
#line 1784 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 126:
#line 1792 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 127:
#line 1801 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 128:
#line 1811 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 129:
#line 1819 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 130:
#line 1828 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 131:
#line 1837 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 132:
#line 1852 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 133:
#line 1864 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 134:
#line 1875 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 135:
#line 1887 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 136:
#line 1893 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 137:
#line 1905 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 138:
#line 1911 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 139:
#line 1925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 140:
#line 1933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 141:
#line 1942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 142:
#line 1950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 143:
#line 1962 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 144:
#line 1977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 145:
#line 1985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(2) - (2)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 146:
#line 1992 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (2)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL);
    ;}
    break;

  case 147:
#line 1999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (2)].node)),
                 NULL,
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 148:
#line 2006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(4) - (2)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(4) - (3)].node)),
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 149:
#line 2016 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 150:
#line 2022 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 151:
#line 2033 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 152:
#line 2039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 153:
#line 2048 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 154:
#line 2055 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      LetClauseList* lc_list_p = new LetClauseList(LOC((yyloc)));
      lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = lc_list_p;
    ;}
    break;

  case 155:
#line 2062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      LetClauseList* lc_list_p = dynamic_cast<LetClauseList*>((yysemantic_stack_[(2) - (1)].node));
      if (lc_list_p) lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    ;}
    break;

  case 156:
#line 2074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 157:
#line 2079 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 158:
#line 2091 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 159:
#line 2097 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 160:
#line 2111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 161:
#line 2117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 162:
#line 2129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 163:
#line 2136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 164:
#line 2143 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 165:
#line 2150 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 166:
#line 2157 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 167:
#line 2164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 168:
#line 2171 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 169:
#line 2184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 170:
#line 2188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 171:
#line 2198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 172:
#line 2203 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 173:
#line 2214 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 174:
#line 2225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 175:
#line 2232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 176:
#line 2245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 177:
#line 2252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 178:
#line 2264 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 179:
#line 2270 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 180:
#line 2283 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(7) - (4)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 181:
#line 2290 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(9) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(9) - (4)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval)),
								(yysemantic_stack_[(9) - (9)].expr));
		;}
    break;

  case 182:
#line 2304 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 183:
#line 2310 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 184:
#line 2322 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 185:
#line 2328 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 186:
#line 2341 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 187:
#line 2352 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 188:
#line 2356 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 189:
#line 2367 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 190:
#line 2371 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 191:
#line 2390 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 192:
#line 2394 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 193:
#line 2402 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<GeneralComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 194:
#line 2410 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "is" | "<<" | ">>" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 195:
#line 2424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 196:
#line 2428 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 197:
#line 2435 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 198:
#line 2448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 199:
#line 2452 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 200:
#line 2463 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 201:
#line 2467 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 202:
#line 2471 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 203:
#line 2481 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 204:
#line 2485 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 205:
#line 2489 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 206:
#line 2493 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 207:
#line 2497 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 208:
#line 2507 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 209:
#line 2511 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 210:
#line 2516 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 211:
#line 2527 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 212:
#line 2531 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 213:
#line 2535 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 214:
#line 2545 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 215:
#line 2549 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 216:
#line 2561 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 217:
#line 2565 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 218:
#line 2577 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 219:
#line 2581 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 220:
#line 2593 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 221:
#line 2597 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 222:
#line 2609 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 223:
#line 2613 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 224:
#line 2625 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 225:
#line 2629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 226:
#line 2633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 227:
#line 2637 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 228:
#line 2649 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 229:
#line 2653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 230:
#line 2657 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 2668 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 232:
#line 2672 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 233:
#line 2676 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 234:
#line 2680 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 235:
#line 2684 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 236:
#line 2688 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 237:
#line 2698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 238:
#line 2702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 239:
#line 2706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 240:
#line 2710 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 241:
#line 2714 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 242:
#line 2718 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 243:
#line 2728 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 244:
#line 2732 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 245:
#line 2736 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 246:
#line 2747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 247:
#line 2751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 248:
#line 2763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 249:
#line 2769 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 250:
#line 2781 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 251:
#line 2787 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 252:
#line 2801 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 253:
#line 2806 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 254:
#line 2849 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 255:
#line 2853 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 256:
#line 2857 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 257:
#line 2861 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 258:
#line 2874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (as != NULL ?
             new RelativePathExpr(LOC ((yyloc)),
                                  ParseConstants::st_slash,
                                  new ContextItemExpr(LOC((yyloc))),
                                  (yysemantic_stack_[(1) - (1)].expr)) :
             (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 259:
#line 2885 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 260:
#line 2890 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 261:
#line 2900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 262:
#line 2904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 263:
#line 2914 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 264:
#line 2920 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 265:
#line 2926 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 266:
#line 2932 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 267:
#line 2944 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 268:
#line 2950 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 269:
#line 2961 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 270:
#line 2965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 271:
#line 2969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 272:
#line 2973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 273:
#line 2977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 274:
#line 2981 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 275:
#line 2985 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 276:
#line 2995 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 277:
#line 2999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 278:
#line 3009 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 279:
#line 3015 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 280:
#line 3027 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 281:
#line 3031 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 282:
#line 3035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 283:
#line 3039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 284:
#line 3043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 285:
#line 3058 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 286:
#line 3062 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 287:
#line 3072 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 288:
#line 3076 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 289:
#line 3086 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 290:
#line 3093 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 291:
#line 3100 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 292:
#line 3113 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 293:
#line 3117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 294:
#line 3129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 295:
#line 3135 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 296:
#line 3149 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 297:
#line 3160 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 298:
#line 3164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 3168 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 3172 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 3176 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 3180 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 3184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 3188 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 3198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 306:
#line 3202 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 307:
#line 3212 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 308:
#line 3217 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 309:
#line 3222 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 310:
#line 3233 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 311:
#line 3243 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 312:
#line 3247 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 313:
#line 3258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 314:
#line 3268 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 315:
#line 3279 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 316:
#line 3335 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 317:
#line 3341 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 318:
#line 3353 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 319:
#line 3359 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 320:
#line 3371 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 321:
#line 3375 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 322:
#line 3385 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 323:
#line 3389 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 324:
#line 3393 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 3403 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 326:
#line 3411 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(4) - (3)].node)), 
								NULL);
		;}
    break;

  case 327:
#line 3419 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 328:
#line 3427 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(7) - (4)].node)));
		;}
    break;

  case 329:
#line 3435 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(7) - (3)].node)),
								NULL);
		;}
    break;

  case 330:
#line 3443 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(8) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(8) - (5)].node)));
		;}
    break;

  case 331:
#line 3458 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 332:
#line 3464 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 333:
#line 3476 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 334:
#line 3482 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 335:
#line 3496 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 336:
#line 3508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 337:
#line 3513 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 338:
#line 3524 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 339:
#line 3528 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 340:
#line 3535 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 341:
#line 3541 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 342:
#line 3547 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 343:
#line 3555 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 344:
#line 3569 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 345:
#line 3573 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 346:
#line 3580 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 347:
#line 3586 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 348:
#line 3592 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 349:
#line 3600 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 350:
#line 3614 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 351:
#line 3619 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 352:
#line 3630 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 353:
#line 3635 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 354:
#line 3646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 355:
#line 3651 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 356:
#line 3656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 357:
#line 3662 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 358:
#line 3674 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 359:
#line 3680 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 360:
#line 3685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 361:
#line 3690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 362:
#line 3701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 363:
#line 3706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 364:
#line 3721 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 365:
#line 3726 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 366:
#line 3743 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 367:
#line 3758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 368:
#line 3762 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 3766 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 370:
#line 3770 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 371:
#line 3774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 372:
#line 3778 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 373:
#line 3788 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 374:
#line 3799 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 375:
#line 3805 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 376:
#line 3811 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 377:
#line 3816 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 378:
#line 3838 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 379:
#line 3844 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 380:
#line 3850 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 381:
#line 3855 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 382:
#line 3866 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 383:
#line 3877 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 384:
#line 3888 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 385:
#line 3894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 386:
#line 3900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 387:
#line 3905 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 388:
#line 3916 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 389:
#line 3922 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 390:
#line 3934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 391:
#line 3945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 392:
#line 3951 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 393:
#line 3957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 394:
#line 3994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 395:
#line 3999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 396:
#line 4004 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 397:
#line 4015 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 398:
#line 4019 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 399:
#line 4023 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 400:
#line 4033 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 401:
#line 4044 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 402:
#line 4048 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 403:
#line 4052 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 404:
#line 4056 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 405:
#line 4060 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 406:
#line 4064 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 407:
#line 4068 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 408:
#line 4072 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 409:
#line 4076 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 410:
#line 4086 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 411:
#line 4096 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 412:
#line 4100 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 413:
#line 4105 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 414:
#line 4116 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 415:
#line 4126 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 416:
#line 4136 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 417:
#line 4140 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 418:
#line 4144 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 419:
#line 4154 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 420:
#line 4160 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 421:
#line 4166 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 422:
#line 4172 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 423:
#line 4178 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 424:
#line 4190 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 425:
#line 4201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 426:
#line 4207 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 427:
#line 4213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 428:
#line 4219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 429:
#line 4225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 430:
#line 4232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 431:
#line 4239 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 432:
#line 4252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 433:
#line 4273 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 434:
#line 4280 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 435:
#line 4300 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 436:
#line 4340 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 437:
#line 4345 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 438:
#line 4348 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
    ;}
    break;

  case 439:
#line 4356 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 440:
#line 4362 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 441:
#line 4368 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 442:
#line 4374 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 443:
#line 4380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 444:
#line 4387 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 445:
#line 4393 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 446:
#line 4399 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 447:
#line 4405 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 448:
#line 4411 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 449:
#line 4423 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 450:
#line 4428 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 451:
#line 4438 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 452:
#line 4444 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 453:
#line 4456 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 454:
#line 4482 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(6) - (2)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(6) - (4)].expr), (yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 455:
#line 4493 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 456:
#line 4499 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 457:
#line 4512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 458:
#line 4526 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 459:
#line 4533 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 460:
#line 4540 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 461:
#line 4551 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 462:
#line 4558 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(7) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
                          (yysemantic_stack_[(7) - (7)].expr));
    ;}
    break;

  case 463:
#line 4566 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(10) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(10) - (5)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
                          (yysemantic_stack_[(10) - (10)].expr));
    ;}
    break;

  case 464:
#line 4575 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(13) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(13) - (5)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(13) - (8)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(13) - (11)].sval)),
                          (yysemantic_stack_[(13) - (13)].expr));
    ;}
    break;

  case 465:
#line 4594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(5) - (2)].node)),
                          (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 466:
#line 4600 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(3) - (2)].expr));
    ;}
    break;

  case 467:
#line 4617 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 468:
#line 4620 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 469:
#line 4623 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 470:
#line 4626 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 471:
#line 4635 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 472:
#line 4638 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 473:
#line 4641 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 474:
#line 4644 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 475:
#line 4653 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 476:
#line 4656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 477:
#line 4665 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 478:
#line 4668 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 479:
#line 4677 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 480:
#line 4680 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 481:
#line 4689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 482:
#line 4692 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 483:
#line 4701 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 484:
#line 4704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 485:
#line 4707 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 486:
#line 4716 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 487:
#line 4719 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 488:
#line 4728 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 489:
#line 4731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 490:
#line 4740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 491:
#line 4743 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 492:
#line 4746 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 493:
#line 4749 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 494:
#line 4752 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 495:
#line 4761 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 496:
#line 4770 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 497:
#line 4774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 498:
#line 4778 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 499:
#line 4782 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 500:
#line 4786 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 501:
#line 4790 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 502:
#line 4794 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 503:
#line 4804 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 504:
#line 4807 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 505:
#line 4810 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 506:
#line 4813 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 507:
#line 4822 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 508:
#line 4825 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 509:
#line 4828 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 510:
#line 4831 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 511:
#line 4840 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 512:
#line 4843 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 513:
#line 4852 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 514:
#line 4855 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 515:
#line 4858 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 516:
#line 4861 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 517:
#line 4864 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 518:
#line 4867 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 519:
#line 4870 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 520:
#line 4879 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 521:
#line 4882 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 522:
#line 4891 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 523:
#line 4894 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 524:
#line 4897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 525:
#line 4900 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 526:
#line 4909 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 527:
#line 4912 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 528:
#line 4915 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 529:
#line 4918 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 530:
#line 4921 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 531:
#line 4930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 532:
#line 4933 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 533:
#line 4942 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 534:
#line 4945 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 535:
#line 4954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 536:
#line 4957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 537:
#line 4966 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 538:
#line 4969 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 539:
#line 4978 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 540:
#line 4987 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 541:
#line 4990 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 542:
#line 4999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 543:
#line 5002 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 544:
#line 5005 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 545:
#line 5014 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 546:
#line 5017 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 547:
#line 5020 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 548:
#line 5023 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 549:
#line 5026 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 550:
#line 5035 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 551:
#line 5039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 552:
#line 5043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 553:
#line 5047 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 554:
#line 5057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 555:
#line 5066 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 556:
#line 5075 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 557:
#line 5084 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 558:
#line 5087 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 559:
#line 5096 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 560:
#line 5099 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 561:
#line 5102 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 562:
#line 5111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 563:
#line 5114 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;

  case 564:
#line 5123 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 5841 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	default: break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse look-ahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		   &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyeof_ && yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  xquery_parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int xquery_parser::yypact_ninf_ = -681;
  const short int
  xquery_parser::yypact_[] =
  {
       777,  1199,  1410,  -681,  -681,    16,  -681,    32,  -681,  -681,
    -681,  3098,    35,   468,  -681,  3098,   -38,  -681,   323,   192,
     195,   320,   327,   251,   300,   380,   281,   399,   374,   -37,
     404,   434,  -681,  -681,  3098,   409,   447,  -681,  -681,  -681,
    3098,    71,   474,  -681,  -681,   478,  3098,    41,   309,  -681,
     484,  1621,  -681,   507,   364,  3098,  -681,   511,    68,  -681,
     448,  -681,  -681,   268,   515,   530,  -681,  3810,  3648,   474,
    -681,   548,  3098,   417,  3098,  3098,  3098,    15,   551,   430,
    3098,  3098,  3098,  3098,  3098,  3098,  3098,   561,   488,   580,
    3098,  3750,   611,   988,  -681,  -681,   253,  3098,   450,   454,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
     573,  -681,  -681,   415,  -681,  -681,  -681,  -681,  -681,  -681,
     486,   594,  -681,  3813,   402,   -10,   257,   -69,   326,  -681,
     519,   469,   612,   615,  3309,  -681,  -681,  -681,     3,  -681,
    -681,  -681,   310,  -681,   545,   468,  -681,   545,   468,  -681,
    -681,  -681,  -681,   545,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,    25,  -681,    62,  1832,  3098,   113,
      23,  -681,    66,  -681,  -681,   122,  -681,  -681,  -681,  -681,
    -681,  -681,   616,   617,  -681,   638,   641,  -681,  -681,   546,
     581,   647,  -681,  -681,   555,   446,   123,  -681,   512,   531,
    -681,   124,    72,  -681,    83,   245,    14,  -681,    -9,   642,
    -681,    93,   657,   678,   659,   570,   682,   674,    -8,   656,
    -681,  -681,    94,   618,  -681,   130,    44,   552,   558,  -681,
     687,  -681,   604,  3098,   562,   563,  -681,  -681,    29,    36,
     131,  -681,    95,   133,   148,   528,  -681,     8,  -681,  -681,
    -681,  -681,  -681,   489,   521,   694,   513,   514,   627,    10,
    -681,  3098,  -681,    -6,  -681,   579,  -681,  -681,  -681,  -681,
     716,  -681,  -681,  -681,  -681,  -681,  -681,  -681,    -5,  -681,
    -681,   258,   307,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,   253,     1,  3098,
    3098,   676,  3098,  3098,  3098,  -681,   426,   379,   595,  3479,
    3479,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  3479,  3479,  3479,     4,
    3479,  3479,  3479,  3479,  3479,  3479,  3479,  3479,  3479,  3479,
    3479,   400,   400,   733,   733,  -681,  -681,  -681,  2043,  -681,
    3648,  3648,  3098,   545,  -681,  -681,   545,  -681,   545,  -681,
    -681,  -681,  -681,   105,   234,   640,   736,  -681,   736,  -681,
    -681,     7,   193,  -681,  -681,    27,   732,  -681,    75,   400,
    -681,  3098,   256,  -681,  -681,  -681,   644,   740,  -681,   740,
    -681,  3098,   653,   686,  3098,   688,  3098,   689,   -26,   655,
      -1,   690,   590,   743,   680,   743,  -681,   681,   737,  3098,
     670,   -62,   697,  -681,   749,  -681,  -681,  -681,  -681,  -681,
    -681,  2254,   238,  -681,  -681,  3098,   691,  -681,    51,    39,
    -681,  -681,   734,  -681,  -681,  -681,   752,  -681,  3098,  3098,
    3098,  3098,  3098,  3098,  3098,  3098,  3098,  3098,  3098,  3098,
    3098,  3098,   701,  3098,   621,   703,  3098,  -681,  -681,   258,
     258,    -5,  -681,   758,   759,    -5,   761,  -681,   263,  -681,
     622,  -681,  -681,  -681,    64,   738,  -681,   764,    21,  -681,
    -681,   738,  -681,  3098,   421,   632,  3098,   633,  3098,   594,
    -681,  -681,  -681,  -681,  3098,     4,   406,  -681,   534,   416,
     559,   553,  -681,  -681,   550,   239,   257,   257,   -15,   -69,
     -69,   -69,   -69,   326,   326,  -681,  -681,  -681,  -681,  -681,
    -681,   505,  -681,  -681,  -681,  -681,   699,  -681,  -681,   274,
    -681,  -681,   100,  -681,  3098,  -681,  -681,  2465,  -681,   643,
     645,  -681,  -681,  -681,  -681,   782,   261,   106,  -681,  -681,
     357,   107,  -681,  -681,  -681,  3098,  2676,   706,   650,   651,
     652,   658,  -681,  3098,   474,  -681,   787,  -681,   794,  3098,
     717,  3098,  3098,   -19,   718,   478,  3098,  -681,   776,   802,
     776,  -681,   743,  -681,  3098,  3098,   744,   484,   684,  -681,
     275,   731,  -681,    18,  -681,  -681,   843,  -681,  -681,  3098,
     836,  -681,  -681,    65,  -681,  -681,  -681,  -681,    77,  -681,
     395,   298,  -681,   693,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,   561,   702,
     646,   580,   705,  -681,  -681,  -681,  -681,  -681,    54,    -5,
     354,   109,   111,     1,  -681,   838,  -681,  -681,  -681,  -681,
      43,   817,  -681,  3098,   819,   676,  -681,  -681,   176,  -681,
    3098,   708,  3098,  -681,  3098,  -681,   276,   710,  -681,  3479,
    -681,  -681,  -681,  -681,    50,   389,  -681,     4,    50,  3479,
    3479,   480,  -681,  -681,  -681,  -681,  -681,  -681,  -681,     4,
       4,   389,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,   284,  -681,
    -681,   835,   400,  -681,  3098,  -681,   795,   390,   400,  -681,
    -681,   396,  -681,  -681,   285,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  3098,  -681,  -681,  3098,   766,
    3098,  -681,   792,   852,   844,   776,  -681,  -681,  3098,  -681,
    -681,  -681,  2887,   247,   427,  -681,  -681,   287,   704,   860,
    -681,   865,   125,   863,   727,   213,  -681,  -681,  -681,  3098,
      60,   646,  -681,  -681,  -681,  -681,  -681,  3479,  3479,  3479,
    3479,   866,   648,   856,  -681,   856,  -681,  -681,   817,  -681,
    -681,  -681,   867,  -681,  -681,  -681,  -681,  -681,  3098,  -681,
    -681,  -681,  -681,   -69,  -681,  -681,  -681,  -155,   559,  -681,
    -681,   244,  3479,  -681,  -681,   553,  -681,   639,  -681,  -681,
     388,   288,  -681,   400,  -681,  -681,   418,   400,  -681,  -681,
    -681,  -681,  -681,  3098,  -681,  3098,  -681,   743,  -681,  -681,
     292,  -681,  -681,   862,   248,  -681,  -681,  -681,  -681,   741,
     458,  -681,  -681,  -681,  -681,   725,   729,   881,   871,  3098,
     879,  3098,  -681,   112,  -681,   -69,   -69,   -69,   419,   389,
    -681,   114,  -681,   115,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,   471,  -681,  -681,
     476,  -681,  -681,   776,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,   735,   400,  -681,   747,  -681,   832,   796,
    3479,   665,   856,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
     753,  3098,   887,  -681,   -69,  -681,  -681,  3098,  -681,   116,
    -681,   839,   796,   888,  -681,   117,   841,   796,   892,  -681,
     762,   796,  -681
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   290,   291,   287,   435,     0,   281,   284,
     271,     0,     0,     0,   269,     0,     0,   307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,   273,     0,     0,     0,   313,   279,   309,
       0,     0,     0,   275,   274,     0,     0,     0,     0,   308,
       0,     0,   225,     0,     0,     0,   280,     0,     0,   224,
       0,   283,   282,     0,     0,     0,   272,   254,     0,     0,
     289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     4,     0,     0,     0,     0,
      15,    17,    19,    20,    21,    27,    22,    25,    26,    31,
      32,    33,    28,    29,    35,    36,    23,    30,    24,     9,
      94,    95,    97,     0,   117,   119,   120,    98,    99,   100,
     101,   187,   189,   191,   195,   198,   200,   203,   208,   211,
     214,   216,   218,   220,     0,   222,   228,   230,     0,   250,
     229,   257,   258,   261,   263,     0,   268,   265,     0,   276,
     286,   288,   262,   292,   297,   305,   298,   299,   300,   303,
     304,   301,   302,   320,   322,   323,   324,   321,   367,   368,
     369,   370,   371,   372,   285,   409,   401,   408,   407,   406,
     403,   405,   402,   404,   306,    34,   102,   103,   105,   104,
     106,   107,   108,   378,     0,   374,     0,     0,     0,     0,
       0,   419,     0,   287,   277,     0,   415,    53,    38,    39,
      70,    71,     0,     0,    52,     0,     0,    46,    47,     0,
       0,     0,    44,    45,     0,     0,     0,   411,     0,     0,
     310,     0,     0,   425,     0,     0,     0,   176,     0,   121,
     122,     0,    62,     0,    54,     0,     0,     0,     0,   134,
     135,   311,     0,     0,   410,     0,     0,     0,     0,   416,
       0,   253,     0,     0,     0,     0,   255,   256,     0,     0,
       0,   414,     0,     0,     0,     0,   363,     0,   436,   437,
     438,   449,   450,     0,     0,     0,     0,     0,     0,     0,
     455,     0,   143,     0,   137,     0,   506,   505,   510,   509,
       0,   503,   504,   508,   512,   530,   519,   541,   528,   507,
     511,     0,     0,   540,    43,   496,   497,   498,   499,   500,
     501,   502,     1,     3,     5,    10,     8,    12,    13,     0,
       0,     0,     0,     0,     0,   118,     0,     0,     0,     0,
       0,   231,   245,   236,   235,   243,   234,   233,   232,   244,
     237,   242,   241,   240,   239,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   226,   223,     0,   251,
       0,     0,     0,   264,   294,   267,   266,   278,   293,   379,
     375,   316,   318,     0,     0,     0,     0,   420,     0,   422,
     383,     0,     0,    40,    41,     0,     0,    42,     0,     0,
      67,     0,     0,   373,   412,   413,     0,     0,   426,     0,
     429,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,    55,     0,
       0,     0,     0,   312,     0,   314,   365,   364,   417,   418,
     252,     0,     0,   424,   432,     0,     0,   325,     0,     0,
     333,   382,     0,   315,   246,   362,     0,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   466,   539,     0,
       0,   529,   531,     0,     0,   526,     0,   514,     0,   513,
       0,    16,    18,    96,   160,   156,   158,     0,   145,   149,
     109,   157,   144,     0,     0,     0,     0,     0,     0,   188,
     190,   193,   192,   194,     0,     0,     0,   488,   196,   467,
     475,   477,   479,   481,   483,   486,   202,   201,   199,   205,
     206,   207,   204,   209,   210,   213,   212,   400,   399,   393,
     215,   391,   397,   398,   217,   219,   388,   221,   248,     0,
     259,   260,     0,   295,     0,   317,   247,     0,   433,     0,
       0,    50,    51,    48,    49,     0,     0,     0,    88,    37,
       0,     0,   390,    66,    69,     0,     0,   433,     0,     0,
       0,     0,   178,     0,     0,   175,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    64,     0,
      56,    60,     0,   139,     0,     0,     0,     0,     0,   384,
       0,     0,   174,     0,   358,   355,     0,   359,   360,     0,
       0,   361,   354,     0,   331,   357,   356,   326,     0,   334,
       0,     0,   182,     0,   442,   443,   440,   439,   441,   447,
     448,   445,   444,   446,   453,   451,   452,   457,     0,     0,
       0,     0,     0,   538,   537,   532,   533,   535,     0,   527,
     522,     0,     0,    14,   169,     0,   170,   171,   172,   161,
     162,   163,   164,     0,   151,     0,   154,   147,   146,   110,
       0,     0,     0,   113,     0,   111,     0,     0,   482,     0,
     197,   495,   543,   542,     0,     0,   544,     0,     0,     0,
       0,   468,   472,   490,   471,   494,   492,   491,   493,     0,
       0,     0,   484,   547,   548,   545,   546,   549,   487,   394,
     396,   395,   392,   389,   249,   296,   319,   380,     0,   421,
     423,    90,     0,    72,     0,    73,     0,     0,     0,    80,
      81,     0,    68,   376,     0,   434,   427,   428,   430,   431,
     179,   177,   132,   133,   126,     0,   128,   125,     0,     0,
       0,   123,     0,     0,    63,    57,   141,   140,     0,   136,
      11,   385,     0,   344,   338,   335,   366,     0,     0,     0,
     332,     0,     0,     0,     0,     0,   183,     7,   456,     0,
       0,   458,   459,   138,   465,   536,   534,     0,     0,     0,
       0,     0,     0,     0,   517,     0,   515,   173,   165,   166,
     167,   159,     0,   152,   150,   155,   148,   114,     0,   112,
     115,   489,   485,   564,   563,   562,   558,     0,   476,   557,
     469,     0,     0,   474,   473,   478,   480,     0,   381,    91,
       0,     0,    89,     0,    74,    75,     0,     0,    82,    83,
     377,   130,   127,     0,   129,     0,    59,     0,   142,   386,
       0,   352,   346,     0,   345,   347,   353,   350,   340,     0,
     339,   341,   351,    92,   327,     0,     0,     0,     0,     0,
       0,     0,   454,     0,   460,   551,   552,   550,     0,   523,
     524,     0,   520,     0,   168,   153,   116,   561,   560,   559,
     554,   555,   470,   556,    76,    77,    93,     0,    84,    85,
       0,   131,   186,    65,   387,   337,   348,   349,   336,   342,
     343,   328,   329,     0,     0,   184,     0,   180,     0,     0,
       0,     0,     0,   518,   516,    78,    79,    86,    87,   330,
       0,     0,     0,   461,   553,   525,   521,     0,   181,     0,
     185,     0,     0,     0,   462,     0,     0,     0,     0,   463,
       0,     0,   464
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -681,  -681,  -681,   828,   831,  -681,   837,  -681,   591,   597,
    -319,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -437,  -681,  -681,  -681,  -681,  -681,
     509,   179,  -681,  -560,   834,    30,   -80,  -681,  -681,   813,
    -681,  -681,   322,   498,  -240,  -481,  -681,  -681,   315,   277,
    -480,   600,  -681,   255,  -681,  -681,  -300,   608,   262,  -681,
    -681,   264,  -642,  -681,   889,   352,  -681,  -681,   308,  -681,
    -681,   613,   614,   289,  -675,   589,   182,  -362,   118,   180,
    -681,  -681,  -681,  -681,  -681,   821,  -681,  -681,  -681,  -681,
    -681,  -681,   815,  -681,   -46,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,    84,   156,  -681,  -681,   217,   203,  -681,  -333,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -459,
    -681,   319,  -681,   500,  -681,  -681,  -681,  -681,  -681,    80,
      87,  -603,  -502,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,   588,  -225,  -365,  -681,  -681,   225,  -366,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,   939,   941,   175,
     560,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,   311,
    -681,  -681,   166,  -681,   445,  -681,  -681,   273,   252,   266,
     455,  -681,  -681,   280,  -681,  -512,  -681,  -681,  -681,  -681,
     169,  -315,  -681,   497,   136,  -681,  -472,  -681,  -681,  -681,
    -681,  -680,  -681,  -681,  -681,  -681,   152,   286,  -681
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   618,   257,   115,   116,   117,   118,
     587,   588,   641,   755,   119,   120,   121,   122,   123,   124,
     125,   249,   250,   438,   439,   126,   259,   303,   260,   304,
     346,   347,   518,   519,   833,   698,   348,   515,   516,   689,
     690,   691,   692,   127,   246,   247,   128,   651,   652,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   366,   367,   368,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   393,   394,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   403,   172,   173,
     174,   643,   469,   470,   795,   889,   890,   883,   884,   891,
     885,   644,   645,   175,   176,   646,   177,   178,   179,   180,
     181,   182,   183,   565,   422,   560,   742,   561,   562,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   579,
     599,   194,   195,   196,   197,   198,   199,   200,   299,   300,
     201,   811,   812,   202,   538,   721,   539,   540,   541,   542,
     543,   544,   545,   722,   723,   324,   325,   326,   327,   328,
     911,   912,   329,   501,   505,   678,   502,   330,   331,   725,
     738,   822,   726,   727,   732,   728,   920,   846,   710
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       291,   292,   293,   294,   295,   296,   297,   509,   620,   642,
     305,   549,   550,   551,   552,   563,   563,   564,   450,   512,
     432,   276,   277,   440,   419,   419,   435,   724,     6,   675,
     760,   204,   206,   451,   435,   847,   537,   696,   697,   625,
     800,   209,   495,   285,   850,   215,   525,   527,   829,   830,
     793,   857,   456,   563,   592,   210,   466,    17,   492,   466,
     634,   635,   433,    26,   236,    28,   252,    30,    31,   695,
     241,   406,     3,   339,   634,   635,   251,   433,   815,     4,
     213,   262,   609,   267,    39,   265,   634,   635,   499,   778,
     685,   242,   268,   449,   917,   636,   476,   214,   684,   436,
     918,   232,   280,   585,   282,   283,   284,   612,   370,   636,
     339,   685,   377,   370,   408,    49,   581,   919,   388,   534,
     427,   636,   216,   467,   378,   535,   647,   402,   687,   688,
     637,   429,   638,   371,   634,   635,   686,   207,   371,   582,
      50,   339,   339,   339,   637,   233,   638,   208,   339,   687,
     688,   585,    60,   574,   756,   756,   637,   823,   638,   825,
     948,   339,   952,   952,   971,   976,   639,   253,   372,   636,
     339,   339,   339,   477,   794,   434,   500,   922,   339,   339,
     639,   339,   399,   407,   642,   785,   914,   586,   457,   642,
     465,   437,   639,   682,    57,   211,   339,   865,   610,   800,
     614,   869,   537,   537,   637,   212,   638,   675,    57,   854,
     468,   626,   286,   648,   816,   496,   344,   835,   836,   400,
      57,   494,   640,    71,   701,   493,   409,   437,   269,   951,
      70,   243,   428,    91,   437,   590,   799,    71,   404,   395,
     639,   244,   397,   430,   437,   437,   536,    77,   801,    71,
     881,   881,   437,   442,   453,   472,   634,   634,   745,   513,
     514,    77,   520,   514,   522,   575,   757,   761,    57,   824,
     405,   826,   949,    77,   953,   954,   972,   977,   419,   410,
     423,   426,   339,   272,   563,   804,   339,   455,   471,   900,
     473,   886,   892,   503,   752,    50,   897,    71,   506,   844,
     925,   229,   583,   462,   845,   474,   929,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    77,   339,   339,   339,   584,   637,   637,   638,   638,
     373,   681,   339,   339,   254,   339,   339,   882,   936,   650,
     339,   593,   506,   642,   570,   571,   218,   843,   217,   220,
     594,   602,   224,   431,   605,   753,   607,   595,   851,    47,
      48,   374,   639,   639,   512,   219,   805,   956,   221,   623,
     958,   344,   901,   779,   396,   507,   754,   225,   255,   504,
     398,   375,   886,   273,   537,   632,   563,   860,   892,   963,
     758,   576,   563,   866,   231,   631,   537,   537,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   974,   669,   230,   557,   672,   979,   569,   379,
     557,   982,   572,   863,   234,   377,   226,   376,   508,   867,
       6,   744,   791,   841,    12,   256,   634,   378,   380,    12,
     933,   858,   870,   699,   893,   926,   703,    16,   705,   934,
     887,   759,    16,   222,    79,   905,   906,   907,   908,    17,
     235,   733,   734,   735,   736,   227,   228,   634,   270,   271,
      35,   803,   754,   240,   223,    35,   390,   391,    41,   419,
       3,   887,   924,    41,   864,    91,    39,     4,   213,   737,
     868,   630,    41,   917,   746,   553,   554,   563,   927,   918,
     245,   563,   930,   754,   248,   754,   637,    12,   638,   558,
     258,   754,   928,    45,   558,   762,   919,    49,   888,   340,
      16,   534,   263,   770,   264,    54,   859,   535,   266,   774,
      54,   776,   777,   754,    50,   274,   782,   637,   526,   638,
     420,    58,   639,    35,   786,   787,    58,   421,   343,   939,
     275,    41,   546,   547,   711,   340,   341,    64,    65,   555,
     556,   340,    64,    65,   706,   955,   340,   341,   279,   237,
     957,    73,    65,   639,   342,   287,    73,   281,   563,   960,
     700,   817,   818,   580,   343,   523,   754,   298,   964,   559,
     343,   754,   819,   820,   559,   343,   573,   950,    54,   573,
     377,   573,   598,   301,   600,   821,   302,   748,   566,   566,
     344,   332,   378,   514,    58,   337,   817,   818,   711,   338,
     837,   339,   839,   349,   840,   350,   764,   819,   820,   381,
      64,    65,   288,   289,   290,   673,   674,   966,    70,   739,
     740,   741,   712,   369,    73,   713,   306,   307,   382,   308,
     309,   714,   715,   716,   383,   531,   532,   533,   384,   717,
     310,   392,   311,   413,   411,   412,   414,   415,   718,   797,
     416,   417,   424,   312,   719,   720,   418,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   478,   479,
     441,   425,   443,   444,   445,   871,   446,   447,   872,   448,
     874,   480,   481,   482,   452,   460,   712,   454,   878,   713,
     306,   307,   458,   308,   309,   714,   715,   716,   459,   461,
     483,   484,   463,   464,   310,   475,   311,   488,   491,   902,
     489,   490,   718,   485,   486,   487,   497,   312,   852,   720,
     498,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   517,   557,   528,   577,   578,   589,   916,   596,
     597,   603,   604,   611,   606,   608,   615,   616,   617,   619,
     621,   624,   622,   627,   628,   650,   653,   668,   670,   671,
     633,     1,   676,   677,   861,   680,   693,   683,     2,     3,
     694,   702,   704,   931,   709,   932,     4,     5,   731,   729,
     730,     6,   743,   749,     7,   750,     8,     9,   751,   765,
     766,   767,   768,   772,    10,    11,    12,    13,   769,   945,
     773,   947,   880,    14,   783,   775,   780,   784,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   788,   792,    32,    33,   790,
     796,    34,    35,    36,    37,    38,   798,    39,   807,    40,
      41,   809,   814,   827,   685,   810,   832,   838,   419,    42,
     842,   585,    43,    44,   873,    45,   875,   876,   894,   877,
     895,   968,    46,    47,    48,   896,   899,   970,    49,   898,
     909,   506,   915,   910,   935,   923,    50,   938,    51,   941,
      52,   943,    53,   942,   944,   946,   961,    54,   962,   959,
     965,   754,   967,   969,   975,   973,    55,   978,   980,    56,
      57,   333,   981,    58,   334,    59,    60,   591,   510,    61,
      62,   336,    63,   335,   511,   862,   345,   781,   613,    64,
      65,    66,   789,    67,    68,    69,   524,    70,   813,    71,
     834,   521,    72,    73,   828,   831,   771,    74,   278,   806,
      75,   548,   529,   389,   530,   387,   903,   802,    76,   649,
     940,   937,   567,    77,   238,    78,   239,   904,    79,   808,
     707,   855,    80,    81,    82,    83,    84,    85,    86,   601,
     848,   708,     1,    87,   913,    88,   856,    89,    90,     2,
       3,   853,   679,   921,   849,     0,     0,     4,     5,    91,
       0,     0,     6,     0,     0,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,     0,    32,    33,
       0,     0,    34,    35,    36,    37,    38,     0,    39,     0,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,     0,    43,    44,     0,    45,     0,     0,     0,
       0,     0,     0,    46,    47,    48,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    51,
       0,    52,     0,    53,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
      56,    57,     0,     0,    58,     0,    59,    60,     0,     0,
      61,    62,     0,    63,     0,     0,     0,     0,     0,     0,
      64,    65,    66,     0,    67,    68,    69,     0,    70,     0,
      71,     0,     0,    72,    73,     0,     0,     0,    74,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,    77,     0,     0,     0,     0,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     1,    87,     0,    88,     0,    89,    90,
       2,     3,     0,     0,     0,     0,     0,     0,     4,     5,
      91,     0,     0,     6,     0,     0,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
      51,     0,    52,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,    56,    57,     0,     0,    58,     0,    59,    60,     0,
       0,    61,    62,     0,    63,     0,   203,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,    69,     0,    70,
       0,    71,     0,     0,    72,    73,     0,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     1,    87,     0,    88,     0,    89,
      90,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     0,     7,     0,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,    43,    44,     0,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,   205,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,    69,     0,
      70,     0,    71,     0,     0,    72,    73,     0,     0,     0,
      74,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,     1,    87,     0,    88,     0,
      89,    90,     2,     3,     0,     0,     0,     0,     0,     0,
       4,     5,     0,     0,     0,     6,     0,     0,     7,     0,
       8,     9,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,     0,    43,    44,     0,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    51,     0,    52,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,    56,    57,     0,     0,    58,     0,    59,
      60,     0,     0,    61,    62,     0,    63,     0,     0,     0,
       0,   261,     0,    64,    65,    66,     0,    67,    68,    69,
       0,    70,     0,    71,     0,     0,    72,    73,     0,     0,
       0,    74,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     1,    87,     0,    88,
       0,    89,    90,     2,     3,     0,     0,     0,     0,     0,
       0,     4,     5,     0,     0,     0,     6,     0,     0,     7,
       0,     8,     9,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,     0,     0,    34,    35,    36,    37,
      38,     0,    39,     0,    40,    41,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,    43,    44,     0,
      45,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,    50,     0,    51,     0,    52,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,    56,    57,     0,     0,    58,     0,
      59,    60,     0,     0,    61,    62,     0,    63,     0,     0,
       0,     0,   401,     0,    64,    65,    66,     0,    67,    68,
      69,     0,    70,     0,    71,     0,     0,    72,    73,     0,
       0,     0,    74,     0,     0,    75,     0,     0,     0,     0,
       0,     0,     0,    76,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     1,    87,     0,
      88,     0,    89,    90,     2,     3,     0,     0,     0,     0,
       0,     0,     4,     5,     0,     0,     0,     6,     0,     0,
       7,     0,     8,     9,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,     0,     0,    34,    35,    36,
      37,    38,     0,    39,     0,    40,    41,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,    43,    44,
       0,    45,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,    50,     0,    51,     0,    52,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,    56,    57,     0,     0,    58,
       0,    59,    60,     0,     0,    61,    62,     0,    63,     0,
     568,     0,     0,     0,     0,    64,    65,    66,     0,    67,
      68,    69,     0,    70,     0,    71,     0,     0,    72,    73,
       0,     0,     0,    74,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     1,    87,
       0,    88,     0,    89,    90,     2,     3,     0,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     0,     6,     0,
       0,     7,     0,     8,     9,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    33,     0,     0,    34,    35,
      36,    37,    38,     0,    39,     0,    40,    41,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     0,    43,
      44,     0,    45,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    51,     0,    52,     0,     0,
       0,     0,     0,     0,    54,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     0,     0,    56,    57,     0,     0,
      58,     0,    59,    60,     0,     0,    61,    62,     0,    63,
       0,   629,     0,     0,     0,     0,    64,    65,    66,     0,
      67,    68,    69,     0,    70,     0,    71,     0,     0,    72,
      73,     0,     0,     0,    74,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     1,
      87,     0,    88,     0,    89,    90,     2,     3,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     0,     6,
       0,     0,     7,     0,     8,     9,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,    34,
      35,    36,    37,    38,     0,    39,     0,    40,    41,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,     0,
      43,    44,     0,    45,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,    50,     0,    51,     0,    52,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,    56,    57,     0,
       0,    58,     0,    59,    60,     0,     0,    61,    62,     0,
      63,     0,   747,     0,     0,     0,     0,    64,    65,    66,
       0,    67,    68,    69,     0,    70,     0,    71,     0,     0,
      72,    73,     0,     0,     0,    74,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    76,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       1,    87,     0,    88,     0,    89,    90,     2,     3,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     0,
       6,     0,     0,     7,     0,     8,     9,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,    43,    44,     0,    45,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    51,     0,    52,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,    56,    57,
       0,     0,    58,     0,    59,    60,     0,     0,    61,    62,
       0,    63,     0,   763,     0,     0,     0,     0,    64,    65,
      66,     0,    67,    68,    69,     0,    70,     0,    71,     0,
       0,    72,    73,     0,     0,     0,    74,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     1,    87,     0,    88,     0,    89,    90,     2,     3,
       0,     0,     0,     0,     0,     0,     4,     5,     0,     0,
       0,     6,     0,     0,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,    38,     0,    39,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,     0,    43,    44,     0,    45,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,    50,     0,    51,     0,
      52,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,    56,
      57,     0,     0,    58,     0,    59,    60,     0,     0,    61,
      62,     0,    63,     0,   879,     0,     0,     0,     0,    64,
      65,    66,     0,    67,    68,    69,     0,    70,     0,    71,
       0,     0,    72,    73,     0,     0,     0,    74,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     1,    87,     0,    88,     0,    89,    90,     2,
       3,     0,     0,     0,     0,     0,     0,     4,     5,     0,
       0,     0,     6,     0,     0,     7,     0,     8,     9,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
       0,     0,    34,    35,    36,    37,    38,     0,    39,     0,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,     0,    43,    44,     0,    45,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    51,
       0,    52,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
      56,    57,     0,     0,    58,     0,    59,    60,     0,     0,
      61,    62,     0,    63,     0,     0,     0,     0,     0,     0,
      64,    65,    66,     0,    67,    68,    69,     0,    70,     0,
      71,     0,     0,    72,    73,     0,     0,     0,    74,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     1,    87,     0,    88,     0,    89,    90,
       2,     3,     0,     0,     0,     0,     0,     0,     4,     5,
       0,     0,     0,     6,     0,     0,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,   385,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,    56,    57,     0,     0,    58,     0,   386,    60,     0,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,     0,     0,    70,
       0,    71,     0,     1,    72,    73,     0,     0,     0,     0,
       2,     3,    75,     0,     0,     0,     0,     0,     4,     5,
      76,     0,     0,     6,     0,    77,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,    52,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,    56,    57,     0,     0,    58,     0,    59,    60,     0,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,     0,     0,    70,
       0,    71,     1,     0,    72,    73,     0,     0,     0,     2,
       3,     0,    75,     0,     0,     0,     0,     4,     5,     0,
      76,     0,     6,     0,     0,    77,     0,     8,     9,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
       0,     0,    34,    35,    36,    37,    38,     0,    39,     0,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     0,
      56,    57,     0,     0,    58,     0,     0,     0,     0,     0,
      61,    62,     0,    63,     0,     0,     0,     0,     0,     0,
      64,    65,    66,     0,     1,     0,     0,     0,    70,     0,
      71,     2,     3,    72,    73,     0,     0,     0,     0,     4,
       5,    75,     0,     0,     6,     0,     0,     0,     0,     8,
       9,     0,     0,     0,    77,     0,     0,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,    34,    35,    36,    37,    38,     0,
      39,     0,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,   351,     0,     0,    43,    44,     0,     0,     0,
     352,     0,     0,   353,     0,   354,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,   355,     0,     0,     0,
     356,    51,     0,     0,     0,   357,     0,     0,     0,     0,
      54,   358,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,     0,     0,
       0,     0,    61,    62,   359,    63,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,     0,     0,     0,     0,
     306,   307,    71,   308,   309,    72,    73,     0,     0,     0,
       0,     0,     0,    75,   310,     0,   311,     0,   360,   361,
     362,   363,   364,   365,     0,     0,    77,   312,     0,     0,
       0,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,    84,    85,    86,   322,   445,   468,
      90,   373,   374,   375,   376,   381,   382,   382,   258,   338,
     245,    67,    68,   248,    33,    33,    35,   539,    24,   501,
     590,     1,     2,   258,    35,   715,   369,   518,   518,   101,
     643,    11,    48,    28,   719,    15,   346,   347,   690,   691,
      32,   731,     8,   419,   419,    20,    20,    53,    48,    20,
       9,    10,    48,    62,    34,    64,    25,    66,    67,    48,
      40,    48,    12,    48,     9,    10,    46,    48,    24,    19,
      20,    51,   108,    15,    80,    55,     9,    10,    93,   108,
      47,    20,    24,   101,   249,    44,    88,    13,    34,   108,
     255,   138,    72,    76,    74,    75,    76,   108,   123,    44,
      48,    47,   181,   123,    48,   111,   109,   272,   115,   115,
      48,    44,   160,    87,   193,   121,    87,   207,    85,    86,
      79,    48,    81,   148,     9,    10,    72,   121,   148,   132,
     119,    48,    48,    48,    79,   182,    81,   115,    48,    85,
      86,    76,   149,    48,    48,    48,    79,    48,    81,    48,
      48,    48,    48,    48,    48,    48,   115,   126,   178,    44,
      48,    48,    48,   165,   156,   161,   181,   852,    48,    48,
     115,    48,   157,   160,   643,   622,   828,   160,   144,   648,
     161,   253,   115,   508,   143,   160,    48,   757,   438,   802,
     440,   761,   535,   536,    79,   170,    81,   679,   143,   721,
     174,   451,   197,   174,   160,   221,   195,   698,   698,   157,
     143,   301,   171,   172,   524,   215,   160,   253,   160,   909,
     170,   160,   160,   232,   253,   160,   171,   172,   208,   155,
     115,   170,   158,   160,   253,   253,   242,   196,   171,   172,
       3,     3,   253,   160,   160,   160,     9,     9,   158,   339,
     340,   196,   342,   343,   344,   160,   160,   160,   143,   160,
     157,   160,   160,   196,   160,   160,   160,   160,    33,   157,
     157,   157,    48,    15,   650,   650,    48,   157,   157,    76,
     157,   793,   794,    35,    33,   119,   171,   172,    35,   249,
     860,    20,   109,   273,   254,   157,   866,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   196,    48,    48,    48,   132,    79,    79,    81,    81,
      73,    68,    48,    48,    25,    48,    48,    90,    90,    41,
      48,   421,    35,   802,   390,   391,   154,   709,    25,   154,
      94,   431,    25,   108,   434,    94,   436,   101,   720,   106,
     107,   104,   115,   115,   683,   173,    68,   927,   173,   449,
     930,   195,   159,   613,   157,    68,   115,   126,    69,   121,
     163,   124,   884,   115,   717,   465,   752,   752,   890,   949,
      33,   157,   758,   758,    20,   157,   729,   730,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   972,   493,    15,    20,   496,   977,   388,    93,
      20,   981,   392,    33,    20,   181,   126,   170,   121,    33,
      24,   157,   157,   157,    39,   126,     9,   193,   112,    39,
     877,   157,   157,   523,   157,   157,   526,    52,   528,   157,
      23,    94,    52,   133,   201,   817,   818,   819,   820,    53,
      26,   222,   223,   224,   225,    85,    86,     9,    20,    21,
      75,    76,   115,    26,   154,    75,   166,   167,    83,    33,
      12,    23,    94,    83,    94,   232,    80,    19,    20,   250,
      94,   461,    83,   249,   574,   377,   378,   863,   863,   255,
      26,   867,   867,   115,    26,   115,    79,    39,    81,   114,
      26,   115,    94,    98,   114,   595,   272,   111,    91,   140,
      52,   115,    15,   603,   160,   130,   751,   121,    17,   609,
     130,   611,   612,   115,   119,    20,   616,    79,   159,    81,
      94,   146,   115,    75,   624,   625,   146,   101,   169,    91,
      20,    83,   370,   371,   138,   140,   141,   162,   163,   379,
     380,   140,   162,   163,   534,    94,   140,   141,    20,   160,
      94,   176,   163,   115,   159,    24,   176,   160,   944,   944,
     159,   227,   228,   408,   169,   159,   115,    26,   950,   194,
     169,   115,   238,   239,   194,   169,   393,   178,   130,   396,
     181,   398,   427,   115,   429,   251,    26,   577,   383,   384,
     195,     0,   193,   693,   146,   165,   227,   228,   138,   165,
     700,    48,   702,   137,   704,    31,   596,   238,   239,   110,
     162,   163,   202,   203,   204,   499,   500,   952,   170,   134,
     135,   136,   226,   241,   176,   229,   230,   231,   179,   233,
     234,   235,   236,   237,    42,   366,   367,   368,    43,   243,
     244,   116,   246,    25,    48,    48,    25,   121,   252,   639,
      89,    24,   160,   257,   258,   259,   121,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   199,   200,
      48,   160,    35,    15,    35,   775,   126,    15,   778,    25,
     780,   212,   213,   214,    48,    18,   226,    89,   788,   229,
     230,   231,   160,   233,   234,   235,   236,   237,   160,   115,
     199,   200,   160,   160,   244,   197,   246,    33,   101,   809,
     217,   217,   252,   212,   213,   214,   157,   257,   258,   259,
      24,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,    76,    20,   159,   115,    20,    25,   838,   115,
      20,   108,    76,   108,    76,    76,    76,   177,    25,    89,
      89,   101,    35,    76,    25,    41,    24,    76,   157,    76,
      89,     4,    24,    24,   754,    24,    48,   165,    11,    12,
      26,   159,   159,   873,   260,   875,    19,    20,   248,   240,
     247,    24,   103,   160,    27,   160,    29,    30,    26,   103,
     160,   160,   160,    26,    37,    38,    39,    40,   160,   899,
      26,   901,   792,    46,    48,   108,   108,    25,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   101,   115,    70,    71,   165,
       7,    74,    75,    76,    77,    78,    20,    80,   165,    82,
      83,   159,   157,    25,    47,   219,    47,   159,    33,    92,
     160,    76,    95,    96,   108,    98,    84,    25,   174,    35,
      20,   961,   105,   106,   107,    20,   159,   967,   111,    26,
      24,    35,    25,   245,    32,   256,   119,   156,   121,   174,
     123,    20,   125,   174,    33,    26,   159,   130,    76,   174,
     245,   115,   159,    26,    26,    76,   139,    76,    26,   142,
     143,    93,   160,   146,    93,   148,   149,   418,   337,   152,
     153,    97,   155,    96,   337,   756,   123,   615,   440,   162,
     163,   164,   627,   166,   167,   168,   346,   170,   671,   172,
     695,   343,   175,   176,   690,   693,   604,   180,    69,   651,
     183,   372,   349,   148,   350,   144,   810,   648,   191,   469,
     890,   884,   384,   196,    35,   198,    35,   811,   201,   668,
     535,   729,   205,   206,   207,   208,   209,   210,   211,   429,
     717,   536,     4,   216,   825,   218,   730,   220,   221,    11,
      12,   721,   505,   851,   718,    -1,    -1,    19,    20,   232,
      -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    -1,    80,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,   123,    -1,   125,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,    -1,
     152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,   166,   167,   168,    -1,   170,    -1,
     172,    -1,    -1,   175,   176,    -1,    -1,    -1,   180,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,    -1,     4,   216,    -1,   218,    -1,   220,   221,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
     232,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,
      -1,   152,   153,    -1,   155,    -1,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,   166,   167,   168,    -1,   170,
      -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,   180,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,     4,   216,    -1,   218,    -1,   220,
     221,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,   157,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
     170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,
     180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,    -1,     4,   216,    -1,   218,    -1,
     220,   221,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,
     149,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,
      -1,   160,    -1,   162,   163,   164,    -1,   166,   167,   168,
      -1,   170,    -1,   172,    -1,    -1,   175,   176,    -1,    -1,
      -1,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,    -1,     4,   216,    -1,   218,
      -1,   220,   221,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    -1,    74,    75,    76,    77,
      78,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,
     148,   149,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,
      -1,    -1,   160,    -1,   162,   163,   164,    -1,   166,   167,
     168,    -1,   170,    -1,   172,    -1,    -1,   175,   176,    -1,
      -1,    -1,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,    -1,     4,   216,    -1,
     218,    -1,   220,   221,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    -1,    -1,    -1,    24,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,   142,   143,    -1,    -1,   146,
      -1,   148,   149,    -1,    -1,   152,   153,    -1,   155,    -1,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,   166,
     167,   168,    -1,   170,    -1,   172,    -1,    -1,   175,   176,
      -1,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,    -1,     4,   216,
      -1,   218,    -1,   220,   221,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,    75,
      76,    77,    78,    -1,    80,    -1,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   142,   143,    -1,    -1,
     146,    -1,   148,   149,    -1,    -1,   152,   153,    -1,   155,
      -1,   157,    -1,    -1,    -1,    -1,   162,   163,   164,    -1,
     166,   167,   168,    -1,   170,    -1,   172,    -1,    -1,   175,
     176,    -1,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,    -1,     4,
     216,    -1,   218,    -1,   220,   221,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    24,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    74,
      75,    76,    77,    78,    -1,    80,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,    -1,
      -1,   146,    -1,   148,   149,    -1,    -1,   152,   153,    -1,
     155,    -1,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,   166,   167,   168,    -1,   170,    -1,   172,    -1,    -1,
     175,   176,    -1,    -1,    -1,   180,    -1,    -1,   183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,    -1,
       4,   216,    -1,   218,    -1,   220,   221,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,
      74,    75,    76,    77,    78,    -1,    80,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,   148,   149,    -1,    -1,   152,   153,
      -1,   155,    -1,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,    -1,   166,   167,   168,    -1,   170,    -1,   172,    -1,
      -1,   175,   176,    -1,    -1,    -1,   180,    -1,    -1,   183,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
      -1,     4,   216,    -1,   218,    -1,   220,   221,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,
      -1,    24,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    80,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,
     143,    -1,    -1,   146,    -1,   148,   149,    -1,    -1,   152,
     153,    -1,   155,    -1,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,    -1,   166,   167,   168,    -1,   170,    -1,   172,
      -1,    -1,   175,   176,    -1,    -1,    -1,   180,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,    -1,     4,   216,    -1,   218,    -1,   220,   221,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    -1,    80,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,    -1,
     152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,   166,   167,   168,    -1,   170,    -1,
     172,    -1,    -1,   175,   176,    -1,    -1,    -1,   180,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,    -1,     4,   216,    -1,   218,    -1,   220,   221,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,   166,   167,    -1,    -1,   170,
      -1,   172,    -1,     4,   175,   176,    -1,    -1,    -1,    -1,
      11,    12,   183,    -1,    -1,    -1,    -1,    -1,    19,    20,
     191,    -1,    -1,    24,    -1,   196,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,   166,   167,    -1,    -1,   170,
      -1,   172,     4,    -1,   175,   176,    -1,    -1,    -1,    11,
      12,    -1,   183,    -1,    -1,    -1,    -1,    19,    20,    -1,
     191,    -1,    24,    -1,    -1,   196,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      -1,    -1,    74,    75,    76,    77,    78,    -1,    80,    -1,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,   143,    -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,
     152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,   164,    -1,     4,    -1,    -1,    -1,   170,    -1,
     172,    11,    12,   175,   176,    -1,    -1,    -1,    -1,    19,
      20,   183,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,   196,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    95,    96,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
     117,   121,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
     130,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,    -1,    -1,
      -1,    -1,   152,   153,   151,   155,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
     230,   231,   172,   233,   234,   175,   176,    -1,    -1,    -1,
      -1,    -1,    -1,   183,   244,    -1,   246,    -1,   185,   186,
     187,   188,   189,   190,    -1,    -1,   196,   257,    -1,    -1,
      -1,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,     4,    11,    12,    19,    20,    24,    27,    29,    30,
      37,    38,    39,    40,    46,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    70,    71,    74,    75,    76,    77,    78,    80,
      82,    83,    92,    95,    96,    98,   105,   106,   107,   111,
     119,   121,   123,   125,   130,   139,   142,   143,   146,   148,
     149,   152,   153,   155,   162,   163,   164,   166,   167,   168,
     170,   172,   175,   176,   180,   183,   191,   196,   198,   201,
     205,   206,   207,   208,   209,   210,   211,   216,   218,   220,
     221,   232,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   310,   311,   312,   313,   318,
     319,   320,   321,   322,   323,   324,   329,   347,   350,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   402,   403,   404,   417,   418,   420,   421,   422,
     423,   424,   425,   426,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   445,   446,   447,   448,   449,   450,
     451,   454,   457,   157,   319,   157,   319,   121,   115,   319,
      20,   160,   170,    20,   386,   319,   160,    25,   154,   173,
     154,   173,   133,   154,    25,   126,   126,    85,    86,    20,
      15,    20,   138,   182,    20,    26,   319,   160,   441,   442,
      26,   319,    20,   160,   170,    26,   348,   349,    26,   325,
     326,   319,    25,   126,    25,    69,   126,   309,    26,   330,
     332,   160,   319,    15,   160,   319,    17,    15,    24,   160,
      20,    21,    15,   115,    20,    20,   378,   378,   348,    20,
     319,   160,   319,   319,   319,    28,   197,    24,   202,   203,
     204,   320,   320,   320,   320,   320,   320,   320,    26,   452,
     453,   115,    26,   331,   333,   320,   230,   231,   233,   234,
     244,   246,   257,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   469,   470,   471,   472,   473,   476,
     481,   482,     0,   287,   288,   290,   318,   165,   165,    48,
     140,   141,   159,   169,   195,   323,   334,   335,   340,   137,
      31,    89,    97,   100,   102,   113,   117,   122,   128,   151,
     185,   186,   187,   188,   189,   190,   370,   371,   372,   241,
     123,   148,   178,    73,   104,   124,   170,   181,   193,    93,
     112,   110,   179,    42,    43,   123,   148,   369,   115,   376,
     166,   167,   116,   390,   391,   386,   390,   386,   390,   157,
     157,   160,   320,   401,   319,   157,    48,   160,    48,   160,
     157,    48,    48,    25,    25,   121,    89,    24,   121,    33,
      94,   101,   428,   157,   160,   160,   157,    48,   160,    48,
     160,   108,   428,    48,   161,    35,   108,   253,   327,   328,
     428,    48,   160,    35,    15,    35,   126,    15,    25,   101,
     328,   428,    48,   160,    89,   157,     8,   144,   160,   160,
      18,   115,   319,   160,   160,   161,    20,    87,   174,   406,
     407,   157,   160,   157,   157,   197,    88,   165,   199,   200,
     212,   213,   214,   199,   200,   212,   213,   214,    33,   217,
     217,   101,    48,   215,   320,    48,   221,   157,    24,    93,
     181,   477,   480,    35,   121,   478,    35,    68,   121,   475,
     292,   293,   294,   320,   320,   341,   342,    76,   336,   337,
     320,   341,   320,   159,   335,   340,   159,   340,   159,   355,
     356,   357,   357,   357,   115,   121,   242,   393,   458,   460,
     461,   462,   463,   464,   465,   466,   360,   360,   359,   361,
     361,   361,   361,   362,   362,   363,   363,    20,   114,   194,
     429,   431,   432,   433,   429,   427,   432,   427,   157,   319,
     378,   378,   319,   391,    48,   160,   157,   115,    20,   443,
     443,   109,   132,   109,   132,    76,   160,   314,   315,    25,
     160,   314,   429,   320,    94,   101,   115,    20,   443,   444,
     443,   444,   320,   108,    76,   320,    76,   320,    76,   108,
     328,   108,   108,   327,   328,    76,   177,    25,   308,    89,
     308,    89,    35,   320,   101,   101,   328,    76,    25,   157,
     319,   157,   320,    89,     9,    10,    44,    79,    81,   115,
     171,   316,   403,   405,   415,   416,   419,    87,   174,   407,
      41,   351,   352,    24,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,    76,   320,
     157,    76,   320,   478,   478,   480,    24,    24,   479,   477,
      24,    68,   475,   165,    34,    47,    72,    85,    86,   343,
     344,   345,   346,    48,    26,    48,   329,   334,   339,   320,
     159,   340,   159,   320,   159,   320,   319,   458,   464,   260,
     492,   138,   226,   229,   235,   236,   237,   243,   252,   258,
     259,   459,   467,   468,   469,   483,   486,   487,   489,   240,
     247,   248,   488,   222,   223,   224,   225,   250,   484,   134,
     135,   136,   430,   103,   157,   158,   320,   157,   319,   160,
     160,    26,    33,    94,   115,   317,    48,   160,    33,    94,
     317,   160,   320,   157,   319,   103,   160,   160,   160,   160,
     320,   349,    26,    26,   320,   108,   320,   320,   108,   328,
     108,   326,   320,    48,    25,   308,   320,   320,   101,   332,
     165,   157,   115,    32,   156,   408,     7,   319,    20,   171,
     415,   171,   405,    76,   429,    68,   352,   165,   453,   159,
     219,   455,   456,   333,   157,    24,   160,   227,   228,   238,
     239,   251,   485,    48,   160,    48,   160,    25,   345,   346,
     346,   342,    47,   338,   337,   329,   334,   320,   159,   320,
     320,   157,   160,   361,   249,   254,   491,   485,   461,   491,
     358,   361,   258,   467,   469,   462,   463,   485,   157,   428,
     429,   319,   315,    33,    94,   317,   429,    33,    94,   317,
     157,   320,   320,   108,   320,    84,    25,    35,   320,   157,
     319,     3,    90,   411,   412,   414,   416,    23,    91,   409,
     410,   413,   416,   157,   174,    20,    20,   171,    26,   159,
      76,   159,   320,   387,   456,   361,   361,   361,   361,    24,
     245,   474,   475,   474,   346,    25,   320,   249,   255,   272,
     490,   490,   358,   256,    94,   317,   157,   429,    94,   317,
     429,   320,   320,   308,   157,    32,    90,   414,   156,    91,
     413,   174,   174,    20,    33,   320,    26,   320,    48,   160,
     178,   485,    48,   160,   160,    94,   317,    94,   317,   174,
     429,   159,    76,   317,   361,   245,   475,   159,   320,    26,
     320,    48,   160,    76,   317,    26,    48,   160,    76,   317,
      26,   160,   317
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  xquery_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   284,   285,   285,   285,   285,   286,   286,   287,   287,
     288,   289,   290,   290,   290,   291,   291,   292,   292,   293,
     293,   293,   293,   294,   294,   294,   294,   295,   295,   295,
     295,   295,   295,   295,   295,   296,   296,   297,   298,   298,
     299,   299,   300,   301,   302,   302,   303,   303,   304,   304,
     304,   304,   305,   306,   307,   307,   307,   307,   308,   308,
     309,   309,   310,   310,   310,   310,   311,   311,   311,   311,
     312,   312,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   314,   314,
     315,   315,   316,   317,   318,   319,   319,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   321,
     321,   321,   321,   321,   321,   321,   321,   322,   322,   323,
     323,   324,   325,   325,   326,   326,   326,   326,   326,   326,
     326,   326,   327,   328,   329,   330,   330,   331,   331,   332,
     332,   332,   332,   333,   334,   335,   335,   335,   335,   336,
     336,   337,   337,   338,   339,   339,   340,   340,   341,   341,
     342,   342,   343,   343,   343,   343,   343,   343,   343,   344,
     344,   345,   345,   346,   347,   347,   348,   348,   349,   349,
     350,   350,   351,   351,   352,   352,   353,   354,   354,   355,
     355,   356,   356,   356,   356,   357,   357,   357,   358,   358,
     359,   359,   359,   360,   360,   360,   360,   360,   361,   361,
     361,   362,   362,   362,   363,   363,   364,   364,   365,   365,
     366,   366,   367,   367,   368,   368,   368,   368,   369,   369,
     369,   370,   370,   370,   370,   370,   370,   371,   371,   371,
     371,   371,   371,   372,   372,   372,   373,   373,   374,   374,
     375,   375,   376,   376,   377,   377,   377,   377,   378,   378,
     378,   379,   379,   380,   380,   380,   380,   381,   381,   382,
     382,   382,   382,   382,   382,   382,   383,   383,   384,   384,
     385,   385,   385,   385,   385,   386,   386,   387,   387,   388,
     388,   388,   389,   389,   390,   390,   391,   392,   392,   392,
     392,   392,   392,   392,   392,   393,   393,   394,   394,   394,
     395,   396,   396,   397,   398,   399,   400,   400,   401,   401,
     402,   402,   403,   403,   403,   404,   404,   404,   404,   404,
     404,   405,   405,   406,   406,   407,   408,   408,   409,   409,
     410,   410,   410,   410,   411,   411,   412,   412,   412,   412,
     413,   413,   414,   414,   415,   415,   415,   415,   416,   416,
     416,   416,   417,   417,   418,   418,   419,   420,   420,   420,
     420,   420,   420,   421,   422,   422,   422,   422,   423,   423,
     423,   423,   424,   425,   426,   426,   426,   426,   427,   427,
     428,   429,   429,   429,   430,   430,   430,   431,   431,   431,
     432,   433,   433,   433,   433,   433,   433,   433,   433,   433,
     434,   435,   435,   435,   436,   437,   438,   438,   438,   439,
     439,   439,   439,   439,   440,   441,   441,   441,   441,   441,
     441,   441,   442,   443,   444,   445,   446,   446,   446,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   448,
     448,   449,   449,   450,   451,   452,   452,   453,   454,   455,
     455,   456,   456,   456,   456,   457,   457,   458,   458,   458,
     458,   459,   459,   459,   459,   460,   460,   461,   461,   462,
     462,   463,   463,   464,   464,   464,   465,   465,   466,   466,
     467,   467,   467,   467,   467,   468,   469,   469,   469,   469,
     469,   469,   469,   470,   470,   470,   470,   471,   471,   471,
     471,   472,   472,   473,   473,   473,   473,   473,   473,   473,
     474,   474,   475,   475,   475,   475,   476,   476,   476,   476,
     476,   477,   477,   478,   478,   479,   479,   480,   480,   481,
     482,   482,   483,   483,   483,   484,   484,   484,   484,   484,
     485,   485,   485,   485,   486,   487,   488,   489,   489,   490,
     490,   490,   491,   491,   492
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     3,     5,     2,     1,
       2,     5,     2,     2,     4,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     2,
       3,     3,     3,     2,     2,     2,     2,     2,     4,     4,
       4,     4,     2,     2,     2,     3,     4,     5,     1,     3,
       3,     2,     2,     5,     4,     7,     4,     3,     5,     4,
       2,     2,     5,     5,     6,     6,     7,     7,     8,     8,
       5,     5,     6,     6,     7,     7,     8,     8,     1,     3,
       2,     3,     3,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     5,     4,     5,     5,     6,     1,     2,     1,
       1,     2,     1,     4,     3,     4,     4,     5,     4,     5,
       5,     6,     3,     3,     2,     1,     4,     1,     4,     3,
       4,     4,     5,     1,     2,     2,     3,     3,     4,     1,
       3,     2,     3,     2,     1,     2,     2,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     2,     2,     3,     1,
       1,     1,     1,     2,     4,     4,     1,     4,     3,     4,
       7,     9,     1,     2,     4,     7,     7,     1,     3,     1,
       3,     1,     3,     3,     3,     1,     3,     4,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     4,
       1,     2,     3,     2,     1,     2,     2,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     3,     3,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     3,     4,     6,     7,     7,
       8,     1,     2,     1,     2,     3,     3,     3,     0,     1,
       1,     1,     2,     2,     0,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     5,     6,     2,     3,
       5,     6,     3,     3,     4,     5,     6,     7,     1,     2,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     3,     2,     2,     2,     3,     3,     2,
       3,     5,     3,     5,     3,     2,     3,     5,     5,     3,
       5,     5,     3,     1,     2,     1,     2,     2,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     2,
       2,     4,     4,     4,     6,     1,     4,     3,     5,     1,
       2,     4,     7,    10,    13,     5,     3,     1,     2,     3,
       4,     1,     1,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     2,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     6,     4,     6,     1,
       1,     3,     2,     4,     4,     6,     2,     3,     1,     2,
       1,     1,     2,     2,     3,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     4,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined",
  "\"'apos attribute content'\"", "\"'<attribute QName {>'\"",
  "\"'<at URI>'\"", "\"'char literal'\"", "\"'char literal]]>'\"",
  "\"'char literal and pi end'\"", "\"'#charref;'\"",
  "\"'element content'\"", "\"'<QName {>'\"", "\"'pref:*'\"",
  "\"'&entity;'\"", "\"'comment literal'\"", "\"'NCName'\"",
  "\"'pi <NCName {>'\"", "\"'pi target'\"", "\"'pragma literal and end'\"",
  "\"'*:QName'\"", "\"'QName'\"", "\"'QName #)'\"", "\"'<QName (>'\"",
  "\"'quote attribute content'\"", "\"'STRING'\"", "\"'URI'\"",
  "\"'variable name'\"", "\"'validate mode'\"", "\"'XML comment'\"",
  "\"'ancestor::'\"", "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"",
  "\"'attribute::'\"", "\"'<attribute {>'\"", "\"'<attribute (>'\"",
  "\"'@'\"", "\"'case'\"", "\"'<castable as>'\"", "\"'<cast as>'\"",
  "\"'CDATA[['\"", "\"']]'\"", "\"'child::'\"", "\"'collation'\"",
  "\"','\"", "\"'(:'\"", "\"':)'\"", "\"'<comment {>'\"",
  "\"'<comment (>'\"", "\"'DECIMAL'\"", "\"'<declare base URI>'\"",
  "\"'<declare boundary space>'\"", "\"'<declare construction>'\"",
  "\"'<declare copy namespaces>'\"", "\"'<declare default collation>'\"",
  "\"'<declare default element>'\"", "\"'<declare default function>'\"",
  "\"'<declare default order>'\"", "\"'<declare function>'\"",
  "\"'<declare namespace>'\"", "\"'<declare option>'\"",
  "\"'<declare ordering>'\"", "\"'<declare updating function>'\"",
  "\"'<declare var $>'\"", "\"'default'\"", "\"'<default element>'\"",
  "\"'descendant::'\"", "\"'descendant-or-self::'\"", "\"'descending'\"",
  "\"'div'\"", "\"'<document {>'\"", "\"'<document node (>'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'<element {>'\"", "\"'<element (>'\"", "\"'else'\"",
  "\"'<empty greatest>'\"", "\"'<empty least>'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"",
  "\"'<every $>'\"", "\"'except'\"", "\"'external'\"", "\"'following::'\"",
  "\"'following-sibling::'\"", "\"'follows'\"", "\"'<for $>'\"",
  "\"'general comp'\"", "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"",
  "\"'idiv'\"", "\"'<if (>'\"", "\"'<import module>\"",
  "\"'<import schema>'\"", "\"'in'\"", "\"'inherit'\"",
  "\"'<instance of>'\"", "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"",
  "\"'item()'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'[ / ]'\"",
  "\"'<let $>'\"", "\"'<let score $>'\"", "\"'('\"", "\"'<'\"", "\"'-'\"",
  "\"'mod'\"", "\"'<module namespace>'\"", "\"'namespace'\"", "\"'nan'\"",
  "\"'!='\"", "\"'nodecomp'\"", "\"'<node (>'\"", "\"'?\\?'\"",
  "\"'<no inherit>'\"", "\"'<no preserve>'\"", "\"'occurs ?'\"",
  "\"'occurs +'\"", "\"'occurs *'\"", "\"'or'\"", "\"'ordered'\"",
  "\"'ordered {'\"", "\"'<order by>'\"", "\"'<group by>'\"",
  "\"'parent::'\"", "\"'<?'\"", "\"'?>'\"", "\"'<pi {>'\"", "\"'<pi (>'\"",
  "\"'PI TARGET'\"", "\"'+'\"", "\"'PRAGMA BEGIN'\"", "\"'PRAGMA END'\"",
  "\"'<<'\"", "\"'preceding::'\"", "\"'preceding-sibling::'\"",
  "\"'preserve'\"", "\"'processing instruction'\"", "\"'\\\"'\"",
  "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"", "\"'satisfies'\"",
  "\"'<schema attribute ('\"", "\"'<schema element (>'\"", "\"'self::'\"",
  "\"';'\"", "\"'/'\"", "\"'//'\"", "\"'<some $>'\"",
  "\"'<stable order by>'\"", "\"'*'\"", "\"'start tag end >'\"",
  "\"'start tag <'\"", "\"'strip'\"", "\"'</'\"", "\"'<text {>'\"",
  "\"'<text (>'\"", "\"'then'\"", "\"'to'\"", "\"'<treat as>'\"",
  "\"'<typeswitch (>'\"", "\"'union'\"", "\"'unordered'\"",
  "\"'<unordered (>'\"", "\"'unrecognized'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'<validate {>'\"",
  "\"'VALUECOMP'\"", "\"'|'\"", "\"'void()'\"", "\"'where'\"",
  "\"'<!--'\"", "\"'-->'\"", "\"'<XQuery Version>'\"", "\"'after'\"",
  "\"'before'\"", "\"'<declare revalidation>'\"", "\"'strict'\"",
  "\"'lax'\"", "\"'skip'\"", "\"'<delete node>'\"", "\"'<delete nodes>'\"",
  "\"'<insert node>'\"", "\"'<insert nodes>'\"", "\"'<rename>'\"",
  "\"'<replace node>'\"", "\"'<replace value of node>'\"",
  "\"'<as first into>'\"", "\"'into'\"", "\"'<as last into>'\"",
  "\"'modify'\"", "\"'<copy $>'\"", "\"'with'\"", "\"'<try>'\"",
  "\"'<catch (>'\"", "\"'<using $>'\"", "\"'<eval {>'\"", "\"'all'\"",
  "\"'<all words>'\"", "\"'any'\"", "\"'<any words>'\"", "\"'<at end>'\"",
  "\"'<at least>'\"", "\"'<at most>'\"", "\"'<at start>'\"",
  "\"'<case insensitive>'\"", "\"'<casesensitive>'\"",
  "\"'<declare ftoption>'\"", "\"'<diacritics insensitive>'\"",
  "\"'<diacritics sensitive>'\"", "\"'different'\"", "\"'distance'\"",
  "\"'<entire content>'\"", "\"'exactly'\"", "\"'from'\"", "\"'&&'\"",
  "\"'ftcontains'\"", "\"'ftnot'\"", "\"'||'\"", "\"'language'\"",
  "\"'levels'\"", "\"'lowercase'\"", "\"'<not in>'\"", "\"'occurs'\"",
  "\"'paragraph'\"", "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"",
  "\"'score'\"", "\"'sentence'\"", "\"'sentences'\"", "\"'times'\"",
  "\"'uppercase'\"", "\"'weight'\"", "\"'window'\"",
  "\"'<without content>'\"", "\"'<without diacritics>'\"",
  "\"'<without stemming>'\"", "\"'<without stop words>'\"",
  "\"'<without thesaurus>'\"", "\"'<without wildcards>'\"",
  "\"'<with default stop words>'\"", "\"'<with diacritics>'\"",
  "\"'<with stemming>'\"", "\"'<with stop words>'\"",
  "\"'<with thesaurus>'\"", "\"'<with wildcards>'\"", "\"'words'\"",
  "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "STEP_REDUCE", "$accept", "Module",
  "VersionDecl", "MainModule", "LibraryModule", "ModuleDecl", "Prolog",
  "SIND_DeclList", "VFO_DeclList", "SIND_Decl", "VFO_Decl", "Setter",
  "Import", "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "VarDecl", "ConstructionDecl", "FunctionDecl", "ParamList", "Param",
  "EnclosedExpr", "NonNodeEnclosedExpr", "QueryBody", "Expr", "ExprSingle",
  "FLWORExpr", "ForLetClauseList", "ForLetClause", "ForClause",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl", "EvalVarDecl",
  "WhereClause", "GroupByClause", "GroupSpecList", "GroupSpec",
  "GroupCollationSpec", "LetClauseList", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "TypeswitchExpr", "CaseClauseList", "CaseClause", "IfExpr", "OrExpr",
  "AndExpr", "ComparisonExpr", "FTContainsExpr", "RangeExpr",
  "AdditiveExpr", "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "UnaryExpr",
  "SignList", "ValueExpr", "GeneralComp", "ValueComp", "NodeComp",
  "ValidateExpr", "ExtensionExpr", "PragmaList", "Pragma", "PathExpr",
  "RelativePathExpr", "StepExpr", "AxisStep", "ForwardStep", "ForwardAxis",
  "AbbrevForwardStep", "ReverseStep", "ReverseAxis", "NodeTest",
  "NameTest", "Wildcard", "FilterExpr", "PredicateList", "Predicate",
  "PrimaryExpr", "Literal", "NumericLiteral", "VarRef",
  "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr", "UnorderedExpr",
  "FunctionCall", "ArgList", "Constructor", "DirectConstructor",
  "DirElemConstructor", "DirElemContentList", "DirAttributeList",
  "DirAttr", "DirAttributeValue", "Opt_QuoteAttrContentList",
  "QuoteAttrContentList", "Opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor", "SingleType",
  "TypeDeclaration", "SequenceType", "OccurrenceIndicator", "ItemType",
  "AtomicType", "KindTest", "AnyKindTest", "DocumentTest", "TextTest",
  "CommentTest", "PITest", "AttributeTest", "SchemaAttributeTest",
  "ElementTest", "SchemaElementTest", "TypeName", "TypeName_WITH_HOOK",
  "StringLiteral", "RevalidationDecl", "InsertExpr", "DeleteExpr",
  "ReplaceExpr", "RenameExpr", "TransformExpr", "VarNameList",
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "EvalExpr",
  "FTSelection", "FTMatchOptionProximityList", "FTOr", "FTAnd",
  "FTMildnot", "FTUnaryNot", "FTWordsSelection", "FTWords", "FTWordsValue",
  "FTProximity", "FTOrderedIndicator", "FTMatchOption", "FTCaseOption",
  "FTDiacriticsOption", "FTStemOption", "FTThesaurusOption",
  "FTThesaurusList", "FTThesaurusID", "FTStopwordOption",
  "FTInclExclStringLiteralList", "FTRefOrList", "FTStringLiteralList",
  "FTInclExclStringLiteral", "FTLanguageOption", "FTWildcardOption",
  "FTContent", "FTAnyallOption", "FTRange", "FTDistance", "FTWindow",
  "FTTimes", "FTScope", "FTUnit", "FTBigUnit", "FTIgnoreOption", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       285,     0,    -1,   287,    -1,   286,   287,    -1,   288,    -1,
     286,   288,    -1,   198,    24,   165,    -1,   198,    24,    88,
      24,   165,    -1,   290,   318,    -1,   318,    -1,   289,   290,
      -1,   125,    15,    89,    25,   165,    -1,   291,   165,    -1,
     292,   165,    -1,   291,   165,   292,   165,    -1,   293,    -1,
     291,   165,   293,    -1,   294,    -1,   292,   165,   294,    -1,
     295,    -1,   296,    -1,   297,    -1,   299,    -1,   311,    -1,
     313,    -1,   300,    -1,   301,    -1,   298,    -1,   305,    -1,
     306,    -1,   312,    -1,   302,    -1,   303,    -1,   304,    -1,
     446,    -1,   307,    -1,   310,    -1,    63,    15,    89,    25,
      -1,    55,   154,    -1,    55,   173,    -1,    59,   126,    25,
      -1,    60,   126,    25,    -1,    64,    20,    24,    -1,   232,
     469,    -1,    65,   138,    -1,    65,   182,    -1,    61,    85,
      -1,    61,    86,    -1,    57,   154,    48,   109,    -1,    57,
     154,    48,   132,    -1,    57,   133,    48,   109,    -1,    57,
     133,    48,   132,    -1,    58,    25,    -1,    54,    25,    -1,
     107,    25,    -1,   107,   309,    25,    -1,   107,    25,    35,
     308,    -1,   107,   309,    25,    35,   308,    -1,    25,    -1,
     308,    48,    25,    -1,   126,    15,    89,    -1,    69,   126,
      -1,   106,    25,    -1,   106,   126,    15,    89,    25,    -1,
     106,    25,    35,   308,    -1,   106,   126,    15,    89,    25,
      35,   308,    -1,    67,    26,   101,   320,    -1,    67,    26,
      94,    -1,    67,    26,   428,   101,   320,    -1,    67,    26,
     428,    94,    -1,    56,   154,    -1,    56,   173,    -1,    62,
      20,   121,   160,    94,    -1,    62,    20,   121,   160,   317,
      -1,    62,    20,   121,   314,   160,    94,    -1,    62,    20,
     121,   314,   160,   317,    -1,    62,    20,   121,   160,    33,
     429,    94,    -1,    62,    20,   121,   160,    33,   429,   317,
      -1,    62,    20,   121,   314,   160,    33,   429,    94,    -1,
      62,    20,   121,   314,   160,    33,   429,   317,    -1,    66,
      20,   121,   160,    94,    -1,    66,    20,   121,   160,   317,
      -1,    66,    20,   121,   314,   160,    94,    -1,    66,    20,
     121,   314,   160,   317,    -1,    66,    20,   121,   160,    33,
     429,    94,    -1,    66,    20,   121,   160,    33,   429,   317,
      -1,    66,    20,   121,   314,   160,    33,   429,    94,    -1,
      66,    20,   121,   314,   160,    33,   429,   317,    -1,   315,
      -1,   314,    48,   315,    -1,    76,    26,    -1,    76,    26,
     428,    -1,   115,   319,   157,    -1,   115,   319,   157,    -1,
     319,    -1,   320,    -1,   319,    48,   320,    -1,   321,    -1,
     347,    -1,   350,    -1,   353,    -1,   354,    -1,   447,    -1,
     448,    -1,   450,    -1,   449,    -1,   451,    -1,   454,    -1,
     457,    -1,   322,   159,   320,    -1,   322,   334,   159,   320,
      -1,   322,   340,   159,   320,    -1,   322,   334,   340,   159,
     320,    -1,   322,   335,   159,   320,    -1,   322,   334,   335,
     159,   320,    -1,   322,   335,   340,   159,   320,    -1,   322,
     334,   335,   340,   159,   320,    -1,   323,    -1,   322,   323,
      -1,   324,    -1,   329,    -1,    98,   325,    -1,   326,    -1,
     325,    48,    76,   326,    -1,    26,   108,   320,    -1,    26,
     428,   108,   320,    -1,    26,   327,   108,   320,    -1,    26,
     428,   327,   108,   320,    -1,    26,   328,   108,   320,    -1,
      26,   428,   328,   108,   320,    -1,    26,   327,   328,   108,
     320,    -1,    26,   428,   327,   328,   108,   320,    -1,    35,
      76,    26,    -1,   253,    76,    26,    -1,   119,   330,    -1,
     332,    -1,   330,    48,    76,   332,    -1,   333,    -1,   331,
      48,    76,   333,    -1,    26,   101,   320,    -1,    26,   428,
     101,   320,    -1,    26,   328,   101,   320,    -1,    26,   428,
     328,   101,   320,    -1,    26,    -1,   195,   320,    -1,   141,
     336,    -1,   141,   336,   339,    -1,   141,   336,   334,    -1,
     141,   336,   339,   334,    -1,   337,    -1,   336,    48,   337,
      -1,    76,    26,    -1,    76,    26,   338,    -1,    47,    25,
      -1,   329,    -1,   339,   329,    -1,   140,   341,    -1,   169,
     341,    -1,   342,    -1,   341,    48,   342,    -1,   320,    -1,
     320,   343,    -1,   344,    -1,   345,    -1,   346,    -1,   344,
     345,    -1,   344,   346,    -1,   345,   346,    -1,   344,   345,
     346,    -1,    34,    -1,    72,    -1,    85,    -1,    86,    -1,
      47,    25,    -1,   168,   348,   161,   320,    -1,    92,   348,
     161,   320,    -1,   349,    -1,   348,    48,    76,   349,    -1,
      26,   108,   320,    -1,    26,   428,   108,   320,    -1,   180,
     319,   160,   351,    68,   159,   320,    -1,   180,   319,   160,
     351,    68,    76,    26,   159,   320,    -1,   352,    -1,   351,
     352,    -1,    41,   429,   159,   320,    -1,    41,    76,    26,
      33,   429,   159,   320,    -1,   105,   319,   160,   177,   320,
      84,   320,    -1,   355,    -1,   354,   137,   355,    -1,   356,
      -1,   355,    31,   356,    -1,   357,    -1,   357,   371,   357,
      -1,   357,   370,   357,    -1,   357,   372,   357,    -1,   358,
      -1,   358,   241,   458,    -1,   358,   241,   458,   492,    -1,
     359,    -1,   359,   178,   359,    -1,   360,    -1,   359,   148,
     360,    -1,   359,   123,   360,    -1,   361,    -1,   360,   170,
     361,    -1,   360,    73,   361,    -1,   360,   104,   361,    -1,
     360,   124,   361,    -1,   362,    -1,   361,   181,   362,    -1,
     361,   193,   362,    -1,   363,    -1,   362,   112,   363,    -1,
     362,    93,   363,    -1,   364,    -1,   364,   110,   429,    -1,
     365,    -1,   365,   179,   429,    -1,   366,    -1,   366,    42,
     427,    -1,   367,    -1,   367,    43,   427,    -1,   369,    -1,
     368,   369,    -1,   148,    -1,   123,    -1,   368,   148,    -1,
     368,   123,    -1,   373,    -1,   377,    -1,   374,    -1,    89,
      -1,   128,    -1,   122,    -1,   117,    -1,   102,    -1,   100,
      -1,   185,    -1,   190,    -1,   189,    -1,   188,    -1,   187,
      -1,   186,    -1,   113,    -1,   151,    -1,    97,    -1,   191,
     319,   157,    -1,    27,   115,   319,   157,    -1,   375,   115,
     157,    -1,   375,   115,   319,   157,    -1,   376,    -1,   375,
     376,    -1,   149,    20,    18,    -1,   149,    21,    -1,   166,
      -1,   166,   378,    -1,   167,   378,    -1,   378,    -1,   379,
      -1,   379,   166,   378,    -1,   379,   167,   378,    -1,   380,
      -1,   389,    -1,   381,    -1,   381,   390,    -1,   384,    -1,
     384,   390,    -1,   382,   386,    -1,   383,    -1,    46,    -1,
      70,    -1,    37,    -1,   164,    -1,    71,    -1,    96,    -1,
      95,    -1,   386,    -1,    40,   386,    -1,   385,   386,    -1,
      78,    -1,   142,    -1,    29,    -1,   153,    -1,   152,    -1,
      30,    -1,   433,    -1,   387,    -1,    20,    -1,   388,    -1,
     170,    -1,    12,    -1,    19,    -1,   392,    -1,   392,   390,
      -1,   391,    -1,   390,   391,    -1,   116,   319,   158,    -1,
     393,    -1,   395,    -1,   396,    -1,   397,    -1,   400,    -1,
     402,    -1,   398,    -1,   399,    -1,   394,    -1,   445,    -1,
      53,    -1,   111,    -1,    80,    -1,    76,    26,    -1,   121,
     160,    -1,   121,   319,   160,    -1,    77,    -1,   139,   319,
     157,    -1,   183,   319,   157,    -1,    20,   121,   160,    -1,
      20,   121,   401,   160,    -1,   320,    -1,   401,    48,   320,
      -1,   403,    -1,   420,    -1,   404,    -1,   417,    -1,   418,
      -1,   172,    20,    87,    -1,   172,    20,   406,    87,    -1,
     172,    20,   174,   171,    20,   174,    -1,   172,    20,   174,
     405,   171,    20,   174,    -1,   172,    20,   406,   174,   171,
      20,   174,    -1,   172,    20,   406,   174,   405,   171,    20,
     174,    -1,   415,    -1,   405,   415,    -1,   407,    -1,   406,
     407,    -1,    20,    89,   408,    -1,   156,   409,   156,    -1,
      32,   411,    32,    -1,    -1,   410,    -1,    91,    -1,   413,
      -1,   410,    91,    -1,   410,   413,    -1,    -1,   412,    -1,
      90,    -1,   414,    -1,   412,    90,    -1,   412,   414,    -1,
      23,    -1,   416,    -1,     3,    -1,   416,    -1,   403,    -1,
      10,    -1,   419,    -1,   416,    -1,     9,    -1,    79,    -1,
      81,    -1,   316,    -1,   196,    28,   197,    -1,   196,   197,
      -1,   143,    17,   144,    -1,   143,    17,     8,    -1,    44,
       7,    -1,   421,    -1,   422,    -1,   423,    -1,   424,    -1,
     425,    -1,   426,    -1,    74,   319,   157,    -1,    11,   157,
      -1,    11,   319,   157,    -1,    82,   319,   157,   115,   157,
      -1,    82,   319,   157,   115,   319,   157,    -1,     4,   157,
      -1,     4,   319,   157,    -1,    38,   319,   157,   115,   157,
      -1,    38,   319,   157,   115,   319,   157,    -1,   175,   319,
     157,    -1,    51,   319,   157,    -1,   155,    15,   115,   157,
      -1,   155,    15,   115,   319,   157,    -1,   155,   115,   319,
     157,   115,   157,    -1,   155,   115,   319,   157,   115,   319,
     157,    -1,   432,    -1,   432,   103,    -1,    33,   429,    -1,
     431,    -1,   431,   430,    -1,   194,    -1,   134,    -1,   136,
      -1,   135,    -1,   432,    -1,   433,    -1,   114,    -1,    20,
      -1,   435,    -1,   441,    -1,   439,    -1,   442,    -1,   440,
      -1,   438,    -1,   437,    -1,   436,    -1,   434,    -1,   130,
     160,    -1,    75,   160,    -1,    75,   441,   160,    -1,    75,
     442,   160,    -1,   176,   160,    -1,    52,   160,    -1,   146,
     160,    -1,   146,    15,   160,    -1,   146,    24,   160,    -1,
      39,   160,    -1,    39,    20,   160,    -1,    39,    20,    48,
     443,   160,    -1,    39,   170,   160,    -1,    39,   170,    48,
     443,   160,    -1,   162,    20,   160,    -1,    83,   160,    -1,
      83,    20,   160,    -1,    83,    20,    48,   443,   160,    -1,
      83,    20,    48,   444,   160,    -1,    83,   170,   160,    -1,
      83,   170,    48,   443,   160,    -1,    83,   170,    48,   444,
     160,    -1,   163,    20,   160,    -1,    20,    -1,    20,   103,
      -1,    24,    -1,   201,   202,    -1,   201,   203,    -1,   201,
     204,    -1,   207,   320,   213,   320,    -1,   207,   320,   212,
     320,    -1,   207,   320,   214,   320,    -1,   207,   320,   199,
     320,    -1,   207,   320,   200,   320,    -1,   208,   320,   213,
     320,    -1,   208,   320,   212,   320,    -1,   208,   320,   214,
     320,    -1,   208,   320,   199,   320,    -1,   208,   320,   200,
     320,    -1,   205,   320,    -1,   206,   320,    -1,   210,   320,
     217,   320,    -1,   211,   320,   217,   320,    -1,   209,   320,
      33,   320,    -1,   216,   452,   215,   320,   159,   320,    -1,
     453,    -1,   452,    48,    76,   453,    -1,    26,   101,   320,
      -1,   218,   115,   320,   157,   455,    -1,   456,    -1,   455,
     456,    -1,   219,   387,   160,   317,    -1,   219,   387,    48,
      76,    26,   160,   317,    -1,   219,   387,    48,    76,    26,
      48,    76,    26,   160,   317,    -1,   219,   387,    48,    76,
      26,    48,    76,    26,    48,    76,    26,   160,   317,    -1,
     220,   331,   221,   320,   157,    -1,   221,   320,   157,    -1,
     460,    -1,   460,   459,    -1,   460,   258,   358,    -1,   460,
     459,   258,   358,    -1,   469,    -1,   467,    -1,   459,   469,
      -1,   459,   467,    -1,   461,    -1,   460,   243,   461,    -1,
     462,    -1,   461,   240,   462,    -1,   463,    -1,   462,   247,
     463,    -1,   464,    -1,   242,   464,    -1,   465,    -1,   465,
     488,    -1,   121,   458,   160,    -1,   466,    -1,   466,   484,
      -1,   393,    -1,   115,   319,   157,    -1,   468,    -1,   487,
      -1,   486,    -1,   489,    -1,   483,    -1,   138,    -1,   470,
      -1,   471,    -1,   472,    -1,   473,    -1,   476,    -1,   481,
      -1,   482,    -1,   246,    -1,   257,    -1,   231,    -1,   230,
      -1,   267,    -1,   261,    -1,   234,    -1,   233,    -1,   268,
      -1,   262,    -1,   270,   475,    -1,   270,    68,    -1,   270,
     121,   475,   160,    -1,   270,   121,   475,    48,   474,   160,
      -1,   270,   121,    68,   160,    -1,   270,   121,    68,    48,
     474,   160,    -1,   264,    -1,   475,    -1,   474,    48,   475,
      -1,    35,    24,    -1,    35,    24,   251,    24,    -1,    35,
      24,   485,   245,    -1,    35,    24,   251,    24,   485,   245,
      -1,   269,   478,    -1,   269,   478,   477,    -1,   266,    -1,
     266,   477,    -1,   263,    -1,   480,    -1,   477,   480,    -1,
      35,    24,    -1,   121,   479,   160,    -1,    24,    -1,   479,
      24,    -1,   181,   478,    -1,    93,   478,    -1,   244,    24,
      -1,   271,    -1,   265,    -1,   229,    -1,   226,    -1,   237,
      -1,   224,    -1,   225,    -1,   222,    -1,   223,    -1,   250,
      -1,   238,   361,    -1,   227,   361,    -1,   228,   361,    -1,
     239,   361,   178,   361,    -1,   236,   485,   490,    -1,   259,
     361,   490,    -1,   248,   485,   256,    -1,   252,   491,    -1,
     235,   491,    -1,   272,    -1,   255,    -1,   249,    -1,   254,
      -1,   249,    -1,   260,   361,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    17,    23,    26,
      28,    31,    37,    40,    43,    48,    50,    54,    56,    60,
      62,    64,    66,    68,    70,    72,    74,    76,    78,    80,
      82,    84,    86,    88,    90,    92,    94,    96,   101,   104,
     107,   111,   115,   119,   122,   125,   128,   131,   134,   139,
     144,   149,   154,   157,   160,   163,   167,   172,   178,   180,
     184,   188,   191,   194,   200,   205,   213,   218,   222,   228,
     233,   236,   239,   245,   251,   258,   265,   273,   281,   290,
     299,   305,   311,   318,   325,   333,   341,   350,   359,   361,
     365,   368,   372,   376,   380,   382,   384,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,   412,
     416,   421,   426,   432,   437,   443,   449,   456,   458,   461,
     463,   465,   468,   470,   475,   479,   484,   489,   495,   500,
     506,   512,   519,   523,   527,   530,   532,   537,   539,   544,
     548,   553,   558,   564,   566,   569,   572,   576,   580,   585,
     587,   591,   594,   598,   601,   603,   606,   609,   612,   614,
     618,   620,   623,   625,   627,   629,   632,   635,   638,   642,
     644,   646,   648,   650,   653,   658,   663,   665,   670,   674,
     679,   687,   697,   699,   702,   707,   715,   723,   725,   729,
     731,   735,   737,   741,   745,   749,   751,   755,   760,   762,
     766,   768,   772,   776,   778,   782,   786,   790,   794,   796,
     800,   804,   806,   810,   814,   816,   820,   822,   826,   828,
     832,   834,   838,   840,   843,   845,   847,   850,   853,   855,
     857,   859,   861,   863,   865,   867,   869,   871,   873,   875,
     877,   879,   881,   883,   885,   887,   889,   893,   898,   902,
     907,   909,   912,   916,   919,   921,   924,   927,   929,   931,
     935,   939,   941,   943,   945,   948,   950,   953,   956,   958,
     960,   962,   964,   966,   968,   970,   972,   974,   977,   980,
     982,   984,   986,   988,   990,   992,   994,   996,   998,  1000,
    1002,  1004,  1006,  1008,  1011,  1013,  1016,  1020,  1022,  1024,
    1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,  1042,  1044,
    1046,  1049,  1052,  1056,  1058,  1062,  1066,  1070,  1075,  1077,
    1081,  1083,  1085,  1087,  1089,  1091,  1095,  1100,  1107,  1115,
    1123,  1132,  1134,  1137,  1139,  1142,  1146,  1150,  1154,  1155,
    1157,  1159,  1161,  1164,  1167,  1168,  1170,  1172,  1174,  1177,
    1180,  1182,  1184,  1186,  1188,  1190,  1192,  1194,  1196,  1198,
    1200,  1202,  1204,  1208,  1211,  1215,  1219,  1222,  1224,  1226,
    1228,  1230,  1232,  1234,  1238,  1241,  1245,  1251,  1258,  1261,
    1265,  1271,  1278,  1282,  1286,  1291,  1297,  1304,  1312,  1314,
    1317,  1320,  1322,  1325,  1327,  1329,  1331,  1333,  1335,  1337,
    1339,  1341,  1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,
    1359,  1362,  1365,  1369,  1373,  1376,  1379,  1382,  1386,  1390,
    1393,  1397,  1403,  1407,  1413,  1417,  1420,  1424,  1430,  1436,
    1440,  1446,  1452,  1456,  1458,  1461,  1463,  1466,  1469,  1472,
    1477,  1482,  1487,  1492,  1497,  1502,  1507,  1512,  1517,  1522,
    1525,  1528,  1533,  1538,  1543,  1550,  1552,  1557,  1561,  1567,
    1569,  1572,  1577,  1585,  1596,  1610,  1616,  1620,  1622,  1625,
    1629,  1634,  1636,  1638,  1641,  1644,  1646,  1650,  1652,  1656,
    1658,  1662,  1664,  1667,  1669,  1672,  1676,  1678,  1681,  1683,
    1687,  1689,  1691,  1693,  1695,  1697,  1699,  1701,  1703,  1705,
    1707,  1709,  1711,  1713,  1715,  1717,  1719,  1721,  1723,  1725,
    1727,  1729,  1731,  1733,  1736,  1739,  1744,  1751,  1756,  1763,
    1765,  1767,  1771,  1774,  1779,  1784,  1791,  1794,  1798,  1800,
    1803,  1805,  1807,  1810,  1813,  1817,  1819,  1822,  1825,  1828,
    1831,  1833,  1835,  1837,  1839,  1841,  1843,  1845,  1847,  1849,
    1851,  1854,  1857,  1860,  1865,  1869,  1873,  1877,  1880,  1883,
    1885,  1887,  1889,  1891,  1893
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   773,   773,   778,   784,   789,   801,   806,   816,   823,
     835,   847,   859,   865,   871,   883,   889,   903,   909,   923,
     927,   931,   935,   944,   948,   952,   958,   968,   972,   976,
     980,   984,   988,   992,   998,  1008,  1012,  1027,  1039,  1044,
    1055,  1061,  1073,  1086,  1097,  1102,  1114,  1119,  1130,  1136,
    1142,  1148,  1167,  1178,  1189,  1196,  1203,  1210,  1223,  1229,
    1244,  1248,  1258,  1264,  1271,  1277,  1291,  1298,  1305,  1312,
    1325,  1330,  1341,  1348,  1356,  1364,  1373,  1382,  1391,  1400,
    1409,  1416,  1424,  1432,  1441,  1450,  1459,  1468,  1483,  1491,
    1505,  1511,  1523,  1531,  1542,  1553,  1559,  1571,  1575,  1579,
    1583,  1587,  1593,  1597,  1601,  1605,  1609,  1613,  1617,  1627,
    1634,  1642,  1650,  1659,  1671,  1683,  1695,  1713,  1719,  1731,
    1735,  1745,  1756,  1762,  1776,  1783,  1791,  1800,  1810,  1818,
    1827,  1836,  1851,  1863,  1874,  1886,  1892,  1904,  1910,  1924,
    1932,  1941,  1949,  1961,  1976,  1984,  1991,  1998,  2005,  2015,
    2021,  2032,  2038,  2047,  2054,  2061,  2073,  2078,  2090,  2096,
    2110,  2116,  2128,  2135,  2142,  2149,  2156,  2163,  2170,  2183,
    2187,  2197,  2202,  2213,  2224,  2231,  2244,  2251,  2263,  2269,
    2282,  2289,  2303,  2309,  2321,  2327,  2340,  2351,  2355,  2366,
    2370,  2389,  2393,  2401,  2409,  2423,  2427,  2434,  2447,  2451,
    2462,  2466,  2470,  2480,  2484,  2488,  2492,  2496,  2506,  2510,
    2515,  2526,  2530,  2534,  2544,  2548,  2560,  2564,  2576,  2580,
    2592,  2596,  2608,  2612,  2624,  2628,  2632,  2636,  2648,  2652,
    2656,  2667,  2671,  2675,  2679,  2683,  2687,  2697,  2701,  2705,
    2709,  2713,  2717,  2727,  2731,  2735,  2746,  2750,  2762,  2768,
    2780,  2786,  2800,  2806,  2848,  2852,  2856,  2860,  2873,  2884,
    2889,  2899,  2903,  2913,  2919,  2925,  2931,  2943,  2949,  2960,
    2964,  2968,  2972,  2976,  2980,  2984,  2994,  2998,  3008,  3014,
    3026,  3030,  3034,  3038,  3042,  3057,  3061,  3071,  3075,  3085,
    3092,  3099,  3112,  3116,  3128,  3134,  3148,  3159,  3163,  3167,
    3171,  3175,  3179,  3183,  3187,  3197,  3201,  3211,  3216,  3221,
    3232,  3242,  3246,  3257,  3267,  3278,  3334,  3340,  3352,  3358,
    3370,  3374,  3384,  3388,  3392,  3402,  3410,  3418,  3426,  3434,
    3442,  3457,  3463,  3475,  3481,  3495,  3507,  3512,  3524,  3527,
    3534,  3540,  3546,  3554,  3569,  3572,  3579,  3585,  3591,  3599,
    3613,  3618,  3629,  3634,  3645,  3650,  3655,  3661,  3673,  3679,
    3684,  3689,  3700,  3705,  3720,  3725,  3742,  3757,  3761,  3765,
    3769,  3773,  3777,  3787,  3798,  3804,  3810,  3815,  3837,  3843,
    3849,  3854,  3865,  3876,  3887,  3893,  3899,  3904,  3915,  3921,
    3933,  3944,  3950,  3956,  3993,  3998,  4003,  4014,  4018,  4022,
    4032,  4043,  4047,  4051,  4055,  4059,  4063,  4067,  4071,  4075,
    4085,  4095,  4099,  4104,  4115,  4125,  4135,  4139,  4143,  4153,
    4159,  4165,  4171,  4177,  4189,  4200,  4206,  4212,  4218,  4224,
    4231,  4238,  4251,  4272,  4279,  4299,  4339,  4344,  4347,  4355,
    4361,  4367,  4373,  4379,  4386,  4392,  4398,  4404,  4410,  4422,
    4427,  4437,  4443,  4455,  4481,  4492,  4498,  4511,  4525,  4532,
    4539,  4550,  4557,  4565,  4574,  4593,  4599,  4616,  4619,  4622,
    4625,  4634,  4637,  4640,  4643,  4652,  4655,  4664,  4667,  4676,
    4679,  4688,  4691,  4700,  4703,  4706,  4715,  4718,  4727,  4730,
    4739,  4742,  4745,  4748,  4751,  4760,  4769,  4773,  4777,  4781,
    4785,  4789,  4793,  4803,  4806,  4809,  4812,  4821,  4824,  4827,
    4830,  4839,  4842,  4851,  4854,  4857,  4860,  4863,  4866,  4869,
    4878,  4881,  4890,  4893,  4896,  4899,  4908,  4911,  4914,  4917,
    4920,  4929,  4932,  4941,  4944,  4953,  4956,  4965,  4968,  4977,
    4986,  4989,  4998,  5001,  5004,  5013,  5016,  5019,  5022,  5025,
    5034,  5038,  5042,  5046,  5056,  5065,  5074,  5083,  5086,  5095,
    5098,  5101,  5110,  5113,  5122
  };

  // Print the state stack on the debug stream.
  void
  xquery_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  xquery_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "), ";
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  xquery_parser::token_number_type
  xquery_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 4021;
  const int xquery_parser::yynnts_ = 209;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 332;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 284;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 538;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 5129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"



/*
	The error member function registers the errors to the driver.
*/

void zorba::xquery_parser::error(
	zorba::xquery_parser::location_type const& loc,
	std::string const& msg)
{
  driver.error(loc, msg);
}


#if 0
static void print_token_value(FILE *file, int type, YYSTYPE value)
{
	if (type==VAR) {
		fprintf (file, "%s", value.tptr->name);
	}
	else if (type==NUM) {
		fprintf (file, "%d", value.val);
	}
}
#endif

