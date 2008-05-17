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
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 782 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]" << endl;
#endif
		;}
    break;

  case 4:
#line 791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 5:
#line 798 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		;}
    break;

  case 6:
#line 812 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), encoding);
		;}
    break;

  case 7:
#line 820 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (2)].sval)), SYMTAB ((yysemantic_stack_[(5) - (4)].sval)));
    ;}
    break;

  case 8:
#line 833 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [prolog.querybody]" << endl;
#endif
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)));
		;}
    break;

  case 9:
#line 843 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [querybody]" << endl;
#endif
			(yyval.node) = new MainModule(LOC ((yyloc)),
								NULL,
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 10:
#line 858 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LibraryModule [ ]" << endl;
#endif
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 11:
#line 873 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleDecl [ ]" << endl;
#endif
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)), 
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (4)].sval)));
		;}
    break;

  case 12:
#line 888 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind]" << endl;
#endif
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		;}
    break;

  case 13:
#line 897 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [vfo]" << endl;
#endif
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		;}
    break;

  case 14:
#line 906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind.vfo]" << endl;
#endif
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 15:
#line 921 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [single]" << endl;
#endif
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		;}
    break;

  case 16:
#line 930 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [list]" << endl;
#endif
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 17:
#line 947 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [single]" << endl;
#endif
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		;}
    break;

  case 18:
#line 956 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [list]" << endl;
#endif
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 19:
#line 973 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 987 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 994 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 1006 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 1013 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 1020 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 1029 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 1042 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1049 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1056 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1063 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1070 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1077 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1084 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1093 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1106 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1113 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1131 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NamespaceDecl [ ]" << endl;
#endif
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (4)].sval)));
		;}
    break;

  case 38:
#line 1146 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1154 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1168 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [element]" << endl;
#endif
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 41:
#line 1177 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [function]" << endl;
#endif
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 42:
#line 1192 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OptionDecl [ ]" << endl;
#endif
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 43:
#line 1208 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1222 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1230 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1245 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1253 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1267 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 49:
#line 1276 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 50:
#line 1285 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		;}
    break;

  case 51:
#line 1294 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]" << endl;
#endif
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		;}
    break;

  case 52:
#line 1316 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1330 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1344 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri]" << endl;
#endif
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 55:
#line 1354 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri]" << endl;
#endif
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(3) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		;}
    break;

  case 56:
#line 1364 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri.urilist]" << endl;
#endif
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 57:
#line 1374 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri.aturi]" << endl;
#endif
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(5) - (2)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		;}
    break;

  case 58:
#line 1390 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [single]" << endl;
#endif
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		;}
    break;

  case 59:
#line 1399 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [list]" << endl;
#endif
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 60:
#line 1417 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1437 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri]" << endl;
#endif
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 63:
#line 1446 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri]" << endl;
#endif
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (5)].sval)),
								NULL);
		;}
    break;

  case 64:
#line 1456 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri.at_uri.list]" << endl;
#endif
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 65:
#line 1465 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri.at_uri.list]" << endl;
#endif
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(7) - (7)].node)));
		;}
    break;

  case 66:
#line 1482 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [expr]" << endl;
#endif
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 67:
#line 1492 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [external]" << endl;
#endif
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								NULL,
								NULL);
		;}
    break;

  case 68:
#line 1502 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.expr]" << endl;
#endif
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 69:
#line 1512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.external]" << endl;
#endif
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (3)].node)),
								NULL);
		;}
    break;

  case 70:
#line 1528 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1536 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1550 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 73:
#line 1560 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 74:
#line 1571 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 75:
#line 1582 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 76:
#line 1594 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 77:
#line 1606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								(yysemantic_stack_[(7) - (7)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 78:
#line 1618 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								NULL,
								ParseConstants::fn_extern);
		;}
    break;

  case 79:
#line 1630 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								(yysemantic_stack_[(8) - (8)].expr),
								ParseConstants::fn_read);
		;}
    break;

  case 80:
#line 1642 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 81:
#line 1652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								NULL,NULL,
								(yysemantic_stack_[(5) - (5)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 82:
#line 1663 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 83:
#line 1674 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(6) - (4)].node)),
								NULL,
								(yysemantic_stack_[(6) - (6)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 84:
#line 1686 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 85:
#line 1698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								NULL,
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)),
								(yysemantic_stack_[(7) - (7)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 86:
#line 1710 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.external]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								NULL,
								ParseConstants::fn_extern_update);
		;}
    break;

  case 87:
#line 1722 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.expr]" << endl;
#endif
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								dynamic_cast<ParamList*>((yysemantic_stack_[(8) - (4)].node)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(8) - (7)].node)),
								(yysemantic_stack_[(8) - (8)].expr),
								ParseConstants::fn_update);
		;}
    break;

  case 88:
#line 1740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [single]" << endl;
#endif
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		;}
    break;

  case 89:
#line 1751 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [list]" << endl;
#endif
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 90:
#line 1768 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname]" << endl;
#endif
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		;}
    break;

  case 91:
#line 1777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname.type]" << endl;
#endif
			(yyval.node) = new Param(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 92:
#line 1792 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1803 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NonNodeEnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1817 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1831 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [single]" << endl;
#endif
			Expr* expr_p = new Expr(LOC ((yyloc)));
			expr_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = expr_p;
		;}
    break;

  case 96:
#line 1840 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [expr.single]" << endl;
#endif
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p) expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
		;}
    break;

  case 97:
#line 1855 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1862 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1869 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1876 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1883 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1892 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1899 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1906 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1913 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1920 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 107:
#line 1927 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
      cout << "ExprSingle [TryExpr]" << endl;
#endif
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 108:
#line 1934 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 109:
#line 1944 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 110:
#line 1954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 111:
#line 1965 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [orderby.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(4) - (1)].node)),
								NULL,NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 112:
#line 1976 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.orderby.return]" << endl;
#endif
			(yyval.expr) = new FLWORExpr(LOC ((yyloc)),
								dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(5) - (1)].node)),
								dynamic_cast<WhereClause*>((yysemantic_stack_[(5) - (2)].node)),
                NULL,
								dynamic_cast<OrderByClause*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 113:
#line 1988 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [groupby.return]" << endl;
#endif
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
#line 2003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.groupby.return]" << endl;
#endif
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
#line 2018 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [groupby.orderby.return]" << endl;
#endif
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
#line 2033 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.groupby.orderby.return]" << endl;
#endif
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
#line 2054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [single]" << endl;
#endif
			ForLetClauseList* flc_list_p = new ForLetClauseList(LOC ((yyloc)));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = flc_list_p;
		;}
    break;

  case 118:
#line 2063 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [list]" << endl;
#endif
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>((yysemantic_stack_[(2) - (1)].node));
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 119:
#line 2078 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 120:
#line 2085 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 121:
#line 2098 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 122:
#line 2112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [single]" << endl;
#endif
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		;}
    break;

  case 123:
#line 2121 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [list]" << endl;
#endif
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 124:
#line 2138 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 125:
#line 2148 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 126:
#line 2159 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 127:
#line 2171 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 128:
#line 2184 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 129:
#line 2195 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 130:
#line 2207 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 131:
#line 2219 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.scorevar.in]" << endl;
#endif
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 132:
#line 2237 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 133:
#line 2252 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 134:
#line 2266 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 135:
#line 2281 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 136:
#line 2290 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [list.single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 137:
#line 2305 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		;}
    break;

  case 138:
#line 2314 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [list.single]" << endl;
#endif
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 139:
#line 2331 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 140:
#line 2342 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 141:
#line 2354 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [scorevar.gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 142:
#line 2365 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.scorevar.gets]" << endl;
#endif
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 143:
#line 2380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      static_cast<VarGetsDecl *> ((yysemantic_stack_[(1) - (1)].node))->set_kind (VarGetsDecl::eval_var);
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 144:
#line 2385 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    ;}
    break;

  case 145:
#line 2400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 146:
#line 2411 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupByClause [groupspec]" << endl;
#endif
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(2) - (2)].node)),
                 NULL,
                 NULL);
    ;}
    break;

  case 147:
#line 2421 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupByClause [groupspec.let]" << endl;
#endif
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (2)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(3) - (3)].node)),
                 NULL);
    ;}
    break;

  case 148:
#line 2431 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupByClause [groupspec.where]" << endl;
#endif
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (2)].node)),
                 NULL,
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(3) - (3)].node)));
    ;}
    break;

  case 149:
#line 2441 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupByClause [groupspec.let.where]" << endl;
#endif
      (yyval.node) = new GroupByClause(LOC((yyloc)),
                 dynamic_cast<GroupSpecList*>((yysemantic_stack_[(4) - (2)].node)),
                 dynamic_cast<LetClauseList*>((yysemantic_stack_[(4) - (3)].node)),
                 dynamic_cast<WhereClause*>((yysemantic_stack_[(4) - (4)].node)));
    ;}
    break;

  case 150:
#line 2454 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpecList [single]" << endl;
#endif
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    ;}
    break;

  case 151:
#line 2463 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpecList [list]" << endl;
#endif
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    ;}
    break;

  case 152:
#line 2477 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpec []" << endl;
#endif
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    ;}
    break;

  case 153:
#line 2486 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupSpec [collation]" << endl;
#endif
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    ;}
    break;

  case 154:
#line 2498 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupCollationSpec [ ]" << endl;
#endif
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 155:
#line 2508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClauseList [single]" << endl;
#endif
      LetClauseList* lc_list_p = new LetClauseList(LOC((yyloc)));
      lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = lc_list_p;
    ;}
    break;

  case 156:
#line 2518 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClauseList [list]" << endl;
#endif
      LetClauseList* lc_list_p = dynamic_cast<LetClauseList*>((yysemantic_stack_[(2) - (1)].node));
      if (lc_list_p) lc_list_p->push_back(dynamic_cast<LetClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    ;}
    break;

  case 157:
#line 2533 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 158:
#line 2541 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [stable]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)),
								true);
		;}
    break;

  case 159:
#line 2556 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [single]" << endl;
#endif
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		;}
    break;

  case 160:
#line 2565 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [list]" << endl;
#endif
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 161:
#line 2582 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		;}
    break;

  case 162:
#line 2591 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single.modifier]" << endl;
#endif
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 163:
#line 2606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		;}
    break;

  case 164:
#line 2616 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 165:
#line 2626 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 166:
#line 2636 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		;}
    break;

  case 167:
#line 2646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 168:
#line 2656 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty.collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 169:
#line 2666 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty.collation]" << endl;
#endif
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 170:
#line 2682 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 171:
#line 2689 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 172:
#line 2702 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 173:
#line 2710 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 174:
#line 2724 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 175:
#line 2738 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [some]" << endl;
#endif
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 176:
#line 2748 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [every]" << endl;
#endif
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 177:
#line 2764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [single]" << endl;
#endif
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		;}
    break;

  case 178:
#line 2774 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [list]" << endl;
#endif
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		;}
    break;

  case 179:
#line 2789 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 180:
#line 2798 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [type.in]" << endl;
#endif
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<TypeDeclaration*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 181:
#line 2814 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.return]" << endl;
#endif
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(7) - (4)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 182:
#line 2824 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.varname.return]" << endl;
#endif
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(9) - (2)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(9) - (4)].node)),
								driver.symtab.get((off_t)(yysemantic_stack_[(9) - (7)].sval)),
								(yysemantic_stack_[(9) - (9)].expr));
		;}
    break;

  case 183:
#line 2841 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [single]" << endl;
#endif
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		;}
    break;

  case 184:
#line 2850 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [list]" << endl;
#endif
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 185:
#line 2865 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.return]" << endl;
#endif
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 186:
#line 2874 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.as.return]" << endl;
#endif
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 187:
#line 2890 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 188:
#line 2904 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 189:
#line 2911 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2925 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2932 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2954 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 193:
#line 2961 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.valcomp.ftcontains]" << endl;
#endif
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 194:
#line 2972 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.gencomp.ftcontains]" << endl;
#endif
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<GeneralComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 195:
#line 2983 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "is" | "<<" | ">>" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.nodecomp.ftcontains]" << endl;
#endif
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 196:
#line 3000 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 197:
#line 3007 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect]" << endl;
#endif
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		;}
    break;

  case 198:
#line 3017 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect.ftignore]" << endl;
#endif
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		;}
    break;

  case 199:
#line 3033 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 3040 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 201:
#line 3054 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 3061 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 203:
#line 3068 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 204:
#line 3081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 205:
#line 3088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 206:
#line 3095 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 207:
#line 3102 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 208:
#line 3109 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 209:
#line 3122 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 211:
#line 3137 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 212:
#line 3151 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 213:
#line 3158 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 214:
#line 3165 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 215:
#line 3178 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 216:
#line 3185 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat.seqtype]" << endl;
#endif
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 217:
#line 3200 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 218:
#line 3207 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable.seqtype]" << endl;
#endif
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 219:
#line 3222 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 220:
#line 3229 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast.singletype]" << endl;
#endif
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 221:
#line 3244 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 222:
#line 3251 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary.singletype]" << endl;
#endif
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 223:
#line 3266 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 224:
#line 3273 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [signlist.value]" << endl;
#endif
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 225:
#line 3288 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 226:
#line 3295 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 227:
#line 3302 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 228:
#line 3309 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.-]" << endl;
#endif
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 229:
#line 3324 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 230:
#line 3331 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 3338 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 232:
#line 3352 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 233:
#line 3359 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 234:
#line 3366 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 235:
#line 3373 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 236:
#line 3380 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 237:
#line 3387 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 238:
#line 3400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 239:
#line 3407 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 240:
#line 3414 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 241:
#line 3421 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 242:
#line 3428 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 243:
#line 3435 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 244:
#line 3448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 245:
#line 3455 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 246:
#line 3462 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 247:
#line 3476 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 248:
#line 3483 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [mode.expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 249:
#line 3498 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		;}
    break;

  case 250:
#line 3507 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist.expr]" << endl;
#endif
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		;}
    break;

  case 251:
#line 3522 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [single]" << endl;
#endif
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		;}
    break;

  case 252:
#line 3531 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [list]" << endl;
#endif
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 253:
#line 3548 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Pragma [ ]" << endl;
#endif
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));

		;}
    break;

  case 254:
#line 3556 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 255:
#line 3599 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 256:
#line 3606 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 257:
#line 3613 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 258:
#line 3620 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]" << endl;
#endif
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 259:
#line 3636 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]" << endl;
#endif
       AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (as != NULL ?
             new RelativePathExpr(LOC ((yyloc)),
                                  ParseConstants::st_slash,
                                  new ContextItemExpr(LOC((yyloc))),
                                  (yysemantic_stack_[(1) - (1)].expr)) :
             (yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 260:
#line 3650 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 261:
#line 3658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 262:
#line 3671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 263:
#line 3678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 264:
#line 3691 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 265:
#line 3700 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 266:
#line 3709 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		;}
    break;

  case 267:
#line 3718 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]" << endl;
#endif
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 268:
#line 3733 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 269:
#line 3742 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 270:
#line 3756 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 271:
#line 3763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 272:
#line 3770 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 273:
#line 3777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 274:
#line 3784 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 275:
#line 3791 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 276:
#line 3798 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 277:
#line 3811 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 278:
#line 3818 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 279:
#line 3831 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]" << endl;
#endif
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 280:
#line 3840 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]" << endl;
#endif
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC ((yyloc)),
								rev_p);
		;}
    break;

  case 281:
#line 3855 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 282:
#line 3862 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 283:
#line 3869 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 284:
#line 3876 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 285:
#line 3883 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 286:
#line 3901 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 287:
#line 3908 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 288:
#line 3921 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 289:
#line 3928 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 290:
#line 3941 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*]" << endl;
#endif
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		;}
    break;

  case 291:
#line 3951 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [pref:*]" << endl;
#endif
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		;}
    break;

  case 292:
#line 3961 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*:qname]" << endl;
#endif
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		;}
    break;

  case 293:
#line 3977 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 294:
#line 3984 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]" << endl;
#endif
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 295:
#line 3999 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]" << endl;
#endif
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		;}
    break;

  case 296:
#line 4008 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [list]" << endl;
#endif
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 297:
#line 4025 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 298:
#line 4039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 4046 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4053 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4060 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4067 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 4088 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 306:
#line 4101 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 307:
#line 4108 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 308:
#line 4121 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 309:
#line 4129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 310:
#line 4137 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 311:
#line 4151 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 312:
#line 4164 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 313:
#line 4171 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 314:
#line 4185 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 315:
#line 4198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 316:
#line 4212 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 317:
#line 4271 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		;}
    break;

  case 318:
#line 4280 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]" << endl;
#endif
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		;}
    break;

  case 319:
#line 4295 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]" << endl;
#endif
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		;}
    break;

  case 320:
#line 4304 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]" << endl;
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		;}
    break;

  case 321:
#line 4319 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 322:
#line 4326 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 323:
#line 4339 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 324:
#line 4346 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 4353 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 326:
#line 4366 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname/> ]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		;}
    break;

  case 327:
#line 4377 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist/> ]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(4) - (3)].node)), 
								NULL);
		;}
    break;

  case 328:
#line 4388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname></qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(6) - (5)].sval))),
								NULL,
								NULL);
		;}
    break;

  case 329:
#line 4399 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname>content</qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(7) - (4)].node)));
		;}
    break;

  case 330:
#line 4410 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist></qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(7) - (6)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(7) - (3)].node)),
								NULL);
		;}
    break;

  case 331:
#line 4421 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist>content</qname>]" << endl;
#endif
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(8) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(8) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(8) - (5)].node)));
		;}
    break;

  case 332:
#line 4439 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]" << endl;
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		;}
    break;

  case 333:
#line 4448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]" << endl;
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 334:
#line 4463 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]" << endl;
#endif
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 335:
#line 4472 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [list]" << endl;
#endif
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 336:
#line 4489 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]" << endl;
#endif
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(3) - (3)].node)));
		;}
    break;

  case 337:
#line 4504 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 338:
#line 4512 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 339:
#line 4526 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 340:
#line 4533 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 341:
#line 4540 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 342:
#line 4549 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		;}
    break;

  case 343:
#line 4558 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list ""]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 344:
#line 4569 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list]" << endl;
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 345:
#line 4586 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 346:
#line 4593 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 347:
#line 4600 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		;}
    break;

  case 348:
#line 4609 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]" << endl;
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		;}
    break;

  case 349:
#line 4618 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.'']" << endl;
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 350:
#line 4629 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.single]" << endl;
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 351:
#line 4646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 352:
#line 4654 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 353:
#line 4668 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 354:
#line 4676 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 355:
#line 4690 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 356:
#line 4698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 357:
#line 4706 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]" << endl;
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		;}
    break;

  case 358:
#line 4715 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]" << endl;
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		;}
    break;

  case 359:
#line 4730 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [char_ref]\n";
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 360:
#line 4739 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 361:
#line 4747 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 362:
#line 4755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 363:
#line 4769 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 364:
#line 4777 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 365:
#line 4795 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 366:
#line 4803 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 367:
#line 4823 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 368:
#line 4841 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 4848 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 370:
#line 4855 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 371:
#line 4862 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 372:
#line 4869 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 373:
#line 4876 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 374:
#line 4889 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 375:
#line 4903 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 376:
#line 4912 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 377:
#line 4921 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 378:
#line 4929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 379:
#line 4957 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								NULL);
		;}
    break;

  case 380:
#line 4966 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval))),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 381:
#line 4975 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 382:
#line 4983 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 383:
#line 4997 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 384:
#line 5011 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 385:
#line 5025 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		;}
    break;

  case 386:
#line 5034 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		;}
    break;

  case 387:
#line 5043 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 388:
#line 5051 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 389:
#line 5065 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		;}
    break;

  case 390:
#line 5074 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]" << endl;
#endif
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		;}
    break;

  case 391:
#line 5089 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 392:
#line 5103 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		;}
    break;

  case 393:
#line 5112 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 394:
#line 5121 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 395:
#line 5161 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 396:
#line 5169 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 397:
#line 5177 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 398:
#line 5191 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 399:
#line 5198 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 400:
#line 5205 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 401:
#line 5218 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 402:
#line 5232 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 403:
#line 5239 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 404:
#line 5246 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 405:
#line 5253 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 406:
#line 5260 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 407:
#line 5267 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 408:
#line 5274 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 409:
#line 5281 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 410:
#line 5288 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 411:
#line 5301 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 412:
#line 5314 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 413:
#line 5321 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 414:
#line 5329 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 415:
#line 5343 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 416:
#line 5356 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 417:
#line 5369 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 418:
#line 5376 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 419:
#line 5383 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 420:
#line 5396 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 421:
#line 5405 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
								NULL);
		;}
    break;

  case 422:
#line 5414 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 423:
#line 5423 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		;}
    break;

  case 424:
#line 5432 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]" << endl;
#endif
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 425:
#line 5447 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 426:
#line 5461 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL);
		;}
    break;

  case 427:
#line 5470 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))),
									NULL);
		;}
    break;

  case 428:
#line 5479 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 429:
#line 5488 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(5) - (2)].sval))),
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)));
		;}
    break;

  case 430:
#line 5497 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		;}
    break;

  case 431:
#line 5507 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 432:
#line 5517 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]" << endl;
#endif
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(5) - (4)].node)),
									true);
		;}
    break;

  case 433:
#line 5533 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 434:
#line 5557 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 435:
#line 5567 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (1)].sval))),
								true);
		;}
    break;

  case 436:
#line 5590 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 437:
#line 5633 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [strict]" << endl;
#endif
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 438:
#line 5641 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [lax]" << endl;
#endif
    ;}
    break;

  case 439:
#line 5647 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [skip]" << endl;
#endif
    ;}
    break;

  case 440:
#line 5658 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 441:
#line 5667 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 442:
#line 5676 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 443:
#line 5685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 444:
#line 5694 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 445:
#line 5704 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 446:
#line 5713 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 447:
#line 5722 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 448:
#line 5731 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.after]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 449:
#line 5740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.before]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 450:
#line 5755 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 451:
#line 5763 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 452:
#line 5776 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 453:
#line 5785 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceValueOfExpr [value.expr]" << endl;
#endif
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 454:
#line 5800 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 455:
#line 5829 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(6) - (2)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(6) - (4)].expr), (yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 456:
#line 5843 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]" << endl;
#endif
       VarNameList* lList = new VarNameList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		;}
    break;

  case 457:
#line 5852 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]" << endl;
#endif
       VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		;}
    break;

  case 458:
#line 5868 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "VarNameDecl [" << driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)) << "]" << endl;
#endif
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 459:
#line 5885 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TryExpr []" << endl;
#endif
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 460:
#line 5895 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchList [single]" << endl;
#endif
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    ;}
    break;

  case 461:
#line 5905 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchList [list]" << endl;
#endif
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    ;}
    break;

  case 462:
#line 5919 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    ;}
    break;

  case 463:
#line 5929 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest,VarErrorCode]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(7) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
                          (yysemantic_stack_[(7) - (7)].expr));
    ;}
    break;

  case 464:
#line 5940 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest,VarErrorCode]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(10) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(10) - (5)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(10) - (8)].sval)),
                          (yysemantic_stack_[(10) - (10)].expr));
    ;}
    break;

  case 465:
#line 5952 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest,VarErrorCode]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(13) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(13) - (5)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(13) - (8)].sval)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(13) - (11)].sval)),
                          (yysemantic_stack_[(13) - (13)].expr));
    ;}
    break;

  case 466:
#line 5974 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(5) - (2)].node)),
                          (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 467:
#line 5980 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(3) - (2)].expr));
    ;}
    break;

  case 468:
#line 5997 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 469:
#line 6003 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 470:
#line 6009 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 471:
#line 6015 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 472:
#line 6027 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 473:
#line 6033 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 474:
#line 6039 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 475:
#line 6045 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 476:
#line 6057 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 477:
#line 6063 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 478:
#line 6075 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 479:
#line 6081 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 480:
#line 6093 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 481:
#line 6099 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 482:
#line 6111 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 483:
#line 6117 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 484:
#line 6129 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 485:
#line 6135 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 486:
#line 6141 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 487:
#line 6153 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 488:
#line 6159 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 489:
#line 6171 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 490:
#line 6177 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 491:
#line 6189 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 492:
#line 6195 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 493:
#line 6201 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 494:
#line 6207 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 495:
#line 6213 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 496:
#line 6225 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 497:
#line 6237 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 498:
#line 6244 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 499:
#line 6251 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 500:
#line 6258 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 501:
#line 6265 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 502:
#line 6272 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 503:
#line 6279 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 504:
#line 6292 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 505:
#line 6298 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 506:
#line 6304 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 507:
#line 6310 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 508:
#line 6322 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 509:
#line 6328 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 510:
#line 6334 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 511:
#line 6340 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 512:
#line 6352 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 513:
#line 6358 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 514:
#line 6370 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 515:
#line 6376 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 516:
#line 6382 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 517:
#line 6388 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 518:
#line 6394 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 519:
#line 6400 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 520:
#line 6406 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 521:
#line 6418 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 522:
#line 6424 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 523:
#line 6436 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 524:
#line 6442 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 525:
#line 6448 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 526:
#line 6454 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 527:
#line 6466 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 528:
#line 6472 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 529:
#line 6478 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 530:
#line 6484 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 531:
#line 6490 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 532:
#line 6502 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 533:
#line 6508 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 534:
#line 6520 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 535:
#line 6526 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 536:
#line 6538 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 537:
#line 6544 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 538:
#line 6556 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 539:
#line 6562 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 540:
#line 6574 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 541:
#line 6586 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 542:
#line 6592 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 543:
#line 6604 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 544:
#line 6610 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 545:
#line 6616 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 546:
#line 6628 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 547:
#line 6634 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 548:
#line 6640 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 549:
#line 6646 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 550:
#line 6652 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 551:
#line 6664 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 552:
#line 6671 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 553:
#line 6678 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 554:
#line 6685 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 555:
#line 6698 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 556:
#line 6710 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 557:
#line 6722 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 558:
#line 6734 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 559:
#line 6740 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 560:
#line 6752 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 561:
#line 6758 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 562:
#line 6764 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 563:
#line 6776 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 564:
#line 6782 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 565:
#line 6794 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]" << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 7515 "/home/muresan/Projects/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -682;
  const short int
  xquery_parser::yypact_[] =
  {
       778,  1200,  1411,  -682,  -682,     7,  -682,    58,  -682,  -682,
    -682,  3099,    89,   315,  -682,  3099,   156,  -682,   312,   -40,
     311,   -23,   326,   227,   235,   435,   345,   381,   493,   -46,
     511,   508,  -682,  -682,  3099,   213,   512,  -682,  -682,  -682,
    3099,    96,   522,  -682,  -682,   536,  3099,   263,   314,  -682,
     556,  1622,  -682,   465,   450,  3099,  -682,   574,    83,  -682,
     546,  -682,  -682,   254,   593,   595,  -682,  3641,  3479,   522,
    -682,   599,  3099,   466,  3099,  3099,  3099,     1,   607,   394,
    3099,  3099,  3099,  3099,  3099,  3099,  3099,   612,   529,   620,
    3099,  3695,   655,   989,  -682,  -682,    85,  3099,   492,   504,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
     626,  -682,  -682,   348,  -682,  -682,  -682,  -682,  -682,  -682,
     540,   647,  -682,  3821,   440,   349,   222,   117,   451,  -682,
     572,   510,   645,   649,   565,  -682,  -682,  -682,   -41,  -682,
    -682,  -682,   407,  -682,   577,   315,  -682,   577,   315,  -682,
    -682,  -682,  -682,   577,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,    75,  -682,   205,  1833,  3099,   206,
      27,  -682,    90,  -682,  -682,   209,  -682,  -682,  -682,  -682,
    -682,  -682,   646,   650,  -682,   672,   675,  -682,  -682,   581,
     614,   681,  -682,  -682,   585,   418,   256,  -682,   550,   552,
    -682,   258,   111,  -682,   113,    45,    29,  -682,    -9,   667,
    -682,   114,   684,   701,   686,   596,   708,   699,    -8,   677,
    -682,  -682,   115,   637,  -682,   261,    60,   573,   576,  -682,
     716,  -682,   623,  3099,   579,   582,  -682,  -682,    69,    42,
     264,  -682,   116,   267,   270,   547,  -682,   223,  -682,  -682,
    -682,  -682,  -682,   454,   459,   710,   528,   530,   648,    11,
    -682,  3099,    -8,    10,  -682,  -682,   589,  -682,  -682,  -682,
    -682,   726,  -682,  -682,  -682,  -682,  -682,  -682,  -682,   162,
    -682,  -682,   301,   408,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,    85,     5,
    3099,  3099,   676,  3099,  3099,  3099,  -682,   334,   342,   592,
    3310,  3310,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  3310,  3310,  3310,
       4,  3310,  3310,  3310,  3310,  3310,  3310,  3310,  3310,  3310,
    3310,  3310,   396,   396,   733,   733,  -682,  -682,  -682,  2044,
    -682,  3479,  3479,  3099,   577,  -682,  -682,   577,  -682,   577,
    -682,  -682,  -682,  -682,   119,   271,   639,   735,  -682,   735,
    -682,  -682,   188,   354,  -682,  -682,    25,   732,  -682,   217,
     396,  -682,  3099,   200,  -682,  -682,  -682,   643,   740,  -682,
     740,  -682,  3099,   654,   687,  3099,   688,  3099,   689,   -65,
     658,    -5,   691,   591,   744,   682,   744,  -682,   683,   738,
    3099,   669,   -28,   698,  -682,   750,  -682,  -682,  -682,  -682,
    -682,  -682,  2255,   273,  -682,  -682,  3099,   690,  -682,    39,
      68,  -682,  -682,   736,  -682,  -682,  -682,   752,  -682,  3099,
    3099,  3099,  3099,  3099,  3099,  3099,  3099,  3099,  3099,  3099,
    3099,  3099,  3099,   702,  3099,   624,   704,  3099,  -682,  -682,
     301,   301,   162,  -682,   759,   760,   162,   762,  -682,    44,
    -682,   622,  -682,  -682,  -682,   475,   743,  -682,   766,    46,
    -682,  -682,   743,  -682,  3099,   359,   629,  3099,   634,  3099,
     647,  -682,  -682,  -682,  -682,  3099,     4,   472,  -682,   535,
    3592,   559,   553,  -682,  -682,   555,   331,   222,   222,   -37,
     117,   117,   117,   117,   451,   451,  -682,  -682,  -682,  -682,
    -682,  -682,   494,  -682,  -682,  -682,  -682,   703,  -682,  -682,
     274,  -682,  -682,   112,  -682,  3099,  -682,  -682,  2466,  -682,
     641,   644,  -682,  -682,  -682,  -682,   783,   358,   120,  -682,
    -682,   393,   121,  -682,  -682,  -682,  3099,  2677,   707,   651,
     652,   653,   659,  -682,  3099,   522,  -682,   788,  -682,   795,
    3099,   717,  3099,  3099,   -17,   718,   536,  3099,  -682,   779,
     803,   779,  -682,   744,  -682,  3099,  3099,   745,   556,   685,
    -682,   275,   742,  -682,    18,  -682,  -682,   840,  -682,  -682,
    3099,   831,  -682,  -682,    43,  -682,  -682,  -682,  -682,    51,
    -682,   137,   292,  -682,   694,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,   612,
     705,   656,   620,   706,  -682,  -682,  -682,  -682,  -682,    23,
     162,   424,   122,   124,     5,  -682,   837,  -682,  -682,  -682,
    -682,   419,   818,  -682,  3099,   819,   676,  -682,  -682,   -39,
    -682,  3099,   709,  3099,  -682,  3099,  -682,   276,   711,  -682,
    3310,  -682,  -682,  -682,  -682,  -128,   452,  -682,     4,  -128,
    3310,  3310,  3638,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
       4,     4,   452,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,   277,
    -682,  -682,   834,   396,  -682,  3099,  -682,   793,   420,   396,
    -682,  -682,   421,  -682,  -682,   280,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  3099,  -682,  -682,  3099,
     764,  3099,  -682,   794,   852,   844,   779,  -682,  -682,  3099,
    -682,  -682,  -682,  2888,   259,   460,  -682,  -682,   281,   712,
     860,  -682,   861,    56,   864,   728,   182,  -682,  -682,  -682,
    3099,    70,   656,  -682,  -682,  -682,  -682,  -682,  3310,  3310,
    3310,  3310,   867,   657,   857,  -682,   857,  -682,  -682,   818,
    -682,  -682,  -682,   868,  -682,  -682,  -682,  -682,  -682,  3099,
    -682,  -682,  -682,  -682,   117,  -682,  -682,  -682,   251,   559,
    -682,  -682,   187,  3310,  -682,  -682,   553,  -682,   638,  -682,
    -682,    19,   282,  -682,   396,  -682,  -682,   366,   396,  -682,
    -682,  -682,  -682,  -682,  3099,  -682,  3099,  -682,   744,  -682,
    -682,   284,  -682,  -682,   863,   269,  -682,  -682,  -682,  -682,
     748,   541,  -682,  -682,  -682,  -682,   722,   724,   880,   872,
    3099,   881,  3099,  -682,   127,  -682,   117,   117,   117,   431,
     452,  -682,   129,  -682,   130,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,   463,  -682,
    -682,   486,  -682,  -682,   779,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,   737,   396,  -682,   747,  -682,   833,
     797,  3310,   665,   857,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,   754,  3099,   888,  -682,   117,  -682,  -682,  3099,  -682,
     131,  -682,   839,   797,   890,  -682,   132,   842,   797,   893,
    -682,   763,   797,  -682
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,     0,     0,   291,   292,   288,   436,     0,   282,   285,
     272,     0,     0,     0,   270,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   274,     0,     0,     0,   314,   280,   310,
       0,     0,     0,   276,   275,     0,     0,     0,     0,   309,
       0,     0,   226,     0,     0,     0,   281,     0,     0,   225,
       0,   284,   283,     0,     0,     0,   273,   255,     0,     0,
     290,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     4,     0,     0,     0,     0,
      15,    17,    19,    20,    21,    27,    22,    25,    26,    31,
      32,    33,    28,    29,    35,    36,    23,    30,    24,     9,
      94,    95,    97,     0,   117,   119,   120,    98,    99,   100,
     101,   188,   190,   192,   196,   199,   201,   204,   209,   212,
     215,   217,   219,   221,     0,   223,   229,   231,     0,   251,
     230,   258,   259,   262,   264,     0,   269,   266,     0,   277,
     287,   289,   263,   293,   298,   306,   299,   300,   301,   304,
     305,   302,   303,   321,   323,   324,   325,   322,   368,   369,
     370,   371,   372,   373,   286,   410,   402,   409,   408,   407,
     404,   406,   403,   405,   307,    34,   102,   103,   105,   104,
     106,   107,   108,   379,     0,   375,     0,     0,     0,     0,
       0,   420,     0,   288,   278,     0,   416,    53,    38,    39,
      70,    71,     0,     0,    52,     0,     0,    46,    47,     0,
       0,     0,    44,    45,     0,     0,     0,   412,     0,     0,
     311,     0,     0,   426,     0,     0,     0,   177,     0,   121,
     122,     0,    62,     0,    54,     0,     0,     0,     0,   134,
     135,   312,     0,     0,   411,     0,     0,     0,     0,   417,
       0,   254,     0,     0,     0,     0,   256,   257,     0,     0,
       0,   415,     0,     0,     0,     0,   364,     0,   437,   438,
     439,   450,   451,     0,     0,     0,     0,     0,     0,     0,
     456,     0,   144,     0,   143,   137,     0,   507,   506,   511,
     510,     0,   504,   505,   509,   513,   531,   520,   542,   529,
     508,   512,     0,     0,   541,    43,   497,   498,   499,   500,
     501,   502,   503,     1,     3,     5,    10,     8,    12,    13,
       0,     0,     0,     0,     0,     0,   118,     0,     0,     0,
       0,     0,   232,   246,   237,   236,   244,   235,   234,   233,
     245,   238,   243,   242,   241,   240,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   227,   224,     0,
     252,     0,     0,     0,   265,   295,   268,   267,   279,   294,
     380,   376,   317,   319,     0,     0,     0,     0,   421,     0,
     423,   384,     0,     0,    40,    41,     0,     0,    42,     0,
       0,    67,     0,     0,   374,   413,   414,     0,     0,   427,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,    55,
       0,     0,     0,     0,   313,     0,   315,   366,   365,   418,
     419,   253,     0,     0,   425,   433,     0,     0,   326,     0,
       0,   334,   383,     0,   316,   247,   363,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   467,   540,
       0,     0,   530,   532,     0,     0,   527,     0,   515,     0,
     514,     0,    16,    18,    96,   161,   157,   159,     0,   146,
     150,   109,   158,   145,     0,     0,     0,     0,     0,     0,
     189,   191,   194,   193,   195,     0,     0,     0,   489,   197,
     468,   476,   478,   480,   482,   484,   487,   203,   202,   200,
     206,   207,   208,   205,   210,   211,   214,   213,   401,   400,
     394,   216,   392,   398,   399,   218,   220,   389,   222,   249,
       0,   260,   261,     0,   296,     0,   318,   248,     0,   434,
       0,     0,    50,    51,    48,    49,     0,     0,     0,    88,
      37,     0,     0,   391,    66,    69,     0,     0,   434,     0,
       0,     0,     0,   179,     0,     0,   176,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    64,
       0,    56,    60,     0,   139,     0,     0,     0,     0,     0,
     385,     0,     0,   175,     0,   359,   356,     0,   360,   361,
       0,     0,   362,   355,     0,   332,   358,   357,   327,     0,
     335,     0,     0,   183,     0,   443,   444,   441,   440,   442,
     448,   449,   446,   445,   447,   454,   452,   453,   458,     0,
       0,     0,     0,     0,   539,   538,   533,   534,   536,     0,
     528,   523,     0,     0,    14,   170,     0,   171,   172,   173,
     162,   163,   164,   165,     0,   152,     0,   155,   148,   147,
     110,     0,     0,     0,   113,     0,   111,     0,     0,   483,
       0,   198,   496,   544,   543,     0,     0,   545,     0,     0,
       0,     0,   469,   473,   491,   472,   495,   493,   492,   494,
       0,     0,     0,   485,   548,   549,   546,   547,   550,   488,
     395,   397,   396,   393,   390,   250,   297,   320,   381,     0,
     422,   424,    90,     0,    72,     0,    73,     0,     0,     0,
      80,    81,     0,    68,   377,     0,   435,   428,   429,   431,
     432,   180,   178,   132,   133,   126,     0,   128,   125,     0,
       0,     0,   123,     0,     0,    63,    57,   141,   140,     0,
     136,    11,   386,     0,   345,   339,   336,   367,     0,     0,
       0,   333,     0,     0,     0,     0,     0,   184,     7,   457,
       0,     0,   459,   460,   138,   466,   537,   535,     0,     0,
       0,     0,     0,     0,     0,   518,     0,   516,   174,   166,
     167,   168,   160,     0,   153,   151,   156,   149,   114,     0,
     112,   115,   490,   486,   565,   564,   563,   559,     0,   477,
     558,   470,     0,     0,   475,   474,   479,   481,     0,   382,
      91,     0,     0,    89,     0,    74,    75,     0,     0,    82,
      83,   378,   130,   127,     0,   129,     0,    59,     0,   142,
     387,     0,   353,   347,     0,   346,   348,   354,   351,   341,
       0,   340,   342,   352,    92,   328,     0,     0,     0,     0,
       0,     0,     0,   455,     0,   461,   552,   553,   551,     0,
     524,   525,     0,   521,     0,   169,   154,   116,   562,   561,
     560,   555,   556,   471,   557,    76,    77,    93,     0,    84,
      85,     0,   131,   187,    65,   388,   338,   349,   350,   337,
     343,   344,   329,   330,     0,     0,   185,     0,   181,     0,
       0,     0,     0,     0,   519,   517,    78,    79,    86,    87,
     331,     0,     0,     0,   462,   554,   526,   522,     0,   182,
       0,   186,     0,     0,     0,   463,     0,     0,     0,     0,
     464,     0,     0,   465
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -682,  -682,  -682,   829,   832,  -682,   836,  -682,   590,   597,
    -320,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -428,  -682,  -682,  -682,  -682,  -682,
     515,   172,  -682,  -553,   841,    30,   -80,  -682,  -682,   813,
    -682,  -682,   321,   498,  -233,  -492,  -682,  -682,   -42,   279,
    -482,   600,  -682,   247,  -682,  -682,  -292,   605,   262,  -682,
    -682,   266,  -595,  -682,   883,   350,  -682,  -682,   308,  -682,
    -682,   609,   611,   316,  -657,   594,   228,  -363,   255,   226,
    -682,  -682,  -682,  -682,  -682,   820,  -682,  -682,  -682,  -682,
    -682,  -682,   815,  -682,   -47,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,    26,   154,  -682,  -682,   307,   -92,  -682,  -336,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -447,
    -682,   317,  -682,   500,  -682,  -682,  -682,  -682,  -682,    77,
      86,  -600,  -423,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,   587,  -212,  -374,  -682,  -682,   265,  -366,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,   938,   940,   140,
     548,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,   313,
    -682,  -682,   165,  -682,   444,  -682,  -682,   272,   285,   250,
     455,  -682,  -682,   283,  -682,  -498,  -682,  -682,  -682,  -682,
     169,  -316,  -682,   485,   164,  -682,  -462,  -682,  -682,  -682,
    -682,  -681,  -682,  -682,  -682,  -682,   145,   287,  -682
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   619,   257,   115,   116,   117,   118,
     588,   589,   642,   756,   119,   120,   121,   122,   123,   124,
     125,   249,   250,   439,   451,   126,   259,   303,   304,   305,
     347,   348,   519,   520,   834,   699,   349,   516,   517,   690,
     691,   692,   693,   127,   246,   247,   128,   652,   653,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   367,   368,   369,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   394,   395,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   404,   172,   173,
     174,   644,   470,   471,   796,   890,   891,   884,   885,   892,
     886,   645,   646,   175,   176,   647,   177,   178,   179,   180,
     181,   182,   183,   566,   452,   561,   743,   562,   563,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   580,
     600,   194,   195,   196,   197,   198,   199,   200,   299,   300,
     201,   812,   813,   202,   539,   722,   540,   541,   542,   543,
     544,   545,   546,   723,   724,   325,   326,   327,   328,   329,
     912,   913,   330,   502,   506,   679,   503,   331,   332,   726,
     739,   823,   727,   728,   733,   729,   921,   847,   711
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       291,   292,   293,   294,   295,   296,   297,   510,   260,   565,
     306,   550,   551,   552,   553,   440,   564,   564,   621,   513,
     276,   277,   643,   423,   420,   420,   436,   697,     6,   285,
     436,   204,   206,   433,   538,   848,   441,   698,   761,   214,
     676,   209,   725,   610,   801,   215,   593,   816,   635,   636,
     794,   858,   635,   636,   564,   526,   528,    17,   496,   493,
     635,   636,   467,   851,   236,   635,   636,    26,   457,    28,
     241,    30,    31,   626,   389,   407,   251,   434,   420,   507,
      50,   262,     3,   637,    39,   265,   371,   637,   467,     4,
     213,   779,   232,   450,   696,   637,   830,   831,   267,   437,
     637,   586,   280,   613,   282,   283,   284,   268,    60,   210,
     222,   372,   682,   925,   218,    49,   242,   434,   638,   535,
     639,   845,   638,   340,   639,   536,   846,   403,   207,   468,
     638,   223,   639,   219,   755,   638,   233,   639,   409,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   432,   640,   648,   345,   558,   640,   428,
     340,   430,   340,   340,   340,    50,   640,   575,   757,   757,
     824,   640,   826,   208,   795,   949,    12,   953,   953,   972,
     977,   396,    57,   817,   398,   587,    57,   408,   438,    16,
     435,    47,    48,   683,    57,   786,   923,   643,   286,    57,
     538,   538,   643,   801,   458,   866,   611,   836,   615,   870,
     641,    71,    35,   804,   800,    71,   469,   837,   676,   627,
      41,   495,   802,    71,   855,   438,   494,   898,    71,   952,
     466,   497,   400,   702,   915,    77,   438,    91,   405,    77,
      70,   345,   649,   269,   438,   438,   537,    77,   438,   211,
     410,   559,    77,   340,   340,   500,   243,   340,   901,   212,
     514,   515,   882,   521,   515,   523,   244,    54,   635,   272,
     746,   429,   882,   431,   443,   454,   473,   805,   635,   576,
     758,   762,   825,    58,   827,   564,    79,   950,   252,   954,
     955,   973,   978,   586,   595,   374,    41,   582,   378,    64,
      65,   596,   574,   463,   340,   574,   340,   574,   926,   340,
     379,   477,   340,    73,   930,   340,   216,    91,   340,   340,
     583,   340,   340,   340,   340,   340,   375,     3,   340,   340,
     340,   560,   340,   651,     4,   213,   504,   217,   638,   254,
     639,   902,   594,   501,   571,   572,   376,   844,   638,   883,
     639,   224,   603,   225,    12,   606,   643,   608,   852,   937,
     806,   226,   401,   406,   513,   229,   411,    16,   378,   273,
     624,   887,   893,   237,   640,   957,    65,   591,   959,   861,
     379,   780,   538,   255,   640,   867,   633,   564,   478,   253,
      35,   753,   377,   564,   538,   538,   230,   964,    41,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   424,   670,   427,   558,   673,   456,   570,
     975,   472,   505,   573,   474,   980,   759,   475,   577,   983,
     632,   745,   792,   842,   859,    12,   918,   871,   894,   927,
     256,   935,   919,   507,   700,    54,    45,   704,    16,   706,
     934,   420,   754,   864,   868,   906,   907,   908,   909,   920,
     929,    58,   887,   584,   397,   220,   686,    50,   893,   635,
     399,    35,   371,   755,   341,   342,   508,    64,    65,    41,
     263,   755,   341,   888,   221,    70,   585,   760,   341,   342,
     928,    73,   631,   524,   931,   747,     6,   372,   564,   341,
     918,   527,   564,   344,   688,   689,   919,   343,   755,   685,
     559,   344,   421,   231,   865,   869,   763,   344,   701,   422,
     227,   228,   686,   920,   771,    17,    54,   373,   344,   509,
     775,   234,   777,   778,   235,   755,   755,   783,   240,   638,
     860,   639,    58,   345,   380,   787,   788,   687,   245,   581,
     635,   889,    39,   734,   735,   736,   737,   956,    64,    65,
     688,   689,   248,   381,   888,   707,   270,   271,   599,     1,
     601,   961,    73,   391,   392,   640,     2,     3,   755,   564,
     958,   738,   258,    49,     4,     5,   790,   535,   965,     6,
     560,   266,     7,   536,     8,     9,   288,   289,   290,   547,
     548,   755,    10,    11,    12,    13,   556,   557,   749,   951,
     264,    14,   378,   274,   515,   275,    15,    16,    17,   279,
     638,   838,   639,   840,   379,   841,   281,   765,   740,   741,
     742,   287,   940,   554,   555,    32,    33,   967,   298,    34,
      35,    36,    37,    38,   301,    39,   302,    40,    41,   567,
     567,   818,   819,   479,   480,   333,   640,   338,   484,   485,
      43,    44,   820,   821,   674,   675,   481,   482,   483,   339,
     798,   486,   487,   488,   340,   822,    49,   350,   351,   818,
     819,   370,   382,   532,   533,   534,    51,   384,   386,   383,
     820,   821,   385,   393,   412,    54,   872,   414,   413,   873,
     415,   875,   416,   417,    55,   418,   419,    56,    57,   879,
     425,    58,   426,   387,    60,   442,   445,    61,    62,   444,
      63,   446,   447,   448,   449,   453,   455,    64,    65,    66,
     903,    67,    68,   459,   461,    70,   460,    71,   462,   464,
      72,    73,   465,   489,   476,   490,   498,   491,    75,   492,
     499,   529,   518,   558,   578,   579,    76,   590,   597,   917,
     598,    77,   604,   605,   607,   609,   612,   616,   617,   618,
     625,   620,   622,   623,   628,   629,   654,   651,   669,   634,
     672,   671,     1,   677,   678,   862,   681,   684,   703,     2,
       3,   694,   695,   705,   932,   710,   933,     4,     5,   730,
     731,   750,     6,   732,   751,     7,   744,     8,     9,   752,
     766,   767,   768,   769,   773,    10,    11,    12,    13,   770,
     946,   774,   948,   881,    14,   776,   781,   784,   785,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   789,   797,    32,    33,
     791,   799,    34,    35,    36,    37,    38,   793,    39,   808,
      40,    41,   828,   815,   810,   686,   833,   420,   839,   586,
      42,   843,   874,    43,    44,   811,    45,   877,   876,   878,
     896,   897,   969,    46,    47,    48,   895,   900,   971,    49,
     899,   910,   507,   916,   924,   936,   942,    50,   943,    51,
     944,    52,   911,    53,   939,   945,   962,   947,    54,   963,
     966,   960,   755,   968,   970,   974,   976,    55,   979,   981,
      56,    57,   334,   982,    58,   335,    59,    60,   511,   863,
      61,    62,   336,    63,   592,   512,   346,   782,   337,   614,
      64,    65,    66,   835,    67,    68,    69,   525,    70,   522,
      71,   814,   278,    72,    73,   772,   832,   829,    74,   530,
     807,    75,   531,   390,   388,   904,   803,   549,   941,    76,
     650,   938,   568,   238,    77,   239,    78,   905,   602,    79,
     708,   857,   809,    80,    81,    82,    83,    84,    85,    86,
     849,   680,   709,     1,    87,   914,    88,   922,    89,    90,
       2,     3,     0,     0,     0,   854,   850,     0,     4,     5,
      91,     0,     0,     6,     0,   856,     7,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
      51,     0,    52,     0,    53,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,    56,    57,     0,     0,    58,     0,    59,    60,     0,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,    67,    68,    69,     0,    70,
       0,    71,     0,     0,    72,    73,     0,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,    77,     0,     0,     0,     0,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     1,    87,     0,    88,     0,    89,
      90,     2,     3,     0,     0,     0,     0,     0,     0,     4,
       5,    91,     0,     0,     6,     0,     0,     7,     0,     8,
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
       0,     0,    61,    62,     0,    63,     0,   203,     0,     0,
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
      60,     0,     0,    61,    62,     0,    63,     0,   205,     0,
       0,     0,     0,    64,    65,    66,     0,    67,    68,    69,
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
       0,     0,   261,     0,    64,    65,    66,     0,    67,    68,
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
       0,     0,     0,   402,     0,    64,    65,    66,     0,    67,
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
       0,   569,     0,     0,     0,     0,    64,    65,    66,     0,
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
      63,     0,   630,     0,     0,     0,     0,    64,    65,    66,
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
       0,    63,     0,   748,     0,     0,     0,     0,    64,    65,
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
      62,     0,    63,     0,   764,     0,     0,     0,     0,    64,
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
      61,    62,     0,    63,     0,   880,     0,     0,     0,     0,
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
       0,    42,     0,     0,    43,    44,     0,    45,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
      51,     0,    52,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,    56,    57,     0,     0,    58,     0,    59,    60,     0,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,    52,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,    56,    57,     0,     0,    58,     0,    59,    60,
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,    67,    68,     0,     0,
      70,     0,    71,     1,     0,    72,    73,     0,     0,     0,
       2,     3,     0,    75,     0,     0,     0,     0,     4,     5,
       0,    76,     0,     6,     0,     0,    77,     0,     8,     9,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,    37,    38,     0,    39,
       0,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,    56,    57,     0,     0,    58,     0,     0,     0,     0,
       0,    61,    62,     0,    63,     0,     0,     0,     0,     0,
       0,    64,    65,    66,     0,     1,     0,     0,     0,    70,
       0,    71,     2,     3,    72,    73,     0,     0,     0,     0,
       4,     5,    75,     0,     0,     6,     0,     0,     0,     0,
       8,     9,     0,     0,     0,    77,     0,     0,    10,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,    40,    41,     0,     0,     0,     0,     0,
     712,     0,     0,     0,     0,     0,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,   712,     0,     0,     0,
      55,     0,     0,    56,    57,     0,     0,    58,     0,     0,
       0,     0,     0,    61,    62,     0,    63,     0,     0,     0,
       0,     0,     0,    64,    65,    66,     0,     0,     0,     0,
       0,     0,     0,    71,     0,     0,    72,    73,   713,     0,
       0,   714,   307,   308,    75,   309,   310,   715,   716,   717,
       0,     0,     0,     0,     0,   718,   311,    77,   312,     0,
       0,     0,     0,     0,   719,     0,     0,     0,     0,   313,
     720,   721,     0,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   713,     0,     0,   714,   307,   308,
       0,   309,   310,   715,   716,   717,     0,     0,     0,     0,
       0,     0,   311,     0,   312,     0,     0,     0,     0,     0,
     719,     0,     0,     0,     0,   313,   853,   721,     0,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     352,     0,     0,     0,     0,     0,     0,     0,   353,     0,
       0,   354,     0,   355,     0,   307,   308,     0,   309,   310,
       0,     0,     0,     0,   356,     0,     0,     0,   357,   311,
       0,   312,     0,   358,     0,     0,     0,     0,     0,   359,
       0,     0,   313,     0,     0,     0,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,     0,     0,     0,
       0,     0,   360,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   361,   362,   363,   364,
     365,   366
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,    84,    85,    86,   323,    50,   383,
      90,   374,   375,   376,   377,   248,   382,   383,   446,   339,
      67,    68,   469,   235,    33,    33,    35,   519,    24,    28,
      35,     1,     2,   245,   370,   716,   248,   519,   591,    13,
     502,    11,   540,   108,   644,    15,   420,    24,     9,    10,
      32,   732,     9,    10,   420,   347,   348,    53,    48,    48,
       9,    10,    20,   720,    34,     9,    10,    62,     8,    64,
      40,    66,    67,   101,   115,    48,    46,    48,    33,    35,
     119,    51,    12,    44,    80,    55,   123,    44,    20,    19,
      20,   108,   138,   101,    48,    44,   691,   692,    15,   108,
      44,    76,    72,   108,    74,    75,    76,    24,   149,    20,
     133,   148,    68,    94,   154,   111,    20,    48,    79,   115,
      81,   249,    79,    48,    81,   121,   254,   207,   121,    87,
      79,   154,    81,   173,   115,    79,   182,    81,    48,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,   108,   115,    87,   195,    20,   115,    48,
      48,    48,    48,    48,    48,   119,   115,    48,    48,    48,
      48,   115,    48,   115,   156,    48,    39,    48,    48,    48,
      48,   155,   143,   160,   158,   160,   143,   160,   253,    52,
     161,   106,   107,   509,   143,   623,   853,   644,   197,   143,
     536,   537,   649,   803,   144,   758,   439,   699,   441,   762,
     171,   172,    75,    76,   171,   172,   174,   699,   680,   452,
      83,   301,   171,   172,   722,   253,   215,   171,   172,   910,
     161,   221,   157,   525,   829,   196,   253,   232,   208,   196,
     170,   195,   174,   160,   253,   253,   242,   196,   253,   160,
     160,   114,   196,    48,    48,    93,   160,    48,    76,   170,
     340,   341,     3,   343,   344,   345,   170,   130,     9,    15,
     158,   160,     3,   160,   160,   160,   160,   651,     9,   160,
     160,   160,   160,   146,   160,   651,   201,   160,    25,   160,
     160,   160,   160,    76,    94,    73,    83,   109,   181,   162,
     163,   101,   394,   273,    48,   397,    48,   399,   861,    48,
     193,    88,    48,   176,   867,    48,   160,   232,    48,    48,
     132,    48,    48,    48,    48,    48,   104,    12,    48,    48,
      48,   194,    48,    41,    19,    20,    35,    25,    79,    25,
      81,   159,   422,   181,   391,   392,   124,   710,    79,    90,
      81,    25,   432,   126,    39,   435,   803,   437,   721,    90,
      68,   126,   157,   157,   684,    20,   157,    52,   181,   115,
     450,   794,   795,   160,   115,   928,   163,   160,   931,   753,
     193,   614,   718,    69,   115,   759,   466,   753,   165,   126,
      75,    33,   170,   759,   730,   731,    15,   950,    83,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   157,   494,   157,    20,   497,   157,   389,
     973,   157,   121,   393,   157,   978,    33,   157,   157,   982,
     157,   157,   157,   157,   157,    39,   249,   157,   157,   157,
     126,   157,   255,    35,   524,   130,    98,   527,    52,   529,
     878,    33,    94,    33,    33,   818,   819,   820,   821,   272,
      94,   146,   885,   109,   157,   154,    47,   119,   891,     9,
     163,    75,   123,   115,   140,   141,    68,   162,   163,    83,
      15,   115,   140,    23,   173,   170,   132,    94,   140,   141,
     864,   176,   462,   159,   868,   575,    24,   148,   864,   140,
     249,   159,   868,   169,    85,    86,   255,   159,   115,    34,
     114,   169,    94,    20,    94,    94,   596,   169,   159,   101,
      85,    86,    47,   272,   604,    53,   130,   178,   169,   121,
     610,    20,   612,   613,    26,   115,   115,   617,    26,    79,
     752,    81,   146,   195,    93,   625,   626,    72,    26,   409,
       9,    91,    80,   222,   223,   224,   225,    94,   162,   163,
      85,    86,    26,   112,    23,   535,    20,    21,   428,     4,
     430,   945,   176,   166,   167,   115,    11,    12,   115,   945,
      94,   250,    26,   111,    19,    20,   628,   115,   951,    24,
     194,    17,    27,   121,    29,    30,   202,   203,   204,   371,
     372,   115,    37,    38,    39,    40,   380,   381,   578,   178,
     160,    46,   181,    20,   694,    20,    51,    52,    53,    20,
      79,   701,    81,   703,   193,   705,   160,   597,   134,   135,
     136,    24,    91,   378,   379,    70,    71,   953,    26,    74,
      75,    76,    77,    78,   115,    80,    26,    82,    83,   384,
     385,   227,   228,   199,   200,     0,   115,   165,   199,   200,
      95,    96,   238,   239,   500,   501,   212,   213,   214,   165,
     640,   212,   213,   214,    48,   251,   111,   137,    31,   227,
     228,   241,   110,   367,   368,   369,   121,    42,   123,   179,
     238,   239,    43,   116,    48,   130,   776,    25,    48,   779,
      25,   781,   121,    89,   139,    24,   121,   142,   143,   789,
     160,   146,   160,   148,   149,    48,    15,   152,   153,    35,
     155,    35,   126,    15,    25,    48,    89,   162,   163,   164,
     810,   166,   167,   160,    18,   170,   160,   172,   115,   160,
     175,   176,   160,    33,   197,   217,   157,   217,   183,   101,
      24,   159,    76,    20,   115,    20,   191,    25,   115,   839,
      20,   196,   108,    76,    76,    76,   108,    76,   177,    25,
     101,    89,    89,    35,    76,    25,    24,    41,    76,    89,
      76,   157,     4,    24,    24,   755,    24,   165,   159,    11,
      12,    48,    26,   159,   874,   260,   876,    19,    20,   240,
     247,   160,    24,   248,   160,    27,   103,    29,    30,    26,
     103,   160,   160,   160,    26,    37,    38,    39,    40,   160,
     900,    26,   902,   793,    46,   108,   108,    48,    25,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   101,     7,    70,    71,
     165,    20,    74,    75,    76,    77,    78,   115,    80,   165,
      82,    83,    25,   157,   159,    47,    47,    33,   159,    76,
      92,   160,   108,    95,    96,   219,    98,    25,    84,    35,
      20,    20,   962,   105,   106,   107,   174,   159,   968,   111,
      26,    24,    35,    25,   256,    32,   174,   119,   174,   121,
      20,   123,   245,   125,   156,    33,   159,    26,   130,    76,
     245,   174,   115,   159,    26,    76,    26,   139,    76,    26,
     142,   143,    93,   160,   146,    93,   148,   149,   338,   757,
     152,   153,    96,   155,   419,   338,   123,   616,    97,   441,
     162,   163,   164,   696,   166,   167,   168,   347,   170,   344,
     172,   672,    69,   175,   176,   605,   694,   691,   180,   350,
     652,   183,   351,   148,   144,   811,   649,   373,   891,   191,
     470,   885,   385,    35,   196,    35,   198,   812,   430,   201,
     536,   731,   669,   205,   206,   207,   208,   209,   210,   211,
     718,   506,   537,     4,   216,   826,   218,   852,   220,   221,
      11,    12,    -1,    -1,    -1,   722,   719,    -1,    19,    20,
     232,    -1,    -1,    24,    -1,   730,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,   123,    -1,   125,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,   166,   167,   168,    -1,   170,
      -1,   172,    -1,    -1,   175,   176,    -1,    -1,    -1,   180,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,     4,   216,    -1,   218,    -1,   220,
     221,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,   232,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,
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
     149,    -1,    -1,   152,   153,    -1,   155,    -1,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
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
      -1,    -1,    -1,   160,    -1,   162,   163,   164,    -1,   166,
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
     152,   153,    -1,   155,    -1,   157,    -1,    -1,    -1,    -1,
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
      -1,    92,    -1,    -1,    95,    96,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,    -1,    -1,   146,    -1,   148,   149,
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,   164,    -1,   166,   167,    -1,    -1,
     170,    -1,   172,     4,    -1,   175,   176,    -1,    -1,    -1,
      11,    12,    -1,   183,    -1,    -1,    -1,    -1,    19,    20,
      -1,   191,    -1,    24,    -1,    -1,   196,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,    -1,    -1,   146,    -1,    -1,    -1,    -1,
      -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,    -1,     4,    -1,    -1,    -1,   170,
      -1,   172,    11,    12,   175,   176,    -1,    -1,    -1,    -1,
      19,    20,   183,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,   196,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
     139,    -1,    -1,   142,   143,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,    -1,    -1,   175,   176,   226,    -1,
      -1,   229,   230,   231,   183,   233,   234,   235,   236,   237,
      -1,    -1,    -1,    -1,    -1,   243,   244,   196,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
     258,   259,    -1,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   226,    -1,    -1,   229,   230,   231,
      -1,   233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    -1,   246,    -1,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,   257,   258,   259,    -1,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,   102,    -1,   230,   231,    -1,   233,   234,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,   244,
      -1,   246,    -1,   122,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,   257,    -1,    -1,    -1,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,   188,
     189,   190
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
     453,   115,    26,   331,   332,   333,   320,   230,   231,   233,
     234,   244,   246,   257,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   469,   470,   471,   472,   473,
     476,   481,   482,     0,   287,   288,   290,   318,   165,   165,
      48,   140,   141,   159,   169,   195,   323,   334,   335,   340,
     137,    31,    89,    97,   100,   102,   113,   117,   122,   128,
     151,   185,   186,   187,   188,   189,   190,   370,   371,   372,
     241,   123,   148,   178,    73,   104,   124,   170,   181,   193,
      93,   112,   110,   179,    42,    43,   123,   148,   369,   115,
     376,   166,   167,   116,   390,   391,   386,   390,   386,   390,
     157,   157,   160,   320,   401,   319,   157,    48,   160,    48,
     160,   157,    48,    48,    25,    25,   121,    89,    24,   121,
      33,    94,   101,   428,   157,   160,   160,   157,    48,   160,
      48,   160,   108,   428,    48,   161,    35,   108,   253,   327,
     328,   428,    48,   160,    35,    15,    35,   126,    15,    25,
     101,   328,   428,    48,   160,    89,   157,     8,   144,   160,
     160,    18,   115,   319,   160,   160,   161,    20,    87,   174,
     406,   407,   157,   160,   157,   157,   197,    88,   165,   199,
     200,   212,   213,   214,   199,   200,   212,   213,   214,    33,
     217,   217,   101,    48,   215,   320,    48,   221,   157,    24,
      93,   181,   477,   480,    35,   121,   478,    35,    68,   121,
     475,   292,   293,   294,   320,   320,   341,   342,    76,   336,
     337,   320,   341,   320,   159,   335,   340,   159,   340,   159,
     355,   356,   357,   357,   357,   115,   121,   242,   393,   458,
     460,   461,   462,   463,   464,   465,   466,   360,   360,   359,
     361,   361,   361,   361,   362,   362,   363,   363,    20,   114,
     194,   429,   431,   432,   433,   429,   427,   432,   427,   157,
     319,   378,   378,   319,   391,    48,   160,   157,   115,    20,
     443,   443,   109,   132,   109,   132,    76,   160,   314,   315,
      25,   160,   314,   429,   320,    94,   101,   115,    20,   443,
     444,   443,   444,   320,   108,    76,   320,    76,   320,    76,
     108,   328,   108,   108,   327,   328,    76,   177,    25,   308,
      89,   308,    89,    35,   320,   101,   101,   328,    76,    25,
     157,   319,   157,   320,    89,     9,    10,    44,    79,    81,
     115,   171,   316,   403,   405,   415,   416,   419,    87,   174,
     407,    41,   351,   352,    24,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,    76,
     320,   157,    76,   320,   478,   478,   480,    24,    24,   479,
     477,    24,    68,   475,   165,    34,    47,    72,    85,    86,
     343,   344,   345,   346,    48,    26,    48,   329,   334,   339,
     320,   159,   340,   159,   320,   159,   320,   319,   458,   464,
     260,   492,   138,   226,   229,   235,   236,   237,   243,   252,
     258,   259,   459,   467,   468,   469,   483,   486,   487,   489,
     240,   247,   248,   488,   222,   223,   224,   225,   250,   484,
     134,   135,   136,   430,   103,   157,   158,   320,   157,   319,
     160,   160,    26,    33,    94,   115,   317,    48,   160,    33,
      94,   317,   160,   320,   157,   319,   103,   160,   160,   160,
     160,   320,   349,    26,    26,   320,   108,   320,   320,   108,
     328,   108,   326,   320,    48,    25,   308,   320,   320,   101,
     332,   165,   157,   115,    32,   156,   408,     7,   319,    20,
     171,   415,   171,   405,    76,   429,    68,   352,   165,   453,
     159,   219,   455,   456,   333,   157,    24,   160,   227,   228,
     238,   239,   251,   485,    48,   160,    48,   160,    25,   345,
     346,   346,   342,    47,   338,   337,   329,   334,   320,   159,
     320,   320,   157,   160,   361,   249,   254,   491,   485,   461,
     491,   358,   361,   258,   467,   469,   462,   463,   485,   157,
     428,   429,   319,   315,    33,    94,   317,   429,    33,    94,
     317,   157,   320,   320,   108,   320,    84,    25,    35,   320,
     157,   319,     3,    90,   411,   412,   414,   416,    23,    91,
     409,   410,   413,   416,   157,   174,    20,    20,   171,    26,
     159,    76,   159,   320,   387,   456,   361,   361,   361,   361,
      24,   245,   474,   475,   474,   346,    25,   320,   249,   255,
     272,   490,   490,   358,   256,    94,   317,   157,   429,    94,
     317,   429,   320,   320,   308,   157,    32,    90,   414,   156,
      91,   413,   174,   174,    20,    33,   320,    26,   320,    48,
     160,   178,   485,    48,   160,   160,    94,   317,    94,   317,
     174,   429,   159,    76,   317,   361,   245,   475,   159,   320,
      26,   320,    48,   160,    76,   317,    26,    48,   160,    76,
     317,    26,   160,   317
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
     332,   332,   332,   333,   333,   334,   335,   335,   335,   335,
     336,   336,   337,   337,   338,   339,   339,   340,   340,   341,
     341,   342,   342,   343,   343,   343,   343,   343,   343,   343,
     344,   344,   345,   345,   346,   347,   347,   348,   348,   349,
     349,   350,   350,   351,   351,   352,   352,   353,   354,   354,
     355,   355,   356,   356,   356,   356,   357,   357,   357,   358,
     358,   359,   359,   359,   360,   360,   360,   360,   360,   361,
     361,   361,   362,   362,   362,   363,   363,   364,   364,   365,
     365,   366,   366,   367,   367,   368,   368,   368,   368,   369,
     369,   369,   370,   370,   370,   370,   370,   370,   371,   371,
     371,   371,   371,   371,   372,   372,   372,   373,   373,   374,
     374,   375,   375,   376,   376,   377,   377,   377,   377,   378,
     378,   378,   379,   379,   380,   380,   380,   380,   381,   381,
     382,   382,   382,   382,   382,   382,   382,   383,   383,   384,
     384,   385,   385,   385,   385,   385,   386,   386,   387,   387,
     388,   388,   388,   389,   389,   390,   390,   391,   392,   392,
     392,   392,   392,   392,   392,   392,   393,   393,   394,   394,
     394,   395,   396,   396,   397,   398,   399,   400,   400,   401,
     401,   402,   402,   403,   403,   403,   404,   404,   404,   404,
     404,   404,   405,   405,   406,   406,   407,   408,   408,   409,
     409,   410,   410,   410,   410,   411,   411,   412,   412,   412,
     412,   413,   413,   414,   414,   415,   415,   415,   415,   416,
     416,   416,   416,   417,   417,   418,   418,   419,   420,   420,
     420,   420,   420,   420,   421,   422,   422,   422,   422,   423,
     423,   423,   423,   424,   425,   426,   426,   426,   426,   427,
     427,   428,   429,   429,   429,   430,   430,   430,   431,   431,
     431,   432,   433,   433,   433,   433,   433,   433,   433,   433,
     433,   434,   435,   435,   435,   436,   437,   438,   438,   438,
     439,   439,   439,   439,   439,   440,   441,   441,   441,   441,
     441,   441,   441,   442,   443,   444,   445,   446,   446,   446,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     448,   448,   449,   449,   450,   451,   452,   452,   453,   454,
     455,   455,   456,   456,   456,   456,   457,   457,   458,   458,
     458,   458,   459,   459,   459,   459,   460,   460,   461,   461,
     462,   462,   463,   463,   464,   464,   464,   465,   465,   466,
     466,   467,   467,   467,   467,   467,   468,   469,   469,   469,
     469,   469,   469,   469,   470,   470,   470,   470,   471,   471,
     471,   471,   472,   472,   473,   473,   473,   473,   473,   473,
     473,   474,   474,   475,   475,   475,   475,   476,   476,   476,
     476,   476,   477,   477,   478,   478,   479,   479,   480,   480,
     481,   482,   482,   483,   483,   483,   484,   484,   484,   484,
     484,   485,   485,   485,   485,   486,   487,   488,   489,   489,
     490,   490,   490,   491,   491,   492
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
       4,     4,     5,     1,     1,     2,     2,     3,     3,     4,
       1,     3,     2,     3,     2,     1,     2,     2,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     1,     1,     2,     4,     4,     1,     4,     3,
       4,     7,     9,     1,     2,     4,     7,     7,     1,     3,
       1,     3,     1,     3,     3,     3,     1,     3,     4,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       4,     1,     2,     3,     2,     1,     2,     2,     1,     1,
       3,     3,     1,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     3,     3,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     3,     4,     6,     7,
       7,     8,     1,     2,     1,     2,     3,     3,     3,     0,
       1,     1,     1,     2,     2,     0,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     5,     6,     2,
       3,     5,     6,     3,     3,     4,     5,     6,     7,     1,
       2,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     2,     2,     2,     3,     3,
       2,     3,     5,     3,     5,     3,     2,     3,     5,     5,
       3,     5,     5,     3,     1,     2,     1,     2,     2,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       2,     2,     4,     4,     4,     6,     1,     4,     3,     5,
       1,     2,     4,     7,    10,    13,     5,     3,     1,     2,
       3,     4,     1,     1,     2,     2,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     2,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     6,     4,     6,
       1,     1,     3,     2,     4,     4,     6,     2,     3,     1,
       2,     1,     1,     2,     2,     3,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     4,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     2
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
     328,   101,   320,    -1,   332,    -1,    26,    -1,   195,   320,
      -1,   141,   336,    -1,   141,   336,   339,    -1,   141,   336,
     334,    -1,   141,   336,   339,   334,    -1,   337,    -1,   336,
      48,   337,    -1,    76,    26,    -1,    76,    26,   338,    -1,
      47,    25,    -1,   329,    -1,   339,   329,    -1,   140,   341,
      -1,   169,   341,    -1,   342,    -1,   341,    48,   342,    -1,
     320,    -1,   320,   343,    -1,   344,    -1,   345,    -1,   346,
      -1,   344,   345,    -1,   344,   346,    -1,   345,   346,    -1,
     344,   345,   346,    -1,    34,    -1,    72,    -1,    85,    -1,
      86,    -1,    47,    25,    -1,   168,   348,   161,   320,    -1,
      92,   348,   161,   320,    -1,   349,    -1,   348,    48,    76,
     349,    -1,    26,   108,   320,    -1,    26,   428,   108,   320,
      -1,   180,   319,   160,   351,    68,   159,   320,    -1,   180,
     319,   160,   351,    68,    76,    26,   159,   320,    -1,   352,
      -1,   351,   352,    -1,    41,   429,   159,   320,    -1,    41,
      76,    26,    33,   429,   159,   320,    -1,   105,   319,   160,
     177,   320,    84,   320,    -1,   355,    -1,   354,   137,   355,
      -1,   356,    -1,   355,    31,   356,    -1,   357,    -1,   357,
     371,   357,    -1,   357,   370,   357,    -1,   357,   372,   357,
      -1,   358,    -1,   358,   241,   458,    -1,   358,   241,   458,
     492,    -1,   359,    -1,   359,   178,   359,    -1,   360,    -1,
     359,   148,   360,    -1,   359,   123,   360,    -1,   361,    -1,
     360,   170,   361,    -1,   360,    73,   361,    -1,   360,   104,
     361,    -1,   360,   124,   361,    -1,   362,    -1,   361,   181,
     362,    -1,   361,   193,   362,    -1,   363,    -1,   362,   112,
     363,    -1,   362,    93,   363,    -1,   364,    -1,   364,   110,
     429,    -1,   365,    -1,   365,   179,   429,    -1,   366,    -1,
     366,    42,   427,    -1,   367,    -1,   367,    43,   427,    -1,
     369,    -1,   368,   369,    -1,   148,    -1,   123,    -1,   368,
     148,    -1,   368,   123,    -1,   373,    -1,   377,    -1,   374,
      -1,    89,    -1,   128,    -1,   122,    -1,   117,    -1,   102,
      -1,   100,    -1,   185,    -1,   190,    -1,   189,    -1,   188,
      -1,   187,    -1,   186,    -1,   113,    -1,   151,    -1,    97,
      -1,   191,   319,   157,    -1,    27,   115,   319,   157,    -1,
     375,   115,   157,    -1,   375,   115,   319,   157,    -1,   376,
      -1,   375,   376,    -1,   149,    20,    18,    -1,   149,    21,
      -1,   166,    -1,   166,   378,    -1,   167,   378,    -1,   378,
      -1,   379,    -1,   379,   166,   378,    -1,   379,   167,   378,
      -1,   380,    -1,   389,    -1,   381,    -1,   381,   390,    -1,
     384,    -1,   384,   390,    -1,   382,   386,    -1,   383,    -1,
      46,    -1,    70,    -1,    37,    -1,   164,    -1,    71,    -1,
      96,    -1,    95,    -1,   386,    -1,    40,   386,    -1,   385,
     386,    -1,    78,    -1,   142,    -1,    29,    -1,   153,    -1,
     152,    -1,    30,    -1,   433,    -1,   387,    -1,    20,    -1,
     388,    -1,   170,    -1,    12,    -1,    19,    -1,   392,    -1,
     392,   390,    -1,   391,    -1,   390,   391,    -1,   116,   319,
     158,    -1,   393,    -1,   395,    -1,   396,    -1,   397,    -1,
     400,    -1,   402,    -1,   398,    -1,   399,    -1,   394,    -1,
     445,    -1,    53,    -1,   111,    -1,    80,    -1,    76,    26,
      -1,   121,   160,    -1,   121,   319,   160,    -1,    77,    -1,
     139,   319,   157,    -1,   183,   319,   157,    -1,    20,   121,
     160,    -1,    20,   121,   401,   160,    -1,   320,    -1,   401,
      48,   320,    -1,   403,    -1,   420,    -1,   404,    -1,   417,
      -1,   418,    -1,   172,    20,    87,    -1,   172,    20,   406,
      87,    -1,   172,    20,   174,   171,    20,   174,    -1,   172,
      20,   174,   405,   171,    20,   174,    -1,   172,    20,   406,
     174,   171,    20,   174,    -1,   172,    20,   406,   174,   405,
     171,    20,   174,    -1,   415,    -1,   405,   415,    -1,   407,
      -1,   406,   407,    -1,    20,    89,   408,    -1,   156,   409,
     156,    -1,    32,   411,    32,    -1,    -1,   410,    -1,    91,
      -1,   413,    -1,   410,    91,    -1,   410,   413,    -1,    -1,
     412,    -1,    90,    -1,   414,    -1,   412,    90,    -1,   412,
     414,    -1,    23,    -1,   416,    -1,     3,    -1,   416,    -1,
     403,    -1,    10,    -1,   419,    -1,   416,    -1,     9,    -1,
      79,    -1,    81,    -1,   316,    -1,   196,    28,   197,    -1,
     196,   197,    -1,   143,    17,   144,    -1,   143,    17,     8,
      -1,    44,     7,    -1,   421,    -1,   422,    -1,   423,    -1,
     424,    -1,   425,    -1,   426,    -1,    74,   319,   157,    -1,
      11,   157,    -1,    11,   319,   157,    -1,    82,   319,   157,
     115,   157,    -1,    82,   319,   157,   115,   319,   157,    -1,
       4,   157,    -1,     4,   319,   157,    -1,    38,   319,   157,
     115,   157,    -1,    38,   319,   157,   115,   319,   157,    -1,
     175,   319,   157,    -1,    51,   319,   157,    -1,   155,    15,
     115,   157,    -1,   155,    15,   115,   319,   157,    -1,   155,
     115,   319,   157,   115,   157,    -1,   155,   115,   319,   157,
     115,   319,   157,    -1,   432,    -1,   432,   103,    -1,    33,
     429,    -1,   431,    -1,   431,   430,    -1,   194,    -1,   134,
      -1,   136,    -1,   135,    -1,   432,    -1,   433,    -1,   114,
      -1,    20,    -1,   435,    -1,   441,    -1,   439,    -1,   442,
      -1,   440,    -1,   438,    -1,   437,    -1,   436,    -1,   434,
      -1,   130,   160,    -1,    75,   160,    -1,    75,   441,   160,
      -1,    75,   442,   160,    -1,   176,   160,    -1,    52,   160,
      -1,   146,   160,    -1,   146,    15,   160,    -1,   146,    24,
     160,    -1,    39,   160,    -1,    39,    20,   160,    -1,    39,
      20,    48,   443,   160,    -1,    39,   170,   160,    -1,    39,
     170,    48,   443,   160,    -1,   162,    20,   160,    -1,    83,
     160,    -1,    83,    20,   160,    -1,    83,    20,    48,   443,
     160,    -1,    83,    20,    48,   444,   160,    -1,    83,   170,
     160,    -1,    83,   170,    48,   443,   160,    -1,    83,   170,
      48,   444,   160,    -1,   163,    20,   160,    -1,    20,    -1,
      20,   103,    -1,    24,    -1,   201,   202,    -1,   201,   203,
      -1,   201,   204,    -1,   207,   320,   213,   320,    -1,   207,
     320,   212,   320,    -1,   207,   320,   214,   320,    -1,   207,
     320,   199,   320,    -1,   207,   320,   200,   320,    -1,   208,
     320,   213,   320,    -1,   208,   320,   212,   320,    -1,   208,
     320,   214,   320,    -1,   208,   320,   199,   320,    -1,   208,
     320,   200,   320,    -1,   205,   320,    -1,   206,   320,    -1,
     210,   320,   217,   320,    -1,   211,   320,   217,   320,    -1,
     209,   320,    33,   320,    -1,   216,   452,   215,   320,   159,
     320,    -1,   453,    -1,   452,    48,    76,   453,    -1,    26,
     101,   320,    -1,   218,   115,   320,   157,   455,    -1,   456,
      -1,   455,   456,    -1,   219,   387,   160,   317,    -1,   219,
     387,    48,    76,    26,   160,   317,    -1,   219,   387,    48,
      76,    26,    48,    76,    26,   160,   317,    -1,   219,   387,
      48,    76,    26,    48,    76,    26,    48,    76,    26,   160,
     317,    -1,   220,   331,   221,   320,   157,    -1,   221,   320,
     157,    -1,   460,    -1,   460,   459,    -1,   460,   258,   358,
      -1,   460,   459,   258,   358,    -1,   469,    -1,   467,    -1,
     459,   469,    -1,   459,   467,    -1,   461,    -1,   460,   243,
     461,    -1,   462,    -1,   461,   240,   462,    -1,   463,    -1,
     462,   247,   463,    -1,   464,    -1,   242,   464,    -1,   465,
      -1,   465,   488,    -1,   121,   458,   160,    -1,   466,    -1,
     466,   484,    -1,   393,    -1,   115,   319,   157,    -1,   468,
      -1,   487,    -1,   486,    -1,   489,    -1,   483,    -1,   138,
      -1,   470,    -1,   471,    -1,   472,    -1,   473,    -1,   476,
      -1,   481,    -1,   482,    -1,   246,    -1,   257,    -1,   231,
      -1,   230,    -1,   267,    -1,   261,    -1,   234,    -1,   233,
      -1,   268,    -1,   262,    -1,   270,   475,    -1,   270,    68,
      -1,   270,   121,   475,   160,    -1,   270,   121,   475,    48,
     474,   160,    -1,   270,   121,    68,   160,    -1,   270,   121,
      68,    48,   474,   160,    -1,   264,    -1,   475,    -1,   474,
      48,   475,    -1,    35,    24,    -1,    35,    24,   251,    24,
      -1,    35,    24,   485,   245,    -1,    35,    24,   251,    24,
     485,   245,    -1,   269,   478,    -1,   269,   478,   477,    -1,
     266,    -1,   266,   477,    -1,   263,    -1,   480,    -1,   477,
     480,    -1,    35,    24,    -1,   121,   479,   160,    -1,    24,
      -1,   479,    24,    -1,   181,   478,    -1,    93,   478,    -1,
     244,    24,    -1,   271,    -1,   265,    -1,   229,    -1,   226,
      -1,   237,    -1,   224,    -1,   225,    -1,   222,    -1,   223,
      -1,   250,    -1,   238,   361,    -1,   227,   361,    -1,   228,
     361,    -1,   239,   361,   178,   361,    -1,   236,   485,   490,
      -1,   259,   361,   490,    -1,   248,   485,   256,    -1,   252,
     491,    -1,   235,   491,    -1,   272,    -1,   255,    -1,   249,
      -1,   254,    -1,   249,    -1,   260,   361,    -1
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
     548,   553,   558,   564,   566,   568,   571,   574,   578,   582,
     587,   589,   593,   596,   600,   603,   605,   608,   611,   614,
     616,   620,   622,   625,   627,   629,   631,   634,   637,   640,
     644,   646,   648,   650,   652,   655,   660,   665,   667,   672,
     676,   681,   689,   699,   701,   704,   709,   717,   725,   727,
     731,   733,   737,   739,   743,   747,   751,   753,   757,   762,
     764,   768,   770,   774,   778,   780,   784,   788,   792,   796,
     798,   802,   806,   808,   812,   816,   818,   822,   824,   828,
     830,   834,   836,   840,   842,   845,   847,   849,   852,   855,
     857,   859,   861,   863,   865,   867,   869,   871,   873,   875,
     877,   879,   881,   883,   885,   887,   889,   891,   895,   900,
     904,   909,   911,   914,   918,   921,   923,   926,   929,   931,
     933,   937,   941,   943,   945,   947,   950,   952,   955,   958,
     960,   962,   964,   966,   968,   970,   972,   974,   976,   979,
     982,   984,   986,   988,   990,   992,   994,   996,   998,  1000,
    1002,  1004,  1006,  1008,  1010,  1013,  1015,  1018,  1022,  1024,
    1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,  1042,  1044,
    1046,  1048,  1051,  1054,  1058,  1060,  1064,  1068,  1072,  1077,
    1079,  1083,  1085,  1087,  1089,  1091,  1093,  1097,  1102,  1109,
    1117,  1125,  1134,  1136,  1139,  1141,  1144,  1148,  1152,  1156,
    1157,  1159,  1161,  1163,  1166,  1169,  1170,  1172,  1174,  1176,
    1179,  1182,  1184,  1186,  1188,  1190,  1192,  1194,  1196,  1198,
    1200,  1202,  1204,  1206,  1210,  1213,  1217,  1221,  1224,  1226,
    1228,  1230,  1232,  1234,  1236,  1240,  1243,  1247,  1253,  1260,
    1263,  1267,  1273,  1280,  1284,  1288,  1293,  1299,  1306,  1314,
    1316,  1319,  1322,  1324,  1327,  1329,  1331,  1333,  1335,  1337,
    1339,  1341,  1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,
    1359,  1361,  1364,  1367,  1371,  1375,  1378,  1381,  1384,  1388,
    1392,  1395,  1399,  1405,  1409,  1415,  1419,  1422,  1426,  1432,
    1438,  1442,  1448,  1454,  1458,  1460,  1463,  1465,  1468,  1471,
    1474,  1479,  1484,  1489,  1494,  1499,  1504,  1509,  1514,  1519,
    1524,  1527,  1530,  1535,  1540,  1545,  1552,  1554,  1559,  1563,
    1569,  1571,  1574,  1579,  1587,  1598,  1612,  1618,  1622,  1624,
    1627,  1631,  1636,  1638,  1640,  1643,  1646,  1648,  1652,  1654,
    1658,  1660,  1664,  1666,  1669,  1671,  1674,  1678,  1680,  1683,
    1685,  1689,  1691,  1693,  1695,  1697,  1699,  1701,  1703,  1705,
    1707,  1709,  1711,  1713,  1715,  1717,  1719,  1721,  1723,  1725,
    1727,  1729,  1731,  1733,  1735,  1738,  1741,  1746,  1753,  1758,
    1765,  1767,  1769,  1773,  1776,  1781,  1786,  1793,  1796,  1800,
    1802,  1805,  1807,  1809,  1812,  1815,  1819,  1821,  1824,  1827,
    1830,  1833,  1835,  1837,  1839,  1841,  1843,  1845,  1847,  1849,
    1851,  1853,  1856,  1859,  1862,  1867,  1871,  1875,  1879,  1882,
    1885,  1887,  1889,  1891,  1893,  1895
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   773,   773,   781,   790,   797,   811,   819,   832,   842,
     857,   872,   887,   896,   905,   920,   929,   946,   955,   972,
     979,   986,   993,  1005,  1012,  1019,  1028,  1041,  1048,  1055,
    1062,  1069,  1076,  1083,  1092,  1105,  1112,  1130,  1145,  1153,
    1167,  1176,  1191,  1207,  1221,  1229,  1244,  1252,  1266,  1275,
    1284,  1293,  1315,  1329,  1343,  1353,  1363,  1373,  1389,  1398,
    1416,  1423,  1436,  1445,  1455,  1464,  1481,  1491,  1501,  1511,
    1527,  1535,  1549,  1559,  1570,  1581,  1593,  1605,  1617,  1629,
    1641,  1651,  1662,  1673,  1685,  1697,  1709,  1721,  1739,  1750,
    1767,  1776,  1791,  1802,  1816,  1830,  1839,  1854,  1861,  1868,
    1875,  1882,  1891,  1898,  1905,  1912,  1919,  1926,  1933,  1943,
    1953,  1964,  1975,  1987,  2002,  2017,  2032,  2053,  2062,  2077,
    2084,  2097,  2111,  2120,  2137,  2147,  2158,  2170,  2183,  2194,
    2206,  2218,  2236,  2251,  2265,  2280,  2289,  2304,  2313,  2330,
    2341,  2353,  2364,  2379,  2384,  2399,  2410,  2420,  2430,  2440,
    2453,  2462,  2476,  2485,  2497,  2507,  2517,  2532,  2540,  2555,
    2564,  2581,  2590,  2605,  2615,  2625,  2635,  2645,  2655,  2665,
    2681,  2688,  2701,  2709,  2723,  2737,  2747,  2763,  2773,  2788,
    2797,  2813,  2823,  2840,  2849,  2864,  2873,  2889,  2903,  2910,
    2924,  2931,  2953,  2960,  2971,  2982,  2999,  3006,  3016,  3032,
    3039,  3053,  3060,  3067,  3080,  3087,  3094,  3101,  3108,  3121,
    3128,  3136,  3150,  3157,  3164,  3177,  3184,  3199,  3206,  3221,
    3228,  3243,  3250,  3265,  3272,  3287,  3294,  3301,  3308,  3323,
    3330,  3337,  3351,  3358,  3365,  3372,  3379,  3386,  3399,  3406,
    3413,  3420,  3427,  3434,  3447,  3454,  3461,  3475,  3482,  3497,
    3506,  3521,  3530,  3547,  3556,  3598,  3605,  3612,  3619,  3635,
    3649,  3657,  3670,  3677,  3690,  3699,  3708,  3717,  3732,  3741,
    3755,  3762,  3769,  3776,  3783,  3790,  3797,  3810,  3817,  3830,
    3839,  3854,  3861,  3868,  3875,  3882,  3900,  3907,  3920,  3927,
    3940,  3950,  3960,  3976,  3983,  3998,  4007,  4024,  4038,  4045,
    4052,  4059,  4066,  4073,  4080,  4087,  4100,  4107,  4120,  4128,
    4136,  4150,  4163,  4170,  4184,  4197,  4211,  4270,  4279,  4294,
    4303,  4318,  4325,  4338,  4345,  4352,  4365,  4376,  4387,  4398,
    4409,  4420,  4438,  4447,  4462,  4471,  4488,  4503,  4511,  4526,
    4532,  4539,  4548,  4557,  4568,  4586,  4592,  4599,  4608,  4617,
    4628,  4645,  4653,  4667,  4675,  4689,  4697,  4705,  4714,  4729,
    4738,  4746,  4754,  4768,  4776,  4794,  4802,  4822,  4840,  4847,
    4854,  4861,  4868,  4875,  4888,  4902,  4911,  4920,  4928,  4956,
    4965,  4974,  4982,  4996,  5010,  5024,  5033,  5042,  5050,  5064,
    5073,  5088,  5102,  5111,  5120,  5160,  5168,  5176,  5190,  5197,
    5204,  5217,  5231,  5238,  5245,  5252,  5259,  5266,  5273,  5280,
    5287,  5300,  5313,  5320,  5328,  5342,  5355,  5368,  5375,  5382,
    5395,  5404,  5413,  5422,  5431,  5446,  5460,  5469,  5478,  5487,
    5496,  5506,  5516,  5532,  5556,  5566,  5589,  5632,  5640,  5646,
    5657,  5666,  5675,  5684,  5693,  5703,  5712,  5721,  5730,  5739,
    5754,  5762,  5775,  5784,  5799,  5828,  5842,  5851,  5867,  5884,
    5894,  5904,  5918,  5928,  5939,  5951,  5973,  5979,  5996,  6002,
    6008,  6014,  6026,  6032,  6038,  6044,  6056,  6062,  6074,  6080,
    6092,  6098,  6110,  6116,  6128,  6134,  6140,  6152,  6158,  6170,
    6176,  6188,  6194,  6200,  6206,  6212,  6224,  6236,  6243,  6250,
    6257,  6264,  6271,  6278,  6291,  6297,  6303,  6309,  6321,  6327,
    6333,  6339,  6351,  6357,  6369,  6375,  6381,  6387,  6393,  6399,
    6405,  6417,  6423,  6435,  6441,  6447,  6453,  6465,  6471,  6477,
    6483,  6489,  6501,  6507,  6519,  6525,  6537,  6543,  6555,  6561,
    6573,  6585,  6591,  6603,  6609,  6615,  6627,  6633,  6639,  6645,
    6651,  6663,  6670,  6677,  6684,  6697,  6709,  6721,  6733,  6739,
    6751,  6757,  6763,  6775,  6781,  6793
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
  const int xquery_parser::yylast_ = 4011;
  const int xquery_parser::yynnts_ = 209;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 333;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 284;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 538;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 6803 "/home/muresan/Projects/zorba/src/compiler/parser/xquery_parser.y"



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

