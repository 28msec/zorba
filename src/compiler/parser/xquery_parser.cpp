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
#line 738 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 51 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"

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
#line 638 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).decval; };
#line 211 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 80: /* "\"'DOUBLE'\"" */
#line 637 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).dval; };
#line 216 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 111: /* "\"'INTEGER'\"" */
#line 636 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (*yyvaluep).ival; };
#line 221 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 286: /* "VersionDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 226 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 287: /* "MainModule" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 231 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 288: /* "LibraryModule" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 236 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 289: /* "ModuleDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 241 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 290: /* "Prolog" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 246 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 291: /* "SIND_DeclList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 251 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 292: /* "VFO_DeclList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 256 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 293: /* "SIND_Decl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 261 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 294: /* "VFO_Decl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 266 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 295: /* "Setter" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 271 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 296: /* "Import" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 276 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 297: /* "NamespaceDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 281 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "BoundarySpaceDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 286 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "DefaultNamespaceDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 291 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "OptionDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 296 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "OrderingModeDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 301 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "EmptyOrderDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 306 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "CopyNamespacesDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 311 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "DefaultCollationDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 316 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "BaseURIDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 321 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "SchemaImport" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 326 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "URILiteralList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 331 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "SchemaPrefix" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 336 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "ModuleImport" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 341 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "VarDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 346 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "ConstructionDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 351 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "FunctionDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 356 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "ParamList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 361 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Param" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 366 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "EnclosedExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 371 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "NonNodeEnclosedExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 376 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "QueryBody" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 381 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "Expr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 386 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ExprSingle" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 391 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "FLWORExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 396 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "ForLetClauseList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 401 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "ForLetClause" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 406 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "ForClause" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 411 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VarInDeclList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 416 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VarInDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 421 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "PositionalVar" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 426 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "LetClause" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 431 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "VarGetsDeclList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 436 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "EvalVarDeclList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 441 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VarGetsDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 446 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "EvalVarDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 451 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "WhereClause" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 456 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "GroupByClause" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 461 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "GroupSpecList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 466 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "GroupSpec" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 471 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "GroupCollationSpec" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 476 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "LetClauseList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 481 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderByClause" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 486 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "OrderSpecList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 491 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "OrderSpec" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 496 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "OrderModifier" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 501 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "OrderDirSpec" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 506 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "OrderEmptySpec" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 511 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderCollationSpec" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 516 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "QuantifiedExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 521 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "QVarInDeclList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 526 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "QVarInDecl" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 531 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "TypeswitchExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 536 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CaseClauseList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 541 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CaseClause" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 546 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "IfExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 551 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "OrExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 556 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "AndExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 561 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ComparisonExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 566 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "RangeExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 571 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "AdditiveExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 576 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "MultiplicativeExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 581 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "UnionExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 586 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IntersectExceptExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 591 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "InstanceofExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 596 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "TreatExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 601 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CastableExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 606 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CastExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 611 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "UnaryExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 616 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "SignList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 621 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ValueExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 626 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "GeneralComp" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 631 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ValueComp" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 636 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "NodeComp" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 641 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ValidateExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 646 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ExtensionExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 651 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "PragmaList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 656 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "Pragma" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 661 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "PathExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 666 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "RelativePathExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 671 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "StepExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 676 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "AxisStep" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 681 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ForwardStep" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 686 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ForwardAxis" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 691 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "AbbrevForwardStep" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 696 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ReverseStep" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 701 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "ReverseAxis" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 706 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "NodeTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 711 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "NameTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 716 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "Wildcard" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 721 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FilterExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 726 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "PredicateList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 731 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Predicate" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 736 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "PrimaryExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 741 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Literal" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 746 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "NumericLiteral" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 751 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "VarRef" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 756 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ParenthesizedExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 761 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ContextItemExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 766 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "OrderedExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 771 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "UnorderedExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 776 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "FunctionCall" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 781 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ArgList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 786 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "Constructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 791 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "DirectConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 796 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "DirElemConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 801 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "DirElemContentList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 806 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "DirAttributeList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 811 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "DirAttr" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 816 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "DirAttributeValue" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 821 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "Opt_QuoteAttrContentList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 826 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "QuoteAttrContentList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 831 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "Opt_AposAttrContentList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 836 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "AposAttrContentList" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 841 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "QuoteAttrValueContent" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 846 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "AposAttrValueContent" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 851 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "DirElemContent" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 856 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "CommonContent" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 861 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "DirCommentConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 866 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "DirPIConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 871 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "CDataSection" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 876 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "ComputedConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 881 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CompDocConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 886 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CompElemConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 891 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CompAttrConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 896 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "CompTextConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 901 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CompCommentConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 906 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CompPIConstructor" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 911 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "SingleType" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 916 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "TypeDeclaration" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 921 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SequenceType" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 926 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "OccurrenceIndicator" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 931 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ItemType" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 936 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "AtomicType" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 941 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "KindTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 946 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "AnyKindTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 951 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "DocumentTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 956 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "TextTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 961 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "CommentTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 966 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "PITest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 971 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AttributeTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 976 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SchemaAttributeTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 981 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ElementTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 986 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "SchemaElementTest" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 991 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "TypeName" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 996 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "TypeName_WITH_HOOK" */
#line 642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->node)); };
#line 1001 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "StringLiteral" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1006 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "TryExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1011 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "CatchListExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1016 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "CatchExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1021 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "EvalExpr" */
#line 643 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
	{ RCHelper::removeReference ((yyvaluep->expr)); };
#line 1026 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
    #line 69 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename.getStore()->str());
}
  /* Line 547 of yacc.c.  */
#line 1107 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
#line 759 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		;}
    break;

  case 3:
#line 767 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 776 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 5:
#line 783 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]" << endl;
#endif
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		;}
    break;

  case 6:
#line 796 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]" << endl;
#endif
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), encoding);
		;}
    break;

  case 7:
#line 804 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]" << endl;
#endif
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (2)].sval)), SYMTAB ((yysemantic_stack_[(5) - (4)].sval)));
    ;}
    break;

  case 8:
#line 817 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 827 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 842 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 857 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 872 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 881 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 890 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 905 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 914 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 931 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 940 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 957 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 20:
#line 964 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 21:
#line 971 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 22:
#line 978 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 23:
#line 990 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 24:
#line 997 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 25:
#line 1004 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 26:
#line 1013 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 27:
#line 1026 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 28:
#line 1033 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 29:
#line 1040 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 30:
#line 1047 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 31:
#line 1054 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 32:
#line 1061 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 33:
#line 1068 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 34:
#line 1077 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 35:
#line 1090 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 36:
#line 1097 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 37:
#line 1115 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1130 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		;}
    break;

  case 39:
#line 1138 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]" << endl;
#endif
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		;}
    break;

  case 40:
#line 1152 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1161 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1176 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1192 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]" << endl;
#endif
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].node));
		;}
    break;

  case 44:
#line 1206 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		;}
    break;

  case 45:
#line 1214 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]" << endl;
#endif
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		;}
    break;

  case 46:
#line 1229 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 47:
#line 1237 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]" << endl;
#endif
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 48:
#line 1251 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1260 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1269 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1278 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1300 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]" << endl;
#endif
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 53:
#line 1314 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]" << endl;
#endif
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 54:
#line 1328 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1338 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1348 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1358 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1374 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1383 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1401 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 61:
#line 1408 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]" << endl;
#endif
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		;}
    break;

  case 62:
#line 1421 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1430 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1440 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1449 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1466 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1476 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1486 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1496 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1512 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		;}
    break;

  case 71:
#line 1520 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]" << endl;
#endif
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		;}
    break;

  case 72:
#line 1534 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1544 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1555 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1566 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1578 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1590 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1602 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1614 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1626 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1636 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1647 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1658 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1670 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1682 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1694 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1706 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1724 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1735 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1752 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1761 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1776 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 93:
#line 1787 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NonNodeEnclosedExpr [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 94:
#line 1801 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]" << endl;
#endif
			(yyval.expr) = new QueryBody(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 95:
#line 1815 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1824 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1839 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 98:
#line 1846 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 99:
#line 1853 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 100:
#line 1860 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 101:
#line 1867 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 102:
#line 1876 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 103:
#line 1883 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 104:
#line 1890 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 105:
#line 1897 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 106:
#line 1904 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 107:
#line 1911 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
      cout << "ExprSingle [TryExpr]" << endl;
#endif
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 108:
#line 1918 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    ;}
    break;

  case 109:
#line 1928 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1938 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1949 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1960 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1972 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1987 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2002 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2017 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2038 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2047 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2062 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 120:
#line 2069 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 121:
#line 2082 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]" << endl;
#endif
			(yyval.node) = new ForClause(LOC ((yyloc)),
								dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 122:
#line 2096 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2105 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2122 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2132 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2143 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2155 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2168 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2179 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2191 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2203 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2221 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]" << endl;
#endif
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 133:
#line 2236 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]" << endl;
#endif
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (3)].sval)));
		;}
    break;

  case 134:
#line 2250 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]" << endl;
#endif
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)));
			
		;}
    break;

  case 135:
#line 2265 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2274 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2289 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2298 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2315 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2326 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2338 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2349 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2364 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    ;}
    break;

  case 144:
#line 2368 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = driver.symtab.get ((off_t)(yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name));
                           
    ;}
    break;

  case 145:
#line 2382 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]" << endl;
#endif
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 146:
#line 2393 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2403 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2413 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2423 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2436 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2445 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2459 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2468 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2480 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GroupCollationSpec [ ]" << endl;
#endif
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
    ;}
    break;

  case 155:
#line 2490 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2500 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2515 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]" << endl;
#endif
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 158:
#line 2523 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2538 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2547 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2564 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2573 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2588 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2598 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2608 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2618 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2628 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2638 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2648 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2664 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		;}
    break;

  case 171:
#line 2671 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]" << endl;
#endif
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		;}
    break;

  case 172:
#line 2684 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		;}
    break;

  case 173:
#line 2692 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]" << endl;
#endif
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		;}
    break;

  case 174:
#line 2706 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]" << endl;
#endif
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 175:
#line 2720 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2730 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2746 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2756 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2771 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2780 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2796 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2806 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2823 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2832 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2847 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2856 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2872 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]" << endl;
#endif
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		;}
    break;

  case 188:
#line 2886 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 189:
#line 2893 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]" << endl;
#endif
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 190:
#line 2907 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 191:
#line 2914 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]" << endl;
#endif
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 192:
#line 2936 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 193:
#line 2943 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2954 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2965 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2982 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 197:
#line 2989 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2999 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3015 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 200:
#line 3022 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]" << endl;
#endif
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 201:
#line 3036 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 202:
#line 3043 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 203:
#line 3050 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]" << endl;
#endif
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 204:
#line 3063 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 205:
#line 3070 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 206:
#line 3077 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 207:
#line 3084 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 208:
#line 3091 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]" << endl;
#endif
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 209:
#line 3104 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 210:
#line 3111 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 211:
#line 3119 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]" << endl;
#endif
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 212:
#line 3133 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 213:
#line 3140 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 214:
#line 3147 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]" << endl;
#endif
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 215:
#line 3160 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 216:
#line 3167 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3182 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 218:
#line 3189 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3204 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 220:
#line 3211 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3226 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 222:
#line 3233 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3248 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 224:
#line 3255 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3270 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		;}
    break;

  case 226:
#line 3277 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]" << endl;
#endif
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		;}
    break;

  case 227:
#line 3284 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		;}
    break;

  case 228:
#line 3291 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3306 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 230:
#line 3313 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 231:
#line 3320 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 232:
#line 3334 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq);
		;}
    break;

  case 233:
#line 3341 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne);
		;}
    break;

  case 234:
#line 3348 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt);
		;}
    break;

  case 235:
#line 3355 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_le);
		;}
    break;

  case 236:
#line 3362 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt);
		;}
    break;

  case 237:
#line 3369 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]" << endl;
#endif
			(yyval.node) = new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge);
		;}
    break;

  case 238:
#line 3382 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		;}
    break;

  case 239:
#line 3389 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		;}
    break;

  case 240:
#line 3396 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		;}
    break;

  case 241:
#line 3403 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		;}
    break;

  case 242:
#line 3410 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		;}
    break;

  case 243:
#line 3417 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]" << endl;
#endif
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		;}
    break;

  case 244:
#line 3430 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		;}
    break;

  case 245:
#line 3437 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		;}
    break;

  case 246:
#line 3444 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]" << endl;
#endif
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		;}
    break;

  case 247:
#line 3458 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]" << endl;
#endif
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 248:
#line 3465 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3480 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3489 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3504 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3513 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3530 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3538 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval))),
								"");      
    ;}
    break;

  case 255:
#line 3581 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		;}
    break;

  case 256:
#line 3588 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 257:
#line 3595 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]" << endl;
#endif
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 258:
#line 3602 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3618 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3632 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 261:
#line 3640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]" << endl;
#endif
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		;}
    break;

  case 262:
#line 3653 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 263:
#line 3660 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 264:
#line 3673 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3682 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3691 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3700 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3715 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3724 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]" << endl;
#endif
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 270:
#line 3738 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		;}
    break;

  case 271:
#line 3745 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		;}
    break;

  case 272:
#line 3752 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		;}
    break;

  case 273:
#line 3759 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		;}
    break;

  case 274:
#line 3766 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		;}
    break;

  case 275:
#line 3773 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		;}
    break;

  case 276:
#line 3780 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]" << endl;
#endif
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		;}
    break;

  case 277:
#line 3793 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node));
		;}
    break;

  case 278:
#line 3800 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]" << endl;
#endif
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		;}
    break;

  case 279:
#line 3813 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3822 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3837 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		;}
    break;

  case 282:
#line 3844 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		;}
    break;

  case 283:
#line 3851 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		;}
    break;

  case 284:
#line 3858 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		;}
    break;

  case 285:
#line 3865 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]" << endl;
#endif
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		;}
    break;

  case 286:
#line 3883 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 287:
#line 3890 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 288:
#line 3903 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 289:
#line 3910 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]" << endl;
#endif
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		;}
    break;

  case 290:
#line 3923 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3933 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3943 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3959 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]" << endl;
#endif
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 294:
#line 3966 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3981 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3990 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4007 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		;}
    break;

  case 298:
#line 4021 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 299:
#line 4028 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 300:
#line 4035 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 301:
#line 4042 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 302:
#line 4049 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 303:
#line 4056 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 304:
#line 4063 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 305:
#line 4070 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 306:
#line 4083 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 307:
#line 4090 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 308:
#line 4103 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.decval);
      delete yylval.decval;
		;}
    break;

  case 309:
#line 4111 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.ival);
      delete yylval.ival;
		;}
    break;

  case 310:
#line 4119 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]" << endl;
#endif
			(yyval.expr) = new NumericLiteral(LOC ((yyloc)), *yylval.dval);
      delete yylval.dval;
		;}
    break;

  case 311:
#line 4133 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]" << endl;
#endif
			(yyval.expr) = new VarRef(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 312:
#line 4146 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		;}
    break;

  case 313:
#line 4153 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]" << endl;
#endif
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 314:
#line 4167 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]" << endl;
#endif
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		;}
    break;

  case 315:
#line 4180 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 316:
#line 4194 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]" << endl;
#endif
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 317:
#line 4253 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4262 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4277 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4286 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4301 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 322:
#line 4308 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 323:
#line 4321 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 324:
#line 4328 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 325:
#line 4335 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 326:
#line 4348 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4359 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4370 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4381 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4392 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4403 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4421 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4430 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4445 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4454 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4471 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4486 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 338:
#line 4494 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]" << endl;
#endif
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 339:
#line 4508 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]" << endl;
#endif
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 340:
#line 4515 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 341:
#line 4522 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4531 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4540 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4551 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4568 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']" << endl;
#endif
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		;}
    break;

  case 346:
#line 4575 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 347:
#line 4582 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4591 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4600 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4611 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4628 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 352:
#line 4636 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 353:
#line 4650 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 354:
#line 4658 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]" << endl;
#endif
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 355:
#line 4672 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		;}
    break;

  case 356:
#line 4680 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]" << endl;
#endif
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 357:
#line 4688 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4697 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4712 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4721 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		;}
    break;

  case 361:
#line 4729 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		;}
    break;

  case 362:
#line 4737 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]" << endl;
#endif
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		;}
    break;

  case 363:
#line 4751 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]" << endl;
#endif
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 364:
#line 4759 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "DirCommentConstructor [ ]" << endl;
#endif
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    ;}
    break;

  case 365:
#line 4777 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 366:
#line 4785 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4805 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]" << endl;
#endif
			(yyval.expr) = new CDataSection(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(2) - (2)].sval)));
		;}
    break;

  case 368:
#line 4823 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 369:
#line 4830 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 370:
#line 4837 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 371:
#line 4844 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 372:
#line 4851 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 373:
#line 4858 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]" << endl;
#endif
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		;}
    break;

  case 374:
#line 4871 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]" << endl;
#endif
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		;}
    break;

  case 375:
#line 4885 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4894 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4903 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 378:
#line 4911 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]" << endl;
#endif
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 379:
#line 4939 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4948 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4957 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr), NULL);
		;}
    break;

  case 382:
#line 4965 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]" << endl;
#endif
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (2)].expr), (yysemantic_stack_[(6) - (5)].expr));
		;}
    break;

  case 383:
#line 4979 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 384:
#line 4993 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]" << endl;
#endif
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)),
								dynamic_cast<Expr*>((yysemantic_stack_[(3) - (2)].expr)));
		;}
    break;

  case 385:
#line 5007 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5016 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5025 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		;}
    break;

  case 388:
#line 5033 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]" << endl;
#endif
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		;}
    break;

  case 389:
#line 5047 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5056 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5071 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]" << endl;
#endif
			(yyval.node) = new TypeDeclaration(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
		;}
    break;

  case 392:
#line 5085 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5094 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5103 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]" << endl;
#endif
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		;}
    break;

  case 395:
#line 5143 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		;}
    break;

  case 396:
#line 5151 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		;}
    break;

  case 397:
#line 5159 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]" << endl;
#endif
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		;}
    break;

  case 398:
#line 5173 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 399:
#line 5180 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 400:
#line 5187 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]" << endl;
#endif
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		;}
    break;

  case 401:
#line 5200 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]" << endl;
#endif
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 402:
#line 5214 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 403:
#line 5221 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 404:
#line 5228 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 405:
#line 5235 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 406:
#line 5242 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 407:
#line 5249 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 408:
#line 5256 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 409:
#line 5263 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 410:
#line 5270 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 411:
#line 5283 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]" << endl;
#endif
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		;}
    break;

  case 412:
#line 5296 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		;}
    break;

  case 413:
#line 5303 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 414:
#line 5311 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]" << endl;
#endif
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(3) - (2)].node)));
		;}
    break;

  case 415:
#line 5325 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]" << endl;
#endif
			(yyval.node) = new TextTest(LOC ((yyloc)));
		;}
    break;

  case 416:
#line 5338 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]" << endl;
#endif
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		;}
    break;

  case 417:
#line 5351 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		;}
    break;

  case 418:
#line 5358 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 419:
#line 5365 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]" << endl;
#endif
			(yyval.node) = new PITest(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval)));
		;}
    break;

  case 420:
#line 5378 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5387 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5396 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5405 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5414 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5429 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 426:
#line 5443 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5452 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5461 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5470 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5479 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5489 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5499 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5515 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]" << endl;
#endif
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(3) - (2)].sval))));
		;}
    break;

  case 434:
#line 5539 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]" << endl;
#endif
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval))));
		;}
    break;

  case 435:
#line 5549 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5572 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]" << endl;
#endif
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(1) - (1)].sval)));
		;}
    break;

  case 437:
#line 5615 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [strict]" << endl;
#endif
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		;}
    break;

  case 438:
#line 5623 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [lax]" << endl;
#endif
    ;}
    break;

  case 439:
#line 5629 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [skip]" << endl;
#endif
    ;}
    break;

  case 440:
#line 5640 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5649 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 442:
#line 5658 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodeExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 443:
#line 5667 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5676 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5686 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5695 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_first]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 447:
#line 5704 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertNodesExpr [expr.as_last]" << endl;
#endif
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(5) - (2)].expr), (yysemantic_stack_[(5) - (5)].expr));
		;}
    break;

  case 448:
#line 5713 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5722 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5737 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodeExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 451:
#line 5745 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteNodesExpr [expr]" << endl;
#endif
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 452:
#line 5758 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5767 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5782 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]" << endl;
#endif
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 455:
#line 5811 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]" << endl;
#endif
      VarNameList* lList = dynamic_cast<VarNameList*>((yysemantic_stack_[(6) - (2)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(6) - (4)].expr), (yysemantic_stack_[(6) - (6)].expr));
		;}
    break;

  case 456:
#line 5825 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5834 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5850 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
       cout << "VarNameDecl [" << driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)) << "]" << endl;
#endif
       (yyval.expr) = new VarBinding(LOC((yyloc)), driver.symtab.get((off_t)(yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    ;}
    break;

  case 459:
#line 5867 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TryExpr []" << endl;
#endif
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    ;}
    break;

  case 460:
#line 5877 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5887 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5901 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5911 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CatchExpr [NameTest,VarName]" << endl;
#endif
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          static_cast<NameTest*>((yysemantic_stack_[(7) - (2)].node)),
                          driver.symtab.get((off_t)(yysemantic_stack_[(7) - (5)].sval)),
                          (yysemantic_stack_[(7) - (7)].expr));
    ;}
    break;

  case 464:
#line 5931 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(5) - (2)].node)),
                          (yysemantic_stack_[(5) - (4)].expr));
    ;}
    break;

  case 465:
#line 5937 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(3) - (2)].expr));
    ;}
    break;

  case 466:
#line 5954 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]" << endl;
#endif
		;}
    break;

  case 467:
#line 5960 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]" << endl;
#endif
		;}
    break;

  case 468:
#line 5966 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]" << endl;
#endif
		;}
    break;

  case 469:
#line 5972 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]" << endl;
#endif
		;}
    break;

  case 470:
#line 5984 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]" << endl;
#endif
		;}
    break;

  case 471:
#line 5990 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]" << endl;
#endif
		;}
    break;

  case 472:
#line 5996 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]" << endl;
#endif
		;}
    break;

  case 473:
#line 6002 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]" << endl;
#endif
		;}
    break;

  case 474:
#line 6014 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]" << endl;
#endif
		;}
    break;

  case 475:
#line 6020 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]" << endl;
#endif
		;}
    break;

  case 476:
#line 6032 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]" << endl;
#endif
		;}
    break;

  case 477:
#line 6038 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]" << endl;
#endif
		;}
    break;

  case 478:
#line 6050 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]" << endl;
#endif
		;}
    break;

  case 479:
#line 6056 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]" << endl;
#endif
		;}
    break;

  case 480:
#line 6068 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]" << endl;
#endif
		;}
    break;

  case 481:
#line 6074 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]" << endl;
#endif
		;}
    break;

  case 482:
#line 6086 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]" << endl;
#endif
		;}
    break;

  case 483:
#line 6092 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]" << endl;
#endif
		;}
    break;

  case 484:
#line 6098 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]" << endl;
#endif
		;}
    break;

  case 485:
#line 6110 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]" << endl;
#endif
		;}
    break;

  case 486:
#line 6116 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]" << endl;
#endif
		;}
    break;

  case 487:
#line 6128 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]" << endl;
#endif
		;}
    break;

  case 488:
#line 6134 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]" << endl;
#endif
		;}
    break;

  case 489:
#line 6146 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]" << endl;
#endif
		;}
    break;

  case 490:
#line 6152 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]" << endl;
#endif
		;}
    break;

  case 491:
#line 6158 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]" << endl;
#endif
		;}
    break;

  case 492:
#line 6164 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]" << endl;
#endif
		;}
    break;

  case 493:
#line 6170 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]" << endl;
#endif
		;}
    break;

  case 494:
#line 6182 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]" << endl;
#endif
		;}
    break;

  case 495:
#line 6194 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 496:
#line 6201 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 497:
#line 6208 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 498:
#line 6215 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 499:
#line 6222 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 500:
#line 6229 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 501:
#line 6236 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]" << endl;
#endif
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		;}
    break;

  case 502:
#line 6249 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]" << endl;
#endif
		;}
    break;

  case 503:
#line 6255 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]" << endl;
#endif
		;}
    break;

  case 504:
#line 6261 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]" << endl;
#endif
		;}
    break;

  case 505:
#line 6267 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]" << endl;
#endif
		;}
    break;

  case 506:
#line 6279 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]" << endl;
#endif
		;}
    break;

  case 507:
#line 6285 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]" << endl;
#endif
		;}
    break;

  case 508:
#line 6291 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]" << endl;
#endif
		;}
    break;

  case 509:
#line 6297 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]" << endl;
#endif
		;}
    break;

  case 510:
#line 6309 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]" << endl;
#endif
		;}
    break;

  case 511:
#line 6315 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]" << endl;
#endif
		;}
    break;

  case 512:
#line 6327 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]" << endl;
#endif
		;}
    break;

  case 513:
#line 6333 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]" << endl;
#endif
		;}
    break;

  case 514:
#line 6339 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]" << endl;
#endif
		;}
    break;

  case 515:
#line 6345 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]" << endl;
#endif
		;}
    break;

  case 516:
#line 6351 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]" << endl;
#endif
		;}
    break;

  case 517:
#line 6357 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]" << endl;
#endif
		;}
    break;

  case 518:
#line 6363 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]" << endl;
#endif
		;}
    break;

  case 519:
#line 6375 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]" << endl;
#endif
		;}
    break;

  case 520:
#line 6381 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]" << endl;
#endif
		;}
    break;

  case 521:
#line 6393 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]" << endl;
#endif
		;}
    break;

  case 522:
#line 6399 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]" << endl;
#endif
		;}
    break;

  case 523:
#line 6405 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]" << endl;
#endif
		;}
    break;

  case 524:
#line 6411 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]" << endl;
#endif
		;}
    break;

  case 525:
#line 6423 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]" << endl;
#endif
		;}
    break;

  case 526:
#line 6429 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]" << endl;
#endif
		;}
    break;

  case 527:
#line 6435 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]" << endl;
#endif
		;}
    break;

  case 528:
#line 6441 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]" << endl;
#endif
		;}
    break;

  case 529:
#line 6447 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]" << endl;
#endif
		;}
    break;

  case 530:
#line 6459 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 531:
#line 6465 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 532:
#line 6477 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]" << endl;
#endif
		;}
    break;

  case 533:
#line 6483 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]" << endl;
#endif
		;}
    break;

  case 534:
#line 6495 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]" << endl;
#endif
		;}
    break;

  case 535:
#line 6501 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]" << endl;
#endif
		;}
    break;

  case 536:
#line 6513 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]" << endl;
#endif
		;}
    break;

  case 537:
#line 6519 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]" << endl;
#endif
		;}
    break;

  case 538:
#line 6531 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]" << endl;
#endif
		;}
    break;

  case 539:
#line 6543 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]" << endl;
#endif
		;}
    break;

  case 540:
#line 6549 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]" << endl;
#endif
		;}
    break;

  case 541:
#line 6561 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]" << endl;
#endif
		;}
    break;

  case 542:
#line 6567 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]" << endl;
#endif
		;}
    break;

  case 543:
#line 6573 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]" << endl;
#endif
		;}
    break;

  case 544:
#line 6585 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]" << endl;
#endif
		;}
    break;

  case 545:
#line 6591 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]" << endl;
#endif
		;}
    break;

  case 546:
#line 6597 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]" << endl;
#endif
		;}
    break;

  case 547:
#line 6603 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]" << endl;
#endif
		;}
    break;

  case 548:
#line 6609 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]" << endl;
#endif
		;}
    break;

  case 549:
#line 6621 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 550:
#line 6628 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 551:
#line 6635 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(2) - (2)].expr));
		;}
    break;

  case 552:
#line 6642 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]" << endl;
#endif
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		;}
    break;

  case 553:
#line 6655 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]" << endl;
#endif
		;}
    break;

  case 554:
#line 6667 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]" << endl;
#endif
		;}
    break;

  case 555:
#line 6679 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]" << endl;
#endif
		;}
    break;

  case 556:
#line 6691 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]" << endl;
#endif
		;}
    break;

  case 557:
#line 6697 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]" << endl;
#endif
		;}
    break;

  case 558:
#line 6709 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]" << endl;
#endif
		;}
    break;

  case 559:
#line 6715 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]" << endl;
#endif
		;}
    break;

  case 560:
#line 6721 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 561:
#line 6733 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]" << endl;
#endif
		;}
    break;

  case 562:
#line 6739 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]" << endl;
#endif
		;}
    break;

  case 563:
#line 6751 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"
    {
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]" << endl;
#endif
		;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 7448 "/usr/local/src/zorba/test/zorbatest/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -677;
  const short int
  xquery_parser::yypact_[] =
  {
       775,  1197,  1408,  -677,  -677,    31,  -677,    -4,  -677,  -677,
    -677,  3096,   108,   547,  -677,  3096,   -21,  -677,   386,   -20,
     210,     4,   437,   263,   350,   344,   458,   336,   476,   -33,
     489,   494,  -677,  -677,  3096,   352,   521,  -677,  -677,  -677,
    3096,   110,   538,  -677,  -677,   543,  3096,   150,   308,  -677,
     555,  1619,  -677,   577,   444,  3096,  -677,   589,    43,  -677,
     496,  -677,  -677,   321,   593,   597,  -677,  3808,  3646,   538,
    -677,   600,  3096,   468,  3096,  3096,  3096,    11,   611,   478,
    3096,  3096,  3096,  3096,  3096,  3096,  3096,   622,   539,   632,
    3096,   503,   663,   986,  -677,  -677,   106,  3096,   510,   526,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
     650,  -677,  -677,   436,  -677,  -677,  -677,  -677,  -677,  -677,
     564,   673,  -677,   603,   465,   -36,   428,   156,   456,  -677,
     598,   536,   676,   678,  3307,  -677,  -677,  -677,     2,  -677,
    -677,  -677,   360,  -677,   606,   547,  -677,   606,   547,  -677,
    -677,  -677,  -677,   606,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,   142,  -677,   182,  1830,  3096,   235,
      20,  -677,    90,  -677,  -677,   260,  -677,  -677,  -677,  -677,
    -677,  -677,   671,   679,  -677,   699,   701,  -677,  -677,   607,
     640,   706,  -677,  -677,   614,   393,   261,  -677,   578,   579,
    -677,   264,    96,  -677,   109,   380,    22,  -677,    -8,   692,
    -677,   111,   707,   726,   708,   618,   730,   721,     0,   700,
    -677,  -677,   136,   661,  -677,   266,   107,   591,   592,  -677,
     735,  -677,   641,  3096,   595,   602,  -677,  -677,    36,    42,
     270,  -677,   137,   283,   284,   560,  -677,   288,  -677,  -677,
    -677,  -677,  -677,    26,    44,   725,   546,   558,   675,    12,
    -677,  3096,     0,    -1,  -677,  -677,   620,  -677,  -677,  -677,
    -677,   754,  -677,  -677,  -677,  -677,  -677,  -677,  -677,   179,
    -677,  -677,   154,   397,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,   106,    27,
    3096,  3096,   704,  3096,  3096,  3096,  -677,   364,   425,   623,
    3477,  3477,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,  3477,  3477,  3477,
      10,  3477,  3477,  3477,  3477,  3477,  3477,  3477,  3477,  3477,
    3477,  3477,   399,   399,   761,   761,  -677,  -677,  -677,  2041,
    -677,  3646,  3646,  3096,   606,  -677,  -677,   606,  -677,   606,
    -677,  -677,  -677,  -677,   138,   286,   668,   764,  -677,   764,
    -677,  -677,   -10,   168,  -677,  -677,    16,   760,  -677,   205,
     399,  -677,  3096,   297,  -677,  -677,  -677,   685,   781,  -677,
     781,  -677,  3096,   695,   731,  3096,   732,  3096,   733,   -12,
     698,     1,   734,   634,   791,   728,   791,  -677,   729,   784,
    3096,   719,    -6,   747,  -677,   800,  -677,  -677,  -677,  -677,
    -677,  -677,  2252,   287,  -677,  -677,  3096,   755,  -677,    35,
      68,  -677,  -677,   802,  -677,  -677,  -677,   823,  -677,   -88,
    3096,  3096,  3096,   -66,  3096,  3096,  3096,  3096,  3096,  3096,
    3096,   772,  3096,   697,   780,  3096,  -677,  -677,   154,   154,
     179,  -677,   835,   836,   179,   837,  -677,    72,  -677,   703,
    -677,  -677,  -677,   524,   814,  -677,   838,    37,  -677,  -677,
     814,  -677,  3096,   449,   710,  3096,   713,  3096,   673,  -677,
    -677,  -677,  -677,  3096,    10,   439,  -677,   605,    58,   626,
     616,  -677,  -677,   627,   402,   428,   428,   -25,   156,   156,
     156,   156,   456,   456,  -677,  -677,  -677,  -677,  -677,  -677,
     549,  -677,  -677,  -677,  -677,   771,  -677,  -677,   292,  -677,
    -677,    21,  -677,  3096,  -677,  -677,  2463,  -677,   716,   717,
    -677,  -677,  -677,  -677,   852,   253,   143,  -677,  -677,   370,
     146,  -677,  -677,  -677,  3096,  2674,   776,   723,   727,   737,
     739,  -677,  3096,   538,  -677,   859,  -677,   862,  3096,   783,
    3096,  3096,    -5,   785,   543,  3096,  -677,   841,   867,   841,
    -677,   791,  -677,  3096,  3096,   794,   555,   736,  -677,   293,
     787,  -677,    18,  -677,  -677,   896,  -677,  -677,  3096,   884,
    -677,  -677,    39,  -677,  -677,  -677,  -677,    62,  -677,   394,
      45,  -677,   741,  3096,  3096,  -677,  -677,  -677,  3096,  3096,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,   622,   748,   689,
     632,   752,  -677,  -677,  -677,  -677,  -677,    95,   179,   451,
     153,   170,    27,  -677,   885,  -677,  -677,  -677,  -677,    50,
     864,  -677,  3096,   865,   704,  -677,  -677,   229,  -677,  3096,
     756,  3096,  -677,  3096,  -677,   295,   753,  -677,  3477,  -677,
    -677,  -677,  -677,   353,   418,  -677,    10,   353,  3477,  3477,
     403,  -677,  -677,  -677,  -677,  -677,  -677,  -677,    10,    10,
     418,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,   298,  -677,  -677,
     883,   399,  -677,  3096,  -677,   843,   392,   399,  -677,  -677,
     395,  -677,  -677,   314,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  3096,  -677,  -677,  3096,   812,  3096,
    -677,   842,   897,   890,   841,  -677,  -677,  3096,  -677,  -677,
    -677,  2885,   341,   457,  -677,  -677,   315,   757,   909,  -677,
     912,    66,   907,   777,   214,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  3096,    54,   689,  -677,  -677,  -677,  -677,  -677,
    3477,  3477,  3477,  3477,   910,   690,   905,  -677,   905,  -677,
    -677,   864,  -677,  -677,  -677,   919,  -677,  -677,  -677,  -677,
    -677,  3096,  -677,  -677,  -677,  -677,   156,  -677,  -677,  -677,
     212,   626,  -677,  -677,   404,  3477,  -677,  -677,   616,  -677,
     693,  -677,  -677,   265,   318,  -677,   399,  -677,  -677,   396,
     399,  -677,  -677,  -677,  -677,  -677,  3096,  -677,  3096,  -677,
     791,  -677,  -677,   326,  -677,  -677,   914,   358,  -677,  -677,
    -677,  -677,   792,   472,  -677,  -677,  -677,  -677,   778,   779,
     934,   923,  3096,   931,  3096,  -677,   218,  -677,   156,   156,
     156,   422,   418,  -677,   219,  -677,   225,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
     427,  -677,  -677,   431,  -677,  -677,   841,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -677,  -677,   786,   399,  -677,   803,
    -677,   887,   844,  3477,   720,   905,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,   805,  3096,   935,  -677,   156,  -677,  -677,
    3096,  -677,   807,  -677,   844,  -677
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
     456,     0,   144,     0,   143,   137,     0,   505,   504,   509,
     508,     0,   502,   503,   507,   511,   529,   518,   540,   527,
     506,   510,     0,     0,   539,    43,   495,   496,   497,   498,
     499,   500,   501,     1,     3,     5,    10,     8,    12,    13,
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
       0,     0,     0,     0,     0,     0,   465,   538,     0,     0,
     528,   530,     0,     0,   525,     0,   513,     0,   512,     0,
      16,    18,    96,   161,   157,   159,     0,   146,   150,   109,
     158,   145,     0,     0,     0,     0,     0,     0,   189,   191,
     194,   193,   195,     0,     0,     0,   487,   197,   466,   474,
     476,   478,   480,   482,   485,   203,   202,   200,   206,   207,
     208,   205,   210,   211,   214,   213,   401,   400,   394,   216,
     392,   398,   399,   218,   220,   389,   222,   249,     0,   260,
     261,     0,   296,     0,   318,   248,     0,   434,     0,     0,
      50,    51,    48,    49,     0,     0,     0,    88,    37,     0,
       0,   391,    66,    69,     0,     0,   434,     0,     0,     0,
       0,   179,     0,     0,   176,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    64,     0,    56,
      60,     0,   139,     0,     0,     0,     0,     0,   385,     0,
       0,   175,     0,   359,   356,     0,   360,   361,     0,     0,
     362,   355,     0,   332,   358,   357,   327,     0,   335,     0,
       0,   183,     0,     0,     0,   443,   444,   440,     0,     0,
     448,   449,   445,   454,   452,   453,   458,     0,     0,     0,
       0,     0,   537,   536,   531,   532,   534,     0,   526,   521,
       0,     0,    14,   170,     0,   171,   172,   173,   162,   163,
     164,   165,     0,   152,     0,   155,   148,   147,   110,     0,
       0,     0,   113,     0,   111,     0,     0,   481,     0,   198,
     494,   542,   541,     0,     0,   543,     0,     0,     0,     0,
     467,   471,   489,   470,   493,   491,   490,   492,     0,     0,
       0,   483,   546,   547,   544,   545,   548,   486,   395,   397,
     396,   393,   390,   250,   297,   320,   381,     0,   422,   424,
      90,     0,    72,     0,    73,     0,     0,     0,    80,    81,
       0,    68,   377,     0,   435,   428,   429,   431,   432,   180,
     178,   132,   133,   126,     0,   128,   125,     0,     0,     0,
     123,     0,     0,    63,    57,   141,   140,     0,   136,    11,
     386,     0,   345,   339,   336,   367,     0,     0,     0,   333,
       0,     0,     0,     0,     0,   184,     7,   441,   442,   446,
     447,   457,     0,     0,   459,   460,   138,   464,   535,   533,
       0,     0,     0,     0,     0,     0,     0,   516,     0,   514,
     174,   166,   167,   168,   160,     0,   153,   151,   156,   149,
     114,     0,   112,   115,   488,   484,   563,   562,   561,   557,
       0,   475,   556,   468,     0,     0,   473,   472,   477,   479,
       0,   382,    91,     0,     0,    89,     0,    74,    75,     0,
       0,    82,    83,   378,   130,   127,     0,   129,     0,    59,
       0,   142,   387,     0,   353,   347,     0,   346,   348,   354,
     351,   341,     0,   340,   342,   352,    92,   328,     0,     0,
       0,     0,     0,     0,     0,   455,     0,   461,   550,   551,
     549,     0,   522,   523,     0,   519,     0,   169,   154,   116,
     560,   559,   558,   553,   554,   469,   555,    76,    77,    93,
       0,    84,    85,     0,   131,   187,    65,   388,   338,   349,
     350,   337,   343,   344,   329,   330,     0,     0,   185,     0,
     181,     0,     0,     0,     0,     0,   517,   515,    78,    79,
      86,    87,   331,     0,     0,     0,   462,   552,   524,   520,
       0,   182,     0,   186,     0,   463
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
      -677,  -677,  -677,   875,   876,  -677,   874,  -677,   636,   637,
    -311,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,  -677,  -426,  -677,  -677,  -677,  -677,  -677,
     553,   222,  -677,  -558,   881,     6,   -80,  -677,  -677,   856,
    -677,  -677,   373,   548,  -224,  -475,  -677,  -677,   -35,   322,
    -474,   647,  -677,   294,  -677,  -677,  -283,   655,   309,  -677,
    -677,   313,  -557,  -677,   939,   400,  -677,  -677,   354,  -677,
    -677,   659,   649,   319,  -663,   638,   271,  -363,   272,   331,
    -677,  -677,  -677,  -677,  -677,   868,  -677,  -677,  -677,  -677,
    -677,  -677,   866,  -677,   -38,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,    91,   204,  -677,  -677,   -55,   217,  -677,  -347,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -443,
    -677,   371,  -677,   550,  -677,  -677,  -677,  -677,  -677,   126,
     134,  -601,  -396,  -677,  -677,  -677,  -677,  -677,  -677,  -677,
    -677,  -677,  -677,   642,  -213,  -367,  -677,  -677,   311,  -364,
    -677,  -677,  -677,  -677,  -677,  -677,  -677,   987,   993,    70,
     599,  -677,  -677,  -677,  -677,  -677,  -677,  -677,  -677,   363,
    -677,  -677,   220,  -677,   497,  -677,  -677,   317,   307,   325,
     501,  -677,  -677,   335,  -677,  -501,  -677,  -677,  -677,  -677,
     230,  -314,  -677,   561,   215,  -677,  -449,  -677,  -677,  -677,
    -677,  -676,  -677,  -677,  -677,  -677,   213,   342,  -677
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   617,   257,   115,   116,   117,   118,
     586,   587,   640,   754,   119,   120,   121,   122,   123,   124,
     125,   249,   250,   439,   451,   126,   259,   303,   304,   305,
     347,   348,   517,   518,   836,   697,   349,   514,   515,   688,
     689,   690,   691,   127,   246,   247,   128,   650,   651,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   367,   368,   369,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   394,   395,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   404,   172,   173,
     174,   642,   470,   471,   794,   892,   893,   886,   887,   894,
     888,   643,   644,   175,   176,   645,   177,   178,   179,   180,
     181,   182,   183,   564,   452,   559,   741,   560,   561,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   578,
     598,   194,   195,   196,   197,   198,   199,   200,   299,   300,
     201,   814,   815,   202,   537,   720,   538,   539,   540,   541,
     542,   543,   544,   721,   722,   325,   326,   327,   328,   329,
     914,   915,   330,   500,   504,   677,   501,   331,   332,   724,
     737,   825,   725,   726,   731,   727,   923,   849,   709
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       291,   292,   293,   294,   295,   296,   297,   204,   206,   508,
     306,   548,   549,   550,   551,   260,   563,   209,   562,   562,
     619,   215,   423,   536,   440,   420,   641,   436,   511,   276,
     277,   759,   433,   420,     6,   441,   436,   723,   850,   285,
     236,   799,   695,   696,   633,   634,   241,   494,   633,   634,
     792,   674,   251,   591,   860,   853,   562,   262,   267,   479,
     491,   265,   467,    17,   524,   526,     3,   268,   407,   340,
     434,   633,   634,     4,   213,   633,   634,   483,   280,   635,
     282,   283,   284,   635,   434,   694,   649,   371,   467,    26,
      39,    28,   584,    30,    31,   624,   608,   684,   371,   580,
     437,   450,   397,   777,   214,   232,   635,   505,   399,   611,
     635,   208,   372,   804,   636,   457,   637,   389,   636,   818,
     637,    49,   581,   372,   653,   533,   654,   403,   210,   468,
     242,   534,   832,   833,   218,   686,   687,   222,   409,   216,
     680,   636,   373,   637,   428,   636,   658,   637,   659,   233,
     638,    60,   207,   219,   638,   646,    50,   430,   223,   340,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   793,   252,   585,   638,    57,   744,
     408,   638,    57,   435,   340,   340,   573,   536,   536,   502,
     340,   755,   925,   681,   755,   784,   710,   466,   868,   641,
     799,   826,   872,   269,   641,    57,   639,    71,   286,    57,
     798,    71,    47,    48,   405,   609,   469,   613,   828,   857,
     495,   493,   838,   839,    70,   480,   481,   492,   625,   674,
     340,    77,   345,   800,    71,    77,   954,   900,    71,   482,
     700,   438,   647,   484,   485,   438,   396,   438,   438,   398,
     410,   458,   535,   438,   438,   819,   429,   486,    77,    91,
     512,   513,    77,   519,   513,   521,   951,   955,   211,   431,
     243,   443,   498,   955,   917,   503,   253,   582,   212,   463,
     244,   584,   803,   340,   711,   562,   751,   712,   307,   308,
     903,   309,   310,   713,   714,   715,   454,   473,   574,   400,
     583,   716,   311,   756,   312,   928,   760,    79,   340,   340,
     717,   932,   340,   827,   340,   313,   718,   719,   340,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     829,   340,   340,   254,   340,   340,   272,   378,    91,   401,
     340,   340,   592,   340,   884,   846,   340,   752,    50,   379,
     633,   230,   601,   569,   570,   604,   854,   606,   641,   927,
     499,   884,   340,   340,   220,   589,   340,   633,   753,   536,
     622,   511,   959,   904,   340,   961,   477,   255,   952,   956,
     753,   536,   536,   221,   863,   957,   631,   562,   778,   225,
     869,   593,   406,   562,   966,   568,   889,   895,   594,   571,
     655,   656,   657,   757,   660,   661,   662,   663,   664,   665,
     666,   217,   668,   420,   556,   671,   975,   411,   424,   556,
     636,   427,   637,   456,   345,   866,   420,   472,   870,   227,
     228,   885,   505,    12,   256,    41,   273,   636,    12,   637,
     474,   475,   698,   575,   630,   702,    16,   704,   939,   743,
     790,    16,   844,   478,   936,   861,   638,   908,   909,   910,
     911,   920,   224,     6,   758,   506,   633,   921,   629,    35,
     802,   873,   896,   638,    35,   929,   226,    41,   229,   579,
     890,   633,    41,   937,   922,   753,   867,   421,   432,   871,
     931,   889,    17,   745,   422,   890,   231,   895,   597,   930,
     599,   374,   562,   933,   341,   342,   562,   753,   557,   234,
     753,   753,   237,   557,   761,    65,   270,   271,   507,    39,
     235,   958,   769,   522,    54,   960,   391,   392,   773,    54,
     775,   776,   375,   344,    45,   781,   636,   862,   637,   705,
      58,   710,   753,   785,   786,    58,   753,   240,   891,   380,
      49,   636,   376,   637,   533,    50,    64,    65,   683,     3,
     534,    64,    65,   942,   245,   341,     4,   213,   381,   248,
      73,   684,   638,   807,   808,    73,   341,   342,   809,   810,
     963,   258,   747,   562,   525,   378,    12,   638,   558,   341,
     967,   788,   263,   558,   344,   343,   685,   379,   377,    16,
     953,   763,   847,   378,   264,   344,   266,   848,   699,   686,
     687,   572,   513,   274,   572,   379,   572,   275,   344,   840,
     279,   842,    35,   843,   732,   733,   734,   735,   281,   711,
      41,   345,   712,   307,   308,   287,   309,   310,   713,   714,
     715,   969,   545,   546,   796,   820,   821,   311,   298,   312,
     552,   553,   736,   920,   301,   717,   822,   823,   302,   921,
     313,   855,   719,   333,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   338,   922,    54,   820,   821,
     288,   289,   290,   738,   739,   740,   530,   531,   532,   822,
     823,   339,   352,    58,   874,   565,   565,   875,   340,   877,
     353,   350,   824,   354,   351,   355,   370,   881,   382,    64,
      65,   554,   555,   672,   673,   383,   356,    70,   384,   412,
     357,   385,   393,    73,   414,   358,   415,   413,   416,   417,
     418,   359,   905,   307,   308,   419,   309,   310,   425,   426,
     442,   445,   444,   446,   447,   448,   449,   311,   453,   312,
     455,   459,   460,   461,   360,   464,   462,   476,   487,   864,
     313,   919,   465,   488,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   489,   490,   496,   497,     1,
     516,   556,   527,   576,   577,   588,     2,     3,   361,   362,
     363,   364,   365,   366,     4,     5,   934,   883,   935,     6,
     595,   596,     7,   602,     8,     9,   610,   603,   605,   607,
     614,   615,    10,    11,    12,    13,   616,   618,   620,   621,
     623,    14,   948,   626,   950,   627,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,   649,   632,    32,    33,   652,   667,    34,
      35,    36,    37,    38,   669,    39,   670,    40,    41,   675,
     676,   679,   692,   729,   693,   708,   728,    42,   682,   701,
      43,    44,   703,    45,   742,   730,   748,   749,   750,   764,
      46,    47,    48,   765,   971,   771,    49,   766,   772,   782,
     973,   774,   783,   779,    50,   787,    51,   767,    52,   768,
      53,   789,   791,   795,   797,    54,   806,   812,   813,   817,
     830,   684,   835,   845,    55,   841,   420,    56,    57,   584,
     876,    58,   879,    59,    60,   880,   878,    61,    62,   898,
      63,   897,   899,   901,   912,   913,   902,    64,    65,    66,
     505,    67,    68,    69,   918,    70,   938,    71,   941,   926,
      72,    73,   944,   945,   946,    74,   947,   949,    75,   753,
     962,   972,   964,   965,   970,   968,    76,   974,   334,   335,
     336,    77,   590,    78,   509,   510,    79,   865,   337,   346,
      80,    81,    82,    83,    84,    85,    86,   780,   837,   612,
       1,    87,   816,    88,   523,    89,    90,     2,     3,   520,
     529,   834,   831,   770,   805,     4,     5,    91,   278,   528,
       6,   547,   388,     7,   390,     8,     9,   906,   801,   943,
     648,   940,   238,    10,    11,    12,    13,   566,   239,   600,
     811,   706,    14,   851,   907,   858,   707,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   859,   856,    32,    33,   916,   852,
      34,    35,    36,    37,    38,   678,    39,   924,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,    43,    44,     0,    45,     0,     0,     0,     0,     0,
       0,    46,    47,    48,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    51,     0,    52,
       0,    53,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,    56,    57,
       0,     0,    58,     0,    59,    60,     0,     0,    61,    62,
       0,    63,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,    67,    68,    69,     0,    70,     0,    71,     0,
       0,    72,    73,     0,     0,     0,    74,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,    77,     0,     0,     0,     0,    79,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     1,    87,     0,    88,     0,    89,    90,     2,     3,
       0,     0,     0,     0,     0,     0,     4,     5,    91,     0,
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
      62,     0,    63,     0,   203,     0,     0,     0,     0,    64,
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
      61,    62,     0,    63,     0,   205,     0,     0,     0,     0,
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
       0,    61,    62,     0,    63,     0,     0,     0,     0,   261,
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
       0,     0,    61,    62,     0,    63,     0,     0,     0,     0,
     402,     0,    64,    65,    66,     0,    67,    68,    69,     0,
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
      60,     0,     0,    61,    62,     0,    63,     0,   567,     0,
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
      59,    60,     0,     0,    61,    62,     0,    63,     0,   628,
       0,     0,     0,     0,    64,    65,    66,     0,    67,    68,
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
     746,     0,     0,     0,     0,    64,    65,    66,     0,    67,
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
       0,   762,     0,     0,     0,     0,    64,    65,    66,     0,
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
      63,     0,   882,     0,     0,     0,     0,    64,    65,    66,
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
       0,    63,     0,     0,     0,     0,     0,     0,    64,    65,
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
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
     386,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,    56,
      57,     0,     0,    58,     0,   387,    60,     0,     0,    61,
      62,     0,    63,     0,     0,     0,     0,     0,     0,    64,
      65,    66,     0,    67,    68,     0,     0,    70,     0,    71,
       0,     1,    72,    73,     0,     0,     0,     0,     2,     3,
      75,     0,     0,     0,     0,     0,     4,     5,    76,     0,
       0,     6,     0,    77,     7,     0,     8,     9,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,    37,    38,     0,    39,     0,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,    56,
      57,     0,     0,    58,     0,    59,    60,     0,     0,    61,
      62,     0,    63,     0,     0,     0,     0,     0,     0,    64,
      65,    66,     0,    67,    68,     0,     0,    70,     0,    71,
       1,     0,    72,    73,     0,     0,     0,     2,     3,     0,
      75,     0,     0,     0,     0,     4,     5,     0,    76,     0,
       6,     0,     0,    77,     0,     8,     9,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,     0,
      34,    35,    36,    37,    38,     0,    39,     0,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,    56,    57,
       0,     0,    58,     0,     0,     0,     0,     0,    61,    62,
       0,    63,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,     1,     0,     0,     0,    70,     0,    71,     2,
       3,    72,    73,     0,     0,     0,     0,     4,     5,    75,
       0,     0,     6,     0,     0,     0,     0,     8,     9,     0,
       0,     0,    77,     0,     0,    10,    11,    12,    13,     0,
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
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
      71,     0,     0,    72,    73,     0,     0,     0,     0,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        80,    81,    82,    83,    84,    85,    86,     1,     2,   323,
      90,   374,   375,   376,   377,    50,   383,    11,   382,   383,
     446,    15,   235,   370,   248,    33,   469,    35,   339,    67,
      68,   589,   245,    33,    24,   248,    35,   538,   714,    28,
      34,   642,   517,   517,     9,    10,    40,    48,     9,    10,
      32,   500,    46,   420,   730,   718,   420,    51,    15,    33,
      48,    55,    20,    53,   347,   348,    12,    24,    48,    48,
      48,     9,    10,    19,    20,     9,    10,    33,    72,    44,
      74,    75,    76,    44,    48,    48,    41,   123,    20,    62,
      80,    64,    76,    66,    67,   101,   108,    47,   123,   109,
     108,   101,   157,   108,    13,   138,    44,    35,   163,   108,
      44,   115,   148,    68,    79,     8,    81,   115,    79,    24,
      81,   111,   132,   148,   212,   115,   214,   207,    20,    87,
      20,   121,   689,   690,   154,    85,    86,   133,    48,   160,
      68,    79,   178,    81,    48,    79,   212,    81,   214,   182,
     115,   149,   121,   173,   115,    87,   119,    48,   154,    48,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   156,    25,   160,   115,   143,   158,
     160,   115,   143,   161,    48,    48,    48,   534,   535,    35,
      48,    48,   855,   507,    48,   621,   138,   161,   756,   642,
     801,    48,   760,   160,   647,   143,   171,   172,   197,   143,
     171,   172,   106,   107,   208,   439,   174,   441,    48,   720,
     221,   301,   697,   697,   170,   199,   200,   215,   452,   678,
      48,   196,   195,   171,   172,   196,   912,   171,   172,   213,
     523,   253,   174,   199,   200,   253,   155,   253,   253,   158,
     160,   144,   242,   253,   253,   160,   160,   213,   196,   232,
     340,   341,   196,   343,   344,   345,    48,    48,   160,   160,
     160,   160,    93,    48,   831,   121,   126,   109,   170,   273,
     170,    76,   649,    48,   226,   649,    33,   229,   230,   231,
      76,   233,   234,   235,   236,   237,   160,   160,   160,   157,
     132,   243,   244,   160,   246,   863,   160,   201,    48,    48,
     252,   869,    48,   160,    48,   257,   258,   259,    48,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     160,    48,    48,    25,    48,    48,    15,   181,   232,   157,
      48,    48,   422,    48,     3,   708,    48,    94,   119,   193,
       9,    15,   432,   391,   392,   435,   719,   437,   801,    94,
     181,     3,    48,    48,   154,   160,    48,     9,   115,   716,
     450,   682,   930,   159,    48,   933,    88,    69,   160,   160,
     115,   728,   729,   173,   751,   160,   466,   751,   612,   126,
     757,    94,   157,   757,   952,   389,   792,   793,   101,   393,
     480,   481,   482,    33,   484,   485,   486,   487,   488,   489,
     490,    25,   492,    33,    20,   495,   974,   157,   157,    20,
      79,   157,    81,   157,   195,    33,    33,   157,    33,    85,
      86,    90,    35,    39,   126,    83,   115,    79,    39,    81,
     157,   157,   522,   157,   157,   525,    52,   527,    90,   157,
     157,    52,   157,   165,   880,   157,   115,   820,   821,   822,
     823,   249,    25,    24,    94,    68,     9,   255,   462,    75,
      76,   157,   157,   115,    75,   157,   126,    83,    20,   409,
      23,     9,    83,   157,   272,   115,    94,    94,   108,    94,
      94,   887,    53,   573,   101,    23,    20,   893,   428,   866,
     430,    73,   866,   870,   140,   141,   870,   115,   114,    20,
     115,   115,   160,   114,   594,   163,    20,    21,   121,    80,
      26,    94,   602,   159,   130,    94,   166,   167,   608,   130,
     610,   611,   104,   169,    98,   615,    79,   750,    81,   533,
     146,   138,   115,   623,   624,   146,   115,    26,    91,    93,
     111,    79,   124,    81,   115,   119,   162,   163,    34,    12,
     121,   162,   163,    91,    26,   140,    19,    20,   112,    26,
     176,    47,   115,   653,   654,   176,   140,   141,   658,   659,
     947,    26,   576,   947,   159,   181,    39,   115,   194,   140,
     953,   626,    15,   194,   169,   159,    72,   193,   170,    52,
     178,   595,   249,   181,   160,   169,    17,   254,   159,    85,
      86,   394,   692,    20,   397,   193,   399,    20,   169,   699,
      20,   701,    75,   703,   222,   223,   224,   225,   160,   226,
      83,   195,   229,   230,   231,    24,   233,   234,   235,   236,
     237,   955,   371,   372,   638,   227,   228,   244,    26,   246,
     378,   379,   250,   249,   115,   252,   238,   239,    26,   255,
     257,   258,   259,     0,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   165,   272,   130,   227,   228,
     202,   203,   204,   134,   135,   136,   367,   368,   369,   238,
     239,   165,    89,   146,   774,   384,   385,   777,    48,   779,
      97,   137,   251,   100,    31,   102,   241,   787,   110,   162,
     163,   380,   381,   498,   499,   179,   113,   170,    42,    48,
     117,    43,   116,   176,    25,   122,    25,    48,   121,    89,
      24,   128,   812,   230,   231,   121,   233,   234,   160,   160,
      48,    15,    35,    35,   126,    15,    25,   244,    48,   246,
      89,   160,   160,    18,   151,   160,   115,   197,    33,   753,
     257,   841,   160,   217,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   217,   101,   157,    24,     4,
      76,    20,   159,   115,    20,    25,    11,    12,   185,   186,
     187,   188,   189,   190,    19,    20,   876,   791,   878,    24,
     115,    20,    27,   108,    29,    30,   108,    76,    76,    76,
      76,   177,    37,    38,    39,    40,    25,    89,    89,    35,
     101,    46,   902,    76,   904,    25,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    41,    89,    70,    71,    24,    76,    74,
      75,    76,    77,    78,   157,    80,    76,    82,    83,    24,
      24,    24,    48,   247,    26,   260,   240,    92,   165,   159,
      95,    96,   159,    98,   103,   248,   160,   160,    26,   103,
     105,   106,   107,   160,   964,    26,   111,   160,    26,    48,
     970,   108,    25,   108,   119,   101,   121,   160,   123,   160,
     125,   165,   115,     7,    20,   130,   165,   159,   219,   157,
      25,    47,    47,   160,   139,   159,    33,   142,   143,    76,
     108,   146,    25,   148,   149,    35,    84,   152,   153,    20,
     155,   174,    20,    26,    24,   245,   159,   162,   163,   164,
      35,   166,   167,   168,    25,   170,    32,   172,   156,   256,
     175,   176,   174,   174,    20,   180,    33,    26,   183,   115,
     174,    26,   159,    76,   159,   245,   191,   160,    93,    93,
      96,   196,   419,   198,   338,   338,   201,   755,    97,   123,
     205,   206,   207,   208,   209,   210,   211,   614,   694,   441,
       4,   216,   670,   218,   347,   220,   221,    11,    12,   344,
     351,   692,   689,   603,   650,    19,    20,   232,    69,   350,
      24,   373,   144,    27,   148,    29,    30,   813,   647,   893,
     470,   887,    35,    37,    38,    39,    40,   385,    35,   430,
     667,   534,    46,   716,   814,   728,   535,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   729,   720,    70,    71,   828,   717,
      74,    75,    76,    77,    78,   504,    80,   854,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,   107,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,   123,
      -1,   125,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,   148,   149,    -1,    -1,   152,   153,
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,    -1,   166,   167,   168,    -1,   170,    -1,   172,    -1,
      -1,   175,   176,    -1,    -1,    -1,   180,    -1,    -1,   183,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
      -1,     4,   216,    -1,   218,    -1,   220,   221,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,   232,    -1,
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
      -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,   160,
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
      -1,    -1,   152,   153,    -1,   155,    -1,    -1,    -1,    -1,
     160,    -1,   162,   163,   164,    -1,   166,   167,   168,    -1,
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
     148,   149,    -1,    -1,   152,   153,    -1,   155,    -1,   157,
      -1,    -1,    -1,    -1,   162,   163,   164,    -1,   166,   167,
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
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
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
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,
     143,    -1,    -1,   146,    -1,   148,   149,    -1,    -1,   152,
     153,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,    -1,   166,   167,    -1,    -1,   170,    -1,   172,
      -1,     4,   175,   176,    -1,    -1,    -1,    -1,    11,    12,
     183,    -1,    -1,    -1,    -1,    -1,    19,    20,   191,    -1,
      -1,    24,    -1,   196,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    80,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,
     143,    -1,    -1,   146,    -1,   148,   149,    -1,    -1,   152,
     153,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,    -1,   166,   167,    -1,    -1,   170,    -1,   172,
       4,    -1,   175,   176,    -1,    -1,    -1,    11,    12,    -1,
     183,    -1,    -1,    -1,    -1,    19,    20,    -1,   191,    -1,
      24,    -1,    -1,   196,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,
      74,    75,    76,    77,    78,    -1,    80,    -1,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,   152,   153,
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
     164,    -1,     4,    -1,    -1,    -1,   170,    -1,   172,    11,
      12,   175,   176,    -1,    -1,    -1,    -1,    19,    20,   183,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,   196,    -1,    -1,    37,    38,    39,    40,    -1,
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
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,    -1,    -1,   175,   176,    -1,    -1,    -1,    -1,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196
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
     406,   407,   157,   160,   157,   157,   197,    88,   165,    33,
     199,   200,   213,    33,   199,   200,   213,    33,   217,   217,
     101,    48,   215,   320,    48,   221,   157,    24,    93,   181,
     477,   480,    35,   121,   478,    35,    68,   121,   475,   292,
     293,   294,   320,   320,   341,   342,    76,   336,   337,   320,
     341,   320,   159,   335,   340,   159,   340,   159,   355,   356,
     357,   357,   357,   115,   121,   242,   393,   458,   460,   461,
     462,   463,   464,   465,   466,   360,   360,   359,   361,   361,
     361,   361,   362,   362,   363,   363,    20,   114,   194,   429,
     431,   432,   433,   429,   427,   432,   427,   157,   319,   378,
     378,   319,   391,    48,   160,   157,   115,    20,   443,   443,
     109,   132,   109,   132,    76,   160,   314,   315,    25,   160,
     314,   429,   320,    94,   101,   115,    20,   443,   444,   443,
     444,   320,   108,    76,   320,    76,   320,    76,   108,   328,
     108,   108,   327,   328,    76,   177,    25,   308,    89,   308,
      89,    35,   320,   101,   101,   328,    76,    25,   157,   319,
     157,   320,    89,     9,    10,    44,    79,    81,   115,   171,
     316,   403,   405,   415,   416,   419,    87,   174,   407,    41,
     351,   352,    24,   212,   214,   320,   320,   320,   212,   214,
     320,   320,   320,   320,   320,   320,   320,    76,   320,   157,
      76,   320,   478,   478,   480,    24,    24,   479,   477,    24,
      68,   475,   165,    34,    47,    72,    85,    86,   343,   344,
     345,   346,    48,    26,    48,   329,   334,   339,   320,   159,
     340,   159,   320,   159,   320,   319,   458,   464,   260,   492,
     138,   226,   229,   235,   236,   237,   243,   252,   258,   259,
     459,   467,   468,   469,   483,   486,   487,   489,   240,   247,
     248,   488,   222,   223,   224,   225,   250,   484,   134,   135,
     136,   430,   103,   157,   158,   320,   157,   319,   160,   160,
      26,    33,    94,   115,   317,    48,   160,    33,    94,   317,
     160,   320,   157,   319,   103,   160,   160,   160,   160,   320,
     349,    26,    26,   320,   108,   320,   320,   108,   328,   108,
     326,   320,    48,    25,   308,   320,   320,   101,   332,   165,
     157,   115,    32,   156,   408,     7,   319,    20,   171,   415,
     171,   405,    76,   429,    68,   352,   165,   320,   320,   320,
     320,   453,   159,   219,   455,   456,   333,   157,    24,   160,
     227,   228,   238,   239,   251,   485,    48,   160,    48,   160,
      25,   345,   346,   346,   342,    47,   338,   337,   329,   334,
     320,   159,   320,   320,   157,   160,   361,   249,   254,   491,
     485,   461,   491,   358,   361,   258,   467,   469,   462,   463,
     485,   157,   428,   429,   319,   315,    33,    94,   317,   429,
      33,    94,   317,   157,   320,   320,   108,   320,    84,    25,
      35,   320,   157,   319,     3,    90,   411,   412,   414,   416,
      23,    91,   409,   410,   413,   416,   157,   174,    20,    20,
     171,    26,   159,    76,   159,   320,   387,   456,   361,   361,
     361,   361,    24,   245,   474,   475,   474,   346,    25,   320,
     249,   255,   272,   490,   490,   358,   256,    94,   317,   157,
     429,    94,   317,   429,   320,   320,   308,   157,    32,    90,
     414,   156,    91,   413,   174,   174,    20,    33,   320,    26,
     320,    48,   160,   178,   485,    48,   160,   160,    94,   317,
      94,   317,   174,   429,   159,    76,   317,   361,   245,   475,
     159,   320,    26,   320,   160,   317
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
     455,   455,   456,   456,   457,   457,   458,   458,   458,   458,
     459,   459,   459,   459,   460,   460,   461,   461,   462,   462,
     463,   463,   464,   464,   464,   465,   465,   466,   466,   467,
     467,   467,   467,   467,   468,   469,   469,   469,   469,   469,
     469,   469,   470,   470,   470,   470,   471,   471,   471,   471,
     472,   472,   473,   473,   473,   473,   473,   473,   473,   474,
     474,   475,   475,   475,   475,   476,   476,   476,   476,   476,
     477,   477,   478,   478,   479,   479,   480,   480,   481,   482,
     482,   483,   483,   483,   484,   484,   484,   484,   484,   485,
     485,   485,   485,   486,   487,   488,   489,   489,   490,   490,
     490,   491,   491,   492
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
       4,     5,     5,     4,     4,     4,     5,     5,     4,     4,
       2,     2,     4,     4,     4,     6,     1,     4,     3,     5,
       1,     2,     4,     7,     5,     3,     1,     2,     3,     4,
       1,     1,     2,     2,     1,     3,     1,     3,     1,     3,
       1,     2,     1,     2,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     6,     4,     6,     1,     1,
       3,     2,     4,     4,     6,     2,     3,     1,     2,     1,
       1,     2,     2,     3,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     4,     3,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     2
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
  "\"'<first into>'\"", "\"'into'\"", "\"'<last into>'\"", "\"'modify'\"",
  "\"'<copy $>'\"", "\"'with'\"", "\"'<try>'\"", "\"'<catch (>'\"",
  "\"'<using $>'\"", "\"'<eval {>'\"", "\"'all'\"", "\"'<all words>'\"",
  "\"'any'\"", "\"'<any words>'\"", "\"'<at end>'\"", "\"'<at least>'\"",
  "\"'<at most>'\"", "\"'<at start>'\"", "\"'<case insensitive>'\"",
  "\"'<casesensitive>'\"", "\"'<declare ftoption>'\"",
  "\"'<diacritics insensitive>'\"", "\"'<diacritics sensitive>'\"",
  "\"'different'\"", "\"'distance'\"", "\"'<entire content>'\"",
  "\"'exactly'\"", "\"'from'\"", "\"'&&'\"", "\"'ftcontains'\"",
  "\"'ftnot'\"", "\"'||'\"", "\"'language'\"", "\"'levels'\"",
  "\"'lowercase'\"", "\"'<not in>'\"", "\"'occurs'\"", "\"'paragraph'\"",
  "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"", "\"'score'\"",
  "\"'sentence'\"", "\"'sentences'\"", "\"'times'\"", "\"'uppercase'\"",
  "\"'weight'\"", "\"'window'\"", "\"'<without content>'\"",
  "\"'<without diacritics>'\"", "\"'<without stemming>'\"",
  "\"'<without stop words>'\"", "\"'<without thesaurus>'\"",
  "\"'<without wildcards>'\"", "\"'<with default stop words>'\"",
  "\"'<with diacritics>'\"", "\"'<with stemming>'\"",
  "\"'<with stop words>'\"", "\"'<with thesaurus>'\"",
  "\"'<with wildcards>'\"", "\"'words'\"", "FTCONTAINS_REDUCE",
  "RANGE_REDUCE", "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "COMMA_DOLLAR", "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "STEP_REDUCE",
  "$accept", "Module", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList", "SIND_Decl",
  "VFO_Decl", "Setter", "Import", "NamespaceDecl", "BoundarySpaceDecl",
  "DefaultNamespaceDecl", "OptionDecl", "FTOptionDecl", "OrderingModeDecl",
  "EmptyOrderDecl", "CopyNamespacesDecl", "DefaultCollationDecl",
  "BaseURIDecl", "SchemaImport", "URILiteralList", "SchemaPrefix",
  "ModuleImport", "VarDecl", "ConstructionDecl", "FunctionDecl",
  "ParamList", "Param", "EnclosedExpr", "NonNodeEnclosedExpr", "QueryBody",
  "Expr", "ExprSingle", "FLWORExpr", "ForLetClauseList", "ForLetClause",
  "ForClause", "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar",
  "LetClause", "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl",
  "EvalVarDecl", "WhereClause", "GroupByClause", "GroupSpecList",
  "GroupSpec", "GroupCollationSpec", "LetClauseList", "OrderByClause",
  "OrderSpecList", "OrderSpec", "OrderModifier", "OrderDirSpec",
  "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "TypeswitchExpr", "CaseClauseList",
  "CaseClause", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr",
  "FTContainsExpr", "RangeExpr", "AdditiveExpr", "MultiplicativeExpr",
  "UnionExpr", "IntersectExceptExpr", "InstanceofExpr", "TreatExpr",
  "CastableExpr", "CastExpr", "UnaryExpr", "SignList", "ValueExpr",
  "GeneralComp", "ValueComp", "NodeComp", "ValidateExpr", "ExtensionExpr",
  "PragmaList", "Pragma", "PathExpr", "RelativePathExpr", "StepExpr",
  "AxisStep", "ForwardStep", "ForwardAxis", "AbbrevForwardStep",
  "ReverseStep", "ReverseAxis", "NodeTest", "NameTest", "Wildcard",
  "FilterExpr", "PredicateList", "Predicate", "PrimaryExpr", "Literal",
  "NumericLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "DirAttributeValue",
  "Opt_QuoteAttrContentList", "QuoteAttrContentList",
  "Opt_AposAttrContentList", "AposAttrContentList",
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
     320,    33,   212,   320,    -1,   207,   320,    33,   214,   320,
      -1,   207,   320,   199,   320,    -1,   207,   320,   200,   320,
      -1,   208,   320,   213,   320,    -1,   208,   320,    33,   212,
     320,    -1,   208,   320,    33,   214,   320,    -1,   208,   320,
     199,   320,    -1,   208,   320,   200,   320,    -1,   205,   320,
      -1,   206,   320,    -1,   210,   320,   217,   320,    -1,   211,
     320,   217,   320,    -1,   209,   320,    33,   320,    -1,   216,
     452,   215,   320,   159,   320,    -1,   453,    -1,   452,    48,
      76,   453,    -1,    26,   101,   320,    -1,   218,   115,   320,
     157,   455,    -1,   456,    -1,   455,   456,    -1,   219,   387,
     160,   317,    -1,   219,   387,    48,    76,    26,   160,   317,
      -1,   220,   331,   221,   320,   157,    -1,   221,   320,   157,
      -1,   460,    -1,   460,   459,    -1,   460,   258,   358,    -1,
     460,   459,   258,   358,    -1,   469,    -1,   467,    -1,   459,
     469,    -1,   459,   467,    -1,   461,    -1,   460,   243,   461,
      -1,   462,    -1,   461,   240,   462,    -1,   463,    -1,   462,
     247,   463,    -1,   464,    -1,   242,   464,    -1,   465,    -1,
     465,   488,    -1,   121,   458,   160,    -1,   466,    -1,   466,
     484,    -1,   393,    -1,   115,   319,   157,    -1,   468,    -1,
     487,    -1,   486,    -1,   489,    -1,   483,    -1,   138,    -1,
     470,    -1,   471,    -1,   472,    -1,   473,    -1,   476,    -1,
     481,    -1,   482,    -1,   246,    -1,   257,    -1,   231,    -1,
     230,    -1,   267,    -1,   261,    -1,   234,    -1,   233,    -1,
     268,    -1,   262,    -1,   270,   475,    -1,   270,    68,    -1,
     270,   121,   475,   160,    -1,   270,   121,   475,    48,   474,
     160,    -1,   270,   121,    68,   160,    -1,   270,   121,    68,
      48,   474,   160,    -1,   264,    -1,   475,    -1,   474,    48,
     475,    -1,    35,    24,    -1,    35,    24,   251,    24,    -1,
      35,    24,   485,   245,    -1,    35,    24,   251,    24,   485,
     245,    -1,   269,   478,    -1,   269,   478,   477,    -1,   266,
      -1,   266,   477,    -1,   263,    -1,   480,    -1,   477,   480,
      -1,    35,    24,    -1,   121,   479,   160,    -1,    24,    -1,
     479,    24,    -1,   181,   478,    -1,    93,   478,    -1,   244,
      24,    -1,   271,    -1,   265,    -1,   229,    -1,   226,    -1,
     237,    -1,   224,    -1,   225,    -1,   222,    -1,   223,    -1,
     250,    -1,   238,   361,    -1,   227,   361,    -1,   228,   361,
      -1,   239,   361,   178,   361,    -1,   236,   485,   490,    -1,
     259,   361,   490,    -1,   248,   485,   256,    -1,   252,   491,
      -1,   235,   491,    -1,   272,    -1,   255,    -1,   249,    -1,
     254,    -1,   249,    -1,   260,   361,    -1
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
    1474,  1479,  1485,  1491,  1496,  1501,  1506,  1512,  1518,  1523,
    1528,  1531,  1534,  1539,  1544,  1549,  1556,  1558,  1563,  1567,
    1573,  1575,  1578,  1583,  1591,  1597,  1601,  1603,  1606,  1610,
    1615,  1617,  1619,  1622,  1625,  1627,  1631,  1633,  1637,  1639,
    1643,  1645,  1648,  1650,  1653,  1657,  1659,  1662,  1664,  1668,
    1670,  1672,  1674,  1676,  1678,  1680,  1682,  1684,  1686,  1688,
    1690,  1692,  1694,  1696,  1698,  1700,  1702,  1704,  1706,  1708,
    1710,  1712,  1714,  1717,  1720,  1725,  1732,  1737,  1744,  1746,
    1748,  1752,  1755,  1760,  1765,  1772,  1775,  1779,  1781,  1784,
    1786,  1788,  1791,  1794,  1798,  1800,  1803,  1806,  1809,  1812,
    1814,  1816,  1818,  1820,  1822,  1824,  1826,  1828,  1830,  1832,
    1835,  1838,  1841,  1846,  1850,  1854,  1858,  1861,  1864,  1866,
    1868,  1870,  1872,  1874
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   758,   758,   766,   775,   782,   795,   803,   816,   826,
     841,   856,   871,   880,   889,   904,   913,   930,   939,   956,
     963,   970,   977,   989,   996,  1003,  1012,  1025,  1032,  1039,
    1046,  1053,  1060,  1067,  1076,  1089,  1096,  1114,  1129,  1137,
    1151,  1160,  1175,  1191,  1205,  1213,  1228,  1236,  1250,  1259,
    1268,  1277,  1299,  1313,  1327,  1337,  1347,  1357,  1373,  1382,
    1400,  1407,  1420,  1429,  1439,  1448,  1465,  1475,  1485,  1495,
    1511,  1519,  1533,  1543,  1554,  1565,  1577,  1589,  1601,  1613,
    1625,  1635,  1646,  1657,  1669,  1681,  1693,  1705,  1723,  1734,
    1751,  1760,  1775,  1786,  1800,  1814,  1823,  1838,  1845,  1852,
    1859,  1866,  1875,  1882,  1889,  1896,  1903,  1910,  1917,  1927,
    1937,  1948,  1959,  1971,  1986,  2001,  2016,  2037,  2046,  2061,
    2068,  2081,  2095,  2104,  2121,  2131,  2142,  2154,  2167,  2178,
    2190,  2202,  2220,  2235,  2249,  2264,  2273,  2288,  2297,  2314,
    2325,  2337,  2348,  2363,  2367,  2381,  2392,  2402,  2412,  2422,
    2435,  2444,  2458,  2467,  2479,  2489,  2499,  2514,  2522,  2537,
    2546,  2563,  2572,  2587,  2597,  2607,  2617,  2627,  2637,  2647,
    2663,  2670,  2683,  2691,  2705,  2719,  2729,  2745,  2755,  2770,
    2779,  2795,  2805,  2822,  2831,  2846,  2855,  2871,  2885,  2892,
    2906,  2913,  2935,  2942,  2953,  2964,  2981,  2988,  2998,  3014,
    3021,  3035,  3042,  3049,  3062,  3069,  3076,  3083,  3090,  3103,
    3110,  3118,  3132,  3139,  3146,  3159,  3166,  3181,  3188,  3203,
    3210,  3225,  3232,  3247,  3254,  3269,  3276,  3283,  3290,  3305,
    3312,  3319,  3333,  3340,  3347,  3354,  3361,  3368,  3381,  3388,
    3395,  3402,  3409,  3416,  3429,  3436,  3443,  3457,  3464,  3479,
    3488,  3503,  3512,  3529,  3538,  3580,  3587,  3594,  3601,  3617,
    3631,  3639,  3652,  3659,  3672,  3681,  3690,  3699,  3714,  3723,
    3737,  3744,  3751,  3758,  3765,  3772,  3779,  3792,  3799,  3812,
    3821,  3836,  3843,  3850,  3857,  3864,  3882,  3889,  3902,  3909,
    3922,  3932,  3942,  3958,  3965,  3980,  3989,  4006,  4020,  4027,
    4034,  4041,  4048,  4055,  4062,  4069,  4082,  4089,  4102,  4110,
    4118,  4132,  4145,  4152,  4166,  4179,  4193,  4252,  4261,  4276,
    4285,  4300,  4307,  4320,  4327,  4334,  4347,  4358,  4369,  4380,
    4391,  4402,  4420,  4429,  4444,  4453,  4470,  4485,  4493,  4508,
    4514,  4521,  4530,  4539,  4550,  4568,  4574,  4581,  4590,  4599,
    4610,  4627,  4635,  4649,  4657,  4671,  4679,  4687,  4696,  4711,
    4720,  4728,  4736,  4750,  4758,  4776,  4784,  4804,  4822,  4829,
    4836,  4843,  4850,  4857,  4870,  4884,  4893,  4902,  4910,  4938,
    4947,  4956,  4964,  4978,  4992,  5006,  5015,  5024,  5032,  5046,
    5055,  5070,  5084,  5093,  5102,  5142,  5150,  5158,  5172,  5179,
    5186,  5199,  5213,  5220,  5227,  5234,  5241,  5248,  5255,  5262,
    5269,  5282,  5295,  5302,  5310,  5324,  5337,  5350,  5357,  5364,
    5377,  5386,  5395,  5404,  5413,  5428,  5442,  5451,  5460,  5469,
    5478,  5488,  5498,  5514,  5538,  5548,  5571,  5614,  5622,  5628,
    5639,  5648,  5657,  5666,  5675,  5685,  5694,  5703,  5712,  5721,
    5736,  5744,  5757,  5766,  5781,  5810,  5824,  5833,  5849,  5866,
    5876,  5886,  5900,  5910,  5930,  5936,  5953,  5959,  5965,  5971,
    5983,  5989,  5995,  6001,  6013,  6019,  6031,  6037,  6049,  6055,
    6067,  6073,  6085,  6091,  6097,  6109,  6115,  6127,  6133,  6145,
    6151,  6157,  6163,  6169,  6181,  6193,  6200,  6207,  6214,  6221,
    6228,  6235,  6248,  6254,  6260,  6266,  6278,  6284,  6290,  6296,
    6308,  6314,  6326,  6332,  6338,  6344,  6350,  6356,  6362,  6374,
    6380,  6392,  6398,  6404,  6410,  6422,  6428,  6434,  6440,  6446,
    6458,  6464,  6476,  6482,  6494,  6500,  6512,  6518,  6530,  6542,
    6548,  6560,  6566,  6572,  6584,  6590,  6596,  6602,  6608,  6620,
    6627,  6634,  6641,  6654,  6666,  6678,  6690,  6696,  6708,  6714,
    6720,  6732,  6738,  6750
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
  const int xquery_parser::yylast_ = 4004;
  const int xquery_parser::yynnts_ = 209;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 333;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 284;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 538;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;

} // namespace zorba

#line 6760 "/usr/local/src/zorba/test/zorbatest/build/zorba/src/compiler/parser/xquery_parser.y"



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

